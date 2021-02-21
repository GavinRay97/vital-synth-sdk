import type { VitalPreset } from "../generated/VitalPreset.types"

import { WaveFile } from "wavefile"
import StreamZip from "node-stream-zip"

import fsSync from "fs"
import fs from "fs/promises"

import path from "path"

// Reads a Vital bank by extracting it in-memory and returning all of the presets JSON data
async function readVitalBank(filepath: string): Promise<VitalPreset[]> {
  const presets: VitalPreset[] = await new Promise((resolve, reject) => {
    const _presets = [] as VitalPreset[]
    const zip = new StreamZip({ file: filepath, storeEntries: true })

    zip.on("ready", () => {
      const [firstEntry] = Object.keys(zip.entries())
      const [vitalBankName] = firstEntry.split("/")

      console.log("Vital bank:", vitalBankName)
      console.log("Entries read: " + zip.entriesCount)

      for (const entry of Object.values(zip.entries())) {
        const [_bank, _presetfolder, presetName] = entry.name.split("/")
        const contents = zip.entryDataSync(entry.name).toString("utf8")
        const preset: VitalPreset = JSON.parse(contents)
        _presets.push(preset)
      }

      zip.close()
      resolve(_presets)
    })

    zip.on("error", reject)
  })

  return presets
}

// Takes the base64-encoded wave data present in keys such as "settings.sample.sample"
// And writes it into regular ".wav" file format
async function readVitalPresetSampleWaveData(preset: VitalPreset) {
  const sample = preset.settings.sample
  const pcmBuffer = Buffer.from(sample.samples, "base64")

  const waveFile = new WaveFile()
  const numChannels = 1
  const bitDepth = "8"
  waveFile.fromScratch(numChannels, sample.sample_rate, bitDepth, pcmBuffer)

  return { pcmBuffer, waveBuffer: waveFile.toBuffer() }
}

async function writeVitalPresetSampleWaveData(preset: VitalPreset) {
  const { pcmBuffer, waveBuffer } = await readVitalPresetSampleWaveData(preset)

  // prettier-ignore
  const pcmOutfilePath = path.join(__dirname, `${preset.preset_name}_sample.pcm`)
  // prettier-ignore
  const wavOutfilePath = path.join(__dirname, `${preset.preset_name}_sample.wav`)

  await fs.writeFile(pcmOutfilePath, pcmBuffer)
  await fs.writeFile(wavOutfilePath, waveBuffer)
}

async function main() {
  const presets = await readVitalBank(
    "./Presets/SNFK-Vital-Essentials.vitalbank"
  )
  console.log(presets.length, "presets found")

  console.log("Trying to read preset sample PCM data and write to .wav file")
  await writeVitalPresetSampleWaveData(presets[0])
}

main().catch(console.log)
