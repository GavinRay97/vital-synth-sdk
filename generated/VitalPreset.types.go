// This file was generated from JSON Schema using quicktype, do not modify it directly.
// To parse and unparse this JSON data, add this code to your project and do:
//
//    vitalPreset, err := UnmarshalVitalPreset(bytes)
//    bytes, err = vitalPreset.Marshal()
//
//    presetStyle, err := UnmarshalPresetStyle(bytes)
//    bytes, err = presetStyle.Marshal()
//
//    presetSettings, err := UnmarshalPresetSettings(bytes)
//    bytes, err = presetSettings.Marshal()
//
//    lfo, err := UnmarshalLfo(bytes)
//    bytes, err = lfo.Marshal()
//
//    modulation, err := UnmarshalModulation(bytes)
//    bytes, err = modulation.Marshal()
//
//    source, err := UnmarshalSource(bytes)
//    bytes, err = source.Marshal()
//
//    sample, err := UnmarshalSample(bytes)
//    bytes, err = sample.Marshal()
//
//    wavetable, err := UnmarshalWavetable(bytes)
//    bytes, err = wavetable.Marshal()
//
//    group, err := UnmarshalGroup(bytes)
//    bytes, err = group.Marshal()
//
//    component, err := UnmarshalComponent(bytes)
//    bytes, err = component.Marshal()
//
//    keyframe, err := UnmarshalKeyframe(bytes)
//    bytes, err = keyframe.Marshal()
//
//    type, err := UnmarshalType(bytes)
//    bytes, err = type.Marshal()

package vital_sdk

import "encoding/json"

func UnmarshalVitalPreset(data []byte) (VitalPreset, error) {
	var r VitalPreset
	err := json.Unmarshal(data, &r)
	return r, err
}

func (r *VitalPreset) Marshal() ([]byte, error) {
	return json.Marshal(r)
}

func UnmarshalPresetStyle(data []byte) (PresetStyle, error) {
	var r PresetStyle
	err := json.Unmarshal(data, &r)
	return r, err
}

func (r *PresetStyle) Marshal() ([]byte, error) {
	return json.Marshal(r)
}

func UnmarshalPresetSettings(data []byte) (PresetSettings, error) {
	var r PresetSettings
	err := json.Unmarshal(data, &r)
	return r, err
}

func (r *PresetSettings) Marshal() ([]byte, error) {
	return json.Marshal(r)
}

func UnmarshalLfo(data []byte) (Lfo, error) {
	var r Lfo
	err := json.Unmarshal(data, &r)
	return r, err
}

func (r *Lfo) Marshal() ([]byte, error) {
	return json.Marshal(r)
}

func UnmarshalModulation(data []byte) (Modulation, error) {
	var r Modulation
	err := json.Unmarshal(data, &r)
	return r, err
}

func (r *Modulation) Marshal() ([]byte, error) {
	return json.Marshal(r)
}

func UnmarshalSource(data []byte) (Source, error) {
	var r Source
	err := json.Unmarshal(data, &r)
	return r, err
}

func (r *Source) Marshal() ([]byte, error) {
	return json.Marshal(r)
}

func UnmarshalSample(data []byte) (Sample, error) {
	var r Sample
	err := json.Unmarshal(data, &r)
	return r, err
}

func (r *Sample) Marshal() ([]byte, error) {
	return json.Marshal(r)
}

func UnmarshalWavetable(data []byte) (Wavetable, error) {
	var r Wavetable
	err := json.Unmarshal(data, &r)
	return r, err
}

func (r *Wavetable) Marshal() ([]byte, error) {
	return json.Marshal(r)
}

func UnmarshalGroup(data []byte) (Group, error) {
	var r Group
	err := json.Unmarshal(data, &r)
	return r, err
}

func (r *Group) Marshal() ([]byte, error) {
	return json.Marshal(r)
}

func UnmarshalComponent(data []byte) (Component, error) {
	var r Component
	err := json.Unmarshal(data, &r)
	return r, err
}

func (r *Component) Marshal() ([]byte, error) {
	return json.Marshal(r)
}

func UnmarshalKeyframe(data []byte) (Keyframe, error) {
	var r Keyframe
	err := json.Unmarshal(data, &r)
	return r, err
}

func (r *Keyframe) Marshal() ([]byte, error) {
	return json.Marshal(r)
}

func UnmarshalType(data []byte) (Type, error) {
	var r Type
	err := json.Unmarshal(data, &r)
	return r, err
}

func (r *Type) Marshal() ([]byte, error) {
	return json.Marshal(r)
}

type VitalPreset struct {
	Author       string         `json:"author"`               
	Comments     string         `json:"comments"`             
	Macro1       string         `json:"macro1"`               
	Macro2       string         `json:"macro2"`               
	Macro3       string         `json:"macro3"`               
	Macro4       string         `json:"macro4"`               
	PresetName   *string        `json:"preset_name,omitempty"`
	PresetStyle  PresetStyle    `json:"preset_style"`         
	Settings     PresetSettings `json:"settings"`             
	SynthVersion string         `json:"synth_version"`        
}

type PresetSettings struct {
	BeatsPerMinute               float64      `json:"beats_per_minute"`                     
	Bypass                       *float64     `json:"bypass,omitempty"`                     
	ChorusCutoff                 *float64     `json:"chorus_cutoff,omitempty"`              
	ChorusDamping                *float64     `json:"chorus_damping,omitempty"`             
	ChorusDelay1                 float64      `json:"chorus_delay_1"`                       
	ChorusDelay2                 float64      `json:"chorus_delay_2"`                       
	ChorusDryWet                 float64      `json:"chorus_dry_wet"`                       
	ChorusFeedback               float64      `json:"chorus_feedback"`                      
	ChorusFrequency              float64      `json:"chorus_frequency"`                     
	ChorusModDepth               float64      `json:"chorus_mod_depth"`                     
	ChorusOn                     float64      `json:"chorus_on"`                            
	ChorusSpread                 *float64     `json:"chorus_spread,omitempty"`              
	ChorusSync                   float64      `json:"chorus_sync"`                          
	ChorusTempo                  float64      `json:"chorus_tempo"`                         
	ChorusVoices                 float64      `json:"chorus_voices"`                        
	CompressorAttack             float64      `json:"compressor_attack"`                    
	CompressorBandGain           float64      `json:"compressor_band_gain"`                 
	CompressorBandLowerRatio     float64      `json:"compressor_band_lower_ratio"`          
	CompressorBandLowerThreshold float64      `json:"compressor_band_lower_threshold"`      
	CompressorBandUpperRatio     float64      `json:"compressor_band_upper_ratio"`          
	CompressorBandUpperThreshold float64      `json:"compressor_band_upper_threshold"`      
	CompressorEnabledBands       float64      `json:"compressor_enabled_bands"`             
	CompressorHighGain           float64      `json:"compressor_high_gain"`                 
	CompressorHighLowerRatio     float64      `json:"compressor_high_lower_ratio"`          
	CompressorHighLowerThreshold float64      `json:"compressor_high_lower_threshold"`      
	CompressorHighUpperRatio     float64      `json:"compressor_high_upper_ratio"`          
	CompressorHighUpperThreshold float64      `json:"compressor_high_upper_threshold"`      
	CompressorLowGain            float64      `json:"compressor_low_gain"`                  
	CompressorLowLowerRatio      float64      `json:"compressor_low_lower_ratio"`           
	CompressorLowLowerThreshold  float64      `json:"compressor_low_lower_threshold"`       
	CompressorLowUpperRatio      float64      `json:"compressor_low_upper_ratio"`           
	CompressorLowUpperThreshold  float64      `json:"compressor_low_upper_threshold"`       
	CompressorMix                *float64     `json:"compressor_mix,omitempty"`             
	CompressorOn                 float64      `json:"compressor_on"`                        
	CompressorRelease            float64      `json:"compressor_release"`                   
	DelayAuxFrequency            float64      `json:"delay_aux_frequency"`                  
	DelayAuxSync                 float64      `json:"delay_aux_sync"`                       
	DelayAuxTempo                float64      `json:"delay_aux_tempo"`                      
	DelayDryWet                  float64      `json:"delay_dry_wet"`                        
	DelayFeedback                float64      `json:"delay_feedback"`                       
	DelayFilterCutoff            float64      `json:"delay_filter_cutoff"`                  
	DelayFilterSpread            float64      `json:"delay_filter_spread"`                  
	DelayFrequency               float64      `json:"delay_frequency"`                      
	DelayOn                      float64      `json:"delay_on"`                             
	DelayStyle                   float64      `json:"delay_style"`                          
	DelaySync                    float64      `json:"delay_sync"`                           
	DelayTempo                   float64      `json:"delay_tempo"`                          
	DistortionDrive              float64      `json:"distortion_drive"`                     
	DistortionFilterBlend        float64      `json:"distortion_filter_blend"`              
	DistortionFilterCutoff       float64      `json:"distortion_filter_cutoff"`             
	DistortionFilterOrder        float64      `json:"distortion_filter_order"`              
	DistortionFilterResonance    float64      `json:"distortion_filter_resonance"`          
	DistortionMix                float64      `json:"distortion_mix"`                       
	DistortionOn                 float64      `json:"distortion_on"`                        
	DistortionType               float64      `json:"distortion_type"`                      
	EffectChainOrder             float64      `json:"effect_chain_order"`                   
	Env1_Attack                  float64      `json:"env_1_attack"`                         
	Env1_AttackPower             float64      `json:"env_1_attack_power"`                   
	Env1_Decay                   float64      `json:"env_1_decay"`                          
	Env1_DecayPower              float64      `json:"env_1_decay_power"`                    
	Env1_Delay                   float64      `json:"env_1_delay"`                          
	Env1_Hold                    float64      `json:"env_1_hold"`                           
	Env1_Release                 float64      `json:"env_1_release"`                        
	Env1_ReleasePower            float64      `json:"env_1_release_power"`                  
	Env1_Sustain                 float64      `json:"env_1_sustain"`                        
	Env2_Attack                  float64      `json:"env_2_attack"`                         
	Env2_AttackPower             float64      `json:"env_2_attack_power"`                   
	Env2_Decay                   float64      `json:"env_2_decay"`                          
	Env2_DecayPower              float64      `json:"env_2_decay_power"`                    
	Env2_Delay                   float64      `json:"env_2_delay"`                          
	Env2_Hold                    float64      `json:"env_2_hold"`                           
	Env2_Release                 float64      `json:"env_2_release"`                        
	Env2_ReleasePower            float64      `json:"env_2_release_power"`                  
	Env2_Sustain                 float64      `json:"env_2_sustain"`                        
	Env3_Attack                  float64      `json:"env_3_attack"`                         
	Env3_AttackPower             float64      `json:"env_3_attack_power"`                   
	Env3_Decay                   float64      `json:"env_3_decay"`                          
	Env3_DecayPower              float64      `json:"env_3_decay_power"`                    
	Env3_Delay                   float64      `json:"env_3_delay"`                          
	Env3_Hold                    float64      `json:"env_3_hold"`                           
	Env3_Release                 float64      `json:"env_3_release"`                        
	Env3_ReleasePower            float64      `json:"env_3_release_power"`                  
	Env3_Sustain                 float64      `json:"env_3_sustain"`                        
	Env4_Attack                  float64      `json:"env_4_attack"`                         
	Env4_AttackPower             float64      `json:"env_4_attack_power"`                   
	Env4_Decay                   float64      `json:"env_4_decay"`                          
	Env4_DecayPower              float64      `json:"env_4_decay_power"`                    
	Env4_Delay                   float64      `json:"env_4_delay"`                          
	Env4_Hold                    float64      `json:"env_4_hold"`                           
	Env4_Release                 float64      `json:"env_4_release"`                        
	Env4_ReleasePower            float64      `json:"env_4_release_power"`                  
	Env4_Sustain                 float64      `json:"env_4_sustain"`                        
	Env5_Attack                  float64      `json:"env_5_attack"`                         
	Env5_AttackPower             float64      `json:"env_5_attack_power"`                   
	Env5_Decay                   float64      `json:"env_5_decay"`                          
	Env5_DecayPower              float64      `json:"env_5_decay_power"`                    
	Env5_Delay                   float64      `json:"env_5_delay"`                          
	Env5_Hold                    float64      `json:"env_5_hold"`                           
	Env5_Release                 float64      `json:"env_5_release"`                        
	Env5_ReleasePower            float64      `json:"env_5_release_power"`                  
	Env5_Sustain                 float64      `json:"env_5_sustain"`                        
	Env6_Attack                  float64      `json:"env_6_attack"`                         
	Env6_AttackPower             float64      `json:"env_6_attack_power"`                   
	Env6_Decay                   float64      `json:"env_6_decay"`                          
	Env6_DecayPower              float64      `json:"env_6_decay_power"`                    
	Env6_Delay                   float64      `json:"env_6_delay"`                          
	Env6_Hold                    float64      `json:"env_6_hold"`                           
	Env6_Release                 float64      `json:"env_6_release"`                        
	Env6_ReleasePower            float64      `json:"env_6_release_power"`                  
	Env6_Sustain                 float64      `json:"env_6_sustain"`                        
	EqBandCutoff                 float64      `json:"eq_band_cutoff"`                       
	EqBandGain                   float64      `json:"eq_band_gain"`                         
	EqBandMode                   float64      `json:"eq_band_mode"`                         
	EqBandResonance              float64      `json:"eq_band_resonance"`                    
	EqHighCutoff                 float64      `json:"eq_high_cutoff"`                       
	EqHighGain                   float64      `json:"eq_high_gain"`                         
	EqHighMode                   float64      `json:"eq_high_mode"`                         
	EqHighResonance              float64      `json:"eq_high_resonance"`                    
	EqLowCutoff                  float64      `json:"eq_low_cutoff"`                        
	EqLowGain                    float64      `json:"eq_low_gain"`                          
	EqLowMode                    float64      `json:"eq_low_mode"`                          
	EqLowResonance               float64      `json:"eq_low_resonance"`                     
	EqOn                         float64      `json:"eq_on"`                                
	Filter1_Blend                float64      `json:"filter_1_blend"`                       
	Filter1_BlendTranspose       float64      `json:"filter_1_blend_transpose"`             
	Filter1_Cutoff               float64      `json:"filter_1_cutoff"`                      
	Filter1_Drive                float64      `json:"filter_1_drive"`                       
	Filter1_FilterInput          float64      `json:"filter_1_filter_input"`                
	Filter1_FormantResonance     float64      `json:"filter_1_formant_resonance"`           
	Filter1_FormantSpread        *float64     `json:"filter_1_formant_spread,omitempty"`    
	Filter1_FormantTranspose     float64      `json:"filter_1_formant_transpose"`           
	Filter1_FormantX             float64      `json:"filter_1_formant_x"`                   
	Filter1_FormantY             float64      `json:"filter_1_formant_y"`                   
	Filter1_Keytrack             float64      `json:"filter_1_keytrack"`                    
	Filter1_Mix                  float64      `json:"filter_1_mix"`                         
	Filter1_Model                float64      `json:"filter_1_model"`                       
	Filter1_On                   float64      `json:"filter_1_on"`                          
	Filter1_Resonance            float64      `json:"filter_1_resonance"`                   
	Filter1_Style                float64      `json:"filter_1_style"`                       
	Filter2_Blend                float64      `json:"filter_2_blend"`                       
	Filter2_BlendTranspose       float64      `json:"filter_2_blend_transpose"`             
	Filter2_Cutoff               float64      `json:"filter_2_cutoff"`                      
	Filter2_Drive                float64      `json:"filter_2_drive"`                       
	Filter2_FilterInput          float64      `json:"filter_2_filter_input"`                
	Filter2_FormantResonance     float64      `json:"filter_2_formant_resonance"`           
	Filter2_FormantSpread        *float64     `json:"filter_2_formant_spread,omitempty"`    
	Filter2_FormantTranspose     float64      `json:"filter_2_formant_transpose"`           
	Filter2_FormantX             float64      `json:"filter_2_formant_x"`                   
	Filter2_FormantY             float64      `json:"filter_2_formant_y"`                   
	Filter2_Keytrack             float64      `json:"filter_2_keytrack"`                    
	Filter2_Mix                  float64      `json:"filter_2_mix"`                         
	Filter2_Model                float64      `json:"filter_2_model"`                       
	Filter2_On                   float64      `json:"filter_2_on"`                          
	Filter2_Resonance            float64      `json:"filter_2_resonance"`                   
	Filter2_Style                float64      `json:"filter_2_style"`                       
	FilterFxBlend                float64      `json:"filter_fx_blend"`                      
	FilterFxBlendTranspose       float64      `json:"filter_fx_blend_transpose"`            
	FilterFxCutoff               float64      `json:"filter_fx_cutoff"`                     
	FilterFxDrive                float64      `json:"filter_fx_drive"`                      
	FilterFxFormantResonance     float64      `json:"filter_fx_formant_resonance"`          
	FilterFxFormantSpread        *float64     `json:"filter_fx_formant_spread,omitempty"`   
	FilterFxFormantTranspose     float64      `json:"filter_fx_formant_transpose"`          
	FilterFxFormantX             float64      `json:"filter_fx_formant_x"`                  
	FilterFxFormantY             float64      `json:"filter_fx_formant_y"`                  
	FilterFxKeytrack             float64      `json:"filter_fx_keytrack"`                   
	FilterFxMix                  float64      `json:"filter_fx_mix"`                        
	FilterFxModel                float64      `json:"filter_fx_model"`                      
	FilterFxOn                   float64      `json:"filter_fx_on"`                         
	FilterFxResonance            float64      `json:"filter_fx_resonance"`                  
	FilterFxStyle                float64      `json:"filter_fx_style"`                      
	FlangerCenter                float64      `json:"flanger_center"`                       
	FlangerDryWet                float64      `json:"flanger_dry_wet"`                      
	FlangerFeedback              float64      `json:"flanger_feedback"`                     
	FlangerFrequency             float64      `json:"flanger_frequency"`                    
	FlangerModDepth              float64      `json:"flanger_mod_depth"`                    
	FlangerOn                    float64      `json:"flanger_on"`                           
	FlangerPhaseOffset           float64      `json:"flanger_phase_offset"`                 
	FlangerSync                  float64      `json:"flanger_sync"`                         
	FlangerTempo                 float64      `json:"flanger_tempo"`                        
	Legato                       float64      `json:"legato"`                               
	Lfo1_DelayTime               float64      `json:"lfo_1_delay_time"`                     
	Lfo1_FadeTime                float64      `json:"lfo_1_fade_time"`                      
	Lfo1_Frequency               float64      `json:"lfo_1_frequency"`                      
	Lfo1_KeytrackTranspose       *float64     `json:"lfo_1_keytrack_transpose,omitempty"`   
	Lfo1_KeytrackTune            *float64     `json:"lfo_1_keytrack_tune,omitempty"`        
	Lfo1_Phase                   float64      `json:"lfo_1_phase"`                          
	Lfo1_SmoothMode              *float64     `json:"lfo_1_smooth_mode,omitempty"`          
	Lfo1_SmoothTime              *float64     `json:"lfo_1_smooth_time,omitempty"`          
	Lfo1_Stereo                  float64      `json:"lfo_1_stereo"`                         
	Lfo1_Sync                    float64      `json:"lfo_1_sync"`                           
	Lfo1_SyncType                float64      `json:"lfo_1_sync_type"`                      
	Lfo1_Tempo                   float64      `json:"lfo_1_tempo"`                          
	Lfo2_DelayTime               float64      `json:"lfo_2_delay_time"`                     
	Lfo2_FadeTime                float64      `json:"lfo_2_fade_time"`                      
	Lfo2_Frequency               float64      `json:"lfo_2_frequency"`                      
	Lfo2_KeytrackTranspose       *float64     `json:"lfo_2_keytrack_transpose,omitempty"`   
	Lfo2_KeytrackTune            *float64     `json:"lfo_2_keytrack_tune,omitempty"`        
	Lfo2_Phase                   float64      `json:"lfo_2_phase"`                          
	Lfo2_SmoothMode              *float64     `json:"lfo_2_smooth_mode,omitempty"`          
	Lfo2_SmoothTime              *float64     `json:"lfo_2_smooth_time,omitempty"`          
	Lfo2_Stereo                  float64      `json:"lfo_2_stereo"`                         
	Lfo2_Sync                    float64      `json:"lfo_2_sync"`                           
	Lfo2_SyncType                float64      `json:"lfo_2_sync_type"`                      
	Lfo2_Tempo                   float64      `json:"lfo_2_tempo"`                          
	Lfo3_DelayTime               float64      `json:"lfo_3_delay_time"`                     
	Lfo3_FadeTime                float64      `json:"lfo_3_fade_time"`                      
	Lfo3_Frequency               float64      `json:"lfo_3_frequency"`                      
	Lfo3_KeytrackTranspose       *float64     `json:"lfo_3_keytrack_transpose,omitempty"`   
	Lfo3_KeytrackTune            *float64     `json:"lfo_3_keytrack_tune,omitempty"`        
	Lfo3_Phase                   float64      `json:"lfo_3_phase"`                          
	Lfo3_SmoothMode              *float64     `json:"lfo_3_smooth_mode,omitempty"`          
	Lfo3_SmoothTime              *float64     `json:"lfo_3_smooth_time,omitempty"`          
	Lfo3_Stereo                  float64      `json:"lfo_3_stereo"`                         
	Lfo3_Sync                    float64      `json:"lfo_3_sync"`                           
	Lfo3_SyncType                float64      `json:"lfo_3_sync_type"`                      
	Lfo3_Tempo                   float64      `json:"lfo_3_tempo"`                          
	Lfo4_DelayTime               float64      `json:"lfo_4_delay_time"`                     
	Lfo4_FadeTime                float64      `json:"lfo_4_fade_time"`                      
	Lfo4_Frequency               float64      `json:"lfo_4_frequency"`                      
	Lfo4_KeytrackTranspose       *float64     `json:"lfo_4_keytrack_transpose,omitempty"`   
	Lfo4_KeytrackTune            *float64     `json:"lfo_4_keytrack_tune,omitempty"`        
	Lfo4_Phase                   float64      `json:"lfo_4_phase"`                          
	Lfo4_SmoothMode              *float64     `json:"lfo_4_smooth_mode,omitempty"`          
	Lfo4_SmoothTime              *float64     `json:"lfo_4_smooth_time,omitempty"`          
	Lfo4_Stereo                  float64      `json:"lfo_4_stereo"`                         
	Lfo4_Sync                    float64      `json:"lfo_4_sync"`                           
	Lfo4_SyncType                float64      `json:"lfo_4_sync_type"`                      
	Lfo4_Tempo                   float64      `json:"lfo_4_tempo"`                          
	Lfo5_DelayTime               float64      `json:"lfo_5_delay_time"`                     
	Lfo5_FadeTime                float64      `json:"lfo_5_fade_time"`                      
	Lfo5_Frequency               float64      `json:"lfo_5_frequency"`                      
	Lfo5_KeytrackTranspose       *float64     `json:"lfo_5_keytrack_transpose,omitempty"`   
	Lfo5_KeytrackTune            *float64     `json:"lfo_5_keytrack_tune,omitempty"`        
	Lfo5_Phase                   float64      `json:"lfo_5_phase"`                          
	Lfo5_SmoothMode              *float64     `json:"lfo_5_smooth_mode,omitempty"`          
	Lfo5_SmoothTime              *float64     `json:"lfo_5_smooth_time,omitempty"`          
	Lfo5_Stereo                  float64      `json:"lfo_5_stereo"`                         
	Lfo5_Sync                    float64      `json:"lfo_5_sync"`                           
	Lfo5_SyncType                float64      `json:"lfo_5_sync_type"`                      
	Lfo5_Tempo                   float64      `json:"lfo_5_tempo"`                          
	Lfo6_DelayTime               float64      `json:"lfo_6_delay_time"`                     
	Lfo6_FadeTime                float64      `json:"lfo_6_fade_time"`                      
	Lfo6_Frequency               float64      `json:"lfo_6_frequency"`                      
	Lfo6_KeytrackTranspose       *float64     `json:"lfo_6_keytrack_transpose,omitempty"`   
	Lfo6_KeytrackTune            *float64     `json:"lfo_6_keytrack_tune,omitempty"`        
	Lfo6_Phase                   float64      `json:"lfo_6_phase"`                          
	Lfo6_SmoothMode              *float64     `json:"lfo_6_smooth_mode,omitempty"`          
	Lfo6_SmoothTime              *float64     `json:"lfo_6_smooth_time,omitempty"`          
	Lfo6_Stereo                  float64      `json:"lfo_6_stereo"`                         
	Lfo6_Sync                    float64      `json:"lfo_6_sync"`                           
	Lfo6_SyncType                float64      `json:"lfo_6_sync_type"`                      
	Lfo6_Tempo                   float64      `json:"lfo_6_tempo"`                          
	Lfo7_DelayTime               float64      `json:"lfo_7_delay_time"`                     
	Lfo7_FadeTime                float64      `json:"lfo_7_fade_time"`                      
	Lfo7_Frequency               float64      `json:"lfo_7_frequency"`                      
	Lfo7_KeytrackTranspose       *float64     `json:"lfo_7_keytrack_transpose,omitempty"`   
	Lfo7_KeytrackTune            *float64     `json:"lfo_7_keytrack_tune,omitempty"`        
	Lfo7_Phase                   float64      `json:"lfo_7_phase"`                          
	Lfo7_SmoothMode              *float64     `json:"lfo_7_smooth_mode,omitempty"`          
	Lfo7_SmoothTime              *float64     `json:"lfo_7_smooth_time,omitempty"`          
	Lfo7_Stereo                  float64      `json:"lfo_7_stereo"`                         
	Lfo7_Sync                    float64      `json:"lfo_7_sync"`                           
	Lfo7_SyncType                float64      `json:"lfo_7_sync_type"`                      
	Lfo7_Tempo                   float64      `json:"lfo_7_tempo"`                          
	Lfo8_DelayTime               float64      `json:"lfo_8_delay_time"`                     
	Lfo8_FadeTime                float64      `json:"lfo_8_fade_time"`                      
	Lfo8_Frequency               float64      `json:"lfo_8_frequency"`                      
	Lfo8_KeytrackTranspose       *float64     `json:"lfo_8_keytrack_transpose,omitempty"`   
	Lfo8_KeytrackTune            *float64     `json:"lfo_8_keytrack_tune,omitempty"`        
	Lfo8_Phase                   float64      `json:"lfo_8_phase"`                          
	Lfo8_SmoothMode              *float64     `json:"lfo_8_smooth_mode,omitempty"`          
	Lfo8_SmoothTime              *float64     `json:"lfo_8_smooth_time,omitempty"`          
	Lfo8_Stereo                  float64      `json:"lfo_8_stereo"`                         
	Lfo8_Sync                    float64      `json:"lfo_8_sync"`                           
	Lfo8_SyncType                float64      `json:"lfo_8_sync_type"`                      
	Lfo8_Tempo                   float64      `json:"lfo_8_tempo"`                          
	Lfos                         []Lfo        `json:"lfos"`                                 
	MacroControl1                float64      `json:"macro_control_1"`                      
	MacroControl2                float64      `json:"macro_control_2"`                      
	MacroControl3                float64      `json:"macro_control_3"`                      
	MacroControl4                float64      `json:"macro_control_4"`                      
	ModWheel                     float64      `json:"mod_wheel"`                            
	Modulation10_Amount          float64      `json:"modulation_10_amount"`                 
	Modulation10_Bipolar         float64      `json:"modulation_10_bipolar"`                
	Modulation10_Bypass          float64      `json:"modulation_10_bypass"`                 
	Modulation10_Power           float64      `json:"modulation_10_power"`                  
	Modulation10_Stereo          float64      `json:"modulation_10_stereo"`                 
	Modulation11_Amount          float64      `json:"modulation_11_amount"`                 
	Modulation11_Bipolar         float64      `json:"modulation_11_bipolar"`                
	Modulation11_Bypass          float64      `json:"modulation_11_bypass"`                 
	Modulation11_Power           float64      `json:"modulation_11_power"`                  
	Modulation11_Stereo          float64      `json:"modulation_11_stereo"`                 
	Modulation12_Amount          float64      `json:"modulation_12_amount"`                 
	Modulation12_Bipolar         float64      `json:"modulation_12_bipolar"`                
	Modulation12_Bypass          float64      `json:"modulation_12_bypass"`                 
	Modulation12_Power           float64      `json:"modulation_12_power"`                  
	Modulation12_Stereo          float64      `json:"modulation_12_stereo"`                 
	Modulation13_Amount          float64      `json:"modulation_13_amount"`                 
	Modulation13_Bipolar         float64      `json:"modulation_13_bipolar"`                
	Modulation13_Bypass          float64      `json:"modulation_13_bypass"`                 
	Modulation13_Power           float64      `json:"modulation_13_power"`                  
	Modulation13_Stereo          float64      `json:"modulation_13_stereo"`                 
	Modulation14_Amount          float64      `json:"modulation_14_amount"`                 
	Modulation14_Bipolar         float64      `json:"modulation_14_bipolar"`                
	Modulation14_Bypass          float64      `json:"modulation_14_bypass"`                 
	Modulation14_Power           float64      `json:"modulation_14_power"`                  
	Modulation14_Stereo          float64      `json:"modulation_14_stereo"`                 
	Modulation15_Amount          float64      `json:"modulation_15_amount"`                 
	Modulation15_Bipolar         float64      `json:"modulation_15_bipolar"`                
	Modulation15_Bypass          float64      `json:"modulation_15_bypass"`                 
	Modulation15_Power           float64      `json:"modulation_15_power"`                  
	Modulation15_Stereo          float64      `json:"modulation_15_stereo"`                 
	Modulation16_Amount          float64      `json:"modulation_16_amount"`                 
	Modulation16_Bipolar         float64      `json:"modulation_16_bipolar"`                
	Modulation16_Bypass          float64      `json:"modulation_16_bypass"`                 
	Modulation16_Power           float64      `json:"modulation_16_power"`                  
	Modulation16_Stereo          float64      `json:"modulation_16_stereo"`                 
	Modulation17_Amount          float64      `json:"modulation_17_amount"`                 
	Modulation17_Bipolar         float64      `json:"modulation_17_bipolar"`                
	Modulation17_Bypass          float64      `json:"modulation_17_bypass"`                 
	Modulation17_Power           float64      `json:"modulation_17_power"`                  
	Modulation17_Stereo          float64      `json:"modulation_17_stereo"`                 
	Modulation18_Amount          float64      `json:"modulation_18_amount"`                 
	Modulation18_Bipolar         float64      `json:"modulation_18_bipolar"`                
	Modulation18_Bypass          float64      `json:"modulation_18_bypass"`                 
	Modulation18_Power           float64      `json:"modulation_18_power"`                  
	Modulation18_Stereo          float64      `json:"modulation_18_stereo"`                 
	Modulation19_Amount          float64      `json:"modulation_19_amount"`                 
	Modulation19_Bipolar         float64      `json:"modulation_19_bipolar"`                
	Modulation19_Bypass          float64      `json:"modulation_19_bypass"`                 
	Modulation19_Power           float64      `json:"modulation_19_power"`                  
	Modulation19_Stereo          float64      `json:"modulation_19_stereo"`                 
	Modulation1_Amount           float64      `json:"modulation_1_amount"`                  
	Modulation1_Bipolar          float64      `json:"modulation_1_bipolar"`                 
	Modulation1_Bypass           float64      `json:"modulation_1_bypass"`                  
	Modulation1_Power            float64      `json:"modulation_1_power"`                   
	Modulation1_Stereo           float64      `json:"modulation_1_stereo"`                  
	Modulation20_Amount          float64      `json:"modulation_20_amount"`                 
	Modulation20_Bipolar         float64      `json:"modulation_20_bipolar"`                
	Modulation20_Bypass          float64      `json:"modulation_20_bypass"`                 
	Modulation20_Power           float64      `json:"modulation_20_power"`                  
	Modulation20_Stereo          float64      `json:"modulation_20_stereo"`                 
	Modulation21_Amount          float64      `json:"modulation_21_amount"`                 
	Modulation21_Bipolar         float64      `json:"modulation_21_bipolar"`                
	Modulation21_Bypass          float64      `json:"modulation_21_bypass"`                 
	Modulation21_Power           float64      `json:"modulation_21_power"`                  
	Modulation21_Stereo          float64      `json:"modulation_21_stereo"`                 
	Modulation22_Amount          float64      `json:"modulation_22_amount"`                 
	Modulation22_Bipolar         float64      `json:"modulation_22_bipolar"`                
	Modulation22_Bypass          float64      `json:"modulation_22_bypass"`                 
	Modulation22_Power           float64      `json:"modulation_22_power"`                  
	Modulation22_Stereo          float64      `json:"modulation_22_stereo"`                 
	Modulation23_Amount          float64      `json:"modulation_23_amount"`                 
	Modulation23_Bipolar         float64      `json:"modulation_23_bipolar"`                
	Modulation23_Bypass          float64      `json:"modulation_23_bypass"`                 
	Modulation23_Power           float64      `json:"modulation_23_power"`                  
	Modulation23_Stereo          float64      `json:"modulation_23_stereo"`                 
	Modulation24_Amount          float64      `json:"modulation_24_amount"`                 
	Modulation24_Bipolar         float64      `json:"modulation_24_bipolar"`                
	Modulation24_Bypass          float64      `json:"modulation_24_bypass"`                 
	Modulation24_Power           float64      `json:"modulation_24_power"`                  
	Modulation24_Stereo          float64      `json:"modulation_24_stereo"`                 
	Modulation25_Amount          float64      `json:"modulation_25_amount"`                 
	Modulation25_Bipolar         float64      `json:"modulation_25_bipolar"`                
	Modulation25_Bypass          float64      `json:"modulation_25_bypass"`                 
	Modulation25_Power           float64      `json:"modulation_25_power"`                  
	Modulation25_Stereo          float64      `json:"modulation_25_stereo"`                 
	Modulation26_Amount          float64      `json:"modulation_26_amount"`                 
	Modulation26_Bipolar         float64      `json:"modulation_26_bipolar"`                
	Modulation26_Bypass          float64      `json:"modulation_26_bypass"`                 
	Modulation26_Power           float64      `json:"modulation_26_power"`                  
	Modulation26_Stereo          float64      `json:"modulation_26_stereo"`                 
	Modulation27_Amount          float64      `json:"modulation_27_amount"`                 
	Modulation27_Bipolar         float64      `json:"modulation_27_bipolar"`                
	Modulation27_Bypass          float64      `json:"modulation_27_bypass"`                 
	Modulation27_Power           float64      `json:"modulation_27_power"`                  
	Modulation27_Stereo          float64      `json:"modulation_27_stereo"`                 
	Modulation28_Amount          float64      `json:"modulation_28_amount"`                 
	Modulation28_Bipolar         float64      `json:"modulation_28_bipolar"`                
	Modulation28_Bypass          float64      `json:"modulation_28_bypass"`                 
	Modulation28_Power           float64      `json:"modulation_28_power"`                  
	Modulation28_Stereo          float64      `json:"modulation_28_stereo"`                 
	Modulation29_Amount          float64      `json:"modulation_29_amount"`                 
	Modulation29_Bipolar         float64      `json:"modulation_29_bipolar"`                
	Modulation29_Bypass          float64      `json:"modulation_29_bypass"`                 
	Modulation29_Power           float64      `json:"modulation_29_power"`                  
	Modulation29_Stereo          float64      `json:"modulation_29_stereo"`                 
	Modulation2_Amount           float64      `json:"modulation_2_amount"`                  
	Modulation2_Bipolar          float64      `json:"modulation_2_bipolar"`                 
	Modulation2_Bypass           float64      `json:"modulation_2_bypass"`                  
	Modulation2_Power            float64      `json:"modulation_2_power"`                   
	Modulation2_Stereo           float64      `json:"modulation_2_stereo"`                  
	Modulation30_Amount          float64      `json:"modulation_30_amount"`                 
	Modulation30_Bipolar         float64      `json:"modulation_30_bipolar"`                
	Modulation30_Bypass          float64      `json:"modulation_30_bypass"`                 
	Modulation30_Power           float64      `json:"modulation_30_power"`                  
	Modulation30_Stereo          float64      `json:"modulation_30_stereo"`                 
	Modulation31_Amount          float64      `json:"modulation_31_amount"`                 
	Modulation31_Bipolar         float64      `json:"modulation_31_bipolar"`                
	Modulation31_Bypass          float64      `json:"modulation_31_bypass"`                 
	Modulation31_Power           float64      `json:"modulation_31_power"`                  
	Modulation31_Stereo          float64      `json:"modulation_31_stereo"`                 
	Modulation32_Amount          float64      `json:"modulation_32_amount"`                 
	Modulation32_Bipolar         float64      `json:"modulation_32_bipolar"`                
	Modulation32_Bypass          float64      `json:"modulation_32_bypass"`                 
	Modulation32_Power           float64      `json:"modulation_32_power"`                  
	Modulation32_Stereo          float64      `json:"modulation_32_stereo"`                 
	Modulation33_Amount          float64      `json:"modulation_33_amount"`                 
	Modulation33_Bipolar         float64      `json:"modulation_33_bipolar"`                
	Modulation33_Bypass          float64      `json:"modulation_33_bypass"`                 
	Modulation33_Power           float64      `json:"modulation_33_power"`                  
	Modulation33_Stereo          float64      `json:"modulation_33_stereo"`                 
	Modulation34_Amount          float64      `json:"modulation_34_amount"`                 
	Modulation34_Bipolar         float64      `json:"modulation_34_bipolar"`                
	Modulation34_Bypass          float64      `json:"modulation_34_bypass"`                 
	Modulation34_Power           float64      `json:"modulation_34_power"`                  
	Modulation34_Stereo          float64      `json:"modulation_34_stereo"`                 
	Modulation35_Amount          float64      `json:"modulation_35_amount"`                 
	Modulation35_Bipolar         float64      `json:"modulation_35_bipolar"`                
	Modulation35_Bypass          float64      `json:"modulation_35_bypass"`                 
	Modulation35_Power           float64      `json:"modulation_35_power"`                  
	Modulation35_Stereo          float64      `json:"modulation_35_stereo"`                 
	Modulation36_Amount          float64      `json:"modulation_36_amount"`                 
	Modulation36_Bipolar         float64      `json:"modulation_36_bipolar"`                
	Modulation36_Bypass          float64      `json:"modulation_36_bypass"`                 
	Modulation36_Power           float64      `json:"modulation_36_power"`                  
	Modulation36_Stereo          float64      `json:"modulation_36_stereo"`                 
	Modulation37_Amount          float64      `json:"modulation_37_amount"`                 
	Modulation37_Bipolar         float64      `json:"modulation_37_bipolar"`                
	Modulation37_Bypass          float64      `json:"modulation_37_bypass"`                 
	Modulation37_Power           float64      `json:"modulation_37_power"`                  
	Modulation37_Stereo          float64      `json:"modulation_37_stereo"`                 
	Modulation38_Amount          float64      `json:"modulation_38_amount"`                 
	Modulation38_Bipolar         float64      `json:"modulation_38_bipolar"`                
	Modulation38_Bypass          float64      `json:"modulation_38_bypass"`                 
	Modulation38_Power           float64      `json:"modulation_38_power"`                  
	Modulation38_Stereo          float64      `json:"modulation_38_stereo"`                 
	Modulation39_Amount          float64      `json:"modulation_39_amount"`                 
	Modulation39_Bipolar         float64      `json:"modulation_39_bipolar"`                
	Modulation39_Bypass          float64      `json:"modulation_39_bypass"`                 
	Modulation39_Power           float64      `json:"modulation_39_power"`                  
	Modulation39_Stereo          float64      `json:"modulation_39_stereo"`                 
	Modulation3_Amount           float64      `json:"modulation_3_amount"`                  
	Modulation3_Bipolar          float64      `json:"modulation_3_bipolar"`                 
	Modulation3_Bypass           float64      `json:"modulation_3_bypass"`                  
	Modulation3_Power            float64      `json:"modulation_3_power"`                   
	Modulation3_Stereo           float64      `json:"modulation_3_stereo"`                  
	Modulation40_Amount          float64      `json:"modulation_40_amount"`                 
	Modulation40_Bipolar         float64      `json:"modulation_40_bipolar"`                
	Modulation40_Bypass          float64      `json:"modulation_40_bypass"`                 
	Modulation40_Power           float64      `json:"modulation_40_power"`                  
	Modulation40_Stereo          float64      `json:"modulation_40_stereo"`                 
	Modulation41_Amount          float64      `json:"modulation_41_amount"`                 
	Modulation41_Bipolar         float64      `json:"modulation_41_bipolar"`                
	Modulation41_Bypass          float64      `json:"modulation_41_bypass"`                 
	Modulation41_Power           float64      `json:"modulation_41_power"`                  
	Modulation41_Stereo          float64      `json:"modulation_41_stereo"`                 
	Modulation42_Amount          float64      `json:"modulation_42_amount"`                 
	Modulation42_Bipolar         float64      `json:"modulation_42_bipolar"`                
	Modulation42_Bypass          float64      `json:"modulation_42_bypass"`                 
	Modulation42_Power           float64      `json:"modulation_42_power"`                  
	Modulation42_Stereo          float64      `json:"modulation_42_stereo"`                 
	Modulation43_Amount          float64      `json:"modulation_43_amount"`                 
	Modulation43_Bipolar         float64      `json:"modulation_43_bipolar"`                
	Modulation43_Bypass          float64      `json:"modulation_43_bypass"`                 
	Modulation43_Power           float64      `json:"modulation_43_power"`                  
	Modulation43_Stereo          float64      `json:"modulation_43_stereo"`                 
	Modulation44_Amount          float64      `json:"modulation_44_amount"`                 
	Modulation44_Bipolar         float64      `json:"modulation_44_bipolar"`                
	Modulation44_Bypass          float64      `json:"modulation_44_bypass"`                 
	Modulation44_Power           float64      `json:"modulation_44_power"`                  
	Modulation44_Stereo          float64      `json:"modulation_44_stereo"`                 
	Modulation45_Amount          float64      `json:"modulation_45_amount"`                 
	Modulation45_Bipolar         float64      `json:"modulation_45_bipolar"`                
	Modulation45_Bypass          float64      `json:"modulation_45_bypass"`                 
	Modulation45_Power           float64      `json:"modulation_45_power"`                  
	Modulation45_Stereo          float64      `json:"modulation_45_stereo"`                 
	Modulation46_Amount          float64      `json:"modulation_46_amount"`                 
	Modulation46_Bipolar         float64      `json:"modulation_46_bipolar"`                
	Modulation46_Bypass          float64      `json:"modulation_46_bypass"`                 
	Modulation46_Power           float64      `json:"modulation_46_power"`                  
	Modulation46_Stereo          float64      `json:"modulation_46_stereo"`                 
	Modulation47_Amount          float64      `json:"modulation_47_amount"`                 
	Modulation47_Bipolar         float64      `json:"modulation_47_bipolar"`                
	Modulation47_Bypass          float64      `json:"modulation_47_bypass"`                 
	Modulation47_Power           float64      `json:"modulation_47_power"`                  
	Modulation47_Stereo          float64      `json:"modulation_47_stereo"`                 
	Modulation48_Amount          float64      `json:"modulation_48_amount"`                 
	Modulation48_Bipolar         float64      `json:"modulation_48_bipolar"`                
	Modulation48_Bypass          float64      `json:"modulation_48_bypass"`                 
	Modulation48_Power           float64      `json:"modulation_48_power"`                  
	Modulation48_Stereo          float64      `json:"modulation_48_stereo"`                 
	Modulation49_Amount          float64      `json:"modulation_49_amount"`                 
	Modulation49_Bipolar         float64      `json:"modulation_49_bipolar"`                
	Modulation49_Bypass          float64      `json:"modulation_49_bypass"`                 
	Modulation49_Power           float64      `json:"modulation_49_power"`                  
	Modulation49_Stereo          float64      `json:"modulation_49_stereo"`                 
	Modulation4_Amount           float64      `json:"modulation_4_amount"`                  
	Modulation4_Bipolar          float64      `json:"modulation_4_bipolar"`                 
	Modulation4_Bypass           float64      `json:"modulation_4_bypass"`                  
	Modulation4_Power            float64      `json:"modulation_4_power"`                   
	Modulation4_Stereo           float64      `json:"modulation_4_stereo"`                  
	Modulation50_Amount          float64      `json:"modulation_50_amount"`                 
	Modulation50_Bipolar         float64      `json:"modulation_50_bipolar"`                
	Modulation50_Bypass          float64      `json:"modulation_50_bypass"`                 
	Modulation50_Power           float64      `json:"modulation_50_power"`                  
	Modulation50_Stereo          float64      `json:"modulation_50_stereo"`                 
	Modulation51_Amount          float64      `json:"modulation_51_amount"`                 
	Modulation51_Bipolar         float64      `json:"modulation_51_bipolar"`                
	Modulation51_Bypass          float64      `json:"modulation_51_bypass"`                 
	Modulation51_Power           float64      `json:"modulation_51_power"`                  
	Modulation51_Stereo          float64      `json:"modulation_51_stereo"`                 
	Modulation52_Amount          float64      `json:"modulation_52_amount"`                 
	Modulation52_Bipolar         float64      `json:"modulation_52_bipolar"`                
	Modulation52_Bypass          float64      `json:"modulation_52_bypass"`                 
	Modulation52_Power           float64      `json:"modulation_52_power"`                  
	Modulation52_Stereo          float64      `json:"modulation_52_stereo"`                 
	Modulation53_Amount          float64      `json:"modulation_53_amount"`                 
	Modulation53_Bipolar         float64      `json:"modulation_53_bipolar"`                
	Modulation53_Bypass          float64      `json:"modulation_53_bypass"`                 
	Modulation53_Power           float64      `json:"modulation_53_power"`                  
	Modulation53_Stereo          float64      `json:"modulation_53_stereo"`                 
	Modulation54_Amount          float64      `json:"modulation_54_amount"`                 
	Modulation54_Bipolar         float64      `json:"modulation_54_bipolar"`                
	Modulation54_Bypass          float64      `json:"modulation_54_bypass"`                 
	Modulation54_Power           float64      `json:"modulation_54_power"`                  
	Modulation54_Stereo          float64      `json:"modulation_54_stereo"`                 
	Modulation55_Amount          float64      `json:"modulation_55_amount"`                 
	Modulation55_Bipolar         float64      `json:"modulation_55_bipolar"`                
	Modulation55_Bypass          float64      `json:"modulation_55_bypass"`                 
	Modulation55_Power           float64      `json:"modulation_55_power"`                  
	Modulation55_Stereo          float64      `json:"modulation_55_stereo"`                 
	Modulation56_Amount          float64      `json:"modulation_56_amount"`                 
	Modulation56_Bipolar         float64      `json:"modulation_56_bipolar"`                
	Modulation56_Bypass          float64      `json:"modulation_56_bypass"`                 
	Modulation56_Power           float64      `json:"modulation_56_power"`                  
	Modulation56_Stereo          float64      `json:"modulation_56_stereo"`                 
	Modulation57_Amount          float64      `json:"modulation_57_amount"`                 
	Modulation57_Bipolar         float64      `json:"modulation_57_bipolar"`                
	Modulation57_Bypass          float64      `json:"modulation_57_bypass"`                 
	Modulation57_Power           float64      `json:"modulation_57_power"`                  
	Modulation57_Stereo          float64      `json:"modulation_57_stereo"`                 
	Modulation58_Amount          float64      `json:"modulation_58_amount"`                 
	Modulation58_Bipolar         float64      `json:"modulation_58_bipolar"`                
	Modulation58_Bypass          float64      `json:"modulation_58_bypass"`                 
	Modulation58_Power           float64      `json:"modulation_58_power"`                  
	Modulation58_Stereo          float64      `json:"modulation_58_stereo"`                 
	Modulation59_Amount          float64      `json:"modulation_59_amount"`                 
	Modulation59_Bipolar         float64      `json:"modulation_59_bipolar"`                
	Modulation59_Bypass          float64      `json:"modulation_59_bypass"`                 
	Modulation59_Power           float64      `json:"modulation_59_power"`                  
	Modulation59_Stereo          float64      `json:"modulation_59_stereo"`                 
	Modulation5_Amount           float64      `json:"modulation_5_amount"`                  
	Modulation5_Bipolar          float64      `json:"modulation_5_bipolar"`                 
	Modulation5_Bypass           float64      `json:"modulation_5_bypass"`                  
	Modulation5_Power            float64      `json:"modulation_5_power"`                   
	Modulation5_Stereo           float64      `json:"modulation_5_stereo"`                  
	Modulation60_Amount          float64      `json:"modulation_60_amount"`                 
	Modulation60_Bipolar         float64      `json:"modulation_60_bipolar"`                
	Modulation60_Bypass          float64      `json:"modulation_60_bypass"`                 
	Modulation60_Power           float64      `json:"modulation_60_power"`                  
	Modulation60_Stereo          float64      `json:"modulation_60_stereo"`                 
	Modulation61_Amount          float64      `json:"modulation_61_amount"`                 
	Modulation61_Bipolar         float64      `json:"modulation_61_bipolar"`                
	Modulation61_Bypass          float64      `json:"modulation_61_bypass"`                 
	Modulation61_Power           float64      `json:"modulation_61_power"`                  
	Modulation61_Stereo          float64      `json:"modulation_61_stereo"`                 
	Modulation62_Amount          float64      `json:"modulation_62_amount"`                 
	Modulation62_Bipolar         float64      `json:"modulation_62_bipolar"`                
	Modulation62_Bypass          float64      `json:"modulation_62_bypass"`                 
	Modulation62_Power           float64      `json:"modulation_62_power"`                  
	Modulation62_Stereo          float64      `json:"modulation_62_stereo"`                 
	Modulation63_Amount          float64      `json:"modulation_63_amount"`                 
	Modulation63_Bipolar         float64      `json:"modulation_63_bipolar"`                
	Modulation63_Bypass          float64      `json:"modulation_63_bypass"`                 
	Modulation63_Power           float64      `json:"modulation_63_power"`                  
	Modulation63_Stereo          float64      `json:"modulation_63_stereo"`                 
	Modulation64_Amount          float64      `json:"modulation_64_amount"`                 
	Modulation64_Bipolar         float64      `json:"modulation_64_bipolar"`                
	Modulation64_Bypass          float64      `json:"modulation_64_bypass"`                 
	Modulation64_Power           float64      `json:"modulation_64_power"`                  
	Modulation64_Stereo          float64      `json:"modulation_64_stereo"`                 
	Modulation6_Amount           float64      `json:"modulation_6_amount"`                  
	Modulation6_Bipolar          float64      `json:"modulation_6_bipolar"`                 
	Modulation6_Bypass           float64      `json:"modulation_6_bypass"`                  
	Modulation6_Power            float64      `json:"modulation_6_power"`                   
	Modulation6_Stereo           float64      `json:"modulation_6_stereo"`                  
	Modulation7_Amount           float64      `json:"modulation_7_amount"`                  
	Modulation7_Bipolar          float64      `json:"modulation_7_bipolar"`                 
	Modulation7_Bypass           float64      `json:"modulation_7_bypass"`                  
	Modulation7_Power            float64      `json:"modulation_7_power"`                   
	Modulation7_Stereo           float64      `json:"modulation_7_stereo"`                  
	Modulation8_Amount           float64      `json:"modulation_8_amount"`                  
	Modulation8_Bipolar          float64      `json:"modulation_8_bipolar"`                 
	Modulation8_Bypass           float64      `json:"modulation_8_bypass"`                  
	Modulation8_Power            float64      `json:"modulation_8_power"`                   
	Modulation8_Stereo           float64      `json:"modulation_8_stereo"`                  
	Modulation9_Amount           float64      `json:"modulation_9_amount"`                  
	Modulation9_Bipolar          float64      `json:"modulation_9_bipolar"`                 
	Modulation9_Bypass           float64      `json:"modulation_9_bypass"`                  
	Modulation9_Power            float64      `json:"modulation_9_power"`                   
	Modulation9_Stereo           float64      `json:"modulation_9_stereo"`                  
	Modulations                  []Modulation `json:"modulations"`                          
	Osc1_Destination             float64      `json:"osc_1_destination"`                    
	Osc1_DetunePower             float64      `json:"osc_1_detune_power"`                   
	Osc1_DetuneRange             float64      `json:"osc_1_detune_range"`                   
	Osc1_DistortionAmount        float64      `json:"osc_1_distortion_amount"`              
	Osc1_DistortionPhase         float64      `json:"osc_1_distortion_phase"`               
	Osc1_DistortionSpread        float64      `json:"osc_1_distortion_spread"`              
	Osc1_DistortionType          float64      `json:"osc_1_distortion_type"`                
	Osc1_FrameSpread             float64      `json:"osc_1_frame_spread"`                   
	Osc1_Level                   float64      `json:"osc_1_level"`                          
	Osc1_MIDITrack               float64      `json:"osc_1_midi_track"`                     
	Osc1_On                      float64      `json:"osc_1_on"`                             
	Osc1_Pan                     float64      `json:"osc_1_pan"`                            
	Osc1_Phase                   float64      `json:"osc_1_phase"`                          
	Osc1_RandomPhase             float64      `json:"osc_1_random_phase"`                   
	Osc1_SmoothInterpolation     float64      `json:"osc_1_smooth_interpolation"`           
	Osc1_SpectralMorphAmount     float64      `json:"osc_1_spectral_morph_amount"`          
	Osc1_SpectralMorphSpread     float64      `json:"osc_1_spectral_morph_spread"`          
	Osc1_SpectralMorphType       float64      `json:"osc_1_spectral_morph_type"`            
	Osc1_SpectralUnison          float64      `json:"osc_1_spectral_unison"`                
	Osc1_StackStyle              float64      `json:"osc_1_stack_style"`                    
	Osc1_StereoSpread            float64      `json:"osc_1_stereo_spread"`                  
	Osc1_Transpose               float64      `json:"osc_1_transpose"`                      
	Osc1_TransposeQuantize       float64      `json:"osc_1_transpose_quantize"`             
	Osc1_Tune                    float64      `json:"osc_1_tune"`                           
	Osc1_UnisonBlend             float64      `json:"osc_1_unison_blend"`                   
	Osc1_UnisonDetune            float64      `json:"osc_1_unison_detune"`                  
	Osc1_UnisonVoices            float64      `json:"osc_1_unison_voices"`                  
	Osc1_View2D                  float64      `json:"osc_1_view_2d"`                        
	Osc1_WaveFrame               float64      `json:"osc_1_wave_frame"`                     
	Osc2_Destination             float64      `json:"osc_2_destination"`                    
	Osc2_DetunePower             float64      `json:"osc_2_detune_power"`                   
	Osc2_DetuneRange             float64      `json:"osc_2_detune_range"`                   
	Osc2_DistortionAmount        float64      `json:"osc_2_distortion_amount"`              
	Osc2_DistortionPhase         float64      `json:"osc_2_distortion_phase"`               
	Osc2_DistortionSpread        float64      `json:"osc_2_distortion_spread"`              
	Osc2_DistortionType          float64      `json:"osc_2_distortion_type"`                
	Osc2_FrameSpread             float64      `json:"osc_2_frame_spread"`                   
	Osc2_Level                   float64      `json:"osc_2_level"`                          
	Osc2_MIDITrack               float64      `json:"osc_2_midi_track"`                     
	Osc2_On                      float64      `json:"osc_2_on"`                             
	Osc2_Pan                     float64      `json:"osc_2_pan"`                            
	Osc2_Phase                   float64      `json:"osc_2_phase"`                          
	Osc2_RandomPhase             float64      `json:"osc_2_random_phase"`                   
	Osc2_SmoothInterpolation     float64      `json:"osc_2_smooth_interpolation"`           
	Osc2_SpectralMorphAmount     float64      `json:"osc_2_spectral_morph_amount"`          
	Osc2_SpectralMorphSpread     float64      `json:"osc_2_spectral_morph_spread"`          
	Osc2_SpectralMorphType       float64      `json:"osc_2_spectral_morph_type"`            
	Osc2_SpectralUnison          float64      `json:"osc_2_spectral_unison"`                
	Osc2_StackStyle              float64      `json:"osc_2_stack_style"`                    
	Osc2_StereoSpread            float64      `json:"osc_2_stereo_spread"`                  
	Osc2_Transpose               float64      `json:"osc_2_transpose"`                      
	Osc2_TransposeQuantize       float64      `json:"osc_2_transpose_quantize"`             
	Osc2_Tune                    float64      `json:"osc_2_tune"`                           
	Osc2_UnisonBlend             float64      `json:"osc_2_unison_blend"`                   
	Osc2_UnisonDetune            float64      `json:"osc_2_unison_detune"`                  
	Osc2_UnisonVoices            float64      `json:"osc_2_unison_voices"`                  
	Osc2_View2D                  float64      `json:"osc_2_view_2d"`                        
	Osc2_WaveFrame               float64      `json:"osc_2_wave_frame"`                     
	Osc3_Destination             float64      `json:"osc_3_destination"`                    
	Osc3_DetunePower             float64      `json:"osc_3_detune_power"`                   
	Osc3_DetuneRange             float64      `json:"osc_3_detune_range"`                   
	Osc3_DistortionAmount        float64      `json:"osc_3_distortion_amount"`              
	Osc3_DistortionPhase         float64      `json:"osc_3_distortion_phase"`               
	Osc3_DistortionSpread        float64      `json:"osc_3_distortion_spread"`              
	Osc3_DistortionType          float64      `json:"osc_3_distortion_type"`                
	Osc3_FrameSpread             float64      `json:"osc_3_frame_spread"`                   
	Osc3_Level                   float64      `json:"osc_3_level"`                          
	Osc3_MIDITrack               float64      `json:"osc_3_midi_track"`                     
	Osc3_On                      float64      `json:"osc_3_on"`                             
	Osc3_Pan                     float64      `json:"osc_3_pan"`                            
	Osc3_Phase                   float64      `json:"osc_3_phase"`                          
	Osc3_RandomPhase             float64      `json:"osc_3_random_phase"`                   
	Osc3_SmoothInterpolation     float64      `json:"osc_3_smooth_interpolation"`           
	Osc3_SpectralMorphAmount     float64      `json:"osc_3_spectral_morph_amount"`          
	Osc3_SpectralMorphSpread     float64      `json:"osc_3_spectral_morph_spread"`          
	Osc3_SpectralMorphType       float64      `json:"osc_3_spectral_morph_type"`            
	Osc3_SpectralUnison          float64      `json:"osc_3_spectral_unison"`                
	Osc3_StackStyle              float64      `json:"osc_3_stack_style"`                    
	Osc3_StereoSpread            float64      `json:"osc_3_stereo_spread"`                  
	Osc3_Transpose               float64      `json:"osc_3_transpose"`                      
	Osc3_TransposeQuantize       float64      `json:"osc_3_transpose_quantize"`             
	Osc3_Tune                    float64      `json:"osc_3_tune"`                           
	Osc3_UnisonBlend             float64      `json:"osc_3_unison_blend"`                   
	Osc3_UnisonDetune            float64      `json:"osc_3_unison_detune"`                  
	Osc3_UnisonVoices            float64      `json:"osc_3_unison_voices"`                  
	Osc3_View2D                  float64      `json:"osc_3_view_2d"`                        
	Osc3_WaveFrame               float64      `json:"osc_3_wave_frame"`                     
	Oversampling                 float64      `json:"oversampling"`                         
	PhaserBlend                  float64      `json:"phaser_blend"`                         
	PhaserCenter                 float64      `json:"phaser_center"`                        
	PhaserDryWet                 float64      `json:"phaser_dry_wet"`                       
	PhaserFeedback               float64      `json:"phaser_feedback"`                      
	PhaserFrequency              float64      `json:"phaser_frequency"`                     
	PhaserModDepth               float64      `json:"phaser_mod_depth"`                     
	PhaserOn                     float64      `json:"phaser_on"`                            
	PhaserPhaseOffset            float64      `json:"phaser_phase_offset"`                  
	PhaserSync                   float64      `json:"phaser_sync"`                          
	PhaserTempo                  float64      `json:"phaser_tempo"`                         
	PitchBendRange               float64      `json:"pitch_bend_range"`                     
	PitchWheel                   float64      `json:"pitch_wheel"`                          
	Polyphony                    float64      `json:"polyphony"`                            
	PortamentoForce              float64      `json:"portamento_force"`                     
	PortamentoScale              float64      `json:"portamento_scale"`                     
	PortamentoSlope              float64      `json:"portamento_slope"`                     
	PortamentoTime               float64      `json:"portamento_time"`                      
	Random1_Frequency            float64      `json:"random_1_frequency"`                   
	Random1_KeytrackTranspose    *float64     `json:"random_1_keytrack_transpose,omitempty"`
	Random1_KeytrackTune         *float64     `json:"random_1_keytrack_tune,omitempty"`     
	Random1_Stereo               float64      `json:"random_1_stereo"`                      
	Random1_Style                float64      `json:"random_1_style"`                       
	Random1_Sync                 float64      `json:"random_1_sync"`                        
	Random1_SyncType             float64      `json:"random_1_sync_type"`                   
	Random1_Tempo                float64      `json:"random_1_tempo"`                       
	Random2_Frequency            float64      `json:"random_2_frequency"`                   
	Random2_KeytrackTranspose    *float64     `json:"random_2_keytrack_transpose,omitempty"`
	Random2_KeytrackTune         *float64     `json:"random_2_keytrack_tune,omitempty"`     
	Random2_Stereo               float64      `json:"random_2_stereo"`                      
	Random2_Style                float64      `json:"random_2_style"`                       
	Random2_Sync                 float64      `json:"random_2_sync"`                        
	Random2_SyncType             float64      `json:"random_2_sync_type"`                   
	Random2_Tempo                float64      `json:"random_2_tempo"`                       
	Random3_Frequency            float64      `json:"random_3_frequency"`                   
	Random3_KeytrackTranspose    *float64     `json:"random_3_keytrack_transpose,omitempty"`
	Random3_KeytrackTune         *float64     `json:"random_3_keytrack_tune,omitempty"`     
	Random3_Stereo               float64      `json:"random_3_stereo"`                      
	Random3_Style                float64      `json:"random_3_style"`                       
	Random3_Sync                 float64      `json:"random_3_sync"`                        
	Random3_SyncType             float64      `json:"random_3_sync_type"`                   
	Random3_Tempo                float64      `json:"random_3_tempo"`                       
	Random4_Frequency            float64      `json:"random_4_frequency"`                   
	Random4_KeytrackTranspose    *float64     `json:"random_4_keytrack_transpose,omitempty"`
	Random4_KeytrackTune         *float64     `json:"random_4_keytrack_tune,omitempty"`     
	Random4_Stereo               float64      `json:"random_4_stereo"`                      
	Random4_Style                float64      `json:"random_4_style"`                       
	Random4_Sync                 float64      `json:"random_4_sync"`                        
	Random4_SyncType             float64      `json:"random_4_sync_type"`                   
	Random4_Tempo                float64      `json:"random_4_tempo"`                       
	ReverbChorusAmount           float64      `json:"reverb_chorus_amount"`                 
	ReverbChorusFrequency        float64      `json:"reverb_chorus_frequency"`              
	ReverbDecayTime              float64      `json:"reverb_decay_time"`                    
	ReverbDelay                  *float64     `json:"reverb_delay,omitempty"`               
	ReverbDryWet                 float64      `json:"reverb_dry_wet"`                       
	ReverbHighShelfCutoff        float64      `json:"reverb_high_shelf_cutoff"`             
	ReverbHighShelfGain          float64      `json:"reverb_high_shelf_gain"`               
	ReverbLowShelfCutoff         float64      `json:"reverb_low_shelf_cutoff"`              
	ReverbLowShelfGain           float64      `json:"reverb_low_shelf_gain"`                
	ReverbOn                     float64      `json:"reverb_on"`                            
	ReverbPreHighCutoff          float64      `json:"reverb_pre_high_cutoff"`               
	ReverbPreLowCutoff           float64      `json:"reverb_pre_low_cutoff"`                
	ReverbSize                   float64      `json:"reverb_size"`                          
	Sample                       Sample       `json:"sample"`                               
	SampleBounce                 *float64     `json:"sample_bounce,omitempty"`              
	SampleDestination            float64      `json:"sample_destination"`                   
	SampleKeytrack               float64      `json:"sample_keytrack"`                      
	SampleLevel                  float64      `json:"sample_level"`                         
	SampleLoop                   float64      `json:"sample_loop"`                          
	SampleOn                     float64      `json:"sample_on"`                            
	SamplePan                    float64      `json:"sample_pan"`                           
	SampleRandomPhase            float64      `json:"sample_random_phase"`                  
	SampleTranspose              float64      `json:"sample_transpose"`                     
	SampleTransposeQuantize      float64      `json:"sample_transpose_quantize"`            
	SampleTune                   float64      `json:"sample_tune"`                          
	StereoMode                   *float64     `json:"stereo_mode,omitempty"`                
	StereoRouting                float64      `json:"stereo_routing"`                       
	VelocityTrack                float64      `json:"velocity_track"`                       
	ViewSpectrogram              *float64     `json:"view_spectrogram,omitempty"`           
	VoiceAmplitude               float64      `json:"voice_amplitude"`                      
	VoiceOverride                *float64     `json:"voice_override,omitempty"`             
	VoicePriority                float64      `json:"voice_priority"`                       
	VoiceTranspose               *float64     `json:"voice_transpose,omitempty"`            
	VoiceTune                    float64      `json:"voice_tune"`                           
	Volume                       float64      `json:"volume"`                               
	Wavetables                   []Wavetable  `json:"wavetables"`                           
}

type Lfo struct {
	Name      string    `json:"name"`      
	NumPoints float64   `json:"num_points"`
	Points    []float64 `json:"points"`    
	Powers    []float64 `json:"powers"`    
	Smooth    bool      `json:"smooth"`    
}

type Modulation struct {
	Destination string `json:"destination"`           
	LineMapping *Lfo   `json:"line_mapping,omitempty"`
	Source      Source `json:"source"`                
}

type Sample struct {
	Length        float64 `json:"length"`                  
	Name          string  `json:"name"`                    
	SampleRate    float64 `json:"sample_rate"`             
	Samples       string  `json:"samples"`                 
	SamplesStereo *string `json:"samples_stereo,omitempty"`
}

type Wavetable struct {
	Author        *string `json:"author,omitempty"`
	FullNormalize bool    `json:"full_normalize"`  
	Groups        []Group `json:"groups"`          
	Name          string  `json:"name"`            
	RemoveAllDc   bool    `json:"remove_all_dc"`   
	Version       string  `json:"version"`         
}

type Group struct {
	Components []Component `json:"components"`
}

type Component struct {
	AudioFile            *string    `json:"audio_file,omitempty"`           
	AudioSampleRate      *float64   `json:"audio_sample_rate,omitempty"`    
	FadeStyle            *float64   `json:"fade_style,omitempty"`           
	HorizontalAsymmetric *bool      `json:"horizontal_asymmetric,omitempty"`
	Interpolation        *float64   `json:"interpolation,omitempty"`        
	InterpolationStyle   float64    `json:"interpolation_style"`            
	Keyframes            []Keyframe `json:"keyframes"`                      
	Normalize            *bool      `json:"normalize,omitempty"`            
	NormalizeGain        *bool      `json:"normalize_gain,omitempty"`       
	NormalizeMult        *bool      `json:"normalize_mult,omitempty"`       
	NumPoints            *float64   `json:"num_points,omitempty"`           
	PhaseStyle           *float64   `json:"phase_style,omitempty"`          
	RandomSeed           *float64   `json:"random_seed,omitempty"`          
	Style                *float64   `json:"style,omitempty"`                
	Type                 Type       `json:"type"`                           
	VerticalAsymmetric   *bool      `json:"vertical_asymmetric,omitempty"`  
	WindowShape          *float64   `json:"window_shape,omitempty"`         
	WindowSize           *float64   `json:"window_size,omitempty"`          
}

type Keyframe struct {
	Cutoff          *float64 `json:"cutoff,omitempty"`          
	DownRunRise     *float64 `json:"down_run_rise,omitempty"`   
	FoldBoost       *float64 `json:"fold_boost,omitempty"`      
	HorizontalPower *float64 `json:"horizontal_power,omitempty"`
	LeftPosition    *float64 `json:"left_position,omitempty"`   
	Line            *Lfo     `json:"line,omitempty"`            
	Mix             *float64 `json:"mix,omitempty"`             
	Phase           *float64 `json:"phase,omitempty"`           
	Position        float64  `json:"position"`                  
	PullPower       *float64 `json:"pull_power,omitempty"`      
	RightPosition   *float64 `json:"right_position,omitempty"`  
	Shape           *float64 `json:"shape,omitempty"`           
	StartPosition   *float64 `json:"start_position,omitempty"`  
	UpRunRise       *float64 `json:"up_run_rise,omitempty"`     
	VerticalPower   *float64 `json:"vertical_power,omitempty"`  
	WaveData        *string  `json:"wave_data,omitempty"`       
	WindowFade      *float64 `json:"window_fade,omitempty"`     
	WindowSize      *float64 `json:"window_size,omitempty"`     
}

type PresetStyle string
const (
	Bass PresetStyle = "Bass"
	Experiment PresetStyle = "Experiment"
	Keys PresetStyle = "Keys"
	Lead PresetStyle = "Lead"
	Pad PresetStyle = "Pad"
	Percussion PresetStyle = "Percussion"
	Purple PresetStyle = ""
	Sequence PresetStyle = "Sequence"
	Sfx PresetStyle = "SFX"
	Template PresetStyle = "Template"
)

type Source string
const (
	Aftertouch Source = "aftertouch"
	Env1 Source = "env_1"
	Env2 Source = "env_2"
	Env3 Source = "env_3"
	Env4 Source = "env_4"
	Env5 Source = "env_5"
	Env6 Source = "env_6"
	Fluffy Source = ""
	Lfo1 Source = "lfo_1"
	Lfo2 Source = "lfo_2"
	Lfo3 Source = "lfo_3"
	Lfo4 Source = "lfo_4"
	Lfo5 Source = "lfo_5"
	Lfo6 Source = "lfo_6"
	Lfo7 Source = "lfo_7"
	Lfo8 Source = "lfo_8"
	Lift Source = "lift"
	MacroControl1 Source = "macro_control_1"
	MacroControl2 Source = "macro_control_2"
	MacroControl3 Source = "macro_control_3"
	MacroControl4 Source = "macro_control_4"
	ModWheel Source = "mod_wheel"
	Note Source = "note"
	NoteInOctave Source = "note_in_octave"
	PitchWheel Source = "pitch_wheel"
	Random Source = "random"
	Random1 Source = "random_1"
	Random2 Source = "random_2"
	Random3 Source = "random_3"
	Random4 Source = "random_4"
	Slide Source = "slide"
	Stereo Source = "stereo"
	Velocity Source = "velocity"
)

type Type string
const (
	AudioFileSource Type = "Audio File Source"
	FrequencyFilter Type = "Frequency Filter"
	LineSource Type = "Line Source"
	PhaseShift Type = "Phase Shift"
	ShepardToneSource Type = "Shepard Tone Source"
	SlewLimiter Type = "Slew Limiter"
	WaveFolder Type = "Wave Folder"
	WaveSource Type = "Wave Source"
	WaveWarp Type = "Wave Warp"
	WaveWindow Type = "Wave Window"
)
