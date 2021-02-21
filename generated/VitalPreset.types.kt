// To parse the JSON, install kotlin's serialization plugin and do:
//
// val json           = Json(JsonConfiguration.Stable)
// val vitalPreset    = json.parse(VitalPreset.serializer(), jsonString)
// val presetStyle    = json.parse(PresetStyle.serializer(), jsonString)
// val presetSettings = json.parse(PresetSettings.serializer(), jsonString)
// val lfo            = json.parse(Lfo.serializer(), jsonString)
// val modulation     = json.parse(Modulation.serializer(), jsonString)
// val source         = json.parse(Source.serializer(), jsonString)
// val sample         = json.parse(Sample.serializer(), jsonString)
// val wavetable      = json.parse(Wavetable.serializer(), jsonString)
// val group          = json.parse(Group.serializer(), jsonString)
// val component      = json.parse(Component.serializer(), jsonString)
// val keyframe       = json.parse(Keyframe.serializer(), jsonString)
// val type           = json.parse(Type.serializer(), jsonString)

package org.vitalsdk.types

import kotlinx.serialization.*
import kotlinx.serialization.json.*
import kotlinx.serialization.internal.*

@Serializable
data class VitalPreset (
    val author: String,
    val comments: String,
    val macro1: String,
    val macro2: String,
    val macro3: String,
    val macro4: String,

    @SerialName("preset_name")
    val presetName: String? = null,

    @SerialName("preset_style")
    val presetStyle: PresetStyle,

    val settings: PresetSettings,

    @SerialName("synth_version")
    val synthVersion: String
)

@Serializable(with = PresetStyle.Companion::class)
enum class PresetStyle(val value: String) {
    Bass("Bass"),
    Empty(""),
    Experiment("Experiment"),
    Keys("Keys"),
    Lead("Lead"),
    Pad("Pad"),
    Percussion("Percussion"),
    Sequence("Sequence"),
    Sfx("SFX"),
    Template("Template");

    companion object : KSerializer<PresetStyle> {
        override val descriptor: SerialDescriptor get() {
            return PrimitiveDescriptor("org.vitalsdk.types.PresetStyle", PrimitiveKind.STRING)
        }
        override fun deserialize(decoder: Decoder): PresetStyle = when (val value = decoder.decodeString()) {
            "Bass"       -> Bass
            ""           -> Empty
            "Experiment" -> Experiment
            "Keys"       -> Keys
            "Lead"       -> Lead
            "Pad"        -> Pad
            "Percussion" -> Percussion
            "Sequence"   -> Sequence
            "SFX"        -> Sfx
            "Template"   -> Template
            else         -> throw IllegalArgumentException("PresetStyle could not parse: $value")
        }
        override fun serialize(encoder: Encoder, value: PresetStyle) {
            return encoder.encodeString(value.value)
        }
    }
}

@Serializable
data class PresetSettings (
    @SerialName("beats_per_minute")
    val beatsPerMinute: Double,

    val bypass: Double? = null,

    @SerialName("chorus_cutoff")
    val chorusCutoff: Double? = null,

    @SerialName("chorus_damping")
    val chorusDamping: Double? = null,

    @SerialName("chorus_delay_1")
    val chorusDelay1: Double,

    @SerialName("chorus_delay_2")
    val chorusDelay2: Double,

    @SerialName("chorus_dry_wet")
    val chorusDryWet: Double,

    @SerialName("chorus_feedback")
    val chorusFeedback: Double,

    @SerialName("chorus_frequency")
    val chorusFrequency: Double,

    @SerialName("chorus_mod_depth")
    val chorusModDepth: Double,

    @SerialName("chorus_on")
    val chorusOn: Double,

    @SerialName("chorus_spread")
    val chorusSpread: Double? = null,

    @SerialName("chorus_sync")
    val chorusSync: Double,

    @SerialName("chorus_tempo")
    val chorusTempo: Double,

    @SerialName("chorus_voices")
    val chorusVoices: Double,

    @SerialName("compressor_attack")
    val compressorAttack: Double,

    @SerialName("compressor_band_gain")
    val compressorBandGain: Double,

    @SerialName("compressor_band_lower_ratio")
    val compressorBandLowerRatio: Double,

    @SerialName("compressor_band_lower_threshold")
    val compressorBandLowerThreshold: Double,

    @SerialName("compressor_band_upper_ratio")
    val compressorBandUpperRatio: Double,

    @SerialName("compressor_band_upper_threshold")
    val compressorBandUpperThreshold: Double,

    @SerialName("compressor_enabled_bands")
    val compressorEnabledBands: Double,

    @SerialName("compressor_high_gain")
    val compressorHighGain: Double,

    @SerialName("compressor_high_lower_ratio")
    val compressorHighLowerRatio: Double,

    @SerialName("compressor_high_lower_threshold")
    val compressorHighLowerThreshold: Double,

    @SerialName("compressor_high_upper_ratio")
    val compressorHighUpperRatio: Double,

    @SerialName("compressor_high_upper_threshold")
    val compressorHighUpperThreshold: Double,

    @SerialName("compressor_low_gain")
    val compressorLowGain: Double,

    @SerialName("compressor_low_lower_ratio")
    val compressorLowLowerRatio: Double,

    @SerialName("compressor_low_lower_threshold")
    val compressorLowLowerThreshold: Double,

    @SerialName("compressor_low_upper_ratio")
    val compressorLowUpperRatio: Double,

    @SerialName("compressor_low_upper_threshold")
    val compressorLowUpperThreshold: Double,

    @SerialName("compressor_mix")
    val compressorMix: Double? = null,

    @SerialName("compressor_on")
    val compressorOn: Double,

    @SerialName("compressor_release")
    val compressorRelease: Double,

    @SerialName("delay_aux_frequency")
    val delayAuxFrequency: Double,

    @SerialName("delay_aux_sync")
    val delayAuxSync: Double,

    @SerialName("delay_aux_tempo")
    val delayAuxTempo: Double,

    @SerialName("delay_dry_wet")
    val delayDryWet: Double,

    @SerialName("delay_feedback")
    val delayFeedback: Double,

    @SerialName("delay_filter_cutoff")
    val delayFilterCutoff: Double,

    @SerialName("delay_filter_spread")
    val delayFilterSpread: Double,

    @SerialName("delay_frequency")
    val delayFrequency: Double,

    @SerialName("delay_on")
    val delayOn: Double,

    @SerialName("delay_style")
    val delayStyle: Double,

    @SerialName("delay_sync")
    val delaySync: Double,

    @SerialName("delay_tempo")
    val delayTempo: Double,

    @SerialName("distortion_drive")
    val distortionDrive: Double,

    @SerialName("distortion_filter_blend")
    val distortionFilterBlend: Double,

    @SerialName("distortion_filter_cutoff")
    val distortionFilterCutoff: Double,

    @SerialName("distortion_filter_order")
    val distortionFilterOrder: Double,

    @SerialName("distortion_filter_resonance")
    val distortionFilterResonance: Double,

    @SerialName("distortion_mix")
    val distortionMix: Double,

    @SerialName("distortion_on")
    val distortionOn: Double,

    @SerialName("distortion_type")
    val distortionType: Double,

    @SerialName("effect_chain_order")
    val effectChainOrder: Double,

    @SerialName("env_1_attack")
    val env1_Attack: Double,

    @SerialName("env_1_attack_power")
    val env1_AttackPower: Double,

    @SerialName("env_1_decay")
    val env1_Decay: Double,

    @SerialName("env_1_decay_power")
    val env1_DecayPower: Double,

    @SerialName("env_1_delay")
    val env1_Delay: Double,

    @SerialName("env_1_hold")
    val env1_Hold: Double,

    @SerialName("env_1_release")
    val env1_Release: Double,

    @SerialName("env_1_release_power")
    val env1_ReleasePower: Double,

    @SerialName("env_1_sustain")
    val env1_Sustain: Double,

    @SerialName("env_2_attack")
    val env2_Attack: Double,

    @SerialName("env_2_attack_power")
    val env2_AttackPower: Double,

    @SerialName("env_2_decay")
    val env2_Decay: Double,

    @SerialName("env_2_decay_power")
    val env2_DecayPower: Double,

    @SerialName("env_2_delay")
    val env2_Delay: Double,

    @SerialName("env_2_hold")
    val env2_Hold: Double,

    @SerialName("env_2_release")
    val env2_Release: Double,

    @SerialName("env_2_release_power")
    val env2_ReleasePower: Double,

    @SerialName("env_2_sustain")
    val env2_Sustain: Double,

    @SerialName("env_3_attack")
    val env3_Attack: Double,

    @SerialName("env_3_attack_power")
    val env3_AttackPower: Double,

    @SerialName("env_3_decay")
    val env3_Decay: Double,

    @SerialName("env_3_decay_power")
    val env3_DecayPower: Double,

    @SerialName("env_3_delay")
    val env3_Delay: Double,

    @SerialName("env_3_hold")
    val env3_Hold: Double,

    @SerialName("env_3_release")
    val env3_Release: Double,

    @SerialName("env_3_release_power")
    val env3_ReleasePower: Double,

    @SerialName("env_3_sustain")
    val env3_Sustain: Double,

    @SerialName("env_4_attack")
    val env4_Attack: Double,

    @SerialName("env_4_attack_power")
    val env4_AttackPower: Double,

    @SerialName("env_4_decay")
    val env4_Decay: Double,

    @SerialName("env_4_decay_power")
    val env4_DecayPower: Double,

    @SerialName("env_4_delay")
    val env4_Delay: Double,

    @SerialName("env_4_hold")
    val env4_Hold: Double,

    @SerialName("env_4_release")
    val env4_Release: Double,

    @SerialName("env_4_release_power")
    val env4_ReleasePower: Double,

    @SerialName("env_4_sustain")
    val env4_Sustain: Double,

    @SerialName("env_5_attack")
    val env5_Attack: Double,

    @SerialName("env_5_attack_power")
    val env5_AttackPower: Double,

    @SerialName("env_5_decay")
    val env5_Decay: Double,

    @SerialName("env_5_decay_power")
    val env5_DecayPower: Double,

    @SerialName("env_5_delay")
    val env5_Delay: Double,

    @SerialName("env_5_hold")
    val env5_Hold: Double,

    @SerialName("env_5_release")
    val env5_Release: Double,

    @SerialName("env_5_release_power")
    val env5_ReleasePower: Double,

    @SerialName("env_5_sustain")
    val env5_Sustain: Double,

    @SerialName("env_6_attack")
    val env6_Attack: Double,

    @SerialName("env_6_attack_power")
    val env6_AttackPower: Double,

    @SerialName("env_6_decay")
    val env6_Decay: Double,

    @SerialName("env_6_decay_power")
    val env6_DecayPower: Double,

    @SerialName("env_6_delay")
    val env6_Delay: Double,

    @SerialName("env_6_hold")
    val env6_Hold: Double,

    @SerialName("env_6_release")
    val env6_Release: Double,

    @SerialName("env_6_release_power")
    val env6_ReleasePower: Double,

    @SerialName("env_6_sustain")
    val env6_Sustain: Double,

    @SerialName("eq_band_cutoff")
    val eqBandCutoff: Double,

    @SerialName("eq_band_gain")
    val eqBandGain: Double,

    @SerialName("eq_band_mode")
    val eqBandMode: Double,

    @SerialName("eq_band_resonance")
    val eqBandResonance: Double,

    @SerialName("eq_high_cutoff")
    val eqHighCutoff: Double,

    @SerialName("eq_high_gain")
    val eqHighGain: Double,

    @SerialName("eq_high_mode")
    val eqHighMode: Double,

    @SerialName("eq_high_resonance")
    val eqHighResonance: Double,

    @SerialName("eq_low_cutoff")
    val eqLowCutoff: Double,

    @SerialName("eq_low_gain")
    val eqLowGain: Double,

    @SerialName("eq_low_mode")
    val eqLowMode: Double,

    @SerialName("eq_low_resonance")
    val eqLowResonance: Double,

    @SerialName("eq_on")
    val eqOn: Double,

    @SerialName("filter_1_blend")
    val filter1_Blend: Double,

    @SerialName("filter_1_blend_transpose")
    val filter1_BlendTranspose: Double,

    @SerialName("filter_1_cutoff")
    val filter1_Cutoff: Double,

    @SerialName("filter_1_drive")
    val filter1_Drive: Double,

    @SerialName("filter_1_filter_input")
    val filter1_FilterInput: Double,

    @SerialName("filter_1_formant_resonance")
    val filter1_FormantResonance: Double,

    @SerialName("filter_1_formant_spread")
    val filter1_FormantSpread: Double? = null,

    @SerialName("filter_1_formant_transpose")
    val filter1_FormantTranspose: Double,

    @SerialName("filter_1_formant_x")
    val filter1_FormantX: Double,

    @SerialName("filter_1_formant_y")
    val filter1_FormantY: Double,

    @SerialName("filter_1_keytrack")
    val filter1_Keytrack: Double,

    @SerialName("filter_1_mix")
    val filter1_Mix: Double,

    @SerialName("filter_1_model")
    val filter1_Model: Double,

    @SerialName("filter_1_on")
    val filter1_On: Double,

    @SerialName("filter_1_resonance")
    val filter1_Resonance: Double,

    @SerialName("filter_1_style")
    val filter1_Style: Double,

    @SerialName("filter_2_blend")
    val filter2_Blend: Double,

    @SerialName("filter_2_blend_transpose")
    val filter2_BlendTranspose: Double,

    @SerialName("filter_2_cutoff")
    val filter2_Cutoff: Double,

    @SerialName("filter_2_drive")
    val filter2_Drive: Double,

    @SerialName("filter_2_filter_input")
    val filter2_FilterInput: Double,

    @SerialName("filter_2_formant_resonance")
    val filter2_FormantResonance: Double,

    @SerialName("filter_2_formant_spread")
    val filter2_FormantSpread: Double? = null,

    @SerialName("filter_2_formant_transpose")
    val filter2_FormantTranspose: Double,

    @SerialName("filter_2_formant_x")
    val filter2_FormantX: Double,

    @SerialName("filter_2_formant_y")
    val filter2_FormantY: Double,

    @SerialName("filter_2_keytrack")
    val filter2_Keytrack: Double,

    @SerialName("filter_2_mix")
    val filter2_Mix: Double,

    @SerialName("filter_2_model")
    val filter2_Model: Double,

    @SerialName("filter_2_on")
    val filter2_On: Double,

    @SerialName("filter_2_resonance")
    val filter2_Resonance: Double,

    @SerialName("filter_2_style")
    val filter2_Style: Double,

    @SerialName("filter_fx_blend")
    val filterFxBlend: Double,

    @SerialName("filter_fx_blend_transpose")
    val filterFxBlendTranspose: Double,

    @SerialName("filter_fx_cutoff")
    val filterFxCutoff: Double,

    @SerialName("filter_fx_drive")
    val filterFxDrive: Double,

    @SerialName("filter_fx_formant_resonance")
    val filterFxFormantResonance: Double,

    @SerialName("filter_fx_formant_spread")
    val filterFxFormantSpread: Double? = null,

    @SerialName("filter_fx_formant_transpose")
    val filterFxFormantTranspose: Double,

    @SerialName("filter_fx_formant_x")
    val filterFxFormantX: Double,

    @SerialName("filter_fx_formant_y")
    val filterFxFormantY: Double,

    @SerialName("filter_fx_keytrack")
    val filterFxKeytrack: Double,

    @SerialName("filter_fx_mix")
    val filterFxMix: Double,

    @SerialName("filter_fx_model")
    val filterFxModel: Double,

    @SerialName("filter_fx_on")
    val filterFxOn: Double,

    @SerialName("filter_fx_resonance")
    val filterFxResonance: Double,

    @SerialName("filter_fx_style")
    val filterFxStyle: Double,

    @SerialName("flanger_center")
    val flangerCenter: Double,

    @SerialName("flanger_dry_wet")
    val flangerDryWet: Double,

    @SerialName("flanger_feedback")
    val flangerFeedback: Double,

    @SerialName("flanger_frequency")
    val flangerFrequency: Double,

    @SerialName("flanger_mod_depth")
    val flangerModDepth: Double,

    @SerialName("flanger_on")
    val flangerOn: Double,

    @SerialName("flanger_phase_offset")
    val flangerPhaseOffset: Double,

    @SerialName("flanger_sync")
    val flangerSync: Double,

    @SerialName("flanger_tempo")
    val flangerTempo: Double,

    val legato: Double,

    @SerialName("lfo_1_delay_time")
    val lfo1_DelayTime: Double,

    @SerialName("lfo_1_fade_time")
    val lfo1_FadeTime: Double,

    @SerialName("lfo_1_frequency")
    val lfo1_Frequency: Double,

    @SerialName("lfo_1_keytrack_transpose")
    val lfo1_KeytrackTranspose: Double? = null,

    @SerialName("lfo_1_keytrack_tune")
    val lfo1_KeytrackTune: Double? = null,

    @SerialName("lfo_1_phase")
    val lfo1_Phase: Double,

    @SerialName("lfo_1_smooth_mode")
    val lfo1_SmoothMode: Double? = null,

    @SerialName("lfo_1_smooth_time")
    val lfo1_SmoothTime: Double? = null,

    @SerialName("lfo_1_stereo")
    val lfo1_Stereo: Double,

    @SerialName("lfo_1_sync")
    val lfo1_Sync: Double,

    @SerialName("lfo_1_sync_type")
    val lfo1_SyncType: Double,

    @SerialName("lfo_1_tempo")
    val lfo1_Tempo: Double,

    @SerialName("lfo_2_delay_time")
    val lfo2_DelayTime: Double,

    @SerialName("lfo_2_fade_time")
    val lfo2_FadeTime: Double,

    @SerialName("lfo_2_frequency")
    val lfo2_Frequency: Double,

    @SerialName("lfo_2_keytrack_transpose")
    val lfo2_KeytrackTranspose: Double? = null,

    @SerialName("lfo_2_keytrack_tune")
    val lfo2_KeytrackTune: Double? = null,

    @SerialName("lfo_2_phase")
    val lfo2_Phase: Double,

    @SerialName("lfo_2_smooth_mode")
    val lfo2_SmoothMode: Double? = null,

    @SerialName("lfo_2_smooth_time")
    val lfo2_SmoothTime: Double? = null,

    @SerialName("lfo_2_stereo")
    val lfo2_Stereo: Double,

    @SerialName("lfo_2_sync")
    val lfo2_Sync: Double,

    @SerialName("lfo_2_sync_type")
    val lfo2_SyncType: Double,

    @SerialName("lfo_2_tempo")
    val lfo2_Tempo: Double,

    @SerialName("lfo_3_delay_time")
    val lfo3_DelayTime: Double,

    @SerialName("lfo_3_fade_time")
    val lfo3_FadeTime: Double,

    @SerialName("lfo_3_frequency")
    val lfo3_Frequency: Double,

    @SerialName("lfo_3_keytrack_transpose")
    val lfo3_KeytrackTranspose: Double? = null,

    @SerialName("lfo_3_keytrack_tune")
    val lfo3_KeytrackTune: Double? = null,

    @SerialName("lfo_3_phase")
    val lfo3_Phase: Double,

    @SerialName("lfo_3_smooth_mode")
    val lfo3_SmoothMode: Double? = null,

    @SerialName("lfo_3_smooth_time")
    val lfo3_SmoothTime: Double? = null,

    @SerialName("lfo_3_stereo")
    val lfo3_Stereo: Double,

    @SerialName("lfo_3_sync")
    val lfo3_Sync: Double,

    @SerialName("lfo_3_sync_type")
    val lfo3_SyncType: Double,

    @SerialName("lfo_3_tempo")
    val lfo3_Tempo: Double,

    @SerialName("lfo_4_delay_time")
    val lfo4_DelayTime: Double,

    @SerialName("lfo_4_fade_time")
    val lfo4_FadeTime: Double,

    @SerialName("lfo_4_frequency")
    val lfo4_Frequency: Double,

    @SerialName("lfo_4_keytrack_transpose")
    val lfo4_KeytrackTranspose: Double? = null,

    @SerialName("lfo_4_keytrack_tune")
    val lfo4_KeytrackTune: Double? = null,

    @SerialName("lfo_4_phase")
    val lfo4_Phase: Double,

    @SerialName("lfo_4_smooth_mode")
    val lfo4_SmoothMode: Double? = null,

    @SerialName("lfo_4_smooth_time")
    val lfo4_SmoothTime: Double? = null,

    @SerialName("lfo_4_stereo")
    val lfo4_Stereo: Double,

    @SerialName("lfo_4_sync")
    val lfo4_Sync: Double,

    @SerialName("lfo_4_sync_type")
    val lfo4_SyncType: Double,

    @SerialName("lfo_4_tempo")
    val lfo4_Tempo: Double,

    @SerialName("lfo_5_delay_time")
    val lfo5_DelayTime: Double,

    @SerialName("lfo_5_fade_time")
    val lfo5_FadeTime: Double,

    @SerialName("lfo_5_frequency")
    val lfo5_Frequency: Double,

    @SerialName("lfo_5_keytrack_transpose")
    val lfo5_KeytrackTranspose: Double? = null,

    @SerialName("lfo_5_keytrack_tune")
    val lfo5_KeytrackTune: Double? = null,

    @SerialName("lfo_5_phase")
    val lfo5_Phase: Double,

    @SerialName("lfo_5_smooth_mode")
    val lfo5_SmoothMode: Double? = null,

    @SerialName("lfo_5_smooth_time")
    val lfo5_SmoothTime: Double? = null,

    @SerialName("lfo_5_stereo")
    val lfo5_Stereo: Double,

    @SerialName("lfo_5_sync")
    val lfo5_Sync: Double,

    @SerialName("lfo_5_sync_type")
    val lfo5_SyncType: Double,

    @SerialName("lfo_5_tempo")
    val lfo5_Tempo: Double,

    @SerialName("lfo_6_delay_time")
    val lfo6_DelayTime: Double,

    @SerialName("lfo_6_fade_time")
    val lfo6_FadeTime: Double,

    @SerialName("lfo_6_frequency")
    val lfo6_Frequency: Double,

    @SerialName("lfo_6_keytrack_transpose")
    val lfo6_KeytrackTranspose: Double? = null,

    @SerialName("lfo_6_keytrack_tune")
    val lfo6_KeytrackTune: Double? = null,

    @SerialName("lfo_6_phase")
    val lfo6_Phase: Double,

    @SerialName("lfo_6_smooth_mode")
    val lfo6_SmoothMode: Double? = null,

    @SerialName("lfo_6_smooth_time")
    val lfo6_SmoothTime: Double? = null,

    @SerialName("lfo_6_stereo")
    val lfo6_Stereo: Double,

    @SerialName("lfo_6_sync")
    val lfo6_Sync: Double,

    @SerialName("lfo_6_sync_type")
    val lfo6_SyncType: Double,

    @SerialName("lfo_6_tempo")
    val lfo6_Tempo: Double,

    @SerialName("lfo_7_delay_time")
    val lfo7_DelayTime: Double,

    @SerialName("lfo_7_fade_time")
    val lfo7_FadeTime: Double,

    @SerialName("lfo_7_frequency")
    val lfo7_Frequency: Double,

    @SerialName("lfo_7_keytrack_transpose")
    val lfo7_KeytrackTranspose: Double? = null,

    @SerialName("lfo_7_keytrack_tune")
    val lfo7_KeytrackTune: Double? = null,

    @SerialName("lfo_7_phase")
    val lfo7_Phase: Double,

    @SerialName("lfo_7_smooth_mode")
    val lfo7_SmoothMode: Double? = null,

    @SerialName("lfo_7_smooth_time")
    val lfo7_SmoothTime: Double? = null,

    @SerialName("lfo_7_stereo")
    val lfo7_Stereo: Double,

    @SerialName("lfo_7_sync")
    val lfo7_Sync: Double,

    @SerialName("lfo_7_sync_type")
    val lfo7_SyncType: Double,

    @SerialName("lfo_7_tempo")
    val lfo7_Tempo: Double,

    @SerialName("lfo_8_delay_time")
    val lfo8_DelayTime: Double,

    @SerialName("lfo_8_fade_time")
    val lfo8_FadeTime: Double,

    @SerialName("lfo_8_frequency")
    val lfo8_Frequency: Double,

    @SerialName("lfo_8_keytrack_transpose")
    val lfo8_KeytrackTranspose: Double? = null,

    @SerialName("lfo_8_keytrack_tune")
    val lfo8_KeytrackTune: Double? = null,

    @SerialName("lfo_8_phase")
    val lfo8_Phase: Double,

    @SerialName("lfo_8_smooth_mode")
    val lfo8_SmoothMode: Double? = null,

    @SerialName("lfo_8_smooth_time")
    val lfo8_SmoothTime: Double? = null,

    @SerialName("lfo_8_stereo")
    val lfo8_Stereo: Double,

    @SerialName("lfo_8_sync")
    val lfo8_Sync: Double,

    @SerialName("lfo_8_sync_type")
    val lfo8_SyncType: Double,

    @SerialName("lfo_8_tempo")
    val lfo8_Tempo: Double,

    val lfos: List<Lfo>,

    @SerialName("macro_control_1")
    val macroControl1: Double,

    @SerialName("macro_control_2")
    val macroControl2: Double,

    @SerialName("macro_control_3")
    val macroControl3: Double,

    @SerialName("macro_control_4")
    val macroControl4: Double,

    @SerialName("mod_wheel")
    val modWheel: Double,

    @SerialName("modulation_10_amount")
    val modulation10_Amount: Double,

    @SerialName("modulation_10_bipolar")
    val modulation10_Bipolar: Double,

    @SerialName("modulation_10_bypass")
    val modulation10_Bypass: Double,

    @SerialName("modulation_10_power")
    val modulation10_Power: Double,

    @SerialName("modulation_10_stereo")
    val modulation10_Stereo: Double,

    @SerialName("modulation_11_amount")
    val modulation11_Amount: Double,

    @SerialName("modulation_11_bipolar")
    val modulation11_Bipolar: Double,

    @SerialName("modulation_11_bypass")
    val modulation11_Bypass: Double,

    @SerialName("modulation_11_power")
    val modulation11_Power: Double,

    @SerialName("modulation_11_stereo")
    val modulation11_Stereo: Double,

    @SerialName("modulation_12_amount")
    val modulation12_Amount: Double,

    @SerialName("modulation_12_bipolar")
    val modulation12_Bipolar: Double,

    @SerialName("modulation_12_bypass")
    val modulation12_Bypass: Double,

    @SerialName("modulation_12_power")
    val modulation12_Power: Double,

    @SerialName("modulation_12_stereo")
    val modulation12_Stereo: Double,

    @SerialName("modulation_13_amount")
    val modulation13_Amount: Double,

    @SerialName("modulation_13_bipolar")
    val modulation13_Bipolar: Double,

    @SerialName("modulation_13_bypass")
    val modulation13_Bypass: Double,

    @SerialName("modulation_13_power")
    val modulation13_Power: Double,

    @SerialName("modulation_13_stereo")
    val modulation13_Stereo: Double,

    @SerialName("modulation_14_amount")
    val modulation14_Amount: Double,

    @SerialName("modulation_14_bipolar")
    val modulation14_Bipolar: Double,

    @SerialName("modulation_14_bypass")
    val modulation14_Bypass: Double,

    @SerialName("modulation_14_power")
    val modulation14_Power: Double,

    @SerialName("modulation_14_stereo")
    val modulation14_Stereo: Double,

    @SerialName("modulation_15_amount")
    val modulation15_Amount: Double,

    @SerialName("modulation_15_bipolar")
    val modulation15_Bipolar: Double,

    @SerialName("modulation_15_bypass")
    val modulation15_Bypass: Double,

    @SerialName("modulation_15_power")
    val modulation15_Power: Double,

    @SerialName("modulation_15_stereo")
    val modulation15_Stereo: Double,

    @SerialName("modulation_16_amount")
    val modulation16_Amount: Double,

    @SerialName("modulation_16_bipolar")
    val modulation16_Bipolar: Double,

    @SerialName("modulation_16_bypass")
    val modulation16_Bypass: Double,

    @SerialName("modulation_16_power")
    val modulation16_Power: Double,

    @SerialName("modulation_16_stereo")
    val modulation16_Stereo: Double,

    @SerialName("modulation_17_amount")
    val modulation17_Amount: Double,

    @SerialName("modulation_17_bipolar")
    val modulation17_Bipolar: Double,

    @SerialName("modulation_17_bypass")
    val modulation17_Bypass: Double,

    @SerialName("modulation_17_power")
    val modulation17_Power: Double,

    @SerialName("modulation_17_stereo")
    val modulation17_Stereo: Double,

    @SerialName("modulation_18_amount")
    val modulation18_Amount: Double,

    @SerialName("modulation_18_bipolar")
    val modulation18_Bipolar: Double,

    @SerialName("modulation_18_bypass")
    val modulation18_Bypass: Double,

    @SerialName("modulation_18_power")
    val modulation18_Power: Double,

    @SerialName("modulation_18_stereo")
    val modulation18_Stereo: Double,

    @SerialName("modulation_19_amount")
    val modulation19_Amount: Double,

    @SerialName("modulation_19_bipolar")
    val modulation19_Bipolar: Double,

    @SerialName("modulation_19_bypass")
    val modulation19_Bypass: Double,

    @SerialName("modulation_19_power")
    val modulation19_Power: Double,

    @SerialName("modulation_19_stereo")
    val modulation19_Stereo: Double,

    @SerialName("modulation_1_amount")
    val modulation1_Amount: Double,

    @SerialName("modulation_1_bipolar")
    val modulation1_Bipolar: Double,

    @SerialName("modulation_1_bypass")
    val modulation1_Bypass: Double,

    @SerialName("modulation_1_power")
    val modulation1_Power: Double,

    @SerialName("modulation_1_stereo")
    val modulation1_Stereo: Double,

    @SerialName("modulation_20_amount")
    val modulation20_Amount: Double,

    @SerialName("modulation_20_bipolar")
    val modulation20_Bipolar: Double,

    @SerialName("modulation_20_bypass")
    val modulation20_Bypass: Double,

    @SerialName("modulation_20_power")
    val modulation20_Power: Double,

    @SerialName("modulation_20_stereo")
    val modulation20_Stereo: Double,

    @SerialName("modulation_21_amount")
    val modulation21_Amount: Double,

    @SerialName("modulation_21_bipolar")
    val modulation21_Bipolar: Double,

    @SerialName("modulation_21_bypass")
    val modulation21_Bypass: Double,

    @SerialName("modulation_21_power")
    val modulation21_Power: Double,

    @SerialName("modulation_21_stereo")
    val modulation21_Stereo: Double,

    @SerialName("modulation_22_amount")
    val modulation22_Amount: Double,

    @SerialName("modulation_22_bipolar")
    val modulation22_Bipolar: Double,

    @SerialName("modulation_22_bypass")
    val modulation22_Bypass: Double,

    @SerialName("modulation_22_power")
    val modulation22_Power: Double,

    @SerialName("modulation_22_stereo")
    val modulation22_Stereo: Double,

    @SerialName("modulation_23_amount")
    val modulation23_Amount: Double,

    @SerialName("modulation_23_bipolar")
    val modulation23_Bipolar: Double,

    @SerialName("modulation_23_bypass")
    val modulation23_Bypass: Double,

    @SerialName("modulation_23_power")
    val modulation23_Power: Double,

    @SerialName("modulation_23_stereo")
    val modulation23_Stereo: Double,

    @SerialName("modulation_24_amount")
    val modulation24_Amount: Double,

    @SerialName("modulation_24_bipolar")
    val modulation24_Bipolar: Double,

    @SerialName("modulation_24_bypass")
    val modulation24_Bypass: Double,

    @SerialName("modulation_24_power")
    val modulation24_Power: Double,

    @SerialName("modulation_24_stereo")
    val modulation24_Stereo: Double,

    @SerialName("modulation_25_amount")
    val modulation25_Amount: Double,

    @SerialName("modulation_25_bipolar")
    val modulation25_Bipolar: Double,

    @SerialName("modulation_25_bypass")
    val modulation25_Bypass: Double,

    @SerialName("modulation_25_power")
    val modulation25_Power: Double,

    @SerialName("modulation_25_stereo")
    val modulation25_Stereo: Double,

    @SerialName("modulation_26_amount")
    val modulation26_Amount: Double,

    @SerialName("modulation_26_bipolar")
    val modulation26_Bipolar: Double,

    @SerialName("modulation_26_bypass")
    val modulation26_Bypass: Double,

    @SerialName("modulation_26_power")
    val modulation26_Power: Double,

    @SerialName("modulation_26_stereo")
    val modulation26_Stereo: Double,

    @SerialName("modulation_27_amount")
    val modulation27_Amount: Double,

    @SerialName("modulation_27_bipolar")
    val modulation27_Bipolar: Double,

    @SerialName("modulation_27_bypass")
    val modulation27_Bypass: Double,

    @SerialName("modulation_27_power")
    val modulation27_Power: Double,

    @SerialName("modulation_27_stereo")
    val modulation27_Stereo: Double,

    @SerialName("modulation_28_amount")
    val modulation28_Amount: Double,

    @SerialName("modulation_28_bipolar")
    val modulation28_Bipolar: Double,

    @SerialName("modulation_28_bypass")
    val modulation28_Bypass: Double,

    @SerialName("modulation_28_power")
    val modulation28_Power: Double,

    @SerialName("modulation_28_stereo")
    val modulation28_Stereo: Double,

    @SerialName("modulation_29_amount")
    val modulation29_Amount: Double,

    @SerialName("modulation_29_bipolar")
    val modulation29_Bipolar: Double,

    @SerialName("modulation_29_bypass")
    val modulation29_Bypass: Double,

    @SerialName("modulation_29_power")
    val modulation29_Power: Double,

    @SerialName("modulation_29_stereo")
    val modulation29_Stereo: Double,

    @SerialName("modulation_2_amount")
    val modulation2_Amount: Double,

    @SerialName("modulation_2_bipolar")
    val modulation2_Bipolar: Double,

    @SerialName("modulation_2_bypass")
    val modulation2_Bypass: Double,

    @SerialName("modulation_2_power")
    val modulation2_Power: Double,

    @SerialName("modulation_2_stereo")
    val modulation2_Stereo: Double,

    @SerialName("modulation_30_amount")
    val modulation30_Amount: Double,

    @SerialName("modulation_30_bipolar")
    val modulation30_Bipolar: Double,

    @SerialName("modulation_30_bypass")
    val modulation30_Bypass: Double,

    @SerialName("modulation_30_power")
    val modulation30_Power: Double,

    @SerialName("modulation_30_stereo")
    val modulation30_Stereo: Double,

    @SerialName("modulation_31_amount")
    val modulation31_Amount: Double,

    @SerialName("modulation_31_bipolar")
    val modulation31_Bipolar: Double,

    @SerialName("modulation_31_bypass")
    val modulation31_Bypass: Double,

    @SerialName("modulation_31_power")
    val modulation31_Power: Double,

    @SerialName("modulation_31_stereo")
    val modulation31_Stereo: Double,

    @SerialName("modulation_32_amount")
    val modulation32_Amount: Double,

    @SerialName("modulation_32_bipolar")
    val modulation32_Bipolar: Double,

    @SerialName("modulation_32_bypass")
    val modulation32_Bypass: Double,

    @SerialName("modulation_32_power")
    val modulation32_Power: Double,

    @SerialName("modulation_32_stereo")
    val modulation32_Stereo: Double,

    @SerialName("modulation_33_amount")
    val modulation33_Amount: Double,

    @SerialName("modulation_33_bipolar")
    val modulation33_Bipolar: Double,

    @SerialName("modulation_33_bypass")
    val modulation33_Bypass: Double,

    @SerialName("modulation_33_power")
    val modulation33_Power: Double,

    @SerialName("modulation_33_stereo")
    val modulation33_Stereo: Double,

    @SerialName("modulation_34_amount")
    val modulation34_Amount: Double,

    @SerialName("modulation_34_bipolar")
    val modulation34_Bipolar: Double,

    @SerialName("modulation_34_bypass")
    val modulation34_Bypass: Double,

    @SerialName("modulation_34_power")
    val modulation34_Power: Double,

    @SerialName("modulation_34_stereo")
    val modulation34_Stereo: Double,

    @SerialName("modulation_35_amount")
    val modulation35_Amount: Double,

    @SerialName("modulation_35_bipolar")
    val modulation35_Bipolar: Double,

    @SerialName("modulation_35_bypass")
    val modulation35_Bypass: Double,

    @SerialName("modulation_35_power")
    val modulation35_Power: Double,

    @SerialName("modulation_35_stereo")
    val modulation35_Stereo: Double,

    @SerialName("modulation_36_amount")
    val modulation36_Amount: Double,

    @SerialName("modulation_36_bipolar")
    val modulation36_Bipolar: Double,

    @SerialName("modulation_36_bypass")
    val modulation36_Bypass: Double,

    @SerialName("modulation_36_power")
    val modulation36_Power: Double,

    @SerialName("modulation_36_stereo")
    val modulation36_Stereo: Double,

    @SerialName("modulation_37_amount")
    val modulation37_Amount: Double,

    @SerialName("modulation_37_bipolar")
    val modulation37_Bipolar: Double,

    @SerialName("modulation_37_bypass")
    val modulation37_Bypass: Double,

    @SerialName("modulation_37_power")
    val modulation37_Power: Double,

    @SerialName("modulation_37_stereo")
    val modulation37_Stereo: Double,

    @SerialName("modulation_38_amount")
    val modulation38_Amount: Double,

    @SerialName("modulation_38_bipolar")
    val modulation38_Bipolar: Double,

    @SerialName("modulation_38_bypass")
    val modulation38_Bypass: Double,

    @SerialName("modulation_38_power")
    val modulation38_Power: Double,

    @SerialName("modulation_38_stereo")
    val modulation38_Stereo: Double,

    @SerialName("modulation_39_amount")
    val modulation39_Amount: Double,

    @SerialName("modulation_39_bipolar")
    val modulation39_Bipolar: Double,

    @SerialName("modulation_39_bypass")
    val modulation39_Bypass: Double,

    @SerialName("modulation_39_power")
    val modulation39_Power: Double,

    @SerialName("modulation_39_stereo")
    val modulation39_Stereo: Double,

    @SerialName("modulation_3_amount")
    val modulation3_Amount: Double,

    @SerialName("modulation_3_bipolar")
    val modulation3_Bipolar: Double,

    @SerialName("modulation_3_bypass")
    val modulation3_Bypass: Double,

    @SerialName("modulation_3_power")
    val modulation3_Power: Double,

    @SerialName("modulation_3_stereo")
    val modulation3_Stereo: Double,

    @SerialName("modulation_40_amount")
    val modulation40_Amount: Double,

    @SerialName("modulation_40_bipolar")
    val modulation40_Bipolar: Double,

    @SerialName("modulation_40_bypass")
    val modulation40_Bypass: Double,

    @SerialName("modulation_40_power")
    val modulation40_Power: Double,

    @SerialName("modulation_40_stereo")
    val modulation40_Stereo: Double,

    @SerialName("modulation_41_amount")
    val modulation41_Amount: Double,

    @SerialName("modulation_41_bipolar")
    val modulation41_Bipolar: Double,

    @SerialName("modulation_41_bypass")
    val modulation41_Bypass: Double,

    @SerialName("modulation_41_power")
    val modulation41_Power: Double,

    @SerialName("modulation_41_stereo")
    val modulation41_Stereo: Double,

    @SerialName("modulation_42_amount")
    val modulation42_Amount: Double,

    @SerialName("modulation_42_bipolar")
    val modulation42_Bipolar: Double,

    @SerialName("modulation_42_bypass")
    val modulation42_Bypass: Double,

    @SerialName("modulation_42_power")
    val modulation42_Power: Double,

    @SerialName("modulation_42_stereo")
    val modulation42_Stereo: Double,

    @SerialName("modulation_43_amount")
    val modulation43_Amount: Double,

    @SerialName("modulation_43_bipolar")
    val modulation43_Bipolar: Double,

    @SerialName("modulation_43_bypass")
    val modulation43_Bypass: Double,

    @SerialName("modulation_43_power")
    val modulation43_Power: Double,

    @SerialName("modulation_43_stereo")
    val modulation43_Stereo: Double,

    @SerialName("modulation_44_amount")
    val modulation44_Amount: Double,

    @SerialName("modulation_44_bipolar")
    val modulation44_Bipolar: Double,

    @SerialName("modulation_44_bypass")
    val modulation44_Bypass: Double,

    @SerialName("modulation_44_power")
    val modulation44_Power: Double,

    @SerialName("modulation_44_stereo")
    val modulation44_Stereo: Double,

    @SerialName("modulation_45_amount")
    val modulation45_Amount: Double,

    @SerialName("modulation_45_bipolar")
    val modulation45_Bipolar: Double,

    @SerialName("modulation_45_bypass")
    val modulation45_Bypass: Double,

    @SerialName("modulation_45_power")
    val modulation45_Power: Double,

    @SerialName("modulation_45_stereo")
    val modulation45_Stereo: Double,

    @SerialName("modulation_46_amount")
    val modulation46_Amount: Double,

    @SerialName("modulation_46_bipolar")
    val modulation46_Bipolar: Double,

    @SerialName("modulation_46_bypass")
    val modulation46_Bypass: Double,

    @SerialName("modulation_46_power")
    val modulation46_Power: Double,

    @SerialName("modulation_46_stereo")
    val modulation46_Stereo: Double,

    @SerialName("modulation_47_amount")
    val modulation47_Amount: Double,

    @SerialName("modulation_47_bipolar")
    val modulation47_Bipolar: Double,

    @SerialName("modulation_47_bypass")
    val modulation47_Bypass: Double,

    @SerialName("modulation_47_power")
    val modulation47_Power: Double,

    @SerialName("modulation_47_stereo")
    val modulation47_Stereo: Double,

    @SerialName("modulation_48_amount")
    val modulation48_Amount: Double,

    @SerialName("modulation_48_bipolar")
    val modulation48_Bipolar: Double,

    @SerialName("modulation_48_bypass")
    val modulation48_Bypass: Double,

    @SerialName("modulation_48_power")
    val modulation48_Power: Double,

    @SerialName("modulation_48_stereo")
    val modulation48_Stereo: Double,

    @SerialName("modulation_49_amount")
    val modulation49_Amount: Double,

    @SerialName("modulation_49_bipolar")
    val modulation49_Bipolar: Double,

    @SerialName("modulation_49_bypass")
    val modulation49_Bypass: Double,

    @SerialName("modulation_49_power")
    val modulation49_Power: Double,

    @SerialName("modulation_49_stereo")
    val modulation49_Stereo: Double,

    @SerialName("modulation_4_amount")
    val modulation4_Amount: Double,

    @SerialName("modulation_4_bipolar")
    val modulation4_Bipolar: Double,

    @SerialName("modulation_4_bypass")
    val modulation4_Bypass: Double,

    @SerialName("modulation_4_power")
    val modulation4_Power: Double,

    @SerialName("modulation_4_stereo")
    val modulation4_Stereo: Double,

    @SerialName("modulation_50_amount")
    val modulation50_Amount: Double,

    @SerialName("modulation_50_bipolar")
    val modulation50_Bipolar: Double,

    @SerialName("modulation_50_bypass")
    val modulation50_Bypass: Double,

    @SerialName("modulation_50_power")
    val modulation50_Power: Double,

    @SerialName("modulation_50_stereo")
    val modulation50_Stereo: Double,

    @SerialName("modulation_51_amount")
    val modulation51_Amount: Double,

    @SerialName("modulation_51_bipolar")
    val modulation51_Bipolar: Double,

    @SerialName("modulation_51_bypass")
    val modulation51_Bypass: Double,

    @SerialName("modulation_51_power")
    val modulation51_Power: Double,

    @SerialName("modulation_51_stereo")
    val modulation51_Stereo: Double,

    @SerialName("modulation_52_amount")
    val modulation52_Amount: Double,

    @SerialName("modulation_52_bipolar")
    val modulation52_Bipolar: Double,

    @SerialName("modulation_52_bypass")
    val modulation52_Bypass: Double,

    @SerialName("modulation_52_power")
    val modulation52_Power: Double,

    @SerialName("modulation_52_stereo")
    val modulation52_Stereo: Double,

    @SerialName("modulation_53_amount")
    val modulation53_Amount: Double,

    @SerialName("modulation_53_bipolar")
    val modulation53_Bipolar: Double,

    @SerialName("modulation_53_bypass")
    val modulation53_Bypass: Double,

    @SerialName("modulation_53_power")
    val modulation53_Power: Double,

    @SerialName("modulation_53_stereo")
    val modulation53_Stereo: Double,

    @SerialName("modulation_54_amount")
    val modulation54_Amount: Double,

    @SerialName("modulation_54_bipolar")
    val modulation54_Bipolar: Double,

    @SerialName("modulation_54_bypass")
    val modulation54_Bypass: Double,

    @SerialName("modulation_54_power")
    val modulation54_Power: Double,

    @SerialName("modulation_54_stereo")
    val modulation54_Stereo: Double,

    @SerialName("modulation_55_amount")
    val modulation55_Amount: Double,

    @SerialName("modulation_55_bipolar")
    val modulation55_Bipolar: Double,

    @SerialName("modulation_55_bypass")
    val modulation55_Bypass: Double,

    @SerialName("modulation_55_power")
    val modulation55_Power: Double,

    @SerialName("modulation_55_stereo")
    val modulation55_Stereo: Double,

    @SerialName("modulation_56_amount")
    val modulation56_Amount: Double,

    @SerialName("modulation_56_bipolar")
    val modulation56_Bipolar: Double,

    @SerialName("modulation_56_bypass")
    val modulation56_Bypass: Double,

    @SerialName("modulation_56_power")
    val modulation56_Power: Double,

    @SerialName("modulation_56_stereo")
    val modulation56_Stereo: Double,

    @SerialName("modulation_57_amount")
    val modulation57_Amount: Double,

    @SerialName("modulation_57_bipolar")
    val modulation57_Bipolar: Double,

    @SerialName("modulation_57_bypass")
    val modulation57_Bypass: Double,

    @SerialName("modulation_57_power")
    val modulation57_Power: Double,

    @SerialName("modulation_57_stereo")
    val modulation57_Stereo: Double,

    @SerialName("modulation_58_amount")
    val modulation58_Amount: Double,

    @SerialName("modulation_58_bipolar")
    val modulation58_Bipolar: Double,

    @SerialName("modulation_58_bypass")
    val modulation58_Bypass: Double,

    @SerialName("modulation_58_power")
    val modulation58_Power: Double,

    @SerialName("modulation_58_stereo")
    val modulation58_Stereo: Double,

    @SerialName("modulation_59_amount")
    val modulation59_Amount: Double,

    @SerialName("modulation_59_bipolar")
    val modulation59_Bipolar: Double,

    @SerialName("modulation_59_bypass")
    val modulation59_Bypass: Double,

    @SerialName("modulation_59_power")
    val modulation59_Power: Double,

    @SerialName("modulation_59_stereo")
    val modulation59_Stereo: Double,

    @SerialName("modulation_5_amount")
    val modulation5_Amount: Double,

    @SerialName("modulation_5_bipolar")
    val modulation5_Bipolar: Double,

    @SerialName("modulation_5_bypass")
    val modulation5_Bypass: Double,

    @SerialName("modulation_5_power")
    val modulation5_Power: Double,

    @SerialName("modulation_5_stereo")
    val modulation5_Stereo: Double,

    @SerialName("modulation_60_amount")
    val modulation60_Amount: Double,

    @SerialName("modulation_60_bipolar")
    val modulation60_Bipolar: Double,

    @SerialName("modulation_60_bypass")
    val modulation60_Bypass: Double,

    @SerialName("modulation_60_power")
    val modulation60_Power: Double,

    @SerialName("modulation_60_stereo")
    val modulation60_Stereo: Double,

    @SerialName("modulation_61_amount")
    val modulation61_Amount: Double,

    @SerialName("modulation_61_bipolar")
    val modulation61_Bipolar: Double,

    @SerialName("modulation_61_bypass")
    val modulation61_Bypass: Double,

    @SerialName("modulation_61_power")
    val modulation61_Power: Double,

    @SerialName("modulation_61_stereo")
    val modulation61_Stereo: Double,

    @SerialName("modulation_62_amount")
    val modulation62_Amount: Double,

    @SerialName("modulation_62_bipolar")
    val modulation62_Bipolar: Double,

    @SerialName("modulation_62_bypass")
    val modulation62_Bypass: Double,

    @SerialName("modulation_62_power")
    val modulation62_Power: Double,

    @SerialName("modulation_62_stereo")
    val modulation62_Stereo: Double,

    @SerialName("modulation_63_amount")
    val modulation63_Amount: Double,

    @SerialName("modulation_63_bipolar")
    val modulation63_Bipolar: Double,

    @SerialName("modulation_63_bypass")
    val modulation63_Bypass: Double,

    @SerialName("modulation_63_power")
    val modulation63_Power: Double,

    @SerialName("modulation_63_stereo")
    val modulation63_Stereo: Double,

    @SerialName("modulation_64_amount")
    val modulation64_Amount: Double,

    @SerialName("modulation_64_bipolar")
    val modulation64_Bipolar: Double,

    @SerialName("modulation_64_bypass")
    val modulation64_Bypass: Double,

    @SerialName("modulation_64_power")
    val modulation64_Power: Double,

    @SerialName("modulation_64_stereo")
    val modulation64_Stereo: Double,

    @SerialName("modulation_6_amount")
    val modulation6_Amount: Double,

    @SerialName("modulation_6_bipolar")
    val modulation6_Bipolar: Double,

    @SerialName("modulation_6_bypass")
    val modulation6_Bypass: Double,

    @SerialName("modulation_6_power")
    val modulation6_Power: Double,

    @SerialName("modulation_6_stereo")
    val modulation6_Stereo: Double,

    @SerialName("modulation_7_amount")
    val modulation7_Amount: Double,

    @SerialName("modulation_7_bipolar")
    val modulation7_Bipolar: Double,

    @SerialName("modulation_7_bypass")
    val modulation7_Bypass: Double,

    @SerialName("modulation_7_power")
    val modulation7_Power: Double,

    @SerialName("modulation_7_stereo")
    val modulation7_Stereo: Double,

    @SerialName("modulation_8_amount")
    val modulation8_Amount: Double,

    @SerialName("modulation_8_bipolar")
    val modulation8_Bipolar: Double,

    @SerialName("modulation_8_bypass")
    val modulation8_Bypass: Double,

    @SerialName("modulation_8_power")
    val modulation8_Power: Double,

    @SerialName("modulation_8_stereo")
    val modulation8_Stereo: Double,

    @SerialName("modulation_9_amount")
    val modulation9_Amount: Double,

    @SerialName("modulation_9_bipolar")
    val modulation9_Bipolar: Double,

    @SerialName("modulation_9_bypass")
    val modulation9_Bypass: Double,

    @SerialName("modulation_9_power")
    val modulation9_Power: Double,

    @SerialName("modulation_9_stereo")
    val modulation9_Stereo: Double,

    val modulations: List<Modulation>,

    @SerialName("osc_1_destination")
    val osc1_Destination: Double,

    @SerialName("osc_1_detune_power")
    val osc1_DetunePower: Double,

    @SerialName("osc_1_detune_range")
    val osc1_DetuneRange: Double,

    @SerialName("osc_1_distortion_amount")
    val osc1_DistortionAmount: Double,

    @SerialName("osc_1_distortion_phase")
    val osc1_DistortionPhase: Double,

    @SerialName("osc_1_distortion_spread")
    val osc1_DistortionSpread: Double,

    @SerialName("osc_1_distortion_type")
    val osc1_DistortionType: Double,

    @SerialName("osc_1_frame_spread")
    val osc1_FrameSpread: Double,

    @SerialName("osc_1_level")
    val osc1_Level: Double,

    @SerialName("osc_1_midi_track")
    val osc1_MIDITrack: Double,

    @SerialName("osc_1_on")
    val osc1_On: Double,

    @SerialName("osc_1_pan")
    val osc1_Pan: Double,

    @SerialName("osc_1_phase")
    val osc1_Phase: Double,

    @SerialName("osc_1_random_phase")
    val osc1_RandomPhase: Double,

    @SerialName("osc_1_smooth_interpolation")
    val osc1_SmoothInterpolation: Double,

    @SerialName("osc_1_spectral_morph_amount")
    val osc1_SpectralMorphAmount: Double,

    @SerialName("osc_1_spectral_morph_spread")
    val osc1_SpectralMorphSpread: Double,

    @SerialName("osc_1_spectral_morph_type")
    val osc1_SpectralMorphType: Double,

    @SerialName("osc_1_spectral_unison")
    val osc1_SpectralUnison: Double,

    @SerialName("osc_1_stack_style")
    val osc1_StackStyle: Double,

    @SerialName("osc_1_stereo_spread")
    val osc1_StereoSpread: Double,

    @SerialName("osc_1_transpose")
    val osc1_Transpose: Double,

    @SerialName("osc_1_transpose_quantize")
    val osc1_TransposeQuantize: Double,

    @SerialName("osc_1_tune")
    val osc1_Tune: Double,

    @SerialName("osc_1_unison_blend")
    val osc1_UnisonBlend: Double,

    @SerialName("osc_1_unison_detune")
    val osc1_UnisonDetune: Double,

    @SerialName("osc_1_unison_voices")
    val osc1_UnisonVoices: Double,

    @SerialName("osc_1_view_2d")
    val osc1_View2D: Double,

    @SerialName("osc_1_wave_frame")
    val osc1_WaveFrame: Double,

    @SerialName("osc_2_destination")
    val osc2_Destination: Double,

    @SerialName("osc_2_detune_power")
    val osc2_DetunePower: Double,

    @SerialName("osc_2_detune_range")
    val osc2_DetuneRange: Double,

    @SerialName("osc_2_distortion_amount")
    val osc2_DistortionAmount: Double,

    @SerialName("osc_2_distortion_phase")
    val osc2_DistortionPhase: Double,

    @SerialName("osc_2_distortion_spread")
    val osc2_DistortionSpread: Double,

    @SerialName("osc_2_distortion_type")
    val osc2_DistortionType: Double,

    @SerialName("osc_2_frame_spread")
    val osc2_FrameSpread: Double,

    @SerialName("osc_2_level")
    val osc2_Level: Double,

    @SerialName("osc_2_midi_track")
    val osc2_MIDITrack: Double,

    @SerialName("osc_2_on")
    val osc2_On: Double,

    @SerialName("osc_2_pan")
    val osc2_Pan: Double,

    @SerialName("osc_2_phase")
    val osc2_Phase: Double,

    @SerialName("osc_2_random_phase")
    val osc2_RandomPhase: Double,

    @SerialName("osc_2_smooth_interpolation")
    val osc2_SmoothInterpolation: Double,

    @SerialName("osc_2_spectral_morph_amount")
    val osc2_SpectralMorphAmount: Double,

    @SerialName("osc_2_spectral_morph_spread")
    val osc2_SpectralMorphSpread: Double,

    @SerialName("osc_2_spectral_morph_type")
    val osc2_SpectralMorphType: Double,

    @SerialName("osc_2_spectral_unison")
    val osc2_SpectralUnison: Double,

    @SerialName("osc_2_stack_style")
    val osc2_StackStyle: Double,

    @SerialName("osc_2_stereo_spread")
    val osc2_StereoSpread: Double,

    @SerialName("osc_2_transpose")
    val osc2_Transpose: Double,

    @SerialName("osc_2_transpose_quantize")
    val osc2_TransposeQuantize: Double,

    @SerialName("osc_2_tune")
    val osc2_Tune: Double,

    @SerialName("osc_2_unison_blend")
    val osc2_UnisonBlend: Double,

    @SerialName("osc_2_unison_detune")
    val osc2_UnisonDetune: Double,

    @SerialName("osc_2_unison_voices")
    val osc2_UnisonVoices: Double,

    @SerialName("osc_2_view_2d")
    val osc2_View2D: Double,

    @SerialName("osc_2_wave_frame")
    val osc2_WaveFrame: Double,

    @SerialName("osc_3_destination")
    val osc3_Destination: Double,

    @SerialName("osc_3_detune_power")
    val osc3_DetunePower: Double,

    @SerialName("osc_3_detune_range")
    val osc3_DetuneRange: Double,

    @SerialName("osc_3_distortion_amount")
    val osc3_DistortionAmount: Double,

    @SerialName("osc_3_distortion_phase")
    val osc3_DistortionPhase: Double,

    @SerialName("osc_3_distortion_spread")
    val osc3_DistortionSpread: Double,

    @SerialName("osc_3_distortion_type")
    val osc3_DistortionType: Double,

    @SerialName("osc_3_frame_spread")
    val osc3_FrameSpread: Double,

    @SerialName("osc_3_level")
    val osc3_Level: Double,

    @SerialName("osc_3_midi_track")
    val osc3_MIDITrack: Double,

    @SerialName("osc_3_on")
    val osc3_On: Double,

    @SerialName("osc_3_pan")
    val osc3_Pan: Double,

    @SerialName("osc_3_phase")
    val osc3_Phase: Double,

    @SerialName("osc_3_random_phase")
    val osc3_RandomPhase: Double,

    @SerialName("osc_3_smooth_interpolation")
    val osc3_SmoothInterpolation: Double,

    @SerialName("osc_3_spectral_morph_amount")
    val osc3_SpectralMorphAmount: Double,

    @SerialName("osc_3_spectral_morph_spread")
    val osc3_SpectralMorphSpread: Double,

    @SerialName("osc_3_spectral_morph_type")
    val osc3_SpectralMorphType: Double,

    @SerialName("osc_3_spectral_unison")
    val osc3_SpectralUnison: Double,

    @SerialName("osc_3_stack_style")
    val osc3_StackStyle: Double,

    @SerialName("osc_3_stereo_spread")
    val osc3_StereoSpread: Double,

    @SerialName("osc_3_transpose")
    val osc3_Transpose: Double,

    @SerialName("osc_3_transpose_quantize")
    val osc3_TransposeQuantize: Double,

    @SerialName("osc_3_tune")
    val osc3_Tune: Double,

    @SerialName("osc_3_unison_blend")
    val osc3_UnisonBlend: Double,

    @SerialName("osc_3_unison_detune")
    val osc3_UnisonDetune: Double,

    @SerialName("osc_3_unison_voices")
    val osc3_UnisonVoices: Double,

    @SerialName("osc_3_view_2d")
    val osc3_View2D: Double,

    @SerialName("osc_3_wave_frame")
    val osc3_WaveFrame: Double,

    val oversampling: Double,

    @SerialName("phaser_blend")
    val phaserBlend: Double,

    @SerialName("phaser_center")
    val phaserCenter: Double,

    @SerialName("phaser_dry_wet")
    val phaserDryWet: Double,

    @SerialName("phaser_feedback")
    val phaserFeedback: Double,

    @SerialName("phaser_frequency")
    val phaserFrequency: Double,

    @SerialName("phaser_mod_depth")
    val phaserModDepth: Double,

    @SerialName("phaser_on")
    val phaserOn: Double,

    @SerialName("phaser_phase_offset")
    val phaserPhaseOffset: Double,

    @SerialName("phaser_sync")
    val phaserSync: Double,

    @SerialName("phaser_tempo")
    val phaserTempo: Double,

    @SerialName("pitch_bend_range")
    val pitchBendRange: Double,

    @SerialName("pitch_wheel")
    val pitchWheel: Double,

    val polyphony: Double,

    @SerialName("portamento_force")
    val portamentoForce: Double,

    @SerialName("portamento_scale")
    val portamentoScale: Double,

    @SerialName("portamento_slope")
    val portamentoSlope: Double,

    @SerialName("portamento_time")
    val portamentoTime: Double,

    @SerialName("random_1_frequency")
    val random1_Frequency: Double,

    @SerialName("random_1_keytrack_transpose")
    val random1_KeytrackTranspose: Double? = null,

    @SerialName("random_1_keytrack_tune")
    val random1_KeytrackTune: Double? = null,

    @SerialName("random_1_stereo")
    val random1_Stereo: Double,

    @SerialName("random_1_style")
    val random1_Style: Double,

    @SerialName("random_1_sync")
    val random1_Sync: Double,

    @SerialName("random_1_sync_type")
    val random1_SyncType: Double,

    @SerialName("random_1_tempo")
    val random1_Tempo: Double,

    @SerialName("random_2_frequency")
    val random2_Frequency: Double,

    @SerialName("random_2_keytrack_transpose")
    val random2_KeytrackTranspose: Double? = null,

    @SerialName("random_2_keytrack_tune")
    val random2_KeytrackTune: Double? = null,

    @SerialName("random_2_stereo")
    val random2_Stereo: Double,

    @SerialName("random_2_style")
    val random2_Style: Double,

    @SerialName("random_2_sync")
    val random2_Sync: Double,

    @SerialName("random_2_sync_type")
    val random2_SyncType: Double,

    @SerialName("random_2_tempo")
    val random2_Tempo: Double,

    @SerialName("random_3_frequency")
    val random3_Frequency: Double,

    @SerialName("random_3_keytrack_transpose")
    val random3_KeytrackTranspose: Double? = null,

    @SerialName("random_3_keytrack_tune")
    val random3_KeytrackTune: Double? = null,

    @SerialName("random_3_stereo")
    val random3_Stereo: Double,

    @SerialName("random_3_style")
    val random3_Style: Double,

    @SerialName("random_3_sync")
    val random3_Sync: Double,

    @SerialName("random_3_sync_type")
    val random3_SyncType: Double,

    @SerialName("random_3_tempo")
    val random3_Tempo: Double,

    @SerialName("random_4_frequency")
    val random4_Frequency: Double,

    @SerialName("random_4_keytrack_transpose")
    val random4_KeytrackTranspose: Double? = null,

    @SerialName("random_4_keytrack_tune")
    val random4_KeytrackTune: Double? = null,

    @SerialName("random_4_stereo")
    val random4_Stereo: Double,

    @SerialName("random_4_style")
    val random4_Style: Double,

    @SerialName("random_4_sync")
    val random4_Sync: Double,

    @SerialName("random_4_sync_type")
    val random4_SyncType: Double,

    @SerialName("random_4_tempo")
    val random4_Tempo: Double,

    @SerialName("reverb_chorus_amount")
    val reverbChorusAmount: Double,

    @SerialName("reverb_chorus_frequency")
    val reverbChorusFrequency: Double,

    @SerialName("reverb_decay_time")
    val reverbDecayTime: Double,

    @SerialName("reverb_delay")
    val reverbDelay: Double? = null,

    @SerialName("reverb_dry_wet")
    val reverbDryWet: Double,

    @SerialName("reverb_high_shelf_cutoff")
    val reverbHighShelfCutoff: Double,

    @SerialName("reverb_high_shelf_gain")
    val reverbHighShelfGain: Double,

    @SerialName("reverb_low_shelf_cutoff")
    val reverbLowShelfCutoff: Double,

    @SerialName("reverb_low_shelf_gain")
    val reverbLowShelfGain: Double,

    @SerialName("reverb_on")
    val reverbOn: Double,

    @SerialName("reverb_pre_high_cutoff")
    val reverbPreHighCutoff: Double,

    @SerialName("reverb_pre_low_cutoff")
    val reverbPreLowCutoff: Double,

    @SerialName("reverb_size")
    val reverbSize: Double,

    val sample: Sample,

    @SerialName("sample_bounce")
    val sampleBounce: Double? = null,

    @SerialName("sample_destination")
    val sampleDestination: Double,

    @SerialName("sample_keytrack")
    val sampleKeytrack: Double,

    @SerialName("sample_level")
    val sampleLevel: Double,

    @SerialName("sample_loop")
    val sampleLoop: Double,

    @SerialName("sample_on")
    val sampleOn: Double,

    @SerialName("sample_pan")
    val samplePan: Double,

    @SerialName("sample_random_phase")
    val sampleRandomPhase: Double,

    @SerialName("sample_transpose")
    val sampleTranspose: Double,

    @SerialName("sample_transpose_quantize")
    val sampleTransposeQuantize: Double,

    @SerialName("sample_tune")
    val sampleTune: Double,

    @SerialName("stereo_mode")
    val stereoMode: Double? = null,

    @SerialName("stereo_routing")
    val stereoRouting: Double,

    @SerialName("velocity_track")
    val velocityTrack: Double,

    @SerialName("view_spectrogram")
    val viewSpectrogram: Double? = null,

    @SerialName("voice_amplitude")
    val voiceAmplitude: Double,

    @SerialName("voice_override")
    val voiceOverride: Double? = null,

    @SerialName("voice_priority")
    val voicePriority: Double,

    @SerialName("voice_transpose")
    val voiceTranspose: Double? = null,

    @SerialName("voice_tune")
    val voiceTune: Double,

    val volume: Double,
    val wavetables: List<Wavetable>
)

@Serializable
data class Lfo (
    val name: String,

    @SerialName("num_points")
    val numPoints: Double,

    val points: List<Double>,
    val powers: List<Double>,
    val smooth: Boolean
)

@Serializable
data class Modulation (
    val destination: String,

    @SerialName("line_mapping")
    val lineMapping: Lfo? = null,

    val source: Source
)

@Serializable(with = Source.Companion::class)
enum class Source(val value: String) {
    Aftertouch("aftertouch"),
    Empty(""),
    Env1("env_1"),
    Env2("env_2"),
    Env3("env_3"),
    Env4("env_4"),
    Env5("env_5"),
    Env6("env_6"),
    Lfo1("lfo_1"),
    Lfo2("lfo_2"),
    Lfo3("lfo_3"),
    Lfo4("lfo_4"),
    Lfo5("lfo_5"),
    Lfo6("lfo_6"),
    Lfo7("lfo_7"),
    Lfo8("lfo_8"),
    Lift("lift"),
    MacroControl1("macro_control_1"),
    MacroControl2("macro_control_2"),
    MacroControl3("macro_control_3"),
    MacroControl4("macro_control_4"),
    ModWheel("mod_wheel"),
    Note("note"),
    NoteInOctave("note_in_octave"),
    PitchWheel("pitch_wheel"),
    Random("random"),
    Random1("random_1"),
    Random2("random_2"),
    Random3("random_3"),
    Random4("random_4"),
    Slide("slide"),
    Stereo("stereo"),
    Velocity("velocity");

    companion object : KSerializer<Source> {
        override val descriptor: SerialDescriptor get() {
            return PrimitiveDescriptor("org.vitalsdk.types.Source", PrimitiveKind.STRING)
        }
        override fun deserialize(decoder: Decoder): Source = when (val value = decoder.decodeString()) {
            "aftertouch"      -> Aftertouch
            ""                -> Empty
            "env_1"           -> Env1
            "env_2"           -> Env2
            "env_3"           -> Env3
            "env_4"           -> Env4
            "env_5"           -> Env5
            "env_6"           -> Env6
            "lfo_1"           -> Lfo1
            "lfo_2"           -> Lfo2
            "lfo_3"           -> Lfo3
            "lfo_4"           -> Lfo4
            "lfo_5"           -> Lfo5
            "lfo_6"           -> Lfo6
            "lfo_7"           -> Lfo7
            "lfo_8"           -> Lfo8
            "lift"            -> Lift
            "macro_control_1" -> MacroControl1
            "macro_control_2" -> MacroControl2
            "macro_control_3" -> MacroControl3
            "macro_control_4" -> MacroControl4
            "mod_wheel"       -> ModWheel
            "note"            -> Note
            "note_in_octave"  -> NoteInOctave
            "pitch_wheel"     -> PitchWheel
            "random"          -> Random
            "random_1"        -> Random1
            "random_2"        -> Random2
            "random_3"        -> Random3
            "random_4"        -> Random4
            "slide"           -> Slide
            "stereo"          -> Stereo
            "velocity"        -> Velocity
            else              -> throw IllegalArgumentException("Source could not parse: $value")
        }
        override fun serialize(encoder: Encoder, value: Source) {
            return encoder.encodeString(value.value)
        }
    }
}

@Serializable
data class Sample (
    val length: Double,
    val name: String,

    @SerialName("sample_rate")
    val sampleRate: Double,

    val samples: String,

    @SerialName("samples_stereo")
    val samplesStereo: String? = null
)

@Serializable
data class Wavetable (
    val author: String? = null,

    @SerialName("full_normalize")
    val fullNormalize: Boolean,

    val groups: List<Group>,
    val name: String,

    @SerialName("remove_all_dc")
    val removeAllDc: Boolean,

    val version: String
)

@Serializable
data class Group (
    val components: List<Component>
)

@Serializable
data class Component (
    @SerialName("audio_file")
    val audioFile: String? = null,

    @SerialName("audio_sample_rate")
    val audioSampleRate: Double? = null,

    @SerialName("fade_style")
    val fadeStyle: Double? = null,

    @SerialName("horizontal_asymmetric")
    val horizontalAsymmetric: Boolean? = null,

    val interpolation: Double? = null,

    @SerialName("interpolation_style")
    val interpolationStyle: Double,

    val keyframes: List<Keyframe>? = null,
    val normalize: Boolean? = null,

    @SerialName("normalize_gain")
    val normalizeGain: Boolean? = null,

    @SerialName("normalize_mult")
    val normalizeMult: Boolean? = null,

    @SerialName("num_points")
    val numPoints: Double? = null,

    @SerialName("phase_style")
    val phaseStyle: Double? = null,

    @SerialName("random_seed")
    val randomSeed: Double? = null,

    val style: Double? = null,
    val type: Type,

    @SerialName("vertical_asymmetric")
    val verticalAsymmetric: Boolean? = null,

    @SerialName("window_shape")
    val windowShape: Double? = null,

    @SerialName("window_size")
    val windowSize: Double? = null
)

@Serializable
data class Keyframe (
    val cutoff: Double? = null,

    @SerialName("down_run_rise")
    val downRunRise: Double? = null,

    @SerialName("fold_boost")
    val foldBoost: Double? = null,

    @SerialName("horizontal_power")
    val horizontalPower: Double? = null,

    @SerialName("left_position")
    val leftPosition: Double? = null,

    val line: Lfo? = null,
    val mix: Double? = null,
    val phase: Double? = null,
    val position: Double,

    @SerialName("pull_power")
    val pullPower: Double? = null,

    @SerialName("right_position")
    val rightPosition: Double? = null,

    val shape: Double? = null,

    @SerialName("start_position")
    val startPosition: Double? = null,

    @SerialName("up_run_rise")
    val upRunRise: Double? = null,

    @SerialName("vertical_power")
    val verticalPower: Double? = null,

    @SerialName("wave_data")
    val waveData: String? = null,

    @SerialName("window_fade")
    val windowFade: Double? = null,

    @SerialName("window_size")
    val windowSize: Double? = null
)

@Serializable(with = Type.Companion::class)
enum class Type(val value: String) {
    AudioFileSource("Audio File Source"),
    FrequencyFilter("Frequency Filter"),
    LineSource("Line Source"),
    PhaseShift("Phase Shift"),
    ShepardToneSource("Shepard Tone Source"),
    SlewLimiter("Slew Limiter"),
    WaveFolder("Wave Folder"),
    WaveSource("Wave Source"),
    WaveWarp("Wave Warp"),
    WaveWindow("Wave Window");

    companion object : KSerializer<Type> {
        override val descriptor: SerialDescriptor get() {
            return PrimitiveDescriptor("org.vitalsdk.types.Type", PrimitiveKind.STRING)
        }
        override fun deserialize(decoder: Decoder): Type = when (val value = decoder.decodeString()) {
            "Audio File Source"   -> AudioFileSource
            "Frequency Filter"    -> FrequencyFilter
            "Line Source"         -> LineSource
            "Phase Shift"         -> PhaseShift
            "Shepard Tone Source" -> ShepardToneSource
            "Slew Limiter"        -> SlewLimiter
            "Wave Folder"         -> WaveFolder
            "Wave Source"         -> WaveSource
            "Wave Warp"           -> WaveWarp
            "Wave Window"         -> WaveWindow
            else                  -> throw IllegalArgumentException("Type could not parse: $value")
        }
        override fun serialize(encoder: Encoder, value: Type) {
            return encoder.encodeString(value.value)
        }
    }
}
