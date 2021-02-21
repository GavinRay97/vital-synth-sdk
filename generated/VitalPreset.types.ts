// To parse this data:
//
//   import { Convert, VitalPreset, PresetStyle, PresetSettings, Lfo, Modulation, Source, Sample, Wavetable, Group, Component, Keyframe, Type } from "./file";
//
//   const vitalPreset = Convert.toVitalPreset(json);
//   const presetStyle = Convert.toPresetStyle(json);
//   const presetSettings = Convert.toPresetSettings(json);
//   const lfo = Convert.toLfo(json);
//   const modulation = Convert.toModulation(json);
//   const source = Convert.toSource(json);
//   const sample = Convert.toSample(json);
//   const wavetable = Convert.toWavetable(json);
//   const group = Convert.toGroup(json);
//   const component = Convert.toComponent(json);
//   const keyframe = Convert.toKeyframe(json);
//   const type = Convert.toType(json);
//
// These functions will throw an error if the JSON doesn't
// match the expected interface, even if the JSON is valid.

export interface VitalPreset {
    author:        string;
    comments:      string;
    macro1:        string;
    macro2:        string;
    macro3:        string;
    macro4:        string;
    preset_name?:  string;
    preset_style:  PresetStyle;
    settings:      PresetSettings;
    synth_version: string;
}

export enum PresetStyle {
    Bass = "Bass",
    Empty = "",
    Experiment = "Experiment",
    Keys = "Keys",
    Lead = "Lead",
    Pad = "Pad",
    Percussion = "Percussion",
    Sequence = "Sequence",
    Sfx = "SFX",
    Template = "Template",
}

export interface PresetSettings {
    beats_per_minute:                number;
    bypass?:                         number;
    chorus_cutoff?:                  number;
    chorus_damping?:                 number;
    chorus_delay_1:                  number;
    chorus_delay_2:                  number;
    chorus_dry_wet:                  number;
    chorus_feedback:                 number;
    chorus_frequency:                number;
    chorus_mod_depth:                number;
    chorus_on:                       number;
    chorus_spread?:                  number;
    chorus_sync:                     number;
    chorus_tempo:                    number;
    chorus_voices:                   number;
    compressor_attack:               number;
    compressor_band_gain:            number;
    compressor_band_lower_ratio:     number;
    compressor_band_lower_threshold: number;
    compressor_band_upper_ratio:     number;
    compressor_band_upper_threshold: number;
    compressor_enabled_bands:        number;
    compressor_high_gain:            number;
    compressor_high_lower_ratio:     number;
    compressor_high_lower_threshold: number;
    compressor_high_upper_ratio:     number;
    compressor_high_upper_threshold: number;
    compressor_low_gain:             number;
    compressor_low_lower_ratio:      number;
    compressor_low_lower_threshold:  number;
    compressor_low_upper_ratio:      number;
    compressor_low_upper_threshold:  number;
    compressor_mix?:                 number;
    compressor_on:                   number;
    compressor_release:              number;
    delay_aux_frequency:             number;
    delay_aux_sync:                  number;
    delay_aux_tempo:                 number;
    delay_dry_wet:                   number;
    delay_feedback:                  number;
    delay_filter_cutoff:             number;
    delay_filter_spread:             number;
    delay_frequency:                 number;
    delay_on:                        number;
    delay_style:                     number;
    delay_sync:                      number;
    delay_tempo:                     number;
    distortion_drive:                number;
    distortion_filter_blend:         number;
    distortion_filter_cutoff:        number;
    distortion_filter_order:         number;
    distortion_filter_resonance:     number;
    distortion_mix:                  number;
    distortion_on:                   number;
    distortion_type:                 number;
    effect_chain_order:              number;
    env_1_attack:                    number;
    env_1_attack_power:              number;
    env_1_decay:                     number;
    env_1_decay_power:               number;
    env_1_delay:                     number;
    env_1_hold:                      number;
    env_1_release:                   number;
    env_1_release_power:             number;
    env_1_sustain:                   number;
    env_2_attack:                    number;
    env_2_attack_power:              number;
    env_2_decay:                     number;
    env_2_decay_power:               number;
    env_2_delay:                     number;
    env_2_hold:                      number;
    env_2_release:                   number;
    env_2_release_power:             number;
    env_2_sustain:                   number;
    env_3_attack:                    number;
    env_3_attack_power:              number;
    env_3_decay:                     number;
    env_3_decay_power:               number;
    env_3_delay:                     number;
    env_3_hold:                      number;
    env_3_release:                   number;
    env_3_release_power:             number;
    env_3_sustain:                   number;
    env_4_attack:                    number;
    env_4_attack_power:              number;
    env_4_decay:                     number;
    env_4_decay_power:               number;
    env_4_delay:                     number;
    env_4_hold:                      number;
    env_4_release:                   number;
    env_4_release_power:             number;
    env_4_sustain:                   number;
    env_5_attack:                    number;
    env_5_attack_power:              number;
    env_5_decay:                     number;
    env_5_decay_power:               number;
    env_5_delay:                     number;
    env_5_hold:                      number;
    env_5_release:                   number;
    env_5_release_power:             number;
    env_5_sustain:                   number;
    env_6_attack:                    number;
    env_6_attack_power:              number;
    env_6_decay:                     number;
    env_6_decay_power:               number;
    env_6_delay:                     number;
    env_6_hold:                      number;
    env_6_release:                   number;
    env_6_release_power:             number;
    env_6_sustain:                   number;
    eq_band_cutoff:                  number;
    eq_band_gain:                    number;
    eq_band_mode:                    number;
    eq_band_resonance:               number;
    eq_high_cutoff:                  number;
    eq_high_gain:                    number;
    eq_high_mode:                    number;
    eq_high_resonance:               number;
    eq_low_cutoff:                   number;
    eq_low_gain:                     number;
    eq_low_mode:                     number;
    eq_low_resonance:                number;
    eq_on:                           number;
    filter_1_blend:                  number;
    filter_1_blend_transpose:        number;
    filter_1_cutoff:                 number;
    filter_1_drive:                  number;
    filter_1_filter_input:           number;
    filter_1_formant_resonance:      number;
    filter_1_formant_spread?:        number;
    filter_1_formant_transpose:      number;
    filter_1_formant_x:              number;
    filter_1_formant_y:              number;
    filter_1_keytrack:               number;
    filter_1_mix:                    number;
    filter_1_model:                  number;
    filter_1_on:                     number;
    filter_1_resonance:              number;
    filter_1_style:                  number;
    filter_2_blend:                  number;
    filter_2_blend_transpose:        number;
    filter_2_cutoff:                 number;
    filter_2_drive:                  number;
    filter_2_filter_input:           number;
    filter_2_formant_resonance:      number;
    filter_2_formant_spread?:        number;
    filter_2_formant_transpose:      number;
    filter_2_formant_x:              number;
    filter_2_formant_y:              number;
    filter_2_keytrack:               number;
    filter_2_mix:                    number;
    filter_2_model:                  number;
    filter_2_on:                     number;
    filter_2_resonance:              number;
    filter_2_style:                  number;
    filter_fx_blend:                 number;
    filter_fx_blend_transpose:       number;
    filter_fx_cutoff:                number;
    filter_fx_drive:                 number;
    filter_fx_formant_resonance:     number;
    filter_fx_formant_spread?:       number;
    filter_fx_formant_transpose:     number;
    filter_fx_formant_x:             number;
    filter_fx_formant_y:             number;
    filter_fx_keytrack:              number;
    filter_fx_mix:                   number;
    filter_fx_model:                 number;
    filter_fx_on:                    number;
    filter_fx_resonance:             number;
    filter_fx_style:                 number;
    flanger_center:                  number;
    flanger_dry_wet:                 number;
    flanger_feedback:                number;
    flanger_frequency:               number;
    flanger_mod_depth:               number;
    flanger_on:                      number;
    flanger_phase_offset:            number;
    flanger_sync:                    number;
    flanger_tempo:                   number;
    legato:                          number;
    lfo_1_delay_time:                number;
    lfo_1_fade_time:                 number;
    lfo_1_frequency:                 number;
    lfo_1_keytrack_transpose?:       number;
    lfo_1_keytrack_tune?:            number;
    lfo_1_phase:                     number;
    lfo_1_smooth_mode?:              number;
    lfo_1_smooth_time?:              number;
    lfo_1_stereo:                    number;
    lfo_1_sync:                      number;
    lfo_1_sync_type:                 number;
    lfo_1_tempo:                     number;
    lfo_2_delay_time:                number;
    lfo_2_fade_time:                 number;
    lfo_2_frequency:                 number;
    lfo_2_keytrack_transpose?:       number;
    lfo_2_keytrack_tune?:            number;
    lfo_2_phase:                     number;
    lfo_2_smooth_mode?:              number;
    lfo_2_smooth_time?:              number;
    lfo_2_stereo:                    number;
    lfo_2_sync:                      number;
    lfo_2_sync_type:                 number;
    lfo_2_tempo:                     number;
    lfo_3_delay_time:                number;
    lfo_3_fade_time:                 number;
    lfo_3_frequency:                 number;
    lfo_3_keytrack_transpose?:       number;
    lfo_3_keytrack_tune?:            number;
    lfo_3_phase:                     number;
    lfo_3_smooth_mode?:              number;
    lfo_3_smooth_time?:              number;
    lfo_3_stereo:                    number;
    lfo_3_sync:                      number;
    lfo_3_sync_type:                 number;
    lfo_3_tempo:                     number;
    lfo_4_delay_time:                number;
    lfo_4_fade_time:                 number;
    lfo_4_frequency:                 number;
    lfo_4_keytrack_transpose?:       number;
    lfo_4_keytrack_tune?:            number;
    lfo_4_phase:                     number;
    lfo_4_smooth_mode?:              number;
    lfo_4_smooth_time?:              number;
    lfo_4_stereo:                    number;
    lfo_4_sync:                      number;
    lfo_4_sync_type:                 number;
    lfo_4_tempo:                     number;
    lfo_5_delay_time:                number;
    lfo_5_fade_time:                 number;
    lfo_5_frequency:                 number;
    lfo_5_keytrack_transpose?:       number;
    lfo_5_keytrack_tune?:            number;
    lfo_5_phase:                     number;
    lfo_5_smooth_mode?:              number;
    lfo_5_smooth_time?:              number;
    lfo_5_stereo:                    number;
    lfo_5_sync:                      number;
    lfo_5_sync_type:                 number;
    lfo_5_tempo:                     number;
    lfo_6_delay_time:                number;
    lfo_6_fade_time:                 number;
    lfo_6_frequency:                 number;
    lfo_6_keytrack_transpose?:       number;
    lfo_6_keytrack_tune?:            number;
    lfo_6_phase:                     number;
    lfo_6_smooth_mode?:              number;
    lfo_6_smooth_time?:              number;
    lfo_6_stereo:                    number;
    lfo_6_sync:                      number;
    lfo_6_sync_type:                 number;
    lfo_6_tempo:                     number;
    lfo_7_delay_time:                number;
    lfo_7_fade_time:                 number;
    lfo_7_frequency:                 number;
    lfo_7_keytrack_transpose?:       number;
    lfo_7_keytrack_tune?:            number;
    lfo_7_phase:                     number;
    lfo_7_smooth_mode?:              number;
    lfo_7_smooth_time?:              number;
    lfo_7_stereo:                    number;
    lfo_7_sync:                      number;
    lfo_7_sync_type:                 number;
    lfo_7_tempo:                     number;
    lfo_8_delay_time:                number;
    lfo_8_fade_time:                 number;
    lfo_8_frequency:                 number;
    lfo_8_keytrack_transpose?:       number;
    lfo_8_keytrack_tune?:            number;
    lfo_8_phase:                     number;
    lfo_8_smooth_mode?:              number;
    lfo_8_smooth_time?:              number;
    lfo_8_stereo:                    number;
    lfo_8_sync:                      number;
    lfo_8_sync_type:                 number;
    lfo_8_tempo:                     number;
    lfos:                            Lfo[];
    macro_control_1:                 number;
    macro_control_2:                 number;
    macro_control_3:                 number;
    macro_control_4:                 number;
    mod_wheel:                       number;
    modulation_10_amount:            number;
    modulation_10_bipolar:           number;
    modulation_10_bypass:            number;
    modulation_10_power:             number;
    modulation_10_stereo:            number;
    modulation_11_amount:            number;
    modulation_11_bipolar:           number;
    modulation_11_bypass:            number;
    modulation_11_power:             number;
    modulation_11_stereo:            number;
    modulation_12_amount:            number;
    modulation_12_bipolar:           number;
    modulation_12_bypass:            number;
    modulation_12_power:             number;
    modulation_12_stereo:            number;
    modulation_13_amount:            number;
    modulation_13_bipolar:           number;
    modulation_13_bypass:            number;
    modulation_13_power:             number;
    modulation_13_stereo:            number;
    modulation_14_amount:            number;
    modulation_14_bipolar:           number;
    modulation_14_bypass:            number;
    modulation_14_power:             number;
    modulation_14_stereo:            number;
    modulation_15_amount:            number;
    modulation_15_bipolar:           number;
    modulation_15_bypass:            number;
    modulation_15_power:             number;
    modulation_15_stereo:            number;
    modulation_16_amount:            number;
    modulation_16_bipolar:           number;
    modulation_16_bypass:            number;
    modulation_16_power:             number;
    modulation_16_stereo:            number;
    modulation_17_amount:            number;
    modulation_17_bipolar:           number;
    modulation_17_bypass:            number;
    modulation_17_power:             number;
    modulation_17_stereo:            number;
    modulation_18_amount:            number;
    modulation_18_bipolar:           number;
    modulation_18_bypass:            number;
    modulation_18_power:             number;
    modulation_18_stereo:            number;
    modulation_19_amount:            number;
    modulation_19_bipolar:           number;
    modulation_19_bypass:            number;
    modulation_19_power:             number;
    modulation_19_stereo:            number;
    modulation_1_amount:             number;
    modulation_1_bipolar:            number;
    modulation_1_bypass:             number;
    modulation_1_power:              number;
    modulation_1_stereo:             number;
    modulation_20_amount:            number;
    modulation_20_bipolar:           number;
    modulation_20_bypass:            number;
    modulation_20_power:             number;
    modulation_20_stereo:            number;
    modulation_21_amount:            number;
    modulation_21_bipolar:           number;
    modulation_21_bypass:            number;
    modulation_21_power:             number;
    modulation_21_stereo:            number;
    modulation_22_amount:            number;
    modulation_22_bipolar:           number;
    modulation_22_bypass:            number;
    modulation_22_power:             number;
    modulation_22_stereo:            number;
    modulation_23_amount:            number;
    modulation_23_bipolar:           number;
    modulation_23_bypass:            number;
    modulation_23_power:             number;
    modulation_23_stereo:            number;
    modulation_24_amount:            number;
    modulation_24_bipolar:           number;
    modulation_24_bypass:            number;
    modulation_24_power:             number;
    modulation_24_stereo:            number;
    modulation_25_amount:            number;
    modulation_25_bipolar:           number;
    modulation_25_bypass:            number;
    modulation_25_power:             number;
    modulation_25_stereo:            number;
    modulation_26_amount:            number;
    modulation_26_bipolar:           number;
    modulation_26_bypass:            number;
    modulation_26_power:             number;
    modulation_26_stereo:            number;
    modulation_27_amount:            number;
    modulation_27_bipolar:           number;
    modulation_27_bypass:            number;
    modulation_27_power:             number;
    modulation_27_stereo:            number;
    modulation_28_amount:            number;
    modulation_28_bipolar:           number;
    modulation_28_bypass:            number;
    modulation_28_power:             number;
    modulation_28_stereo:            number;
    modulation_29_amount:            number;
    modulation_29_bipolar:           number;
    modulation_29_bypass:            number;
    modulation_29_power:             number;
    modulation_29_stereo:            number;
    modulation_2_amount:             number;
    modulation_2_bipolar:            number;
    modulation_2_bypass:             number;
    modulation_2_power:              number;
    modulation_2_stereo:             number;
    modulation_30_amount:            number;
    modulation_30_bipolar:           number;
    modulation_30_bypass:            number;
    modulation_30_power:             number;
    modulation_30_stereo:            number;
    modulation_31_amount:            number;
    modulation_31_bipolar:           number;
    modulation_31_bypass:            number;
    modulation_31_power:             number;
    modulation_31_stereo:            number;
    modulation_32_amount:            number;
    modulation_32_bipolar:           number;
    modulation_32_bypass:            number;
    modulation_32_power:             number;
    modulation_32_stereo:            number;
    modulation_33_amount:            number;
    modulation_33_bipolar:           number;
    modulation_33_bypass:            number;
    modulation_33_power:             number;
    modulation_33_stereo:            number;
    modulation_34_amount:            number;
    modulation_34_bipolar:           number;
    modulation_34_bypass:            number;
    modulation_34_power:             number;
    modulation_34_stereo:            number;
    modulation_35_amount:            number;
    modulation_35_bipolar:           number;
    modulation_35_bypass:            number;
    modulation_35_power:             number;
    modulation_35_stereo:            number;
    modulation_36_amount:            number;
    modulation_36_bipolar:           number;
    modulation_36_bypass:            number;
    modulation_36_power:             number;
    modulation_36_stereo:            number;
    modulation_37_amount:            number;
    modulation_37_bipolar:           number;
    modulation_37_bypass:            number;
    modulation_37_power:             number;
    modulation_37_stereo:            number;
    modulation_38_amount:            number;
    modulation_38_bipolar:           number;
    modulation_38_bypass:            number;
    modulation_38_power:             number;
    modulation_38_stereo:            number;
    modulation_39_amount:            number;
    modulation_39_bipolar:           number;
    modulation_39_bypass:            number;
    modulation_39_power:             number;
    modulation_39_stereo:            number;
    modulation_3_amount:             number;
    modulation_3_bipolar:            number;
    modulation_3_bypass:             number;
    modulation_3_power:              number;
    modulation_3_stereo:             number;
    modulation_40_amount:            number;
    modulation_40_bipolar:           number;
    modulation_40_bypass:            number;
    modulation_40_power:             number;
    modulation_40_stereo:            number;
    modulation_41_amount:            number;
    modulation_41_bipolar:           number;
    modulation_41_bypass:            number;
    modulation_41_power:             number;
    modulation_41_stereo:            number;
    modulation_42_amount:            number;
    modulation_42_bipolar:           number;
    modulation_42_bypass:            number;
    modulation_42_power:             number;
    modulation_42_stereo:            number;
    modulation_43_amount:            number;
    modulation_43_bipolar:           number;
    modulation_43_bypass:            number;
    modulation_43_power:             number;
    modulation_43_stereo:            number;
    modulation_44_amount:            number;
    modulation_44_bipolar:           number;
    modulation_44_bypass:            number;
    modulation_44_power:             number;
    modulation_44_stereo:            number;
    modulation_45_amount:            number;
    modulation_45_bipolar:           number;
    modulation_45_bypass:            number;
    modulation_45_power:             number;
    modulation_45_stereo:            number;
    modulation_46_amount:            number;
    modulation_46_bipolar:           number;
    modulation_46_bypass:            number;
    modulation_46_power:             number;
    modulation_46_stereo:            number;
    modulation_47_amount:            number;
    modulation_47_bipolar:           number;
    modulation_47_bypass:            number;
    modulation_47_power:             number;
    modulation_47_stereo:            number;
    modulation_48_amount:            number;
    modulation_48_bipolar:           number;
    modulation_48_bypass:            number;
    modulation_48_power:             number;
    modulation_48_stereo:            number;
    modulation_49_amount:            number;
    modulation_49_bipolar:           number;
    modulation_49_bypass:            number;
    modulation_49_power:             number;
    modulation_49_stereo:            number;
    modulation_4_amount:             number;
    modulation_4_bipolar:            number;
    modulation_4_bypass:             number;
    modulation_4_power:              number;
    modulation_4_stereo:             number;
    modulation_50_amount:            number;
    modulation_50_bipolar:           number;
    modulation_50_bypass:            number;
    modulation_50_power:             number;
    modulation_50_stereo:            number;
    modulation_51_amount:            number;
    modulation_51_bipolar:           number;
    modulation_51_bypass:            number;
    modulation_51_power:             number;
    modulation_51_stereo:            number;
    modulation_52_amount:            number;
    modulation_52_bipolar:           number;
    modulation_52_bypass:            number;
    modulation_52_power:             number;
    modulation_52_stereo:            number;
    modulation_53_amount:            number;
    modulation_53_bipolar:           number;
    modulation_53_bypass:            number;
    modulation_53_power:             number;
    modulation_53_stereo:            number;
    modulation_54_amount:            number;
    modulation_54_bipolar:           number;
    modulation_54_bypass:            number;
    modulation_54_power:             number;
    modulation_54_stereo:            number;
    modulation_55_amount:            number;
    modulation_55_bipolar:           number;
    modulation_55_bypass:            number;
    modulation_55_power:             number;
    modulation_55_stereo:            number;
    modulation_56_amount:            number;
    modulation_56_bipolar:           number;
    modulation_56_bypass:            number;
    modulation_56_power:             number;
    modulation_56_stereo:            number;
    modulation_57_amount:            number;
    modulation_57_bipolar:           number;
    modulation_57_bypass:            number;
    modulation_57_power:             number;
    modulation_57_stereo:            number;
    modulation_58_amount:            number;
    modulation_58_bipolar:           number;
    modulation_58_bypass:            number;
    modulation_58_power:             number;
    modulation_58_stereo:            number;
    modulation_59_amount:            number;
    modulation_59_bipolar:           number;
    modulation_59_bypass:            number;
    modulation_59_power:             number;
    modulation_59_stereo:            number;
    modulation_5_amount:             number;
    modulation_5_bipolar:            number;
    modulation_5_bypass:             number;
    modulation_5_power:              number;
    modulation_5_stereo:             number;
    modulation_60_amount:            number;
    modulation_60_bipolar:           number;
    modulation_60_bypass:            number;
    modulation_60_power:             number;
    modulation_60_stereo:            number;
    modulation_61_amount:            number;
    modulation_61_bipolar:           number;
    modulation_61_bypass:            number;
    modulation_61_power:             number;
    modulation_61_stereo:            number;
    modulation_62_amount:            number;
    modulation_62_bipolar:           number;
    modulation_62_bypass:            number;
    modulation_62_power:             number;
    modulation_62_stereo:            number;
    modulation_63_amount:            number;
    modulation_63_bipolar:           number;
    modulation_63_bypass:            number;
    modulation_63_power:             number;
    modulation_63_stereo:            number;
    modulation_64_amount:            number;
    modulation_64_bipolar:           number;
    modulation_64_bypass:            number;
    modulation_64_power:             number;
    modulation_64_stereo:            number;
    modulation_6_amount:             number;
    modulation_6_bipolar:            number;
    modulation_6_bypass:             number;
    modulation_6_power:              number;
    modulation_6_stereo:             number;
    modulation_7_amount:             number;
    modulation_7_bipolar:            number;
    modulation_7_bypass:             number;
    modulation_7_power:              number;
    modulation_7_stereo:             number;
    modulation_8_amount:             number;
    modulation_8_bipolar:            number;
    modulation_8_bypass:             number;
    modulation_8_power:              number;
    modulation_8_stereo:             number;
    modulation_9_amount:             number;
    modulation_9_bipolar:            number;
    modulation_9_bypass:             number;
    modulation_9_power:              number;
    modulation_9_stereo:             number;
    modulations:                     Modulation[];
    osc_1_destination:               number;
    osc_1_detune_power:              number;
    osc_1_detune_range:              number;
    osc_1_distortion_amount:         number;
    osc_1_distortion_phase:          number;
    osc_1_distortion_spread:         number;
    osc_1_distortion_type:           number;
    osc_1_frame_spread:              number;
    osc_1_level:                     number;
    osc_1_midi_track:                number;
    osc_1_on:                        number;
    osc_1_pan:                       number;
    osc_1_phase:                     number;
    osc_1_random_phase:              number;
    osc_1_smooth_interpolation:      number;
    osc_1_spectral_morph_amount:     number;
    osc_1_spectral_morph_spread:     number;
    osc_1_spectral_morph_type:       number;
    osc_1_spectral_unison:           number;
    osc_1_stack_style:               number;
    osc_1_stereo_spread:             number;
    osc_1_transpose:                 number;
    osc_1_transpose_quantize:        number;
    osc_1_tune:                      number;
    osc_1_unison_blend:              number;
    osc_1_unison_detune:             number;
    osc_1_unison_voices:             number;
    osc_1_view_2d:                   number;
    osc_1_wave_frame:                number;
    osc_2_destination:               number;
    osc_2_detune_power:              number;
    osc_2_detune_range:              number;
    osc_2_distortion_amount:         number;
    osc_2_distortion_phase:          number;
    osc_2_distortion_spread:         number;
    osc_2_distortion_type:           number;
    osc_2_frame_spread:              number;
    osc_2_level:                     number;
    osc_2_midi_track:                number;
    osc_2_on:                        number;
    osc_2_pan:                       number;
    osc_2_phase:                     number;
    osc_2_random_phase:              number;
    osc_2_smooth_interpolation:      number;
    osc_2_spectral_morph_amount:     number;
    osc_2_spectral_morph_spread:     number;
    osc_2_spectral_morph_type:       number;
    osc_2_spectral_unison:           number;
    osc_2_stack_style:               number;
    osc_2_stereo_spread:             number;
    osc_2_transpose:                 number;
    osc_2_transpose_quantize:        number;
    osc_2_tune:                      number;
    osc_2_unison_blend:              number;
    osc_2_unison_detune:             number;
    osc_2_unison_voices:             number;
    osc_2_view_2d:                   number;
    osc_2_wave_frame:                number;
    osc_3_destination:               number;
    osc_3_detune_power:              number;
    osc_3_detune_range:              number;
    osc_3_distortion_amount:         number;
    osc_3_distortion_phase:          number;
    osc_3_distortion_spread:         number;
    osc_3_distortion_type:           number;
    osc_3_frame_spread:              number;
    osc_3_level:                     number;
    osc_3_midi_track:                number;
    osc_3_on:                        number;
    osc_3_pan:                       number;
    osc_3_phase:                     number;
    osc_3_random_phase:              number;
    osc_3_smooth_interpolation:      number;
    osc_3_spectral_morph_amount:     number;
    osc_3_spectral_morph_spread:     number;
    osc_3_spectral_morph_type:       number;
    osc_3_spectral_unison:           number;
    osc_3_stack_style:               number;
    osc_3_stereo_spread:             number;
    osc_3_transpose:                 number;
    osc_3_transpose_quantize:        number;
    osc_3_tune:                      number;
    osc_3_unison_blend:              number;
    osc_3_unison_detune:             number;
    osc_3_unison_voices:             number;
    osc_3_view_2d:                   number;
    osc_3_wave_frame:                number;
    oversampling:                    number;
    phaser_blend:                    number;
    phaser_center:                   number;
    phaser_dry_wet:                  number;
    phaser_feedback:                 number;
    phaser_frequency:                number;
    phaser_mod_depth:                number;
    phaser_on:                       number;
    phaser_phase_offset:             number;
    phaser_sync:                     number;
    phaser_tempo:                    number;
    pitch_bend_range:                number;
    pitch_wheel:                     number;
    polyphony:                       number;
    portamento_force:                number;
    portamento_scale:                number;
    portamento_slope:                number;
    portamento_time:                 number;
    random_1_frequency:              number;
    random_1_keytrack_transpose?:    number;
    random_1_keytrack_tune?:         number;
    random_1_stereo:                 number;
    random_1_style:                  number;
    random_1_sync:                   number;
    random_1_sync_type:              number;
    random_1_tempo:                  number;
    random_2_frequency:              number;
    random_2_keytrack_transpose?:    number;
    random_2_keytrack_tune?:         number;
    random_2_stereo:                 number;
    random_2_style:                  number;
    random_2_sync:                   number;
    random_2_sync_type:              number;
    random_2_tempo:                  number;
    random_3_frequency:              number;
    random_3_keytrack_transpose?:    number;
    random_3_keytrack_tune?:         number;
    random_3_stereo:                 number;
    random_3_style:                  number;
    random_3_sync:                   number;
    random_3_sync_type:              number;
    random_3_tempo:                  number;
    random_4_frequency:              number;
    random_4_keytrack_transpose?:    number;
    random_4_keytrack_tune?:         number;
    random_4_stereo:                 number;
    random_4_style:                  number;
    random_4_sync:                   number;
    random_4_sync_type:              number;
    random_4_tempo:                  number;
    reverb_chorus_amount:            number;
    reverb_chorus_frequency:         number;
    reverb_decay_time:               number;
    reverb_delay?:                   number;
    reverb_dry_wet:                  number;
    reverb_high_shelf_cutoff:        number;
    reverb_high_shelf_gain:          number;
    reverb_low_shelf_cutoff:         number;
    reverb_low_shelf_gain:           number;
    reverb_on:                       number;
    reverb_pre_high_cutoff:          number;
    reverb_pre_low_cutoff:           number;
    reverb_size:                     number;
    sample:                          Sample;
    sample_bounce?:                  number;
    sample_destination:              number;
    sample_keytrack:                 number;
    sample_level:                    number;
    sample_loop:                     number;
    sample_on:                       number;
    sample_pan:                      number;
    sample_random_phase:             number;
    sample_transpose:                number;
    sample_transpose_quantize:       number;
    sample_tune:                     number;
    stereo_mode?:                    number;
    stereo_routing:                  number;
    velocity_track:                  number;
    view_spectrogram?:               number;
    voice_amplitude:                 number;
    voice_override?:                 number;
    voice_priority:                  number;
    voice_transpose?:                number;
    voice_tune:                      number;
    volume:                          number;
    wavetables:                      Wavetable[];
}

export interface Lfo {
    name:       string;
    num_points: number;
    points:     number[];
    powers:     number[];
    smooth:     boolean;
}

export interface Modulation {
    destination:   string;
    line_mapping?: Lfo;
    source:        Source;
}

export enum Source {
    Aftertouch = "aftertouch",
    Empty = "",
    Env1 = "env_1",
    Env2 = "env_2",
    Env3 = "env_3",
    Env4 = "env_4",
    Env5 = "env_5",
    Env6 = "env_6",
    Lfo1 = "lfo_1",
    Lfo2 = "lfo_2",
    Lfo3 = "lfo_3",
    Lfo4 = "lfo_4",
    Lfo5 = "lfo_5",
    Lfo6 = "lfo_6",
    Lfo7 = "lfo_7",
    Lfo8 = "lfo_8",
    Lift = "lift",
    MacroControl1 = "macro_control_1",
    MacroControl2 = "macro_control_2",
    MacroControl3 = "macro_control_3",
    MacroControl4 = "macro_control_4",
    ModWheel = "mod_wheel",
    Note = "note",
    NoteInOctave = "note_in_octave",
    PitchWheel = "pitch_wheel",
    Random = "random",
    Random1 = "random_1",
    Random2 = "random_2",
    Random3 = "random_3",
    Random4 = "random_4",
    Slide = "slide",
    Stereo = "stereo",
    Velocity = "velocity",
}

export interface Sample {
    length:          number;
    name:            string;
    sample_rate:     number;
    samples:         string;
    samples_stereo?: string;
}

export interface Wavetable {
    author?:        string;
    full_normalize: boolean;
    groups:         Group[];
    name:           string;
    remove_all_dc:  boolean;
    version:        string;
}

export interface Group {
    components: Component[];
}

export interface Component {
    audio_file?:            string;
    audio_sample_rate?:     number;
    fade_style?:            number;
    horizontal_asymmetric?: boolean;
    interpolation?:         number;
    interpolation_style:    number;
    keyframes:              Keyframe[] | null;
    normalize?:             boolean;
    normalize_gain?:        boolean;
    normalize_mult?:        boolean;
    num_points?:            number;
    phase_style?:           number;
    random_seed?:           number;
    style?:                 number;
    type:                   Type;
    vertical_asymmetric?:   boolean;
    window_shape?:          number;
    window_size?:           number;
}

export interface Keyframe {
    cutoff?:           number;
    down_run_rise?:    number;
    fold_boost?:       number;
    horizontal_power?: number;
    left_position?:    number;
    line?:             Lfo;
    mix?:              number;
    phase?:            number;
    position:          number;
    pull_power?:       number;
    right_position?:   number;
    shape?:            number;
    start_position?:   number;
    up_run_rise?:      number;
    vertical_power?:   number;
    wave_data?:        string;
    window_fade?:      number;
    window_size?:      number;
}

export enum Type {
    AudioFileSource = "Audio File Source",
    FrequencyFilter = "Frequency Filter",
    LineSource = "Line Source",
    PhaseShift = "Phase Shift",
    ShepardToneSource = "Shepard Tone Source",
    SlewLimiter = "Slew Limiter",
    WaveFolder = "Wave Folder",
    WaveSource = "Wave Source",
    WaveWarp = "Wave Warp",
    WaveWindow = "Wave Window",
}

// Converts JSON strings to/from your types
// and asserts the results of JSON.parse at runtime
export class Convert {
    public static toVitalPreset(json: string): VitalPreset {
        return cast(JSON.parse(json), r("VitalPreset"));
    }

    public static vitalPresetToJson(value: VitalPreset): string {
        return JSON.stringify(uncast(value, r("VitalPreset")), null, 2);
    }

    public static toPresetStyle(json: string): PresetStyle {
        return cast(JSON.parse(json), r("PresetStyle"));
    }

    public static presetStyleToJson(value: PresetStyle): string {
        return JSON.stringify(uncast(value, r("PresetStyle")), null, 2);
    }

    public static toPresetSettings(json: string): PresetSettings {
        return cast(JSON.parse(json), r("PresetSettings"));
    }

    public static presetSettingsToJson(value: PresetSettings): string {
        return JSON.stringify(uncast(value, r("PresetSettings")), null, 2);
    }

    public static toLfo(json: string): Lfo {
        return cast(JSON.parse(json), r("Lfo"));
    }

    public static lfoToJson(value: Lfo): string {
        return JSON.stringify(uncast(value, r("Lfo")), null, 2);
    }

    public static toModulation(json: string): Modulation {
        return cast(JSON.parse(json), r("Modulation"));
    }

    public static modulationToJson(value: Modulation): string {
        return JSON.stringify(uncast(value, r("Modulation")), null, 2);
    }

    public static toSource(json: string): Source {
        return cast(JSON.parse(json), r("Source"));
    }

    public static sourceToJson(value: Source): string {
        return JSON.stringify(uncast(value, r("Source")), null, 2);
    }

    public static toSample(json: string): Sample {
        return cast(JSON.parse(json), r("Sample"));
    }

    public static sampleToJson(value: Sample): string {
        return JSON.stringify(uncast(value, r("Sample")), null, 2);
    }

    public static toWavetable(json: string): Wavetable {
        return cast(JSON.parse(json), r("Wavetable"));
    }

    public static wavetableToJson(value: Wavetable): string {
        return JSON.stringify(uncast(value, r("Wavetable")), null, 2);
    }

    public static toGroup(json: string): Group {
        return cast(JSON.parse(json), r("Group"));
    }

    public static groupToJson(value: Group): string {
        return JSON.stringify(uncast(value, r("Group")), null, 2);
    }

    public static toComponent(json: string): Component {
        return cast(JSON.parse(json), r("Component"));
    }

    public static componentToJson(value: Component): string {
        return JSON.stringify(uncast(value, r("Component")), null, 2);
    }

    public static toKeyframe(json: string): Keyframe {
        return cast(JSON.parse(json), r("Keyframe"));
    }

    public static keyframeToJson(value: Keyframe): string {
        return JSON.stringify(uncast(value, r("Keyframe")), null, 2);
    }

    public static toType(json: string): Type {
        return cast(JSON.parse(json), r("Type"));
    }

    public static typeToJson(value: Type): string {
        return JSON.stringify(uncast(value, r("Type")), null, 2);
    }
}

function invalidValue(typ: any, val: any, key: any = ''): never {
    if (key) {
        throw Error(`Invalid value for key "${key}". Expected type ${JSON.stringify(typ)} but got ${JSON.stringify(val)}`);
    }
    throw Error(`Invalid value ${JSON.stringify(val)} for type ${JSON.stringify(typ)}`, );
}

function jsonToJSProps(typ: any): any {
    if (typ.jsonToJS === undefined) {
        const map: any = {};
        typ.props.forEach((p: any) => map[p.json] = { key: p.js, typ: p.typ });
        typ.jsonToJS = map;
    }
    return typ.jsonToJS;
}

function jsToJSONProps(typ: any): any {
    if (typ.jsToJSON === undefined) {
        const map: any = {};
        typ.props.forEach((p: any) => map[p.js] = { key: p.json, typ: p.typ });
        typ.jsToJSON = map;
    }
    return typ.jsToJSON;
}

function transform(val: any, typ: any, getProps: any, key: any = ''): any {
    function transformPrimitive(typ: string, val: any): any {
        if (typeof typ === typeof val) return val;
        return invalidValue(typ, val, key);
    }

    function transformUnion(typs: any[], val: any): any {
        // val must validate against one typ in typs
        const l = typs.length;
        for (let i = 0; i < l; i++) {
            const typ = typs[i];
            try {
                return transform(val, typ, getProps);
            } catch (_) {}
        }
        return invalidValue(typs, val);
    }

    function transformEnum(cases: string[], val: any): any {
        if (cases.indexOf(val) !== -1) return val;
        return invalidValue(cases, val);
    }

    function transformArray(typ: any, val: any): any {
        // val must be an array with no invalid elements
        if (!Array.isArray(val)) return invalidValue("array", val);
        return val.map(el => transform(el, typ, getProps));
    }

    function transformDate(val: any): any {
        if (val === null) {
            return null;
        }
        const d = new Date(val);
        if (isNaN(d.valueOf())) {
            return invalidValue("Date", val);
        }
        return d;
    }

    function transformObject(props: { [k: string]: any }, additional: any, val: any): any {
        if (val === null || typeof val !== "object" || Array.isArray(val)) {
            return invalidValue("object", val);
        }
        const result: any = {};
        Object.getOwnPropertyNames(props).forEach(key => {
            const prop = props[key];
            const v = Object.prototype.hasOwnProperty.call(val, key) ? val[key] : undefined;
            result[prop.key] = transform(v, prop.typ, getProps, prop.key);
        });
        Object.getOwnPropertyNames(val).forEach(key => {
            if (!Object.prototype.hasOwnProperty.call(props, key)) {
                result[key] = transform(val[key], additional, getProps, key);
            }
        });
        return result;
    }

    if (typ === "any") return val;
    if (typ === null) {
        if (val === null) return val;
        return invalidValue(typ, val);
    }
    if (typ === false) return invalidValue(typ, val);
    while (typeof typ === "object" && typ.ref !== undefined) {
        typ = typeMap[typ.ref];
    }
    if (Array.isArray(typ)) return transformEnum(typ, val);
    if (typeof typ === "object") {
        return typ.hasOwnProperty("unionMembers") ? transformUnion(typ.unionMembers, val)
            : typ.hasOwnProperty("arrayItems")    ? transformArray(typ.arrayItems, val)
            : typ.hasOwnProperty("props")         ? transformObject(getProps(typ), typ.additional, val)
            : invalidValue(typ, val);
    }
    // Numbers can be parsed by Date but shouldn't be.
    if (typ === Date && typeof val !== "number") return transformDate(val);
    return transformPrimitive(typ, val);
}

function cast<T>(val: any, typ: any): T {
    return transform(val, typ, jsonToJSProps);
}

function uncast<T>(val: T, typ: any): any {
    return transform(val, typ, jsToJSONProps);
}

function a(typ: any) {
    return { arrayItems: typ };
}

function u(...typs: any[]) {
    return { unionMembers: typs };
}

function o(props: any[], additional: any) {
    return { props, additional };
}

function m(additional: any) {
    return { props: [], additional };
}

function r(name: string) {
    return { ref: name };
}

const typeMap: any = {
    "VitalPreset": o([
        { json: "author", js: "author", typ: "" },
        { json: "comments", js: "comments", typ: "" },
        { json: "macro1", js: "macro1", typ: "" },
        { json: "macro2", js: "macro2", typ: "" },
        { json: "macro3", js: "macro3", typ: "" },
        { json: "macro4", js: "macro4", typ: "" },
        { json: "preset_name", js: "preset_name", typ: u(undefined, "") },
        { json: "preset_style", js: "preset_style", typ: r("PresetStyle") },
        { json: "settings", js: "settings", typ: r("PresetSettings") },
        { json: "synth_version", js: "synth_version", typ: "" },
    ], "any"),
    "PresetSettings": o([
        { json: "beats_per_minute", js: "beats_per_minute", typ: 3.14 },
        { json: "bypass", js: "bypass", typ: u(undefined, 3.14) },
        { json: "chorus_cutoff", js: "chorus_cutoff", typ: u(undefined, 3.14) },
        { json: "chorus_damping", js: "chorus_damping", typ: u(undefined, 3.14) },
        { json: "chorus_delay_1", js: "chorus_delay_1", typ: 3.14 },
        { json: "chorus_delay_2", js: "chorus_delay_2", typ: 3.14 },
        { json: "chorus_dry_wet", js: "chorus_dry_wet", typ: 3.14 },
        { json: "chorus_feedback", js: "chorus_feedback", typ: 3.14 },
        { json: "chorus_frequency", js: "chorus_frequency", typ: 3.14 },
        { json: "chorus_mod_depth", js: "chorus_mod_depth", typ: 3.14 },
        { json: "chorus_on", js: "chorus_on", typ: 3.14 },
        { json: "chorus_spread", js: "chorus_spread", typ: u(undefined, 3.14) },
        { json: "chorus_sync", js: "chorus_sync", typ: 3.14 },
        { json: "chorus_tempo", js: "chorus_tempo", typ: 3.14 },
        { json: "chorus_voices", js: "chorus_voices", typ: 3.14 },
        { json: "compressor_attack", js: "compressor_attack", typ: 3.14 },
        { json: "compressor_band_gain", js: "compressor_band_gain", typ: 3.14 },
        { json: "compressor_band_lower_ratio", js: "compressor_band_lower_ratio", typ: 3.14 },
        { json: "compressor_band_lower_threshold", js: "compressor_band_lower_threshold", typ: 3.14 },
        { json: "compressor_band_upper_ratio", js: "compressor_band_upper_ratio", typ: 3.14 },
        { json: "compressor_band_upper_threshold", js: "compressor_band_upper_threshold", typ: 3.14 },
        { json: "compressor_enabled_bands", js: "compressor_enabled_bands", typ: 3.14 },
        { json: "compressor_high_gain", js: "compressor_high_gain", typ: 3.14 },
        { json: "compressor_high_lower_ratio", js: "compressor_high_lower_ratio", typ: 3.14 },
        { json: "compressor_high_lower_threshold", js: "compressor_high_lower_threshold", typ: 3.14 },
        { json: "compressor_high_upper_ratio", js: "compressor_high_upper_ratio", typ: 3.14 },
        { json: "compressor_high_upper_threshold", js: "compressor_high_upper_threshold", typ: 3.14 },
        { json: "compressor_low_gain", js: "compressor_low_gain", typ: 3.14 },
        { json: "compressor_low_lower_ratio", js: "compressor_low_lower_ratio", typ: 3.14 },
        { json: "compressor_low_lower_threshold", js: "compressor_low_lower_threshold", typ: 3.14 },
        { json: "compressor_low_upper_ratio", js: "compressor_low_upper_ratio", typ: 3.14 },
        { json: "compressor_low_upper_threshold", js: "compressor_low_upper_threshold", typ: 3.14 },
        { json: "compressor_mix", js: "compressor_mix", typ: u(undefined, 3.14) },
        { json: "compressor_on", js: "compressor_on", typ: 3.14 },
        { json: "compressor_release", js: "compressor_release", typ: 3.14 },
        { json: "delay_aux_frequency", js: "delay_aux_frequency", typ: 3.14 },
        { json: "delay_aux_sync", js: "delay_aux_sync", typ: 3.14 },
        { json: "delay_aux_tempo", js: "delay_aux_tempo", typ: 3.14 },
        { json: "delay_dry_wet", js: "delay_dry_wet", typ: 3.14 },
        { json: "delay_feedback", js: "delay_feedback", typ: 3.14 },
        { json: "delay_filter_cutoff", js: "delay_filter_cutoff", typ: 3.14 },
        { json: "delay_filter_spread", js: "delay_filter_spread", typ: 3.14 },
        { json: "delay_frequency", js: "delay_frequency", typ: 3.14 },
        { json: "delay_on", js: "delay_on", typ: 3.14 },
        { json: "delay_style", js: "delay_style", typ: 3.14 },
        { json: "delay_sync", js: "delay_sync", typ: 3.14 },
        { json: "delay_tempo", js: "delay_tempo", typ: 3.14 },
        { json: "distortion_drive", js: "distortion_drive", typ: 3.14 },
        { json: "distortion_filter_blend", js: "distortion_filter_blend", typ: 3.14 },
        { json: "distortion_filter_cutoff", js: "distortion_filter_cutoff", typ: 3.14 },
        { json: "distortion_filter_order", js: "distortion_filter_order", typ: 3.14 },
        { json: "distortion_filter_resonance", js: "distortion_filter_resonance", typ: 3.14 },
        { json: "distortion_mix", js: "distortion_mix", typ: 3.14 },
        { json: "distortion_on", js: "distortion_on", typ: 3.14 },
        { json: "distortion_type", js: "distortion_type", typ: 3.14 },
        { json: "effect_chain_order", js: "effect_chain_order", typ: 3.14 },
        { json: "env_1_attack", js: "env_1_attack", typ: 3.14 },
        { json: "env_1_attack_power", js: "env_1_attack_power", typ: 3.14 },
        { json: "env_1_decay", js: "env_1_decay", typ: 3.14 },
        { json: "env_1_decay_power", js: "env_1_decay_power", typ: 3.14 },
        { json: "env_1_delay", js: "env_1_delay", typ: 3.14 },
        { json: "env_1_hold", js: "env_1_hold", typ: 3.14 },
        { json: "env_1_release", js: "env_1_release", typ: 3.14 },
        { json: "env_1_release_power", js: "env_1_release_power", typ: 3.14 },
        { json: "env_1_sustain", js: "env_1_sustain", typ: 3.14 },
        { json: "env_2_attack", js: "env_2_attack", typ: 3.14 },
        { json: "env_2_attack_power", js: "env_2_attack_power", typ: 3.14 },
        { json: "env_2_decay", js: "env_2_decay", typ: 3.14 },
        { json: "env_2_decay_power", js: "env_2_decay_power", typ: 3.14 },
        { json: "env_2_delay", js: "env_2_delay", typ: 3.14 },
        { json: "env_2_hold", js: "env_2_hold", typ: 3.14 },
        { json: "env_2_release", js: "env_2_release", typ: 3.14 },
        { json: "env_2_release_power", js: "env_2_release_power", typ: 3.14 },
        { json: "env_2_sustain", js: "env_2_sustain", typ: 3.14 },
        { json: "env_3_attack", js: "env_3_attack", typ: 3.14 },
        { json: "env_3_attack_power", js: "env_3_attack_power", typ: 3.14 },
        { json: "env_3_decay", js: "env_3_decay", typ: 3.14 },
        { json: "env_3_decay_power", js: "env_3_decay_power", typ: 3.14 },
        { json: "env_3_delay", js: "env_3_delay", typ: 3.14 },
        { json: "env_3_hold", js: "env_3_hold", typ: 3.14 },
        { json: "env_3_release", js: "env_3_release", typ: 3.14 },
        { json: "env_3_release_power", js: "env_3_release_power", typ: 3.14 },
        { json: "env_3_sustain", js: "env_3_sustain", typ: 3.14 },
        { json: "env_4_attack", js: "env_4_attack", typ: 3.14 },
        { json: "env_4_attack_power", js: "env_4_attack_power", typ: 3.14 },
        { json: "env_4_decay", js: "env_4_decay", typ: 3.14 },
        { json: "env_4_decay_power", js: "env_4_decay_power", typ: 3.14 },
        { json: "env_4_delay", js: "env_4_delay", typ: 3.14 },
        { json: "env_4_hold", js: "env_4_hold", typ: 3.14 },
        { json: "env_4_release", js: "env_4_release", typ: 3.14 },
        { json: "env_4_release_power", js: "env_4_release_power", typ: 3.14 },
        { json: "env_4_sustain", js: "env_4_sustain", typ: 3.14 },
        { json: "env_5_attack", js: "env_5_attack", typ: 3.14 },
        { json: "env_5_attack_power", js: "env_5_attack_power", typ: 3.14 },
        { json: "env_5_decay", js: "env_5_decay", typ: 3.14 },
        { json: "env_5_decay_power", js: "env_5_decay_power", typ: 3.14 },
        { json: "env_5_delay", js: "env_5_delay", typ: 3.14 },
        { json: "env_5_hold", js: "env_5_hold", typ: 3.14 },
        { json: "env_5_release", js: "env_5_release", typ: 3.14 },
        { json: "env_5_release_power", js: "env_5_release_power", typ: 3.14 },
        { json: "env_5_sustain", js: "env_5_sustain", typ: 3.14 },
        { json: "env_6_attack", js: "env_6_attack", typ: 3.14 },
        { json: "env_6_attack_power", js: "env_6_attack_power", typ: 3.14 },
        { json: "env_6_decay", js: "env_6_decay", typ: 3.14 },
        { json: "env_6_decay_power", js: "env_6_decay_power", typ: 3.14 },
        { json: "env_6_delay", js: "env_6_delay", typ: 3.14 },
        { json: "env_6_hold", js: "env_6_hold", typ: 3.14 },
        { json: "env_6_release", js: "env_6_release", typ: 3.14 },
        { json: "env_6_release_power", js: "env_6_release_power", typ: 3.14 },
        { json: "env_6_sustain", js: "env_6_sustain", typ: 3.14 },
        { json: "eq_band_cutoff", js: "eq_band_cutoff", typ: 3.14 },
        { json: "eq_band_gain", js: "eq_band_gain", typ: 3.14 },
        { json: "eq_band_mode", js: "eq_band_mode", typ: 3.14 },
        { json: "eq_band_resonance", js: "eq_band_resonance", typ: 3.14 },
        { json: "eq_high_cutoff", js: "eq_high_cutoff", typ: 3.14 },
        { json: "eq_high_gain", js: "eq_high_gain", typ: 3.14 },
        { json: "eq_high_mode", js: "eq_high_mode", typ: 3.14 },
        { json: "eq_high_resonance", js: "eq_high_resonance", typ: 3.14 },
        { json: "eq_low_cutoff", js: "eq_low_cutoff", typ: 3.14 },
        { json: "eq_low_gain", js: "eq_low_gain", typ: 3.14 },
        { json: "eq_low_mode", js: "eq_low_mode", typ: 3.14 },
        { json: "eq_low_resonance", js: "eq_low_resonance", typ: 3.14 },
        { json: "eq_on", js: "eq_on", typ: 3.14 },
        { json: "filter_1_blend", js: "filter_1_blend", typ: 3.14 },
        { json: "filter_1_blend_transpose", js: "filter_1_blend_transpose", typ: 3.14 },
        { json: "filter_1_cutoff", js: "filter_1_cutoff", typ: 3.14 },
        { json: "filter_1_drive", js: "filter_1_drive", typ: 3.14 },
        { json: "filter_1_filter_input", js: "filter_1_filter_input", typ: 3.14 },
        { json: "filter_1_formant_resonance", js: "filter_1_formant_resonance", typ: 3.14 },
        { json: "filter_1_formant_spread", js: "filter_1_formant_spread", typ: u(undefined, 3.14) },
        { json: "filter_1_formant_transpose", js: "filter_1_formant_transpose", typ: 3.14 },
        { json: "filter_1_formant_x", js: "filter_1_formant_x", typ: 3.14 },
        { json: "filter_1_formant_y", js: "filter_1_formant_y", typ: 3.14 },
        { json: "filter_1_keytrack", js: "filter_1_keytrack", typ: 3.14 },
        { json: "filter_1_mix", js: "filter_1_mix", typ: 3.14 },
        { json: "filter_1_model", js: "filter_1_model", typ: 3.14 },
        { json: "filter_1_on", js: "filter_1_on", typ: 3.14 },
        { json: "filter_1_resonance", js: "filter_1_resonance", typ: 3.14 },
        { json: "filter_1_style", js: "filter_1_style", typ: 3.14 },
        { json: "filter_2_blend", js: "filter_2_blend", typ: 3.14 },
        { json: "filter_2_blend_transpose", js: "filter_2_blend_transpose", typ: 3.14 },
        { json: "filter_2_cutoff", js: "filter_2_cutoff", typ: 3.14 },
        { json: "filter_2_drive", js: "filter_2_drive", typ: 3.14 },
        { json: "filter_2_filter_input", js: "filter_2_filter_input", typ: 3.14 },
        { json: "filter_2_formant_resonance", js: "filter_2_formant_resonance", typ: 3.14 },
        { json: "filter_2_formant_spread", js: "filter_2_formant_spread", typ: u(undefined, 3.14) },
        { json: "filter_2_formant_transpose", js: "filter_2_formant_transpose", typ: 3.14 },
        { json: "filter_2_formant_x", js: "filter_2_formant_x", typ: 3.14 },
        { json: "filter_2_formant_y", js: "filter_2_formant_y", typ: 3.14 },
        { json: "filter_2_keytrack", js: "filter_2_keytrack", typ: 3.14 },
        { json: "filter_2_mix", js: "filter_2_mix", typ: 3.14 },
        { json: "filter_2_model", js: "filter_2_model", typ: 3.14 },
        { json: "filter_2_on", js: "filter_2_on", typ: 3.14 },
        { json: "filter_2_resonance", js: "filter_2_resonance", typ: 3.14 },
        { json: "filter_2_style", js: "filter_2_style", typ: 3.14 },
        { json: "filter_fx_blend", js: "filter_fx_blend", typ: 3.14 },
        { json: "filter_fx_blend_transpose", js: "filter_fx_blend_transpose", typ: 3.14 },
        { json: "filter_fx_cutoff", js: "filter_fx_cutoff", typ: 3.14 },
        { json: "filter_fx_drive", js: "filter_fx_drive", typ: 3.14 },
        { json: "filter_fx_formant_resonance", js: "filter_fx_formant_resonance", typ: 3.14 },
        { json: "filter_fx_formant_spread", js: "filter_fx_formant_spread", typ: u(undefined, 3.14) },
        { json: "filter_fx_formant_transpose", js: "filter_fx_formant_transpose", typ: 3.14 },
        { json: "filter_fx_formant_x", js: "filter_fx_formant_x", typ: 3.14 },
        { json: "filter_fx_formant_y", js: "filter_fx_formant_y", typ: 3.14 },
        { json: "filter_fx_keytrack", js: "filter_fx_keytrack", typ: 3.14 },
        { json: "filter_fx_mix", js: "filter_fx_mix", typ: 3.14 },
        { json: "filter_fx_model", js: "filter_fx_model", typ: 3.14 },
        { json: "filter_fx_on", js: "filter_fx_on", typ: 3.14 },
        { json: "filter_fx_resonance", js: "filter_fx_resonance", typ: 3.14 },
        { json: "filter_fx_style", js: "filter_fx_style", typ: 3.14 },
        { json: "flanger_center", js: "flanger_center", typ: 3.14 },
        { json: "flanger_dry_wet", js: "flanger_dry_wet", typ: 3.14 },
        { json: "flanger_feedback", js: "flanger_feedback", typ: 3.14 },
        { json: "flanger_frequency", js: "flanger_frequency", typ: 3.14 },
        { json: "flanger_mod_depth", js: "flanger_mod_depth", typ: 3.14 },
        { json: "flanger_on", js: "flanger_on", typ: 3.14 },
        { json: "flanger_phase_offset", js: "flanger_phase_offset", typ: 3.14 },
        { json: "flanger_sync", js: "flanger_sync", typ: 3.14 },
        { json: "flanger_tempo", js: "flanger_tempo", typ: 3.14 },
        { json: "legato", js: "legato", typ: 3.14 },
        { json: "lfo_1_delay_time", js: "lfo_1_delay_time", typ: 3.14 },
        { json: "lfo_1_fade_time", js: "lfo_1_fade_time", typ: 3.14 },
        { json: "lfo_1_frequency", js: "lfo_1_frequency", typ: 3.14 },
        { json: "lfo_1_keytrack_transpose", js: "lfo_1_keytrack_transpose", typ: u(undefined, 3.14) },
        { json: "lfo_1_keytrack_tune", js: "lfo_1_keytrack_tune", typ: u(undefined, 3.14) },
        { json: "lfo_1_phase", js: "lfo_1_phase", typ: 3.14 },
        { json: "lfo_1_smooth_mode", js: "lfo_1_smooth_mode", typ: u(undefined, 3.14) },
        { json: "lfo_1_smooth_time", js: "lfo_1_smooth_time", typ: u(undefined, 3.14) },
        { json: "lfo_1_stereo", js: "lfo_1_stereo", typ: 3.14 },
        { json: "lfo_1_sync", js: "lfo_1_sync", typ: 3.14 },
        { json: "lfo_1_sync_type", js: "lfo_1_sync_type", typ: 3.14 },
        { json: "lfo_1_tempo", js: "lfo_1_tempo", typ: 3.14 },
        { json: "lfo_2_delay_time", js: "lfo_2_delay_time", typ: 3.14 },
        { json: "lfo_2_fade_time", js: "lfo_2_fade_time", typ: 3.14 },
        { json: "lfo_2_frequency", js: "lfo_2_frequency", typ: 3.14 },
        { json: "lfo_2_keytrack_transpose", js: "lfo_2_keytrack_transpose", typ: u(undefined, 3.14) },
        { json: "lfo_2_keytrack_tune", js: "lfo_2_keytrack_tune", typ: u(undefined, 3.14) },
        { json: "lfo_2_phase", js: "lfo_2_phase", typ: 3.14 },
        { json: "lfo_2_smooth_mode", js: "lfo_2_smooth_mode", typ: u(undefined, 3.14) },
        { json: "lfo_2_smooth_time", js: "lfo_2_smooth_time", typ: u(undefined, 3.14) },
        { json: "lfo_2_stereo", js: "lfo_2_stereo", typ: 3.14 },
        { json: "lfo_2_sync", js: "lfo_2_sync", typ: 3.14 },
        { json: "lfo_2_sync_type", js: "lfo_2_sync_type", typ: 3.14 },
        { json: "lfo_2_tempo", js: "lfo_2_tempo", typ: 3.14 },
        { json: "lfo_3_delay_time", js: "lfo_3_delay_time", typ: 3.14 },
        { json: "lfo_3_fade_time", js: "lfo_3_fade_time", typ: 3.14 },
        { json: "lfo_3_frequency", js: "lfo_3_frequency", typ: 3.14 },
        { json: "lfo_3_keytrack_transpose", js: "lfo_3_keytrack_transpose", typ: u(undefined, 3.14) },
        { json: "lfo_3_keytrack_tune", js: "lfo_3_keytrack_tune", typ: u(undefined, 3.14) },
        { json: "lfo_3_phase", js: "lfo_3_phase", typ: 3.14 },
        { json: "lfo_3_smooth_mode", js: "lfo_3_smooth_mode", typ: u(undefined, 3.14) },
        { json: "lfo_3_smooth_time", js: "lfo_3_smooth_time", typ: u(undefined, 3.14) },
        { json: "lfo_3_stereo", js: "lfo_3_stereo", typ: 3.14 },
        { json: "lfo_3_sync", js: "lfo_3_sync", typ: 3.14 },
        { json: "lfo_3_sync_type", js: "lfo_3_sync_type", typ: 3.14 },
        { json: "lfo_3_tempo", js: "lfo_3_tempo", typ: 3.14 },
        { json: "lfo_4_delay_time", js: "lfo_4_delay_time", typ: 3.14 },
        { json: "lfo_4_fade_time", js: "lfo_4_fade_time", typ: 3.14 },
        { json: "lfo_4_frequency", js: "lfo_4_frequency", typ: 3.14 },
        { json: "lfo_4_keytrack_transpose", js: "lfo_4_keytrack_transpose", typ: u(undefined, 3.14) },
        { json: "lfo_4_keytrack_tune", js: "lfo_4_keytrack_tune", typ: u(undefined, 3.14) },
        { json: "lfo_4_phase", js: "lfo_4_phase", typ: 3.14 },
        { json: "lfo_4_smooth_mode", js: "lfo_4_smooth_mode", typ: u(undefined, 3.14) },
        { json: "lfo_4_smooth_time", js: "lfo_4_smooth_time", typ: u(undefined, 3.14) },
        { json: "lfo_4_stereo", js: "lfo_4_stereo", typ: 3.14 },
        { json: "lfo_4_sync", js: "lfo_4_sync", typ: 3.14 },
        { json: "lfo_4_sync_type", js: "lfo_4_sync_type", typ: 3.14 },
        { json: "lfo_4_tempo", js: "lfo_4_tempo", typ: 3.14 },
        { json: "lfo_5_delay_time", js: "lfo_5_delay_time", typ: 3.14 },
        { json: "lfo_5_fade_time", js: "lfo_5_fade_time", typ: 3.14 },
        { json: "lfo_5_frequency", js: "lfo_5_frequency", typ: 3.14 },
        { json: "lfo_5_keytrack_transpose", js: "lfo_5_keytrack_transpose", typ: u(undefined, 3.14) },
        { json: "lfo_5_keytrack_tune", js: "lfo_5_keytrack_tune", typ: u(undefined, 3.14) },
        { json: "lfo_5_phase", js: "lfo_5_phase", typ: 3.14 },
        { json: "lfo_5_smooth_mode", js: "lfo_5_smooth_mode", typ: u(undefined, 3.14) },
        { json: "lfo_5_smooth_time", js: "lfo_5_smooth_time", typ: u(undefined, 3.14) },
        { json: "lfo_5_stereo", js: "lfo_5_stereo", typ: 3.14 },
        { json: "lfo_5_sync", js: "lfo_5_sync", typ: 3.14 },
        { json: "lfo_5_sync_type", js: "lfo_5_sync_type", typ: 3.14 },
        { json: "lfo_5_tempo", js: "lfo_5_tempo", typ: 3.14 },
        { json: "lfo_6_delay_time", js: "lfo_6_delay_time", typ: 3.14 },
        { json: "lfo_6_fade_time", js: "lfo_6_fade_time", typ: 3.14 },
        { json: "lfo_6_frequency", js: "lfo_6_frequency", typ: 3.14 },
        { json: "lfo_6_keytrack_transpose", js: "lfo_6_keytrack_transpose", typ: u(undefined, 3.14) },
        { json: "lfo_6_keytrack_tune", js: "lfo_6_keytrack_tune", typ: u(undefined, 3.14) },
        { json: "lfo_6_phase", js: "lfo_6_phase", typ: 3.14 },
        { json: "lfo_6_smooth_mode", js: "lfo_6_smooth_mode", typ: u(undefined, 3.14) },
        { json: "lfo_6_smooth_time", js: "lfo_6_smooth_time", typ: u(undefined, 3.14) },
        { json: "lfo_6_stereo", js: "lfo_6_stereo", typ: 3.14 },
        { json: "lfo_6_sync", js: "lfo_6_sync", typ: 3.14 },
        { json: "lfo_6_sync_type", js: "lfo_6_sync_type", typ: 3.14 },
        { json: "lfo_6_tempo", js: "lfo_6_tempo", typ: 3.14 },
        { json: "lfo_7_delay_time", js: "lfo_7_delay_time", typ: 3.14 },
        { json: "lfo_7_fade_time", js: "lfo_7_fade_time", typ: 3.14 },
        { json: "lfo_7_frequency", js: "lfo_7_frequency", typ: 3.14 },
        { json: "lfo_7_keytrack_transpose", js: "lfo_7_keytrack_transpose", typ: u(undefined, 3.14) },
        { json: "lfo_7_keytrack_tune", js: "lfo_7_keytrack_tune", typ: u(undefined, 3.14) },
        { json: "lfo_7_phase", js: "lfo_7_phase", typ: 3.14 },
        { json: "lfo_7_smooth_mode", js: "lfo_7_smooth_mode", typ: u(undefined, 3.14) },
        { json: "lfo_7_smooth_time", js: "lfo_7_smooth_time", typ: u(undefined, 3.14) },
        { json: "lfo_7_stereo", js: "lfo_7_stereo", typ: 3.14 },
        { json: "lfo_7_sync", js: "lfo_7_sync", typ: 3.14 },
        { json: "lfo_7_sync_type", js: "lfo_7_sync_type", typ: 3.14 },
        { json: "lfo_7_tempo", js: "lfo_7_tempo", typ: 3.14 },
        { json: "lfo_8_delay_time", js: "lfo_8_delay_time", typ: 3.14 },
        { json: "lfo_8_fade_time", js: "lfo_8_fade_time", typ: 3.14 },
        { json: "lfo_8_frequency", js: "lfo_8_frequency", typ: 3.14 },
        { json: "lfo_8_keytrack_transpose", js: "lfo_8_keytrack_transpose", typ: u(undefined, 3.14) },
        { json: "lfo_8_keytrack_tune", js: "lfo_8_keytrack_tune", typ: u(undefined, 3.14) },
        { json: "lfo_8_phase", js: "lfo_8_phase", typ: 3.14 },
        { json: "lfo_8_smooth_mode", js: "lfo_8_smooth_mode", typ: u(undefined, 3.14) },
        { json: "lfo_8_smooth_time", js: "lfo_8_smooth_time", typ: u(undefined, 3.14) },
        { json: "lfo_8_stereo", js: "lfo_8_stereo", typ: 3.14 },
        { json: "lfo_8_sync", js: "lfo_8_sync", typ: 3.14 },
        { json: "lfo_8_sync_type", js: "lfo_8_sync_type", typ: 3.14 },
        { json: "lfo_8_tempo", js: "lfo_8_tempo", typ: 3.14 },
        { json: "lfos", js: "lfos", typ: a(r("Lfo")) },
        { json: "macro_control_1", js: "macro_control_1", typ: 3.14 },
        { json: "macro_control_2", js: "macro_control_2", typ: 3.14 },
        { json: "macro_control_3", js: "macro_control_3", typ: 3.14 },
        { json: "macro_control_4", js: "macro_control_4", typ: 3.14 },
        { json: "mod_wheel", js: "mod_wheel", typ: 3.14 },
        { json: "modulation_10_amount", js: "modulation_10_amount", typ: 3.14 },
        { json: "modulation_10_bipolar", js: "modulation_10_bipolar", typ: 3.14 },
        { json: "modulation_10_bypass", js: "modulation_10_bypass", typ: 3.14 },
        { json: "modulation_10_power", js: "modulation_10_power", typ: 3.14 },
        { json: "modulation_10_stereo", js: "modulation_10_stereo", typ: 3.14 },
        { json: "modulation_11_amount", js: "modulation_11_amount", typ: 3.14 },
        { json: "modulation_11_bipolar", js: "modulation_11_bipolar", typ: 3.14 },
        { json: "modulation_11_bypass", js: "modulation_11_bypass", typ: 3.14 },
        { json: "modulation_11_power", js: "modulation_11_power", typ: 3.14 },
        { json: "modulation_11_stereo", js: "modulation_11_stereo", typ: 3.14 },
        { json: "modulation_12_amount", js: "modulation_12_amount", typ: 3.14 },
        { json: "modulation_12_bipolar", js: "modulation_12_bipolar", typ: 3.14 },
        { json: "modulation_12_bypass", js: "modulation_12_bypass", typ: 3.14 },
        { json: "modulation_12_power", js: "modulation_12_power", typ: 3.14 },
        { json: "modulation_12_stereo", js: "modulation_12_stereo", typ: 3.14 },
        { json: "modulation_13_amount", js: "modulation_13_amount", typ: 3.14 },
        { json: "modulation_13_bipolar", js: "modulation_13_bipolar", typ: 3.14 },
        { json: "modulation_13_bypass", js: "modulation_13_bypass", typ: 3.14 },
        { json: "modulation_13_power", js: "modulation_13_power", typ: 3.14 },
        { json: "modulation_13_stereo", js: "modulation_13_stereo", typ: 3.14 },
        { json: "modulation_14_amount", js: "modulation_14_amount", typ: 3.14 },
        { json: "modulation_14_bipolar", js: "modulation_14_bipolar", typ: 3.14 },
        { json: "modulation_14_bypass", js: "modulation_14_bypass", typ: 3.14 },
        { json: "modulation_14_power", js: "modulation_14_power", typ: 3.14 },
        { json: "modulation_14_stereo", js: "modulation_14_stereo", typ: 3.14 },
        { json: "modulation_15_amount", js: "modulation_15_amount", typ: 3.14 },
        { json: "modulation_15_bipolar", js: "modulation_15_bipolar", typ: 3.14 },
        { json: "modulation_15_bypass", js: "modulation_15_bypass", typ: 3.14 },
        { json: "modulation_15_power", js: "modulation_15_power", typ: 3.14 },
        { json: "modulation_15_stereo", js: "modulation_15_stereo", typ: 3.14 },
        { json: "modulation_16_amount", js: "modulation_16_amount", typ: 3.14 },
        { json: "modulation_16_bipolar", js: "modulation_16_bipolar", typ: 3.14 },
        { json: "modulation_16_bypass", js: "modulation_16_bypass", typ: 3.14 },
        { json: "modulation_16_power", js: "modulation_16_power", typ: 3.14 },
        { json: "modulation_16_stereo", js: "modulation_16_stereo", typ: 3.14 },
        { json: "modulation_17_amount", js: "modulation_17_amount", typ: 3.14 },
        { json: "modulation_17_bipolar", js: "modulation_17_bipolar", typ: 3.14 },
        { json: "modulation_17_bypass", js: "modulation_17_bypass", typ: 3.14 },
        { json: "modulation_17_power", js: "modulation_17_power", typ: 3.14 },
        { json: "modulation_17_stereo", js: "modulation_17_stereo", typ: 3.14 },
        { json: "modulation_18_amount", js: "modulation_18_amount", typ: 3.14 },
        { json: "modulation_18_bipolar", js: "modulation_18_bipolar", typ: 3.14 },
        { json: "modulation_18_bypass", js: "modulation_18_bypass", typ: 3.14 },
        { json: "modulation_18_power", js: "modulation_18_power", typ: 3.14 },
        { json: "modulation_18_stereo", js: "modulation_18_stereo", typ: 3.14 },
        { json: "modulation_19_amount", js: "modulation_19_amount", typ: 3.14 },
        { json: "modulation_19_bipolar", js: "modulation_19_bipolar", typ: 3.14 },
        { json: "modulation_19_bypass", js: "modulation_19_bypass", typ: 3.14 },
        { json: "modulation_19_power", js: "modulation_19_power", typ: 3.14 },
        { json: "modulation_19_stereo", js: "modulation_19_stereo", typ: 3.14 },
        { json: "modulation_1_amount", js: "modulation_1_amount", typ: 3.14 },
        { json: "modulation_1_bipolar", js: "modulation_1_bipolar", typ: 3.14 },
        { json: "modulation_1_bypass", js: "modulation_1_bypass", typ: 3.14 },
        { json: "modulation_1_power", js: "modulation_1_power", typ: 3.14 },
        { json: "modulation_1_stereo", js: "modulation_1_stereo", typ: 3.14 },
        { json: "modulation_20_amount", js: "modulation_20_amount", typ: 3.14 },
        { json: "modulation_20_bipolar", js: "modulation_20_bipolar", typ: 3.14 },
        { json: "modulation_20_bypass", js: "modulation_20_bypass", typ: 3.14 },
        { json: "modulation_20_power", js: "modulation_20_power", typ: 3.14 },
        { json: "modulation_20_stereo", js: "modulation_20_stereo", typ: 3.14 },
        { json: "modulation_21_amount", js: "modulation_21_amount", typ: 3.14 },
        { json: "modulation_21_bipolar", js: "modulation_21_bipolar", typ: 3.14 },
        { json: "modulation_21_bypass", js: "modulation_21_bypass", typ: 3.14 },
        { json: "modulation_21_power", js: "modulation_21_power", typ: 3.14 },
        { json: "modulation_21_stereo", js: "modulation_21_stereo", typ: 3.14 },
        { json: "modulation_22_amount", js: "modulation_22_amount", typ: 3.14 },
        { json: "modulation_22_bipolar", js: "modulation_22_bipolar", typ: 3.14 },
        { json: "modulation_22_bypass", js: "modulation_22_bypass", typ: 3.14 },
        { json: "modulation_22_power", js: "modulation_22_power", typ: 3.14 },
        { json: "modulation_22_stereo", js: "modulation_22_stereo", typ: 3.14 },
        { json: "modulation_23_amount", js: "modulation_23_amount", typ: 3.14 },
        { json: "modulation_23_bipolar", js: "modulation_23_bipolar", typ: 3.14 },
        { json: "modulation_23_bypass", js: "modulation_23_bypass", typ: 3.14 },
        { json: "modulation_23_power", js: "modulation_23_power", typ: 3.14 },
        { json: "modulation_23_stereo", js: "modulation_23_stereo", typ: 3.14 },
        { json: "modulation_24_amount", js: "modulation_24_amount", typ: 3.14 },
        { json: "modulation_24_bipolar", js: "modulation_24_bipolar", typ: 3.14 },
        { json: "modulation_24_bypass", js: "modulation_24_bypass", typ: 3.14 },
        { json: "modulation_24_power", js: "modulation_24_power", typ: 3.14 },
        { json: "modulation_24_stereo", js: "modulation_24_stereo", typ: 3.14 },
        { json: "modulation_25_amount", js: "modulation_25_amount", typ: 3.14 },
        { json: "modulation_25_bipolar", js: "modulation_25_bipolar", typ: 3.14 },
        { json: "modulation_25_bypass", js: "modulation_25_bypass", typ: 3.14 },
        { json: "modulation_25_power", js: "modulation_25_power", typ: 3.14 },
        { json: "modulation_25_stereo", js: "modulation_25_stereo", typ: 3.14 },
        { json: "modulation_26_amount", js: "modulation_26_amount", typ: 3.14 },
        { json: "modulation_26_bipolar", js: "modulation_26_bipolar", typ: 3.14 },
        { json: "modulation_26_bypass", js: "modulation_26_bypass", typ: 3.14 },
        { json: "modulation_26_power", js: "modulation_26_power", typ: 3.14 },
        { json: "modulation_26_stereo", js: "modulation_26_stereo", typ: 3.14 },
        { json: "modulation_27_amount", js: "modulation_27_amount", typ: 3.14 },
        { json: "modulation_27_bipolar", js: "modulation_27_bipolar", typ: 3.14 },
        { json: "modulation_27_bypass", js: "modulation_27_bypass", typ: 3.14 },
        { json: "modulation_27_power", js: "modulation_27_power", typ: 3.14 },
        { json: "modulation_27_stereo", js: "modulation_27_stereo", typ: 3.14 },
        { json: "modulation_28_amount", js: "modulation_28_amount", typ: 3.14 },
        { json: "modulation_28_bipolar", js: "modulation_28_bipolar", typ: 3.14 },
        { json: "modulation_28_bypass", js: "modulation_28_bypass", typ: 3.14 },
        { json: "modulation_28_power", js: "modulation_28_power", typ: 3.14 },
        { json: "modulation_28_stereo", js: "modulation_28_stereo", typ: 3.14 },
        { json: "modulation_29_amount", js: "modulation_29_amount", typ: 3.14 },
        { json: "modulation_29_bipolar", js: "modulation_29_bipolar", typ: 3.14 },
        { json: "modulation_29_bypass", js: "modulation_29_bypass", typ: 3.14 },
        { json: "modulation_29_power", js: "modulation_29_power", typ: 3.14 },
        { json: "modulation_29_stereo", js: "modulation_29_stereo", typ: 3.14 },
        { json: "modulation_2_amount", js: "modulation_2_amount", typ: 3.14 },
        { json: "modulation_2_bipolar", js: "modulation_2_bipolar", typ: 3.14 },
        { json: "modulation_2_bypass", js: "modulation_2_bypass", typ: 3.14 },
        { json: "modulation_2_power", js: "modulation_2_power", typ: 3.14 },
        { json: "modulation_2_stereo", js: "modulation_2_stereo", typ: 3.14 },
        { json: "modulation_30_amount", js: "modulation_30_amount", typ: 3.14 },
        { json: "modulation_30_bipolar", js: "modulation_30_bipolar", typ: 3.14 },
        { json: "modulation_30_bypass", js: "modulation_30_bypass", typ: 3.14 },
        { json: "modulation_30_power", js: "modulation_30_power", typ: 3.14 },
        { json: "modulation_30_stereo", js: "modulation_30_stereo", typ: 3.14 },
        { json: "modulation_31_amount", js: "modulation_31_amount", typ: 3.14 },
        { json: "modulation_31_bipolar", js: "modulation_31_bipolar", typ: 3.14 },
        { json: "modulation_31_bypass", js: "modulation_31_bypass", typ: 3.14 },
        { json: "modulation_31_power", js: "modulation_31_power", typ: 3.14 },
        { json: "modulation_31_stereo", js: "modulation_31_stereo", typ: 3.14 },
        { json: "modulation_32_amount", js: "modulation_32_amount", typ: 3.14 },
        { json: "modulation_32_bipolar", js: "modulation_32_bipolar", typ: 3.14 },
        { json: "modulation_32_bypass", js: "modulation_32_bypass", typ: 3.14 },
        { json: "modulation_32_power", js: "modulation_32_power", typ: 3.14 },
        { json: "modulation_32_stereo", js: "modulation_32_stereo", typ: 3.14 },
        { json: "modulation_33_amount", js: "modulation_33_amount", typ: 3.14 },
        { json: "modulation_33_bipolar", js: "modulation_33_bipolar", typ: 3.14 },
        { json: "modulation_33_bypass", js: "modulation_33_bypass", typ: 3.14 },
        { json: "modulation_33_power", js: "modulation_33_power", typ: 3.14 },
        { json: "modulation_33_stereo", js: "modulation_33_stereo", typ: 3.14 },
        { json: "modulation_34_amount", js: "modulation_34_amount", typ: 3.14 },
        { json: "modulation_34_bipolar", js: "modulation_34_bipolar", typ: 3.14 },
        { json: "modulation_34_bypass", js: "modulation_34_bypass", typ: 3.14 },
        { json: "modulation_34_power", js: "modulation_34_power", typ: 3.14 },
        { json: "modulation_34_stereo", js: "modulation_34_stereo", typ: 3.14 },
        { json: "modulation_35_amount", js: "modulation_35_amount", typ: 3.14 },
        { json: "modulation_35_bipolar", js: "modulation_35_bipolar", typ: 3.14 },
        { json: "modulation_35_bypass", js: "modulation_35_bypass", typ: 3.14 },
        { json: "modulation_35_power", js: "modulation_35_power", typ: 3.14 },
        { json: "modulation_35_stereo", js: "modulation_35_stereo", typ: 3.14 },
        { json: "modulation_36_amount", js: "modulation_36_amount", typ: 3.14 },
        { json: "modulation_36_bipolar", js: "modulation_36_bipolar", typ: 3.14 },
        { json: "modulation_36_bypass", js: "modulation_36_bypass", typ: 3.14 },
        { json: "modulation_36_power", js: "modulation_36_power", typ: 3.14 },
        { json: "modulation_36_stereo", js: "modulation_36_stereo", typ: 3.14 },
        { json: "modulation_37_amount", js: "modulation_37_amount", typ: 3.14 },
        { json: "modulation_37_bipolar", js: "modulation_37_bipolar", typ: 3.14 },
        { json: "modulation_37_bypass", js: "modulation_37_bypass", typ: 3.14 },
        { json: "modulation_37_power", js: "modulation_37_power", typ: 3.14 },
        { json: "modulation_37_stereo", js: "modulation_37_stereo", typ: 3.14 },
        { json: "modulation_38_amount", js: "modulation_38_amount", typ: 3.14 },
        { json: "modulation_38_bipolar", js: "modulation_38_bipolar", typ: 3.14 },
        { json: "modulation_38_bypass", js: "modulation_38_bypass", typ: 3.14 },
        { json: "modulation_38_power", js: "modulation_38_power", typ: 3.14 },
        { json: "modulation_38_stereo", js: "modulation_38_stereo", typ: 3.14 },
        { json: "modulation_39_amount", js: "modulation_39_amount", typ: 3.14 },
        { json: "modulation_39_bipolar", js: "modulation_39_bipolar", typ: 3.14 },
        { json: "modulation_39_bypass", js: "modulation_39_bypass", typ: 3.14 },
        { json: "modulation_39_power", js: "modulation_39_power", typ: 3.14 },
        { json: "modulation_39_stereo", js: "modulation_39_stereo", typ: 3.14 },
        { json: "modulation_3_amount", js: "modulation_3_amount", typ: 3.14 },
        { json: "modulation_3_bipolar", js: "modulation_3_bipolar", typ: 3.14 },
        { json: "modulation_3_bypass", js: "modulation_3_bypass", typ: 3.14 },
        { json: "modulation_3_power", js: "modulation_3_power", typ: 3.14 },
        { json: "modulation_3_stereo", js: "modulation_3_stereo", typ: 3.14 },
        { json: "modulation_40_amount", js: "modulation_40_amount", typ: 3.14 },
        { json: "modulation_40_bipolar", js: "modulation_40_bipolar", typ: 3.14 },
        { json: "modulation_40_bypass", js: "modulation_40_bypass", typ: 3.14 },
        { json: "modulation_40_power", js: "modulation_40_power", typ: 3.14 },
        { json: "modulation_40_stereo", js: "modulation_40_stereo", typ: 3.14 },
        { json: "modulation_41_amount", js: "modulation_41_amount", typ: 3.14 },
        { json: "modulation_41_bipolar", js: "modulation_41_bipolar", typ: 3.14 },
        { json: "modulation_41_bypass", js: "modulation_41_bypass", typ: 3.14 },
        { json: "modulation_41_power", js: "modulation_41_power", typ: 3.14 },
        { json: "modulation_41_stereo", js: "modulation_41_stereo", typ: 3.14 },
        { json: "modulation_42_amount", js: "modulation_42_amount", typ: 3.14 },
        { json: "modulation_42_bipolar", js: "modulation_42_bipolar", typ: 3.14 },
        { json: "modulation_42_bypass", js: "modulation_42_bypass", typ: 3.14 },
        { json: "modulation_42_power", js: "modulation_42_power", typ: 3.14 },
        { json: "modulation_42_stereo", js: "modulation_42_stereo", typ: 3.14 },
        { json: "modulation_43_amount", js: "modulation_43_amount", typ: 3.14 },
        { json: "modulation_43_bipolar", js: "modulation_43_bipolar", typ: 3.14 },
        { json: "modulation_43_bypass", js: "modulation_43_bypass", typ: 3.14 },
        { json: "modulation_43_power", js: "modulation_43_power", typ: 3.14 },
        { json: "modulation_43_stereo", js: "modulation_43_stereo", typ: 3.14 },
        { json: "modulation_44_amount", js: "modulation_44_amount", typ: 3.14 },
        { json: "modulation_44_bipolar", js: "modulation_44_bipolar", typ: 3.14 },
        { json: "modulation_44_bypass", js: "modulation_44_bypass", typ: 3.14 },
        { json: "modulation_44_power", js: "modulation_44_power", typ: 3.14 },
        { json: "modulation_44_stereo", js: "modulation_44_stereo", typ: 3.14 },
        { json: "modulation_45_amount", js: "modulation_45_amount", typ: 3.14 },
        { json: "modulation_45_bipolar", js: "modulation_45_bipolar", typ: 3.14 },
        { json: "modulation_45_bypass", js: "modulation_45_bypass", typ: 3.14 },
        { json: "modulation_45_power", js: "modulation_45_power", typ: 3.14 },
        { json: "modulation_45_stereo", js: "modulation_45_stereo", typ: 3.14 },
        { json: "modulation_46_amount", js: "modulation_46_amount", typ: 3.14 },
        { json: "modulation_46_bipolar", js: "modulation_46_bipolar", typ: 3.14 },
        { json: "modulation_46_bypass", js: "modulation_46_bypass", typ: 3.14 },
        { json: "modulation_46_power", js: "modulation_46_power", typ: 3.14 },
        { json: "modulation_46_stereo", js: "modulation_46_stereo", typ: 3.14 },
        { json: "modulation_47_amount", js: "modulation_47_amount", typ: 3.14 },
        { json: "modulation_47_bipolar", js: "modulation_47_bipolar", typ: 3.14 },
        { json: "modulation_47_bypass", js: "modulation_47_bypass", typ: 3.14 },
        { json: "modulation_47_power", js: "modulation_47_power", typ: 3.14 },
        { json: "modulation_47_stereo", js: "modulation_47_stereo", typ: 3.14 },
        { json: "modulation_48_amount", js: "modulation_48_amount", typ: 3.14 },
        { json: "modulation_48_bipolar", js: "modulation_48_bipolar", typ: 3.14 },
        { json: "modulation_48_bypass", js: "modulation_48_bypass", typ: 3.14 },
        { json: "modulation_48_power", js: "modulation_48_power", typ: 3.14 },
        { json: "modulation_48_stereo", js: "modulation_48_stereo", typ: 3.14 },
        { json: "modulation_49_amount", js: "modulation_49_amount", typ: 3.14 },
        { json: "modulation_49_bipolar", js: "modulation_49_bipolar", typ: 3.14 },
        { json: "modulation_49_bypass", js: "modulation_49_bypass", typ: 3.14 },
        { json: "modulation_49_power", js: "modulation_49_power", typ: 3.14 },
        { json: "modulation_49_stereo", js: "modulation_49_stereo", typ: 3.14 },
        { json: "modulation_4_amount", js: "modulation_4_amount", typ: 3.14 },
        { json: "modulation_4_bipolar", js: "modulation_4_bipolar", typ: 3.14 },
        { json: "modulation_4_bypass", js: "modulation_4_bypass", typ: 3.14 },
        { json: "modulation_4_power", js: "modulation_4_power", typ: 3.14 },
        { json: "modulation_4_stereo", js: "modulation_4_stereo", typ: 3.14 },
        { json: "modulation_50_amount", js: "modulation_50_amount", typ: 3.14 },
        { json: "modulation_50_bipolar", js: "modulation_50_bipolar", typ: 3.14 },
        { json: "modulation_50_bypass", js: "modulation_50_bypass", typ: 3.14 },
        { json: "modulation_50_power", js: "modulation_50_power", typ: 3.14 },
        { json: "modulation_50_stereo", js: "modulation_50_stereo", typ: 3.14 },
        { json: "modulation_51_amount", js: "modulation_51_amount", typ: 3.14 },
        { json: "modulation_51_bipolar", js: "modulation_51_bipolar", typ: 3.14 },
        { json: "modulation_51_bypass", js: "modulation_51_bypass", typ: 3.14 },
        { json: "modulation_51_power", js: "modulation_51_power", typ: 3.14 },
        { json: "modulation_51_stereo", js: "modulation_51_stereo", typ: 3.14 },
        { json: "modulation_52_amount", js: "modulation_52_amount", typ: 3.14 },
        { json: "modulation_52_bipolar", js: "modulation_52_bipolar", typ: 3.14 },
        { json: "modulation_52_bypass", js: "modulation_52_bypass", typ: 3.14 },
        { json: "modulation_52_power", js: "modulation_52_power", typ: 3.14 },
        { json: "modulation_52_stereo", js: "modulation_52_stereo", typ: 3.14 },
        { json: "modulation_53_amount", js: "modulation_53_amount", typ: 3.14 },
        { json: "modulation_53_bipolar", js: "modulation_53_bipolar", typ: 3.14 },
        { json: "modulation_53_bypass", js: "modulation_53_bypass", typ: 3.14 },
        { json: "modulation_53_power", js: "modulation_53_power", typ: 3.14 },
        { json: "modulation_53_stereo", js: "modulation_53_stereo", typ: 3.14 },
        { json: "modulation_54_amount", js: "modulation_54_amount", typ: 3.14 },
        { json: "modulation_54_bipolar", js: "modulation_54_bipolar", typ: 3.14 },
        { json: "modulation_54_bypass", js: "modulation_54_bypass", typ: 3.14 },
        { json: "modulation_54_power", js: "modulation_54_power", typ: 3.14 },
        { json: "modulation_54_stereo", js: "modulation_54_stereo", typ: 3.14 },
        { json: "modulation_55_amount", js: "modulation_55_amount", typ: 3.14 },
        { json: "modulation_55_bipolar", js: "modulation_55_bipolar", typ: 3.14 },
        { json: "modulation_55_bypass", js: "modulation_55_bypass", typ: 3.14 },
        { json: "modulation_55_power", js: "modulation_55_power", typ: 3.14 },
        { json: "modulation_55_stereo", js: "modulation_55_stereo", typ: 3.14 },
        { json: "modulation_56_amount", js: "modulation_56_amount", typ: 3.14 },
        { json: "modulation_56_bipolar", js: "modulation_56_bipolar", typ: 3.14 },
        { json: "modulation_56_bypass", js: "modulation_56_bypass", typ: 3.14 },
        { json: "modulation_56_power", js: "modulation_56_power", typ: 3.14 },
        { json: "modulation_56_stereo", js: "modulation_56_stereo", typ: 3.14 },
        { json: "modulation_57_amount", js: "modulation_57_amount", typ: 3.14 },
        { json: "modulation_57_bipolar", js: "modulation_57_bipolar", typ: 3.14 },
        { json: "modulation_57_bypass", js: "modulation_57_bypass", typ: 3.14 },
        { json: "modulation_57_power", js: "modulation_57_power", typ: 3.14 },
        { json: "modulation_57_stereo", js: "modulation_57_stereo", typ: 3.14 },
        { json: "modulation_58_amount", js: "modulation_58_amount", typ: 3.14 },
        { json: "modulation_58_bipolar", js: "modulation_58_bipolar", typ: 3.14 },
        { json: "modulation_58_bypass", js: "modulation_58_bypass", typ: 3.14 },
        { json: "modulation_58_power", js: "modulation_58_power", typ: 3.14 },
        { json: "modulation_58_stereo", js: "modulation_58_stereo", typ: 3.14 },
        { json: "modulation_59_amount", js: "modulation_59_amount", typ: 3.14 },
        { json: "modulation_59_bipolar", js: "modulation_59_bipolar", typ: 3.14 },
        { json: "modulation_59_bypass", js: "modulation_59_bypass", typ: 3.14 },
        { json: "modulation_59_power", js: "modulation_59_power", typ: 3.14 },
        { json: "modulation_59_stereo", js: "modulation_59_stereo", typ: 3.14 },
        { json: "modulation_5_amount", js: "modulation_5_amount", typ: 3.14 },
        { json: "modulation_5_bipolar", js: "modulation_5_bipolar", typ: 3.14 },
        { json: "modulation_5_bypass", js: "modulation_5_bypass", typ: 3.14 },
        { json: "modulation_5_power", js: "modulation_5_power", typ: 3.14 },
        { json: "modulation_5_stereo", js: "modulation_5_stereo", typ: 3.14 },
        { json: "modulation_60_amount", js: "modulation_60_amount", typ: 3.14 },
        { json: "modulation_60_bipolar", js: "modulation_60_bipolar", typ: 3.14 },
        { json: "modulation_60_bypass", js: "modulation_60_bypass", typ: 3.14 },
        { json: "modulation_60_power", js: "modulation_60_power", typ: 3.14 },
        { json: "modulation_60_stereo", js: "modulation_60_stereo", typ: 3.14 },
        { json: "modulation_61_amount", js: "modulation_61_amount", typ: 3.14 },
        { json: "modulation_61_bipolar", js: "modulation_61_bipolar", typ: 3.14 },
        { json: "modulation_61_bypass", js: "modulation_61_bypass", typ: 3.14 },
        { json: "modulation_61_power", js: "modulation_61_power", typ: 3.14 },
        { json: "modulation_61_stereo", js: "modulation_61_stereo", typ: 3.14 },
        { json: "modulation_62_amount", js: "modulation_62_amount", typ: 3.14 },
        { json: "modulation_62_bipolar", js: "modulation_62_bipolar", typ: 3.14 },
        { json: "modulation_62_bypass", js: "modulation_62_bypass", typ: 3.14 },
        { json: "modulation_62_power", js: "modulation_62_power", typ: 3.14 },
        { json: "modulation_62_stereo", js: "modulation_62_stereo", typ: 3.14 },
        { json: "modulation_63_amount", js: "modulation_63_amount", typ: 3.14 },
        { json: "modulation_63_bipolar", js: "modulation_63_bipolar", typ: 3.14 },
        { json: "modulation_63_bypass", js: "modulation_63_bypass", typ: 3.14 },
        { json: "modulation_63_power", js: "modulation_63_power", typ: 3.14 },
        { json: "modulation_63_stereo", js: "modulation_63_stereo", typ: 3.14 },
        { json: "modulation_64_amount", js: "modulation_64_amount", typ: 3.14 },
        { json: "modulation_64_bipolar", js: "modulation_64_bipolar", typ: 3.14 },
        { json: "modulation_64_bypass", js: "modulation_64_bypass", typ: 3.14 },
        { json: "modulation_64_power", js: "modulation_64_power", typ: 3.14 },
        { json: "modulation_64_stereo", js: "modulation_64_stereo", typ: 3.14 },
        { json: "modulation_6_amount", js: "modulation_6_amount", typ: 3.14 },
        { json: "modulation_6_bipolar", js: "modulation_6_bipolar", typ: 3.14 },
        { json: "modulation_6_bypass", js: "modulation_6_bypass", typ: 3.14 },
        { json: "modulation_6_power", js: "modulation_6_power", typ: 3.14 },
        { json: "modulation_6_stereo", js: "modulation_6_stereo", typ: 3.14 },
        { json: "modulation_7_amount", js: "modulation_7_amount", typ: 3.14 },
        { json: "modulation_7_bipolar", js: "modulation_7_bipolar", typ: 3.14 },
        { json: "modulation_7_bypass", js: "modulation_7_bypass", typ: 3.14 },
        { json: "modulation_7_power", js: "modulation_7_power", typ: 3.14 },
        { json: "modulation_7_stereo", js: "modulation_7_stereo", typ: 3.14 },
        { json: "modulation_8_amount", js: "modulation_8_amount", typ: 3.14 },
        { json: "modulation_8_bipolar", js: "modulation_8_bipolar", typ: 3.14 },
        { json: "modulation_8_bypass", js: "modulation_8_bypass", typ: 3.14 },
        { json: "modulation_8_power", js: "modulation_8_power", typ: 3.14 },
        { json: "modulation_8_stereo", js: "modulation_8_stereo", typ: 3.14 },
        { json: "modulation_9_amount", js: "modulation_9_amount", typ: 3.14 },
        { json: "modulation_9_bipolar", js: "modulation_9_bipolar", typ: 3.14 },
        { json: "modulation_9_bypass", js: "modulation_9_bypass", typ: 3.14 },
        { json: "modulation_9_power", js: "modulation_9_power", typ: 3.14 },
        { json: "modulation_9_stereo", js: "modulation_9_stereo", typ: 3.14 },
        { json: "modulations", js: "modulations", typ: a(r("Modulation")) },
        { json: "osc_1_destination", js: "osc_1_destination", typ: 3.14 },
        { json: "osc_1_detune_power", js: "osc_1_detune_power", typ: 3.14 },
        { json: "osc_1_detune_range", js: "osc_1_detune_range", typ: 3.14 },
        { json: "osc_1_distortion_amount", js: "osc_1_distortion_amount", typ: 3.14 },
        { json: "osc_1_distortion_phase", js: "osc_1_distortion_phase", typ: 3.14 },
        { json: "osc_1_distortion_spread", js: "osc_1_distortion_spread", typ: 3.14 },
        { json: "osc_1_distortion_type", js: "osc_1_distortion_type", typ: 3.14 },
        { json: "osc_1_frame_spread", js: "osc_1_frame_spread", typ: 3.14 },
        { json: "osc_1_level", js: "osc_1_level", typ: 3.14 },
        { json: "osc_1_midi_track", js: "osc_1_midi_track", typ: 3.14 },
        { json: "osc_1_on", js: "osc_1_on", typ: 3.14 },
        { json: "osc_1_pan", js: "osc_1_pan", typ: 3.14 },
        { json: "osc_1_phase", js: "osc_1_phase", typ: 3.14 },
        { json: "osc_1_random_phase", js: "osc_1_random_phase", typ: 3.14 },
        { json: "osc_1_smooth_interpolation", js: "osc_1_smooth_interpolation", typ: 3.14 },
        { json: "osc_1_spectral_morph_amount", js: "osc_1_spectral_morph_amount", typ: 3.14 },
        { json: "osc_1_spectral_morph_spread", js: "osc_1_spectral_morph_spread", typ: 3.14 },
        { json: "osc_1_spectral_morph_type", js: "osc_1_spectral_morph_type", typ: 3.14 },
        { json: "osc_1_spectral_unison", js: "osc_1_spectral_unison", typ: 3.14 },
        { json: "osc_1_stack_style", js: "osc_1_stack_style", typ: 3.14 },
        { json: "osc_1_stereo_spread", js: "osc_1_stereo_spread", typ: 3.14 },
        { json: "osc_1_transpose", js: "osc_1_transpose", typ: 3.14 },
        { json: "osc_1_transpose_quantize", js: "osc_1_transpose_quantize", typ: 3.14 },
        { json: "osc_1_tune", js: "osc_1_tune", typ: 3.14 },
        { json: "osc_1_unison_blend", js: "osc_1_unison_blend", typ: 3.14 },
        { json: "osc_1_unison_detune", js: "osc_1_unison_detune", typ: 3.14 },
        { json: "osc_1_unison_voices", js: "osc_1_unison_voices", typ: 3.14 },
        { json: "osc_1_view_2d", js: "osc_1_view_2d", typ: 3.14 },
        { json: "osc_1_wave_frame", js: "osc_1_wave_frame", typ: 3.14 },
        { json: "osc_2_destination", js: "osc_2_destination", typ: 3.14 },
        { json: "osc_2_detune_power", js: "osc_2_detune_power", typ: 3.14 },
        { json: "osc_2_detune_range", js: "osc_2_detune_range", typ: 3.14 },
        { json: "osc_2_distortion_amount", js: "osc_2_distortion_amount", typ: 3.14 },
        { json: "osc_2_distortion_phase", js: "osc_2_distortion_phase", typ: 3.14 },
        { json: "osc_2_distortion_spread", js: "osc_2_distortion_spread", typ: 3.14 },
        { json: "osc_2_distortion_type", js: "osc_2_distortion_type", typ: 3.14 },
        { json: "osc_2_frame_spread", js: "osc_2_frame_spread", typ: 3.14 },
        { json: "osc_2_level", js: "osc_2_level", typ: 3.14 },
        { json: "osc_2_midi_track", js: "osc_2_midi_track", typ: 3.14 },
        { json: "osc_2_on", js: "osc_2_on", typ: 3.14 },
        { json: "osc_2_pan", js: "osc_2_pan", typ: 3.14 },
        { json: "osc_2_phase", js: "osc_2_phase", typ: 3.14 },
        { json: "osc_2_random_phase", js: "osc_2_random_phase", typ: 3.14 },
        { json: "osc_2_smooth_interpolation", js: "osc_2_smooth_interpolation", typ: 3.14 },
        { json: "osc_2_spectral_morph_amount", js: "osc_2_spectral_morph_amount", typ: 3.14 },
        { json: "osc_2_spectral_morph_spread", js: "osc_2_spectral_morph_spread", typ: 3.14 },
        { json: "osc_2_spectral_morph_type", js: "osc_2_spectral_morph_type", typ: 3.14 },
        { json: "osc_2_spectral_unison", js: "osc_2_spectral_unison", typ: 3.14 },
        { json: "osc_2_stack_style", js: "osc_2_stack_style", typ: 3.14 },
        { json: "osc_2_stereo_spread", js: "osc_2_stereo_spread", typ: 3.14 },
        { json: "osc_2_transpose", js: "osc_2_transpose", typ: 3.14 },
        { json: "osc_2_transpose_quantize", js: "osc_2_transpose_quantize", typ: 3.14 },
        { json: "osc_2_tune", js: "osc_2_tune", typ: 3.14 },
        { json: "osc_2_unison_blend", js: "osc_2_unison_blend", typ: 3.14 },
        { json: "osc_2_unison_detune", js: "osc_2_unison_detune", typ: 3.14 },
        { json: "osc_2_unison_voices", js: "osc_2_unison_voices", typ: 3.14 },
        { json: "osc_2_view_2d", js: "osc_2_view_2d", typ: 3.14 },
        { json: "osc_2_wave_frame", js: "osc_2_wave_frame", typ: 3.14 },
        { json: "osc_3_destination", js: "osc_3_destination", typ: 3.14 },
        { json: "osc_3_detune_power", js: "osc_3_detune_power", typ: 3.14 },
        { json: "osc_3_detune_range", js: "osc_3_detune_range", typ: 3.14 },
        { json: "osc_3_distortion_amount", js: "osc_3_distortion_amount", typ: 3.14 },
        { json: "osc_3_distortion_phase", js: "osc_3_distortion_phase", typ: 3.14 },
        { json: "osc_3_distortion_spread", js: "osc_3_distortion_spread", typ: 3.14 },
        { json: "osc_3_distortion_type", js: "osc_3_distortion_type", typ: 3.14 },
        { json: "osc_3_frame_spread", js: "osc_3_frame_spread", typ: 3.14 },
        { json: "osc_3_level", js: "osc_3_level", typ: 3.14 },
        { json: "osc_3_midi_track", js: "osc_3_midi_track", typ: 3.14 },
        { json: "osc_3_on", js: "osc_3_on", typ: 3.14 },
        { json: "osc_3_pan", js: "osc_3_pan", typ: 3.14 },
        { json: "osc_3_phase", js: "osc_3_phase", typ: 3.14 },
        { json: "osc_3_random_phase", js: "osc_3_random_phase", typ: 3.14 },
        { json: "osc_3_smooth_interpolation", js: "osc_3_smooth_interpolation", typ: 3.14 },
        { json: "osc_3_spectral_morph_amount", js: "osc_3_spectral_morph_amount", typ: 3.14 },
        { json: "osc_3_spectral_morph_spread", js: "osc_3_spectral_morph_spread", typ: 3.14 },
        { json: "osc_3_spectral_morph_type", js: "osc_3_spectral_morph_type", typ: 3.14 },
        { json: "osc_3_spectral_unison", js: "osc_3_spectral_unison", typ: 3.14 },
        { json: "osc_3_stack_style", js: "osc_3_stack_style", typ: 3.14 },
        { json: "osc_3_stereo_spread", js: "osc_3_stereo_spread", typ: 3.14 },
        { json: "osc_3_transpose", js: "osc_3_transpose", typ: 3.14 },
        { json: "osc_3_transpose_quantize", js: "osc_3_transpose_quantize", typ: 3.14 },
        { json: "osc_3_tune", js: "osc_3_tune", typ: 3.14 },
        { json: "osc_3_unison_blend", js: "osc_3_unison_blend", typ: 3.14 },
        { json: "osc_3_unison_detune", js: "osc_3_unison_detune", typ: 3.14 },
        { json: "osc_3_unison_voices", js: "osc_3_unison_voices", typ: 3.14 },
        { json: "osc_3_view_2d", js: "osc_3_view_2d", typ: 3.14 },
        { json: "osc_3_wave_frame", js: "osc_3_wave_frame", typ: 3.14 },
        { json: "oversampling", js: "oversampling", typ: 3.14 },
        { json: "phaser_blend", js: "phaser_blend", typ: 3.14 },
        { json: "phaser_center", js: "phaser_center", typ: 3.14 },
        { json: "phaser_dry_wet", js: "phaser_dry_wet", typ: 3.14 },
        { json: "phaser_feedback", js: "phaser_feedback", typ: 3.14 },
        { json: "phaser_frequency", js: "phaser_frequency", typ: 3.14 },
        { json: "phaser_mod_depth", js: "phaser_mod_depth", typ: 3.14 },
        { json: "phaser_on", js: "phaser_on", typ: 3.14 },
        { json: "phaser_phase_offset", js: "phaser_phase_offset", typ: 3.14 },
        { json: "phaser_sync", js: "phaser_sync", typ: 3.14 },
        { json: "phaser_tempo", js: "phaser_tempo", typ: 3.14 },
        { json: "pitch_bend_range", js: "pitch_bend_range", typ: 3.14 },
        { json: "pitch_wheel", js: "pitch_wheel", typ: 3.14 },
        { json: "polyphony", js: "polyphony", typ: 3.14 },
        { json: "portamento_force", js: "portamento_force", typ: 3.14 },
        { json: "portamento_scale", js: "portamento_scale", typ: 3.14 },
        { json: "portamento_slope", js: "portamento_slope", typ: 3.14 },
        { json: "portamento_time", js: "portamento_time", typ: 3.14 },
        { json: "random_1_frequency", js: "random_1_frequency", typ: 3.14 },
        { json: "random_1_keytrack_transpose", js: "random_1_keytrack_transpose", typ: u(undefined, 3.14) },
        { json: "random_1_keytrack_tune", js: "random_1_keytrack_tune", typ: u(undefined, 3.14) },
        { json: "random_1_stereo", js: "random_1_stereo", typ: 3.14 },
        { json: "random_1_style", js: "random_1_style", typ: 3.14 },
        { json: "random_1_sync", js: "random_1_sync", typ: 3.14 },
        { json: "random_1_sync_type", js: "random_1_sync_type", typ: 3.14 },
        { json: "random_1_tempo", js: "random_1_tempo", typ: 3.14 },
        { json: "random_2_frequency", js: "random_2_frequency", typ: 3.14 },
        { json: "random_2_keytrack_transpose", js: "random_2_keytrack_transpose", typ: u(undefined, 3.14) },
        { json: "random_2_keytrack_tune", js: "random_2_keytrack_tune", typ: u(undefined, 3.14) },
        { json: "random_2_stereo", js: "random_2_stereo", typ: 3.14 },
        { json: "random_2_style", js: "random_2_style", typ: 3.14 },
        { json: "random_2_sync", js: "random_2_sync", typ: 3.14 },
        { json: "random_2_sync_type", js: "random_2_sync_type", typ: 3.14 },
        { json: "random_2_tempo", js: "random_2_tempo", typ: 3.14 },
        { json: "random_3_frequency", js: "random_3_frequency", typ: 3.14 },
        { json: "random_3_keytrack_transpose", js: "random_3_keytrack_transpose", typ: u(undefined, 3.14) },
        { json: "random_3_keytrack_tune", js: "random_3_keytrack_tune", typ: u(undefined, 3.14) },
        { json: "random_3_stereo", js: "random_3_stereo", typ: 3.14 },
        { json: "random_3_style", js: "random_3_style", typ: 3.14 },
        { json: "random_3_sync", js: "random_3_sync", typ: 3.14 },
        { json: "random_3_sync_type", js: "random_3_sync_type", typ: 3.14 },
        { json: "random_3_tempo", js: "random_3_tempo", typ: 3.14 },
        { json: "random_4_frequency", js: "random_4_frequency", typ: 3.14 },
        { json: "random_4_keytrack_transpose", js: "random_4_keytrack_transpose", typ: u(undefined, 3.14) },
        { json: "random_4_keytrack_tune", js: "random_4_keytrack_tune", typ: u(undefined, 3.14) },
        { json: "random_4_stereo", js: "random_4_stereo", typ: 3.14 },
        { json: "random_4_style", js: "random_4_style", typ: 3.14 },
        { json: "random_4_sync", js: "random_4_sync", typ: 3.14 },
        { json: "random_4_sync_type", js: "random_4_sync_type", typ: 3.14 },
        { json: "random_4_tempo", js: "random_4_tempo", typ: 3.14 },
        { json: "reverb_chorus_amount", js: "reverb_chorus_amount", typ: 3.14 },
        { json: "reverb_chorus_frequency", js: "reverb_chorus_frequency", typ: 3.14 },
        { json: "reverb_decay_time", js: "reverb_decay_time", typ: 3.14 },
        { json: "reverb_delay", js: "reverb_delay", typ: u(undefined, 3.14) },
        { json: "reverb_dry_wet", js: "reverb_dry_wet", typ: 3.14 },
        { json: "reverb_high_shelf_cutoff", js: "reverb_high_shelf_cutoff", typ: 3.14 },
        { json: "reverb_high_shelf_gain", js: "reverb_high_shelf_gain", typ: 3.14 },
        { json: "reverb_low_shelf_cutoff", js: "reverb_low_shelf_cutoff", typ: 3.14 },
        { json: "reverb_low_shelf_gain", js: "reverb_low_shelf_gain", typ: 3.14 },
        { json: "reverb_on", js: "reverb_on", typ: 3.14 },
        { json: "reverb_pre_high_cutoff", js: "reverb_pre_high_cutoff", typ: 3.14 },
        { json: "reverb_pre_low_cutoff", js: "reverb_pre_low_cutoff", typ: 3.14 },
        { json: "reverb_size", js: "reverb_size", typ: 3.14 },
        { json: "sample", js: "sample", typ: r("Sample") },
        { json: "sample_bounce", js: "sample_bounce", typ: u(undefined, 3.14) },
        { json: "sample_destination", js: "sample_destination", typ: 3.14 },
        { json: "sample_keytrack", js: "sample_keytrack", typ: 3.14 },
        { json: "sample_level", js: "sample_level", typ: 3.14 },
        { json: "sample_loop", js: "sample_loop", typ: 3.14 },
        { json: "sample_on", js: "sample_on", typ: 3.14 },
        { json: "sample_pan", js: "sample_pan", typ: 3.14 },
        { json: "sample_random_phase", js: "sample_random_phase", typ: 3.14 },
        { json: "sample_transpose", js: "sample_transpose", typ: 3.14 },
        { json: "sample_transpose_quantize", js: "sample_transpose_quantize", typ: 3.14 },
        { json: "sample_tune", js: "sample_tune", typ: 3.14 },
        { json: "stereo_mode", js: "stereo_mode", typ: u(undefined, 3.14) },
        { json: "stereo_routing", js: "stereo_routing", typ: 3.14 },
        { json: "velocity_track", js: "velocity_track", typ: 3.14 },
        { json: "view_spectrogram", js: "view_spectrogram", typ: u(undefined, 3.14) },
        { json: "voice_amplitude", js: "voice_amplitude", typ: 3.14 },
        { json: "voice_override", js: "voice_override", typ: u(undefined, 3.14) },
        { json: "voice_priority", js: "voice_priority", typ: 3.14 },
        { json: "voice_transpose", js: "voice_transpose", typ: u(undefined, 3.14) },
        { json: "voice_tune", js: "voice_tune", typ: 3.14 },
        { json: "volume", js: "volume", typ: 3.14 },
        { json: "wavetables", js: "wavetables", typ: a(r("Wavetable")) },
    ], "any"),
    "Lfo": o([
        { json: "name", js: "name", typ: "" },
        { json: "num_points", js: "num_points", typ: 3.14 },
        { json: "points", js: "points", typ: a(3.14) },
        { json: "powers", js: "powers", typ: a(3.14) },
        { json: "smooth", js: "smooth", typ: true },
    ], "any"),
    "Modulation": o([
        { json: "destination", js: "destination", typ: "" },
        { json: "line_mapping", js: "line_mapping", typ: u(undefined, r("Lfo")) },
        { json: "source", js: "source", typ: r("Source") },
    ], "any"),
    "Sample": o([
        { json: "length", js: "length", typ: 3.14 },
        { json: "name", js: "name", typ: "" },
        { json: "sample_rate", js: "sample_rate", typ: 3.14 },
        { json: "samples", js: "samples", typ: "" },
        { json: "samples_stereo", js: "samples_stereo", typ: u(undefined, "") },
    ], "any"),
    "Wavetable": o([
        { json: "author", js: "author", typ: u(undefined, "") },
        { json: "full_normalize", js: "full_normalize", typ: true },
        { json: "groups", js: "groups", typ: a(r("Group")) },
        { json: "name", js: "name", typ: "" },
        { json: "remove_all_dc", js: "remove_all_dc", typ: true },
        { json: "version", js: "version", typ: "" },
    ], "any"),
    "Group": o([
        { json: "components", js: "components", typ: a(r("Component")) },
    ], "any"),
    "Component": o([
        { json: "audio_file", js: "audio_file", typ: u(undefined, "") },
        { json: "audio_sample_rate", js: "audio_sample_rate", typ: u(undefined, 3.14) },
        { json: "fade_style", js: "fade_style", typ: u(undefined, 3.14) },
        { json: "horizontal_asymmetric", js: "horizontal_asymmetric", typ: u(undefined, true) },
        { json: "interpolation", js: "interpolation", typ: u(undefined, 3.14) },
        { json: "interpolation_style", js: "interpolation_style", typ: 3.14 },
        { json: "keyframes", js: "keyframes", typ: u(a(r("Keyframe")), null) },
        { json: "normalize", js: "normalize", typ: u(undefined, true) },
        { json: "normalize_gain", js: "normalize_gain", typ: u(undefined, true) },
        { json: "normalize_mult", js: "normalize_mult", typ: u(undefined, true) },
        { json: "num_points", js: "num_points", typ: u(undefined, 3.14) },
        { json: "phase_style", js: "phase_style", typ: u(undefined, 3.14) },
        { json: "random_seed", js: "random_seed", typ: u(undefined, 3.14) },
        { json: "style", js: "style", typ: u(undefined, 3.14) },
        { json: "type", js: "type", typ: r("Type") },
        { json: "vertical_asymmetric", js: "vertical_asymmetric", typ: u(undefined, true) },
        { json: "window_shape", js: "window_shape", typ: u(undefined, 3.14) },
        { json: "window_size", js: "window_size", typ: u(undefined, 3.14) },
    ], "any"),
    "Keyframe": o([
        { json: "cutoff", js: "cutoff", typ: u(undefined, 3.14) },
        { json: "down_run_rise", js: "down_run_rise", typ: u(undefined, 3.14) },
        { json: "fold_boost", js: "fold_boost", typ: u(undefined, 3.14) },
        { json: "horizontal_power", js: "horizontal_power", typ: u(undefined, 3.14) },
        { json: "left_position", js: "left_position", typ: u(undefined, 3.14) },
        { json: "line", js: "line", typ: u(undefined, r("Lfo")) },
        { json: "mix", js: "mix", typ: u(undefined, 3.14) },
        { json: "phase", js: "phase", typ: u(undefined, 3.14) },
        { json: "position", js: "position", typ: 3.14 },
        { json: "pull_power", js: "pull_power", typ: u(undefined, 3.14) },
        { json: "right_position", js: "right_position", typ: u(undefined, 3.14) },
        { json: "shape", js: "shape", typ: u(undefined, 3.14) },
        { json: "start_position", js: "start_position", typ: u(undefined, 3.14) },
        { json: "up_run_rise", js: "up_run_rise", typ: u(undefined, 3.14) },
        { json: "vertical_power", js: "vertical_power", typ: u(undefined, 3.14) },
        { json: "wave_data", js: "wave_data", typ: u(undefined, "") },
        { json: "window_fade", js: "window_fade", typ: u(undefined, 3.14) },
        { json: "window_size", js: "window_size", typ: u(undefined, 3.14) },
    ], "any"),
    "PresetStyle": [
        "Bass",
        "",
        "Experiment",
        "Keys",
        "Lead",
        "Pad",
        "Percussion",
        "Sequence",
        "SFX",
        "Template",
    ],
    "Source": [
        "aftertouch",
        "",
        "env_1",
        "env_2",
        "env_3",
        "env_4",
        "env_5",
        "env_6",
        "lfo_1",
        "lfo_2",
        "lfo_3",
        "lfo_4",
        "lfo_5",
        "lfo_6",
        "lfo_7",
        "lfo_8",
        "lift",
        "macro_control_1",
        "macro_control_2",
        "macro_control_3",
        "macro_control_4",
        "mod_wheel",
        "note",
        "note_in_octave",
        "pitch_wheel",
        "random",
        "random_1",
        "random_2",
        "random_3",
        "random_4",
        "slide",
        "stereo",
        "velocity",
    ],
    "Type": [
        "Audio File Source",
        "Frequency Filter",
        "Line Source",
        "Phase Shift",
        "Shepard Tone Source",
        "Slew Limiter",
        "Wave Folder",
        "Wave Source",
        "Wave Warp",
        "Wave Window",
    ],
};
