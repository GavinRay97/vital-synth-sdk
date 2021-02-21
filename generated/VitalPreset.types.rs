// Example code that deserializes and serializes the model.
// extern crate serde;
// #[macro_use]
// extern crate serde_derive;
// extern crate serde_json;
//
// use generated_module::[object Object];
//
// fn main() {
//     let json = r#"{"answer": 42}"#;
//     let model: [object Object] = serde_json::from_str(&json).unwrap();
// }

extern crate serde_derive;

#[derive(Serialize, Deserialize)]
pub struct VitalPreset {
    #[serde(rename = "author")]
    author: String,

    #[serde(rename = "comments")]
    comments: String,

    #[serde(rename = "macro1")]
    macro1: String,

    #[serde(rename = "macro2")]
    macro2: String,

    #[serde(rename = "macro3")]
    macro3: String,

    #[serde(rename = "macro4")]
    macro4: String,

    #[serde(rename = "preset_name")]
    preset_name: Option<String>,

    #[serde(rename = "preset_style")]
    preset_style: PresetStyle,

    #[serde(rename = "settings")]
    settings: PresetSettings,

    #[serde(rename = "synth_version")]
    synth_version: String,
}

#[derive(Serialize, Deserialize)]
pub struct PresetSettings {
    #[serde(rename = "beats_per_minute")]
    beats_per_minute: f64,

    #[serde(rename = "bypass")]
    bypass: Option<f64>,

    #[serde(rename = "chorus_cutoff")]
    chorus_cutoff: Option<f64>,

    #[serde(rename = "chorus_damping")]
    chorus_damping: Option<f64>,

    #[serde(rename = "chorus_delay_1")]
    chorus_delay_1: f64,

    #[serde(rename = "chorus_delay_2")]
    chorus_delay_2: f64,

    #[serde(rename = "chorus_dry_wet")]
    chorus_dry_wet: f64,

    #[serde(rename = "chorus_feedback")]
    chorus_feedback: f64,

    #[serde(rename = "chorus_frequency")]
    chorus_frequency: f64,

    #[serde(rename = "chorus_mod_depth")]
    chorus_mod_depth: f64,

    #[serde(rename = "chorus_on")]
    chorus_on: f64,

    #[serde(rename = "chorus_spread")]
    chorus_spread: Option<f64>,

    #[serde(rename = "chorus_sync")]
    chorus_sync: f64,

    #[serde(rename = "chorus_tempo")]
    chorus_tempo: f64,

    #[serde(rename = "chorus_voices")]
    chorus_voices: f64,

    #[serde(rename = "compressor_attack")]
    compressor_attack: f64,

    #[serde(rename = "compressor_band_gain")]
    compressor_band_gain: f64,

    #[serde(rename = "compressor_band_lower_ratio")]
    compressor_band_lower_ratio: f64,

    #[serde(rename = "compressor_band_lower_threshold")]
    compressor_band_lower_threshold: f64,

    #[serde(rename = "compressor_band_upper_ratio")]
    compressor_band_upper_ratio: f64,

    #[serde(rename = "compressor_band_upper_threshold")]
    compressor_band_upper_threshold: f64,

    #[serde(rename = "compressor_enabled_bands")]
    compressor_enabled_bands: f64,

    #[serde(rename = "compressor_high_gain")]
    compressor_high_gain: f64,

    #[serde(rename = "compressor_high_lower_ratio")]
    compressor_high_lower_ratio: f64,

    #[serde(rename = "compressor_high_lower_threshold")]
    compressor_high_lower_threshold: f64,

    #[serde(rename = "compressor_high_upper_ratio")]
    compressor_high_upper_ratio: f64,

    #[serde(rename = "compressor_high_upper_threshold")]
    compressor_high_upper_threshold: f64,

    #[serde(rename = "compressor_low_gain")]
    compressor_low_gain: f64,

    #[serde(rename = "compressor_low_lower_ratio")]
    compressor_low_lower_ratio: f64,

    #[serde(rename = "compressor_low_lower_threshold")]
    compressor_low_lower_threshold: f64,

    #[serde(rename = "compressor_low_upper_ratio")]
    compressor_low_upper_ratio: f64,

    #[serde(rename = "compressor_low_upper_threshold")]
    compressor_low_upper_threshold: f64,

    #[serde(rename = "compressor_mix")]
    compressor_mix: Option<f64>,

    #[serde(rename = "compressor_on")]
    compressor_on: f64,

    #[serde(rename = "compressor_release")]
    compressor_release: f64,

    #[serde(rename = "delay_aux_frequency")]
    delay_aux_frequency: f64,

    #[serde(rename = "delay_aux_sync")]
    delay_aux_sync: f64,

    #[serde(rename = "delay_aux_tempo")]
    delay_aux_tempo: f64,

    #[serde(rename = "delay_dry_wet")]
    delay_dry_wet: f64,

    #[serde(rename = "delay_feedback")]
    delay_feedback: f64,

    #[serde(rename = "delay_filter_cutoff")]
    delay_filter_cutoff: f64,

    #[serde(rename = "delay_filter_spread")]
    delay_filter_spread: f64,

    #[serde(rename = "delay_frequency")]
    delay_frequency: f64,

    #[serde(rename = "delay_on")]
    delay_on: f64,

    #[serde(rename = "delay_style")]
    delay_style: f64,

    #[serde(rename = "delay_sync")]
    delay_sync: f64,

    #[serde(rename = "delay_tempo")]
    delay_tempo: f64,

    #[serde(rename = "distortion_drive")]
    distortion_drive: f64,

    #[serde(rename = "distortion_filter_blend")]
    distortion_filter_blend: f64,

    #[serde(rename = "distortion_filter_cutoff")]
    distortion_filter_cutoff: f64,

    #[serde(rename = "distortion_filter_order")]
    distortion_filter_order: f64,

    #[serde(rename = "distortion_filter_resonance")]
    distortion_filter_resonance: f64,

    #[serde(rename = "distortion_mix")]
    distortion_mix: f64,

    #[serde(rename = "distortion_on")]
    distortion_on: f64,

    #[serde(rename = "distortion_type")]
    distortion_type: f64,

    #[serde(rename = "effect_chain_order")]
    effect_chain_order: f64,

    #[serde(rename = "env_1_attack")]
    env_1__attack: f64,

    #[serde(rename = "env_1_attack_power")]
    env_1__attack_power: f64,

    #[serde(rename = "env_1_decay")]
    env_1__decay: f64,

    #[serde(rename = "env_1_decay_power")]
    env_1__decay_power: f64,

    #[serde(rename = "env_1_delay")]
    env_1__delay: f64,

    #[serde(rename = "env_1_hold")]
    env_1__hold: f64,

    #[serde(rename = "env_1_release")]
    env_1__release: f64,

    #[serde(rename = "env_1_release_power")]
    env_1__release_power: f64,

    #[serde(rename = "env_1_sustain")]
    env_1__sustain: f64,

    #[serde(rename = "env_2_attack")]
    env_2__attack: f64,

    #[serde(rename = "env_2_attack_power")]
    env_2__attack_power: f64,

    #[serde(rename = "env_2_decay")]
    env_2__decay: f64,

    #[serde(rename = "env_2_decay_power")]
    env_2__decay_power: f64,

    #[serde(rename = "env_2_delay")]
    env_2__delay: f64,

    #[serde(rename = "env_2_hold")]
    env_2__hold: f64,

    #[serde(rename = "env_2_release")]
    env_2__release: f64,

    #[serde(rename = "env_2_release_power")]
    env_2__release_power: f64,

    #[serde(rename = "env_2_sustain")]
    env_2__sustain: f64,

    #[serde(rename = "env_3_attack")]
    env_3__attack: f64,

    #[serde(rename = "env_3_attack_power")]
    env_3__attack_power: f64,

    #[serde(rename = "env_3_decay")]
    env_3__decay: f64,

    #[serde(rename = "env_3_decay_power")]
    env_3__decay_power: f64,

    #[serde(rename = "env_3_delay")]
    env_3__delay: f64,

    #[serde(rename = "env_3_hold")]
    env_3__hold: f64,

    #[serde(rename = "env_3_release")]
    env_3__release: f64,

    #[serde(rename = "env_3_release_power")]
    env_3__release_power: f64,

    #[serde(rename = "env_3_sustain")]
    env_3__sustain: f64,

    #[serde(rename = "env_4_attack")]
    env_4__attack: f64,

    #[serde(rename = "env_4_attack_power")]
    env_4__attack_power: f64,

    #[serde(rename = "env_4_decay")]
    env_4__decay: f64,

    #[serde(rename = "env_4_decay_power")]
    env_4__decay_power: f64,

    #[serde(rename = "env_4_delay")]
    env_4__delay: f64,

    #[serde(rename = "env_4_hold")]
    env_4__hold: f64,

    #[serde(rename = "env_4_release")]
    env_4__release: f64,

    #[serde(rename = "env_4_release_power")]
    env_4__release_power: f64,

    #[serde(rename = "env_4_sustain")]
    env_4__sustain: f64,

    #[serde(rename = "env_5_attack")]
    env_5__attack: f64,

    #[serde(rename = "env_5_attack_power")]
    env_5__attack_power: f64,

    #[serde(rename = "env_5_decay")]
    env_5__decay: f64,

    #[serde(rename = "env_5_decay_power")]
    env_5__decay_power: f64,

    #[serde(rename = "env_5_delay")]
    env_5__delay: f64,

    #[serde(rename = "env_5_hold")]
    env_5__hold: f64,

    #[serde(rename = "env_5_release")]
    env_5__release: f64,

    #[serde(rename = "env_5_release_power")]
    env_5__release_power: f64,

    #[serde(rename = "env_5_sustain")]
    env_5__sustain: f64,

    #[serde(rename = "env_6_attack")]
    env_6__attack: f64,

    #[serde(rename = "env_6_attack_power")]
    env_6__attack_power: f64,

    #[serde(rename = "env_6_decay")]
    env_6__decay: f64,

    #[serde(rename = "env_6_decay_power")]
    env_6__decay_power: f64,

    #[serde(rename = "env_6_delay")]
    env_6__delay: f64,

    #[serde(rename = "env_6_hold")]
    env_6__hold: f64,

    #[serde(rename = "env_6_release")]
    env_6__release: f64,

    #[serde(rename = "env_6_release_power")]
    env_6__release_power: f64,

    #[serde(rename = "env_6_sustain")]
    env_6__sustain: f64,

    #[serde(rename = "eq_band_cutoff")]
    eq_band_cutoff: f64,

    #[serde(rename = "eq_band_gain")]
    eq_band_gain: f64,

    #[serde(rename = "eq_band_mode")]
    eq_band_mode: f64,

    #[serde(rename = "eq_band_resonance")]
    eq_band_resonance: f64,

    #[serde(rename = "eq_high_cutoff")]
    eq_high_cutoff: f64,

    #[serde(rename = "eq_high_gain")]
    eq_high_gain: f64,

    #[serde(rename = "eq_high_mode")]
    eq_high_mode: f64,

    #[serde(rename = "eq_high_resonance")]
    eq_high_resonance: f64,

    #[serde(rename = "eq_low_cutoff")]
    eq_low_cutoff: f64,

    #[serde(rename = "eq_low_gain")]
    eq_low_gain: f64,

    #[serde(rename = "eq_low_mode")]
    eq_low_mode: f64,

    #[serde(rename = "eq_low_resonance")]
    eq_low_resonance: f64,

    #[serde(rename = "eq_on")]
    eq_on: f64,

    #[serde(rename = "filter_1_blend")]
    filter_1__blend: f64,

    #[serde(rename = "filter_1_blend_transpose")]
    filter_1__blend_transpose: f64,

    #[serde(rename = "filter_1_cutoff")]
    filter_1__cutoff: f64,

    #[serde(rename = "filter_1_drive")]
    filter_1__drive: f64,

    #[serde(rename = "filter_1_filter_input")]
    filter_1__filter_input: f64,

    #[serde(rename = "filter_1_formant_resonance")]
    filter_1__formant_resonance: f64,

    #[serde(rename = "filter_1_formant_spread")]
    filter_1__formant_spread: Option<f64>,

    #[serde(rename = "filter_1_formant_transpose")]
    filter_1__formant_transpose: f64,

    #[serde(rename = "filter_1_formant_x")]
    filter_1__formant_x: f64,

    #[serde(rename = "filter_1_formant_y")]
    filter_1__formant_y: f64,

    #[serde(rename = "filter_1_keytrack")]
    filter_1__keytrack: f64,

    #[serde(rename = "filter_1_mix")]
    filter_1__mix: f64,

    #[serde(rename = "filter_1_model")]
    filter_1__model: f64,

    #[serde(rename = "filter_1_on")]
    filter_1__on: f64,

    #[serde(rename = "filter_1_resonance")]
    filter_1__resonance: f64,

    #[serde(rename = "filter_1_style")]
    filter_1__style: f64,

    #[serde(rename = "filter_2_blend")]
    filter_2__blend: f64,

    #[serde(rename = "filter_2_blend_transpose")]
    filter_2__blend_transpose: f64,

    #[serde(rename = "filter_2_cutoff")]
    filter_2__cutoff: f64,

    #[serde(rename = "filter_2_drive")]
    filter_2__drive: f64,

    #[serde(rename = "filter_2_filter_input")]
    filter_2__filter_input: f64,

    #[serde(rename = "filter_2_formant_resonance")]
    filter_2__formant_resonance: f64,

    #[serde(rename = "filter_2_formant_spread")]
    filter_2__formant_spread: Option<f64>,

    #[serde(rename = "filter_2_formant_transpose")]
    filter_2__formant_transpose: f64,

    #[serde(rename = "filter_2_formant_x")]
    filter_2__formant_x: f64,

    #[serde(rename = "filter_2_formant_y")]
    filter_2__formant_y: f64,

    #[serde(rename = "filter_2_keytrack")]
    filter_2__keytrack: f64,

    #[serde(rename = "filter_2_mix")]
    filter_2__mix: f64,

    #[serde(rename = "filter_2_model")]
    filter_2__model: f64,

    #[serde(rename = "filter_2_on")]
    filter_2__on: f64,

    #[serde(rename = "filter_2_resonance")]
    filter_2__resonance: f64,

    #[serde(rename = "filter_2_style")]
    filter_2__style: f64,

    #[serde(rename = "filter_fx_blend")]
    filter_fx_blend: f64,

    #[serde(rename = "filter_fx_blend_transpose")]
    filter_fx_blend_transpose: f64,

    #[serde(rename = "filter_fx_cutoff")]
    filter_fx_cutoff: f64,

    #[serde(rename = "filter_fx_drive")]
    filter_fx_drive: f64,

    #[serde(rename = "filter_fx_formant_resonance")]
    filter_fx_formant_resonance: f64,

    #[serde(rename = "filter_fx_formant_spread")]
    filter_fx_formant_spread: Option<f64>,

    #[serde(rename = "filter_fx_formant_transpose")]
    filter_fx_formant_transpose: f64,

    #[serde(rename = "filter_fx_formant_x")]
    filter_fx_formant_x: f64,

    #[serde(rename = "filter_fx_formant_y")]
    filter_fx_formant_y: f64,

    #[serde(rename = "filter_fx_keytrack")]
    filter_fx_keytrack: f64,

    #[serde(rename = "filter_fx_mix")]
    filter_fx_mix: f64,

    #[serde(rename = "filter_fx_model")]
    filter_fx_model: f64,

    #[serde(rename = "filter_fx_on")]
    filter_fx_on: f64,

    #[serde(rename = "filter_fx_resonance")]
    filter_fx_resonance: f64,

    #[serde(rename = "filter_fx_style")]
    filter_fx_style: f64,

    #[serde(rename = "flanger_center")]
    flanger_center: f64,

    #[serde(rename = "flanger_dry_wet")]
    flanger_dry_wet: f64,

    #[serde(rename = "flanger_feedback")]
    flanger_feedback: f64,

    #[serde(rename = "flanger_frequency")]
    flanger_frequency: f64,

    #[serde(rename = "flanger_mod_depth")]
    flanger_mod_depth: f64,

    #[serde(rename = "flanger_on")]
    flanger_on: f64,

    #[serde(rename = "flanger_phase_offset")]
    flanger_phase_offset: f64,

    #[serde(rename = "flanger_sync")]
    flanger_sync: f64,

    #[serde(rename = "flanger_tempo")]
    flanger_tempo: f64,

    #[serde(rename = "legato")]
    legato: f64,

    #[serde(rename = "lfo_1_delay_time")]
    lfo_1__delay_time: f64,

    #[serde(rename = "lfo_1_fade_time")]
    lfo_1__fade_time: f64,

    #[serde(rename = "lfo_1_frequency")]
    lfo_1__frequency: f64,

    #[serde(rename = "lfo_1_keytrack_transpose")]
    lfo_1__keytrack_transpose: Option<f64>,

    #[serde(rename = "lfo_1_keytrack_tune")]
    lfo_1__keytrack_tune: Option<f64>,

    #[serde(rename = "lfo_1_phase")]
    lfo_1__phase: f64,

    #[serde(rename = "lfo_1_smooth_mode")]
    lfo_1__smooth_mode: Option<f64>,

    #[serde(rename = "lfo_1_smooth_time")]
    lfo_1__smooth_time: Option<f64>,

    #[serde(rename = "lfo_1_stereo")]
    lfo_1__stereo: f64,

    #[serde(rename = "lfo_1_sync")]
    lfo_1__sync: f64,

    #[serde(rename = "lfo_1_sync_type")]
    lfo_1__sync_type: f64,

    #[serde(rename = "lfo_1_tempo")]
    lfo_1__tempo: f64,

    #[serde(rename = "lfo_2_delay_time")]
    lfo_2__delay_time: f64,

    #[serde(rename = "lfo_2_fade_time")]
    lfo_2__fade_time: f64,

    #[serde(rename = "lfo_2_frequency")]
    lfo_2__frequency: f64,

    #[serde(rename = "lfo_2_keytrack_transpose")]
    lfo_2__keytrack_transpose: Option<f64>,

    #[serde(rename = "lfo_2_keytrack_tune")]
    lfo_2__keytrack_tune: Option<f64>,

    #[serde(rename = "lfo_2_phase")]
    lfo_2__phase: f64,

    #[serde(rename = "lfo_2_smooth_mode")]
    lfo_2__smooth_mode: Option<f64>,

    #[serde(rename = "lfo_2_smooth_time")]
    lfo_2__smooth_time: Option<f64>,

    #[serde(rename = "lfo_2_stereo")]
    lfo_2__stereo: f64,

    #[serde(rename = "lfo_2_sync")]
    lfo_2__sync: f64,

    #[serde(rename = "lfo_2_sync_type")]
    lfo_2__sync_type: f64,

    #[serde(rename = "lfo_2_tempo")]
    lfo_2__tempo: f64,

    #[serde(rename = "lfo_3_delay_time")]
    lfo_3__delay_time: f64,

    #[serde(rename = "lfo_3_fade_time")]
    lfo_3__fade_time: f64,

    #[serde(rename = "lfo_3_frequency")]
    lfo_3__frequency: f64,

    #[serde(rename = "lfo_3_keytrack_transpose")]
    lfo_3__keytrack_transpose: Option<f64>,

    #[serde(rename = "lfo_3_keytrack_tune")]
    lfo_3__keytrack_tune: Option<f64>,

    #[serde(rename = "lfo_3_phase")]
    lfo_3__phase: f64,

    #[serde(rename = "lfo_3_smooth_mode")]
    lfo_3__smooth_mode: Option<f64>,

    #[serde(rename = "lfo_3_smooth_time")]
    lfo_3__smooth_time: Option<f64>,

    #[serde(rename = "lfo_3_stereo")]
    lfo_3__stereo: f64,

    #[serde(rename = "lfo_3_sync")]
    lfo_3__sync: f64,

    #[serde(rename = "lfo_3_sync_type")]
    lfo_3__sync_type: f64,

    #[serde(rename = "lfo_3_tempo")]
    lfo_3__tempo: f64,

    #[serde(rename = "lfo_4_delay_time")]
    lfo_4__delay_time: f64,

    #[serde(rename = "lfo_4_fade_time")]
    lfo_4__fade_time: f64,

    #[serde(rename = "lfo_4_frequency")]
    lfo_4__frequency: f64,

    #[serde(rename = "lfo_4_keytrack_transpose")]
    lfo_4__keytrack_transpose: Option<f64>,

    #[serde(rename = "lfo_4_keytrack_tune")]
    lfo_4__keytrack_tune: Option<f64>,

    #[serde(rename = "lfo_4_phase")]
    lfo_4__phase: f64,

    #[serde(rename = "lfo_4_smooth_mode")]
    lfo_4__smooth_mode: Option<f64>,

    #[serde(rename = "lfo_4_smooth_time")]
    lfo_4__smooth_time: Option<f64>,

    #[serde(rename = "lfo_4_stereo")]
    lfo_4__stereo: f64,

    #[serde(rename = "lfo_4_sync")]
    lfo_4__sync: f64,

    #[serde(rename = "lfo_4_sync_type")]
    lfo_4__sync_type: f64,

    #[serde(rename = "lfo_4_tempo")]
    lfo_4__tempo: f64,

    #[serde(rename = "lfo_5_delay_time")]
    lfo_5__delay_time: f64,

    #[serde(rename = "lfo_5_fade_time")]
    lfo_5__fade_time: f64,

    #[serde(rename = "lfo_5_frequency")]
    lfo_5__frequency: f64,

    #[serde(rename = "lfo_5_keytrack_transpose")]
    lfo_5__keytrack_transpose: Option<f64>,

    #[serde(rename = "lfo_5_keytrack_tune")]
    lfo_5__keytrack_tune: Option<f64>,

    #[serde(rename = "lfo_5_phase")]
    lfo_5__phase: f64,

    #[serde(rename = "lfo_5_smooth_mode")]
    lfo_5__smooth_mode: Option<f64>,

    #[serde(rename = "lfo_5_smooth_time")]
    lfo_5__smooth_time: Option<f64>,

    #[serde(rename = "lfo_5_stereo")]
    lfo_5__stereo: f64,

    #[serde(rename = "lfo_5_sync")]
    lfo_5__sync: f64,

    #[serde(rename = "lfo_5_sync_type")]
    lfo_5__sync_type: f64,

    #[serde(rename = "lfo_5_tempo")]
    lfo_5__tempo: f64,

    #[serde(rename = "lfo_6_delay_time")]
    lfo_6__delay_time: f64,

    #[serde(rename = "lfo_6_fade_time")]
    lfo_6__fade_time: f64,

    #[serde(rename = "lfo_6_frequency")]
    lfo_6__frequency: f64,

    #[serde(rename = "lfo_6_keytrack_transpose")]
    lfo_6__keytrack_transpose: Option<f64>,

    #[serde(rename = "lfo_6_keytrack_tune")]
    lfo_6__keytrack_tune: Option<f64>,

    #[serde(rename = "lfo_6_phase")]
    lfo_6__phase: f64,

    #[serde(rename = "lfo_6_smooth_mode")]
    lfo_6__smooth_mode: Option<f64>,

    #[serde(rename = "lfo_6_smooth_time")]
    lfo_6__smooth_time: Option<f64>,

    #[serde(rename = "lfo_6_stereo")]
    lfo_6__stereo: f64,

    #[serde(rename = "lfo_6_sync")]
    lfo_6__sync: f64,

    #[serde(rename = "lfo_6_sync_type")]
    lfo_6__sync_type: f64,

    #[serde(rename = "lfo_6_tempo")]
    lfo_6__tempo: f64,

    #[serde(rename = "lfo_7_delay_time")]
    lfo_7__delay_time: f64,

    #[serde(rename = "lfo_7_fade_time")]
    lfo_7__fade_time: f64,

    #[serde(rename = "lfo_7_frequency")]
    lfo_7__frequency: f64,

    #[serde(rename = "lfo_7_keytrack_transpose")]
    lfo_7__keytrack_transpose: Option<f64>,

    #[serde(rename = "lfo_7_keytrack_tune")]
    lfo_7__keytrack_tune: Option<f64>,

    #[serde(rename = "lfo_7_phase")]
    lfo_7__phase: f64,

    #[serde(rename = "lfo_7_smooth_mode")]
    lfo_7__smooth_mode: Option<f64>,

    #[serde(rename = "lfo_7_smooth_time")]
    lfo_7__smooth_time: Option<f64>,

    #[serde(rename = "lfo_7_stereo")]
    lfo_7__stereo: f64,

    #[serde(rename = "lfo_7_sync")]
    lfo_7__sync: f64,

    #[serde(rename = "lfo_7_sync_type")]
    lfo_7__sync_type: f64,

    #[serde(rename = "lfo_7_tempo")]
    lfo_7__tempo: f64,

    #[serde(rename = "lfo_8_delay_time")]
    lfo_8__delay_time: f64,

    #[serde(rename = "lfo_8_fade_time")]
    lfo_8__fade_time: f64,

    #[serde(rename = "lfo_8_frequency")]
    lfo_8__frequency: f64,

    #[serde(rename = "lfo_8_keytrack_transpose")]
    lfo_8__keytrack_transpose: Option<f64>,

    #[serde(rename = "lfo_8_keytrack_tune")]
    lfo_8__keytrack_tune: Option<f64>,

    #[serde(rename = "lfo_8_phase")]
    lfo_8__phase: f64,

    #[serde(rename = "lfo_8_smooth_mode")]
    lfo_8__smooth_mode: Option<f64>,

    #[serde(rename = "lfo_8_smooth_time")]
    lfo_8__smooth_time: Option<f64>,

    #[serde(rename = "lfo_8_stereo")]
    lfo_8__stereo: f64,

    #[serde(rename = "lfo_8_sync")]
    lfo_8__sync: f64,

    #[serde(rename = "lfo_8_sync_type")]
    lfo_8__sync_type: f64,

    #[serde(rename = "lfo_8_tempo")]
    lfo_8__tempo: f64,

    #[serde(rename = "lfos")]
    lfos: Vec<Lfo>,

    #[serde(rename = "macro_control_1")]
    macro_control_1: f64,

    #[serde(rename = "macro_control_2")]
    macro_control_2: f64,

    #[serde(rename = "macro_control_3")]
    macro_control_3: f64,

    #[serde(rename = "macro_control_4")]
    macro_control_4: f64,

    #[serde(rename = "mod_wheel")]
    mod_wheel: f64,

    #[serde(rename = "modulation_10_amount")]
    modulation_10__amount: f64,

    #[serde(rename = "modulation_10_bipolar")]
    modulation_10__bipolar: f64,

    #[serde(rename = "modulation_10_bypass")]
    modulation_10__bypass: f64,

    #[serde(rename = "modulation_10_power")]
    modulation_10__power: f64,

    #[serde(rename = "modulation_10_stereo")]
    modulation_10__stereo: f64,

    #[serde(rename = "modulation_11_amount")]
    modulation_11__amount: f64,

    #[serde(rename = "modulation_11_bipolar")]
    modulation_11__bipolar: f64,

    #[serde(rename = "modulation_11_bypass")]
    modulation_11__bypass: f64,

    #[serde(rename = "modulation_11_power")]
    modulation_11__power: f64,

    #[serde(rename = "modulation_11_stereo")]
    modulation_11__stereo: f64,

    #[serde(rename = "modulation_12_amount")]
    modulation_12__amount: f64,

    #[serde(rename = "modulation_12_bipolar")]
    modulation_12__bipolar: f64,

    #[serde(rename = "modulation_12_bypass")]
    modulation_12__bypass: f64,

    #[serde(rename = "modulation_12_power")]
    modulation_12__power: f64,

    #[serde(rename = "modulation_12_stereo")]
    modulation_12__stereo: f64,

    #[serde(rename = "modulation_13_amount")]
    modulation_13__amount: f64,

    #[serde(rename = "modulation_13_bipolar")]
    modulation_13__bipolar: f64,

    #[serde(rename = "modulation_13_bypass")]
    modulation_13__bypass: f64,

    #[serde(rename = "modulation_13_power")]
    modulation_13__power: f64,

    #[serde(rename = "modulation_13_stereo")]
    modulation_13__stereo: f64,

    #[serde(rename = "modulation_14_amount")]
    modulation_14__amount: f64,

    #[serde(rename = "modulation_14_bipolar")]
    modulation_14__bipolar: f64,

    #[serde(rename = "modulation_14_bypass")]
    modulation_14__bypass: f64,

    #[serde(rename = "modulation_14_power")]
    modulation_14__power: f64,

    #[serde(rename = "modulation_14_stereo")]
    modulation_14__stereo: f64,

    #[serde(rename = "modulation_15_amount")]
    modulation_15__amount: f64,

    #[serde(rename = "modulation_15_bipolar")]
    modulation_15__bipolar: f64,

    #[serde(rename = "modulation_15_bypass")]
    modulation_15__bypass: f64,

    #[serde(rename = "modulation_15_power")]
    modulation_15__power: f64,

    #[serde(rename = "modulation_15_stereo")]
    modulation_15__stereo: f64,

    #[serde(rename = "modulation_16_amount")]
    modulation_16__amount: f64,

    #[serde(rename = "modulation_16_bipolar")]
    modulation_16__bipolar: f64,

    #[serde(rename = "modulation_16_bypass")]
    modulation_16__bypass: f64,

    #[serde(rename = "modulation_16_power")]
    modulation_16__power: f64,

    #[serde(rename = "modulation_16_stereo")]
    modulation_16__stereo: f64,

    #[serde(rename = "modulation_17_amount")]
    modulation_17__amount: f64,

    #[serde(rename = "modulation_17_bipolar")]
    modulation_17__bipolar: f64,

    #[serde(rename = "modulation_17_bypass")]
    modulation_17__bypass: f64,

    #[serde(rename = "modulation_17_power")]
    modulation_17__power: f64,

    #[serde(rename = "modulation_17_stereo")]
    modulation_17__stereo: f64,

    #[serde(rename = "modulation_18_amount")]
    modulation_18__amount: f64,

    #[serde(rename = "modulation_18_bipolar")]
    modulation_18__bipolar: f64,

    #[serde(rename = "modulation_18_bypass")]
    modulation_18__bypass: f64,

    #[serde(rename = "modulation_18_power")]
    modulation_18__power: f64,

    #[serde(rename = "modulation_18_stereo")]
    modulation_18__stereo: f64,

    #[serde(rename = "modulation_19_amount")]
    modulation_19__amount: f64,

    #[serde(rename = "modulation_19_bipolar")]
    modulation_19__bipolar: f64,

    #[serde(rename = "modulation_19_bypass")]
    modulation_19__bypass: f64,

    #[serde(rename = "modulation_19_power")]
    modulation_19__power: f64,

    #[serde(rename = "modulation_19_stereo")]
    modulation_19__stereo: f64,

    #[serde(rename = "modulation_1_amount")]
    modulation_1__amount: f64,

    #[serde(rename = "modulation_1_bipolar")]
    modulation_1__bipolar: f64,

    #[serde(rename = "modulation_1_bypass")]
    modulation_1__bypass: f64,

    #[serde(rename = "modulation_1_power")]
    modulation_1__power: f64,

    #[serde(rename = "modulation_1_stereo")]
    modulation_1__stereo: f64,

    #[serde(rename = "modulation_20_amount")]
    modulation_20__amount: f64,

    #[serde(rename = "modulation_20_bipolar")]
    modulation_20__bipolar: f64,

    #[serde(rename = "modulation_20_bypass")]
    modulation_20__bypass: f64,

    #[serde(rename = "modulation_20_power")]
    modulation_20__power: f64,

    #[serde(rename = "modulation_20_stereo")]
    modulation_20__stereo: f64,

    #[serde(rename = "modulation_21_amount")]
    modulation_21__amount: f64,

    #[serde(rename = "modulation_21_bipolar")]
    modulation_21__bipolar: f64,

    #[serde(rename = "modulation_21_bypass")]
    modulation_21__bypass: f64,

    #[serde(rename = "modulation_21_power")]
    modulation_21__power: f64,

    #[serde(rename = "modulation_21_stereo")]
    modulation_21__stereo: f64,

    #[serde(rename = "modulation_22_amount")]
    modulation_22__amount: f64,

    #[serde(rename = "modulation_22_bipolar")]
    modulation_22__bipolar: f64,

    #[serde(rename = "modulation_22_bypass")]
    modulation_22__bypass: f64,

    #[serde(rename = "modulation_22_power")]
    modulation_22__power: f64,

    #[serde(rename = "modulation_22_stereo")]
    modulation_22__stereo: f64,

    #[serde(rename = "modulation_23_amount")]
    modulation_23__amount: f64,

    #[serde(rename = "modulation_23_bipolar")]
    modulation_23__bipolar: f64,

    #[serde(rename = "modulation_23_bypass")]
    modulation_23__bypass: f64,

    #[serde(rename = "modulation_23_power")]
    modulation_23__power: f64,

    #[serde(rename = "modulation_23_stereo")]
    modulation_23__stereo: f64,

    #[serde(rename = "modulation_24_amount")]
    modulation_24__amount: f64,

    #[serde(rename = "modulation_24_bipolar")]
    modulation_24__bipolar: f64,

    #[serde(rename = "modulation_24_bypass")]
    modulation_24__bypass: f64,

    #[serde(rename = "modulation_24_power")]
    modulation_24__power: f64,

    #[serde(rename = "modulation_24_stereo")]
    modulation_24__stereo: f64,

    #[serde(rename = "modulation_25_amount")]
    modulation_25__amount: f64,

    #[serde(rename = "modulation_25_bipolar")]
    modulation_25__bipolar: f64,

    #[serde(rename = "modulation_25_bypass")]
    modulation_25__bypass: f64,

    #[serde(rename = "modulation_25_power")]
    modulation_25__power: f64,

    #[serde(rename = "modulation_25_stereo")]
    modulation_25__stereo: f64,

    #[serde(rename = "modulation_26_amount")]
    modulation_26__amount: f64,

    #[serde(rename = "modulation_26_bipolar")]
    modulation_26__bipolar: f64,

    #[serde(rename = "modulation_26_bypass")]
    modulation_26__bypass: f64,

    #[serde(rename = "modulation_26_power")]
    modulation_26__power: f64,

    #[serde(rename = "modulation_26_stereo")]
    modulation_26__stereo: f64,

    #[serde(rename = "modulation_27_amount")]
    modulation_27__amount: f64,

    #[serde(rename = "modulation_27_bipolar")]
    modulation_27__bipolar: f64,

    #[serde(rename = "modulation_27_bypass")]
    modulation_27__bypass: f64,

    #[serde(rename = "modulation_27_power")]
    modulation_27__power: f64,

    #[serde(rename = "modulation_27_stereo")]
    modulation_27__stereo: f64,

    #[serde(rename = "modulation_28_amount")]
    modulation_28__amount: f64,

    #[serde(rename = "modulation_28_bipolar")]
    modulation_28__bipolar: f64,

    #[serde(rename = "modulation_28_bypass")]
    modulation_28__bypass: f64,

    #[serde(rename = "modulation_28_power")]
    modulation_28__power: f64,

    #[serde(rename = "modulation_28_stereo")]
    modulation_28__stereo: f64,

    #[serde(rename = "modulation_29_amount")]
    modulation_29__amount: f64,

    #[serde(rename = "modulation_29_bipolar")]
    modulation_29__bipolar: f64,

    #[serde(rename = "modulation_29_bypass")]
    modulation_29__bypass: f64,

    #[serde(rename = "modulation_29_power")]
    modulation_29__power: f64,

    #[serde(rename = "modulation_29_stereo")]
    modulation_29__stereo: f64,

    #[serde(rename = "modulation_2_amount")]
    modulation_2__amount: f64,

    #[serde(rename = "modulation_2_bipolar")]
    modulation_2__bipolar: f64,

    #[serde(rename = "modulation_2_bypass")]
    modulation_2__bypass: f64,

    #[serde(rename = "modulation_2_power")]
    modulation_2__power: f64,

    #[serde(rename = "modulation_2_stereo")]
    modulation_2__stereo: f64,

    #[serde(rename = "modulation_30_amount")]
    modulation_30__amount: f64,

    #[serde(rename = "modulation_30_bipolar")]
    modulation_30__bipolar: f64,

    #[serde(rename = "modulation_30_bypass")]
    modulation_30__bypass: f64,

    #[serde(rename = "modulation_30_power")]
    modulation_30__power: f64,

    #[serde(rename = "modulation_30_stereo")]
    modulation_30__stereo: f64,

    #[serde(rename = "modulation_31_amount")]
    modulation_31__amount: f64,

    #[serde(rename = "modulation_31_bipolar")]
    modulation_31__bipolar: f64,

    #[serde(rename = "modulation_31_bypass")]
    modulation_31__bypass: f64,

    #[serde(rename = "modulation_31_power")]
    modulation_31__power: f64,

    #[serde(rename = "modulation_31_stereo")]
    modulation_31__stereo: f64,

    #[serde(rename = "modulation_32_amount")]
    modulation_32__amount: f64,

    #[serde(rename = "modulation_32_bipolar")]
    modulation_32__bipolar: f64,

    #[serde(rename = "modulation_32_bypass")]
    modulation_32__bypass: f64,

    #[serde(rename = "modulation_32_power")]
    modulation_32__power: f64,

    #[serde(rename = "modulation_32_stereo")]
    modulation_32__stereo: f64,

    #[serde(rename = "modulation_33_amount")]
    modulation_33__amount: f64,

    #[serde(rename = "modulation_33_bipolar")]
    modulation_33__bipolar: f64,

    #[serde(rename = "modulation_33_bypass")]
    modulation_33__bypass: f64,

    #[serde(rename = "modulation_33_power")]
    modulation_33__power: f64,

    #[serde(rename = "modulation_33_stereo")]
    modulation_33__stereo: f64,

    #[serde(rename = "modulation_34_amount")]
    modulation_34__amount: f64,

    #[serde(rename = "modulation_34_bipolar")]
    modulation_34__bipolar: f64,

    #[serde(rename = "modulation_34_bypass")]
    modulation_34__bypass: f64,

    #[serde(rename = "modulation_34_power")]
    modulation_34__power: f64,

    #[serde(rename = "modulation_34_stereo")]
    modulation_34__stereo: f64,

    #[serde(rename = "modulation_35_amount")]
    modulation_35__amount: f64,

    #[serde(rename = "modulation_35_bipolar")]
    modulation_35__bipolar: f64,

    #[serde(rename = "modulation_35_bypass")]
    modulation_35__bypass: f64,

    #[serde(rename = "modulation_35_power")]
    modulation_35__power: f64,

    #[serde(rename = "modulation_35_stereo")]
    modulation_35__stereo: f64,

    #[serde(rename = "modulation_36_amount")]
    modulation_36__amount: f64,

    #[serde(rename = "modulation_36_bipolar")]
    modulation_36__bipolar: f64,

    #[serde(rename = "modulation_36_bypass")]
    modulation_36__bypass: f64,

    #[serde(rename = "modulation_36_power")]
    modulation_36__power: f64,

    #[serde(rename = "modulation_36_stereo")]
    modulation_36__stereo: f64,

    #[serde(rename = "modulation_37_amount")]
    modulation_37__amount: f64,

    #[serde(rename = "modulation_37_bipolar")]
    modulation_37__bipolar: f64,

    #[serde(rename = "modulation_37_bypass")]
    modulation_37__bypass: f64,

    #[serde(rename = "modulation_37_power")]
    modulation_37__power: f64,

    #[serde(rename = "modulation_37_stereo")]
    modulation_37__stereo: f64,

    #[serde(rename = "modulation_38_amount")]
    modulation_38__amount: f64,

    #[serde(rename = "modulation_38_bipolar")]
    modulation_38__bipolar: f64,

    #[serde(rename = "modulation_38_bypass")]
    modulation_38__bypass: f64,

    #[serde(rename = "modulation_38_power")]
    modulation_38__power: f64,

    #[serde(rename = "modulation_38_stereo")]
    modulation_38__stereo: f64,

    #[serde(rename = "modulation_39_amount")]
    modulation_39__amount: f64,

    #[serde(rename = "modulation_39_bipolar")]
    modulation_39__bipolar: f64,

    #[serde(rename = "modulation_39_bypass")]
    modulation_39__bypass: f64,

    #[serde(rename = "modulation_39_power")]
    modulation_39__power: f64,

    #[serde(rename = "modulation_39_stereo")]
    modulation_39__stereo: f64,

    #[serde(rename = "modulation_3_amount")]
    modulation_3__amount: f64,

    #[serde(rename = "modulation_3_bipolar")]
    modulation_3__bipolar: f64,

    #[serde(rename = "modulation_3_bypass")]
    modulation_3__bypass: f64,

    #[serde(rename = "modulation_3_power")]
    modulation_3__power: f64,

    #[serde(rename = "modulation_3_stereo")]
    modulation_3__stereo: f64,

    #[serde(rename = "modulation_40_amount")]
    modulation_40__amount: f64,

    #[serde(rename = "modulation_40_bipolar")]
    modulation_40__bipolar: f64,

    #[serde(rename = "modulation_40_bypass")]
    modulation_40__bypass: f64,

    #[serde(rename = "modulation_40_power")]
    modulation_40__power: f64,

    #[serde(rename = "modulation_40_stereo")]
    modulation_40__stereo: f64,

    #[serde(rename = "modulation_41_amount")]
    modulation_41__amount: f64,

    #[serde(rename = "modulation_41_bipolar")]
    modulation_41__bipolar: f64,

    #[serde(rename = "modulation_41_bypass")]
    modulation_41__bypass: f64,

    #[serde(rename = "modulation_41_power")]
    modulation_41__power: f64,

    #[serde(rename = "modulation_41_stereo")]
    modulation_41__stereo: f64,

    #[serde(rename = "modulation_42_amount")]
    modulation_42__amount: f64,

    #[serde(rename = "modulation_42_bipolar")]
    modulation_42__bipolar: f64,

    #[serde(rename = "modulation_42_bypass")]
    modulation_42__bypass: f64,

    #[serde(rename = "modulation_42_power")]
    modulation_42__power: f64,

    #[serde(rename = "modulation_42_stereo")]
    modulation_42__stereo: f64,

    #[serde(rename = "modulation_43_amount")]
    modulation_43__amount: f64,

    #[serde(rename = "modulation_43_bipolar")]
    modulation_43__bipolar: f64,

    #[serde(rename = "modulation_43_bypass")]
    modulation_43__bypass: f64,

    #[serde(rename = "modulation_43_power")]
    modulation_43__power: f64,

    #[serde(rename = "modulation_43_stereo")]
    modulation_43__stereo: f64,

    #[serde(rename = "modulation_44_amount")]
    modulation_44__amount: f64,

    #[serde(rename = "modulation_44_bipolar")]
    modulation_44__bipolar: f64,

    #[serde(rename = "modulation_44_bypass")]
    modulation_44__bypass: f64,

    #[serde(rename = "modulation_44_power")]
    modulation_44__power: f64,

    #[serde(rename = "modulation_44_stereo")]
    modulation_44__stereo: f64,

    #[serde(rename = "modulation_45_amount")]
    modulation_45__amount: f64,

    #[serde(rename = "modulation_45_bipolar")]
    modulation_45__bipolar: f64,

    #[serde(rename = "modulation_45_bypass")]
    modulation_45__bypass: f64,

    #[serde(rename = "modulation_45_power")]
    modulation_45__power: f64,

    #[serde(rename = "modulation_45_stereo")]
    modulation_45__stereo: f64,

    #[serde(rename = "modulation_46_amount")]
    modulation_46__amount: f64,

    #[serde(rename = "modulation_46_bipolar")]
    modulation_46__bipolar: f64,

    #[serde(rename = "modulation_46_bypass")]
    modulation_46__bypass: f64,

    #[serde(rename = "modulation_46_power")]
    modulation_46__power: f64,

    #[serde(rename = "modulation_46_stereo")]
    modulation_46__stereo: f64,

    #[serde(rename = "modulation_47_amount")]
    modulation_47__amount: f64,

    #[serde(rename = "modulation_47_bipolar")]
    modulation_47__bipolar: f64,

    #[serde(rename = "modulation_47_bypass")]
    modulation_47__bypass: f64,

    #[serde(rename = "modulation_47_power")]
    modulation_47__power: f64,

    #[serde(rename = "modulation_47_stereo")]
    modulation_47__stereo: f64,

    #[serde(rename = "modulation_48_amount")]
    modulation_48__amount: f64,

    #[serde(rename = "modulation_48_bipolar")]
    modulation_48__bipolar: f64,

    #[serde(rename = "modulation_48_bypass")]
    modulation_48__bypass: f64,

    #[serde(rename = "modulation_48_power")]
    modulation_48__power: f64,

    #[serde(rename = "modulation_48_stereo")]
    modulation_48__stereo: f64,

    #[serde(rename = "modulation_49_amount")]
    modulation_49__amount: f64,

    #[serde(rename = "modulation_49_bipolar")]
    modulation_49__bipolar: f64,

    #[serde(rename = "modulation_49_bypass")]
    modulation_49__bypass: f64,

    #[serde(rename = "modulation_49_power")]
    modulation_49__power: f64,

    #[serde(rename = "modulation_49_stereo")]
    modulation_49__stereo: f64,

    #[serde(rename = "modulation_4_amount")]
    modulation_4__amount: f64,

    #[serde(rename = "modulation_4_bipolar")]
    modulation_4__bipolar: f64,

    #[serde(rename = "modulation_4_bypass")]
    modulation_4__bypass: f64,

    #[serde(rename = "modulation_4_power")]
    modulation_4__power: f64,

    #[serde(rename = "modulation_4_stereo")]
    modulation_4__stereo: f64,

    #[serde(rename = "modulation_50_amount")]
    modulation_50__amount: f64,

    #[serde(rename = "modulation_50_bipolar")]
    modulation_50__bipolar: f64,

    #[serde(rename = "modulation_50_bypass")]
    modulation_50__bypass: f64,

    #[serde(rename = "modulation_50_power")]
    modulation_50__power: f64,

    #[serde(rename = "modulation_50_stereo")]
    modulation_50__stereo: f64,

    #[serde(rename = "modulation_51_amount")]
    modulation_51__amount: f64,

    #[serde(rename = "modulation_51_bipolar")]
    modulation_51__bipolar: f64,

    #[serde(rename = "modulation_51_bypass")]
    modulation_51__bypass: f64,

    #[serde(rename = "modulation_51_power")]
    modulation_51__power: f64,

    #[serde(rename = "modulation_51_stereo")]
    modulation_51__stereo: f64,

    #[serde(rename = "modulation_52_amount")]
    modulation_52__amount: f64,

    #[serde(rename = "modulation_52_bipolar")]
    modulation_52__bipolar: f64,

    #[serde(rename = "modulation_52_bypass")]
    modulation_52__bypass: f64,

    #[serde(rename = "modulation_52_power")]
    modulation_52__power: f64,

    #[serde(rename = "modulation_52_stereo")]
    modulation_52__stereo: f64,

    #[serde(rename = "modulation_53_amount")]
    modulation_53__amount: f64,

    #[serde(rename = "modulation_53_bipolar")]
    modulation_53__bipolar: f64,

    #[serde(rename = "modulation_53_bypass")]
    modulation_53__bypass: f64,

    #[serde(rename = "modulation_53_power")]
    modulation_53__power: f64,

    #[serde(rename = "modulation_53_stereo")]
    modulation_53__stereo: f64,

    #[serde(rename = "modulation_54_amount")]
    modulation_54__amount: f64,

    #[serde(rename = "modulation_54_bipolar")]
    modulation_54__bipolar: f64,

    #[serde(rename = "modulation_54_bypass")]
    modulation_54__bypass: f64,

    #[serde(rename = "modulation_54_power")]
    modulation_54__power: f64,

    #[serde(rename = "modulation_54_stereo")]
    modulation_54__stereo: f64,

    #[serde(rename = "modulation_55_amount")]
    modulation_55__amount: f64,

    #[serde(rename = "modulation_55_bipolar")]
    modulation_55__bipolar: f64,

    #[serde(rename = "modulation_55_bypass")]
    modulation_55__bypass: f64,

    #[serde(rename = "modulation_55_power")]
    modulation_55__power: f64,

    #[serde(rename = "modulation_55_stereo")]
    modulation_55__stereo: f64,

    #[serde(rename = "modulation_56_amount")]
    modulation_56__amount: f64,

    #[serde(rename = "modulation_56_bipolar")]
    modulation_56__bipolar: f64,

    #[serde(rename = "modulation_56_bypass")]
    modulation_56__bypass: f64,

    #[serde(rename = "modulation_56_power")]
    modulation_56__power: f64,

    #[serde(rename = "modulation_56_stereo")]
    modulation_56__stereo: f64,

    #[serde(rename = "modulation_57_amount")]
    modulation_57__amount: f64,

    #[serde(rename = "modulation_57_bipolar")]
    modulation_57__bipolar: f64,

    #[serde(rename = "modulation_57_bypass")]
    modulation_57__bypass: f64,

    #[serde(rename = "modulation_57_power")]
    modulation_57__power: f64,

    #[serde(rename = "modulation_57_stereo")]
    modulation_57__stereo: f64,

    #[serde(rename = "modulation_58_amount")]
    modulation_58__amount: f64,

    #[serde(rename = "modulation_58_bipolar")]
    modulation_58__bipolar: f64,

    #[serde(rename = "modulation_58_bypass")]
    modulation_58__bypass: f64,

    #[serde(rename = "modulation_58_power")]
    modulation_58__power: f64,

    #[serde(rename = "modulation_58_stereo")]
    modulation_58__stereo: f64,

    #[serde(rename = "modulation_59_amount")]
    modulation_59__amount: f64,

    #[serde(rename = "modulation_59_bipolar")]
    modulation_59__bipolar: f64,

    #[serde(rename = "modulation_59_bypass")]
    modulation_59__bypass: f64,

    #[serde(rename = "modulation_59_power")]
    modulation_59__power: f64,

    #[serde(rename = "modulation_59_stereo")]
    modulation_59__stereo: f64,

    #[serde(rename = "modulation_5_amount")]
    modulation_5__amount: f64,

    #[serde(rename = "modulation_5_bipolar")]
    modulation_5__bipolar: f64,

    #[serde(rename = "modulation_5_bypass")]
    modulation_5__bypass: f64,

    #[serde(rename = "modulation_5_power")]
    modulation_5__power: f64,

    #[serde(rename = "modulation_5_stereo")]
    modulation_5__stereo: f64,

    #[serde(rename = "modulation_60_amount")]
    modulation_60__amount: f64,

    #[serde(rename = "modulation_60_bipolar")]
    modulation_60__bipolar: f64,

    #[serde(rename = "modulation_60_bypass")]
    modulation_60__bypass: f64,

    #[serde(rename = "modulation_60_power")]
    modulation_60__power: f64,

    #[serde(rename = "modulation_60_stereo")]
    modulation_60__stereo: f64,

    #[serde(rename = "modulation_61_amount")]
    modulation_61__amount: f64,

    #[serde(rename = "modulation_61_bipolar")]
    modulation_61__bipolar: f64,

    #[serde(rename = "modulation_61_bypass")]
    modulation_61__bypass: f64,

    #[serde(rename = "modulation_61_power")]
    modulation_61__power: f64,

    #[serde(rename = "modulation_61_stereo")]
    modulation_61__stereo: f64,

    #[serde(rename = "modulation_62_amount")]
    modulation_62__amount: f64,

    #[serde(rename = "modulation_62_bipolar")]
    modulation_62__bipolar: f64,

    #[serde(rename = "modulation_62_bypass")]
    modulation_62__bypass: f64,

    #[serde(rename = "modulation_62_power")]
    modulation_62__power: f64,

    #[serde(rename = "modulation_62_stereo")]
    modulation_62__stereo: f64,

    #[serde(rename = "modulation_63_amount")]
    modulation_63__amount: f64,

    #[serde(rename = "modulation_63_bipolar")]
    modulation_63__bipolar: f64,

    #[serde(rename = "modulation_63_bypass")]
    modulation_63__bypass: f64,

    #[serde(rename = "modulation_63_power")]
    modulation_63__power: f64,

    #[serde(rename = "modulation_63_stereo")]
    modulation_63__stereo: f64,

    #[serde(rename = "modulation_64_amount")]
    modulation_64__amount: f64,

    #[serde(rename = "modulation_64_bipolar")]
    modulation_64__bipolar: f64,

    #[serde(rename = "modulation_64_bypass")]
    modulation_64__bypass: f64,

    #[serde(rename = "modulation_64_power")]
    modulation_64__power: f64,

    #[serde(rename = "modulation_64_stereo")]
    modulation_64__stereo: f64,

    #[serde(rename = "modulation_6_amount")]
    modulation_6__amount: f64,

    #[serde(rename = "modulation_6_bipolar")]
    modulation_6__bipolar: f64,

    #[serde(rename = "modulation_6_bypass")]
    modulation_6__bypass: f64,

    #[serde(rename = "modulation_6_power")]
    modulation_6__power: f64,

    #[serde(rename = "modulation_6_stereo")]
    modulation_6__stereo: f64,

    #[serde(rename = "modulation_7_amount")]
    modulation_7__amount: f64,

    #[serde(rename = "modulation_7_bipolar")]
    modulation_7__bipolar: f64,

    #[serde(rename = "modulation_7_bypass")]
    modulation_7__bypass: f64,

    #[serde(rename = "modulation_7_power")]
    modulation_7__power: f64,

    #[serde(rename = "modulation_7_stereo")]
    modulation_7__stereo: f64,

    #[serde(rename = "modulation_8_amount")]
    modulation_8__amount: f64,

    #[serde(rename = "modulation_8_bipolar")]
    modulation_8__bipolar: f64,

    #[serde(rename = "modulation_8_bypass")]
    modulation_8__bypass: f64,

    #[serde(rename = "modulation_8_power")]
    modulation_8__power: f64,

    #[serde(rename = "modulation_8_stereo")]
    modulation_8__stereo: f64,

    #[serde(rename = "modulation_9_amount")]
    modulation_9__amount: f64,

    #[serde(rename = "modulation_9_bipolar")]
    modulation_9__bipolar: f64,

    #[serde(rename = "modulation_9_bypass")]
    modulation_9__bypass: f64,

    #[serde(rename = "modulation_9_power")]
    modulation_9__power: f64,

    #[serde(rename = "modulation_9_stereo")]
    modulation_9__stereo: f64,

    #[serde(rename = "modulations")]
    modulations: Vec<Modulation>,

    #[serde(rename = "osc_1_destination")]
    osc_1__destination: f64,

    #[serde(rename = "osc_1_detune_power")]
    osc_1__detune_power: f64,

    #[serde(rename = "osc_1_detune_range")]
    osc_1__detune_range: f64,

    #[serde(rename = "osc_1_distortion_amount")]
    osc_1__distortion_amount: f64,

    #[serde(rename = "osc_1_distortion_phase")]
    osc_1__distortion_phase: f64,

    #[serde(rename = "osc_1_distortion_spread")]
    osc_1__distortion_spread: f64,

    #[serde(rename = "osc_1_distortion_type")]
    osc_1__distortion_type: f64,

    #[serde(rename = "osc_1_frame_spread")]
    osc_1__frame_spread: f64,

    #[serde(rename = "osc_1_level")]
    osc_1__level: f64,

    #[serde(rename = "osc_1_midi_track")]
    osc_1__midi_track: f64,

    #[serde(rename = "osc_1_on")]
    osc_1__on: f64,

    #[serde(rename = "osc_1_pan")]
    osc_1__pan: f64,

    #[serde(rename = "osc_1_phase")]
    osc_1__phase: f64,

    #[serde(rename = "osc_1_random_phase")]
    osc_1__random_phase: f64,

    #[serde(rename = "osc_1_smooth_interpolation")]
    osc_1__smooth_interpolation: f64,

    #[serde(rename = "osc_1_spectral_morph_amount")]
    osc_1__spectral_morph_amount: f64,

    #[serde(rename = "osc_1_spectral_morph_spread")]
    osc_1__spectral_morph_spread: f64,

    #[serde(rename = "osc_1_spectral_morph_type")]
    osc_1__spectral_morph_type: f64,

    #[serde(rename = "osc_1_spectral_unison")]
    osc_1__spectral_unison: f64,

    #[serde(rename = "osc_1_stack_style")]
    osc_1__stack_style: f64,

    #[serde(rename = "osc_1_stereo_spread")]
    osc_1__stereo_spread: f64,

    #[serde(rename = "osc_1_transpose")]
    osc_1__transpose: f64,

    #[serde(rename = "osc_1_transpose_quantize")]
    osc_1__transpose_quantize: f64,

    #[serde(rename = "osc_1_tune")]
    osc_1__tune: f64,

    #[serde(rename = "osc_1_unison_blend")]
    osc_1__unison_blend: f64,

    #[serde(rename = "osc_1_unison_detune")]
    osc_1__unison_detune: f64,

    #[serde(rename = "osc_1_unison_voices")]
    osc_1__unison_voices: f64,

    #[serde(rename = "osc_1_view_2d")]
    osc_1__view_2_d: f64,

    #[serde(rename = "osc_1_wave_frame")]
    osc_1__wave_frame: f64,

    #[serde(rename = "osc_2_destination")]
    osc_2__destination: f64,

    #[serde(rename = "osc_2_detune_power")]
    osc_2__detune_power: f64,

    #[serde(rename = "osc_2_detune_range")]
    osc_2__detune_range: f64,

    #[serde(rename = "osc_2_distortion_amount")]
    osc_2__distortion_amount: f64,

    #[serde(rename = "osc_2_distortion_phase")]
    osc_2__distortion_phase: f64,

    #[serde(rename = "osc_2_distortion_spread")]
    osc_2__distortion_spread: f64,

    #[serde(rename = "osc_2_distortion_type")]
    osc_2__distortion_type: f64,

    #[serde(rename = "osc_2_frame_spread")]
    osc_2__frame_spread: f64,

    #[serde(rename = "osc_2_level")]
    osc_2__level: f64,

    #[serde(rename = "osc_2_midi_track")]
    osc_2__midi_track: f64,

    #[serde(rename = "osc_2_on")]
    osc_2__on: f64,

    #[serde(rename = "osc_2_pan")]
    osc_2__pan: f64,

    #[serde(rename = "osc_2_phase")]
    osc_2__phase: f64,

    #[serde(rename = "osc_2_random_phase")]
    osc_2__random_phase: f64,

    #[serde(rename = "osc_2_smooth_interpolation")]
    osc_2__smooth_interpolation: f64,

    #[serde(rename = "osc_2_spectral_morph_amount")]
    osc_2__spectral_morph_amount: f64,

    #[serde(rename = "osc_2_spectral_morph_spread")]
    osc_2__spectral_morph_spread: f64,

    #[serde(rename = "osc_2_spectral_morph_type")]
    osc_2__spectral_morph_type: f64,

    #[serde(rename = "osc_2_spectral_unison")]
    osc_2__spectral_unison: f64,

    #[serde(rename = "osc_2_stack_style")]
    osc_2__stack_style: f64,

    #[serde(rename = "osc_2_stereo_spread")]
    osc_2__stereo_spread: f64,

    #[serde(rename = "osc_2_transpose")]
    osc_2__transpose: f64,

    #[serde(rename = "osc_2_transpose_quantize")]
    osc_2__transpose_quantize: f64,

    #[serde(rename = "osc_2_tune")]
    osc_2__tune: f64,

    #[serde(rename = "osc_2_unison_blend")]
    osc_2__unison_blend: f64,

    #[serde(rename = "osc_2_unison_detune")]
    osc_2__unison_detune: f64,

    #[serde(rename = "osc_2_unison_voices")]
    osc_2__unison_voices: f64,

    #[serde(rename = "osc_2_view_2d")]
    osc_2__view_2_d: f64,

    #[serde(rename = "osc_2_wave_frame")]
    osc_2__wave_frame: f64,

    #[serde(rename = "osc_3_destination")]
    osc_3__destination: f64,

    #[serde(rename = "osc_3_detune_power")]
    osc_3__detune_power: f64,

    #[serde(rename = "osc_3_detune_range")]
    osc_3__detune_range: f64,

    #[serde(rename = "osc_3_distortion_amount")]
    osc_3__distortion_amount: f64,

    #[serde(rename = "osc_3_distortion_phase")]
    osc_3__distortion_phase: f64,

    #[serde(rename = "osc_3_distortion_spread")]
    osc_3__distortion_spread: f64,

    #[serde(rename = "osc_3_distortion_type")]
    osc_3__distortion_type: f64,

    #[serde(rename = "osc_3_frame_spread")]
    osc_3__frame_spread: f64,

    #[serde(rename = "osc_3_level")]
    osc_3__level: f64,

    #[serde(rename = "osc_3_midi_track")]
    osc_3__midi_track: f64,

    #[serde(rename = "osc_3_on")]
    osc_3__on: f64,

    #[serde(rename = "osc_3_pan")]
    osc_3__pan: f64,

    #[serde(rename = "osc_3_phase")]
    osc_3__phase: f64,

    #[serde(rename = "osc_3_random_phase")]
    osc_3__random_phase: f64,

    #[serde(rename = "osc_3_smooth_interpolation")]
    osc_3__smooth_interpolation: f64,

    #[serde(rename = "osc_3_spectral_morph_amount")]
    osc_3__spectral_morph_amount: f64,

    #[serde(rename = "osc_3_spectral_morph_spread")]
    osc_3__spectral_morph_spread: f64,

    #[serde(rename = "osc_3_spectral_morph_type")]
    osc_3__spectral_morph_type: f64,

    #[serde(rename = "osc_3_spectral_unison")]
    osc_3__spectral_unison: f64,

    #[serde(rename = "osc_3_stack_style")]
    osc_3__stack_style: f64,

    #[serde(rename = "osc_3_stereo_spread")]
    osc_3__stereo_spread: f64,

    #[serde(rename = "osc_3_transpose")]
    osc_3__transpose: f64,

    #[serde(rename = "osc_3_transpose_quantize")]
    osc_3__transpose_quantize: f64,

    #[serde(rename = "osc_3_tune")]
    osc_3__tune: f64,

    #[serde(rename = "osc_3_unison_blend")]
    osc_3__unison_blend: f64,

    #[serde(rename = "osc_3_unison_detune")]
    osc_3__unison_detune: f64,

    #[serde(rename = "osc_3_unison_voices")]
    osc_3__unison_voices: f64,

    #[serde(rename = "osc_3_view_2d")]
    osc_3__view_2_d: f64,

    #[serde(rename = "osc_3_wave_frame")]
    osc_3__wave_frame: f64,

    #[serde(rename = "oversampling")]
    oversampling: f64,

    #[serde(rename = "phaser_blend")]
    phaser_blend: f64,

    #[serde(rename = "phaser_center")]
    phaser_center: f64,

    #[serde(rename = "phaser_dry_wet")]
    phaser_dry_wet: f64,

    #[serde(rename = "phaser_feedback")]
    phaser_feedback: f64,

    #[serde(rename = "phaser_frequency")]
    phaser_frequency: f64,

    #[serde(rename = "phaser_mod_depth")]
    phaser_mod_depth: f64,

    #[serde(rename = "phaser_on")]
    phaser_on: f64,

    #[serde(rename = "phaser_phase_offset")]
    phaser_phase_offset: f64,

    #[serde(rename = "phaser_sync")]
    phaser_sync: f64,

    #[serde(rename = "phaser_tempo")]
    phaser_tempo: f64,

    #[serde(rename = "pitch_bend_range")]
    pitch_bend_range: f64,

    #[serde(rename = "pitch_wheel")]
    pitch_wheel: f64,

    #[serde(rename = "polyphony")]
    polyphony: f64,

    #[serde(rename = "portamento_force")]
    portamento_force: f64,

    #[serde(rename = "portamento_scale")]
    portamento_scale: f64,

    #[serde(rename = "portamento_slope")]
    portamento_slope: f64,

    #[serde(rename = "portamento_time")]
    portamento_time: f64,

    #[serde(rename = "random_1_frequency")]
    random_1__frequency: f64,

    #[serde(rename = "random_1_keytrack_transpose")]
    random_1__keytrack_transpose: Option<f64>,

    #[serde(rename = "random_1_keytrack_tune")]
    random_1__keytrack_tune: Option<f64>,

    #[serde(rename = "random_1_stereo")]
    random_1__stereo: f64,

    #[serde(rename = "random_1_style")]
    random_1__style: f64,

    #[serde(rename = "random_1_sync")]
    random_1__sync: f64,

    #[serde(rename = "random_1_sync_type")]
    random_1__sync_type: f64,

    #[serde(rename = "random_1_tempo")]
    random_1__tempo: f64,

    #[serde(rename = "random_2_frequency")]
    random_2__frequency: f64,

    #[serde(rename = "random_2_keytrack_transpose")]
    random_2__keytrack_transpose: Option<f64>,

    #[serde(rename = "random_2_keytrack_tune")]
    random_2__keytrack_tune: Option<f64>,

    #[serde(rename = "random_2_stereo")]
    random_2__stereo: f64,

    #[serde(rename = "random_2_style")]
    random_2__style: f64,

    #[serde(rename = "random_2_sync")]
    random_2__sync: f64,

    #[serde(rename = "random_2_sync_type")]
    random_2__sync_type: f64,

    #[serde(rename = "random_2_tempo")]
    random_2__tempo: f64,

    #[serde(rename = "random_3_frequency")]
    random_3__frequency: f64,

    #[serde(rename = "random_3_keytrack_transpose")]
    random_3__keytrack_transpose: Option<f64>,

    #[serde(rename = "random_3_keytrack_tune")]
    random_3__keytrack_tune: Option<f64>,

    #[serde(rename = "random_3_stereo")]
    random_3__stereo: f64,

    #[serde(rename = "random_3_style")]
    random_3__style: f64,

    #[serde(rename = "random_3_sync")]
    random_3__sync: f64,

    #[serde(rename = "random_3_sync_type")]
    random_3__sync_type: f64,

    #[serde(rename = "random_3_tempo")]
    random_3__tempo: f64,

    #[serde(rename = "random_4_frequency")]
    random_4__frequency: f64,

    #[serde(rename = "random_4_keytrack_transpose")]
    random_4__keytrack_transpose: Option<f64>,

    #[serde(rename = "random_4_keytrack_tune")]
    random_4__keytrack_tune: Option<f64>,

    #[serde(rename = "random_4_stereo")]
    random_4__stereo: f64,

    #[serde(rename = "random_4_style")]
    random_4__style: f64,

    #[serde(rename = "random_4_sync")]
    random_4__sync: f64,

    #[serde(rename = "random_4_sync_type")]
    random_4__sync_type: f64,

    #[serde(rename = "random_4_tempo")]
    random_4__tempo: f64,

    #[serde(rename = "reverb_chorus_amount")]
    reverb_chorus_amount: f64,

    #[serde(rename = "reverb_chorus_frequency")]
    reverb_chorus_frequency: f64,

    #[serde(rename = "reverb_decay_time")]
    reverb_decay_time: f64,

    #[serde(rename = "reverb_delay")]
    reverb_delay: Option<f64>,

    #[serde(rename = "reverb_dry_wet")]
    reverb_dry_wet: f64,

    #[serde(rename = "reverb_high_shelf_cutoff")]
    reverb_high_shelf_cutoff: f64,

    #[serde(rename = "reverb_high_shelf_gain")]
    reverb_high_shelf_gain: f64,

    #[serde(rename = "reverb_low_shelf_cutoff")]
    reverb_low_shelf_cutoff: f64,

    #[serde(rename = "reverb_low_shelf_gain")]
    reverb_low_shelf_gain: f64,

    #[serde(rename = "reverb_on")]
    reverb_on: f64,

    #[serde(rename = "reverb_pre_high_cutoff")]
    reverb_pre_high_cutoff: f64,

    #[serde(rename = "reverb_pre_low_cutoff")]
    reverb_pre_low_cutoff: f64,

    #[serde(rename = "reverb_size")]
    reverb_size: f64,

    #[serde(rename = "sample")]
    sample: Sample,

    #[serde(rename = "sample_bounce")]
    sample_bounce: Option<f64>,

    #[serde(rename = "sample_destination")]
    sample_destination: f64,

    #[serde(rename = "sample_keytrack")]
    sample_keytrack: f64,

    #[serde(rename = "sample_level")]
    sample_level: f64,

    #[serde(rename = "sample_loop")]
    sample_loop: f64,

    #[serde(rename = "sample_on")]
    sample_on: f64,

    #[serde(rename = "sample_pan")]
    sample_pan: f64,

    #[serde(rename = "sample_random_phase")]
    sample_random_phase: f64,

    #[serde(rename = "sample_transpose")]
    sample_transpose: f64,

    #[serde(rename = "sample_transpose_quantize")]
    sample_transpose_quantize: f64,

    #[serde(rename = "sample_tune")]
    sample_tune: f64,

    #[serde(rename = "stereo_mode")]
    stereo_mode: Option<f64>,

    #[serde(rename = "stereo_routing")]
    stereo_routing: f64,

    #[serde(rename = "velocity_track")]
    velocity_track: f64,

    #[serde(rename = "view_spectrogram")]
    view_spectrogram: Option<f64>,

    #[serde(rename = "voice_amplitude")]
    voice_amplitude: f64,

    #[serde(rename = "voice_override")]
    voice_override: Option<f64>,

    #[serde(rename = "voice_priority")]
    voice_priority: f64,

    #[serde(rename = "voice_transpose")]
    voice_transpose: Option<f64>,

    #[serde(rename = "voice_tune")]
    voice_tune: f64,

    #[serde(rename = "volume")]
    volume: f64,

    #[serde(rename = "wavetables")]
    wavetables: Vec<Wavetable>,
}

#[derive(Serialize, Deserialize)]
pub struct Lfo {
    #[serde(rename = "name")]
    name: String,

    #[serde(rename = "num_points")]
    num_points: f64,

    #[serde(rename = "points")]
    points: Vec<f64>,

    #[serde(rename = "powers")]
    powers: Vec<f64>,

    #[serde(rename = "smooth")]
    smooth: bool,
}

#[derive(Serialize, Deserialize)]
pub struct Modulation {
    #[serde(rename = "destination")]
    destination: String,

    #[serde(rename = "line_mapping")]
    line_mapping: Option<Lfo>,

    #[serde(rename = "source")]
    source: Source,
}

#[derive(Serialize, Deserialize)]
pub struct Sample {
    #[serde(rename = "length")]
    length: f64,

    #[serde(rename = "name")]
    name: String,

    #[serde(rename = "sample_rate")]
    sample_rate: f64,

    #[serde(rename = "samples")]
    samples: String,

    #[serde(rename = "samples_stereo")]
    samples_stereo: Option<String>,
}

#[derive(Serialize, Deserialize)]
pub struct Wavetable {
    #[serde(rename = "author")]
    author: Option<String>,

    #[serde(rename = "full_normalize")]
    full_normalize: bool,

    #[serde(rename = "groups")]
    groups: Vec<Group>,

    #[serde(rename = "name")]
    name: String,

    #[serde(rename = "remove_all_dc")]
    remove_all_dc: bool,

    #[serde(rename = "version")]
    version: String,
}

#[derive(Serialize, Deserialize)]
pub struct Group {
    #[serde(rename = "components")]
    components: Vec<Component>,
}

#[derive(Serialize, Deserialize)]
pub struct Component {
    #[serde(rename = "audio_file")]
    audio_file: Option<String>,

    #[serde(rename = "audio_sample_rate")]
    audio_sample_rate: Option<f64>,

    #[serde(rename = "fade_style")]
    fade_style: Option<f64>,

    #[serde(rename = "horizontal_asymmetric")]
    horizontal_asymmetric: Option<bool>,

    #[serde(rename = "interpolation")]
    interpolation: Option<f64>,

    #[serde(rename = "interpolation_style")]
    interpolation_style: f64,

    #[serde(rename = "keyframes")]
    keyframes: Option<Vec<Keyframe>>,

    #[serde(rename = "normalize")]
    normalize: Option<bool>,

    #[serde(rename = "normalize_gain")]
    normalize_gain: Option<bool>,

    #[serde(rename = "normalize_mult")]
    normalize_mult: Option<bool>,

    #[serde(rename = "num_points")]
    num_points: Option<f64>,

    #[serde(rename = "phase_style")]
    phase_style: Option<f64>,

    #[serde(rename = "random_seed")]
    random_seed: Option<f64>,

    #[serde(rename = "style")]
    style: Option<f64>,

    #[serde(rename = "type")]
    component_type: Type,

    #[serde(rename = "vertical_asymmetric")]
    vertical_asymmetric: Option<bool>,

    #[serde(rename = "window_shape")]
    window_shape: Option<f64>,

    #[serde(rename = "window_size")]
    window_size: Option<f64>,
}

#[derive(Serialize, Deserialize)]
pub struct Keyframe {
    #[serde(rename = "cutoff")]
    cutoff: Option<f64>,

    #[serde(rename = "down_run_rise")]
    down_run_rise: Option<f64>,

    #[serde(rename = "fold_boost")]
    fold_boost: Option<f64>,

    #[serde(rename = "horizontal_power")]
    horizontal_power: Option<f64>,

    #[serde(rename = "left_position")]
    left_position: Option<f64>,

    #[serde(rename = "line")]
    line: Option<Lfo>,

    #[serde(rename = "mix")]
    mix: Option<f64>,

    #[serde(rename = "phase")]
    phase: Option<f64>,

    #[serde(rename = "position")]
    position: f64,

    #[serde(rename = "pull_power")]
    pull_power: Option<f64>,

    #[serde(rename = "right_position")]
    right_position: Option<f64>,

    #[serde(rename = "shape")]
    shape: Option<f64>,

    #[serde(rename = "start_position")]
    start_position: Option<f64>,

    #[serde(rename = "up_run_rise")]
    up_run_rise: Option<f64>,

    #[serde(rename = "vertical_power")]
    vertical_power: Option<f64>,

    #[serde(rename = "wave_data")]
    wave_data: Option<String>,

    #[serde(rename = "window_fade")]
    window_fade: Option<f64>,

    #[serde(rename = "window_size")]
    window_size: Option<f64>,
}

#[derive(Serialize, Deserialize)]
pub enum PresetStyle {
    #[serde(rename = "Bass")]
    Bass,

    #[serde(rename = "")]
    Empty,

    #[serde(rename = "Experiment")]
    Experiment,

    #[serde(rename = "Keys")]
    Keys,

    #[serde(rename = "Lead")]
    Lead,

    #[serde(rename = "Pad")]
    Pad,

    #[serde(rename = "Percussion")]
    Percussion,

    #[serde(rename = "Sequence")]
    Sequence,

    #[serde(rename = "SFX")]
    Sfx,

    #[serde(rename = "Template")]
    Template,
}

#[derive(Serialize, Deserialize)]
pub enum Source {
    #[serde(rename = "aftertouch")]
    Aftertouch,

    #[serde(rename = "")]
    Empty,

    #[serde(rename = "env_1")]
    Env1,

    #[serde(rename = "env_2")]
    Env2,

    #[serde(rename = "env_3")]
    Env3,

    #[serde(rename = "env_4")]
    Env4,

    #[serde(rename = "env_5")]
    Env5,

    #[serde(rename = "env_6")]
    Env6,

    #[serde(rename = "lfo_1")]
    Lfo1,

    #[serde(rename = "lfo_2")]
    Lfo2,

    #[serde(rename = "lfo_3")]
    Lfo3,

    #[serde(rename = "lfo_4")]
    Lfo4,

    #[serde(rename = "lfo_5")]
    Lfo5,

    #[serde(rename = "lfo_6")]
    Lfo6,

    #[serde(rename = "lfo_7")]
    Lfo7,

    #[serde(rename = "lfo_8")]
    Lfo8,

    #[serde(rename = "lift")]
    Lift,

    #[serde(rename = "macro_control_1")]
    MacroControl1,

    #[serde(rename = "macro_control_2")]
    MacroControl2,

    #[serde(rename = "macro_control_3")]
    MacroControl3,

    #[serde(rename = "macro_control_4")]
    MacroControl4,

    #[serde(rename = "mod_wheel")]
    ModWheel,

    #[serde(rename = "note")]
    Note,

    #[serde(rename = "note_in_octave")]
    NoteInOctave,

    #[serde(rename = "pitch_wheel")]
    PitchWheel,

    #[serde(rename = "random")]
    Random,

    #[serde(rename = "random_1")]
    Random1,

    #[serde(rename = "random_2")]
    Random2,

    #[serde(rename = "random_3")]
    Random3,

    #[serde(rename = "random_4")]
    Random4,

    #[serde(rename = "slide")]
    Slide,

    #[serde(rename = "stereo")]
    Stereo,

    #[serde(rename = "velocity")]
    Velocity,
}

#[derive(Serialize, Deserialize)]
pub enum Type {
    #[serde(rename = "Audio File Source")]
    AudioFileSource,

    #[serde(rename = "Frequency Filter")]
    FrequencyFilter,

    #[serde(rename = "Line Source")]
    LineSource,

    #[serde(rename = "Phase Shift")]
    PhaseShift,

    #[serde(rename = "Shepard Tone Source")]
    ShepardToneSource,

    #[serde(rename = "Slew Limiter")]
    SlewLimiter,

    #[serde(rename = "Wave Folder")]
    WaveFolder,

    #[serde(rename = "Wave Source")]
    WaveSource,

    #[serde(rename = "Wave Warp")]
    WaveWarp,

    #[serde(rename = "Wave Window")]
    WaveWindow,
}
