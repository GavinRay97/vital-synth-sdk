// Converter.java

// To use this code, add the following Maven dependency to your project:
//
//
//     com.fasterxml.jackson.core     : jackson-databind          : 2.9.0
//     com.fasterxml.jackson.datatype : jackson-datatype-jsr310   : 2.9.0
//
// Import this package:
//
//     import org.vitalsdk.types.Converter;
//
// Then you can deserialize a JSON string with
//
//     VitalPreset data = Converter.VitalPresetFromJsonString(jsonString);
//     PresetStyle data = Converter.PresetStyleFromJsonString(jsonString);
//     PresetSettings data = Converter.PresetSettingsFromJsonString(jsonString);
//     Lfo data = Converter.LfoFromJsonString(jsonString);
//     Modulation data = Converter.ModulationFromJsonString(jsonString);
//     Source data = Converter.SourceFromJsonString(jsonString);
//     Sample data = Converter.SampleFromJsonString(jsonString);
//     Wavetable data = Converter.WavetableFromJsonString(jsonString);
//     Group data = Converter.GroupFromJsonString(jsonString);
//     Component data = Converter.ComponentFromJsonString(jsonString);
//     Keyframe data = Converter.KeyframeFromJsonString(jsonString);
//     Type data = Converter.TypeFromJsonString(jsonString);

package org.vitalsdk.types;

import java.io.IOException;
import com.fasterxml.jackson.databind.*;
import com.fasterxml.jackson.databind.module.SimpleModule;
import com.fasterxml.jackson.core.JsonParser;
import com.fasterxml.jackson.core.JsonProcessingException;
import java.util.*;
import java.time.LocalDate;
import java.time.OffsetDateTime;
import java.time.OffsetTime;
import java.time.ZoneOffset;
import java.time.ZonedDateTime;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeFormatterBuilder;
import java.time.temporal.ChronoField;

public class Converter {
    // Date-time helpers

    private static final DateTimeFormatter DATE_TIME_FORMATTER = new DateTimeFormatterBuilder()
            .appendOptional(DateTimeFormatter.ISO_DATE_TIME)
            .appendOptional(DateTimeFormatter.ISO_OFFSET_DATE_TIME)
            .appendOptional(DateTimeFormatter.ISO_INSTANT)
            .appendOptional(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss.SX"))
            .appendOptional(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ssX"))
            .appendOptional(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"))
            .toFormatter()
            .withZone(ZoneOffset.UTC);

    public static OffsetDateTime parseDateTimeString(String str) {
        return ZonedDateTime.from(Converter.DATE_TIME_FORMATTER.parse(str)).toOffsetDateTime();
    }

    private static final DateTimeFormatter TIME_FORMATTER = new DateTimeFormatterBuilder()
            .appendOptional(DateTimeFormatter.ISO_TIME)
            .appendOptional(DateTimeFormatter.ISO_OFFSET_TIME)
            .parseDefaulting(ChronoField.YEAR, 2020)
            .parseDefaulting(ChronoField.MONTH_OF_YEAR, 1)
            .parseDefaulting(ChronoField.DAY_OF_MONTH, 1)
            .toFormatter()
            .withZone(ZoneOffset.UTC);

    public static OffsetTime parseTimeString(String str) {
        return ZonedDateTime.from(Converter.TIME_FORMATTER.parse(str)).toOffsetDateTime().toOffsetTime();
    }
    // Serialize/deserialize helpers

    public static VitalPreset VitalPresetFromJsonString(String json) throws IOException {
        return getVitalPresetObjectReader().readValue(json);
    }

    public static String VitalPresetToJsonString(VitalPreset obj) throws JsonProcessingException {
        return getVitalPresetObjectWriter().writeValueAsString(obj);
    }

    public static PresetStyle PresetStyleFromJsonString(String json) throws IOException {
        return getPresetStyleObjectReader().readValue(json);
    }

    public static String PresetStyleToJsonString(PresetStyle obj) throws JsonProcessingException {
        return getPresetStyleObjectWriter().writeValueAsString(obj);
    }

    public static PresetSettings PresetSettingsFromJsonString(String json) throws IOException {
        return getPresetSettingsObjectReader().readValue(json);
    }

    public static String PresetSettingsToJsonString(PresetSettings obj) throws JsonProcessingException {
        return getPresetSettingsObjectWriter().writeValueAsString(obj);
    }

    public static Lfo LfoFromJsonString(String json) throws IOException {
        return getLfoObjectReader().readValue(json);
    }

    public static String LfoToJsonString(Lfo obj) throws JsonProcessingException {
        return getLfoObjectWriter().writeValueAsString(obj);
    }

    public static Modulation ModulationFromJsonString(String json) throws IOException {
        return getModulationObjectReader().readValue(json);
    }

    public static String ModulationToJsonString(Modulation obj) throws JsonProcessingException {
        return getModulationObjectWriter().writeValueAsString(obj);
    }

    public static Source SourceFromJsonString(String json) throws IOException {
        return getSourceObjectReader().readValue(json);
    }

    public static String SourceToJsonString(Source obj) throws JsonProcessingException {
        return getSourceObjectWriter().writeValueAsString(obj);
    }

    public static Sample SampleFromJsonString(String json) throws IOException {
        return getSampleObjectReader().readValue(json);
    }

    public static String SampleToJsonString(Sample obj) throws JsonProcessingException {
        return getSampleObjectWriter().writeValueAsString(obj);
    }

    public static Wavetable WavetableFromJsonString(String json) throws IOException {
        return getWavetableObjectReader().readValue(json);
    }

    public static String WavetableToJsonString(Wavetable obj) throws JsonProcessingException {
        return getWavetableObjectWriter().writeValueAsString(obj);
    }

    public static Group GroupFromJsonString(String json) throws IOException {
        return getGroupObjectReader().readValue(json);
    }

    public static String GroupToJsonString(Group obj) throws JsonProcessingException {
        return getGroupObjectWriter().writeValueAsString(obj);
    }

    public static Component ComponentFromJsonString(String json) throws IOException {
        return getComponentObjectReader().readValue(json);
    }

    public static String ComponentToJsonString(Component obj) throws JsonProcessingException {
        return getComponentObjectWriter().writeValueAsString(obj);
    }

    public static Keyframe KeyframeFromJsonString(String json) throws IOException {
        return getKeyframeObjectReader().readValue(json);
    }

    public static String KeyframeToJsonString(Keyframe obj) throws JsonProcessingException {
        return getKeyframeObjectWriter().writeValueAsString(obj);
    }

    public static Type TypeFromJsonString(String json) throws IOException {
        return getTypeObjectReader().readValue(json);
    }

    public static String TypeToJsonString(Type obj) throws JsonProcessingException {
        return getTypeObjectWriter().writeValueAsString(obj);
    }

    private static ObjectReader VitalPresetReader;
    private static ObjectWriter VitalPresetWriter;

    private static void instantiateVitalPresetMapper() {
        ObjectMapper mapper = new ObjectMapper();
        mapper.findAndRegisterModules();
        mapper.configure(SerializationFeature.WRITE_DATES_AS_TIMESTAMPS, false);
        SimpleModule module = new SimpleModule();
        module.addDeserializer(OffsetDateTime.class, new JsonDeserializer<OffsetDateTime>() {
            @Override
            public OffsetDateTime deserialize(JsonParser jsonParser, DeserializationContext deserializationContext) throws IOException, JsonProcessingException {
                String value = jsonParser.getText();
                return Converter.parseDateTimeString(value);
            }
        });
        mapper.registerModule(module);
        VitalPresetReader = mapper.readerFor(VitalPreset.class);
        VitalPresetWriter = mapper.writerFor(VitalPreset.class);
    }

    private static ObjectReader getVitalPresetObjectReader() {
        if (VitalPresetReader == null) instantiateVitalPresetMapper();
        return VitalPresetReader;
    }

    private static ObjectWriter getVitalPresetObjectWriter() {
        if (VitalPresetWriter == null) instantiateVitalPresetMapper();
        return VitalPresetWriter;
    }

    private static ObjectReader PresetStyleReader;
    private static ObjectWriter PresetStyleWriter;

    private static void instantiatePresetStyleMapper() {
        ObjectMapper mapper = new ObjectMapper();
        mapper.findAndRegisterModules();
        mapper.configure(SerializationFeature.WRITE_DATES_AS_TIMESTAMPS, false);
        SimpleModule module = new SimpleModule();
        module.addDeserializer(OffsetDateTime.class, new JsonDeserializer<OffsetDateTime>() {
            @Override
            public OffsetDateTime deserialize(JsonParser jsonParser, DeserializationContext deserializationContext) throws IOException, JsonProcessingException {
                String value = jsonParser.getText();
                return Converter.parseDateTimeString(value);
            }
        });
        mapper.registerModule(module);
        PresetStyleReader = mapper.readerFor(PresetStyle.class);
        PresetStyleWriter = mapper.writerFor(PresetStyle.class);
    }

    private static ObjectReader getPresetStyleObjectReader() {
        if (PresetStyleReader == null) instantiatePresetStyleMapper();
        return PresetStyleReader;
    }

    private static ObjectWriter getPresetStyleObjectWriter() {
        if (PresetStyleWriter == null) instantiatePresetStyleMapper();
        return PresetStyleWriter;
    }

    private static ObjectReader PresetSettingsReader;
    private static ObjectWriter PresetSettingsWriter;

    private static void instantiatePresetSettingsMapper() {
        ObjectMapper mapper = new ObjectMapper();
        mapper.findAndRegisterModules();
        mapper.configure(SerializationFeature.WRITE_DATES_AS_TIMESTAMPS, false);
        SimpleModule module = new SimpleModule();
        module.addDeserializer(OffsetDateTime.class, new JsonDeserializer<OffsetDateTime>() {
            @Override
            public OffsetDateTime deserialize(JsonParser jsonParser, DeserializationContext deserializationContext) throws IOException, JsonProcessingException {
                String value = jsonParser.getText();
                return Converter.parseDateTimeString(value);
            }
        });
        mapper.registerModule(module);
        PresetSettingsReader = mapper.readerFor(PresetSettings.class);
        PresetSettingsWriter = mapper.writerFor(PresetSettings.class);
    }

    private static ObjectReader getPresetSettingsObjectReader() {
        if (PresetSettingsReader == null) instantiatePresetSettingsMapper();
        return PresetSettingsReader;
    }

    private static ObjectWriter getPresetSettingsObjectWriter() {
        if (PresetSettingsWriter == null) instantiatePresetSettingsMapper();
        return PresetSettingsWriter;
    }

    private static ObjectReader LfoReader;
    private static ObjectWriter LfoWriter;

    private static void instantiateLfoMapper() {
        ObjectMapper mapper = new ObjectMapper();
        mapper.findAndRegisterModules();
        mapper.configure(SerializationFeature.WRITE_DATES_AS_TIMESTAMPS, false);
        SimpleModule module = new SimpleModule();
        module.addDeserializer(OffsetDateTime.class, new JsonDeserializer<OffsetDateTime>() {
            @Override
            public OffsetDateTime deserialize(JsonParser jsonParser, DeserializationContext deserializationContext) throws IOException, JsonProcessingException {
                String value = jsonParser.getText();
                return Converter.parseDateTimeString(value);
            }
        });
        mapper.registerModule(module);
        LfoReader = mapper.readerFor(Lfo.class);
        LfoWriter = mapper.writerFor(Lfo.class);
    }

    private static ObjectReader getLfoObjectReader() {
        if (LfoReader == null) instantiateLfoMapper();
        return LfoReader;
    }

    private static ObjectWriter getLfoObjectWriter() {
        if (LfoWriter == null) instantiateLfoMapper();
        return LfoWriter;
    }

    private static ObjectReader ModulationReader;
    private static ObjectWriter ModulationWriter;

    private static void instantiateModulationMapper() {
        ObjectMapper mapper = new ObjectMapper();
        mapper.findAndRegisterModules();
        mapper.configure(SerializationFeature.WRITE_DATES_AS_TIMESTAMPS, false);
        SimpleModule module = new SimpleModule();
        module.addDeserializer(OffsetDateTime.class, new JsonDeserializer<OffsetDateTime>() {
            @Override
            public OffsetDateTime deserialize(JsonParser jsonParser, DeserializationContext deserializationContext) throws IOException, JsonProcessingException {
                String value = jsonParser.getText();
                return Converter.parseDateTimeString(value);
            }
        });
        mapper.registerModule(module);
        ModulationReader = mapper.readerFor(Modulation.class);
        ModulationWriter = mapper.writerFor(Modulation.class);
    }

    private static ObjectReader getModulationObjectReader() {
        if (ModulationReader == null) instantiateModulationMapper();
        return ModulationReader;
    }

    private static ObjectWriter getModulationObjectWriter() {
        if (ModulationWriter == null) instantiateModulationMapper();
        return ModulationWriter;
    }

    private static ObjectReader SourceReader;
    private static ObjectWriter SourceWriter;

    private static void instantiateSourceMapper() {
        ObjectMapper mapper = new ObjectMapper();
        mapper.findAndRegisterModules();
        mapper.configure(SerializationFeature.WRITE_DATES_AS_TIMESTAMPS, false);
        SimpleModule module = new SimpleModule();
        module.addDeserializer(OffsetDateTime.class, new JsonDeserializer<OffsetDateTime>() {
            @Override
            public OffsetDateTime deserialize(JsonParser jsonParser, DeserializationContext deserializationContext) throws IOException, JsonProcessingException {
                String value = jsonParser.getText();
                return Converter.parseDateTimeString(value);
            }
        });
        mapper.registerModule(module);
        SourceReader = mapper.readerFor(Source.class);
        SourceWriter = mapper.writerFor(Source.class);
    }

    private static ObjectReader getSourceObjectReader() {
        if (SourceReader == null) instantiateSourceMapper();
        return SourceReader;
    }

    private static ObjectWriter getSourceObjectWriter() {
        if (SourceWriter == null) instantiateSourceMapper();
        return SourceWriter;
    }

    private static ObjectReader SampleReader;
    private static ObjectWriter SampleWriter;

    private static void instantiateSampleMapper() {
        ObjectMapper mapper = new ObjectMapper();
        mapper.findAndRegisterModules();
        mapper.configure(SerializationFeature.WRITE_DATES_AS_TIMESTAMPS, false);
        SimpleModule module = new SimpleModule();
        module.addDeserializer(OffsetDateTime.class, new JsonDeserializer<OffsetDateTime>() {
            @Override
            public OffsetDateTime deserialize(JsonParser jsonParser, DeserializationContext deserializationContext) throws IOException, JsonProcessingException {
                String value = jsonParser.getText();
                return Converter.parseDateTimeString(value);
            }
        });
        mapper.registerModule(module);
        SampleReader = mapper.readerFor(Sample.class);
        SampleWriter = mapper.writerFor(Sample.class);
    }

    private static ObjectReader getSampleObjectReader() {
        if (SampleReader == null) instantiateSampleMapper();
        return SampleReader;
    }

    private static ObjectWriter getSampleObjectWriter() {
        if (SampleWriter == null) instantiateSampleMapper();
        return SampleWriter;
    }

    private static ObjectReader WavetableReader;
    private static ObjectWriter WavetableWriter;

    private static void instantiateWavetableMapper() {
        ObjectMapper mapper = new ObjectMapper();
        mapper.findAndRegisterModules();
        mapper.configure(SerializationFeature.WRITE_DATES_AS_TIMESTAMPS, false);
        SimpleModule module = new SimpleModule();
        module.addDeserializer(OffsetDateTime.class, new JsonDeserializer<OffsetDateTime>() {
            @Override
            public OffsetDateTime deserialize(JsonParser jsonParser, DeserializationContext deserializationContext) throws IOException, JsonProcessingException {
                String value = jsonParser.getText();
                return Converter.parseDateTimeString(value);
            }
        });
        mapper.registerModule(module);
        WavetableReader = mapper.readerFor(Wavetable.class);
        WavetableWriter = mapper.writerFor(Wavetable.class);
    }

    private static ObjectReader getWavetableObjectReader() {
        if (WavetableReader == null) instantiateWavetableMapper();
        return WavetableReader;
    }

    private static ObjectWriter getWavetableObjectWriter() {
        if (WavetableWriter == null) instantiateWavetableMapper();
        return WavetableWriter;
    }

    private static ObjectReader GroupReader;
    private static ObjectWriter GroupWriter;

    private static void instantiateGroupMapper() {
        ObjectMapper mapper = new ObjectMapper();
        mapper.findAndRegisterModules();
        mapper.configure(SerializationFeature.WRITE_DATES_AS_TIMESTAMPS, false);
        SimpleModule module = new SimpleModule();
        module.addDeserializer(OffsetDateTime.class, new JsonDeserializer<OffsetDateTime>() {
            @Override
            public OffsetDateTime deserialize(JsonParser jsonParser, DeserializationContext deserializationContext) throws IOException, JsonProcessingException {
                String value = jsonParser.getText();
                return Converter.parseDateTimeString(value);
            }
        });
        mapper.registerModule(module);
        GroupReader = mapper.readerFor(Group.class);
        GroupWriter = mapper.writerFor(Group.class);
    }

    private static ObjectReader getGroupObjectReader() {
        if (GroupReader == null) instantiateGroupMapper();
        return GroupReader;
    }

    private static ObjectWriter getGroupObjectWriter() {
        if (GroupWriter == null) instantiateGroupMapper();
        return GroupWriter;
    }

    private static ObjectReader ComponentReader;
    private static ObjectWriter ComponentWriter;

    private static void instantiateComponentMapper() {
        ObjectMapper mapper = new ObjectMapper();
        mapper.findAndRegisterModules();
        mapper.configure(SerializationFeature.WRITE_DATES_AS_TIMESTAMPS, false);
        SimpleModule module = new SimpleModule();
        module.addDeserializer(OffsetDateTime.class, new JsonDeserializer<OffsetDateTime>() {
            @Override
            public OffsetDateTime deserialize(JsonParser jsonParser, DeserializationContext deserializationContext) throws IOException, JsonProcessingException {
                String value = jsonParser.getText();
                return Converter.parseDateTimeString(value);
            }
        });
        mapper.registerModule(module);
        ComponentReader = mapper.readerFor(Component.class);
        ComponentWriter = mapper.writerFor(Component.class);
    }

    private static ObjectReader getComponentObjectReader() {
        if (ComponentReader == null) instantiateComponentMapper();
        return ComponentReader;
    }

    private static ObjectWriter getComponentObjectWriter() {
        if (ComponentWriter == null) instantiateComponentMapper();
        return ComponentWriter;
    }

    private static ObjectReader KeyframeReader;
    private static ObjectWriter KeyframeWriter;

    private static void instantiateKeyframeMapper() {
        ObjectMapper mapper = new ObjectMapper();
        mapper.findAndRegisterModules();
        mapper.configure(SerializationFeature.WRITE_DATES_AS_TIMESTAMPS, false);
        SimpleModule module = new SimpleModule();
        module.addDeserializer(OffsetDateTime.class, new JsonDeserializer<OffsetDateTime>() {
            @Override
            public OffsetDateTime deserialize(JsonParser jsonParser, DeserializationContext deserializationContext) throws IOException, JsonProcessingException {
                String value = jsonParser.getText();
                return Converter.parseDateTimeString(value);
            }
        });
        mapper.registerModule(module);
        KeyframeReader = mapper.readerFor(Keyframe.class);
        KeyframeWriter = mapper.writerFor(Keyframe.class);
    }

    private static ObjectReader getKeyframeObjectReader() {
        if (KeyframeReader == null) instantiateKeyframeMapper();
        return KeyframeReader;
    }

    private static ObjectWriter getKeyframeObjectWriter() {
        if (KeyframeWriter == null) instantiateKeyframeMapper();
        return KeyframeWriter;
    }

    private static ObjectReader TypeReader;
    private static ObjectWriter TypeWriter;

    private static void instantiateTypeMapper() {
        ObjectMapper mapper = new ObjectMapper();
        mapper.findAndRegisterModules();
        mapper.configure(SerializationFeature.WRITE_DATES_AS_TIMESTAMPS, false);
        SimpleModule module = new SimpleModule();
        module.addDeserializer(OffsetDateTime.class, new JsonDeserializer<OffsetDateTime>() {
            @Override
            public OffsetDateTime deserialize(JsonParser jsonParser, DeserializationContext deserializationContext) throws IOException, JsonProcessingException {
                String value = jsonParser.getText();
                return Converter.parseDateTimeString(value);
            }
        });
        mapper.registerModule(module);
        TypeReader = mapper.readerFor(Type.class);
        TypeWriter = mapper.writerFor(Type.class);
    }

    private static ObjectReader getTypeObjectReader() {
        if (TypeReader == null) instantiateTypeMapper();
        return TypeReader;
    }

    private static ObjectWriter getTypeObjectWriter() {
        if (TypeWriter == null) instantiateTypeMapper();
        return TypeWriter;
    }
}

// VitalPreset.java

package org.vitalsdk.types;

import com.fasterxml.jackson.annotation.*;

public class VitalPreset {
    private String author;
    private String comments;
    private String macro1;
    private String macro2;
    private String macro3;
    private String macro4;
    private String presetName;
    private PresetStyle presetStyle;
    private PresetSettings settings;
    private String synthVersion;

    @JsonProperty("author")
    public String getAuthor() { return author; }
    @JsonProperty("author")
    public void setAuthor(String value) { this.author = value; }

    @JsonProperty("comments")
    public String getComments() { return comments; }
    @JsonProperty("comments")
    public void setComments(String value) { this.comments = value; }

    @JsonProperty("macro1")
    public String getMacro1() { return macro1; }
    @JsonProperty("macro1")
    public void setMacro1(String value) { this.macro1 = value; }

    @JsonProperty("macro2")
    public String getMacro2() { return macro2; }
    @JsonProperty("macro2")
    public void setMacro2(String value) { this.macro2 = value; }

    @JsonProperty("macro3")
    public String getMacro3() { return macro3; }
    @JsonProperty("macro3")
    public void setMacro3(String value) { this.macro3 = value; }

    @JsonProperty("macro4")
    public String getMacro4() { return macro4; }
    @JsonProperty("macro4")
    public void setMacro4(String value) { this.macro4 = value; }

    @JsonProperty("preset_name")
    public String getPresetName() { return presetName; }
    @JsonProperty("preset_name")
    public void setPresetName(String value) { this.presetName = value; }

    @JsonProperty("preset_style")
    public PresetStyle getPresetStyle() { return presetStyle; }
    @JsonProperty("preset_style")
    public void setPresetStyle(PresetStyle value) { this.presetStyle = value; }

    @JsonProperty("settings")
    public PresetSettings getSettings() { return settings; }
    @JsonProperty("settings")
    public void setSettings(PresetSettings value) { this.settings = value; }

    @JsonProperty("synth_version")
    public String getSynthVersion() { return synthVersion; }
    @JsonProperty("synth_version")
    public void setSynthVersion(String value) { this.synthVersion = value; }
}

// PresetStyle.java

package org.vitalsdk.types;

import java.io.IOException;
import com.fasterxml.jackson.annotation.*;

public enum PresetStyle {
    BASS, EMPTY, EXPERIMENT, KEYS, LEAD, PAD, PERCUSSION, SEQUENCE, SFX, TEMPLATE;

    @JsonValue
    public String toValue() {
        switch (this) {
            case BASS: return "Bass";
            case EMPTY: return "";
            case EXPERIMENT: return "Experiment";
            case KEYS: return "Keys";
            case LEAD: return "Lead";
            case PAD: return "Pad";
            case PERCUSSION: return "Percussion";
            case SEQUENCE: return "Sequence";
            case SFX: return "SFX";
            case TEMPLATE: return "Template";
        }
        return null;
    }

    @JsonCreator
    public static PresetStyle forValue(String value) throws IOException {
        if (value.equals("Bass")) return BASS;
        if (value.equals("")) return EMPTY;
        if (value.equals("Experiment")) return EXPERIMENT;
        if (value.equals("Keys")) return KEYS;
        if (value.equals("Lead")) return LEAD;
        if (value.equals("Pad")) return PAD;
        if (value.equals("Percussion")) return PERCUSSION;
        if (value.equals("Sequence")) return SEQUENCE;
        if (value.equals("SFX")) return SFX;
        if (value.equals("Template")) return TEMPLATE;
        throw new IOException("Cannot deserialize PresetStyle");
    }
}

// PresetSettings.java

package org.vitalsdk.types;

import com.fasterxml.jackson.annotation.*;

public class PresetSettings {
    private double beatsPerMinute;
    private Double bypass;
    private Double chorusCutoff;
    private Double chorusDamping;
    private double chorusDelay1;
    private double chorusDelay2;
    private double chorusDryWet;
    private double chorusFeedback;
    private double chorusFrequency;
    private double chorusModDepth;
    private double chorusOn;
    private Double chorusSpread;
    private double chorusSync;
    private double chorusTempo;
    private double chorusVoices;
    private double compressorAttack;
    private double compressorBandGain;
    private double compressorBandLowerRatio;
    private double compressorBandLowerThreshold;
    private double compressorBandUpperRatio;
    private double compressorBandUpperThreshold;
    private double compressorEnabledBands;
    private double compressorHighGain;
    private double compressorHighLowerRatio;
    private double compressorHighLowerThreshold;
    private double compressorHighUpperRatio;
    private double compressorHighUpperThreshold;
    private double compressorLowGain;
    private double compressorLowLowerRatio;
    private double compressorLowLowerThreshold;
    private double compressorLowUpperRatio;
    private double compressorLowUpperThreshold;
    private Double compressorMix;
    private double compressorOn;
    private double compressorRelease;
    private double delayAuxFrequency;
    private double delayAuxSync;
    private double delayAuxTempo;
    private double delayDryWet;
    private double delayFeedback;
    private double delayFilterCutoff;
    private double delayFilterSpread;
    private double delayFrequency;
    private double delayOn;
    private double delayStyle;
    private double delaySync;
    private double delayTempo;
    private double distortionDrive;
    private double distortionFilterBlend;
    private double distortionFilterCutoff;
    private double distortionFilterOrder;
    private double distortionFilterResonance;
    private double distortionMix;
    private double distortionOn;
    private double distortionType;
    private double effectChainOrder;
    private double env1_Attack;
    private double env1_AttackPower;
    private double env1_Decay;
    private double env1_DecayPower;
    private double env1_Delay;
    private double env1_Hold;
    private double env1_Release;
    private double env1_ReleasePower;
    private double env1_Sustain;
    private double env2_Attack;
    private double env2_AttackPower;
    private double env2_Decay;
    private double env2_DecayPower;
    private double env2_Delay;
    private double env2_Hold;
    private double env2_Release;
    private double env2_ReleasePower;
    private double env2_Sustain;
    private double env3_Attack;
    private double env3_AttackPower;
    private double env3_Decay;
    private double env3_DecayPower;
    private double env3_Delay;
    private double env3_Hold;
    private double env3_Release;
    private double env3_ReleasePower;
    private double env3_Sustain;
    private double env4_Attack;
    private double env4_AttackPower;
    private double env4_Decay;
    private double env4_DecayPower;
    private double env4_Delay;
    private double env4_Hold;
    private double env4_Release;
    private double env4_ReleasePower;
    private double env4_Sustain;
    private double env5_Attack;
    private double env5_AttackPower;
    private double env5_Decay;
    private double env5_DecayPower;
    private double env5_Delay;
    private double env5_Hold;
    private double env5_Release;
    private double env5_ReleasePower;
    private double env5_Sustain;
    private double env6_Attack;
    private double env6_AttackPower;
    private double env6_Decay;
    private double env6_DecayPower;
    private double env6_Delay;
    private double env6_Hold;
    private double env6_Release;
    private double env6_ReleasePower;
    private double env6_Sustain;
    private double eqBandCutoff;
    private double eqBandGain;
    private double eqBandMode;
    private double eqBandResonance;
    private double eqHighCutoff;
    private double eqHighGain;
    private double eqHighMode;
    private double eqHighResonance;
    private double eqLowCutoff;
    private double eqLowGain;
    private double eqLowMode;
    private double eqLowResonance;
    private double eqOn;
    private double filter1_Blend;
    private double filter1_BlendTranspose;
    private double filter1_Cutoff;
    private double filter1_Drive;
    private double filter1_FilterInput;
    private double filter1_FormantResonance;
    private Double filter1_FormantSpread;
    private double filter1_FormantTranspose;
    private double filter1_FormantX;
    private double filter1_FormantY;
    private double filter1_Keytrack;
    private double filter1_Mix;
    private double filter1_Model;
    private double filter1_On;
    private double filter1_Resonance;
    private double filter1_Style;
    private double filter2_Blend;
    private double filter2_BlendTranspose;
    private double filter2_Cutoff;
    private double filter2_Drive;
    private double filter2_FilterInput;
    private double filter2_FormantResonance;
    private Double filter2_FormantSpread;
    private double filter2_FormantTranspose;
    private double filter2_FormantX;
    private double filter2_FormantY;
    private double filter2_Keytrack;
    private double filter2_Mix;
    private double filter2_Model;
    private double filter2_On;
    private double filter2_Resonance;
    private double filter2_Style;
    private double filterFxBlend;
    private double filterFxBlendTranspose;
    private double filterFxCutoff;
    private double filterFxDrive;
    private double filterFxFormantResonance;
    private Double filterFxFormantSpread;
    private double filterFxFormantTranspose;
    private double filterFxFormantX;
    private double filterFxFormantY;
    private double filterFxKeytrack;
    private double filterFxMix;
    private double filterFxModel;
    private double filterFxOn;
    private double filterFxResonance;
    private double filterFxStyle;
    private double flangerCenter;
    private double flangerDryWet;
    private double flangerFeedback;
    private double flangerFrequency;
    private double flangerModDepth;
    private double flangerOn;
    private double flangerPhaseOffset;
    private double flangerSync;
    private double flangerTempo;
    private double legato;
    private double lfo1_DelayTime;
    private double lfo1_FadeTime;
    private double lfo1_Frequency;
    private Double lfo1_KeytrackTranspose;
    private Double lfo1_KeytrackTune;
    private double lfo1_Phase;
    private Double lfo1_SmoothMode;
    private Double lfo1_SmoothTime;
    private double lfo1_Stereo;
    private double lfo1_Sync;
    private double lfo1_SyncType;
    private double lfo1_Tempo;
    private double lfo2_DelayTime;
    private double lfo2_FadeTime;
    private double lfo2_Frequency;
    private Double lfo2_KeytrackTranspose;
    private Double lfo2_KeytrackTune;
    private double lfo2_Phase;
    private Double lfo2_SmoothMode;
    private Double lfo2_SmoothTime;
    private double lfo2_Stereo;
    private double lfo2_Sync;
    private double lfo2_SyncType;
    private double lfo2_Tempo;
    private double lfo3_DelayTime;
    private double lfo3_FadeTime;
    private double lfo3_Frequency;
    private Double lfo3_KeytrackTranspose;
    private Double lfo3_KeytrackTune;
    private double lfo3_Phase;
    private Double lfo3_SmoothMode;
    private Double lfo3_SmoothTime;
    private double lfo3_Stereo;
    private double lfo3_Sync;
    private double lfo3_SyncType;
    private double lfo3_Tempo;
    private double lfo4_DelayTime;
    private double lfo4_FadeTime;
    private double lfo4_Frequency;
    private Double lfo4_KeytrackTranspose;
    private Double lfo4_KeytrackTune;
    private double lfo4_Phase;
    private Double lfo4_SmoothMode;
    private Double lfo4_SmoothTime;
    private double lfo4_Stereo;
    private double lfo4_Sync;
    private double lfo4_SyncType;
    private double lfo4_Tempo;
    private double lfo5_DelayTime;
    private double lfo5_FadeTime;
    private double lfo5_Frequency;
    private Double lfo5_KeytrackTranspose;
    private Double lfo5_KeytrackTune;
    private double lfo5_Phase;
    private Double lfo5_SmoothMode;
    private Double lfo5_SmoothTime;
    private double lfo5_Stereo;
    private double lfo5_Sync;
    private double lfo5_SyncType;
    private double lfo5_Tempo;
    private double lfo6_DelayTime;
    private double lfo6_FadeTime;
    private double lfo6_Frequency;
    private Double lfo6_KeytrackTranspose;
    private Double lfo6_KeytrackTune;
    private double lfo6_Phase;
    private Double lfo6_SmoothMode;
    private Double lfo6_SmoothTime;
    private double lfo6_Stereo;
    private double lfo6_Sync;
    private double lfo6_SyncType;
    private double lfo6_Tempo;
    private double lfo7_DelayTime;
    private double lfo7_FadeTime;
    private double lfo7_Frequency;
    private Double lfo7_KeytrackTranspose;
    private Double lfo7_KeytrackTune;
    private double lfo7_Phase;
    private Double lfo7_SmoothMode;
    private Double lfo7_SmoothTime;
    private double lfo7_Stereo;
    private double lfo7_Sync;
    private double lfo7_SyncType;
    private double lfo7_Tempo;
    private double lfo8_DelayTime;
    private double lfo8_FadeTime;
    private double lfo8_Frequency;
    private Double lfo8_KeytrackTranspose;
    private Double lfo8_KeytrackTune;
    private double lfo8_Phase;
    private Double lfo8_SmoothMode;
    private Double lfo8_SmoothTime;
    private double lfo8_Stereo;
    private double lfo8_Sync;
    private double lfo8_SyncType;
    private double lfo8_Tempo;
    private Lfo[] lfos;
    private double macroControl1;
    private double macroControl2;
    private double macroControl3;
    private double macroControl4;
    private double modWheel;
    private double modulation10_Amount;
    private double modulation10_Bipolar;
    private double modulation10_Bypass;
    private double modulation10_Power;
    private double modulation10_Stereo;
    private double modulation11_Amount;
    private double modulation11_Bipolar;
    private double modulation11_Bypass;
    private double modulation11_Power;
    private double modulation11_Stereo;
    private double modulation12_Amount;
    private double modulation12_Bipolar;
    private double modulation12_Bypass;
    private double modulation12_Power;
    private double modulation12_Stereo;
    private double modulation13_Amount;
    private double modulation13_Bipolar;
    private double modulation13_Bypass;
    private double modulation13_Power;
    private double modulation13_Stereo;
    private double modulation14_Amount;
    private double modulation14_Bipolar;
    private double modulation14_Bypass;
    private double modulation14_Power;
    private double modulation14_Stereo;
    private double modulation15_Amount;
    private double modulation15_Bipolar;
    private double modulation15_Bypass;
    private double modulation15_Power;
    private double modulation15_Stereo;
    private double modulation16_Amount;
    private double modulation16_Bipolar;
    private double modulation16_Bypass;
    private double modulation16_Power;
    private double modulation16_Stereo;
    private double modulation17_Amount;
    private double modulation17_Bipolar;
    private double modulation17_Bypass;
    private double modulation17_Power;
    private double modulation17_Stereo;
    private double modulation18_Amount;
    private double modulation18_Bipolar;
    private double modulation18_Bypass;
    private double modulation18_Power;
    private double modulation18_Stereo;
    private double modulation19_Amount;
    private double modulation19_Bipolar;
    private double modulation19_Bypass;
    private double modulation19_Power;
    private double modulation19_Stereo;
    private double modulation1_Amount;
    private double modulation1_Bipolar;
    private double modulation1_Bypass;
    private double modulation1_Power;
    private double modulation1_Stereo;
    private double modulation20_Amount;
    private double modulation20_Bipolar;
    private double modulation20_Bypass;
    private double modulation20_Power;
    private double modulation20_Stereo;
    private double modulation21_Amount;
    private double modulation21_Bipolar;
    private double modulation21_Bypass;
    private double modulation21_Power;
    private double modulation21_Stereo;
    private double modulation22_Amount;
    private double modulation22_Bipolar;
    private double modulation22_Bypass;
    private double modulation22_Power;
    private double modulation22_Stereo;
    private double modulation23_Amount;
    private double modulation23_Bipolar;
    private double modulation23_Bypass;
    private double modulation23_Power;
    private double modulation23_Stereo;
    private double modulation24_Amount;
    private double modulation24_Bipolar;
    private double modulation24_Bypass;
    private double modulation24_Power;
    private double modulation24_Stereo;
    private double modulation25_Amount;
    private double modulation25_Bipolar;
    private double modulation25_Bypass;
    private double modulation25_Power;
    private double modulation25_Stereo;
    private double modulation26_Amount;
    private double modulation26_Bipolar;
    private double modulation26_Bypass;
    private double modulation26_Power;
    private double modulation26_Stereo;
    private double modulation27_Amount;
    private double modulation27_Bipolar;
    private double modulation27_Bypass;
    private double modulation27_Power;
    private double modulation27_Stereo;
    private double modulation28_Amount;
    private double modulation28_Bipolar;
    private double modulation28_Bypass;
    private double modulation28_Power;
    private double modulation28_Stereo;
    private double modulation29_Amount;
    private double modulation29_Bipolar;
    private double modulation29_Bypass;
    private double modulation29_Power;
    private double modulation29_Stereo;
    private double modulation2_Amount;
    private double modulation2_Bipolar;
    private double modulation2_Bypass;
    private double modulation2_Power;
    private double modulation2_Stereo;
    private double modulation30_Amount;
    private double modulation30_Bipolar;
    private double modulation30_Bypass;
    private double modulation30_Power;
    private double modulation30_Stereo;
    private double modulation31_Amount;
    private double modulation31_Bipolar;
    private double modulation31_Bypass;
    private double modulation31_Power;
    private double modulation31_Stereo;
    private double modulation32_Amount;
    private double modulation32_Bipolar;
    private double modulation32_Bypass;
    private double modulation32_Power;
    private double modulation32_Stereo;
    private double modulation33_Amount;
    private double modulation33_Bipolar;
    private double modulation33_Bypass;
    private double modulation33_Power;
    private double modulation33_Stereo;
    private double modulation34_Amount;
    private double modulation34_Bipolar;
    private double modulation34_Bypass;
    private double modulation34_Power;
    private double modulation34_Stereo;
    private double modulation35_Amount;
    private double modulation35_Bipolar;
    private double modulation35_Bypass;
    private double modulation35_Power;
    private double modulation35_Stereo;
    private double modulation36_Amount;
    private double modulation36_Bipolar;
    private double modulation36_Bypass;
    private double modulation36_Power;
    private double modulation36_Stereo;
    private double modulation37_Amount;
    private double modulation37_Bipolar;
    private double modulation37_Bypass;
    private double modulation37_Power;
    private double modulation37_Stereo;
    private double modulation38_Amount;
    private double modulation38_Bipolar;
    private double modulation38_Bypass;
    private double modulation38_Power;
    private double modulation38_Stereo;
    private double modulation39_Amount;
    private double modulation39_Bipolar;
    private double modulation39_Bypass;
    private double modulation39_Power;
    private double modulation39_Stereo;
    private double modulation3_Amount;
    private double modulation3_Bipolar;
    private double modulation3_Bypass;
    private double modulation3_Power;
    private double modulation3_Stereo;
    private double modulation40_Amount;
    private double modulation40_Bipolar;
    private double modulation40_Bypass;
    private double modulation40_Power;
    private double modulation40_Stereo;
    private double modulation41_Amount;
    private double modulation41_Bipolar;
    private double modulation41_Bypass;
    private double modulation41_Power;
    private double modulation41_Stereo;
    private double modulation42_Amount;
    private double modulation42_Bipolar;
    private double modulation42_Bypass;
    private double modulation42_Power;
    private double modulation42_Stereo;
    private double modulation43_Amount;
    private double modulation43_Bipolar;
    private double modulation43_Bypass;
    private double modulation43_Power;
    private double modulation43_Stereo;
    private double modulation44_Amount;
    private double modulation44_Bipolar;
    private double modulation44_Bypass;
    private double modulation44_Power;
    private double modulation44_Stereo;
    private double modulation45_Amount;
    private double modulation45_Bipolar;
    private double modulation45_Bypass;
    private double modulation45_Power;
    private double modulation45_Stereo;
    private double modulation46_Amount;
    private double modulation46_Bipolar;
    private double modulation46_Bypass;
    private double modulation46_Power;
    private double modulation46_Stereo;
    private double modulation47_Amount;
    private double modulation47_Bipolar;
    private double modulation47_Bypass;
    private double modulation47_Power;
    private double modulation47_Stereo;
    private double modulation48_Amount;
    private double modulation48_Bipolar;
    private double modulation48_Bypass;
    private double modulation48_Power;
    private double modulation48_Stereo;
    private double modulation49_Amount;
    private double modulation49_Bipolar;
    private double modulation49_Bypass;
    private double modulation49_Power;
    private double modulation49_Stereo;
    private double modulation4_Amount;
    private double modulation4_Bipolar;
    private double modulation4_Bypass;
    private double modulation4_Power;
    private double modulation4_Stereo;
    private double modulation50_Amount;
    private double modulation50_Bipolar;
    private double modulation50_Bypass;
    private double modulation50_Power;
    private double modulation50_Stereo;
    private double modulation51_Amount;
    private double modulation51_Bipolar;
    private double modulation51_Bypass;
    private double modulation51_Power;
    private double modulation51_Stereo;
    private double modulation52_Amount;
    private double modulation52_Bipolar;
    private double modulation52_Bypass;
    private double modulation52_Power;
    private double modulation52_Stereo;
    private double modulation53_Amount;
    private double modulation53_Bipolar;
    private double modulation53_Bypass;
    private double modulation53_Power;
    private double modulation53_Stereo;
    private double modulation54_Amount;
    private double modulation54_Bipolar;
    private double modulation54_Bypass;
    private double modulation54_Power;
    private double modulation54_Stereo;
    private double modulation55_Amount;
    private double modulation55_Bipolar;
    private double modulation55_Bypass;
    private double modulation55_Power;
    private double modulation55_Stereo;
    private double modulation56_Amount;
    private double modulation56_Bipolar;
    private double modulation56_Bypass;
    private double modulation56_Power;
    private double modulation56_Stereo;
    private double modulation57_Amount;
    private double modulation57_Bipolar;
    private double modulation57_Bypass;
    private double modulation57_Power;
    private double modulation57_Stereo;
    private double modulation58_Amount;
    private double modulation58_Bipolar;
    private double modulation58_Bypass;
    private double modulation58_Power;
    private double modulation58_Stereo;
    private double modulation59_Amount;
    private double modulation59_Bipolar;
    private double modulation59_Bypass;
    private double modulation59_Power;
    private double modulation59_Stereo;
    private double modulation5_Amount;
    private double modulation5_Bipolar;
    private double modulation5_Bypass;
    private double modulation5_Power;
    private double modulation5_Stereo;
    private double modulation60_Amount;
    private double modulation60_Bipolar;
    private double modulation60_Bypass;
    private double modulation60_Power;
    private double modulation60_Stereo;
    private double modulation61_Amount;
    private double modulation61_Bipolar;
    private double modulation61_Bypass;
    private double modulation61_Power;
    private double modulation61_Stereo;
    private double modulation62_Amount;
    private double modulation62_Bipolar;
    private double modulation62_Bypass;
    private double modulation62_Power;
    private double modulation62_Stereo;
    private double modulation63_Amount;
    private double modulation63_Bipolar;
    private double modulation63_Bypass;
    private double modulation63_Power;
    private double modulation63_Stereo;
    private double modulation64_Amount;
    private double modulation64_Bipolar;
    private double modulation64_Bypass;
    private double modulation64_Power;
    private double modulation64_Stereo;
    private double modulation6_Amount;
    private double modulation6_Bipolar;
    private double modulation6_Bypass;
    private double modulation6_Power;
    private double modulation6_Stereo;
    private double modulation7_Amount;
    private double modulation7_Bipolar;
    private double modulation7_Bypass;
    private double modulation7_Power;
    private double modulation7_Stereo;
    private double modulation8_Amount;
    private double modulation8_Bipolar;
    private double modulation8_Bypass;
    private double modulation8_Power;
    private double modulation8_Stereo;
    private double modulation9_Amount;
    private double modulation9_Bipolar;
    private double modulation9_Bypass;
    private double modulation9_Power;
    private double modulation9_Stereo;
    private Modulation[] modulations;
    private double osc1_Destination;
    private double osc1_DetunePower;
    private double osc1_DetuneRange;
    private double osc1_DistortionAmount;
    private double osc1_DistortionPhase;
    private double osc1_DistortionSpread;
    private double osc1_DistortionType;
    private double osc1_FrameSpread;
    private double osc1_Level;
    private double osc1_MIDITrack;
    private double osc1_On;
    private double osc1_Pan;
    private double osc1_Phase;
    private double osc1_RandomPhase;
    private double osc1_SmoothInterpolation;
    private double osc1_SpectralMorphAmount;
    private double osc1_SpectralMorphSpread;
    private double osc1_SpectralMorphType;
    private double osc1_SpectralUnison;
    private double osc1_StackStyle;
    private double osc1_StereoSpread;
    private double osc1_Transpose;
    private double osc1_TransposeQuantize;
    private double osc1_Tune;
    private double osc1_UnisonBlend;
    private double osc1_UnisonDetune;
    private double osc1_UnisonVoices;
    private double osc1_View2D;
    private double osc1_WaveFrame;
    private double osc2_Destination;
    private double osc2_DetunePower;
    private double osc2_DetuneRange;
    private double osc2_DistortionAmount;
    private double osc2_DistortionPhase;
    private double osc2_DistortionSpread;
    private double osc2_DistortionType;
    private double osc2_FrameSpread;
    private double osc2_Level;
    private double osc2_MIDITrack;
    private double osc2_On;
    private double osc2_Pan;
    private double osc2_Phase;
    private double osc2_RandomPhase;
    private double osc2_SmoothInterpolation;
    private double osc2_SpectralMorphAmount;
    private double osc2_SpectralMorphSpread;
    private double osc2_SpectralMorphType;
    private double osc2_SpectralUnison;
    private double osc2_StackStyle;
    private double osc2_StereoSpread;
    private double osc2_Transpose;
    private double osc2_TransposeQuantize;
    private double osc2_Tune;
    private double osc2_UnisonBlend;
    private double osc2_UnisonDetune;
    private double osc2_UnisonVoices;
    private double osc2_View2D;
    private double osc2_WaveFrame;
    private double osc3_Destination;
    private double osc3_DetunePower;
    private double osc3_DetuneRange;
    private double osc3_DistortionAmount;
    private double osc3_DistortionPhase;
    private double osc3_DistortionSpread;
    private double osc3_DistortionType;
    private double osc3_FrameSpread;
    private double osc3_Level;
    private double osc3_MIDITrack;
    private double osc3_On;
    private double osc3_Pan;
    private double osc3_Phase;
    private double osc3_RandomPhase;
    private double osc3_SmoothInterpolation;
    private double osc3_SpectralMorphAmount;
    private double osc3_SpectralMorphSpread;
    private double osc3_SpectralMorphType;
    private double osc3_SpectralUnison;
    private double osc3_StackStyle;
    private double osc3_StereoSpread;
    private double osc3_Transpose;
    private double osc3_TransposeQuantize;
    private double osc3_Tune;
    private double osc3_UnisonBlend;
    private double osc3_UnisonDetune;
    private double osc3_UnisonVoices;
    private double osc3_View2D;
    private double osc3_WaveFrame;
    private double oversampling;
    private double phaserBlend;
    private double phaserCenter;
    private double phaserDryWet;
    private double phaserFeedback;
    private double phaserFrequency;
    private double phaserModDepth;
    private double phaserOn;
    private double phaserPhaseOffset;
    private double phaserSync;
    private double phaserTempo;
    private double pitchBendRange;
    private double pitchWheel;
    private double polyphony;
    private double portamentoForce;
    private double portamentoScale;
    private double portamentoSlope;
    private double portamentoTime;
    private double random1_Frequency;
    private Double random1_KeytrackTranspose;
    private Double random1_KeytrackTune;
    private double random1_Stereo;
    private double random1_Style;
    private double random1_Sync;
    private double random1_SyncType;
    private double random1_Tempo;
    private double random2_Frequency;
    private Double random2_KeytrackTranspose;
    private Double random2_KeytrackTune;
    private double random2_Stereo;
    private double random2_Style;
    private double random2_Sync;
    private double random2_SyncType;
    private double random2_Tempo;
    private double random3_Frequency;
    private Double random3_KeytrackTranspose;
    private Double random3_KeytrackTune;
    private double random3_Stereo;
    private double random3_Style;
    private double random3_Sync;
    private double random3_SyncType;
    private double random3_Tempo;
    private double random4_Frequency;
    private Double random4_KeytrackTranspose;
    private Double random4_KeytrackTune;
    private double random4_Stereo;
    private double random4_Style;
    private double random4_Sync;
    private double random4_SyncType;
    private double random4_Tempo;
    private double reverbChorusAmount;
    private double reverbChorusFrequency;
    private double reverbDecayTime;
    private Double reverbDelay;
    private double reverbDryWet;
    private double reverbHighShelfCutoff;
    private double reverbHighShelfGain;
    private double reverbLowShelfCutoff;
    private double reverbLowShelfGain;
    private double reverbOn;
    private double reverbPreHighCutoff;
    private double reverbPreLowCutoff;
    private double reverbSize;
    private Sample sample;
    private Double sampleBounce;
    private double sampleDestination;
    private double sampleKeytrack;
    private double sampleLevel;
    private double sampleLoop;
    private double sampleOn;
    private double samplePan;
    private double sampleRandomPhase;
    private double sampleTranspose;
    private double sampleTransposeQuantize;
    private double sampleTune;
    private Double stereoMode;
    private double stereoRouting;
    private double velocityTrack;
    private Double viewSpectrogram;
    private double voiceAmplitude;
    private Double voiceOverride;
    private double voicePriority;
    private Double voiceTranspose;
    private double voiceTune;
    private double volume;
    private Wavetable[] wavetables;

    @JsonProperty("beats_per_minute")
    public double getBeatsPerMinute() { return beatsPerMinute; }
    @JsonProperty("beats_per_minute")
    public void setBeatsPerMinute(double value) { this.beatsPerMinute = value; }

    @JsonProperty("bypass")
    public Double getBypass() { return bypass; }
    @JsonProperty("bypass")
    public void setBypass(Double value) { this.bypass = value; }

    @JsonProperty("chorus_cutoff")
    public Double getChorusCutoff() { return chorusCutoff; }
    @JsonProperty("chorus_cutoff")
    public void setChorusCutoff(Double value) { this.chorusCutoff = value; }

    @JsonProperty("chorus_damping")
    public Double getChorusDamping() { return chorusDamping; }
    @JsonProperty("chorus_damping")
    public void setChorusDamping(Double value) { this.chorusDamping = value; }

    @JsonProperty("chorus_delay_1")
    public double getChorusDelay1() { return chorusDelay1; }
    @JsonProperty("chorus_delay_1")
    public void setChorusDelay1(double value) { this.chorusDelay1 = value; }

    @JsonProperty("chorus_delay_2")
    public double getChorusDelay2() { return chorusDelay2; }
    @JsonProperty("chorus_delay_2")
    public void setChorusDelay2(double value) { this.chorusDelay2 = value; }

    @JsonProperty("chorus_dry_wet")
    public double getChorusDryWet() { return chorusDryWet; }
    @JsonProperty("chorus_dry_wet")
    public void setChorusDryWet(double value) { this.chorusDryWet = value; }

    @JsonProperty("chorus_feedback")
    public double getChorusFeedback() { return chorusFeedback; }
    @JsonProperty("chorus_feedback")
    public void setChorusFeedback(double value) { this.chorusFeedback = value; }

    @JsonProperty("chorus_frequency")
    public double getChorusFrequency() { return chorusFrequency; }
    @JsonProperty("chorus_frequency")
    public void setChorusFrequency(double value) { this.chorusFrequency = value; }

    @JsonProperty("chorus_mod_depth")
    public double getChorusModDepth() { return chorusModDepth; }
    @JsonProperty("chorus_mod_depth")
    public void setChorusModDepth(double value) { this.chorusModDepth = value; }

    @JsonProperty("chorus_on")
    public double getChorusOn() { return chorusOn; }
    @JsonProperty("chorus_on")
    public void setChorusOn(double value) { this.chorusOn = value; }

    @JsonProperty("chorus_spread")
    public Double getChorusSpread() { return chorusSpread; }
    @JsonProperty("chorus_spread")
    public void setChorusSpread(Double value) { this.chorusSpread = value; }

    @JsonProperty("chorus_sync")
    public double getChorusSync() { return chorusSync; }
    @JsonProperty("chorus_sync")
    public void setChorusSync(double value) { this.chorusSync = value; }

    @JsonProperty("chorus_tempo")
    public double getChorusTempo() { return chorusTempo; }
    @JsonProperty("chorus_tempo")
    public void setChorusTempo(double value) { this.chorusTempo = value; }

    @JsonProperty("chorus_voices")
    public double getChorusVoices() { return chorusVoices; }
    @JsonProperty("chorus_voices")
    public void setChorusVoices(double value) { this.chorusVoices = value; }

    @JsonProperty("compressor_attack")
    public double getCompressorAttack() { return compressorAttack; }
    @JsonProperty("compressor_attack")
    public void setCompressorAttack(double value) { this.compressorAttack = value; }

    @JsonProperty("compressor_band_gain")
    public double getCompressorBandGain() { return compressorBandGain; }
    @JsonProperty("compressor_band_gain")
    public void setCompressorBandGain(double value) { this.compressorBandGain = value; }

    @JsonProperty("compressor_band_lower_ratio")
    public double getCompressorBandLowerRatio() { return compressorBandLowerRatio; }
    @JsonProperty("compressor_band_lower_ratio")
    public void setCompressorBandLowerRatio(double value) { this.compressorBandLowerRatio = value; }

    @JsonProperty("compressor_band_lower_threshold")
    public double getCompressorBandLowerThreshold() { return compressorBandLowerThreshold; }
    @JsonProperty("compressor_band_lower_threshold")
    public void setCompressorBandLowerThreshold(double value) { this.compressorBandLowerThreshold = value; }

    @JsonProperty("compressor_band_upper_ratio")
    public double getCompressorBandUpperRatio() { return compressorBandUpperRatio; }
    @JsonProperty("compressor_band_upper_ratio")
    public void setCompressorBandUpperRatio(double value) { this.compressorBandUpperRatio = value; }

    @JsonProperty("compressor_band_upper_threshold")
    public double getCompressorBandUpperThreshold() { return compressorBandUpperThreshold; }
    @JsonProperty("compressor_band_upper_threshold")
    public void setCompressorBandUpperThreshold(double value) { this.compressorBandUpperThreshold = value; }

    @JsonProperty("compressor_enabled_bands")
    public double getCompressorEnabledBands() { return compressorEnabledBands; }
    @JsonProperty("compressor_enabled_bands")
    public void setCompressorEnabledBands(double value) { this.compressorEnabledBands = value; }

    @JsonProperty("compressor_high_gain")
    public double getCompressorHighGain() { return compressorHighGain; }
    @JsonProperty("compressor_high_gain")
    public void setCompressorHighGain(double value) { this.compressorHighGain = value; }

    @JsonProperty("compressor_high_lower_ratio")
    public double getCompressorHighLowerRatio() { return compressorHighLowerRatio; }
    @JsonProperty("compressor_high_lower_ratio")
    public void setCompressorHighLowerRatio(double value) { this.compressorHighLowerRatio = value; }

    @JsonProperty("compressor_high_lower_threshold")
    public double getCompressorHighLowerThreshold() { return compressorHighLowerThreshold; }
    @JsonProperty("compressor_high_lower_threshold")
    public void setCompressorHighLowerThreshold(double value) { this.compressorHighLowerThreshold = value; }

    @JsonProperty("compressor_high_upper_ratio")
    public double getCompressorHighUpperRatio() { return compressorHighUpperRatio; }
    @JsonProperty("compressor_high_upper_ratio")
    public void setCompressorHighUpperRatio(double value) { this.compressorHighUpperRatio = value; }

    @JsonProperty("compressor_high_upper_threshold")
    public double getCompressorHighUpperThreshold() { return compressorHighUpperThreshold; }
    @JsonProperty("compressor_high_upper_threshold")
    public void setCompressorHighUpperThreshold(double value) { this.compressorHighUpperThreshold = value; }

    @JsonProperty("compressor_low_gain")
    public double getCompressorLowGain() { return compressorLowGain; }
    @JsonProperty("compressor_low_gain")
    public void setCompressorLowGain(double value) { this.compressorLowGain = value; }

    @JsonProperty("compressor_low_lower_ratio")
    public double getCompressorLowLowerRatio() { return compressorLowLowerRatio; }
    @JsonProperty("compressor_low_lower_ratio")
    public void setCompressorLowLowerRatio(double value) { this.compressorLowLowerRatio = value; }

    @JsonProperty("compressor_low_lower_threshold")
    public double getCompressorLowLowerThreshold() { return compressorLowLowerThreshold; }
    @JsonProperty("compressor_low_lower_threshold")
    public void setCompressorLowLowerThreshold(double value) { this.compressorLowLowerThreshold = value; }

    @JsonProperty("compressor_low_upper_ratio")
    public double getCompressorLowUpperRatio() { return compressorLowUpperRatio; }
    @JsonProperty("compressor_low_upper_ratio")
    public void setCompressorLowUpperRatio(double value) { this.compressorLowUpperRatio = value; }

    @JsonProperty("compressor_low_upper_threshold")
    public double getCompressorLowUpperThreshold() { return compressorLowUpperThreshold; }
    @JsonProperty("compressor_low_upper_threshold")
    public void setCompressorLowUpperThreshold(double value) { this.compressorLowUpperThreshold = value; }

    @JsonProperty("compressor_mix")
    public Double getCompressorMix() { return compressorMix; }
    @JsonProperty("compressor_mix")
    public void setCompressorMix(Double value) { this.compressorMix = value; }

    @JsonProperty("compressor_on")
    public double getCompressorOn() { return compressorOn; }
    @JsonProperty("compressor_on")
    public void setCompressorOn(double value) { this.compressorOn = value; }

    @JsonProperty("compressor_release")
    public double getCompressorRelease() { return compressorRelease; }
    @JsonProperty("compressor_release")
    public void setCompressorRelease(double value) { this.compressorRelease = value; }

    @JsonProperty("delay_aux_frequency")
    public double getDelayAuxFrequency() { return delayAuxFrequency; }
    @JsonProperty("delay_aux_frequency")
    public void setDelayAuxFrequency(double value) { this.delayAuxFrequency = value; }

    @JsonProperty("delay_aux_sync")
    public double getDelayAuxSync() { return delayAuxSync; }
    @JsonProperty("delay_aux_sync")
    public void setDelayAuxSync(double value) { this.delayAuxSync = value; }

    @JsonProperty("delay_aux_tempo")
    public double getDelayAuxTempo() { return delayAuxTempo; }
    @JsonProperty("delay_aux_tempo")
    public void setDelayAuxTempo(double value) { this.delayAuxTempo = value; }

    @JsonProperty("delay_dry_wet")
    public double getDelayDryWet() { return delayDryWet; }
    @JsonProperty("delay_dry_wet")
    public void setDelayDryWet(double value) { this.delayDryWet = value; }

    @JsonProperty("delay_feedback")
    public double getDelayFeedback() { return delayFeedback; }
    @JsonProperty("delay_feedback")
    public void setDelayFeedback(double value) { this.delayFeedback = value; }

    @JsonProperty("delay_filter_cutoff")
    public double getDelayFilterCutoff() { return delayFilterCutoff; }
    @JsonProperty("delay_filter_cutoff")
    public void setDelayFilterCutoff(double value) { this.delayFilterCutoff = value; }

    @JsonProperty("delay_filter_spread")
    public double getDelayFilterSpread() { return delayFilterSpread; }
    @JsonProperty("delay_filter_spread")
    public void setDelayFilterSpread(double value) { this.delayFilterSpread = value; }

    @JsonProperty("delay_frequency")
    public double getDelayFrequency() { return delayFrequency; }
    @JsonProperty("delay_frequency")
    public void setDelayFrequency(double value) { this.delayFrequency = value; }

    @JsonProperty("delay_on")
    public double getDelayOn() { return delayOn; }
    @JsonProperty("delay_on")
    public void setDelayOn(double value) { this.delayOn = value; }

    @JsonProperty("delay_style")
    public double getDelayStyle() { return delayStyle; }
    @JsonProperty("delay_style")
    public void setDelayStyle(double value) { this.delayStyle = value; }

    @JsonProperty("delay_sync")
    public double getDelaySync() { return delaySync; }
    @JsonProperty("delay_sync")
    public void setDelaySync(double value) { this.delaySync = value; }

    @JsonProperty("delay_tempo")
    public double getDelayTempo() { return delayTempo; }
    @JsonProperty("delay_tempo")
    public void setDelayTempo(double value) { this.delayTempo = value; }

    @JsonProperty("distortion_drive")
    public double getDistortionDrive() { return distortionDrive; }
    @JsonProperty("distortion_drive")
    public void setDistortionDrive(double value) { this.distortionDrive = value; }

    @JsonProperty("distortion_filter_blend")
    public double getDistortionFilterBlend() { return distortionFilterBlend; }
    @JsonProperty("distortion_filter_blend")
    public void setDistortionFilterBlend(double value) { this.distortionFilterBlend = value; }

    @JsonProperty("distortion_filter_cutoff")
    public double getDistortionFilterCutoff() { return distortionFilterCutoff; }
    @JsonProperty("distortion_filter_cutoff")
    public void setDistortionFilterCutoff(double value) { this.distortionFilterCutoff = value; }

    @JsonProperty("distortion_filter_order")
    public double getDistortionFilterOrder() { return distortionFilterOrder; }
    @JsonProperty("distortion_filter_order")
    public void setDistortionFilterOrder(double value) { this.distortionFilterOrder = value; }

    @JsonProperty("distortion_filter_resonance")
    public double getDistortionFilterResonance() { return distortionFilterResonance; }
    @JsonProperty("distortion_filter_resonance")
    public void setDistortionFilterResonance(double value) { this.distortionFilterResonance = value; }

    @JsonProperty("distortion_mix")
    public double getDistortionMix() { return distortionMix; }
    @JsonProperty("distortion_mix")
    public void setDistortionMix(double value) { this.distortionMix = value; }

    @JsonProperty("distortion_on")
    public double getDistortionOn() { return distortionOn; }
    @JsonProperty("distortion_on")
    public void setDistortionOn(double value) { this.distortionOn = value; }

    @JsonProperty("distortion_type")
    public double getDistortionType() { return distortionType; }
    @JsonProperty("distortion_type")
    public void setDistortionType(double value) { this.distortionType = value; }

    @JsonProperty("effect_chain_order")
    public double getEffectChainOrder() { return effectChainOrder; }
    @JsonProperty("effect_chain_order")
    public void setEffectChainOrder(double value) { this.effectChainOrder = value; }

    @JsonProperty("env_1_attack")
    public double getEnv1Attack() { return env1_Attack; }
    @JsonProperty("env_1_attack")
    public void setEnv1Attack(double value) { this.env1_Attack = value; }

    @JsonProperty("env_1_attack_power")
    public double getEnv1AttackPower() { return env1_AttackPower; }
    @JsonProperty("env_1_attack_power")
    public void setEnv1AttackPower(double value) { this.env1_AttackPower = value; }

    @JsonProperty("env_1_decay")
    public double getEnv1Decay() { return env1_Decay; }
    @JsonProperty("env_1_decay")
    public void setEnv1Decay(double value) { this.env1_Decay = value; }

    @JsonProperty("env_1_decay_power")
    public double getEnv1DecayPower() { return env1_DecayPower; }
    @JsonProperty("env_1_decay_power")
    public void setEnv1DecayPower(double value) { this.env1_DecayPower = value; }

    @JsonProperty("env_1_delay")
    public double getEnv1Delay() { return env1_Delay; }
    @JsonProperty("env_1_delay")
    public void setEnv1Delay(double value) { this.env1_Delay = value; }

    @JsonProperty("env_1_hold")
    public double getEnv1Hold() { return env1_Hold; }
    @JsonProperty("env_1_hold")
    public void setEnv1Hold(double value) { this.env1_Hold = value; }

    @JsonProperty("env_1_release")
    public double getEnv1Release() { return env1_Release; }
    @JsonProperty("env_1_release")
    public void setEnv1Release(double value) { this.env1_Release = value; }

    @JsonProperty("env_1_release_power")
    public double getEnv1ReleasePower() { return env1_ReleasePower; }
    @JsonProperty("env_1_release_power")
    public void setEnv1ReleasePower(double value) { this.env1_ReleasePower = value; }

    @JsonProperty("env_1_sustain")
    public double getEnv1Sustain() { return env1_Sustain; }
    @JsonProperty("env_1_sustain")
    public void setEnv1Sustain(double value) { this.env1_Sustain = value; }

    @JsonProperty("env_2_attack")
    public double getEnv2Attack() { return env2_Attack; }
    @JsonProperty("env_2_attack")
    public void setEnv2Attack(double value) { this.env2_Attack = value; }

    @JsonProperty("env_2_attack_power")
    public double getEnv2AttackPower() { return env2_AttackPower; }
    @JsonProperty("env_2_attack_power")
    public void setEnv2AttackPower(double value) { this.env2_AttackPower = value; }

    @JsonProperty("env_2_decay")
    public double getEnv2Decay() { return env2_Decay; }
    @JsonProperty("env_2_decay")
    public void setEnv2Decay(double value) { this.env2_Decay = value; }

    @JsonProperty("env_2_decay_power")
    public double getEnv2DecayPower() { return env2_DecayPower; }
    @JsonProperty("env_2_decay_power")
    public void setEnv2DecayPower(double value) { this.env2_DecayPower = value; }

    @JsonProperty("env_2_delay")
    public double getEnv2Delay() { return env2_Delay; }
    @JsonProperty("env_2_delay")
    public void setEnv2Delay(double value) { this.env2_Delay = value; }

    @JsonProperty("env_2_hold")
    public double getEnv2Hold() { return env2_Hold; }
    @JsonProperty("env_2_hold")
    public void setEnv2Hold(double value) { this.env2_Hold = value; }

    @JsonProperty("env_2_release")
    public double getEnv2Release() { return env2_Release; }
    @JsonProperty("env_2_release")
    public void setEnv2Release(double value) { this.env2_Release = value; }

    @JsonProperty("env_2_release_power")
    public double getEnv2ReleasePower() { return env2_ReleasePower; }
    @JsonProperty("env_2_release_power")
    public void setEnv2ReleasePower(double value) { this.env2_ReleasePower = value; }

    @JsonProperty("env_2_sustain")
    public double getEnv2Sustain() { return env2_Sustain; }
    @JsonProperty("env_2_sustain")
    public void setEnv2Sustain(double value) { this.env2_Sustain = value; }

    @JsonProperty("env_3_attack")
    public double getEnv3Attack() { return env3_Attack; }
    @JsonProperty("env_3_attack")
    public void setEnv3Attack(double value) { this.env3_Attack = value; }

    @JsonProperty("env_3_attack_power")
    public double getEnv3AttackPower() { return env3_AttackPower; }
    @JsonProperty("env_3_attack_power")
    public void setEnv3AttackPower(double value) { this.env3_AttackPower = value; }

    @JsonProperty("env_3_decay")
    public double getEnv3Decay() { return env3_Decay; }
    @JsonProperty("env_3_decay")
    public void setEnv3Decay(double value) { this.env3_Decay = value; }

    @JsonProperty("env_3_decay_power")
    public double getEnv3DecayPower() { return env3_DecayPower; }
    @JsonProperty("env_3_decay_power")
    public void setEnv3DecayPower(double value) { this.env3_DecayPower = value; }

    @JsonProperty("env_3_delay")
    public double getEnv3Delay() { return env3_Delay; }
    @JsonProperty("env_3_delay")
    public void setEnv3Delay(double value) { this.env3_Delay = value; }

    @JsonProperty("env_3_hold")
    public double getEnv3Hold() { return env3_Hold; }
    @JsonProperty("env_3_hold")
    public void setEnv3Hold(double value) { this.env3_Hold = value; }

    @JsonProperty("env_3_release")
    public double getEnv3Release() { return env3_Release; }
    @JsonProperty("env_3_release")
    public void setEnv3Release(double value) { this.env3_Release = value; }

    @JsonProperty("env_3_release_power")
    public double getEnv3ReleasePower() { return env3_ReleasePower; }
    @JsonProperty("env_3_release_power")
    public void setEnv3ReleasePower(double value) { this.env3_ReleasePower = value; }

    @JsonProperty("env_3_sustain")
    public double getEnv3Sustain() { return env3_Sustain; }
    @JsonProperty("env_3_sustain")
    public void setEnv3Sustain(double value) { this.env3_Sustain = value; }

    @JsonProperty("env_4_attack")
    public double getEnv4Attack() { return env4_Attack; }
    @JsonProperty("env_4_attack")
    public void setEnv4Attack(double value) { this.env4_Attack = value; }

    @JsonProperty("env_4_attack_power")
    public double getEnv4AttackPower() { return env4_AttackPower; }
    @JsonProperty("env_4_attack_power")
    public void setEnv4AttackPower(double value) { this.env4_AttackPower = value; }

    @JsonProperty("env_4_decay")
    public double getEnv4Decay() { return env4_Decay; }
    @JsonProperty("env_4_decay")
    public void setEnv4Decay(double value) { this.env4_Decay = value; }

    @JsonProperty("env_4_decay_power")
    public double getEnv4DecayPower() { return env4_DecayPower; }
    @JsonProperty("env_4_decay_power")
    public void setEnv4DecayPower(double value) { this.env4_DecayPower = value; }

    @JsonProperty("env_4_delay")
    public double getEnv4Delay() { return env4_Delay; }
    @JsonProperty("env_4_delay")
    public void setEnv4Delay(double value) { this.env4_Delay = value; }

    @JsonProperty("env_4_hold")
    public double getEnv4Hold() { return env4_Hold; }
    @JsonProperty("env_4_hold")
    public void setEnv4Hold(double value) { this.env4_Hold = value; }

    @JsonProperty("env_4_release")
    public double getEnv4Release() { return env4_Release; }
    @JsonProperty("env_4_release")
    public void setEnv4Release(double value) { this.env4_Release = value; }

    @JsonProperty("env_4_release_power")
    public double getEnv4ReleasePower() { return env4_ReleasePower; }
    @JsonProperty("env_4_release_power")
    public void setEnv4ReleasePower(double value) { this.env4_ReleasePower = value; }

    @JsonProperty("env_4_sustain")
    public double getEnv4Sustain() { return env4_Sustain; }
    @JsonProperty("env_4_sustain")
    public void setEnv4Sustain(double value) { this.env4_Sustain = value; }

    @JsonProperty("env_5_attack")
    public double getEnv5Attack() { return env5_Attack; }
    @JsonProperty("env_5_attack")
    public void setEnv5Attack(double value) { this.env5_Attack = value; }

    @JsonProperty("env_5_attack_power")
    public double getEnv5AttackPower() { return env5_AttackPower; }
    @JsonProperty("env_5_attack_power")
    public void setEnv5AttackPower(double value) { this.env5_AttackPower = value; }

    @JsonProperty("env_5_decay")
    public double getEnv5Decay() { return env5_Decay; }
    @JsonProperty("env_5_decay")
    public void setEnv5Decay(double value) { this.env5_Decay = value; }

    @JsonProperty("env_5_decay_power")
    public double getEnv5DecayPower() { return env5_DecayPower; }
    @JsonProperty("env_5_decay_power")
    public void setEnv5DecayPower(double value) { this.env5_DecayPower = value; }

    @JsonProperty("env_5_delay")
    public double getEnv5Delay() { return env5_Delay; }
    @JsonProperty("env_5_delay")
    public void setEnv5Delay(double value) { this.env5_Delay = value; }

    @JsonProperty("env_5_hold")
    public double getEnv5Hold() { return env5_Hold; }
    @JsonProperty("env_5_hold")
    public void setEnv5Hold(double value) { this.env5_Hold = value; }

    @JsonProperty("env_5_release")
    public double getEnv5Release() { return env5_Release; }
    @JsonProperty("env_5_release")
    public void setEnv5Release(double value) { this.env5_Release = value; }

    @JsonProperty("env_5_release_power")
    public double getEnv5ReleasePower() { return env5_ReleasePower; }
    @JsonProperty("env_5_release_power")
    public void setEnv5ReleasePower(double value) { this.env5_ReleasePower = value; }

    @JsonProperty("env_5_sustain")
    public double getEnv5Sustain() { return env5_Sustain; }
    @JsonProperty("env_5_sustain")
    public void setEnv5Sustain(double value) { this.env5_Sustain = value; }

    @JsonProperty("env_6_attack")
    public double getEnv6Attack() { return env6_Attack; }
    @JsonProperty("env_6_attack")
    public void setEnv6Attack(double value) { this.env6_Attack = value; }

    @JsonProperty("env_6_attack_power")
    public double getEnv6AttackPower() { return env6_AttackPower; }
    @JsonProperty("env_6_attack_power")
    public void setEnv6AttackPower(double value) { this.env6_AttackPower = value; }

    @JsonProperty("env_6_decay")
    public double getEnv6Decay() { return env6_Decay; }
    @JsonProperty("env_6_decay")
    public void setEnv6Decay(double value) { this.env6_Decay = value; }

    @JsonProperty("env_6_decay_power")
    public double getEnv6DecayPower() { return env6_DecayPower; }
    @JsonProperty("env_6_decay_power")
    public void setEnv6DecayPower(double value) { this.env6_DecayPower = value; }

    @JsonProperty("env_6_delay")
    public double getEnv6Delay() { return env6_Delay; }
    @JsonProperty("env_6_delay")
    public void setEnv6Delay(double value) { this.env6_Delay = value; }

    @JsonProperty("env_6_hold")
    public double getEnv6Hold() { return env6_Hold; }
    @JsonProperty("env_6_hold")
    public void setEnv6Hold(double value) { this.env6_Hold = value; }

    @JsonProperty("env_6_release")
    public double getEnv6Release() { return env6_Release; }
    @JsonProperty("env_6_release")
    public void setEnv6Release(double value) { this.env6_Release = value; }

    @JsonProperty("env_6_release_power")
    public double getEnv6ReleasePower() { return env6_ReleasePower; }
    @JsonProperty("env_6_release_power")
    public void setEnv6ReleasePower(double value) { this.env6_ReleasePower = value; }

    @JsonProperty("env_6_sustain")
    public double getEnv6Sustain() { return env6_Sustain; }
    @JsonProperty("env_6_sustain")
    public void setEnv6Sustain(double value) { this.env6_Sustain = value; }

    @JsonProperty("eq_band_cutoff")
    public double getEqBandCutoff() { return eqBandCutoff; }
    @JsonProperty("eq_band_cutoff")
    public void setEqBandCutoff(double value) { this.eqBandCutoff = value; }

    @JsonProperty("eq_band_gain")
    public double getEqBandGain() { return eqBandGain; }
    @JsonProperty("eq_band_gain")
    public void setEqBandGain(double value) { this.eqBandGain = value; }

    @JsonProperty("eq_band_mode")
    public double getEqBandMode() { return eqBandMode; }
    @JsonProperty("eq_band_mode")
    public void setEqBandMode(double value) { this.eqBandMode = value; }

    @JsonProperty("eq_band_resonance")
    public double getEqBandResonance() { return eqBandResonance; }
    @JsonProperty("eq_band_resonance")
    public void setEqBandResonance(double value) { this.eqBandResonance = value; }

    @JsonProperty("eq_high_cutoff")
    public double getEqHighCutoff() { return eqHighCutoff; }
    @JsonProperty("eq_high_cutoff")
    public void setEqHighCutoff(double value) { this.eqHighCutoff = value; }

    @JsonProperty("eq_high_gain")
    public double getEqHighGain() { return eqHighGain; }
    @JsonProperty("eq_high_gain")
    public void setEqHighGain(double value) { this.eqHighGain = value; }

    @JsonProperty("eq_high_mode")
    public double getEqHighMode() { return eqHighMode; }
    @JsonProperty("eq_high_mode")
    public void setEqHighMode(double value) { this.eqHighMode = value; }

    @JsonProperty("eq_high_resonance")
    public double getEqHighResonance() { return eqHighResonance; }
    @JsonProperty("eq_high_resonance")
    public void setEqHighResonance(double value) { this.eqHighResonance = value; }

    @JsonProperty("eq_low_cutoff")
    public double getEqLowCutoff() { return eqLowCutoff; }
    @JsonProperty("eq_low_cutoff")
    public void setEqLowCutoff(double value) { this.eqLowCutoff = value; }

    @JsonProperty("eq_low_gain")
    public double getEqLowGain() { return eqLowGain; }
    @JsonProperty("eq_low_gain")
    public void setEqLowGain(double value) { this.eqLowGain = value; }

    @JsonProperty("eq_low_mode")
    public double getEqLowMode() { return eqLowMode; }
    @JsonProperty("eq_low_mode")
    public void setEqLowMode(double value) { this.eqLowMode = value; }

    @JsonProperty("eq_low_resonance")
    public double getEqLowResonance() { return eqLowResonance; }
    @JsonProperty("eq_low_resonance")
    public void setEqLowResonance(double value) { this.eqLowResonance = value; }

    @JsonProperty("eq_on")
    public double getEqOn() { return eqOn; }
    @JsonProperty("eq_on")
    public void setEqOn(double value) { this.eqOn = value; }

    @JsonProperty("filter_1_blend")
    public double getFilter1Blend() { return filter1_Blend; }
    @JsonProperty("filter_1_blend")
    public void setFilter1Blend(double value) { this.filter1_Blend = value; }

    @JsonProperty("filter_1_blend_transpose")
    public double getFilter1BlendTranspose() { return filter1_BlendTranspose; }
    @JsonProperty("filter_1_blend_transpose")
    public void setFilter1BlendTranspose(double value) { this.filter1_BlendTranspose = value; }

    @JsonProperty("filter_1_cutoff")
    public double getFilter1Cutoff() { return filter1_Cutoff; }
    @JsonProperty("filter_1_cutoff")
    public void setFilter1Cutoff(double value) { this.filter1_Cutoff = value; }

    @JsonProperty("filter_1_drive")
    public double getFilter1Drive() { return filter1_Drive; }
    @JsonProperty("filter_1_drive")
    public void setFilter1Drive(double value) { this.filter1_Drive = value; }

    @JsonProperty("filter_1_filter_input")
    public double getFilter1FilterInput() { return filter1_FilterInput; }
    @JsonProperty("filter_1_filter_input")
    public void setFilter1FilterInput(double value) { this.filter1_FilterInput = value; }

    @JsonProperty("filter_1_formant_resonance")
    public double getFilter1FormantResonance() { return filter1_FormantResonance; }
    @JsonProperty("filter_1_formant_resonance")
    public void setFilter1FormantResonance(double value) { this.filter1_FormantResonance = value; }

    @JsonProperty("filter_1_formant_spread")
    public Double getFilter1FormantSpread() { return filter1_FormantSpread; }
    @JsonProperty("filter_1_formant_spread")
    public void setFilter1FormantSpread(Double value) { this.filter1_FormantSpread = value; }

    @JsonProperty("filter_1_formant_transpose")
    public double getFilter1FormantTranspose() { return filter1_FormantTranspose; }
    @JsonProperty("filter_1_formant_transpose")
    public void setFilter1FormantTranspose(double value) { this.filter1_FormantTranspose = value; }

    @JsonProperty("filter_1_formant_x")
    public double getFilter1FormantX() { return filter1_FormantX; }
    @JsonProperty("filter_1_formant_x")
    public void setFilter1FormantX(double value) { this.filter1_FormantX = value; }

    @JsonProperty("filter_1_formant_y")
    public double getFilter1FormantY() { return filter1_FormantY; }
    @JsonProperty("filter_1_formant_y")
    public void setFilter1FormantY(double value) { this.filter1_FormantY = value; }

    @JsonProperty("filter_1_keytrack")
    public double getFilter1Keytrack() { return filter1_Keytrack; }
    @JsonProperty("filter_1_keytrack")
    public void setFilter1Keytrack(double value) { this.filter1_Keytrack = value; }

    @JsonProperty("filter_1_mix")
    public double getFilter1Mix() { return filter1_Mix; }
    @JsonProperty("filter_1_mix")
    public void setFilter1Mix(double value) { this.filter1_Mix = value; }

    @JsonProperty("filter_1_model")
    public double getFilter1Model() { return filter1_Model; }
    @JsonProperty("filter_1_model")
    public void setFilter1Model(double value) { this.filter1_Model = value; }

    @JsonProperty("filter_1_on")
    public double getFilter1On() { return filter1_On; }
    @JsonProperty("filter_1_on")
    public void setFilter1On(double value) { this.filter1_On = value; }

    @JsonProperty("filter_1_resonance")
    public double getFilter1Resonance() { return filter1_Resonance; }
    @JsonProperty("filter_1_resonance")
    public void setFilter1Resonance(double value) { this.filter1_Resonance = value; }

    @JsonProperty("filter_1_style")
    public double getFilter1Style() { return filter1_Style; }
    @JsonProperty("filter_1_style")
    public void setFilter1Style(double value) { this.filter1_Style = value; }

    @JsonProperty("filter_2_blend")
    public double getFilter2Blend() { return filter2_Blend; }
    @JsonProperty("filter_2_blend")
    public void setFilter2Blend(double value) { this.filter2_Blend = value; }

    @JsonProperty("filter_2_blend_transpose")
    public double getFilter2BlendTranspose() { return filter2_BlendTranspose; }
    @JsonProperty("filter_2_blend_transpose")
    public void setFilter2BlendTranspose(double value) { this.filter2_BlendTranspose = value; }

    @JsonProperty("filter_2_cutoff")
    public double getFilter2Cutoff() { return filter2_Cutoff; }
    @JsonProperty("filter_2_cutoff")
    public void setFilter2Cutoff(double value) { this.filter2_Cutoff = value; }

    @JsonProperty("filter_2_drive")
    public double getFilter2Drive() { return filter2_Drive; }
    @JsonProperty("filter_2_drive")
    public void setFilter2Drive(double value) { this.filter2_Drive = value; }

    @JsonProperty("filter_2_filter_input")
    public double getFilter2FilterInput() { return filter2_FilterInput; }
    @JsonProperty("filter_2_filter_input")
    public void setFilter2FilterInput(double value) { this.filter2_FilterInput = value; }

    @JsonProperty("filter_2_formant_resonance")
    public double getFilter2FormantResonance() { return filter2_FormantResonance; }
    @JsonProperty("filter_2_formant_resonance")
    public void setFilter2FormantResonance(double value) { this.filter2_FormantResonance = value; }

    @JsonProperty("filter_2_formant_spread")
    public Double getFilter2FormantSpread() { return filter2_FormantSpread; }
    @JsonProperty("filter_2_formant_spread")
    public void setFilter2FormantSpread(Double value) { this.filter2_FormantSpread = value; }

    @JsonProperty("filter_2_formant_transpose")
    public double getFilter2FormantTranspose() { return filter2_FormantTranspose; }
    @JsonProperty("filter_2_formant_transpose")
    public void setFilter2FormantTranspose(double value) { this.filter2_FormantTranspose = value; }

    @JsonProperty("filter_2_formant_x")
    public double getFilter2FormantX() { return filter2_FormantX; }
    @JsonProperty("filter_2_formant_x")
    public void setFilter2FormantX(double value) { this.filter2_FormantX = value; }

    @JsonProperty("filter_2_formant_y")
    public double getFilter2FormantY() { return filter2_FormantY; }
    @JsonProperty("filter_2_formant_y")
    public void setFilter2FormantY(double value) { this.filter2_FormantY = value; }

    @JsonProperty("filter_2_keytrack")
    public double getFilter2Keytrack() { return filter2_Keytrack; }
    @JsonProperty("filter_2_keytrack")
    public void setFilter2Keytrack(double value) { this.filter2_Keytrack = value; }

    @JsonProperty("filter_2_mix")
    public double getFilter2Mix() { return filter2_Mix; }
    @JsonProperty("filter_2_mix")
    public void setFilter2Mix(double value) { this.filter2_Mix = value; }

    @JsonProperty("filter_2_model")
    public double getFilter2Model() { return filter2_Model; }
    @JsonProperty("filter_2_model")
    public void setFilter2Model(double value) { this.filter2_Model = value; }

    @JsonProperty("filter_2_on")
    public double getFilter2On() { return filter2_On; }
    @JsonProperty("filter_2_on")
    public void setFilter2On(double value) { this.filter2_On = value; }

    @JsonProperty("filter_2_resonance")
    public double getFilter2Resonance() { return filter2_Resonance; }
    @JsonProperty("filter_2_resonance")
    public void setFilter2Resonance(double value) { this.filter2_Resonance = value; }

    @JsonProperty("filter_2_style")
    public double getFilter2Style() { return filter2_Style; }
    @JsonProperty("filter_2_style")
    public void setFilter2Style(double value) { this.filter2_Style = value; }

    @JsonProperty("filter_fx_blend")
    public double getFilterFxBlend() { return filterFxBlend; }
    @JsonProperty("filter_fx_blend")
    public void setFilterFxBlend(double value) { this.filterFxBlend = value; }

    @JsonProperty("filter_fx_blend_transpose")
    public double getFilterFxBlendTranspose() { return filterFxBlendTranspose; }
    @JsonProperty("filter_fx_blend_transpose")
    public void setFilterFxBlendTranspose(double value) { this.filterFxBlendTranspose = value; }

    @JsonProperty("filter_fx_cutoff")
    public double getFilterFxCutoff() { return filterFxCutoff; }
    @JsonProperty("filter_fx_cutoff")
    public void setFilterFxCutoff(double value) { this.filterFxCutoff = value; }

    @JsonProperty("filter_fx_drive")
    public double getFilterFxDrive() { return filterFxDrive; }
    @JsonProperty("filter_fx_drive")
    public void setFilterFxDrive(double value) { this.filterFxDrive = value; }

    @JsonProperty("filter_fx_formant_resonance")
    public double getFilterFxFormantResonance() { return filterFxFormantResonance; }
    @JsonProperty("filter_fx_formant_resonance")
    public void setFilterFxFormantResonance(double value) { this.filterFxFormantResonance = value; }

    @JsonProperty("filter_fx_formant_spread")
    public Double getFilterFxFormantSpread() { return filterFxFormantSpread; }
    @JsonProperty("filter_fx_formant_spread")
    public void setFilterFxFormantSpread(Double value) { this.filterFxFormantSpread = value; }

    @JsonProperty("filter_fx_formant_transpose")
    public double getFilterFxFormantTranspose() { return filterFxFormantTranspose; }
    @JsonProperty("filter_fx_formant_transpose")
    public void setFilterFxFormantTranspose(double value) { this.filterFxFormantTranspose = value; }

    @JsonProperty("filter_fx_formant_x")
    public double getFilterFxFormantX() { return filterFxFormantX; }
    @JsonProperty("filter_fx_formant_x")
    public void setFilterFxFormantX(double value) { this.filterFxFormantX = value; }

    @JsonProperty("filter_fx_formant_y")
    public double getFilterFxFormantY() { return filterFxFormantY; }
    @JsonProperty("filter_fx_formant_y")
    public void setFilterFxFormantY(double value) { this.filterFxFormantY = value; }

    @JsonProperty("filter_fx_keytrack")
    public double getFilterFxKeytrack() { return filterFxKeytrack; }
    @JsonProperty("filter_fx_keytrack")
    public void setFilterFxKeytrack(double value) { this.filterFxKeytrack = value; }

    @JsonProperty("filter_fx_mix")
    public double getFilterFxMix() { return filterFxMix; }
    @JsonProperty("filter_fx_mix")
    public void setFilterFxMix(double value) { this.filterFxMix = value; }

    @JsonProperty("filter_fx_model")
    public double getFilterFxModel() { return filterFxModel; }
    @JsonProperty("filter_fx_model")
    public void setFilterFxModel(double value) { this.filterFxModel = value; }

    @JsonProperty("filter_fx_on")
    public double getFilterFxOn() { return filterFxOn; }
    @JsonProperty("filter_fx_on")
    public void setFilterFxOn(double value) { this.filterFxOn = value; }

    @JsonProperty("filter_fx_resonance")
    public double getFilterFxResonance() { return filterFxResonance; }
    @JsonProperty("filter_fx_resonance")
    public void setFilterFxResonance(double value) { this.filterFxResonance = value; }

    @JsonProperty("filter_fx_style")
    public double getFilterFxStyle() { return filterFxStyle; }
    @JsonProperty("filter_fx_style")
    public void setFilterFxStyle(double value) { this.filterFxStyle = value; }

    @JsonProperty("flanger_center")
    public double getFlangerCenter() { return flangerCenter; }
    @JsonProperty("flanger_center")
    public void setFlangerCenter(double value) { this.flangerCenter = value; }

    @JsonProperty("flanger_dry_wet")
    public double getFlangerDryWet() { return flangerDryWet; }
    @JsonProperty("flanger_dry_wet")
    public void setFlangerDryWet(double value) { this.flangerDryWet = value; }

    @JsonProperty("flanger_feedback")
    public double getFlangerFeedback() { return flangerFeedback; }
    @JsonProperty("flanger_feedback")
    public void setFlangerFeedback(double value) { this.flangerFeedback = value; }

    @JsonProperty("flanger_frequency")
    public double getFlangerFrequency() { return flangerFrequency; }
    @JsonProperty("flanger_frequency")
    public void setFlangerFrequency(double value) { this.flangerFrequency = value; }

    @JsonProperty("flanger_mod_depth")
    public double getFlangerModDepth() { return flangerModDepth; }
    @JsonProperty("flanger_mod_depth")
    public void setFlangerModDepth(double value) { this.flangerModDepth = value; }

    @JsonProperty("flanger_on")
    public double getFlangerOn() { return flangerOn; }
    @JsonProperty("flanger_on")
    public void setFlangerOn(double value) { this.flangerOn = value; }

    @JsonProperty("flanger_phase_offset")
    public double getFlangerPhaseOffset() { return flangerPhaseOffset; }
    @JsonProperty("flanger_phase_offset")
    public void setFlangerPhaseOffset(double value) { this.flangerPhaseOffset = value; }

    @JsonProperty("flanger_sync")
    public double getFlangerSync() { return flangerSync; }
    @JsonProperty("flanger_sync")
    public void setFlangerSync(double value) { this.flangerSync = value; }

    @JsonProperty("flanger_tempo")
    public double getFlangerTempo() { return flangerTempo; }
    @JsonProperty("flanger_tempo")
    public void setFlangerTempo(double value) { this.flangerTempo = value; }

    @JsonProperty("legato")
    public double getLegato() { return legato; }
    @JsonProperty("legato")
    public void setLegato(double value) { this.legato = value; }

    @JsonProperty("lfo_1_delay_time")
    public double getLfo1DelayTime() { return lfo1_DelayTime; }
    @JsonProperty("lfo_1_delay_time")
    public void setLfo1DelayTime(double value) { this.lfo1_DelayTime = value; }

    @JsonProperty("lfo_1_fade_time")
    public double getLfo1FadeTime() { return lfo1_FadeTime; }
    @JsonProperty("lfo_1_fade_time")
    public void setLfo1FadeTime(double value) { this.lfo1_FadeTime = value; }

    @JsonProperty("lfo_1_frequency")
    public double getLfo1Frequency() { return lfo1_Frequency; }
    @JsonProperty("lfo_1_frequency")
    public void setLfo1Frequency(double value) { this.lfo1_Frequency = value; }

    @JsonProperty("lfo_1_keytrack_transpose")
    public Double getLfo1KeytrackTranspose() { return lfo1_KeytrackTranspose; }
    @JsonProperty("lfo_1_keytrack_transpose")
    public void setLfo1KeytrackTranspose(Double value) { this.lfo1_KeytrackTranspose = value; }

    @JsonProperty("lfo_1_keytrack_tune")
    public Double getLfo1KeytrackTune() { return lfo1_KeytrackTune; }
    @JsonProperty("lfo_1_keytrack_tune")
    public void setLfo1KeytrackTune(Double value) { this.lfo1_KeytrackTune = value; }

    @JsonProperty("lfo_1_phase")
    public double getLfo1Phase() { return lfo1_Phase; }
    @JsonProperty("lfo_1_phase")
    public void setLfo1Phase(double value) { this.lfo1_Phase = value; }

    @JsonProperty("lfo_1_smooth_mode")
    public Double getLfo1SmoothMode() { return lfo1_SmoothMode; }
    @JsonProperty("lfo_1_smooth_mode")
    public void setLfo1SmoothMode(Double value) { this.lfo1_SmoothMode = value; }

    @JsonProperty("lfo_1_smooth_time")
    public Double getLfo1SmoothTime() { return lfo1_SmoothTime; }
    @JsonProperty("lfo_1_smooth_time")
    public void setLfo1SmoothTime(Double value) { this.lfo1_SmoothTime = value; }

    @JsonProperty("lfo_1_stereo")
    public double getLfo1Stereo() { return lfo1_Stereo; }
    @JsonProperty("lfo_1_stereo")
    public void setLfo1Stereo(double value) { this.lfo1_Stereo = value; }

    @JsonProperty("lfo_1_sync")
    public double getLfo1Sync() { return lfo1_Sync; }
    @JsonProperty("lfo_1_sync")
    public void setLfo1Sync(double value) { this.lfo1_Sync = value; }

    @JsonProperty("lfo_1_sync_type")
    public double getLfo1SyncType() { return lfo1_SyncType; }
    @JsonProperty("lfo_1_sync_type")
    public void setLfo1SyncType(double value) { this.lfo1_SyncType = value; }

    @JsonProperty("lfo_1_tempo")
    public double getLfo1Tempo() { return lfo1_Tempo; }
    @JsonProperty("lfo_1_tempo")
    public void setLfo1Tempo(double value) { this.lfo1_Tempo = value; }

    @JsonProperty("lfo_2_delay_time")
    public double getLfo2DelayTime() { return lfo2_DelayTime; }
    @JsonProperty("lfo_2_delay_time")
    public void setLfo2DelayTime(double value) { this.lfo2_DelayTime = value; }

    @JsonProperty("lfo_2_fade_time")
    public double getLfo2FadeTime() { return lfo2_FadeTime; }
    @JsonProperty("lfo_2_fade_time")
    public void setLfo2FadeTime(double value) { this.lfo2_FadeTime = value; }

    @JsonProperty("lfo_2_frequency")
    public double getLfo2Frequency() { return lfo2_Frequency; }
    @JsonProperty("lfo_2_frequency")
    public void setLfo2Frequency(double value) { this.lfo2_Frequency = value; }

    @JsonProperty("lfo_2_keytrack_transpose")
    public Double getLfo2KeytrackTranspose() { return lfo2_KeytrackTranspose; }
    @JsonProperty("lfo_2_keytrack_transpose")
    public void setLfo2KeytrackTranspose(Double value) { this.lfo2_KeytrackTranspose = value; }

    @JsonProperty("lfo_2_keytrack_tune")
    public Double getLfo2KeytrackTune() { return lfo2_KeytrackTune; }
    @JsonProperty("lfo_2_keytrack_tune")
    public void setLfo2KeytrackTune(Double value) { this.lfo2_KeytrackTune = value; }

    @JsonProperty("lfo_2_phase")
    public double getLfo2Phase() { return lfo2_Phase; }
    @JsonProperty("lfo_2_phase")
    public void setLfo2Phase(double value) { this.lfo2_Phase = value; }

    @JsonProperty("lfo_2_smooth_mode")
    public Double getLfo2SmoothMode() { return lfo2_SmoothMode; }
    @JsonProperty("lfo_2_smooth_mode")
    public void setLfo2SmoothMode(Double value) { this.lfo2_SmoothMode = value; }

    @JsonProperty("lfo_2_smooth_time")
    public Double getLfo2SmoothTime() { return lfo2_SmoothTime; }
    @JsonProperty("lfo_2_smooth_time")
    public void setLfo2SmoothTime(Double value) { this.lfo2_SmoothTime = value; }

    @JsonProperty("lfo_2_stereo")
    public double getLfo2Stereo() { return lfo2_Stereo; }
    @JsonProperty("lfo_2_stereo")
    public void setLfo2Stereo(double value) { this.lfo2_Stereo = value; }

    @JsonProperty("lfo_2_sync")
    public double getLfo2Sync() { return lfo2_Sync; }
    @JsonProperty("lfo_2_sync")
    public void setLfo2Sync(double value) { this.lfo2_Sync = value; }

    @JsonProperty("lfo_2_sync_type")
    public double getLfo2SyncType() { return lfo2_SyncType; }
    @JsonProperty("lfo_2_sync_type")
    public void setLfo2SyncType(double value) { this.lfo2_SyncType = value; }

    @JsonProperty("lfo_2_tempo")
    public double getLfo2Tempo() { return lfo2_Tempo; }
    @JsonProperty("lfo_2_tempo")
    public void setLfo2Tempo(double value) { this.lfo2_Tempo = value; }

    @JsonProperty("lfo_3_delay_time")
    public double getLfo3DelayTime() { return lfo3_DelayTime; }
    @JsonProperty("lfo_3_delay_time")
    public void setLfo3DelayTime(double value) { this.lfo3_DelayTime = value; }

    @JsonProperty("lfo_3_fade_time")
    public double getLfo3FadeTime() { return lfo3_FadeTime; }
    @JsonProperty("lfo_3_fade_time")
    public void setLfo3FadeTime(double value) { this.lfo3_FadeTime = value; }

    @JsonProperty("lfo_3_frequency")
    public double getLfo3Frequency() { return lfo3_Frequency; }
    @JsonProperty("lfo_3_frequency")
    public void setLfo3Frequency(double value) { this.lfo3_Frequency = value; }

    @JsonProperty("lfo_3_keytrack_transpose")
    public Double getLfo3KeytrackTranspose() { return lfo3_KeytrackTranspose; }
    @JsonProperty("lfo_3_keytrack_transpose")
    public void setLfo3KeytrackTranspose(Double value) { this.lfo3_KeytrackTranspose = value; }

    @JsonProperty("lfo_3_keytrack_tune")
    public Double getLfo3KeytrackTune() { return lfo3_KeytrackTune; }
    @JsonProperty("lfo_3_keytrack_tune")
    public void setLfo3KeytrackTune(Double value) { this.lfo3_KeytrackTune = value; }

    @JsonProperty("lfo_3_phase")
    public double getLfo3Phase() { return lfo3_Phase; }
    @JsonProperty("lfo_3_phase")
    public void setLfo3Phase(double value) { this.lfo3_Phase = value; }

    @JsonProperty("lfo_3_smooth_mode")
    public Double getLfo3SmoothMode() { return lfo3_SmoothMode; }
    @JsonProperty("lfo_3_smooth_mode")
    public void setLfo3SmoothMode(Double value) { this.lfo3_SmoothMode = value; }

    @JsonProperty("lfo_3_smooth_time")
    public Double getLfo3SmoothTime() { return lfo3_SmoothTime; }
    @JsonProperty("lfo_3_smooth_time")
    public void setLfo3SmoothTime(Double value) { this.lfo3_SmoothTime = value; }

    @JsonProperty("lfo_3_stereo")
    public double getLfo3Stereo() { return lfo3_Stereo; }
    @JsonProperty("lfo_3_stereo")
    public void setLfo3Stereo(double value) { this.lfo3_Stereo = value; }

    @JsonProperty("lfo_3_sync")
    public double getLfo3Sync() { return lfo3_Sync; }
    @JsonProperty("lfo_3_sync")
    public void setLfo3Sync(double value) { this.lfo3_Sync = value; }

    @JsonProperty("lfo_3_sync_type")
    public double getLfo3SyncType() { return lfo3_SyncType; }
    @JsonProperty("lfo_3_sync_type")
    public void setLfo3SyncType(double value) { this.lfo3_SyncType = value; }

    @JsonProperty("lfo_3_tempo")
    public double getLfo3Tempo() { return lfo3_Tempo; }
    @JsonProperty("lfo_3_tempo")
    public void setLfo3Tempo(double value) { this.lfo3_Tempo = value; }

    @JsonProperty("lfo_4_delay_time")
    public double getLfo4DelayTime() { return lfo4_DelayTime; }
    @JsonProperty("lfo_4_delay_time")
    public void setLfo4DelayTime(double value) { this.lfo4_DelayTime = value; }

    @JsonProperty("lfo_4_fade_time")
    public double getLfo4FadeTime() { return lfo4_FadeTime; }
    @JsonProperty("lfo_4_fade_time")
    public void setLfo4FadeTime(double value) { this.lfo4_FadeTime = value; }

    @JsonProperty("lfo_4_frequency")
    public double getLfo4Frequency() { return lfo4_Frequency; }
    @JsonProperty("lfo_4_frequency")
    public void setLfo4Frequency(double value) { this.lfo4_Frequency = value; }

    @JsonProperty("lfo_4_keytrack_transpose")
    public Double getLfo4KeytrackTranspose() { return lfo4_KeytrackTranspose; }
    @JsonProperty("lfo_4_keytrack_transpose")
    public void setLfo4KeytrackTranspose(Double value) { this.lfo4_KeytrackTranspose = value; }

    @JsonProperty("lfo_4_keytrack_tune")
    public Double getLfo4KeytrackTune() { return lfo4_KeytrackTune; }
    @JsonProperty("lfo_4_keytrack_tune")
    public void setLfo4KeytrackTune(Double value) { this.lfo4_KeytrackTune = value; }

    @JsonProperty("lfo_4_phase")
    public double getLfo4Phase() { return lfo4_Phase; }
    @JsonProperty("lfo_4_phase")
    public void setLfo4Phase(double value) { this.lfo4_Phase = value; }

    @JsonProperty("lfo_4_smooth_mode")
    public Double getLfo4SmoothMode() { return lfo4_SmoothMode; }
    @JsonProperty("lfo_4_smooth_mode")
    public void setLfo4SmoothMode(Double value) { this.lfo4_SmoothMode = value; }

    @JsonProperty("lfo_4_smooth_time")
    public Double getLfo4SmoothTime() { return lfo4_SmoothTime; }
    @JsonProperty("lfo_4_smooth_time")
    public void setLfo4SmoothTime(Double value) { this.lfo4_SmoothTime = value; }

    @JsonProperty("lfo_4_stereo")
    public double getLfo4Stereo() { return lfo4_Stereo; }
    @JsonProperty("lfo_4_stereo")
    public void setLfo4Stereo(double value) { this.lfo4_Stereo = value; }

    @JsonProperty("lfo_4_sync")
    public double getLfo4Sync() { return lfo4_Sync; }
    @JsonProperty("lfo_4_sync")
    public void setLfo4Sync(double value) { this.lfo4_Sync = value; }

    @JsonProperty("lfo_4_sync_type")
    public double getLfo4SyncType() { return lfo4_SyncType; }
    @JsonProperty("lfo_4_sync_type")
    public void setLfo4SyncType(double value) { this.lfo4_SyncType = value; }

    @JsonProperty("lfo_4_tempo")
    public double getLfo4Tempo() { return lfo4_Tempo; }
    @JsonProperty("lfo_4_tempo")
    public void setLfo4Tempo(double value) { this.lfo4_Tempo = value; }

    @JsonProperty("lfo_5_delay_time")
    public double getLfo5DelayTime() { return lfo5_DelayTime; }
    @JsonProperty("lfo_5_delay_time")
    public void setLfo5DelayTime(double value) { this.lfo5_DelayTime = value; }

    @JsonProperty("lfo_5_fade_time")
    public double getLfo5FadeTime() { return lfo5_FadeTime; }
    @JsonProperty("lfo_5_fade_time")
    public void setLfo5FadeTime(double value) { this.lfo5_FadeTime = value; }

    @JsonProperty("lfo_5_frequency")
    public double getLfo5Frequency() { return lfo5_Frequency; }
    @JsonProperty("lfo_5_frequency")
    public void setLfo5Frequency(double value) { this.lfo5_Frequency = value; }

    @JsonProperty("lfo_5_keytrack_transpose")
    public Double getLfo5KeytrackTranspose() { return lfo5_KeytrackTranspose; }
    @JsonProperty("lfo_5_keytrack_transpose")
    public void setLfo5KeytrackTranspose(Double value) { this.lfo5_KeytrackTranspose = value; }

    @JsonProperty("lfo_5_keytrack_tune")
    public Double getLfo5KeytrackTune() { return lfo5_KeytrackTune; }
    @JsonProperty("lfo_5_keytrack_tune")
    public void setLfo5KeytrackTune(Double value) { this.lfo5_KeytrackTune = value; }

    @JsonProperty("lfo_5_phase")
    public double getLfo5Phase() { return lfo5_Phase; }
    @JsonProperty("lfo_5_phase")
    public void setLfo5Phase(double value) { this.lfo5_Phase = value; }

    @JsonProperty("lfo_5_smooth_mode")
    public Double getLfo5SmoothMode() { return lfo5_SmoothMode; }
    @JsonProperty("lfo_5_smooth_mode")
    public void setLfo5SmoothMode(Double value) { this.lfo5_SmoothMode = value; }

    @JsonProperty("lfo_5_smooth_time")
    public Double getLfo5SmoothTime() { return lfo5_SmoothTime; }
    @JsonProperty("lfo_5_smooth_time")
    public void setLfo5SmoothTime(Double value) { this.lfo5_SmoothTime = value; }

    @JsonProperty("lfo_5_stereo")
    public double getLfo5Stereo() { return lfo5_Stereo; }
    @JsonProperty("lfo_5_stereo")
    public void setLfo5Stereo(double value) { this.lfo5_Stereo = value; }

    @JsonProperty("lfo_5_sync")
    public double getLfo5Sync() { return lfo5_Sync; }
    @JsonProperty("lfo_5_sync")
    public void setLfo5Sync(double value) { this.lfo5_Sync = value; }

    @JsonProperty("lfo_5_sync_type")
    public double getLfo5SyncType() { return lfo5_SyncType; }
    @JsonProperty("lfo_5_sync_type")
    public void setLfo5SyncType(double value) { this.lfo5_SyncType = value; }

    @JsonProperty("lfo_5_tempo")
    public double getLfo5Tempo() { return lfo5_Tempo; }
    @JsonProperty("lfo_5_tempo")
    public void setLfo5Tempo(double value) { this.lfo5_Tempo = value; }

    @JsonProperty("lfo_6_delay_time")
    public double getLfo6DelayTime() { return lfo6_DelayTime; }
    @JsonProperty("lfo_6_delay_time")
    public void setLfo6DelayTime(double value) { this.lfo6_DelayTime = value; }

    @JsonProperty("lfo_6_fade_time")
    public double getLfo6FadeTime() { return lfo6_FadeTime; }
    @JsonProperty("lfo_6_fade_time")
    public void setLfo6FadeTime(double value) { this.lfo6_FadeTime = value; }

    @JsonProperty("lfo_6_frequency")
    public double getLfo6Frequency() { return lfo6_Frequency; }
    @JsonProperty("lfo_6_frequency")
    public void setLfo6Frequency(double value) { this.lfo6_Frequency = value; }

    @JsonProperty("lfo_6_keytrack_transpose")
    public Double getLfo6KeytrackTranspose() { return lfo6_KeytrackTranspose; }
    @JsonProperty("lfo_6_keytrack_transpose")
    public void setLfo6KeytrackTranspose(Double value) { this.lfo6_KeytrackTranspose = value; }

    @JsonProperty("lfo_6_keytrack_tune")
    public Double getLfo6KeytrackTune() { return lfo6_KeytrackTune; }
    @JsonProperty("lfo_6_keytrack_tune")
    public void setLfo6KeytrackTune(Double value) { this.lfo6_KeytrackTune = value; }

    @JsonProperty("lfo_6_phase")
    public double getLfo6Phase() { return lfo6_Phase; }
    @JsonProperty("lfo_6_phase")
    public void setLfo6Phase(double value) { this.lfo6_Phase = value; }

    @JsonProperty("lfo_6_smooth_mode")
    public Double getLfo6SmoothMode() { return lfo6_SmoothMode; }
    @JsonProperty("lfo_6_smooth_mode")
    public void setLfo6SmoothMode(Double value) { this.lfo6_SmoothMode = value; }

    @JsonProperty("lfo_6_smooth_time")
    public Double getLfo6SmoothTime() { return lfo6_SmoothTime; }
    @JsonProperty("lfo_6_smooth_time")
    public void setLfo6SmoothTime(Double value) { this.lfo6_SmoothTime = value; }

    @JsonProperty("lfo_6_stereo")
    public double getLfo6Stereo() { return lfo6_Stereo; }
    @JsonProperty("lfo_6_stereo")
    public void setLfo6Stereo(double value) { this.lfo6_Stereo = value; }

    @JsonProperty("lfo_6_sync")
    public double getLfo6Sync() { return lfo6_Sync; }
    @JsonProperty("lfo_6_sync")
    public void setLfo6Sync(double value) { this.lfo6_Sync = value; }

    @JsonProperty("lfo_6_sync_type")
    public double getLfo6SyncType() { return lfo6_SyncType; }
    @JsonProperty("lfo_6_sync_type")
    public void setLfo6SyncType(double value) { this.lfo6_SyncType = value; }

    @JsonProperty("lfo_6_tempo")
    public double getLfo6Tempo() { return lfo6_Tempo; }
    @JsonProperty("lfo_6_tempo")
    public void setLfo6Tempo(double value) { this.lfo6_Tempo = value; }

    @JsonProperty("lfo_7_delay_time")
    public double getLfo7DelayTime() { return lfo7_DelayTime; }
    @JsonProperty("lfo_7_delay_time")
    public void setLfo7DelayTime(double value) { this.lfo7_DelayTime = value; }

    @JsonProperty("lfo_7_fade_time")
    public double getLfo7FadeTime() { return lfo7_FadeTime; }
    @JsonProperty("lfo_7_fade_time")
    public void setLfo7FadeTime(double value) { this.lfo7_FadeTime = value; }

    @JsonProperty("lfo_7_frequency")
    public double getLfo7Frequency() { return lfo7_Frequency; }
    @JsonProperty("lfo_7_frequency")
    public void setLfo7Frequency(double value) { this.lfo7_Frequency = value; }

    @JsonProperty("lfo_7_keytrack_transpose")
    public Double getLfo7KeytrackTranspose() { return lfo7_KeytrackTranspose; }
    @JsonProperty("lfo_7_keytrack_transpose")
    public void setLfo7KeytrackTranspose(Double value) { this.lfo7_KeytrackTranspose = value; }

    @JsonProperty("lfo_7_keytrack_tune")
    public Double getLfo7KeytrackTune() { return lfo7_KeytrackTune; }
    @JsonProperty("lfo_7_keytrack_tune")
    public void setLfo7KeytrackTune(Double value) { this.lfo7_KeytrackTune = value; }

    @JsonProperty("lfo_7_phase")
    public double getLfo7Phase() { return lfo7_Phase; }
    @JsonProperty("lfo_7_phase")
    public void setLfo7Phase(double value) { this.lfo7_Phase = value; }

    @JsonProperty("lfo_7_smooth_mode")
    public Double getLfo7SmoothMode() { return lfo7_SmoothMode; }
    @JsonProperty("lfo_7_smooth_mode")
    public void setLfo7SmoothMode(Double value) { this.lfo7_SmoothMode = value; }

    @JsonProperty("lfo_7_smooth_time")
    public Double getLfo7SmoothTime() { return lfo7_SmoothTime; }
    @JsonProperty("lfo_7_smooth_time")
    public void setLfo7SmoothTime(Double value) { this.lfo7_SmoothTime = value; }

    @JsonProperty("lfo_7_stereo")
    public double getLfo7Stereo() { return lfo7_Stereo; }
    @JsonProperty("lfo_7_stereo")
    public void setLfo7Stereo(double value) { this.lfo7_Stereo = value; }

    @JsonProperty("lfo_7_sync")
    public double getLfo7Sync() { return lfo7_Sync; }
    @JsonProperty("lfo_7_sync")
    public void setLfo7Sync(double value) { this.lfo7_Sync = value; }

    @JsonProperty("lfo_7_sync_type")
    public double getLfo7SyncType() { return lfo7_SyncType; }
    @JsonProperty("lfo_7_sync_type")
    public void setLfo7SyncType(double value) { this.lfo7_SyncType = value; }

    @JsonProperty("lfo_7_tempo")
    public double getLfo7Tempo() { return lfo7_Tempo; }
    @JsonProperty("lfo_7_tempo")
    public void setLfo7Tempo(double value) { this.lfo7_Tempo = value; }

    @JsonProperty("lfo_8_delay_time")
    public double getLfo8DelayTime() { return lfo8_DelayTime; }
    @JsonProperty("lfo_8_delay_time")
    public void setLfo8DelayTime(double value) { this.lfo8_DelayTime = value; }

    @JsonProperty("lfo_8_fade_time")
    public double getLfo8FadeTime() { return lfo8_FadeTime; }
    @JsonProperty("lfo_8_fade_time")
    public void setLfo8FadeTime(double value) { this.lfo8_FadeTime = value; }

    @JsonProperty("lfo_8_frequency")
    public double getLfo8Frequency() { return lfo8_Frequency; }
    @JsonProperty("lfo_8_frequency")
    public void setLfo8Frequency(double value) { this.lfo8_Frequency = value; }

    @JsonProperty("lfo_8_keytrack_transpose")
    public Double getLfo8KeytrackTranspose() { return lfo8_KeytrackTranspose; }
    @JsonProperty("lfo_8_keytrack_transpose")
    public void setLfo8KeytrackTranspose(Double value) { this.lfo8_KeytrackTranspose = value; }

    @JsonProperty("lfo_8_keytrack_tune")
    public Double getLfo8KeytrackTune() { return lfo8_KeytrackTune; }
    @JsonProperty("lfo_8_keytrack_tune")
    public void setLfo8KeytrackTune(Double value) { this.lfo8_KeytrackTune = value; }

    @JsonProperty("lfo_8_phase")
    public double getLfo8Phase() { return lfo8_Phase; }
    @JsonProperty("lfo_8_phase")
    public void setLfo8Phase(double value) { this.lfo8_Phase = value; }

    @JsonProperty("lfo_8_smooth_mode")
    public Double getLfo8SmoothMode() { return lfo8_SmoothMode; }
    @JsonProperty("lfo_8_smooth_mode")
    public void setLfo8SmoothMode(Double value) { this.lfo8_SmoothMode = value; }

    @JsonProperty("lfo_8_smooth_time")
    public Double getLfo8SmoothTime() { return lfo8_SmoothTime; }
    @JsonProperty("lfo_8_smooth_time")
    public void setLfo8SmoothTime(Double value) { this.lfo8_SmoothTime = value; }

    @JsonProperty("lfo_8_stereo")
    public double getLfo8Stereo() { return lfo8_Stereo; }
    @JsonProperty("lfo_8_stereo")
    public void setLfo8Stereo(double value) { this.lfo8_Stereo = value; }

    @JsonProperty("lfo_8_sync")
    public double getLfo8Sync() { return lfo8_Sync; }
    @JsonProperty("lfo_8_sync")
    public void setLfo8Sync(double value) { this.lfo8_Sync = value; }

    @JsonProperty("lfo_8_sync_type")
    public double getLfo8SyncType() { return lfo8_SyncType; }
    @JsonProperty("lfo_8_sync_type")
    public void setLfo8SyncType(double value) { this.lfo8_SyncType = value; }

    @JsonProperty("lfo_8_tempo")
    public double getLfo8Tempo() { return lfo8_Tempo; }
    @JsonProperty("lfo_8_tempo")
    public void setLfo8Tempo(double value) { this.lfo8_Tempo = value; }

    @JsonProperty("lfos")
    public Lfo[] getLfos() { return lfos; }
    @JsonProperty("lfos")
    public void setLfos(Lfo[] value) { this.lfos = value; }

    @JsonProperty("macro_control_1")
    public double getMacroControl1() { return macroControl1; }
    @JsonProperty("macro_control_1")
    public void setMacroControl1(double value) { this.macroControl1 = value; }

    @JsonProperty("macro_control_2")
    public double getMacroControl2() { return macroControl2; }
    @JsonProperty("macro_control_2")
    public void setMacroControl2(double value) { this.macroControl2 = value; }

    @JsonProperty("macro_control_3")
    public double getMacroControl3() { return macroControl3; }
    @JsonProperty("macro_control_3")
    public void setMacroControl3(double value) { this.macroControl3 = value; }

    @JsonProperty("macro_control_4")
    public double getMacroControl4() { return macroControl4; }
    @JsonProperty("macro_control_4")
    public void setMacroControl4(double value) { this.macroControl4 = value; }

    @JsonProperty("mod_wheel")
    public double getModWheel() { return modWheel; }
    @JsonProperty("mod_wheel")
    public void setModWheel(double value) { this.modWheel = value; }

    @JsonProperty("modulation_10_amount")
    public double getModulation10Amount() { return modulation10_Amount; }
    @JsonProperty("modulation_10_amount")
    public void setModulation10Amount(double value) { this.modulation10_Amount = value; }

    @JsonProperty("modulation_10_bipolar")
    public double getModulation10Bipolar() { return modulation10_Bipolar; }
    @JsonProperty("modulation_10_bipolar")
    public void setModulation10Bipolar(double value) { this.modulation10_Bipolar = value; }

    @JsonProperty("modulation_10_bypass")
    public double getModulation10Bypass() { return modulation10_Bypass; }
    @JsonProperty("modulation_10_bypass")
    public void setModulation10Bypass(double value) { this.modulation10_Bypass = value; }

    @JsonProperty("modulation_10_power")
    public double getModulation10Power() { return modulation10_Power; }
    @JsonProperty("modulation_10_power")
    public void setModulation10Power(double value) { this.modulation10_Power = value; }

    @JsonProperty("modulation_10_stereo")
    public double getModulation10Stereo() { return modulation10_Stereo; }
    @JsonProperty("modulation_10_stereo")
    public void setModulation10Stereo(double value) { this.modulation10_Stereo = value; }

    @JsonProperty("modulation_11_amount")
    public double getModulation11Amount() { return modulation11_Amount; }
    @JsonProperty("modulation_11_amount")
    public void setModulation11Amount(double value) { this.modulation11_Amount = value; }

    @JsonProperty("modulation_11_bipolar")
    public double getModulation11Bipolar() { return modulation11_Bipolar; }
    @JsonProperty("modulation_11_bipolar")
    public void setModulation11Bipolar(double value) { this.modulation11_Bipolar = value; }

    @JsonProperty("modulation_11_bypass")
    public double getModulation11Bypass() { return modulation11_Bypass; }
    @JsonProperty("modulation_11_bypass")
    public void setModulation11Bypass(double value) { this.modulation11_Bypass = value; }

    @JsonProperty("modulation_11_power")
    public double getModulation11Power() { return modulation11_Power; }
    @JsonProperty("modulation_11_power")
    public void setModulation11Power(double value) { this.modulation11_Power = value; }

    @JsonProperty("modulation_11_stereo")
    public double getModulation11Stereo() { return modulation11_Stereo; }
    @JsonProperty("modulation_11_stereo")
    public void setModulation11Stereo(double value) { this.modulation11_Stereo = value; }

    @JsonProperty("modulation_12_amount")
    public double getModulation12Amount() { return modulation12_Amount; }
    @JsonProperty("modulation_12_amount")
    public void setModulation12Amount(double value) { this.modulation12_Amount = value; }

    @JsonProperty("modulation_12_bipolar")
    public double getModulation12Bipolar() { return modulation12_Bipolar; }
    @JsonProperty("modulation_12_bipolar")
    public void setModulation12Bipolar(double value) { this.modulation12_Bipolar = value; }

    @JsonProperty("modulation_12_bypass")
    public double getModulation12Bypass() { return modulation12_Bypass; }
    @JsonProperty("modulation_12_bypass")
    public void setModulation12Bypass(double value) { this.modulation12_Bypass = value; }

    @JsonProperty("modulation_12_power")
    public double getModulation12Power() { return modulation12_Power; }
    @JsonProperty("modulation_12_power")
    public void setModulation12Power(double value) { this.modulation12_Power = value; }

    @JsonProperty("modulation_12_stereo")
    public double getModulation12Stereo() { return modulation12_Stereo; }
    @JsonProperty("modulation_12_stereo")
    public void setModulation12Stereo(double value) { this.modulation12_Stereo = value; }

    @JsonProperty("modulation_13_amount")
    public double getModulation13Amount() { return modulation13_Amount; }
    @JsonProperty("modulation_13_amount")
    public void setModulation13Amount(double value) { this.modulation13_Amount = value; }

    @JsonProperty("modulation_13_bipolar")
    public double getModulation13Bipolar() { return modulation13_Bipolar; }
    @JsonProperty("modulation_13_bipolar")
    public void setModulation13Bipolar(double value) { this.modulation13_Bipolar = value; }

    @JsonProperty("modulation_13_bypass")
    public double getModulation13Bypass() { return modulation13_Bypass; }
    @JsonProperty("modulation_13_bypass")
    public void setModulation13Bypass(double value) { this.modulation13_Bypass = value; }

    @JsonProperty("modulation_13_power")
    public double getModulation13Power() { return modulation13_Power; }
    @JsonProperty("modulation_13_power")
    public void setModulation13Power(double value) { this.modulation13_Power = value; }

    @JsonProperty("modulation_13_stereo")
    public double getModulation13Stereo() { return modulation13_Stereo; }
    @JsonProperty("modulation_13_stereo")
    public void setModulation13Stereo(double value) { this.modulation13_Stereo = value; }

    @JsonProperty("modulation_14_amount")
    public double getModulation14Amount() { return modulation14_Amount; }
    @JsonProperty("modulation_14_amount")
    public void setModulation14Amount(double value) { this.modulation14_Amount = value; }

    @JsonProperty("modulation_14_bipolar")
    public double getModulation14Bipolar() { return modulation14_Bipolar; }
    @JsonProperty("modulation_14_bipolar")
    public void setModulation14Bipolar(double value) { this.modulation14_Bipolar = value; }

    @JsonProperty("modulation_14_bypass")
    public double getModulation14Bypass() { return modulation14_Bypass; }
    @JsonProperty("modulation_14_bypass")
    public void setModulation14Bypass(double value) { this.modulation14_Bypass = value; }

    @JsonProperty("modulation_14_power")
    public double getModulation14Power() { return modulation14_Power; }
    @JsonProperty("modulation_14_power")
    public void setModulation14Power(double value) { this.modulation14_Power = value; }

    @JsonProperty("modulation_14_stereo")
    public double getModulation14Stereo() { return modulation14_Stereo; }
    @JsonProperty("modulation_14_stereo")
    public void setModulation14Stereo(double value) { this.modulation14_Stereo = value; }

    @JsonProperty("modulation_15_amount")
    public double getModulation15Amount() { return modulation15_Amount; }
    @JsonProperty("modulation_15_amount")
    public void setModulation15Amount(double value) { this.modulation15_Amount = value; }

    @JsonProperty("modulation_15_bipolar")
    public double getModulation15Bipolar() { return modulation15_Bipolar; }
    @JsonProperty("modulation_15_bipolar")
    public void setModulation15Bipolar(double value) { this.modulation15_Bipolar = value; }

    @JsonProperty("modulation_15_bypass")
    public double getModulation15Bypass() { return modulation15_Bypass; }
    @JsonProperty("modulation_15_bypass")
    public void setModulation15Bypass(double value) { this.modulation15_Bypass = value; }

    @JsonProperty("modulation_15_power")
    public double getModulation15Power() { return modulation15_Power; }
    @JsonProperty("modulation_15_power")
    public void setModulation15Power(double value) { this.modulation15_Power = value; }

    @JsonProperty("modulation_15_stereo")
    public double getModulation15Stereo() { return modulation15_Stereo; }
    @JsonProperty("modulation_15_stereo")
    public void setModulation15Stereo(double value) { this.modulation15_Stereo = value; }

    @JsonProperty("modulation_16_amount")
    public double getModulation16Amount() { return modulation16_Amount; }
    @JsonProperty("modulation_16_amount")
    public void setModulation16Amount(double value) { this.modulation16_Amount = value; }

    @JsonProperty("modulation_16_bipolar")
    public double getModulation16Bipolar() { return modulation16_Bipolar; }
    @JsonProperty("modulation_16_bipolar")
    public void setModulation16Bipolar(double value) { this.modulation16_Bipolar = value; }

    @JsonProperty("modulation_16_bypass")
    public double getModulation16Bypass() { return modulation16_Bypass; }
    @JsonProperty("modulation_16_bypass")
    public void setModulation16Bypass(double value) { this.modulation16_Bypass = value; }

    @JsonProperty("modulation_16_power")
    public double getModulation16Power() { return modulation16_Power; }
    @JsonProperty("modulation_16_power")
    public void setModulation16Power(double value) { this.modulation16_Power = value; }

    @JsonProperty("modulation_16_stereo")
    public double getModulation16Stereo() { return modulation16_Stereo; }
    @JsonProperty("modulation_16_stereo")
    public void setModulation16Stereo(double value) { this.modulation16_Stereo = value; }

    @JsonProperty("modulation_17_amount")
    public double getModulation17Amount() { return modulation17_Amount; }
    @JsonProperty("modulation_17_amount")
    public void setModulation17Amount(double value) { this.modulation17_Amount = value; }

    @JsonProperty("modulation_17_bipolar")
    public double getModulation17Bipolar() { return modulation17_Bipolar; }
    @JsonProperty("modulation_17_bipolar")
    public void setModulation17Bipolar(double value) { this.modulation17_Bipolar = value; }

    @JsonProperty("modulation_17_bypass")
    public double getModulation17Bypass() { return modulation17_Bypass; }
    @JsonProperty("modulation_17_bypass")
    public void setModulation17Bypass(double value) { this.modulation17_Bypass = value; }

    @JsonProperty("modulation_17_power")
    public double getModulation17Power() { return modulation17_Power; }
    @JsonProperty("modulation_17_power")
    public void setModulation17Power(double value) { this.modulation17_Power = value; }

    @JsonProperty("modulation_17_stereo")
    public double getModulation17Stereo() { return modulation17_Stereo; }
    @JsonProperty("modulation_17_stereo")
    public void setModulation17Stereo(double value) { this.modulation17_Stereo = value; }

    @JsonProperty("modulation_18_amount")
    public double getModulation18Amount() { return modulation18_Amount; }
    @JsonProperty("modulation_18_amount")
    public void setModulation18Amount(double value) { this.modulation18_Amount = value; }

    @JsonProperty("modulation_18_bipolar")
    public double getModulation18Bipolar() { return modulation18_Bipolar; }
    @JsonProperty("modulation_18_bipolar")
    public void setModulation18Bipolar(double value) { this.modulation18_Bipolar = value; }

    @JsonProperty("modulation_18_bypass")
    public double getModulation18Bypass() { return modulation18_Bypass; }
    @JsonProperty("modulation_18_bypass")
    public void setModulation18Bypass(double value) { this.modulation18_Bypass = value; }

    @JsonProperty("modulation_18_power")
    public double getModulation18Power() { return modulation18_Power; }
    @JsonProperty("modulation_18_power")
    public void setModulation18Power(double value) { this.modulation18_Power = value; }

    @JsonProperty("modulation_18_stereo")
    public double getModulation18Stereo() { return modulation18_Stereo; }
    @JsonProperty("modulation_18_stereo")
    public void setModulation18Stereo(double value) { this.modulation18_Stereo = value; }

    @JsonProperty("modulation_19_amount")
    public double getModulation19Amount() { return modulation19_Amount; }
    @JsonProperty("modulation_19_amount")
    public void setModulation19Amount(double value) { this.modulation19_Amount = value; }

    @JsonProperty("modulation_19_bipolar")
    public double getModulation19Bipolar() { return modulation19_Bipolar; }
    @JsonProperty("modulation_19_bipolar")
    public void setModulation19Bipolar(double value) { this.modulation19_Bipolar = value; }

    @JsonProperty("modulation_19_bypass")
    public double getModulation19Bypass() { return modulation19_Bypass; }
    @JsonProperty("modulation_19_bypass")
    public void setModulation19Bypass(double value) { this.modulation19_Bypass = value; }

    @JsonProperty("modulation_19_power")
    public double getModulation19Power() { return modulation19_Power; }
    @JsonProperty("modulation_19_power")
    public void setModulation19Power(double value) { this.modulation19_Power = value; }

    @JsonProperty("modulation_19_stereo")
    public double getModulation19Stereo() { return modulation19_Stereo; }
    @JsonProperty("modulation_19_stereo")
    public void setModulation19Stereo(double value) { this.modulation19_Stereo = value; }

    @JsonProperty("modulation_1_amount")
    public double getModulation1Amount() { return modulation1_Amount; }
    @JsonProperty("modulation_1_amount")
    public void setModulation1Amount(double value) { this.modulation1_Amount = value; }

    @JsonProperty("modulation_1_bipolar")
    public double getModulation1Bipolar() { return modulation1_Bipolar; }
    @JsonProperty("modulation_1_bipolar")
    public void setModulation1Bipolar(double value) { this.modulation1_Bipolar = value; }

    @JsonProperty("modulation_1_bypass")
    public double getModulation1Bypass() { return modulation1_Bypass; }
    @JsonProperty("modulation_1_bypass")
    public void setModulation1Bypass(double value) { this.modulation1_Bypass = value; }

    @JsonProperty("modulation_1_power")
    public double getModulation1Power() { return modulation1_Power; }
    @JsonProperty("modulation_1_power")
    public void setModulation1Power(double value) { this.modulation1_Power = value; }

    @JsonProperty("modulation_1_stereo")
    public double getModulation1Stereo() { return modulation1_Stereo; }
    @JsonProperty("modulation_1_stereo")
    public void setModulation1Stereo(double value) { this.modulation1_Stereo = value; }

    @JsonProperty("modulation_20_amount")
    public double getModulation20Amount() { return modulation20_Amount; }
    @JsonProperty("modulation_20_amount")
    public void setModulation20Amount(double value) { this.modulation20_Amount = value; }

    @JsonProperty("modulation_20_bipolar")
    public double getModulation20Bipolar() { return modulation20_Bipolar; }
    @JsonProperty("modulation_20_bipolar")
    public void setModulation20Bipolar(double value) { this.modulation20_Bipolar = value; }

    @JsonProperty("modulation_20_bypass")
    public double getModulation20Bypass() { return modulation20_Bypass; }
    @JsonProperty("modulation_20_bypass")
    public void setModulation20Bypass(double value) { this.modulation20_Bypass = value; }

    @JsonProperty("modulation_20_power")
    public double getModulation20Power() { return modulation20_Power; }
    @JsonProperty("modulation_20_power")
    public void setModulation20Power(double value) { this.modulation20_Power = value; }

    @JsonProperty("modulation_20_stereo")
    public double getModulation20Stereo() { return modulation20_Stereo; }
    @JsonProperty("modulation_20_stereo")
    public void setModulation20Stereo(double value) { this.modulation20_Stereo = value; }

    @JsonProperty("modulation_21_amount")
    public double getModulation21Amount() { return modulation21_Amount; }
    @JsonProperty("modulation_21_amount")
    public void setModulation21Amount(double value) { this.modulation21_Amount = value; }

    @JsonProperty("modulation_21_bipolar")
    public double getModulation21Bipolar() { return modulation21_Bipolar; }
    @JsonProperty("modulation_21_bipolar")
    public void setModulation21Bipolar(double value) { this.modulation21_Bipolar = value; }

    @JsonProperty("modulation_21_bypass")
    public double getModulation21Bypass() { return modulation21_Bypass; }
    @JsonProperty("modulation_21_bypass")
    public void setModulation21Bypass(double value) { this.modulation21_Bypass = value; }

    @JsonProperty("modulation_21_power")
    public double getModulation21Power() { return modulation21_Power; }
    @JsonProperty("modulation_21_power")
    public void setModulation21Power(double value) { this.modulation21_Power = value; }

    @JsonProperty("modulation_21_stereo")
    public double getModulation21Stereo() { return modulation21_Stereo; }
    @JsonProperty("modulation_21_stereo")
    public void setModulation21Stereo(double value) { this.modulation21_Stereo = value; }

    @JsonProperty("modulation_22_amount")
    public double getModulation22Amount() { return modulation22_Amount; }
    @JsonProperty("modulation_22_amount")
    public void setModulation22Amount(double value) { this.modulation22_Amount = value; }

    @JsonProperty("modulation_22_bipolar")
    public double getModulation22Bipolar() { return modulation22_Bipolar; }
    @JsonProperty("modulation_22_bipolar")
    public void setModulation22Bipolar(double value) { this.modulation22_Bipolar = value; }

    @JsonProperty("modulation_22_bypass")
    public double getModulation22Bypass() { return modulation22_Bypass; }
    @JsonProperty("modulation_22_bypass")
    public void setModulation22Bypass(double value) { this.modulation22_Bypass = value; }

    @JsonProperty("modulation_22_power")
    public double getModulation22Power() { return modulation22_Power; }
    @JsonProperty("modulation_22_power")
    public void setModulation22Power(double value) { this.modulation22_Power = value; }

    @JsonProperty("modulation_22_stereo")
    public double getModulation22Stereo() { return modulation22_Stereo; }
    @JsonProperty("modulation_22_stereo")
    public void setModulation22Stereo(double value) { this.modulation22_Stereo = value; }

    @JsonProperty("modulation_23_amount")
    public double getModulation23Amount() { return modulation23_Amount; }
    @JsonProperty("modulation_23_amount")
    public void setModulation23Amount(double value) { this.modulation23_Amount = value; }

    @JsonProperty("modulation_23_bipolar")
    public double getModulation23Bipolar() { return modulation23_Bipolar; }
    @JsonProperty("modulation_23_bipolar")
    public void setModulation23Bipolar(double value) { this.modulation23_Bipolar = value; }

    @JsonProperty("modulation_23_bypass")
    public double getModulation23Bypass() { return modulation23_Bypass; }
    @JsonProperty("modulation_23_bypass")
    public void setModulation23Bypass(double value) { this.modulation23_Bypass = value; }

    @JsonProperty("modulation_23_power")
    public double getModulation23Power() { return modulation23_Power; }
    @JsonProperty("modulation_23_power")
    public void setModulation23Power(double value) { this.modulation23_Power = value; }

    @JsonProperty("modulation_23_stereo")
    public double getModulation23Stereo() { return modulation23_Stereo; }
    @JsonProperty("modulation_23_stereo")
    public void setModulation23Stereo(double value) { this.modulation23_Stereo = value; }

    @JsonProperty("modulation_24_amount")
    public double getModulation24Amount() { return modulation24_Amount; }
    @JsonProperty("modulation_24_amount")
    public void setModulation24Amount(double value) { this.modulation24_Amount = value; }

    @JsonProperty("modulation_24_bipolar")
    public double getModulation24Bipolar() { return modulation24_Bipolar; }
    @JsonProperty("modulation_24_bipolar")
    public void setModulation24Bipolar(double value) { this.modulation24_Bipolar = value; }

    @JsonProperty("modulation_24_bypass")
    public double getModulation24Bypass() { return modulation24_Bypass; }
    @JsonProperty("modulation_24_bypass")
    public void setModulation24Bypass(double value) { this.modulation24_Bypass = value; }

    @JsonProperty("modulation_24_power")
    public double getModulation24Power() { return modulation24_Power; }
    @JsonProperty("modulation_24_power")
    public void setModulation24Power(double value) { this.modulation24_Power = value; }

    @JsonProperty("modulation_24_stereo")
    public double getModulation24Stereo() { return modulation24_Stereo; }
    @JsonProperty("modulation_24_stereo")
    public void setModulation24Stereo(double value) { this.modulation24_Stereo = value; }

    @JsonProperty("modulation_25_amount")
    public double getModulation25Amount() { return modulation25_Amount; }
    @JsonProperty("modulation_25_amount")
    public void setModulation25Amount(double value) { this.modulation25_Amount = value; }

    @JsonProperty("modulation_25_bipolar")
    public double getModulation25Bipolar() { return modulation25_Bipolar; }
    @JsonProperty("modulation_25_bipolar")
    public void setModulation25Bipolar(double value) { this.modulation25_Bipolar = value; }

    @JsonProperty("modulation_25_bypass")
    public double getModulation25Bypass() { return modulation25_Bypass; }
    @JsonProperty("modulation_25_bypass")
    public void setModulation25Bypass(double value) { this.modulation25_Bypass = value; }

    @JsonProperty("modulation_25_power")
    public double getModulation25Power() { return modulation25_Power; }
    @JsonProperty("modulation_25_power")
    public void setModulation25Power(double value) { this.modulation25_Power = value; }

    @JsonProperty("modulation_25_stereo")
    public double getModulation25Stereo() { return modulation25_Stereo; }
    @JsonProperty("modulation_25_stereo")
    public void setModulation25Stereo(double value) { this.modulation25_Stereo = value; }

    @JsonProperty("modulation_26_amount")
    public double getModulation26Amount() { return modulation26_Amount; }
    @JsonProperty("modulation_26_amount")
    public void setModulation26Amount(double value) { this.modulation26_Amount = value; }

    @JsonProperty("modulation_26_bipolar")
    public double getModulation26Bipolar() { return modulation26_Bipolar; }
    @JsonProperty("modulation_26_bipolar")
    public void setModulation26Bipolar(double value) { this.modulation26_Bipolar = value; }

    @JsonProperty("modulation_26_bypass")
    public double getModulation26Bypass() { return modulation26_Bypass; }
    @JsonProperty("modulation_26_bypass")
    public void setModulation26Bypass(double value) { this.modulation26_Bypass = value; }

    @JsonProperty("modulation_26_power")
    public double getModulation26Power() { return modulation26_Power; }
    @JsonProperty("modulation_26_power")
    public void setModulation26Power(double value) { this.modulation26_Power = value; }

    @JsonProperty("modulation_26_stereo")
    public double getModulation26Stereo() { return modulation26_Stereo; }
    @JsonProperty("modulation_26_stereo")
    public void setModulation26Stereo(double value) { this.modulation26_Stereo = value; }

    @JsonProperty("modulation_27_amount")
    public double getModulation27Amount() { return modulation27_Amount; }
    @JsonProperty("modulation_27_amount")
    public void setModulation27Amount(double value) { this.modulation27_Amount = value; }

    @JsonProperty("modulation_27_bipolar")
    public double getModulation27Bipolar() { return modulation27_Bipolar; }
    @JsonProperty("modulation_27_bipolar")
    public void setModulation27Bipolar(double value) { this.modulation27_Bipolar = value; }

    @JsonProperty("modulation_27_bypass")
    public double getModulation27Bypass() { return modulation27_Bypass; }
    @JsonProperty("modulation_27_bypass")
    public void setModulation27Bypass(double value) { this.modulation27_Bypass = value; }

    @JsonProperty("modulation_27_power")
    public double getModulation27Power() { return modulation27_Power; }
    @JsonProperty("modulation_27_power")
    public void setModulation27Power(double value) { this.modulation27_Power = value; }

    @JsonProperty("modulation_27_stereo")
    public double getModulation27Stereo() { return modulation27_Stereo; }
    @JsonProperty("modulation_27_stereo")
    public void setModulation27Stereo(double value) { this.modulation27_Stereo = value; }

    @JsonProperty("modulation_28_amount")
    public double getModulation28Amount() { return modulation28_Amount; }
    @JsonProperty("modulation_28_amount")
    public void setModulation28Amount(double value) { this.modulation28_Amount = value; }

    @JsonProperty("modulation_28_bipolar")
    public double getModulation28Bipolar() { return modulation28_Bipolar; }
    @JsonProperty("modulation_28_bipolar")
    public void setModulation28Bipolar(double value) { this.modulation28_Bipolar = value; }

    @JsonProperty("modulation_28_bypass")
    public double getModulation28Bypass() { return modulation28_Bypass; }
    @JsonProperty("modulation_28_bypass")
    public void setModulation28Bypass(double value) { this.modulation28_Bypass = value; }

    @JsonProperty("modulation_28_power")
    public double getModulation28Power() { return modulation28_Power; }
    @JsonProperty("modulation_28_power")
    public void setModulation28Power(double value) { this.modulation28_Power = value; }

    @JsonProperty("modulation_28_stereo")
    public double getModulation28Stereo() { return modulation28_Stereo; }
    @JsonProperty("modulation_28_stereo")
    public void setModulation28Stereo(double value) { this.modulation28_Stereo = value; }

    @JsonProperty("modulation_29_amount")
    public double getModulation29Amount() { return modulation29_Amount; }
    @JsonProperty("modulation_29_amount")
    public void setModulation29Amount(double value) { this.modulation29_Amount = value; }

    @JsonProperty("modulation_29_bipolar")
    public double getModulation29Bipolar() { return modulation29_Bipolar; }
    @JsonProperty("modulation_29_bipolar")
    public void setModulation29Bipolar(double value) { this.modulation29_Bipolar = value; }

    @JsonProperty("modulation_29_bypass")
    public double getModulation29Bypass() { return modulation29_Bypass; }
    @JsonProperty("modulation_29_bypass")
    public void setModulation29Bypass(double value) { this.modulation29_Bypass = value; }

    @JsonProperty("modulation_29_power")
    public double getModulation29Power() { return modulation29_Power; }
    @JsonProperty("modulation_29_power")
    public void setModulation29Power(double value) { this.modulation29_Power = value; }

    @JsonProperty("modulation_29_stereo")
    public double getModulation29Stereo() { return modulation29_Stereo; }
    @JsonProperty("modulation_29_stereo")
    public void setModulation29Stereo(double value) { this.modulation29_Stereo = value; }

    @JsonProperty("modulation_2_amount")
    public double getModulation2Amount() { return modulation2_Amount; }
    @JsonProperty("modulation_2_amount")
    public void setModulation2Amount(double value) { this.modulation2_Amount = value; }

    @JsonProperty("modulation_2_bipolar")
    public double getModulation2Bipolar() { return modulation2_Bipolar; }
    @JsonProperty("modulation_2_bipolar")
    public void setModulation2Bipolar(double value) { this.modulation2_Bipolar = value; }

    @JsonProperty("modulation_2_bypass")
    public double getModulation2Bypass() { return modulation2_Bypass; }
    @JsonProperty("modulation_2_bypass")
    public void setModulation2Bypass(double value) { this.modulation2_Bypass = value; }

    @JsonProperty("modulation_2_power")
    public double getModulation2Power() { return modulation2_Power; }
    @JsonProperty("modulation_2_power")
    public void setModulation2Power(double value) { this.modulation2_Power = value; }

    @JsonProperty("modulation_2_stereo")
    public double getModulation2Stereo() { return modulation2_Stereo; }
    @JsonProperty("modulation_2_stereo")
    public void setModulation2Stereo(double value) { this.modulation2_Stereo = value; }

    @JsonProperty("modulation_30_amount")
    public double getModulation30Amount() { return modulation30_Amount; }
    @JsonProperty("modulation_30_amount")
    public void setModulation30Amount(double value) { this.modulation30_Amount = value; }

    @JsonProperty("modulation_30_bipolar")
    public double getModulation30Bipolar() { return modulation30_Bipolar; }
    @JsonProperty("modulation_30_bipolar")
    public void setModulation30Bipolar(double value) { this.modulation30_Bipolar = value; }

    @JsonProperty("modulation_30_bypass")
    public double getModulation30Bypass() { return modulation30_Bypass; }
    @JsonProperty("modulation_30_bypass")
    public void setModulation30Bypass(double value) { this.modulation30_Bypass = value; }

    @JsonProperty("modulation_30_power")
    public double getModulation30Power() { return modulation30_Power; }
    @JsonProperty("modulation_30_power")
    public void setModulation30Power(double value) { this.modulation30_Power = value; }

    @JsonProperty("modulation_30_stereo")
    public double getModulation30Stereo() { return modulation30_Stereo; }
    @JsonProperty("modulation_30_stereo")
    public void setModulation30Stereo(double value) { this.modulation30_Stereo = value; }

    @JsonProperty("modulation_31_amount")
    public double getModulation31Amount() { return modulation31_Amount; }
    @JsonProperty("modulation_31_amount")
    public void setModulation31Amount(double value) { this.modulation31_Amount = value; }

    @JsonProperty("modulation_31_bipolar")
    public double getModulation31Bipolar() { return modulation31_Bipolar; }
    @JsonProperty("modulation_31_bipolar")
    public void setModulation31Bipolar(double value) { this.modulation31_Bipolar = value; }

    @JsonProperty("modulation_31_bypass")
    public double getModulation31Bypass() { return modulation31_Bypass; }
    @JsonProperty("modulation_31_bypass")
    public void setModulation31Bypass(double value) { this.modulation31_Bypass = value; }

    @JsonProperty("modulation_31_power")
    public double getModulation31Power() { return modulation31_Power; }
    @JsonProperty("modulation_31_power")
    public void setModulation31Power(double value) { this.modulation31_Power = value; }

    @JsonProperty("modulation_31_stereo")
    public double getModulation31Stereo() { return modulation31_Stereo; }
    @JsonProperty("modulation_31_stereo")
    public void setModulation31Stereo(double value) { this.modulation31_Stereo = value; }

    @JsonProperty("modulation_32_amount")
    public double getModulation32Amount() { return modulation32_Amount; }
    @JsonProperty("modulation_32_amount")
    public void setModulation32Amount(double value) { this.modulation32_Amount = value; }

    @JsonProperty("modulation_32_bipolar")
    public double getModulation32Bipolar() { return modulation32_Bipolar; }
    @JsonProperty("modulation_32_bipolar")
    public void setModulation32Bipolar(double value) { this.modulation32_Bipolar = value; }

    @JsonProperty("modulation_32_bypass")
    public double getModulation32Bypass() { return modulation32_Bypass; }
    @JsonProperty("modulation_32_bypass")
    public void setModulation32Bypass(double value) { this.modulation32_Bypass = value; }

    @JsonProperty("modulation_32_power")
    public double getModulation32Power() { return modulation32_Power; }
    @JsonProperty("modulation_32_power")
    public void setModulation32Power(double value) { this.modulation32_Power = value; }

    @JsonProperty("modulation_32_stereo")
    public double getModulation32Stereo() { return modulation32_Stereo; }
    @JsonProperty("modulation_32_stereo")
    public void setModulation32Stereo(double value) { this.modulation32_Stereo = value; }

    @JsonProperty("modulation_33_amount")
    public double getModulation33Amount() { return modulation33_Amount; }
    @JsonProperty("modulation_33_amount")
    public void setModulation33Amount(double value) { this.modulation33_Amount = value; }

    @JsonProperty("modulation_33_bipolar")
    public double getModulation33Bipolar() { return modulation33_Bipolar; }
    @JsonProperty("modulation_33_bipolar")
    public void setModulation33Bipolar(double value) { this.modulation33_Bipolar = value; }

    @JsonProperty("modulation_33_bypass")
    public double getModulation33Bypass() { return modulation33_Bypass; }
    @JsonProperty("modulation_33_bypass")
    public void setModulation33Bypass(double value) { this.modulation33_Bypass = value; }

    @JsonProperty("modulation_33_power")
    public double getModulation33Power() { return modulation33_Power; }
    @JsonProperty("modulation_33_power")
    public void setModulation33Power(double value) { this.modulation33_Power = value; }

    @JsonProperty("modulation_33_stereo")
    public double getModulation33Stereo() { return modulation33_Stereo; }
    @JsonProperty("modulation_33_stereo")
    public void setModulation33Stereo(double value) { this.modulation33_Stereo = value; }

    @JsonProperty("modulation_34_amount")
    public double getModulation34Amount() { return modulation34_Amount; }
    @JsonProperty("modulation_34_amount")
    public void setModulation34Amount(double value) { this.modulation34_Amount = value; }

    @JsonProperty("modulation_34_bipolar")
    public double getModulation34Bipolar() { return modulation34_Bipolar; }
    @JsonProperty("modulation_34_bipolar")
    public void setModulation34Bipolar(double value) { this.modulation34_Bipolar = value; }

    @JsonProperty("modulation_34_bypass")
    public double getModulation34Bypass() { return modulation34_Bypass; }
    @JsonProperty("modulation_34_bypass")
    public void setModulation34Bypass(double value) { this.modulation34_Bypass = value; }

    @JsonProperty("modulation_34_power")
    public double getModulation34Power() { return modulation34_Power; }
    @JsonProperty("modulation_34_power")
    public void setModulation34Power(double value) { this.modulation34_Power = value; }

    @JsonProperty("modulation_34_stereo")
    public double getModulation34Stereo() { return modulation34_Stereo; }
    @JsonProperty("modulation_34_stereo")
    public void setModulation34Stereo(double value) { this.modulation34_Stereo = value; }

    @JsonProperty("modulation_35_amount")
    public double getModulation35Amount() { return modulation35_Amount; }
    @JsonProperty("modulation_35_amount")
    public void setModulation35Amount(double value) { this.modulation35_Amount = value; }

    @JsonProperty("modulation_35_bipolar")
    public double getModulation35Bipolar() { return modulation35_Bipolar; }
    @JsonProperty("modulation_35_bipolar")
    public void setModulation35Bipolar(double value) { this.modulation35_Bipolar = value; }

    @JsonProperty("modulation_35_bypass")
    public double getModulation35Bypass() { return modulation35_Bypass; }
    @JsonProperty("modulation_35_bypass")
    public void setModulation35Bypass(double value) { this.modulation35_Bypass = value; }

    @JsonProperty("modulation_35_power")
    public double getModulation35Power() { return modulation35_Power; }
    @JsonProperty("modulation_35_power")
    public void setModulation35Power(double value) { this.modulation35_Power = value; }

    @JsonProperty("modulation_35_stereo")
    public double getModulation35Stereo() { return modulation35_Stereo; }
    @JsonProperty("modulation_35_stereo")
    public void setModulation35Stereo(double value) { this.modulation35_Stereo = value; }

    @JsonProperty("modulation_36_amount")
    public double getModulation36Amount() { return modulation36_Amount; }
    @JsonProperty("modulation_36_amount")
    public void setModulation36Amount(double value) { this.modulation36_Amount = value; }

    @JsonProperty("modulation_36_bipolar")
    public double getModulation36Bipolar() { return modulation36_Bipolar; }
    @JsonProperty("modulation_36_bipolar")
    public void setModulation36Bipolar(double value) { this.modulation36_Bipolar = value; }

    @JsonProperty("modulation_36_bypass")
    public double getModulation36Bypass() { return modulation36_Bypass; }
    @JsonProperty("modulation_36_bypass")
    public void setModulation36Bypass(double value) { this.modulation36_Bypass = value; }

    @JsonProperty("modulation_36_power")
    public double getModulation36Power() { return modulation36_Power; }
    @JsonProperty("modulation_36_power")
    public void setModulation36Power(double value) { this.modulation36_Power = value; }

    @JsonProperty("modulation_36_stereo")
    public double getModulation36Stereo() { return modulation36_Stereo; }
    @JsonProperty("modulation_36_stereo")
    public void setModulation36Stereo(double value) { this.modulation36_Stereo = value; }

    @JsonProperty("modulation_37_amount")
    public double getModulation37Amount() { return modulation37_Amount; }
    @JsonProperty("modulation_37_amount")
    public void setModulation37Amount(double value) { this.modulation37_Amount = value; }

    @JsonProperty("modulation_37_bipolar")
    public double getModulation37Bipolar() { return modulation37_Bipolar; }
    @JsonProperty("modulation_37_bipolar")
    public void setModulation37Bipolar(double value) { this.modulation37_Bipolar = value; }

    @JsonProperty("modulation_37_bypass")
    public double getModulation37Bypass() { return modulation37_Bypass; }
    @JsonProperty("modulation_37_bypass")
    public void setModulation37Bypass(double value) { this.modulation37_Bypass = value; }

    @JsonProperty("modulation_37_power")
    public double getModulation37Power() { return modulation37_Power; }
    @JsonProperty("modulation_37_power")
    public void setModulation37Power(double value) { this.modulation37_Power = value; }

    @JsonProperty("modulation_37_stereo")
    public double getModulation37Stereo() { return modulation37_Stereo; }
    @JsonProperty("modulation_37_stereo")
    public void setModulation37Stereo(double value) { this.modulation37_Stereo = value; }

    @JsonProperty("modulation_38_amount")
    public double getModulation38Amount() { return modulation38_Amount; }
    @JsonProperty("modulation_38_amount")
    public void setModulation38Amount(double value) { this.modulation38_Amount = value; }

    @JsonProperty("modulation_38_bipolar")
    public double getModulation38Bipolar() { return modulation38_Bipolar; }
    @JsonProperty("modulation_38_bipolar")
    public void setModulation38Bipolar(double value) { this.modulation38_Bipolar = value; }

    @JsonProperty("modulation_38_bypass")
    public double getModulation38Bypass() { return modulation38_Bypass; }
    @JsonProperty("modulation_38_bypass")
    public void setModulation38Bypass(double value) { this.modulation38_Bypass = value; }

    @JsonProperty("modulation_38_power")
    public double getModulation38Power() { return modulation38_Power; }
    @JsonProperty("modulation_38_power")
    public void setModulation38Power(double value) { this.modulation38_Power = value; }

    @JsonProperty("modulation_38_stereo")
    public double getModulation38Stereo() { return modulation38_Stereo; }
    @JsonProperty("modulation_38_stereo")
    public void setModulation38Stereo(double value) { this.modulation38_Stereo = value; }

    @JsonProperty("modulation_39_amount")
    public double getModulation39Amount() { return modulation39_Amount; }
    @JsonProperty("modulation_39_amount")
    public void setModulation39Amount(double value) { this.modulation39_Amount = value; }

    @JsonProperty("modulation_39_bipolar")
    public double getModulation39Bipolar() { return modulation39_Bipolar; }
    @JsonProperty("modulation_39_bipolar")
    public void setModulation39Bipolar(double value) { this.modulation39_Bipolar = value; }

    @JsonProperty("modulation_39_bypass")
    public double getModulation39Bypass() { return modulation39_Bypass; }
    @JsonProperty("modulation_39_bypass")
    public void setModulation39Bypass(double value) { this.modulation39_Bypass = value; }

    @JsonProperty("modulation_39_power")
    public double getModulation39Power() { return modulation39_Power; }
    @JsonProperty("modulation_39_power")
    public void setModulation39Power(double value) { this.modulation39_Power = value; }

    @JsonProperty("modulation_39_stereo")
    public double getModulation39Stereo() { return modulation39_Stereo; }
    @JsonProperty("modulation_39_stereo")
    public void setModulation39Stereo(double value) { this.modulation39_Stereo = value; }

    @JsonProperty("modulation_3_amount")
    public double getModulation3Amount() { return modulation3_Amount; }
    @JsonProperty("modulation_3_amount")
    public void setModulation3Amount(double value) { this.modulation3_Amount = value; }

    @JsonProperty("modulation_3_bipolar")
    public double getModulation3Bipolar() { return modulation3_Bipolar; }
    @JsonProperty("modulation_3_bipolar")
    public void setModulation3Bipolar(double value) { this.modulation3_Bipolar = value; }

    @JsonProperty("modulation_3_bypass")
    public double getModulation3Bypass() { return modulation3_Bypass; }
    @JsonProperty("modulation_3_bypass")
    public void setModulation3Bypass(double value) { this.modulation3_Bypass = value; }

    @JsonProperty("modulation_3_power")
    public double getModulation3Power() { return modulation3_Power; }
    @JsonProperty("modulation_3_power")
    public void setModulation3Power(double value) { this.modulation3_Power = value; }

    @JsonProperty("modulation_3_stereo")
    public double getModulation3Stereo() { return modulation3_Stereo; }
    @JsonProperty("modulation_3_stereo")
    public void setModulation3Stereo(double value) { this.modulation3_Stereo = value; }

    @JsonProperty("modulation_40_amount")
    public double getModulation40Amount() { return modulation40_Amount; }
    @JsonProperty("modulation_40_amount")
    public void setModulation40Amount(double value) { this.modulation40_Amount = value; }

    @JsonProperty("modulation_40_bipolar")
    public double getModulation40Bipolar() { return modulation40_Bipolar; }
    @JsonProperty("modulation_40_bipolar")
    public void setModulation40Bipolar(double value) { this.modulation40_Bipolar = value; }

    @JsonProperty("modulation_40_bypass")
    public double getModulation40Bypass() { return modulation40_Bypass; }
    @JsonProperty("modulation_40_bypass")
    public void setModulation40Bypass(double value) { this.modulation40_Bypass = value; }

    @JsonProperty("modulation_40_power")
    public double getModulation40Power() { return modulation40_Power; }
    @JsonProperty("modulation_40_power")
    public void setModulation40Power(double value) { this.modulation40_Power = value; }

    @JsonProperty("modulation_40_stereo")
    public double getModulation40Stereo() { return modulation40_Stereo; }
    @JsonProperty("modulation_40_stereo")
    public void setModulation40Stereo(double value) { this.modulation40_Stereo = value; }

    @JsonProperty("modulation_41_amount")
    public double getModulation41Amount() { return modulation41_Amount; }
    @JsonProperty("modulation_41_amount")
    public void setModulation41Amount(double value) { this.modulation41_Amount = value; }

    @JsonProperty("modulation_41_bipolar")
    public double getModulation41Bipolar() { return modulation41_Bipolar; }
    @JsonProperty("modulation_41_bipolar")
    public void setModulation41Bipolar(double value) { this.modulation41_Bipolar = value; }

    @JsonProperty("modulation_41_bypass")
    public double getModulation41Bypass() { return modulation41_Bypass; }
    @JsonProperty("modulation_41_bypass")
    public void setModulation41Bypass(double value) { this.modulation41_Bypass = value; }

    @JsonProperty("modulation_41_power")
    public double getModulation41Power() { return modulation41_Power; }
    @JsonProperty("modulation_41_power")
    public void setModulation41Power(double value) { this.modulation41_Power = value; }

    @JsonProperty("modulation_41_stereo")
    public double getModulation41Stereo() { return modulation41_Stereo; }
    @JsonProperty("modulation_41_stereo")
    public void setModulation41Stereo(double value) { this.modulation41_Stereo = value; }

    @JsonProperty("modulation_42_amount")
    public double getModulation42Amount() { return modulation42_Amount; }
    @JsonProperty("modulation_42_amount")
    public void setModulation42Amount(double value) { this.modulation42_Amount = value; }

    @JsonProperty("modulation_42_bipolar")
    public double getModulation42Bipolar() { return modulation42_Bipolar; }
    @JsonProperty("modulation_42_bipolar")
    public void setModulation42Bipolar(double value) { this.modulation42_Bipolar = value; }

    @JsonProperty("modulation_42_bypass")
    public double getModulation42Bypass() { return modulation42_Bypass; }
    @JsonProperty("modulation_42_bypass")
    public void setModulation42Bypass(double value) { this.modulation42_Bypass = value; }

    @JsonProperty("modulation_42_power")
    public double getModulation42Power() { return modulation42_Power; }
    @JsonProperty("modulation_42_power")
    public void setModulation42Power(double value) { this.modulation42_Power = value; }

    @JsonProperty("modulation_42_stereo")
    public double getModulation42Stereo() { return modulation42_Stereo; }
    @JsonProperty("modulation_42_stereo")
    public void setModulation42Stereo(double value) { this.modulation42_Stereo = value; }

    @JsonProperty("modulation_43_amount")
    public double getModulation43Amount() { return modulation43_Amount; }
    @JsonProperty("modulation_43_amount")
    public void setModulation43Amount(double value) { this.modulation43_Amount = value; }

    @JsonProperty("modulation_43_bipolar")
    public double getModulation43Bipolar() { return modulation43_Bipolar; }
    @JsonProperty("modulation_43_bipolar")
    public void setModulation43Bipolar(double value) { this.modulation43_Bipolar = value; }

    @JsonProperty("modulation_43_bypass")
    public double getModulation43Bypass() { return modulation43_Bypass; }
    @JsonProperty("modulation_43_bypass")
    public void setModulation43Bypass(double value) { this.modulation43_Bypass = value; }

    @JsonProperty("modulation_43_power")
    public double getModulation43Power() { return modulation43_Power; }
    @JsonProperty("modulation_43_power")
    public void setModulation43Power(double value) { this.modulation43_Power = value; }

    @JsonProperty("modulation_43_stereo")
    public double getModulation43Stereo() { return modulation43_Stereo; }
    @JsonProperty("modulation_43_stereo")
    public void setModulation43Stereo(double value) { this.modulation43_Stereo = value; }

    @JsonProperty("modulation_44_amount")
    public double getModulation44Amount() { return modulation44_Amount; }
    @JsonProperty("modulation_44_amount")
    public void setModulation44Amount(double value) { this.modulation44_Amount = value; }

    @JsonProperty("modulation_44_bipolar")
    public double getModulation44Bipolar() { return modulation44_Bipolar; }
    @JsonProperty("modulation_44_bipolar")
    public void setModulation44Bipolar(double value) { this.modulation44_Bipolar = value; }

    @JsonProperty("modulation_44_bypass")
    public double getModulation44Bypass() { return modulation44_Bypass; }
    @JsonProperty("modulation_44_bypass")
    public void setModulation44Bypass(double value) { this.modulation44_Bypass = value; }

    @JsonProperty("modulation_44_power")
    public double getModulation44Power() { return modulation44_Power; }
    @JsonProperty("modulation_44_power")
    public void setModulation44Power(double value) { this.modulation44_Power = value; }

    @JsonProperty("modulation_44_stereo")
    public double getModulation44Stereo() { return modulation44_Stereo; }
    @JsonProperty("modulation_44_stereo")
    public void setModulation44Stereo(double value) { this.modulation44_Stereo = value; }

    @JsonProperty("modulation_45_amount")
    public double getModulation45Amount() { return modulation45_Amount; }
    @JsonProperty("modulation_45_amount")
    public void setModulation45Amount(double value) { this.modulation45_Amount = value; }

    @JsonProperty("modulation_45_bipolar")
    public double getModulation45Bipolar() { return modulation45_Bipolar; }
    @JsonProperty("modulation_45_bipolar")
    public void setModulation45Bipolar(double value) { this.modulation45_Bipolar = value; }

    @JsonProperty("modulation_45_bypass")
    public double getModulation45Bypass() { return modulation45_Bypass; }
    @JsonProperty("modulation_45_bypass")
    public void setModulation45Bypass(double value) { this.modulation45_Bypass = value; }

    @JsonProperty("modulation_45_power")
    public double getModulation45Power() { return modulation45_Power; }
    @JsonProperty("modulation_45_power")
    public void setModulation45Power(double value) { this.modulation45_Power = value; }

    @JsonProperty("modulation_45_stereo")
    public double getModulation45Stereo() { return modulation45_Stereo; }
    @JsonProperty("modulation_45_stereo")
    public void setModulation45Stereo(double value) { this.modulation45_Stereo = value; }

    @JsonProperty("modulation_46_amount")
    public double getModulation46Amount() { return modulation46_Amount; }
    @JsonProperty("modulation_46_amount")
    public void setModulation46Amount(double value) { this.modulation46_Amount = value; }

    @JsonProperty("modulation_46_bipolar")
    public double getModulation46Bipolar() { return modulation46_Bipolar; }
    @JsonProperty("modulation_46_bipolar")
    public void setModulation46Bipolar(double value) { this.modulation46_Bipolar = value; }

    @JsonProperty("modulation_46_bypass")
    public double getModulation46Bypass() { return modulation46_Bypass; }
    @JsonProperty("modulation_46_bypass")
    public void setModulation46Bypass(double value) { this.modulation46_Bypass = value; }

    @JsonProperty("modulation_46_power")
    public double getModulation46Power() { return modulation46_Power; }
    @JsonProperty("modulation_46_power")
    public void setModulation46Power(double value) { this.modulation46_Power = value; }

    @JsonProperty("modulation_46_stereo")
    public double getModulation46Stereo() { return modulation46_Stereo; }
    @JsonProperty("modulation_46_stereo")
    public void setModulation46Stereo(double value) { this.modulation46_Stereo = value; }

    @JsonProperty("modulation_47_amount")
    public double getModulation47Amount() { return modulation47_Amount; }
    @JsonProperty("modulation_47_amount")
    public void setModulation47Amount(double value) { this.modulation47_Amount = value; }

    @JsonProperty("modulation_47_bipolar")
    public double getModulation47Bipolar() { return modulation47_Bipolar; }
    @JsonProperty("modulation_47_bipolar")
    public void setModulation47Bipolar(double value) { this.modulation47_Bipolar = value; }

    @JsonProperty("modulation_47_bypass")
    public double getModulation47Bypass() { return modulation47_Bypass; }
    @JsonProperty("modulation_47_bypass")
    public void setModulation47Bypass(double value) { this.modulation47_Bypass = value; }

    @JsonProperty("modulation_47_power")
    public double getModulation47Power() { return modulation47_Power; }
    @JsonProperty("modulation_47_power")
    public void setModulation47Power(double value) { this.modulation47_Power = value; }

    @JsonProperty("modulation_47_stereo")
    public double getModulation47Stereo() { return modulation47_Stereo; }
    @JsonProperty("modulation_47_stereo")
    public void setModulation47Stereo(double value) { this.modulation47_Stereo = value; }

    @JsonProperty("modulation_48_amount")
    public double getModulation48Amount() { return modulation48_Amount; }
    @JsonProperty("modulation_48_amount")
    public void setModulation48Amount(double value) { this.modulation48_Amount = value; }

    @JsonProperty("modulation_48_bipolar")
    public double getModulation48Bipolar() { return modulation48_Bipolar; }
    @JsonProperty("modulation_48_bipolar")
    public void setModulation48Bipolar(double value) { this.modulation48_Bipolar = value; }

    @JsonProperty("modulation_48_bypass")
    public double getModulation48Bypass() { return modulation48_Bypass; }
    @JsonProperty("modulation_48_bypass")
    public void setModulation48Bypass(double value) { this.modulation48_Bypass = value; }

    @JsonProperty("modulation_48_power")
    public double getModulation48Power() { return modulation48_Power; }
    @JsonProperty("modulation_48_power")
    public void setModulation48Power(double value) { this.modulation48_Power = value; }

    @JsonProperty("modulation_48_stereo")
    public double getModulation48Stereo() { return modulation48_Stereo; }
    @JsonProperty("modulation_48_stereo")
    public void setModulation48Stereo(double value) { this.modulation48_Stereo = value; }

    @JsonProperty("modulation_49_amount")
    public double getModulation49Amount() { return modulation49_Amount; }
    @JsonProperty("modulation_49_amount")
    public void setModulation49Amount(double value) { this.modulation49_Amount = value; }

    @JsonProperty("modulation_49_bipolar")
    public double getModulation49Bipolar() { return modulation49_Bipolar; }
    @JsonProperty("modulation_49_bipolar")
    public void setModulation49Bipolar(double value) { this.modulation49_Bipolar = value; }

    @JsonProperty("modulation_49_bypass")
    public double getModulation49Bypass() { return modulation49_Bypass; }
    @JsonProperty("modulation_49_bypass")
    public void setModulation49Bypass(double value) { this.modulation49_Bypass = value; }

    @JsonProperty("modulation_49_power")
    public double getModulation49Power() { return modulation49_Power; }
    @JsonProperty("modulation_49_power")
    public void setModulation49Power(double value) { this.modulation49_Power = value; }

    @JsonProperty("modulation_49_stereo")
    public double getModulation49Stereo() { return modulation49_Stereo; }
    @JsonProperty("modulation_49_stereo")
    public void setModulation49Stereo(double value) { this.modulation49_Stereo = value; }

    @JsonProperty("modulation_4_amount")
    public double getModulation4Amount() { return modulation4_Amount; }
    @JsonProperty("modulation_4_amount")
    public void setModulation4Amount(double value) { this.modulation4_Amount = value; }

    @JsonProperty("modulation_4_bipolar")
    public double getModulation4Bipolar() { return modulation4_Bipolar; }
    @JsonProperty("modulation_4_bipolar")
    public void setModulation4Bipolar(double value) { this.modulation4_Bipolar = value; }

    @JsonProperty("modulation_4_bypass")
    public double getModulation4Bypass() { return modulation4_Bypass; }
    @JsonProperty("modulation_4_bypass")
    public void setModulation4Bypass(double value) { this.modulation4_Bypass = value; }

    @JsonProperty("modulation_4_power")
    public double getModulation4Power() { return modulation4_Power; }
    @JsonProperty("modulation_4_power")
    public void setModulation4Power(double value) { this.modulation4_Power = value; }

    @JsonProperty("modulation_4_stereo")
    public double getModulation4Stereo() { return modulation4_Stereo; }
    @JsonProperty("modulation_4_stereo")
    public void setModulation4Stereo(double value) { this.modulation4_Stereo = value; }

    @JsonProperty("modulation_50_amount")
    public double getModulation50Amount() { return modulation50_Amount; }
    @JsonProperty("modulation_50_amount")
    public void setModulation50Amount(double value) { this.modulation50_Amount = value; }

    @JsonProperty("modulation_50_bipolar")
    public double getModulation50Bipolar() { return modulation50_Bipolar; }
    @JsonProperty("modulation_50_bipolar")
    public void setModulation50Bipolar(double value) { this.modulation50_Bipolar = value; }

    @JsonProperty("modulation_50_bypass")
    public double getModulation50Bypass() { return modulation50_Bypass; }
    @JsonProperty("modulation_50_bypass")
    public void setModulation50Bypass(double value) { this.modulation50_Bypass = value; }

    @JsonProperty("modulation_50_power")
    public double getModulation50Power() { return modulation50_Power; }
    @JsonProperty("modulation_50_power")
    public void setModulation50Power(double value) { this.modulation50_Power = value; }

    @JsonProperty("modulation_50_stereo")
    public double getModulation50Stereo() { return modulation50_Stereo; }
    @JsonProperty("modulation_50_stereo")
    public void setModulation50Stereo(double value) { this.modulation50_Stereo = value; }

    @JsonProperty("modulation_51_amount")
    public double getModulation51Amount() { return modulation51_Amount; }
    @JsonProperty("modulation_51_amount")
    public void setModulation51Amount(double value) { this.modulation51_Amount = value; }

    @JsonProperty("modulation_51_bipolar")
    public double getModulation51Bipolar() { return modulation51_Bipolar; }
    @JsonProperty("modulation_51_bipolar")
    public void setModulation51Bipolar(double value) { this.modulation51_Bipolar = value; }

    @JsonProperty("modulation_51_bypass")
    public double getModulation51Bypass() { return modulation51_Bypass; }
    @JsonProperty("modulation_51_bypass")
    public void setModulation51Bypass(double value) { this.modulation51_Bypass = value; }

    @JsonProperty("modulation_51_power")
    public double getModulation51Power() { return modulation51_Power; }
    @JsonProperty("modulation_51_power")
    public void setModulation51Power(double value) { this.modulation51_Power = value; }

    @JsonProperty("modulation_51_stereo")
    public double getModulation51Stereo() { return modulation51_Stereo; }
    @JsonProperty("modulation_51_stereo")
    public void setModulation51Stereo(double value) { this.modulation51_Stereo = value; }

    @JsonProperty("modulation_52_amount")
    public double getModulation52Amount() { return modulation52_Amount; }
    @JsonProperty("modulation_52_amount")
    public void setModulation52Amount(double value) { this.modulation52_Amount = value; }

    @JsonProperty("modulation_52_bipolar")
    public double getModulation52Bipolar() { return modulation52_Bipolar; }
    @JsonProperty("modulation_52_bipolar")
    public void setModulation52Bipolar(double value) { this.modulation52_Bipolar = value; }

    @JsonProperty("modulation_52_bypass")
    public double getModulation52Bypass() { return modulation52_Bypass; }
    @JsonProperty("modulation_52_bypass")
    public void setModulation52Bypass(double value) { this.modulation52_Bypass = value; }

    @JsonProperty("modulation_52_power")
    public double getModulation52Power() { return modulation52_Power; }
    @JsonProperty("modulation_52_power")
    public void setModulation52Power(double value) { this.modulation52_Power = value; }

    @JsonProperty("modulation_52_stereo")
    public double getModulation52Stereo() { return modulation52_Stereo; }
    @JsonProperty("modulation_52_stereo")
    public void setModulation52Stereo(double value) { this.modulation52_Stereo = value; }

    @JsonProperty("modulation_53_amount")
    public double getModulation53Amount() { return modulation53_Amount; }
    @JsonProperty("modulation_53_amount")
    public void setModulation53Amount(double value) { this.modulation53_Amount = value; }

    @JsonProperty("modulation_53_bipolar")
    public double getModulation53Bipolar() { return modulation53_Bipolar; }
    @JsonProperty("modulation_53_bipolar")
    public void setModulation53Bipolar(double value) { this.modulation53_Bipolar = value; }

    @JsonProperty("modulation_53_bypass")
    public double getModulation53Bypass() { return modulation53_Bypass; }
    @JsonProperty("modulation_53_bypass")
    public void setModulation53Bypass(double value) { this.modulation53_Bypass = value; }

    @JsonProperty("modulation_53_power")
    public double getModulation53Power() { return modulation53_Power; }
    @JsonProperty("modulation_53_power")
    public void setModulation53Power(double value) { this.modulation53_Power = value; }

    @JsonProperty("modulation_53_stereo")
    public double getModulation53Stereo() { return modulation53_Stereo; }
    @JsonProperty("modulation_53_stereo")
    public void setModulation53Stereo(double value) { this.modulation53_Stereo = value; }

    @JsonProperty("modulation_54_amount")
    public double getModulation54Amount() { return modulation54_Amount; }
    @JsonProperty("modulation_54_amount")
    public void setModulation54Amount(double value) { this.modulation54_Amount = value; }

    @JsonProperty("modulation_54_bipolar")
    public double getModulation54Bipolar() { return modulation54_Bipolar; }
    @JsonProperty("modulation_54_bipolar")
    public void setModulation54Bipolar(double value) { this.modulation54_Bipolar = value; }

    @JsonProperty("modulation_54_bypass")
    public double getModulation54Bypass() { return modulation54_Bypass; }
    @JsonProperty("modulation_54_bypass")
    public void setModulation54Bypass(double value) { this.modulation54_Bypass = value; }

    @JsonProperty("modulation_54_power")
    public double getModulation54Power() { return modulation54_Power; }
    @JsonProperty("modulation_54_power")
    public void setModulation54Power(double value) { this.modulation54_Power = value; }

    @JsonProperty("modulation_54_stereo")
    public double getModulation54Stereo() { return modulation54_Stereo; }
    @JsonProperty("modulation_54_stereo")
    public void setModulation54Stereo(double value) { this.modulation54_Stereo = value; }

    @JsonProperty("modulation_55_amount")
    public double getModulation55Amount() { return modulation55_Amount; }
    @JsonProperty("modulation_55_amount")
    public void setModulation55Amount(double value) { this.modulation55_Amount = value; }

    @JsonProperty("modulation_55_bipolar")
    public double getModulation55Bipolar() { return modulation55_Bipolar; }
    @JsonProperty("modulation_55_bipolar")
    public void setModulation55Bipolar(double value) { this.modulation55_Bipolar = value; }

    @JsonProperty("modulation_55_bypass")
    public double getModulation55Bypass() { return modulation55_Bypass; }
    @JsonProperty("modulation_55_bypass")
    public void setModulation55Bypass(double value) { this.modulation55_Bypass = value; }

    @JsonProperty("modulation_55_power")
    public double getModulation55Power() { return modulation55_Power; }
    @JsonProperty("modulation_55_power")
    public void setModulation55Power(double value) { this.modulation55_Power = value; }

    @JsonProperty("modulation_55_stereo")
    public double getModulation55Stereo() { return modulation55_Stereo; }
    @JsonProperty("modulation_55_stereo")
    public void setModulation55Stereo(double value) { this.modulation55_Stereo = value; }

    @JsonProperty("modulation_56_amount")
    public double getModulation56Amount() { return modulation56_Amount; }
    @JsonProperty("modulation_56_amount")
    public void setModulation56Amount(double value) { this.modulation56_Amount = value; }

    @JsonProperty("modulation_56_bipolar")
    public double getModulation56Bipolar() { return modulation56_Bipolar; }
    @JsonProperty("modulation_56_bipolar")
    public void setModulation56Bipolar(double value) { this.modulation56_Bipolar = value; }

    @JsonProperty("modulation_56_bypass")
    public double getModulation56Bypass() { return modulation56_Bypass; }
    @JsonProperty("modulation_56_bypass")
    public void setModulation56Bypass(double value) { this.modulation56_Bypass = value; }

    @JsonProperty("modulation_56_power")
    public double getModulation56Power() { return modulation56_Power; }
    @JsonProperty("modulation_56_power")
    public void setModulation56Power(double value) { this.modulation56_Power = value; }

    @JsonProperty("modulation_56_stereo")
    public double getModulation56Stereo() { return modulation56_Stereo; }
    @JsonProperty("modulation_56_stereo")
    public void setModulation56Stereo(double value) { this.modulation56_Stereo = value; }

    @JsonProperty("modulation_57_amount")
    public double getModulation57Amount() { return modulation57_Amount; }
    @JsonProperty("modulation_57_amount")
    public void setModulation57Amount(double value) { this.modulation57_Amount = value; }

    @JsonProperty("modulation_57_bipolar")
    public double getModulation57Bipolar() { return modulation57_Bipolar; }
    @JsonProperty("modulation_57_bipolar")
    public void setModulation57Bipolar(double value) { this.modulation57_Bipolar = value; }

    @JsonProperty("modulation_57_bypass")
    public double getModulation57Bypass() { return modulation57_Bypass; }
    @JsonProperty("modulation_57_bypass")
    public void setModulation57Bypass(double value) { this.modulation57_Bypass = value; }

    @JsonProperty("modulation_57_power")
    public double getModulation57Power() { return modulation57_Power; }
    @JsonProperty("modulation_57_power")
    public void setModulation57Power(double value) { this.modulation57_Power = value; }

    @JsonProperty("modulation_57_stereo")
    public double getModulation57Stereo() { return modulation57_Stereo; }
    @JsonProperty("modulation_57_stereo")
    public void setModulation57Stereo(double value) { this.modulation57_Stereo = value; }

    @JsonProperty("modulation_58_amount")
    public double getModulation58Amount() { return modulation58_Amount; }
    @JsonProperty("modulation_58_amount")
    public void setModulation58Amount(double value) { this.modulation58_Amount = value; }

    @JsonProperty("modulation_58_bipolar")
    public double getModulation58Bipolar() { return modulation58_Bipolar; }
    @JsonProperty("modulation_58_bipolar")
    public void setModulation58Bipolar(double value) { this.modulation58_Bipolar = value; }

    @JsonProperty("modulation_58_bypass")
    public double getModulation58Bypass() { return modulation58_Bypass; }
    @JsonProperty("modulation_58_bypass")
    public void setModulation58Bypass(double value) { this.modulation58_Bypass = value; }

    @JsonProperty("modulation_58_power")
    public double getModulation58Power() { return modulation58_Power; }
    @JsonProperty("modulation_58_power")
    public void setModulation58Power(double value) { this.modulation58_Power = value; }

    @JsonProperty("modulation_58_stereo")
    public double getModulation58Stereo() { return modulation58_Stereo; }
    @JsonProperty("modulation_58_stereo")
    public void setModulation58Stereo(double value) { this.modulation58_Stereo = value; }

    @JsonProperty("modulation_59_amount")
    public double getModulation59Amount() { return modulation59_Amount; }
    @JsonProperty("modulation_59_amount")
    public void setModulation59Amount(double value) { this.modulation59_Amount = value; }

    @JsonProperty("modulation_59_bipolar")
    public double getModulation59Bipolar() { return modulation59_Bipolar; }
    @JsonProperty("modulation_59_bipolar")
    public void setModulation59Bipolar(double value) { this.modulation59_Bipolar = value; }

    @JsonProperty("modulation_59_bypass")
    public double getModulation59Bypass() { return modulation59_Bypass; }
    @JsonProperty("modulation_59_bypass")
    public void setModulation59Bypass(double value) { this.modulation59_Bypass = value; }

    @JsonProperty("modulation_59_power")
    public double getModulation59Power() { return modulation59_Power; }
    @JsonProperty("modulation_59_power")
    public void setModulation59Power(double value) { this.modulation59_Power = value; }

    @JsonProperty("modulation_59_stereo")
    public double getModulation59Stereo() { return modulation59_Stereo; }
    @JsonProperty("modulation_59_stereo")
    public void setModulation59Stereo(double value) { this.modulation59_Stereo = value; }

    @JsonProperty("modulation_5_amount")
    public double getModulation5Amount() { return modulation5_Amount; }
    @JsonProperty("modulation_5_amount")
    public void setModulation5Amount(double value) { this.modulation5_Amount = value; }

    @JsonProperty("modulation_5_bipolar")
    public double getModulation5Bipolar() { return modulation5_Bipolar; }
    @JsonProperty("modulation_5_bipolar")
    public void setModulation5Bipolar(double value) { this.modulation5_Bipolar = value; }

    @JsonProperty("modulation_5_bypass")
    public double getModulation5Bypass() { return modulation5_Bypass; }
    @JsonProperty("modulation_5_bypass")
    public void setModulation5Bypass(double value) { this.modulation5_Bypass = value; }

    @JsonProperty("modulation_5_power")
    public double getModulation5Power() { return modulation5_Power; }
    @JsonProperty("modulation_5_power")
    public void setModulation5Power(double value) { this.modulation5_Power = value; }

    @JsonProperty("modulation_5_stereo")
    public double getModulation5Stereo() { return modulation5_Stereo; }
    @JsonProperty("modulation_5_stereo")
    public void setModulation5Stereo(double value) { this.modulation5_Stereo = value; }

    @JsonProperty("modulation_60_amount")
    public double getModulation60Amount() { return modulation60_Amount; }
    @JsonProperty("modulation_60_amount")
    public void setModulation60Amount(double value) { this.modulation60_Amount = value; }

    @JsonProperty("modulation_60_bipolar")
    public double getModulation60Bipolar() { return modulation60_Bipolar; }
    @JsonProperty("modulation_60_bipolar")
    public void setModulation60Bipolar(double value) { this.modulation60_Bipolar = value; }

    @JsonProperty("modulation_60_bypass")
    public double getModulation60Bypass() { return modulation60_Bypass; }
    @JsonProperty("modulation_60_bypass")
    public void setModulation60Bypass(double value) { this.modulation60_Bypass = value; }

    @JsonProperty("modulation_60_power")
    public double getModulation60Power() { return modulation60_Power; }
    @JsonProperty("modulation_60_power")
    public void setModulation60Power(double value) { this.modulation60_Power = value; }

    @JsonProperty("modulation_60_stereo")
    public double getModulation60Stereo() { return modulation60_Stereo; }
    @JsonProperty("modulation_60_stereo")
    public void setModulation60Stereo(double value) { this.modulation60_Stereo = value; }

    @JsonProperty("modulation_61_amount")
    public double getModulation61Amount() { return modulation61_Amount; }
    @JsonProperty("modulation_61_amount")
    public void setModulation61Amount(double value) { this.modulation61_Amount = value; }

    @JsonProperty("modulation_61_bipolar")
    public double getModulation61Bipolar() { return modulation61_Bipolar; }
    @JsonProperty("modulation_61_bipolar")
    public void setModulation61Bipolar(double value) { this.modulation61_Bipolar = value; }

    @JsonProperty("modulation_61_bypass")
    public double getModulation61Bypass() { return modulation61_Bypass; }
    @JsonProperty("modulation_61_bypass")
    public void setModulation61Bypass(double value) { this.modulation61_Bypass = value; }

    @JsonProperty("modulation_61_power")
    public double getModulation61Power() { return modulation61_Power; }
    @JsonProperty("modulation_61_power")
    public void setModulation61Power(double value) { this.modulation61_Power = value; }

    @JsonProperty("modulation_61_stereo")
    public double getModulation61Stereo() { return modulation61_Stereo; }
    @JsonProperty("modulation_61_stereo")
    public void setModulation61Stereo(double value) { this.modulation61_Stereo = value; }

    @JsonProperty("modulation_62_amount")
    public double getModulation62Amount() { return modulation62_Amount; }
    @JsonProperty("modulation_62_amount")
    public void setModulation62Amount(double value) { this.modulation62_Amount = value; }

    @JsonProperty("modulation_62_bipolar")
    public double getModulation62Bipolar() { return modulation62_Bipolar; }
    @JsonProperty("modulation_62_bipolar")
    public void setModulation62Bipolar(double value) { this.modulation62_Bipolar = value; }

    @JsonProperty("modulation_62_bypass")
    public double getModulation62Bypass() { return modulation62_Bypass; }
    @JsonProperty("modulation_62_bypass")
    public void setModulation62Bypass(double value) { this.modulation62_Bypass = value; }

    @JsonProperty("modulation_62_power")
    public double getModulation62Power() { return modulation62_Power; }
    @JsonProperty("modulation_62_power")
    public void setModulation62Power(double value) { this.modulation62_Power = value; }

    @JsonProperty("modulation_62_stereo")
    public double getModulation62Stereo() { return modulation62_Stereo; }
    @JsonProperty("modulation_62_stereo")
    public void setModulation62Stereo(double value) { this.modulation62_Stereo = value; }

    @JsonProperty("modulation_63_amount")
    public double getModulation63Amount() { return modulation63_Amount; }
    @JsonProperty("modulation_63_amount")
    public void setModulation63Amount(double value) { this.modulation63_Amount = value; }

    @JsonProperty("modulation_63_bipolar")
    public double getModulation63Bipolar() { return modulation63_Bipolar; }
    @JsonProperty("modulation_63_bipolar")
    public void setModulation63Bipolar(double value) { this.modulation63_Bipolar = value; }

    @JsonProperty("modulation_63_bypass")
    public double getModulation63Bypass() { return modulation63_Bypass; }
    @JsonProperty("modulation_63_bypass")
    public void setModulation63Bypass(double value) { this.modulation63_Bypass = value; }

    @JsonProperty("modulation_63_power")
    public double getModulation63Power() { return modulation63_Power; }
    @JsonProperty("modulation_63_power")
    public void setModulation63Power(double value) { this.modulation63_Power = value; }

    @JsonProperty("modulation_63_stereo")
    public double getModulation63Stereo() { return modulation63_Stereo; }
    @JsonProperty("modulation_63_stereo")
    public void setModulation63Stereo(double value) { this.modulation63_Stereo = value; }

    @JsonProperty("modulation_64_amount")
    public double getModulation64Amount() { return modulation64_Amount; }
    @JsonProperty("modulation_64_amount")
    public void setModulation64Amount(double value) { this.modulation64_Amount = value; }

    @JsonProperty("modulation_64_bipolar")
    public double getModulation64Bipolar() { return modulation64_Bipolar; }
    @JsonProperty("modulation_64_bipolar")
    public void setModulation64Bipolar(double value) { this.modulation64_Bipolar = value; }

    @JsonProperty("modulation_64_bypass")
    public double getModulation64Bypass() { return modulation64_Bypass; }
    @JsonProperty("modulation_64_bypass")
    public void setModulation64Bypass(double value) { this.modulation64_Bypass = value; }

    @JsonProperty("modulation_64_power")
    public double getModulation64Power() { return modulation64_Power; }
    @JsonProperty("modulation_64_power")
    public void setModulation64Power(double value) { this.modulation64_Power = value; }

    @JsonProperty("modulation_64_stereo")
    public double getModulation64Stereo() { return modulation64_Stereo; }
    @JsonProperty("modulation_64_stereo")
    public void setModulation64Stereo(double value) { this.modulation64_Stereo = value; }

    @JsonProperty("modulation_6_amount")
    public double getModulation6Amount() { return modulation6_Amount; }
    @JsonProperty("modulation_6_amount")
    public void setModulation6Amount(double value) { this.modulation6_Amount = value; }

    @JsonProperty("modulation_6_bipolar")
    public double getModulation6Bipolar() { return modulation6_Bipolar; }
    @JsonProperty("modulation_6_bipolar")
    public void setModulation6Bipolar(double value) { this.modulation6_Bipolar = value; }

    @JsonProperty("modulation_6_bypass")
    public double getModulation6Bypass() { return modulation6_Bypass; }
    @JsonProperty("modulation_6_bypass")
    public void setModulation6Bypass(double value) { this.modulation6_Bypass = value; }

    @JsonProperty("modulation_6_power")
    public double getModulation6Power() { return modulation6_Power; }
    @JsonProperty("modulation_6_power")
    public void setModulation6Power(double value) { this.modulation6_Power = value; }

    @JsonProperty("modulation_6_stereo")
    public double getModulation6Stereo() { return modulation6_Stereo; }
    @JsonProperty("modulation_6_stereo")
    public void setModulation6Stereo(double value) { this.modulation6_Stereo = value; }

    @JsonProperty("modulation_7_amount")
    public double getModulation7Amount() { return modulation7_Amount; }
    @JsonProperty("modulation_7_amount")
    public void setModulation7Amount(double value) { this.modulation7_Amount = value; }

    @JsonProperty("modulation_7_bipolar")
    public double getModulation7Bipolar() { return modulation7_Bipolar; }
    @JsonProperty("modulation_7_bipolar")
    public void setModulation7Bipolar(double value) { this.modulation7_Bipolar = value; }

    @JsonProperty("modulation_7_bypass")
    public double getModulation7Bypass() { return modulation7_Bypass; }
    @JsonProperty("modulation_7_bypass")
    public void setModulation7Bypass(double value) { this.modulation7_Bypass = value; }

    @JsonProperty("modulation_7_power")
    public double getModulation7Power() { return modulation7_Power; }
    @JsonProperty("modulation_7_power")
    public void setModulation7Power(double value) { this.modulation7_Power = value; }

    @JsonProperty("modulation_7_stereo")
    public double getModulation7Stereo() { return modulation7_Stereo; }
    @JsonProperty("modulation_7_stereo")
    public void setModulation7Stereo(double value) { this.modulation7_Stereo = value; }

    @JsonProperty("modulation_8_amount")
    public double getModulation8Amount() { return modulation8_Amount; }
    @JsonProperty("modulation_8_amount")
    public void setModulation8Amount(double value) { this.modulation8_Amount = value; }

    @JsonProperty("modulation_8_bipolar")
    public double getModulation8Bipolar() { return modulation8_Bipolar; }
    @JsonProperty("modulation_8_bipolar")
    public void setModulation8Bipolar(double value) { this.modulation8_Bipolar = value; }

    @JsonProperty("modulation_8_bypass")
    public double getModulation8Bypass() { return modulation8_Bypass; }
    @JsonProperty("modulation_8_bypass")
    public void setModulation8Bypass(double value) { this.modulation8_Bypass = value; }

    @JsonProperty("modulation_8_power")
    public double getModulation8Power() { return modulation8_Power; }
    @JsonProperty("modulation_8_power")
    public void setModulation8Power(double value) { this.modulation8_Power = value; }

    @JsonProperty("modulation_8_stereo")
    public double getModulation8Stereo() { return modulation8_Stereo; }
    @JsonProperty("modulation_8_stereo")
    public void setModulation8Stereo(double value) { this.modulation8_Stereo = value; }

    @JsonProperty("modulation_9_amount")
    public double getModulation9Amount() { return modulation9_Amount; }
    @JsonProperty("modulation_9_amount")
    public void setModulation9Amount(double value) { this.modulation9_Amount = value; }

    @JsonProperty("modulation_9_bipolar")
    public double getModulation9Bipolar() { return modulation9_Bipolar; }
    @JsonProperty("modulation_9_bipolar")
    public void setModulation9Bipolar(double value) { this.modulation9_Bipolar = value; }

    @JsonProperty("modulation_9_bypass")
    public double getModulation9Bypass() { return modulation9_Bypass; }
    @JsonProperty("modulation_9_bypass")
    public void setModulation9Bypass(double value) { this.modulation9_Bypass = value; }

    @JsonProperty("modulation_9_power")
    public double getModulation9Power() { return modulation9_Power; }
    @JsonProperty("modulation_9_power")
    public void setModulation9Power(double value) { this.modulation9_Power = value; }

    @JsonProperty("modulation_9_stereo")
    public double getModulation9Stereo() { return modulation9_Stereo; }
    @JsonProperty("modulation_9_stereo")
    public void setModulation9Stereo(double value) { this.modulation9_Stereo = value; }

    @JsonProperty("modulations")
    public Modulation[] getModulations() { return modulations; }
    @JsonProperty("modulations")
    public void setModulations(Modulation[] value) { this.modulations = value; }

    @JsonProperty("osc_1_destination")
    public double getOsc1Destination() { return osc1_Destination; }
    @JsonProperty("osc_1_destination")
    public void setOsc1Destination(double value) { this.osc1_Destination = value; }

    @JsonProperty("osc_1_detune_power")
    public double getOsc1DetunePower() { return osc1_DetunePower; }
    @JsonProperty("osc_1_detune_power")
    public void setOsc1DetunePower(double value) { this.osc1_DetunePower = value; }

    @JsonProperty("osc_1_detune_range")
    public double getOsc1DetuneRange() { return osc1_DetuneRange; }
    @JsonProperty("osc_1_detune_range")
    public void setOsc1DetuneRange(double value) { this.osc1_DetuneRange = value; }

    @JsonProperty("osc_1_distortion_amount")
    public double getOsc1DistortionAmount() { return osc1_DistortionAmount; }
    @JsonProperty("osc_1_distortion_amount")
    public void setOsc1DistortionAmount(double value) { this.osc1_DistortionAmount = value; }

    @JsonProperty("osc_1_distortion_phase")
    public double getOsc1DistortionPhase() { return osc1_DistortionPhase; }
    @JsonProperty("osc_1_distortion_phase")
    public void setOsc1DistortionPhase(double value) { this.osc1_DistortionPhase = value; }

    @JsonProperty("osc_1_distortion_spread")
    public double getOsc1DistortionSpread() { return osc1_DistortionSpread; }
    @JsonProperty("osc_1_distortion_spread")
    public void setOsc1DistortionSpread(double value) { this.osc1_DistortionSpread = value; }

    @JsonProperty("osc_1_distortion_type")
    public double getOsc1DistortionType() { return osc1_DistortionType; }
    @JsonProperty("osc_1_distortion_type")
    public void setOsc1DistortionType(double value) { this.osc1_DistortionType = value; }

    @JsonProperty("osc_1_frame_spread")
    public double getOsc1FrameSpread() { return osc1_FrameSpread; }
    @JsonProperty("osc_1_frame_spread")
    public void setOsc1FrameSpread(double value) { this.osc1_FrameSpread = value; }

    @JsonProperty("osc_1_level")
    public double getOsc1Level() { return osc1_Level; }
    @JsonProperty("osc_1_level")
    public void setOsc1Level(double value) { this.osc1_Level = value; }

    @JsonProperty("osc_1_midi_track")
    public double getOsc1MIDITrack() { return osc1_MIDITrack; }
    @JsonProperty("osc_1_midi_track")
    public void setOsc1MIDITrack(double value) { this.osc1_MIDITrack = value; }

    @JsonProperty("osc_1_on")
    public double getOsc1On() { return osc1_On; }
    @JsonProperty("osc_1_on")
    public void setOsc1On(double value) { this.osc1_On = value; }

    @JsonProperty("osc_1_pan")
    public double getOsc1Pan() { return osc1_Pan; }
    @JsonProperty("osc_1_pan")
    public void setOsc1Pan(double value) { this.osc1_Pan = value; }

    @JsonProperty("osc_1_phase")
    public double getOsc1Phase() { return osc1_Phase; }
    @JsonProperty("osc_1_phase")
    public void setOsc1Phase(double value) { this.osc1_Phase = value; }

    @JsonProperty("osc_1_random_phase")
    public double getOsc1RandomPhase() { return osc1_RandomPhase; }
    @JsonProperty("osc_1_random_phase")
    public void setOsc1RandomPhase(double value) { this.osc1_RandomPhase = value; }

    @JsonProperty("osc_1_smooth_interpolation")
    public double getOsc1SmoothInterpolation() { return osc1_SmoothInterpolation; }
    @JsonProperty("osc_1_smooth_interpolation")
    public void setOsc1SmoothInterpolation(double value) { this.osc1_SmoothInterpolation = value; }

    @JsonProperty("osc_1_spectral_morph_amount")
    public double getOsc1SpectralMorphAmount() { return osc1_SpectralMorphAmount; }
    @JsonProperty("osc_1_spectral_morph_amount")
    public void setOsc1SpectralMorphAmount(double value) { this.osc1_SpectralMorphAmount = value; }

    @JsonProperty("osc_1_spectral_morph_spread")
    public double getOsc1SpectralMorphSpread() { return osc1_SpectralMorphSpread; }
    @JsonProperty("osc_1_spectral_morph_spread")
    public void setOsc1SpectralMorphSpread(double value) { this.osc1_SpectralMorphSpread = value; }

    @JsonProperty("osc_1_spectral_morph_type")
    public double getOsc1SpectralMorphType() { return osc1_SpectralMorphType; }
    @JsonProperty("osc_1_spectral_morph_type")
    public void setOsc1SpectralMorphType(double value) { this.osc1_SpectralMorphType = value; }

    @JsonProperty("osc_1_spectral_unison")
    public double getOsc1SpectralUnison() { return osc1_SpectralUnison; }
    @JsonProperty("osc_1_spectral_unison")
    public void setOsc1SpectralUnison(double value) { this.osc1_SpectralUnison = value; }

    @JsonProperty("osc_1_stack_style")
    public double getOsc1StackStyle() { return osc1_StackStyle; }
    @JsonProperty("osc_1_stack_style")
    public void setOsc1StackStyle(double value) { this.osc1_StackStyle = value; }

    @JsonProperty("osc_1_stereo_spread")
    public double getOsc1StereoSpread() { return osc1_StereoSpread; }
    @JsonProperty("osc_1_stereo_spread")
    public void setOsc1StereoSpread(double value) { this.osc1_StereoSpread = value; }

    @JsonProperty("osc_1_transpose")
    public double getOsc1Transpose() { return osc1_Transpose; }
    @JsonProperty("osc_1_transpose")
    public void setOsc1Transpose(double value) { this.osc1_Transpose = value; }

    @JsonProperty("osc_1_transpose_quantize")
    public double getOsc1TransposeQuantize() { return osc1_TransposeQuantize; }
    @JsonProperty("osc_1_transpose_quantize")
    public void setOsc1TransposeQuantize(double value) { this.osc1_TransposeQuantize = value; }

    @JsonProperty("osc_1_tune")
    public double getOsc1Tune() { return osc1_Tune; }
    @JsonProperty("osc_1_tune")
    public void setOsc1Tune(double value) { this.osc1_Tune = value; }

    @JsonProperty("osc_1_unison_blend")
    public double getOsc1UnisonBlend() { return osc1_UnisonBlend; }
    @JsonProperty("osc_1_unison_blend")
    public void setOsc1UnisonBlend(double value) { this.osc1_UnisonBlend = value; }

    @JsonProperty("osc_1_unison_detune")
    public double getOsc1UnisonDetune() { return osc1_UnisonDetune; }
    @JsonProperty("osc_1_unison_detune")
    public void setOsc1UnisonDetune(double value) { this.osc1_UnisonDetune = value; }

    @JsonProperty("osc_1_unison_voices")
    public double getOsc1UnisonVoices() { return osc1_UnisonVoices; }
    @JsonProperty("osc_1_unison_voices")
    public void setOsc1UnisonVoices(double value) { this.osc1_UnisonVoices = value; }

    @JsonProperty("osc_1_view_2d")
    public double getOsc1View2D() { return osc1_View2D; }
    @JsonProperty("osc_1_view_2d")
    public void setOsc1View2D(double value) { this.osc1_View2D = value; }

    @JsonProperty("osc_1_wave_frame")
    public double getOsc1WaveFrame() { return osc1_WaveFrame; }
    @JsonProperty("osc_1_wave_frame")
    public void setOsc1WaveFrame(double value) { this.osc1_WaveFrame = value; }

    @JsonProperty("osc_2_destination")
    public double getOsc2Destination() { return osc2_Destination; }
    @JsonProperty("osc_2_destination")
    public void setOsc2Destination(double value) { this.osc2_Destination = value; }

    @JsonProperty("osc_2_detune_power")
    public double getOsc2DetunePower() { return osc2_DetunePower; }
    @JsonProperty("osc_2_detune_power")
    public void setOsc2DetunePower(double value) { this.osc2_DetunePower = value; }

    @JsonProperty("osc_2_detune_range")
    public double getOsc2DetuneRange() { return osc2_DetuneRange; }
    @JsonProperty("osc_2_detune_range")
    public void setOsc2DetuneRange(double value) { this.osc2_DetuneRange = value; }

    @JsonProperty("osc_2_distortion_amount")
    public double getOsc2DistortionAmount() { return osc2_DistortionAmount; }
    @JsonProperty("osc_2_distortion_amount")
    public void setOsc2DistortionAmount(double value) { this.osc2_DistortionAmount = value; }

    @JsonProperty("osc_2_distortion_phase")
    public double getOsc2DistortionPhase() { return osc2_DistortionPhase; }
    @JsonProperty("osc_2_distortion_phase")
    public void setOsc2DistortionPhase(double value) { this.osc2_DistortionPhase = value; }

    @JsonProperty("osc_2_distortion_spread")
    public double getOsc2DistortionSpread() { return osc2_DistortionSpread; }
    @JsonProperty("osc_2_distortion_spread")
    public void setOsc2DistortionSpread(double value) { this.osc2_DistortionSpread = value; }

    @JsonProperty("osc_2_distortion_type")
    public double getOsc2DistortionType() { return osc2_DistortionType; }
    @JsonProperty("osc_2_distortion_type")
    public void setOsc2DistortionType(double value) { this.osc2_DistortionType = value; }

    @JsonProperty("osc_2_frame_spread")
    public double getOsc2FrameSpread() { return osc2_FrameSpread; }
    @JsonProperty("osc_2_frame_spread")
    public void setOsc2FrameSpread(double value) { this.osc2_FrameSpread = value; }

    @JsonProperty("osc_2_level")
    public double getOsc2Level() { return osc2_Level; }
    @JsonProperty("osc_2_level")
    public void setOsc2Level(double value) { this.osc2_Level = value; }

    @JsonProperty("osc_2_midi_track")
    public double getOsc2MIDITrack() { return osc2_MIDITrack; }
    @JsonProperty("osc_2_midi_track")
    public void setOsc2MIDITrack(double value) { this.osc2_MIDITrack = value; }

    @JsonProperty("osc_2_on")
    public double getOsc2On() { return osc2_On; }
    @JsonProperty("osc_2_on")
    public void setOsc2On(double value) { this.osc2_On = value; }

    @JsonProperty("osc_2_pan")
    public double getOsc2Pan() { return osc2_Pan; }
    @JsonProperty("osc_2_pan")
    public void setOsc2Pan(double value) { this.osc2_Pan = value; }

    @JsonProperty("osc_2_phase")
    public double getOsc2Phase() { return osc2_Phase; }
    @JsonProperty("osc_2_phase")
    public void setOsc2Phase(double value) { this.osc2_Phase = value; }

    @JsonProperty("osc_2_random_phase")
    public double getOsc2RandomPhase() { return osc2_RandomPhase; }
    @JsonProperty("osc_2_random_phase")
    public void setOsc2RandomPhase(double value) { this.osc2_RandomPhase = value; }

    @JsonProperty("osc_2_smooth_interpolation")
    public double getOsc2SmoothInterpolation() { return osc2_SmoothInterpolation; }
    @JsonProperty("osc_2_smooth_interpolation")
    public void setOsc2SmoothInterpolation(double value) { this.osc2_SmoothInterpolation = value; }

    @JsonProperty("osc_2_spectral_morph_amount")
    public double getOsc2SpectralMorphAmount() { return osc2_SpectralMorphAmount; }
    @JsonProperty("osc_2_spectral_morph_amount")
    public void setOsc2SpectralMorphAmount(double value) { this.osc2_SpectralMorphAmount = value; }

    @JsonProperty("osc_2_spectral_morph_spread")
    public double getOsc2SpectralMorphSpread() { return osc2_SpectralMorphSpread; }
    @JsonProperty("osc_2_spectral_morph_spread")
    public void setOsc2SpectralMorphSpread(double value) { this.osc2_SpectralMorphSpread = value; }

    @JsonProperty("osc_2_spectral_morph_type")
    public double getOsc2SpectralMorphType() { return osc2_SpectralMorphType; }
    @JsonProperty("osc_2_spectral_morph_type")
    public void setOsc2SpectralMorphType(double value) { this.osc2_SpectralMorphType = value; }

    @JsonProperty("osc_2_spectral_unison")
    public double getOsc2SpectralUnison() { return osc2_SpectralUnison; }
    @JsonProperty("osc_2_spectral_unison")
    public void setOsc2SpectralUnison(double value) { this.osc2_SpectralUnison = value; }

    @JsonProperty("osc_2_stack_style")
    public double getOsc2StackStyle() { return osc2_StackStyle; }
    @JsonProperty("osc_2_stack_style")
    public void setOsc2StackStyle(double value) { this.osc2_StackStyle = value; }

    @JsonProperty("osc_2_stereo_spread")
    public double getOsc2StereoSpread() { return osc2_StereoSpread; }
    @JsonProperty("osc_2_stereo_spread")
    public void setOsc2StereoSpread(double value) { this.osc2_StereoSpread = value; }

    @JsonProperty("osc_2_transpose")
    public double getOsc2Transpose() { return osc2_Transpose; }
    @JsonProperty("osc_2_transpose")
    public void setOsc2Transpose(double value) { this.osc2_Transpose = value; }

    @JsonProperty("osc_2_transpose_quantize")
    public double getOsc2TransposeQuantize() { return osc2_TransposeQuantize; }
    @JsonProperty("osc_2_transpose_quantize")
    public void setOsc2TransposeQuantize(double value) { this.osc2_TransposeQuantize = value; }

    @JsonProperty("osc_2_tune")
    public double getOsc2Tune() { return osc2_Tune; }
    @JsonProperty("osc_2_tune")
    public void setOsc2Tune(double value) { this.osc2_Tune = value; }

    @JsonProperty("osc_2_unison_blend")
    public double getOsc2UnisonBlend() { return osc2_UnisonBlend; }
    @JsonProperty("osc_2_unison_blend")
    public void setOsc2UnisonBlend(double value) { this.osc2_UnisonBlend = value; }

    @JsonProperty("osc_2_unison_detune")
    public double getOsc2UnisonDetune() { return osc2_UnisonDetune; }
    @JsonProperty("osc_2_unison_detune")
    public void setOsc2UnisonDetune(double value) { this.osc2_UnisonDetune = value; }

    @JsonProperty("osc_2_unison_voices")
    public double getOsc2UnisonVoices() { return osc2_UnisonVoices; }
    @JsonProperty("osc_2_unison_voices")
    public void setOsc2UnisonVoices(double value) { this.osc2_UnisonVoices = value; }

    @JsonProperty("osc_2_view_2d")
    public double getOsc2View2D() { return osc2_View2D; }
    @JsonProperty("osc_2_view_2d")
    public void setOsc2View2D(double value) { this.osc2_View2D = value; }

    @JsonProperty("osc_2_wave_frame")
    public double getOsc2WaveFrame() { return osc2_WaveFrame; }
    @JsonProperty("osc_2_wave_frame")
    public void setOsc2WaveFrame(double value) { this.osc2_WaveFrame = value; }

    @JsonProperty("osc_3_destination")
    public double getOsc3Destination() { return osc3_Destination; }
    @JsonProperty("osc_3_destination")
    public void setOsc3Destination(double value) { this.osc3_Destination = value; }

    @JsonProperty("osc_3_detune_power")
    public double getOsc3DetunePower() { return osc3_DetunePower; }
    @JsonProperty("osc_3_detune_power")
    public void setOsc3DetunePower(double value) { this.osc3_DetunePower = value; }

    @JsonProperty("osc_3_detune_range")
    public double getOsc3DetuneRange() { return osc3_DetuneRange; }
    @JsonProperty("osc_3_detune_range")
    public void setOsc3DetuneRange(double value) { this.osc3_DetuneRange = value; }

    @JsonProperty("osc_3_distortion_amount")
    public double getOsc3DistortionAmount() { return osc3_DistortionAmount; }
    @JsonProperty("osc_3_distortion_amount")
    public void setOsc3DistortionAmount(double value) { this.osc3_DistortionAmount = value; }

    @JsonProperty("osc_3_distortion_phase")
    public double getOsc3DistortionPhase() { return osc3_DistortionPhase; }
    @JsonProperty("osc_3_distortion_phase")
    public void setOsc3DistortionPhase(double value) { this.osc3_DistortionPhase = value; }

    @JsonProperty("osc_3_distortion_spread")
    public double getOsc3DistortionSpread() { return osc3_DistortionSpread; }
    @JsonProperty("osc_3_distortion_spread")
    public void setOsc3DistortionSpread(double value) { this.osc3_DistortionSpread = value; }

    @JsonProperty("osc_3_distortion_type")
    public double getOsc3DistortionType() { return osc3_DistortionType; }
    @JsonProperty("osc_3_distortion_type")
    public void setOsc3DistortionType(double value) { this.osc3_DistortionType = value; }

    @JsonProperty("osc_3_frame_spread")
    public double getOsc3FrameSpread() { return osc3_FrameSpread; }
    @JsonProperty("osc_3_frame_spread")
    public void setOsc3FrameSpread(double value) { this.osc3_FrameSpread = value; }

    @JsonProperty("osc_3_level")
    public double getOsc3Level() { return osc3_Level; }
    @JsonProperty("osc_3_level")
    public void setOsc3Level(double value) { this.osc3_Level = value; }

    @JsonProperty("osc_3_midi_track")
    public double getOsc3MIDITrack() { return osc3_MIDITrack; }
    @JsonProperty("osc_3_midi_track")
    public void setOsc3MIDITrack(double value) { this.osc3_MIDITrack = value; }

    @JsonProperty("osc_3_on")
    public double getOsc3On() { return osc3_On; }
    @JsonProperty("osc_3_on")
    public void setOsc3On(double value) { this.osc3_On = value; }

    @JsonProperty("osc_3_pan")
    public double getOsc3Pan() { return osc3_Pan; }
    @JsonProperty("osc_3_pan")
    public void setOsc3Pan(double value) { this.osc3_Pan = value; }

    @JsonProperty("osc_3_phase")
    public double getOsc3Phase() { return osc3_Phase; }
    @JsonProperty("osc_3_phase")
    public void setOsc3Phase(double value) { this.osc3_Phase = value; }

    @JsonProperty("osc_3_random_phase")
    public double getOsc3RandomPhase() { return osc3_RandomPhase; }
    @JsonProperty("osc_3_random_phase")
    public void setOsc3RandomPhase(double value) { this.osc3_RandomPhase = value; }

    @JsonProperty("osc_3_smooth_interpolation")
    public double getOsc3SmoothInterpolation() { return osc3_SmoothInterpolation; }
    @JsonProperty("osc_3_smooth_interpolation")
    public void setOsc3SmoothInterpolation(double value) { this.osc3_SmoothInterpolation = value; }

    @JsonProperty("osc_3_spectral_morph_amount")
    public double getOsc3SpectralMorphAmount() { return osc3_SpectralMorphAmount; }
    @JsonProperty("osc_3_spectral_morph_amount")
    public void setOsc3SpectralMorphAmount(double value) { this.osc3_SpectralMorphAmount = value; }

    @JsonProperty("osc_3_spectral_morph_spread")
    public double getOsc3SpectralMorphSpread() { return osc3_SpectralMorphSpread; }
    @JsonProperty("osc_3_spectral_morph_spread")
    public void setOsc3SpectralMorphSpread(double value) { this.osc3_SpectralMorphSpread = value; }

    @JsonProperty("osc_3_spectral_morph_type")
    public double getOsc3SpectralMorphType() { return osc3_SpectralMorphType; }
    @JsonProperty("osc_3_spectral_morph_type")
    public void setOsc3SpectralMorphType(double value) { this.osc3_SpectralMorphType = value; }

    @JsonProperty("osc_3_spectral_unison")
    public double getOsc3SpectralUnison() { return osc3_SpectralUnison; }
    @JsonProperty("osc_3_spectral_unison")
    public void setOsc3SpectralUnison(double value) { this.osc3_SpectralUnison = value; }

    @JsonProperty("osc_3_stack_style")
    public double getOsc3StackStyle() { return osc3_StackStyle; }
    @JsonProperty("osc_3_stack_style")
    public void setOsc3StackStyle(double value) { this.osc3_StackStyle = value; }

    @JsonProperty("osc_3_stereo_spread")
    public double getOsc3StereoSpread() { return osc3_StereoSpread; }
    @JsonProperty("osc_3_stereo_spread")
    public void setOsc3StereoSpread(double value) { this.osc3_StereoSpread = value; }

    @JsonProperty("osc_3_transpose")
    public double getOsc3Transpose() { return osc3_Transpose; }
    @JsonProperty("osc_3_transpose")
    public void setOsc3Transpose(double value) { this.osc3_Transpose = value; }

    @JsonProperty("osc_3_transpose_quantize")
    public double getOsc3TransposeQuantize() { return osc3_TransposeQuantize; }
    @JsonProperty("osc_3_transpose_quantize")
    public void setOsc3TransposeQuantize(double value) { this.osc3_TransposeQuantize = value; }

    @JsonProperty("osc_3_tune")
    public double getOsc3Tune() { return osc3_Tune; }
    @JsonProperty("osc_3_tune")
    public void setOsc3Tune(double value) { this.osc3_Tune = value; }

    @JsonProperty("osc_3_unison_blend")
    public double getOsc3UnisonBlend() { return osc3_UnisonBlend; }
    @JsonProperty("osc_3_unison_blend")
    public void setOsc3UnisonBlend(double value) { this.osc3_UnisonBlend = value; }

    @JsonProperty("osc_3_unison_detune")
    public double getOsc3UnisonDetune() { return osc3_UnisonDetune; }
    @JsonProperty("osc_3_unison_detune")
    public void setOsc3UnisonDetune(double value) { this.osc3_UnisonDetune = value; }

    @JsonProperty("osc_3_unison_voices")
    public double getOsc3UnisonVoices() { return osc3_UnisonVoices; }
    @JsonProperty("osc_3_unison_voices")
    public void setOsc3UnisonVoices(double value) { this.osc3_UnisonVoices = value; }

    @JsonProperty("osc_3_view_2d")
    public double getOsc3View2D() { return osc3_View2D; }
    @JsonProperty("osc_3_view_2d")
    public void setOsc3View2D(double value) { this.osc3_View2D = value; }

    @JsonProperty("osc_3_wave_frame")
    public double getOsc3WaveFrame() { return osc3_WaveFrame; }
    @JsonProperty("osc_3_wave_frame")
    public void setOsc3WaveFrame(double value) { this.osc3_WaveFrame = value; }

    @JsonProperty("oversampling")
    public double getOversampling() { return oversampling; }
    @JsonProperty("oversampling")
    public void setOversampling(double value) { this.oversampling = value; }

    @JsonProperty("phaser_blend")
    public double getPhaserBlend() { return phaserBlend; }
    @JsonProperty("phaser_blend")
    public void setPhaserBlend(double value) { this.phaserBlend = value; }

    @JsonProperty("phaser_center")
    public double getPhaserCenter() { return phaserCenter; }
    @JsonProperty("phaser_center")
    public void setPhaserCenter(double value) { this.phaserCenter = value; }

    @JsonProperty("phaser_dry_wet")
    public double getPhaserDryWet() { return phaserDryWet; }
    @JsonProperty("phaser_dry_wet")
    public void setPhaserDryWet(double value) { this.phaserDryWet = value; }

    @JsonProperty("phaser_feedback")
    public double getPhaserFeedback() { return phaserFeedback; }
    @JsonProperty("phaser_feedback")
    public void setPhaserFeedback(double value) { this.phaserFeedback = value; }

    @JsonProperty("phaser_frequency")
    public double getPhaserFrequency() { return phaserFrequency; }
    @JsonProperty("phaser_frequency")
    public void setPhaserFrequency(double value) { this.phaserFrequency = value; }

    @JsonProperty("phaser_mod_depth")
    public double getPhaserModDepth() { return phaserModDepth; }
    @JsonProperty("phaser_mod_depth")
    public void setPhaserModDepth(double value) { this.phaserModDepth = value; }

    @JsonProperty("phaser_on")
    public double getPhaserOn() { return phaserOn; }
    @JsonProperty("phaser_on")
    public void setPhaserOn(double value) { this.phaserOn = value; }

    @JsonProperty("phaser_phase_offset")
    public double getPhaserPhaseOffset() { return phaserPhaseOffset; }
    @JsonProperty("phaser_phase_offset")
    public void setPhaserPhaseOffset(double value) { this.phaserPhaseOffset = value; }

    @JsonProperty("phaser_sync")
    public double getPhaserSync() { return phaserSync; }
    @JsonProperty("phaser_sync")
    public void setPhaserSync(double value) { this.phaserSync = value; }

    @JsonProperty("phaser_tempo")
    public double getPhaserTempo() { return phaserTempo; }
    @JsonProperty("phaser_tempo")
    public void setPhaserTempo(double value) { this.phaserTempo = value; }

    @JsonProperty("pitch_bend_range")
    public double getPitchBendRange() { return pitchBendRange; }
    @JsonProperty("pitch_bend_range")
    public void setPitchBendRange(double value) { this.pitchBendRange = value; }

    @JsonProperty("pitch_wheel")
    public double getPitchWheel() { return pitchWheel; }
    @JsonProperty("pitch_wheel")
    public void setPitchWheel(double value) { this.pitchWheel = value; }

    @JsonProperty("polyphony")
    public double getPolyphony() { return polyphony; }
    @JsonProperty("polyphony")
    public void setPolyphony(double value) { this.polyphony = value; }

    @JsonProperty("portamento_force")
    public double getPortamentoForce() { return portamentoForce; }
    @JsonProperty("portamento_force")
    public void setPortamentoForce(double value) { this.portamentoForce = value; }

    @JsonProperty("portamento_scale")
    public double getPortamentoScale() { return portamentoScale; }
    @JsonProperty("portamento_scale")
    public void setPortamentoScale(double value) { this.portamentoScale = value; }

    @JsonProperty("portamento_slope")
    public double getPortamentoSlope() { return portamentoSlope; }
    @JsonProperty("portamento_slope")
    public void setPortamentoSlope(double value) { this.portamentoSlope = value; }

    @JsonProperty("portamento_time")
    public double getPortamentoTime() { return portamentoTime; }
    @JsonProperty("portamento_time")
    public void setPortamentoTime(double value) { this.portamentoTime = value; }

    @JsonProperty("random_1_frequency")
    public double getRandom1Frequency() { return random1_Frequency; }
    @JsonProperty("random_1_frequency")
    public void setRandom1Frequency(double value) { this.random1_Frequency = value; }

    @JsonProperty("random_1_keytrack_transpose")
    public Double getRandom1KeytrackTranspose() { return random1_KeytrackTranspose; }
    @JsonProperty("random_1_keytrack_transpose")
    public void setRandom1KeytrackTranspose(Double value) { this.random1_KeytrackTranspose = value; }

    @JsonProperty("random_1_keytrack_tune")
    public Double getRandom1KeytrackTune() { return random1_KeytrackTune; }
    @JsonProperty("random_1_keytrack_tune")
    public void setRandom1KeytrackTune(Double value) { this.random1_KeytrackTune = value; }

    @JsonProperty("random_1_stereo")
    public double getRandom1Stereo() { return random1_Stereo; }
    @JsonProperty("random_1_stereo")
    public void setRandom1Stereo(double value) { this.random1_Stereo = value; }

    @JsonProperty("random_1_style")
    public double getRandom1Style() { return random1_Style; }
    @JsonProperty("random_1_style")
    public void setRandom1Style(double value) { this.random1_Style = value; }

    @JsonProperty("random_1_sync")
    public double getRandom1Sync() { return random1_Sync; }
    @JsonProperty("random_1_sync")
    public void setRandom1Sync(double value) { this.random1_Sync = value; }

    @JsonProperty("random_1_sync_type")
    public double getRandom1SyncType() { return random1_SyncType; }
    @JsonProperty("random_1_sync_type")
    public void setRandom1SyncType(double value) { this.random1_SyncType = value; }

    @JsonProperty("random_1_tempo")
    public double getRandom1Tempo() { return random1_Tempo; }
    @JsonProperty("random_1_tempo")
    public void setRandom1Tempo(double value) { this.random1_Tempo = value; }

    @JsonProperty("random_2_frequency")
    public double getRandom2Frequency() { return random2_Frequency; }
    @JsonProperty("random_2_frequency")
    public void setRandom2Frequency(double value) { this.random2_Frequency = value; }

    @JsonProperty("random_2_keytrack_transpose")
    public Double getRandom2KeytrackTranspose() { return random2_KeytrackTranspose; }
    @JsonProperty("random_2_keytrack_transpose")
    public void setRandom2KeytrackTranspose(Double value) { this.random2_KeytrackTranspose = value; }

    @JsonProperty("random_2_keytrack_tune")
    public Double getRandom2KeytrackTune() { return random2_KeytrackTune; }
    @JsonProperty("random_2_keytrack_tune")
    public void setRandom2KeytrackTune(Double value) { this.random2_KeytrackTune = value; }

    @JsonProperty("random_2_stereo")
    public double getRandom2Stereo() { return random2_Stereo; }
    @JsonProperty("random_2_stereo")
    public void setRandom2Stereo(double value) { this.random2_Stereo = value; }

    @JsonProperty("random_2_style")
    public double getRandom2Style() { return random2_Style; }
    @JsonProperty("random_2_style")
    public void setRandom2Style(double value) { this.random2_Style = value; }

    @JsonProperty("random_2_sync")
    public double getRandom2Sync() { return random2_Sync; }
    @JsonProperty("random_2_sync")
    public void setRandom2Sync(double value) { this.random2_Sync = value; }

    @JsonProperty("random_2_sync_type")
    public double getRandom2SyncType() { return random2_SyncType; }
    @JsonProperty("random_2_sync_type")
    public void setRandom2SyncType(double value) { this.random2_SyncType = value; }

    @JsonProperty("random_2_tempo")
    public double getRandom2Tempo() { return random2_Tempo; }
    @JsonProperty("random_2_tempo")
    public void setRandom2Tempo(double value) { this.random2_Tempo = value; }

    @JsonProperty("random_3_frequency")
    public double getRandom3Frequency() { return random3_Frequency; }
    @JsonProperty("random_3_frequency")
    public void setRandom3Frequency(double value) { this.random3_Frequency = value; }

    @JsonProperty("random_3_keytrack_transpose")
    public Double getRandom3KeytrackTranspose() { return random3_KeytrackTranspose; }
    @JsonProperty("random_3_keytrack_transpose")
    public void setRandom3KeytrackTranspose(Double value) { this.random3_KeytrackTranspose = value; }

    @JsonProperty("random_3_keytrack_tune")
    public Double getRandom3KeytrackTune() { return random3_KeytrackTune; }
    @JsonProperty("random_3_keytrack_tune")
    public void setRandom3KeytrackTune(Double value) { this.random3_KeytrackTune = value; }

    @JsonProperty("random_3_stereo")
    public double getRandom3Stereo() { return random3_Stereo; }
    @JsonProperty("random_3_stereo")
    public void setRandom3Stereo(double value) { this.random3_Stereo = value; }

    @JsonProperty("random_3_style")
    public double getRandom3Style() { return random3_Style; }
    @JsonProperty("random_3_style")
    public void setRandom3Style(double value) { this.random3_Style = value; }

    @JsonProperty("random_3_sync")
    public double getRandom3Sync() { return random3_Sync; }
    @JsonProperty("random_3_sync")
    public void setRandom3Sync(double value) { this.random3_Sync = value; }

    @JsonProperty("random_3_sync_type")
    public double getRandom3SyncType() { return random3_SyncType; }
    @JsonProperty("random_3_sync_type")
    public void setRandom3SyncType(double value) { this.random3_SyncType = value; }

    @JsonProperty("random_3_tempo")
    public double getRandom3Tempo() { return random3_Tempo; }
    @JsonProperty("random_3_tempo")
    public void setRandom3Tempo(double value) { this.random3_Tempo = value; }

    @JsonProperty("random_4_frequency")
    public double getRandom4Frequency() { return random4_Frequency; }
    @JsonProperty("random_4_frequency")
    public void setRandom4Frequency(double value) { this.random4_Frequency = value; }

    @JsonProperty("random_4_keytrack_transpose")
    public Double getRandom4KeytrackTranspose() { return random4_KeytrackTranspose; }
    @JsonProperty("random_4_keytrack_transpose")
    public void setRandom4KeytrackTranspose(Double value) { this.random4_KeytrackTranspose = value; }

    @JsonProperty("random_4_keytrack_tune")
    public Double getRandom4KeytrackTune() { return random4_KeytrackTune; }
    @JsonProperty("random_4_keytrack_tune")
    public void setRandom4KeytrackTune(Double value) { this.random4_KeytrackTune = value; }

    @JsonProperty("random_4_stereo")
    public double getRandom4Stereo() { return random4_Stereo; }
    @JsonProperty("random_4_stereo")
    public void setRandom4Stereo(double value) { this.random4_Stereo = value; }

    @JsonProperty("random_4_style")
    public double getRandom4Style() { return random4_Style; }
    @JsonProperty("random_4_style")
    public void setRandom4Style(double value) { this.random4_Style = value; }

    @JsonProperty("random_4_sync")
    public double getRandom4Sync() { return random4_Sync; }
    @JsonProperty("random_4_sync")
    public void setRandom4Sync(double value) { this.random4_Sync = value; }

    @JsonProperty("random_4_sync_type")
    public double getRandom4SyncType() { return random4_SyncType; }
    @JsonProperty("random_4_sync_type")
    public void setRandom4SyncType(double value) { this.random4_SyncType = value; }

    @JsonProperty("random_4_tempo")
    public double getRandom4Tempo() { return random4_Tempo; }
    @JsonProperty("random_4_tempo")
    public void setRandom4Tempo(double value) { this.random4_Tempo = value; }

    @JsonProperty("reverb_chorus_amount")
    public double getReverbChorusAmount() { return reverbChorusAmount; }
    @JsonProperty("reverb_chorus_amount")
    public void setReverbChorusAmount(double value) { this.reverbChorusAmount = value; }

    @JsonProperty("reverb_chorus_frequency")
    public double getReverbChorusFrequency() { return reverbChorusFrequency; }
    @JsonProperty("reverb_chorus_frequency")
    public void setReverbChorusFrequency(double value) { this.reverbChorusFrequency = value; }

    @JsonProperty("reverb_decay_time")
    public double getReverbDecayTime() { return reverbDecayTime; }
    @JsonProperty("reverb_decay_time")
    public void setReverbDecayTime(double value) { this.reverbDecayTime = value; }

    @JsonProperty("reverb_delay")
    public Double getReverbDelay() { return reverbDelay; }
    @JsonProperty("reverb_delay")
    public void setReverbDelay(Double value) { this.reverbDelay = value; }

    @JsonProperty("reverb_dry_wet")
    public double getReverbDryWet() { return reverbDryWet; }
    @JsonProperty("reverb_dry_wet")
    public void setReverbDryWet(double value) { this.reverbDryWet = value; }

    @JsonProperty("reverb_high_shelf_cutoff")
    public double getReverbHighShelfCutoff() { return reverbHighShelfCutoff; }
    @JsonProperty("reverb_high_shelf_cutoff")
    public void setReverbHighShelfCutoff(double value) { this.reverbHighShelfCutoff = value; }

    @JsonProperty("reverb_high_shelf_gain")
    public double getReverbHighShelfGain() { return reverbHighShelfGain; }
    @JsonProperty("reverb_high_shelf_gain")
    public void setReverbHighShelfGain(double value) { this.reverbHighShelfGain = value; }

    @JsonProperty("reverb_low_shelf_cutoff")
    public double getReverbLowShelfCutoff() { return reverbLowShelfCutoff; }
    @JsonProperty("reverb_low_shelf_cutoff")
    public void setReverbLowShelfCutoff(double value) { this.reverbLowShelfCutoff = value; }

    @JsonProperty("reverb_low_shelf_gain")
    public double getReverbLowShelfGain() { return reverbLowShelfGain; }
    @JsonProperty("reverb_low_shelf_gain")
    public void setReverbLowShelfGain(double value) { this.reverbLowShelfGain = value; }

    @JsonProperty("reverb_on")
    public double getReverbOn() { return reverbOn; }
    @JsonProperty("reverb_on")
    public void setReverbOn(double value) { this.reverbOn = value; }

    @JsonProperty("reverb_pre_high_cutoff")
    public double getReverbPreHighCutoff() { return reverbPreHighCutoff; }
    @JsonProperty("reverb_pre_high_cutoff")
    public void setReverbPreHighCutoff(double value) { this.reverbPreHighCutoff = value; }

    @JsonProperty("reverb_pre_low_cutoff")
    public double getReverbPreLowCutoff() { return reverbPreLowCutoff; }
    @JsonProperty("reverb_pre_low_cutoff")
    public void setReverbPreLowCutoff(double value) { this.reverbPreLowCutoff = value; }

    @JsonProperty("reverb_size")
    public double getReverbSize() { return reverbSize; }
    @JsonProperty("reverb_size")
    public void setReverbSize(double value) { this.reverbSize = value; }

    @JsonProperty("sample")
    public Sample getSample() { return sample; }
    @JsonProperty("sample")
    public void setSample(Sample value) { this.sample = value; }

    @JsonProperty("sample_bounce")
    public Double getSampleBounce() { return sampleBounce; }
    @JsonProperty("sample_bounce")
    public void setSampleBounce(Double value) { this.sampleBounce = value; }

    @JsonProperty("sample_destination")
    public double getSampleDestination() { return sampleDestination; }
    @JsonProperty("sample_destination")
    public void setSampleDestination(double value) { this.sampleDestination = value; }

    @JsonProperty("sample_keytrack")
    public double getSampleKeytrack() { return sampleKeytrack; }
    @JsonProperty("sample_keytrack")
    public void setSampleKeytrack(double value) { this.sampleKeytrack = value; }

    @JsonProperty("sample_level")
    public double getSampleLevel() { return sampleLevel; }
    @JsonProperty("sample_level")
    public void setSampleLevel(double value) { this.sampleLevel = value; }

    @JsonProperty("sample_loop")
    public double getSampleLoop() { return sampleLoop; }
    @JsonProperty("sample_loop")
    public void setSampleLoop(double value) { this.sampleLoop = value; }

    @JsonProperty("sample_on")
    public double getSampleOn() { return sampleOn; }
    @JsonProperty("sample_on")
    public void setSampleOn(double value) { this.sampleOn = value; }

    @JsonProperty("sample_pan")
    public double getSamplePan() { return samplePan; }
    @JsonProperty("sample_pan")
    public void setSamplePan(double value) { this.samplePan = value; }

    @JsonProperty("sample_random_phase")
    public double getSampleRandomPhase() { return sampleRandomPhase; }
    @JsonProperty("sample_random_phase")
    public void setSampleRandomPhase(double value) { this.sampleRandomPhase = value; }

    @JsonProperty("sample_transpose")
    public double getSampleTranspose() { return sampleTranspose; }
    @JsonProperty("sample_transpose")
    public void setSampleTranspose(double value) { this.sampleTranspose = value; }

    @JsonProperty("sample_transpose_quantize")
    public double getSampleTransposeQuantize() { return sampleTransposeQuantize; }
    @JsonProperty("sample_transpose_quantize")
    public void setSampleTransposeQuantize(double value) { this.sampleTransposeQuantize = value; }

    @JsonProperty("sample_tune")
    public double getSampleTune() { return sampleTune; }
    @JsonProperty("sample_tune")
    public void setSampleTune(double value) { this.sampleTune = value; }

    @JsonProperty("stereo_mode")
    public Double getStereoMode() { return stereoMode; }
    @JsonProperty("stereo_mode")
    public void setStereoMode(Double value) { this.stereoMode = value; }

    @JsonProperty("stereo_routing")
    public double getStereoRouting() { return stereoRouting; }
    @JsonProperty("stereo_routing")
    public void setStereoRouting(double value) { this.stereoRouting = value; }

    @JsonProperty("velocity_track")
    public double getVelocityTrack() { return velocityTrack; }
    @JsonProperty("velocity_track")
    public void setVelocityTrack(double value) { this.velocityTrack = value; }

    @JsonProperty("view_spectrogram")
    public Double getViewSpectrogram() { return viewSpectrogram; }
    @JsonProperty("view_spectrogram")
    public void setViewSpectrogram(Double value) { this.viewSpectrogram = value; }

    @JsonProperty("voice_amplitude")
    public double getVoiceAmplitude() { return voiceAmplitude; }
    @JsonProperty("voice_amplitude")
    public void setVoiceAmplitude(double value) { this.voiceAmplitude = value; }

    @JsonProperty("voice_override")
    public Double getVoiceOverride() { return voiceOverride; }
    @JsonProperty("voice_override")
    public void setVoiceOverride(Double value) { this.voiceOverride = value; }

    @JsonProperty("voice_priority")
    public double getVoicePriority() { return voicePriority; }
    @JsonProperty("voice_priority")
    public void setVoicePriority(double value) { this.voicePriority = value; }

    @JsonProperty("voice_transpose")
    public Double getVoiceTranspose() { return voiceTranspose; }
    @JsonProperty("voice_transpose")
    public void setVoiceTranspose(Double value) { this.voiceTranspose = value; }

    @JsonProperty("voice_tune")
    public double getVoiceTune() { return voiceTune; }
    @JsonProperty("voice_tune")
    public void setVoiceTune(double value) { this.voiceTune = value; }

    @JsonProperty("volume")
    public double getVolume() { return volume; }
    @JsonProperty("volume")
    public void setVolume(double value) { this.volume = value; }

    @JsonProperty("wavetables")
    public Wavetable[] getWavetables() { return wavetables; }
    @JsonProperty("wavetables")
    public void setWavetables(Wavetable[] value) { this.wavetables = value; }
}

// Lfo.java

package org.vitalsdk.types;

import com.fasterxml.jackson.annotation.*;

public class Lfo {
    private String name;
    private double numPoints;
    private double[] points;
    private double[] powers;
    private boolean smooth;

    @JsonProperty("name")
    public String getName() { return name; }
    @JsonProperty("name")
    public void setName(String value) { this.name = value; }

    @JsonProperty("num_points")
    public double getNumPoints() { return numPoints; }
    @JsonProperty("num_points")
    public void setNumPoints(double value) { this.numPoints = value; }

    @JsonProperty("points")
    public double[] getPoints() { return points; }
    @JsonProperty("points")
    public void setPoints(double[] value) { this.points = value; }

    @JsonProperty("powers")
    public double[] getPowers() { return powers; }
    @JsonProperty("powers")
    public void setPowers(double[] value) { this.powers = value; }

    @JsonProperty("smooth")
    public boolean getSmooth() { return smooth; }
    @JsonProperty("smooth")
    public void setSmooth(boolean value) { this.smooth = value; }
}

// Modulation.java

package org.vitalsdk.types;

import com.fasterxml.jackson.annotation.*;

public class Modulation {
    private String destination;
    private Lfo lineMapping;
    private Source source;

    @JsonProperty("destination")
    public String getDestination() { return destination; }
    @JsonProperty("destination")
    public void setDestination(String value) { this.destination = value; }

    @JsonProperty("line_mapping")
    public Lfo getLineMapping() { return lineMapping; }
    @JsonProperty("line_mapping")
    public void setLineMapping(Lfo value) { this.lineMapping = value; }

    @JsonProperty("source")
    public Source getSource() { return source; }
    @JsonProperty("source")
    public void setSource(Source value) { this.source = value; }
}

// Source.java

package org.vitalsdk.types;

import java.io.IOException;
import com.fasterxml.jackson.annotation.*;

public enum Source {
    AFTERTOUCH, EMPTY, ENV_1, ENV_2, ENV_3, ENV_4, ENV_5, ENV_6, LFO_1, LFO_2, LFO_3, LFO_4, LFO_5, LFO_6, LFO_7, LFO_8, LIFT, MACRO_CONTROL_1, MACRO_CONTROL_2, MACRO_CONTROL_3, MACRO_CONTROL_4, MOD_WHEEL, NOTE, NOTE_IN_OCTAVE, PITCH_WHEEL, RANDOM, RANDOM_1, RANDOM_2, RANDOM_3, RANDOM_4, SLIDE, STEREO, VELOCITY;

    @JsonValue
    public String toValue() {
        switch (this) {
            case AFTERTOUCH: return "aftertouch";
            case EMPTY: return "";
            case ENV_1: return "env_1";
            case ENV_2: return "env_2";
            case ENV_3: return "env_3";
            case ENV_4: return "env_4";
            case ENV_5: return "env_5";
            case ENV_6: return "env_6";
            case LFO_1: return "lfo_1";
            case LFO_2: return "lfo_2";
            case LFO_3: return "lfo_3";
            case LFO_4: return "lfo_4";
            case LFO_5: return "lfo_5";
            case LFO_6: return "lfo_6";
            case LFO_7: return "lfo_7";
            case LFO_8: return "lfo_8";
            case LIFT: return "lift";
            case MACRO_CONTROL_1: return "macro_control_1";
            case MACRO_CONTROL_2: return "macro_control_2";
            case MACRO_CONTROL_3: return "macro_control_3";
            case MACRO_CONTROL_4: return "macro_control_4";
            case MOD_WHEEL: return "mod_wheel";
            case NOTE: return "note";
            case NOTE_IN_OCTAVE: return "note_in_octave";
            case PITCH_WHEEL: return "pitch_wheel";
            case RANDOM: return "random";
            case RANDOM_1: return "random_1";
            case RANDOM_2: return "random_2";
            case RANDOM_3: return "random_3";
            case RANDOM_4: return "random_4";
            case SLIDE: return "slide";
            case STEREO: return "stereo";
            case VELOCITY: return "velocity";
        }
        return null;
    }

    @JsonCreator
    public static Source forValue(String value) throws IOException {
        if (value.equals("aftertouch")) return AFTERTOUCH;
        if (value.equals("")) return EMPTY;
        if (value.equals("env_1")) return ENV_1;
        if (value.equals("env_2")) return ENV_2;
        if (value.equals("env_3")) return ENV_3;
        if (value.equals("env_4")) return ENV_4;
        if (value.equals("env_5")) return ENV_5;
        if (value.equals("env_6")) return ENV_6;
        if (value.equals("lfo_1")) return LFO_1;
        if (value.equals("lfo_2")) return LFO_2;
        if (value.equals("lfo_3")) return LFO_3;
        if (value.equals("lfo_4")) return LFO_4;
        if (value.equals("lfo_5")) return LFO_5;
        if (value.equals("lfo_6")) return LFO_6;
        if (value.equals("lfo_7")) return LFO_7;
        if (value.equals("lfo_8")) return LFO_8;
        if (value.equals("lift")) return LIFT;
        if (value.equals("macro_control_1")) return MACRO_CONTROL_1;
        if (value.equals("macro_control_2")) return MACRO_CONTROL_2;
        if (value.equals("macro_control_3")) return MACRO_CONTROL_3;
        if (value.equals("macro_control_4")) return MACRO_CONTROL_4;
        if (value.equals("mod_wheel")) return MOD_WHEEL;
        if (value.equals("note")) return NOTE;
        if (value.equals("note_in_octave")) return NOTE_IN_OCTAVE;
        if (value.equals("pitch_wheel")) return PITCH_WHEEL;
        if (value.equals("random")) return RANDOM;
        if (value.equals("random_1")) return RANDOM_1;
        if (value.equals("random_2")) return RANDOM_2;
        if (value.equals("random_3")) return RANDOM_3;
        if (value.equals("random_4")) return RANDOM_4;
        if (value.equals("slide")) return SLIDE;
        if (value.equals("stereo")) return STEREO;
        if (value.equals("velocity")) return VELOCITY;
        throw new IOException("Cannot deserialize Source");
    }
}

// Sample.java

package org.vitalsdk.types;

import com.fasterxml.jackson.annotation.*;

public class Sample {
    private double length;
    private String name;
    private double sampleRate;
    private String samples;
    private String samplesStereo;

    @JsonProperty("length")
    public double getLength() { return length; }
    @JsonProperty("length")
    public void setLength(double value) { this.length = value; }

    @JsonProperty("name")
    public String getName() { return name; }
    @JsonProperty("name")
    public void setName(String value) { this.name = value; }

    @JsonProperty("sample_rate")
    public double getSampleRate() { return sampleRate; }
    @JsonProperty("sample_rate")
    public void setSampleRate(double value) { this.sampleRate = value; }

    @JsonProperty("samples")
    public String getSamples() { return samples; }
    @JsonProperty("samples")
    public void setSamples(String value) { this.samples = value; }

    @JsonProperty("samples_stereo")
    public String getSamplesStereo() { return samplesStereo; }
    @JsonProperty("samples_stereo")
    public void setSamplesStereo(String value) { this.samplesStereo = value; }
}

// Wavetable.java

package org.vitalsdk.types;

import com.fasterxml.jackson.annotation.*;

public class Wavetable {
    private String author;
    private boolean fullNormalize;
    private Group[] groups;
    private String name;
    private boolean removeAllDc;
    private String version;

    @JsonProperty("author")
    public String getAuthor() { return author; }
    @JsonProperty("author")
    public void setAuthor(String value) { this.author = value; }

    @JsonProperty("full_normalize")
    public boolean getFullNormalize() { return fullNormalize; }
    @JsonProperty("full_normalize")
    public void setFullNormalize(boolean value) { this.fullNormalize = value; }

    @JsonProperty("groups")
    public Group[] getGroups() { return groups; }
    @JsonProperty("groups")
    public void setGroups(Group[] value) { this.groups = value; }

    @JsonProperty("name")
    public String getName() { return name; }
    @JsonProperty("name")
    public void setName(String value) { this.name = value; }

    @JsonProperty("remove_all_dc")
    public boolean getRemoveAllDc() { return removeAllDc; }
    @JsonProperty("remove_all_dc")
    public void setRemoveAllDc(boolean value) { this.removeAllDc = value; }

    @JsonProperty("version")
    public String getVersion() { return version; }
    @JsonProperty("version")
    public void setVersion(String value) { this.version = value; }
}

// Group.java

package org.vitalsdk.types;

import com.fasterxml.jackson.annotation.*;

public class Group {
    private Component[] components;

    @JsonProperty("components")
    public Component[] getComponents() { return components; }
    @JsonProperty("components")
    public void setComponents(Component[] value) { this.components = value; }
}

// Component.java

package org.vitalsdk.types;

import com.fasterxml.jackson.annotation.*;

public class Component {
    private String audioFile;
    private Double audioSampleRate;
    private Double fadeStyle;
    private Boolean horizontalAsymmetric;
    private Double interpolation;
    private double interpolationStyle;
    private Keyframe[] keyframes;
    private Boolean normalize;
    private Boolean normalizeGain;
    private Boolean normalizeMult;
    private Double numPoints;
    private Double phaseStyle;
    private Double randomSeed;
    private Double style;
    private Type type;
    private Boolean verticalAsymmetric;
    private Double windowShape;
    private Double windowSize;

    @JsonProperty("audio_file")
    public String getAudioFile() { return audioFile; }
    @JsonProperty("audio_file")
    public void setAudioFile(String value) { this.audioFile = value; }

    @JsonProperty("audio_sample_rate")
    public Double getAudioSampleRate() { return audioSampleRate; }
    @JsonProperty("audio_sample_rate")
    public void setAudioSampleRate(Double value) { this.audioSampleRate = value; }

    @JsonProperty("fade_style")
    public Double getFadeStyle() { return fadeStyle; }
    @JsonProperty("fade_style")
    public void setFadeStyle(Double value) { this.fadeStyle = value; }

    @JsonProperty("horizontal_asymmetric")
    public Boolean getHorizontalAsymmetric() { return horizontalAsymmetric; }
    @JsonProperty("horizontal_asymmetric")
    public void setHorizontalAsymmetric(Boolean value) { this.horizontalAsymmetric = value; }

    @JsonProperty("interpolation")
    public Double getInterpolation() { return interpolation; }
    @JsonProperty("interpolation")
    public void setInterpolation(Double value) { this.interpolation = value; }

    @JsonProperty("interpolation_style")
    public double getInterpolationStyle() { return interpolationStyle; }
    @JsonProperty("interpolation_style")
    public void setInterpolationStyle(double value) { this.interpolationStyle = value; }

    @JsonProperty("keyframes")
    public Keyframe[] getKeyframes() { return keyframes; }
    @JsonProperty("keyframes")
    public void setKeyframes(Keyframe[] value) { this.keyframes = value; }

    @JsonProperty("normalize")
    public Boolean getNormalize() { return normalize; }
    @JsonProperty("normalize")
    public void setNormalize(Boolean value) { this.normalize = value; }

    @JsonProperty("normalize_gain")
    public Boolean getNormalizeGain() { return normalizeGain; }
    @JsonProperty("normalize_gain")
    public void setNormalizeGain(Boolean value) { this.normalizeGain = value; }

    @JsonProperty("normalize_mult")
    public Boolean getNormalizeMult() { return normalizeMult; }
    @JsonProperty("normalize_mult")
    public void setNormalizeMult(Boolean value) { this.normalizeMult = value; }

    @JsonProperty("num_points")
    public Double getNumPoints() { return numPoints; }
    @JsonProperty("num_points")
    public void setNumPoints(Double value) { this.numPoints = value; }

    @JsonProperty("phase_style")
    public Double getPhaseStyle() { return phaseStyle; }
    @JsonProperty("phase_style")
    public void setPhaseStyle(Double value) { this.phaseStyle = value; }

    @JsonProperty("random_seed")
    public Double getRandomSeed() { return randomSeed; }
    @JsonProperty("random_seed")
    public void setRandomSeed(Double value) { this.randomSeed = value; }

    @JsonProperty("style")
    public Double getStyle() { return style; }
    @JsonProperty("style")
    public void setStyle(Double value) { this.style = value; }

    @JsonProperty("type")
    public Type getType() { return type; }
    @JsonProperty("type")
    public void setType(Type value) { this.type = value; }

    @JsonProperty("vertical_asymmetric")
    public Boolean getVerticalAsymmetric() { return verticalAsymmetric; }
    @JsonProperty("vertical_asymmetric")
    public void setVerticalAsymmetric(Boolean value) { this.verticalAsymmetric = value; }

    @JsonProperty("window_shape")
    public Double getWindowShape() { return windowShape; }
    @JsonProperty("window_shape")
    public void setWindowShape(Double value) { this.windowShape = value; }

    @JsonProperty("window_size")
    public Double getWindowSize() { return windowSize; }
    @JsonProperty("window_size")
    public void setWindowSize(Double value) { this.windowSize = value; }
}

// Keyframe.java

package org.vitalsdk.types;

import com.fasterxml.jackson.annotation.*;

public class Keyframe {
    private Double cutoff;
    private Double downRunRise;
    private Double foldBoost;
    private Double horizontalPower;
    private Double leftPosition;
    private Lfo line;
    private Double mix;
    private Double phase;
    private double position;
    private Double pullPower;
    private Double rightPosition;
    private Double shape;
    private Double startPosition;
    private Double upRunRise;
    private Double verticalPower;
    private String waveData;
    private Double windowFade;
    private Double windowSize;

    @JsonProperty("cutoff")
    public Double getCutoff() { return cutoff; }
    @JsonProperty("cutoff")
    public void setCutoff(Double value) { this.cutoff = value; }

    @JsonProperty("down_run_rise")
    public Double getDownRunRise() { return downRunRise; }
    @JsonProperty("down_run_rise")
    public void setDownRunRise(Double value) { this.downRunRise = value; }

    @JsonProperty("fold_boost")
    public Double getFoldBoost() { return foldBoost; }
    @JsonProperty("fold_boost")
    public void setFoldBoost(Double value) { this.foldBoost = value; }

    @JsonProperty("horizontal_power")
    public Double getHorizontalPower() { return horizontalPower; }
    @JsonProperty("horizontal_power")
    public void setHorizontalPower(Double value) { this.horizontalPower = value; }

    @JsonProperty("left_position")
    public Double getLeftPosition() { return leftPosition; }
    @JsonProperty("left_position")
    public void setLeftPosition(Double value) { this.leftPosition = value; }

    @JsonProperty("line")
    public Lfo getLine() { return line; }
    @JsonProperty("line")
    public void setLine(Lfo value) { this.line = value; }

    @JsonProperty("mix")
    public Double getMix() { return mix; }
    @JsonProperty("mix")
    public void setMix(Double value) { this.mix = value; }

    @JsonProperty("phase")
    public Double getPhase() { return phase; }
    @JsonProperty("phase")
    public void setPhase(Double value) { this.phase = value; }

    @JsonProperty("position")
    public double getPosition() { return position; }
    @JsonProperty("position")
    public void setPosition(double value) { this.position = value; }

    @JsonProperty("pull_power")
    public Double getPullPower() { return pullPower; }
    @JsonProperty("pull_power")
    public void setPullPower(Double value) { this.pullPower = value; }

    @JsonProperty("right_position")
    public Double getRightPosition() { return rightPosition; }
    @JsonProperty("right_position")
    public void setRightPosition(Double value) { this.rightPosition = value; }

    @JsonProperty("shape")
    public Double getShape() { return shape; }
    @JsonProperty("shape")
    public void setShape(Double value) { this.shape = value; }

    @JsonProperty("start_position")
    public Double getStartPosition() { return startPosition; }
    @JsonProperty("start_position")
    public void setStartPosition(Double value) { this.startPosition = value; }

    @JsonProperty("up_run_rise")
    public Double getUpRunRise() { return upRunRise; }
    @JsonProperty("up_run_rise")
    public void setUpRunRise(Double value) { this.upRunRise = value; }

    @JsonProperty("vertical_power")
    public Double getVerticalPower() { return verticalPower; }
    @JsonProperty("vertical_power")
    public void setVerticalPower(Double value) { this.verticalPower = value; }

    @JsonProperty("wave_data")
    public String getWaveData() { return waveData; }
    @JsonProperty("wave_data")
    public void setWaveData(String value) { this.waveData = value; }

    @JsonProperty("window_fade")
    public Double getWindowFade() { return windowFade; }
    @JsonProperty("window_fade")
    public void setWindowFade(Double value) { this.windowFade = value; }

    @JsonProperty("window_size")
    public Double getWindowSize() { return windowSize; }
    @JsonProperty("window_size")
    public void setWindowSize(Double value) { this.windowSize = value; }
}

// Type.java

package org.vitalsdk.types;

import java.io.IOException;
import com.fasterxml.jackson.annotation.*;

public enum Type {
    AUDIO_FILE_SOURCE, FREQUENCY_FILTER, LINE_SOURCE, PHASE_SHIFT, SHEPARD_TONE_SOURCE, SLEW_LIMITER, WAVE_FOLDER, WAVE_SOURCE, WAVE_WARP, WAVE_WINDOW;

    @JsonValue
    public String toValue() {
        switch (this) {
            case AUDIO_FILE_SOURCE: return "Audio File Source";
            case FREQUENCY_FILTER: return "Frequency Filter";
            case LINE_SOURCE: return "Line Source";
            case PHASE_SHIFT: return "Phase Shift";
            case SHEPARD_TONE_SOURCE: return "Shepard Tone Source";
            case SLEW_LIMITER: return "Slew Limiter";
            case WAVE_FOLDER: return "Wave Folder";
            case WAVE_SOURCE: return "Wave Source";
            case WAVE_WARP: return "Wave Warp";
            case WAVE_WINDOW: return "Wave Window";
        }
        return null;
    }

    @JsonCreator
    public static Type forValue(String value) throws IOException {
        if (value.equals("Audio File Source")) return AUDIO_FILE_SOURCE;
        if (value.equals("Frequency Filter")) return FREQUENCY_FILTER;
        if (value.equals("Line Source")) return LINE_SOURCE;
        if (value.equals("Phase Shift")) return PHASE_SHIFT;
        if (value.equals("Shepard Tone Source")) return SHEPARD_TONE_SOURCE;
        if (value.equals("Slew Limiter")) return SLEW_LIMITER;
        if (value.equals("Wave Folder")) return WAVE_FOLDER;
        if (value.equals("Wave Source")) return WAVE_SOURCE;
        if (value.equals("Wave Warp")) return WAVE_WARP;
        if (value.equals("Wave Window")) return WAVE_WINDOW;
        throw new IOException("Cannot deserialize Type");
    }
}
