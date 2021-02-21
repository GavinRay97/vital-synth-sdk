//  To parse this JSON data, first install
//
//      Boost     http://www.boost.org
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     VitalPreset data = nlohmann::json::parse(jsonString);
//     PresetStyle data = nlohmann::json::parse(jsonString);
//     PresetSettings data = nlohmann::json::parse(jsonString);
//     Lfo data = nlohmann::json::parse(jsonString);
//     Modulation data = nlohmann::json::parse(jsonString);
//     Source data = nlohmann::json::parse(jsonString);
//     Sample data = nlohmann::json::parse(jsonString);
//     Wavetable data = nlohmann::json::parse(jsonString);
//     Group data = nlohmann::json::parse(jsonString);
//     Component data = nlohmann::json::parse(jsonString);
//     Keyframe data = nlohmann::json::parse(jsonString);
//     Type data = nlohmann::json::parse(jsonString);

#pragma once

#include "json.hpp"

#include <boost/optional.hpp>
#include <stdexcept>
#include <regex>
#include <unordered_map>

#ifndef NLOHMANN_OPT_HELPER
#define NLOHMANN_OPT_HELPER
namespace nlohmann {
    template <typename T>
    struct adl_serializer<std::shared_ptr<T>> {
        static void to_json(json & j, const std::shared_ptr<T> & opt) {
            if (!opt) j = nullptr; else j = *opt;
        }

        static std::shared_ptr<T> from_json(const json & j) {
            if (j.is_null()) return std::unique_ptr<T>(); else return std::unique_ptr<T>(new T(j.get<T>()));
        }
    };
}
#endif

namespace quicktype {
    using nlohmann::json;

    inline json get_untyped(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<json>();
        }
        return json();
    }

    inline json get_untyped(const json & j, std::string property) {
        return get_untyped(j, property.data());
    }

    template <typename T>
    inline std::shared_ptr<T> get_optional(const json & j, const char * property) {
        if (j.find(property) != j.end()) {
            return j.at(property).get<std::shared_ptr<T>>();
        }
        return std::shared_ptr<T>();
    }

    template <typename T>
    inline std::shared_ptr<T> get_optional(const json & j, std::string property) {
        return get_optional<T>(j, property.data());
    }

    enum class PresetStyle : int { BASS, EMPTY, EXPERIMENT, KEYS, LEAD, PAD, PERCUSSION, SEQUENCE, SFX, TEMPLATE };

    class Lfo {
        public:
        Lfo() = default;
        virtual ~Lfo() = default;

        private:
        std::string name;
        double num_points;
        std::vector<double> points;
        std::vector<double> powers;
        bool smooth;

        public:
        const std::string & get_name() const { return name; }
        std::string & get_mutable_name() { return name; }
        void set_name(const std::string & value) { this->name = value; }

        const double & get_num_points() const { return num_points; }
        double & get_mutable_num_points() { return num_points; }
        void set_num_points(const double & value) { this->num_points = value; }

        const std::vector<double> & get_points() const { return points; }
        std::vector<double> & get_mutable_points() { return points; }
        void set_points(const std::vector<double> & value) { this->points = value; }

        const std::vector<double> & get_powers() const { return powers; }
        std::vector<double> & get_mutable_powers() { return powers; }
        void set_powers(const std::vector<double> & value) { this->powers = value; }

        const bool & get_smooth() const { return smooth; }
        bool & get_mutable_smooth() { return smooth; }
        void set_smooth(const bool & value) { this->smooth = value; }
    };

    enum class Source : int { AFTERTOUCH, EMPTY, ENV_1, ENV_2, ENV_3, ENV_4, ENV_5, ENV_6, LFO_1, LFO_2, LFO_3, LFO_4, LFO_5, LFO_6, LFO_7, LFO_8, LIFT, MACRO_CONTROL_1, MACRO_CONTROL_2, MACRO_CONTROL_3, MACRO_CONTROL_4, MOD_WHEEL, NOTE, NOTE_IN_OCTAVE, PITCH_WHEEL, RANDOM, RANDOM_1, RANDOM_2, RANDOM_3, RANDOM_4, SLIDE, STEREO, VELOCITY };

    class Modulation {
        public:
        Modulation() = default;
        virtual ~Modulation() = default;

        private:
        std::string destination;
        std::shared_ptr<Lfo> line_mapping;
        Source source;

        public:
        const std::string & get_destination() const { return destination; }
        std::string & get_mutable_destination() { return destination; }
        void set_destination(const std::string & value) { this->destination = value; }

        std::shared_ptr<Lfo> get_line_mapping() const { return line_mapping; }
        void set_line_mapping(std::shared_ptr<Lfo> value) { this->line_mapping = value; }

        const Source & get_source() const { return source; }
        Source & get_mutable_source() { return source; }
        void set_source(const Source & value) { this->source = value; }
    };

    class Sample {
        public:
        Sample() = default;
        virtual ~Sample() = default;

        private:
        double length;
        std::string name;
        double sample_rate;
        std::string samples;
        std::shared_ptr<std::string> samples_stereo;

        public:
        const double & get_length() const { return length; }
        double & get_mutable_length() { return length; }
        void set_length(const double & value) { this->length = value; }

        const std::string & get_name() const { return name; }
        std::string & get_mutable_name() { return name; }
        void set_name(const std::string & value) { this->name = value; }

        const double & get_sample_rate() const { return sample_rate; }
        double & get_mutable_sample_rate() { return sample_rate; }
        void set_sample_rate(const double & value) { this->sample_rate = value; }

        const std::string & get_samples() const { return samples; }
        std::string & get_mutable_samples() { return samples; }
        void set_samples(const std::string & value) { this->samples = value; }

        std::shared_ptr<std::string> get_samples_stereo() const { return samples_stereo; }
        void set_samples_stereo(std::shared_ptr<std::string> value) { this->samples_stereo = value; }
    };

    class Keyframe {
        public:
        Keyframe() = default;
        virtual ~Keyframe() = default;

        private:
        std::shared_ptr<double> cutoff;
        std::shared_ptr<double> down_run_rise;
        std::shared_ptr<double> fold_boost;
        std::shared_ptr<double> horizontal_power;
        std::shared_ptr<double> left_position;
        std::shared_ptr<Lfo> line;
        std::shared_ptr<double> mix;
        std::shared_ptr<double> phase;
        double position;
        std::shared_ptr<double> pull_power;
        std::shared_ptr<double> right_position;
        std::shared_ptr<double> shape;
        std::shared_ptr<double> start_position;
        std::shared_ptr<double> up_run_rise;
        std::shared_ptr<double> vertical_power;
        std::shared_ptr<std::string> wave_data;
        std::shared_ptr<double> window_fade;
        std::shared_ptr<double> window_size;

        public:
        std::shared_ptr<double> get_cutoff() const { return cutoff; }
        void set_cutoff(std::shared_ptr<double> value) { this->cutoff = value; }

        std::shared_ptr<double> get_down_run_rise() const { return down_run_rise; }
        void set_down_run_rise(std::shared_ptr<double> value) { this->down_run_rise = value; }

        std::shared_ptr<double> get_fold_boost() const { return fold_boost; }
        void set_fold_boost(std::shared_ptr<double> value) { this->fold_boost = value; }

        std::shared_ptr<double> get_horizontal_power() const { return horizontal_power; }
        void set_horizontal_power(std::shared_ptr<double> value) { this->horizontal_power = value; }

        std::shared_ptr<double> get_left_position() const { return left_position; }
        void set_left_position(std::shared_ptr<double> value) { this->left_position = value; }

        std::shared_ptr<Lfo> get_line() const { return line; }
        void set_line(std::shared_ptr<Lfo> value) { this->line = value; }

        std::shared_ptr<double> get_mix() const { return mix; }
        void set_mix(std::shared_ptr<double> value) { this->mix = value; }

        std::shared_ptr<double> get_phase() const { return phase; }
        void set_phase(std::shared_ptr<double> value) { this->phase = value; }

        const double & get_position() const { return position; }
        double & get_mutable_position() { return position; }
        void set_position(const double & value) { this->position = value; }

        std::shared_ptr<double> get_pull_power() const { return pull_power; }
        void set_pull_power(std::shared_ptr<double> value) { this->pull_power = value; }

        std::shared_ptr<double> get_right_position() const { return right_position; }
        void set_right_position(std::shared_ptr<double> value) { this->right_position = value; }

        std::shared_ptr<double> get_shape() const { return shape; }
        void set_shape(std::shared_ptr<double> value) { this->shape = value; }

        std::shared_ptr<double> get_start_position() const { return start_position; }
        void set_start_position(std::shared_ptr<double> value) { this->start_position = value; }

        std::shared_ptr<double> get_up_run_rise() const { return up_run_rise; }
        void set_up_run_rise(std::shared_ptr<double> value) { this->up_run_rise = value; }

        std::shared_ptr<double> get_vertical_power() const { return vertical_power; }
        void set_vertical_power(std::shared_ptr<double> value) { this->vertical_power = value; }

        std::shared_ptr<std::string> get_wave_data() const { return wave_data; }
        void set_wave_data(std::shared_ptr<std::string> value) { this->wave_data = value; }

        std::shared_ptr<double> get_window_fade() const { return window_fade; }
        void set_window_fade(std::shared_ptr<double> value) { this->window_fade = value; }

        std::shared_ptr<double> get_window_size() const { return window_size; }
        void set_window_size(std::shared_ptr<double> value) { this->window_size = value; }
    };

    enum class Type : int { AUDIO_FILE_SOURCE, FREQUENCY_FILTER, LINE_SOURCE, PHASE_SHIFT, SHEPARD_TONE_SOURCE, SLEW_LIMITER, WAVE_FOLDER, WAVE_SOURCE, WAVE_WARP, WAVE_WINDOW };

    class Component {
        public:
        Component() = default;
        virtual ~Component() = default;

        private:
        std::shared_ptr<std::string> audio_file;
        std::shared_ptr<double> audio_sample_rate;
        std::shared_ptr<double> fade_style;
        std::shared_ptr<bool> horizontal_asymmetric;
        std::shared_ptr<double> interpolation;
        double interpolation_style;
        std::shared_ptr<std::vector<Keyframe>> keyframes;
        std::shared_ptr<bool> normalize;
        std::shared_ptr<bool> normalize_gain;
        std::shared_ptr<bool> normalize_mult;
        std::shared_ptr<double> num_points;
        std::shared_ptr<double> phase_style;
        std::shared_ptr<double> random_seed;
        std::shared_ptr<double> style;
        Type type;
        std::shared_ptr<bool> vertical_asymmetric;
        std::shared_ptr<double> window_shape;
        std::shared_ptr<double> window_size;

        public:
        std::shared_ptr<std::string> get_audio_file() const { return audio_file; }
        void set_audio_file(std::shared_ptr<std::string> value) { this->audio_file = value; }

        std::shared_ptr<double> get_audio_sample_rate() const { return audio_sample_rate; }
        void set_audio_sample_rate(std::shared_ptr<double> value) { this->audio_sample_rate = value; }

        std::shared_ptr<double> get_fade_style() const { return fade_style; }
        void set_fade_style(std::shared_ptr<double> value) { this->fade_style = value; }

        std::shared_ptr<bool> get_horizontal_asymmetric() const { return horizontal_asymmetric; }
        void set_horizontal_asymmetric(std::shared_ptr<bool> value) { this->horizontal_asymmetric = value; }

        std::shared_ptr<double> get_interpolation() const { return interpolation; }
        void set_interpolation(std::shared_ptr<double> value) { this->interpolation = value; }

        const double & get_interpolation_style() const { return interpolation_style; }
        double & get_mutable_interpolation_style() { return interpolation_style; }
        void set_interpolation_style(const double & value) { this->interpolation_style = value; }

        std::shared_ptr<std::vector<Keyframe>> get_keyframes() const { return keyframes; }
        void set_keyframes(std::shared_ptr<std::vector<Keyframe>> value) { this->keyframes = value; }

        std::shared_ptr<bool> get_normalize() const { return normalize; }
        void set_normalize(std::shared_ptr<bool> value) { this->normalize = value; }

        std::shared_ptr<bool> get_normalize_gain() const { return normalize_gain; }
        void set_normalize_gain(std::shared_ptr<bool> value) { this->normalize_gain = value; }

        std::shared_ptr<bool> get_normalize_mult() const { return normalize_mult; }
        void set_normalize_mult(std::shared_ptr<bool> value) { this->normalize_mult = value; }

        std::shared_ptr<double> get_num_points() const { return num_points; }
        void set_num_points(std::shared_ptr<double> value) { this->num_points = value; }

        std::shared_ptr<double> get_phase_style() const { return phase_style; }
        void set_phase_style(std::shared_ptr<double> value) { this->phase_style = value; }

        std::shared_ptr<double> get_random_seed() const { return random_seed; }
        void set_random_seed(std::shared_ptr<double> value) { this->random_seed = value; }

        std::shared_ptr<double> get_style() const { return style; }
        void set_style(std::shared_ptr<double> value) { this->style = value; }

        const Type & get_type() const { return type; }
        Type & get_mutable_type() { return type; }
        void set_type(const Type & value) { this->type = value; }

        std::shared_ptr<bool> get_vertical_asymmetric() const { return vertical_asymmetric; }
        void set_vertical_asymmetric(std::shared_ptr<bool> value) { this->vertical_asymmetric = value; }

        std::shared_ptr<double> get_window_shape() const { return window_shape; }
        void set_window_shape(std::shared_ptr<double> value) { this->window_shape = value; }

        std::shared_ptr<double> get_window_size() const { return window_size; }
        void set_window_size(std::shared_ptr<double> value) { this->window_size = value; }
    };

    class Group {
        public:
        Group() = default;
        virtual ~Group() = default;

        private:
        std::vector<Component> components;

        public:
        const std::vector<Component> & get_components() const { return components; }
        std::vector<Component> & get_mutable_components() { return components; }
        void set_components(const std::vector<Component> & value) { this->components = value; }
    };

    class Wavetable {
        public:
        Wavetable() = default;
        virtual ~Wavetable() = default;

        private:
        std::shared_ptr<std::string> author;
        bool full_normalize;
        std::vector<Group> groups;
        std::string name;
        bool remove_all_dc;
        std::string version;

        public:
        std::shared_ptr<std::string> get_author() const { return author; }
        void set_author(std::shared_ptr<std::string> value) { this->author = value; }

        const bool & get_full_normalize() const { return full_normalize; }
        bool & get_mutable_full_normalize() { return full_normalize; }
        void set_full_normalize(const bool & value) { this->full_normalize = value; }

        const std::vector<Group> & get_groups() const { return groups; }
        std::vector<Group> & get_mutable_groups() { return groups; }
        void set_groups(const std::vector<Group> & value) { this->groups = value; }

        const std::string & get_name() const { return name; }
        std::string & get_mutable_name() { return name; }
        void set_name(const std::string & value) { this->name = value; }

        const bool & get_remove_all_dc() const { return remove_all_dc; }
        bool & get_mutable_remove_all_dc() { return remove_all_dc; }
        void set_remove_all_dc(const bool & value) { this->remove_all_dc = value; }

        const std::string & get_version() const { return version; }
        std::string & get_mutable_version() { return version; }
        void set_version(const std::string & value) { this->version = value; }
    };

    class PresetSettings {
        public:
        PresetSettings() = default;
        virtual ~PresetSettings() = default;

        private:
        double beats_per_minute;
        std::shared_ptr<double> bypass;
        std::shared_ptr<double> chorus_cutoff;
        std::shared_ptr<double> chorus_damping;
        double chorus_delay_1;
        double chorus_delay_2;
        double chorus_dry_wet;
        double chorus_feedback;
        double chorus_frequency;
        double chorus_mod_depth;
        double chorus_on;
        std::shared_ptr<double> chorus_spread;
        double chorus_sync;
        double chorus_tempo;
        double chorus_voices;
        double compressor_attack;
        double compressor_band_gain;
        double compressor_band_lower_ratio;
        double compressor_band_lower_threshold;
        double compressor_band_upper_ratio;
        double compressor_band_upper_threshold;
        double compressor_enabled_bands;
        double compressor_high_gain;
        double compressor_high_lower_ratio;
        double compressor_high_lower_threshold;
        double compressor_high_upper_ratio;
        double compressor_high_upper_threshold;
        double compressor_low_gain;
        double compressor_low_lower_ratio;
        double compressor_low_lower_threshold;
        double compressor_low_upper_ratio;
        double compressor_low_upper_threshold;
        std::shared_ptr<double> compressor_mix;
        double compressor_on;
        double compressor_release;
        double delay_aux_frequency;
        double delay_aux_sync;
        double delay_aux_tempo;
        double delay_dry_wet;
        double delay_feedback;
        double delay_filter_cutoff;
        double delay_filter_spread;
        double delay_frequency;
        double delay_on;
        double delay_style;
        double delay_sync;
        double delay_tempo;
        double distortion_drive;
        double distortion_filter_blend;
        double distortion_filter_cutoff;
        double distortion_filter_order;
        double distortion_filter_resonance;
        double distortion_mix;
        double distortion_on;
        double distortion_type;
        double effect_chain_order;
        double env_1__attack;
        double env_1__attack_power;
        double env_1__decay;
        double env_1__decay_power;
        double env_1__delay;
        double env_1__hold;
        double env_1__release;
        double env_1__release_power;
        double env_1__sustain;
        double env_2__attack;
        double env_2__attack_power;
        double env_2__decay;
        double env_2__decay_power;
        double env_2__delay;
        double env_2__hold;
        double env_2__release;
        double env_2__release_power;
        double env_2__sustain;
        double env_3__attack;
        double env_3__attack_power;
        double env_3__decay;
        double env_3__decay_power;
        double env_3__delay;
        double env_3__hold;
        double env_3__release;
        double env_3__release_power;
        double env_3__sustain;
        double env_4__attack;
        double env_4__attack_power;
        double env_4__decay;
        double env_4__decay_power;
        double env_4__delay;
        double env_4__hold;
        double env_4__release;
        double env_4__release_power;
        double env_4__sustain;
        double env_5__attack;
        double env_5__attack_power;
        double env_5__decay;
        double env_5__decay_power;
        double env_5__delay;
        double env_5__hold;
        double env_5__release;
        double env_5__release_power;
        double env_5__sustain;
        double env_6__attack;
        double env_6__attack_power;
        double env_6__decay;
        double env_6__decay_power;
        double env_6__delay;
        double env_6__hold;
        double env_6__release;
        double env_6__release_power;
        double env_6__sustain;
        double eq_band_cutoff;
        double eq_band_gain;
        double eq_band_mode;
        double eq_band_resonance;
        double eq_high_cutoff;
        double eq_high_gain;
        double eq_high_mode;
        double eq_high_resonance;
        double eq_low_cutoff;
        double eq_low_gain;
        double eq_low_mode;
        double eq_low_resonance;
        double eq_on;
        double filter_1__blend;
        double filter_1__blend_transpose;
        double filter_1__cutoff;
        double filter_1__drive;
        double filter_1__filter_input;
        double filter_1__formant_resonance;
        std::shared_ptr<double> filter_1__formant_spread;
        double filter_1__formant_transpose;
        double filter_1__formant_x;
        double filter_1__formant_y;
        double filter_1__keytrack;
        double filter_1__mix;
        double filter_1__model;
        double filter_1__on;
        double filter_1__resonance;
        double filter_1__style;
        double filter_2__blend;
        double filter_2__blend_transpose;
        double filter_2__cutoff;
        double filter_2__drive;
        double filter_2__filter_input;
        double filter_2__formant_resonance;
        std::shared_ptr<double> filter_2__formant_spread;
        double filter_2__formant_transpose;
        double filter_2__formant_x;
        double filter_2__formant_y;
        double filter_2__keytrack;
        double filter_2__mix;
        double filter_2__model;
        double filter_2__on;
        double filter_2__resonance;
        double filter_2__style;
        double filter_fx_blend;
        double filter_fx_blend_transpose;
        double filter_fx_cutoff;
        double filter_fx_drive;
        double filter_fx_formant_resonance;
        std::shared_ptr<double> filter_fx_formant_spread;
        double filter_fx_formant_transpose;
        double filter_fx_formant_x;
        double filter_fx_formant_y;
        double filter_fx_keytrack;
        double filter_fx_mix;
        double filter_fx_model;
        double filter_fx_on;
        double filter_fx_resonance;
        double filter_fx_style;
        double flanger_center;
        double flanger_dry_wet;
        double flanger_feedback;
        double flanger_frequency;
        double flanger_mod_depth;
        double flanger_on;
        double flanger_phase_offset;
        double flanger_sync;
        double flanger_tempo;
        double legato;
        double lfo_1__delay_time;
        double lfo_1__fade_time;
        double lfo_1__frequency;
        std::shared_ptr<double> lfo_1__keytrack_transpose;
        std::shared_ptr<double> lfo_1__keytrack_tune;
        double lfo_1__phase;
        std::shared_ptr<double> lfo_1__smooth_mode;
        std::shared_ptr<double> lfo_1__smooth_time;
        double lfo_1__stereo;
        double lfo_1__sync;
        double lfo_1__sync_type;
        double lfo_1__tempo;
        double lfo_2__delay_time;
        double lfo_2__fade_time;
        double lfo_2__frequency;
        std::shared_ptr<double> lfo_2__keytrack_transpose;
        std::shared_ptr<double> lfo_2__keytrack_tune;
        double lfo_2__phase;
        std::shared_ptr<double> lfo_2__smooth_mode;
        std::shared_ptr<double> lfo_2__smooth_time;
        double lfo_2__stereo;
        double lfo_2__sync;
        double lfo_2__sync_type;
        double lfo_2__tempo;
        double lfo_3__delay_time;
        double lfo_3__fade_time;
        double lfo_3__frequency;
        std::shared_ptr<double> lfo_3__keytrack_transpose;
        std::shared_ptr<double> lfo_3__keytrack_tune;
        double lfo_3__phase;
        std::shared_ptr<double> lfo_3__smooth_mode;
        std::shared_ptr<double> lfo_3__smooth_time;
        double lfo_3__stereo;
        double lfo_3__sync;
        double lfo_3__sync_type;
        double lfo_3__tempo;
        double lfo_4__delay_time;
        double lfo_4__fade_time;
        double lfo_4__frequency;
        std::shared_ptr<double> lfo_4__keytrack_transpose;
        std::shared_ptr<double> lfo_4__keytrack_tune;
        double lfo_4__phase;
        std::shared_ptr<double> lfo_4__smooth_mode;
        std::shared_ptr<double> lfo_4__smooth_time;
        double lfo_4__stereo;
        double lfo_4__sync;
        double lfo_4__sync_type;
        double lfo_4__tempo;
        double lfo_5__delay_time;
        double lfo_5__fade_time;
        double lfo_5__frequency;
        std::shared_ptr<double> lfo_5__keytrack_transpose;
        std::shared_ptr<double> lfo_5__keytrack_tune;
        double lfo_5__phase;
        std::shared_ptr<double> lfo_5__smooth_mode;
        std::shared_ptr<double> lfo_5__smooth_time;
        double lfo_5__stereo;
        double lfo_5__sync;
        double lfo_5__sync_type;
        double lfo_5__tempo;
        double lfo_6__delay_time;
        double lfo_6__fade_time;
        double lfo_6__frequency;
        std::shared_ptr<double> lfo_6__keytrack_transpose;
        std::shared_ptr<double> lfo_6__keytrack_tune;
        double lfo_6__phase;
        std::shared_ptr<double> lfo_6__smooth_mode;
        std::shared_ptr<double> lfo_6__smooth_time;
        double lfo_6__stereo;
        double lfo_6__sync;
        double lfo_6__sync_type;
        double lfo_6__tempo;
        double lfo_7__delay_time;
        double lfo_7__fade_time;
        double lfo_7__frequency;
        std::shared_ptr<double> lfo_7__keytrack_transpose;
        std::shared_ptr<double> lfo_7__keytrack_tune;
        double lfo_7__phase;
        std::shared_ptr<double> lfo_7__smooth_mode;
        std::shared_ptr<double> lfo_7__smooth_time;
        double lfo_7__stereo;
        double lfo_7__sync;
        double lfo_7__sync_type;
        double lfo_7__tempo;
        double lfo_8__delay_time;
        double lfo_8__fade_time;
        double lfo_8__frequency;
        std::shared_ptr<double> lfo_8__keytrack_transpose;
        std::shared_ptr<double> lfo_8__keytrack_tune;
        double lfo_8__phase;
        std::shared_ptr<double> lfo_8__smooth_mode;
        std::shared_ptr<double> lfo_8__smooth_time;
        double lfo_8__stereo;
        double lfo_8__sync;
        double lfo_8__sync_type;
        double lfo_8__tempo;
        std::vector<Lfo> lfos;
        double macro_control_1;
        double macro_control_2;
        double macro_control_3;
        double macro_control_4;
        double mod_wheel;
        double modulation_10__amount;
        double modulation_10__bipolar;
        double modulation_10__bypass;
        double modulation_10__power;
        double modulation_10__stereo;
        double modulation_11__amount;
        double modulation_11__bipolar;
        double modulation_11__bypass;
        double modulation_11__power;
        double modulation_11__stereo;
        double modulation_12__amount;
        double modulation_12__bipolar;
        double modulation_12__bypass;
        double modulation_12__power;
        double modulation_12__stereo;
        double modulation_13__amount;
        double modulation_13__bipolar;
        double modulation_13__bypass;
        double modulation_13__power;
        double modulation_13__stereo;
        double modulation_14__amount;
        double modulation_14__bipolar;
        double modulation_14__bypass;
        double modulation_14__power;
        double modulation_14__stereo;
        double modulation_15__amount;
        double modulation_15__bipolar;
        double modulation_15__bypass;
        double modulation_15__power;
        double modulation_15__stereo;
        double modulation_16__amount;
        double modulation_16__bipolar;
        double modulation_16__bypass;
        double modulation_16__power;
        double modulation_16__stereo;
        double modulation_17__amount;
        double modulation_17__bipolar;
        double modulation_17__bypass;
        double modulation_17__power;
        double modulation_17__stereo;
        double modulation_18__amount;
        double modulation_18__bipolar;
        double modulation_18__bypass;
        double modulation_18__power;
        double modulation_18__stereo;
        double modulation_19__amount;
        double modulation_19__bipolar;
        double modulation_19__bypass;
        double modulation_19__power;
        double modulation_19__stereo;
        double modulation_1__amount;
        double modulation_1__bipolar;
        double modulation_1__bypass;
        double modulation_1__power;
        double modulation_1__stereo;
        double modulation_20__amount;
        double modulation_20__bipolar;
        double modulation_20__bypass;
        double modulation_20__power;
        double modulation_20__stereo;
        double modulation_21__amount;
        double modulation_21__bipolar;
        double modulation_21__bypass;
        double modulation_21__power;
        double modulation_21__stereo;
        double modulation_22__amount;
        double modulation_22__bipolar;
        double modulation_22__bypass;
        double modulation_22__power;
        double modulation_22__stereo;
        double modulation_23__amount;
        double modulation_23__bipolar;
        double modulation_23__bypass;
        double modulation_23__power;
        double modulation_23__stereo;
        double modulation_24__amount;
        double modulation_24__bipolar;
        double modulation_24__bypass;
        double modulation_24__power;
        double modulation_24__stereo;
        double modulation_25__amount;
        double modulation_25__bipolar;
        double modulation_25__bypass;
        double modulation_25__power;
        double modulation_25__stereo;
        double modulation_26__amount;
        double modulation_26__bipolar;
        double modulation_26__bypass;
        double modulation_26__power;
        double modulation_26__stereo;
        double modulation_27__amount;
        double modulation_27__bipolar;
        double modulation_27__bypass;
        double modulation_27__power;
        double modulation_27__stereo;
        double modulation_28__amount;
        double modulation_28__bipolar;
        double modulation_28__bypass;
        double modulation_28__power;
        double modulation_28__stereo;
        double modulation_29__amount;
        double modulation_29__bipolar;
        double modulation_29__bypass;
        double modulation_29__power;
        double modulation_29__stereo;
        double modulation_2__amount;
        double modulation_2__bipolar;
        double modulation_2__bypass;
        double modulation_2__power;
        double modulation_2__stereo;
        double modulation_30__amount;
        double modulation_30__bipolar;
        double modulation_30__bypass;
        double modulation_30__power;
        double modulation_30__stereo;
        double modulation_31__amount;
        double modulation_31__bipolar;
        double modulation_31__bypass;
        double modulation_31__power;
        double modulation_31__stereo;
        double modulation_32__amount;
        double modulation_32__bipolar;
        double modulation_32__bypass;
        double modulation_32__power;
        double modulation_32__stereo;
        double modulation_33__amount;
        double modulation_33__bipolar;
        double modulation_33__bypass;
        double modulation_33__power;
        double modulation_33__stereo;
        double modulation_34__amount;
        double modulation_34__bipolar;
        double modulation_34__bypass;
        double modulation_34__power;
        double modulation_34__stereo;
        double modulation_35__amount;
        double modulation_35__bipolar;
        double modulation_35__bypass;
        double modulation_35__power;
        double modulation_35__stereo;
        double modulation_36__amount;
        double modulation_36__bipolar;
        double modulation_36__bypass;
        double modulation_36__power;
        double modulation_36__stereo;
        double modulation_37__amount;
        double modulation_37__bipolar;
        double modulation_37__bypass;
        double modulation_37__power;
        double modulation_37__stereo;
        double modulation_38__amount;
        double modulation_38__bipolar;
        double modulation_38__bypass;
        double modulation_38__power;
        double modulation_38__stereo;
        double modulation_39__amount;
        double modulation_39__bipolar;
        double modulation_39__bypass;
        double modulation_39__power;
        double modulation_39__stereo;
        double modulation_3__amount;
        double modulation_3__bipolar;
        double modulation_3__bypass;
        double modulation_3__power;
        double modulation_3__stereo;
        double modulation_40__amount;
        double modulation_40__bipolar;
        double modulation_40__bypass;
        double modulation_40__power;
        double modulation_40__stereo;
        double modulation_41__amount;
        double modulation_41__bipolar;
        double modulation_41__bypass;
        double modulation_41__power;
        double modulation_41__stereo;
        double modulation_42__amount;
        double modulation_42__bipolar;
        double modulation_42__bypass;
        double modulation_42__power;
        double modulation_42__stereo;
        double modulation_43__amount;
        double modulation_43__bipolar;
        double modulation_43__bypass;
        double modulation_43__power;
        double modulation_43__stereo;
        double modulation_44__amount;
        double modulation_44__bipolar;
        double modulation_44__bypass;
        double modulation_44__power;
        double modulation_44__stereo;
        double modulation_45__amount;
        double modulation_45__bipolar;
        double modulation_45__bypass;
        double modulation_45__power;
        double modulation_45__stereo;
        double modulation_46__amount;
        double modulation_46__bipolar;
        double modulation_46__bypass;
        double modulation_46__power;
        double modulation_46__stereo;
        double modulation_47__amount;
        double modulation_47__bipolar;
        double modulation_47__bypass;
        double modulation_47__power;
        double modulation_47__stereo;
        double modulation_48__amount;
        double modulation_48__bipolar;
        double modulation_48__bypass;
        double modulation_48__power;
        double modulation_48__stereo;
        double modulation_49__amount;
        double modulation_49__bipolar;
        double modulation_49__bypass;
        double modulation_49__power;
        double modulation_49__stereo;
        double modulation_4__amount;
        double modulation_4__bipolar;
        double modulation_4__bypass;
        double modulation_4__power;
        double modulation_4__stereo;
        double modulation_50__amount;
        double modulation_50__bipolar;
        double modulation_50__bypass;
        double modulation_50__power;
        double modulation_50__stereo;
        double modulation_51__amount;
        double modulation_51__bipolar;
        double modulation_51__bypass;
        double modulation_51__power;
        double modulation_51__stereo;
        double modulation_52__amount;
        double modulation_52__bipolar;
        double modulation_52__bypass;
        double modulation_52__power;
        double modulation_52__stereo;
        double modulation_53__amount;
        double modulation_53__bipolar;
        double modulation_53__bypass;
        double modulation_53__power;
        double modulation_53__stereo;
        double modulation_54__amount;
        double modulation_54__bipolar;
        double modulation_54__bypass;
        double modulation_54__power;
        double modulation_54__stereo;
        double modulation_55__amount;
        double modulation_55__bipolar;
        double modulation_55__bypass;
        double modulation_55__power;
        double modulation_55__stereo;
        double modulation_56__amount;
        double modulation_56__bipolar;
        double modulation_56__bypass;
        double modulation_56__power;
        double modulation_56__stereo;
        double modulation_57__amount;
        double modulation_57__bipolar;
        double modulation_57__bypass;
        double modulation_57__power;
        double modulation_57__stereo;
        double modulation_58__amount;
        double modulation_58__bipolar;
        double modulation_58__bypass;
        double modulation_58__power;
        double modulation_58__stereo;
        double modulation_59__amount;
        double modulation_59__bipolar;
        double modulation_59__bypass;
        double modulation_59__power;
        double modulation_59__stereo;
        double modulation_5__amount;
        double modulation_5__bipolar;
        double modulation_5__bypass;
        double modulation_5__power;
        double modulation_5__stereo;
        double modulation_60__amount;
        double modulation_60__bipolar;
        double modulation_60__bypass;
        double modulation_60__power;
        double modulation_60__stereo;
        double modulation_61__amount;
        double modulation_61__bipolar;
        double modulation_61__bypass;
        double modulation_61__power;
        double modulation_61__stereo;
        double modulation_62__amount;
        double modulation_62__bipolar;
        double modulation_62__bypass;
        double modulation_62__power;
        double modulation_62__stereo;
        double modulation_63__amount;
        double modulation_63__bipolar;
        double modulation_63__bypass;
        double modulation_63__power;
        double modulation_63__stereo;
        double modulation_64__amount;
        double modulation_64__bipolar;
        double modulation_64__bypass;
        double modulation_64__power;
        double modulation_64__stereo;
        double modulation_6__amount;
        double modulation_6__bipolar;
        double modulation_6__bypass;
        double modulation_6__power;
        double modulation_6__stereo;
        double modulation_7__amount;
        double modulation_7__bipolar;
        double modulation_7__bypass;
        double modulation_7__power;
        double modulation_7__stereo;
        double modulation_8__amount;
        double modulation_8__bipolar;
        double modulation_8__bypass;
        double modulation_8__power;
        double modulation_8__stereo;
        double modulation_9__amount;
        double modulation_9__bipolar;
        double modulation_9__bypass;
        double modulation_9__power;
        double modulation_9__stereo;
        std::vector<Modulation> modulations;
        double osc_1__destination;
        double osc_1__detune_power;
        double osc_1__detune_range;
        double osc_1__distortion_amount;
        double osc_1__distortion_phase;
        double osc_1__distortion_spread;
        double osc_1__distortion_type;
        double osc_1__frame_spread;
        double osc_1__level;
        double osc_1__midi_track;
        double osc_1__on;
        double osc_1__pan;
        double osc_1__phase;
        double osc_1__random_phase;
        double osc_1__smooth_interpolation;
        double osc_1__spectral_morph_amount;
        double osc_1__spectral_morph_spread;
        double osc_1__spectral_morph_type;
        double osc_1__spectral_unison;
        double osc_1__stack_style;
        double osc_1__stereo_spread;
        double osc_1__transpose;
        double osc_1__transpose_quantize;
        double osc_1__tune;
        double osc_1__unison_blend;
        double osc_1__unison_detune;
        double osc_1__unison_voices;
        double osc_1__view_2_d;
        double osc_1__wave_frame;
        double osc_2__destination;
        double osc_2__detune_power;
        double osc_2__detune_range;
        double osc_2__distortion_amount;
        double osc_2__distortion_phase;
        double osc_2__distortion_spread;
        double osc_2__distortion_type;
        double osc_2__frame_spread;
        double osc_2__level;
        double osc_2__midi_track;
        double osc_2__on;
        double osc_2__pan;
        double osc_2__phase;
        double osc_2__random_phase;
        double osc_2__smooth_interpolation;
        double osc_2__spectral_morph_amount;
        double osc_2__spectral_morph_spread;
        double osc_2__spectral_morph_type;
        double osc_2__spectral_unison;
        double osc_2__stack_style;
        double osc_2__stereo_spread;
        double osc_2__transpose;
        double osc_2__transpose_quantize;
        double osc_2__tune;
        double osc_2__unison_blend;
        double osc_2__unison_detune;
        double osc_2__unison_voices;
        double osc_2__view_2_d;
        double osc_2__wave_frame;
        double osc_3__destination;
        double osc_3__detune_power;
        double osc_3__detune_range;
        double osc_3__distortion_amount;
        double osc_3__distortion_phase;
        double osc_3__distortion_spread;
        double osc_3__distortion_type;
        double osc_3__frame_spread;
        double osc_3__level;
        double osc_3__midi_track;
        double osc_3__on;
        double osc_3__pan;
        double osc_3__phase;
        double osc_3__random_phase;
        double osc_3__smooth_interpolation;
        double osc_3__spectral_morph_amount;
        double osc_3__spectral_morph_spread;
        double osc_3__spectral_morph_type;
        double osc_3__spectral_unison;
        double osc_3__stack_style;
        double osc_3__stereo_spread;
        double osc_3__transpose;
        double osc_3__transpose_quantize;
        double osc_3__tune;
        double osc_3__unison_blend;
        double osc_3__unison_detune;
        double osc_3__unison_voices;
        double osc_3__view_2_d;
        double osc_3__wave_frame;
        double oversampling;
        double phaser_blend;
        double phaser_center;
        double phaser_dry_wet;
        double phaser_feedback;
        double phaser_frequency;
        double phaser_mod_depth;
        double phaser_on;
        double phaser_phase_offset;
        double phaser_sync;
        double phaser_tempo;
        double pitch_bend_range;
        double pitch_wheel;
        double polyphony;
        double portamento_force;
        double portamento_scale;
        double portamento_slope;
        double portamento_time;
        double random_1__frequency;
        std::shared_ptr<double> random_1__keytrack_transpose;
        std::shared_ptr<double> random_1__keytrack_tune;
        double random_1__stereo;
        double random_1__style;
        double random_1__sync;
        double random_1__sync_type;
        double random_1__tempo;
        double random_2__frequency;
        std::shared_ptr<double> random_2__keytrack_transpose;
        std::shared_ptr<double> random_2__keytrack_tune;
        double random_2__stereo;
        double random_2__style;
        double random_2__sync;
        double random_2__sync_type;
        double random_2__tempo;
        double random_3__frequency;
        std::shared_ptr<double> random_3__keytrack_transpose;
        std::shared_ptr<double> random_3__keytrack_tune;
        double random_3__stereo;
        double random_3__style;
        double random_3__sync;
        double random_3__sync_type;
        double random_3__tempo;
        double random_4__frequency;
        std::shared_ptr<double> random_4__keytrack_transpose;
        std::shared_ptr<double> random_4__keytrack_tune;
        double random_4__stereo;
        double random_4__style;
        double random_4__sync;
        double random_4__sync_type;
        double random_4__tempo;
        double reverb_chorus_amount;
        double reverb_chorus_frequency;
        double reverb_decay_time;
        std::shared_ptr<double> reverb_delay;
        double reverb_dry_wet;
        double reverb_high_shelf_cutoff;
        double reverb_high_shelf_gain;
        double reverb_low_shelf_cutoff;
        double reverb_low_shelf_gain;
        double reverb_on;
        double reverb_pre_high_cutoff;
        double reverb_pre_low_cutoff;
        double reverb_size;
        Sample sample;
        std::shared_ptr<double> sample_bounce;
        double sample_destination;
        double sample_keytrack;
        double sample_level;
        double sample_loop;
        double sample_on;
        double sample_pan;
        double sample_random_phase;
        double sample_transpose;
        double sample_transpose_quantize;
        double sample_tune;
        std::shared_ptr<double> stereo_mode;
        double stereo_routing;
        double velocity_track;
        std::shared_ptr<double> view_spectrogram;
        double voice_amplitude;
        std::shared_ptr<double> voice_override;
        double voice_priority;
        std::shared_ptr<double> voice_transpose;
        double voice_tune;
        double volume;
        std::vector<Wavetable> wavetables;

        public:
        const double & get_beats_per_minute() const { return beats_per_minute; }
        double & get_mutable_beats_per_minute() { return beats_per_minute; }
        void set_beats_per_minute(const double & value) { this->beats_per_minute = value; }

        std::shared_ptr<double> get_bypass() const { return bypass; }
        void set_bypass(std::shared_ptr<double> value) { this->bypass = value; }

        std::shared_ptr<double> get_chorus_cutoff() const { return chorus_cutoff; }
        void set_chorus_cutoff(std::shared_ptr<double> value) { this->chorus_cutoff = value; }

        std::shared_ptr<double> get_chorus_damping() const { return chorus_damping; }
        void set_chorus_damping(std::shared_ptr<double> value) { this->chorus_damping = value; }

        const double & get_chorus_delay_1() const { return chorus_delay_1; }
        double & get_mutable_chorus_delay_1() { return chorus_delay_1; }
        void set_chorus_delay_1(const double & value) { this->chorus_delay_1 = value; }

        const double & get_chorus_delay_2() const { return chorus_delay_2; }
        double & get_mutable_chorus_delay_2() { return chorus_delay_2; }
        void set_chorus_delay_2(const double & value) { this->chorus_delay_2 = value; }

        const double & get_chorus_dry_wet() const { return chorus_dry_wet; }
        double & get_mutable_chorus_dry_wet() { return chorus_dry_wet; }
        void set_chorus_dry_wet(const double & value) { this->chorus_dry_wet = value; }

        const double & get_chorus_feedback() const { return chorus_feedback; }
        double & get_mutable_chorus_feedback() { return chorus_feedback; }
        void set_chorus_feedback(const double & value) { this->chorus_feedback = value; }

        const double & get_chorus_frequency() const { return chorus_frequency; }
        double & get_mutable_chorus_frequency() { return chorus_frequency; }
        void set_chorus_frequency(const double & value) { this->chorus_frequency = value; }

        const double & get_chorus_mod_depth() const { return chorus_mod_depth; }
        double & get_mutable_chorus_mod_depth() { return chorus_mod_depth; }
        void set_chorus_mod_depth(const double & value) { this->chorus_mod_depth = value; }

        const double & get_chorus_on() const { return chorus_on; }
        double & get_mutable_chorus_on() { return chorus_on; }
        void set_chorus_on(const double & value) { this->chorus_on = value; }

        std::shared_ptr<double> get_chorus_spread() const { return chorus_spread; }
        void set_chorus_spread(std::shared_ptr<double> value) { this->chorus_spread = value; }

        const double & get_chorus_sync() const { return chorus_sync; }
        double & get_mutable_chorus_sync() { return chorus_sync; }
        void set_chorus_sync(const double & value) { this->chorus_sync = value; }

        const double & get_chorus_tempo() const { return chorus_tempo; }
        double & get_mutable_chorus_tempo() { return chorus_tempo; }
        void set_chorus_tempo(const double & value) { this->chorus_tempo = value; }

        const double & get_chorus_voices() const { return chorus_voices; }
        double & get_mutable_chorus_voices() { return chorus_voices; }
        void set_chorus_voices(const double & value) { this->chorus_voices = value; }

        const double & get_compressor_attack() const { return compressor_attack; }
        double & get_mutable_compressor_attack() { return compressor_attack; }
        void set_compressor_attack(const double & value) { this->compressor_attack = value; }

        const double & get_compressor_band_gain() const { return compressor_band_gain; }
        double & get_mutable_compressor_band_gain() { return compressor_band_gain; }
        void set_compressor_band_gain(const double & value) { this->compressor_band_gain = value; }

        const double & get_compressor_band_lower_ratio() const { return compressor_band_lower_ratio; }
        double & get_mutable_compressor_band_lower_ratio() { return compressor_band_lower_ratio; }
        void set_compressor_band_lower_ratio(const double & value) { this->compressor_band_lower_ratio = value; }

        const double & get_compressor_band_lower_threshold() const { return compressor_band_lower_threshold; }
        double & get_mutable_compressor_band_lower_threshold() { return compressor_band_lower_threshold; }
        void set_compressor_band_lower_threshold(const double & value) { this->compressor_band_lower_threshold = value; }

        const double & get_compressor_band_upper_ratio() const { return compressor_band_upper_ratio; }
        double & get_mutable_compressor_band_upper_ratio() { return compressor_band_upper_ratio; }
        void set_compressor_band_upper_ratio(const double & value) { this->compressor_band_upper_ratio = value; }

        const double & get_compressor_band_upper_threshold() const { return compressor_band_upper_threshold; }
        double & get_mutable_compressor_band_upper_threshold() { return compressor_band_upper_threshold; }
        void set_compressor_band_upper_threshold(const double & value) { this->compressor_band_upper_threshold = value; }

        const double & get_compressor_enabled_bands() const { return compressor_enabled_bands; }
        double & get_mutable_compressor_enabled_bands() { return compressor_enabled_bands; }
        void set_compressor_enabled_bands(const double & value) { this->compressor_enabled_bands = value; }

        const double & get_compressor_high_gain() const { return compressor_high_gain; }
        double & get_mutable_compressor_high_gain() { return compressor_high_gain; }
        void set_compressor_high_gain(const double & value) { this->compressor_high_gain = value; }

        const double & get_compressor_high_lower_ratio() const { return compressor_high_lower_ratio; }
        double & get_mutable_compressor_high_lower_ratio() { return compressor_high_lower_ratio; }
        void set_compressor_high_lower_ratio(const double & value) { this->compressor_high_lower_ratio = value; }

        const double & get_compressor_high_lower_threshold() const { return compressor_high_lower_threshold; }
        double & get_mutable_compressor_high_lower_threshold() { return compressor_high_lower_threshold; }
        void set_compressor_high_lower_threshold(const double & value) { this->compressor_high_lower_threshold = value; }

        const double & get_compressor_high_upper_ratio() const { return compressor_high_upper_ratio; }
        double & get_mutable_compressor_high_upper_ratio() { return compressor_high_upper_ratio; }
        void set_compressor_high_upper_ratio(const double & value) { this->compressor_high_upper_ratio = value; }

        const double & get_compressor_high_upper_threshold() const { return compressor_high_upper_threshold; }
        double & get_mutable_compressor_high_upper_threshold() { return compressor_high_upper_threshold; }
        void set_compressor_high_upper_threshold(const double & value) { this->compressor_high_upper_threshold = value; }

        const double & get_compressor_low_gain() const { return compressor_low_gain; }
        double & get_mutable_compressor_low_gain() { return compressor_low_gain; }
        void set_compressor_low_gain(const double & value) { this->compressor_low_gain = value; }

        const double & get_compressor_low_lower_ratio() const { return compressor_low_lower_ratio; }
        double & get_mutable_compressor_low_lower_ratio() { return compressor_low_lower_ratio; }
        void set_compressor_low_lower_ratio(const double & value) { this->compressor_low_lower_ratio = value; }

        const double & get_compressor_low_lower_threshold() const { return compressor_low_lower_threshold; }
        double & get_mutable_compressor_low_lower_threshold() { return compressor_low_lower_threshold; }
        void set_compressor_low_lower_threshold(const double & value) { this->compressor_low_lower_threshold = value; }

        const double & get_compressor_low_upper_ratio() const { return compressor_low_upper_ratio; }
        double & get_mutable_compressor_low_upper_ratio() { return compressor_low_upper_ratio; }
        void set_compressor_low_upper_ratio(const double & value) { this->compressor_low_upper_ratio = value; }

        const double & get_compressor_low_upper_threshold() const { return compressor_low_upper_threshold; }
        double & get_mutable_compressor_low_upper_threshold() { return compressor_low_upper_threshold; }
        void set_compressor_low_upper_threshold(const double & value) { this->compressor_low_upper_threshold = value; }

        std::shared_ptr<double> get_compressor_mix() const { return compressor_mix; }
        void set_compressor_mix(std::shared_ptr<double> value) { this->compressor_mix = value; }

        const double & get_compressor_on() const { return compressor_on; }
        double & get_mutable_compressor_on() { return compressor_on; }
        void set_compressor_on(const double & value) { this->compressor_on = value; }

        const double & get_compressor_release() const { return compressor_release; }
        double & get_mutable_compressor_release() { return compressor_release; }
        void set_compressor_release(const double & value) { this->compressor_release = value; }

        const double & get_delay_aux_frequency() const { return delay_aux_frequency; }
        double & get_mutable_delay_aux_frequency() { return delay_aux_frequency; }
        void set_delay_aux_frequency(const double & value) { this->delay_aux_frequency = value; }

        const double & get_delay_aux_sync() const { return delay_aux_sync; }
        double & get_mutable_delay_aux_sync() { return delay_aux_sync; }
        void set_delay_aux_sync(const double & value) { this->delay_aux_sync = value; }

        const double & get_delay_aux_tempo() const { return delay_aux_tempo; }
        double & get_mutable_delay_aux_tempo() { return delay_aux_tempo; }
        void set_delay_aux_tempo(const double & value) { this->delay_aux_tempo = value; }

        const double & get_delay_dry_wet() const { return delay_dry_wet; }
        double & get_mutable_delay_dry_wet() { return delay_dry_wet; }
        void set_delay_dry_wet(const double & value) { this->delay_dry_wet = value; }

        const double & get_delay_feedback() const { return delay_feedback; }
        double & get_mutable_delay_feedback() { return delay_feedback; }
        void set_delay_feedback(const double & value) { this->delay_feedback = value; }

        const double & get_delay_filter_cutoff() const { return delay_filter_cutoff; }
        double & get_mutable_delay_filter_cutoff() { return delay_filter_cutoff; }
        void set_delay_filter_cutoff(const double & value) { this->delay_filter_cutoff = value; }

        const double & get_delay_filter_spread() const { return delay_filter_spread; }
        double & get_mutable_delay_filter_spread() { return delay_filter_spread; }
        void set_delay_filter_spread(const double & value) { this->delay_filter_spread = value; }

        const double & get_delay_frequency() const { return delay_frequency; }
        double & get_mutable_delay_frequency() { return delay_frequency; }
        void set_delay_frequency(const double & value) { this->delay_frequency = value; }

        const double & get_delay_on() const { return delay_on; }
        double & get_mutable_delay_on() { return delay_on; }
        void set_delay_on(const double & value) { this->delay_on = value; }

        const double & get_delay_style() const { return delay_style; }
        double & get_mutable_delay_style() { return delay_style; }
        void set_delay_style(const double & value) { this->delay_style = value; }

        const double & get_delay_sync() const { return delay_sync; }
        double & get_mutable_delay_sync() { return delay_sync; }
        void set_delay_sync(const double & value) { this->delay_sync = value; }

        const double & get_delay_tempo() const { return delay_tempo; }
        double & get_mutable_delay_tempo() { return delay_tempo; }
        void set_delay_tempo(const double & value) { this->delay_tempo = value; }

        const double & get_distortion_drive() const { return distortion_drive; }
        double & get_mutable_distortion_drive() { return distortion_drive; }
        void set_distortion_drive(const double & value) { this->distortion_drive = value; }

        const double & get_distortion_filter_blend() const { return distortion_filter_blend; }
        double & get_mutable_distortion_filter_blend() { return distortion_filter_blend; }
        void set_distortion_filter_blend(const double & value) { this->distortion_filter_blend = value; }

        const double & get_distortion_filter_cutoff() const { return distortion_filter_cutoff; }
        double & get_mutable_distortion_filter_cutoff() { return distortion_filter_cutoff; }
        void set_distortion_filter_cutoff(const double & value) { this->distortion_filter_cutoff = value; }

        const double & get_distortion_filter_order() const { return distortion_filter_order; }
        double & get_mutable_distortion_filter_order() { return distortion_filter_order; }
        void set_distortion_filter_order(const double & value) { this->distortion_filter_order = value; }

        const double & get_distortion_filter_resonance() const { return distortion_filter_resonance; }
        double & get_mutable_distortion_filter_resonance() { return distortion_filter_resonance; }
        void set_distortion_filter_resonance(const double & value) { this->distortion_filter_resonance = value; }

        const double & get_distortion_mix() const { return distortion_mix; }
        double & get_mutable_distortion_mix() { return distortion_mix; }
        void set_distortion_mix(const double & value) { this->distortion_mix = value; }

        const double & get_distortion_on() const { return distortion_on; }
        double & get_mutable_distortion_on() { return distortion_on; }
        void set_distortion_on(const double & value) { this->distortion_on = value; }

        const double & get_distortion_type() const { return distortion_type; }
        double & get_mutable_distortion_type() { return distortion_type; }
        void set_distortion_type(const double & value) { this->distortion_type = value; }

        const double & get_effect_chain_order() const { return effect_chain_order; }
        double & get_mutable_effect_chain_order() { return effect_chain_order; }
        void set_effect_chain_order(const double & value) { this->effect_chain_order = value; }

        const double & get_env_1___attack() const { return env_1__attack; }
        double & get_mutable_env_1___attack() { return env_1__attack; }
        void set_env_1___attack(const double & value) { this->env_1__attack = value; }

        const double & get_env_1___attack_power() const { return env_1__attack_power; }
        double & get_mutable_env_1___attack_power() { return env_1__attack_power; }
        void set_env_1___attack_power(const double & value) { this->env_1__attack_power = value; }

        const double & get_env_1___decay() const { return env_1__decay; }
        double & get_mutable_env_1___decay() { return env_1__decay; }
        void set_env_1___decay(const double & value) { this->env_1__decay = value; }

        const double & get_env_1___decay_power() const { return env_1__decay_power; }
        double & get_mutable_env_1___decay_power() { return env_1__decay_power; }
        void set_env_1___decay_power(const double & value) { this->env_1__decay_power = value; }

        const double & get_env_1___delay() const { return env_1__delay; }
        double & get_mutable_env_1___delay() { return env_1__delay; }
        void set_env_1___delay(const double & value) { this->env_1__delay = value; }

        const double & get_env_1___hold() const { return env_1__hold; }
        double & get_mutable_env_1___hold() { return env_1__hold; }
        void set_env_1___hold(const double & value) { this->env_1__hold = value; }

        const double & get_env_1___release() const { return env_1__release; }
        double & get_mutable_env_1___release() { return env_1__release; }
        void set_env_1___release(const double & value) { this->env_1__release = value; }

        const double & get_env_1___release_power() const { return env_1__release_power; }
        double & get_mutable_env_1___release_power() { return env_1__release_power; }
        void set_env_1___release_power(const double & value) { this->env_1__release_power = value; }

        const double & get_env_1___sustain() const { return env_1__sustain; }
        double & get_mutable_env_1___sustain() { return env_1__sustain; }
        void set_env_1___sustain(const double & value) { this->env_1__sustain = value; }

        const double & get_env_2___attack() const { return env_2__attack; }
        double & get_mutable_env_2___attack() { return env_2__attack; }
        void set_env_2___attack(const double & value) { this->env_2__attack = value; }

        const double & get_env_2___attack_power() const { return env_2__attack_power; }
        double & get_mutable_env_2___attack_power() { return env_2__attack_power; }
        void set_env_2___attack_power(const double & value) { this->env_2__attack_power = value; }

        const double & get_env_2___decay() const { return env_2__decay; }
        double & get_mutable_env_2___decay() { return env_2__decay; }
        void set_env_2___decay(const double & value) { this->env_2__decay = value; }

        const double & get_env_2___decay_power() const { return env_2__decay_power; }
        double & get_mutable_env_2___decay_power() { return env_2__decay_power; }
        void set_env_2___decay_power(const double & value) { this->env_2__decay_power = value; }

        const double & get_env_2___delay() const { return env_2__delay; }
        double & get_mutable_env_2___delay() { return env_2__delay; }
        void set_env_2___delay(const double & value) { this->env_2__delay = value; }

        const double & get_env_2___hold() const { return env_2__hold; }
        double & get_mutable_env_2___hold() { return env_2__hold; }
        void set_env_2___hold(const double & value) { this->env_2__hold = value; }

        const double & get_env_2___release() const { return env_2__release; }
        double & get_mutable_env_2___release() { return env_2__release; }
        void set_env_2___release(const double & value) { this->env_2__release = value; }

        const double & get_env_2___release_power() const { return env_2__release_power; }
        double & get_mutable_env_2___release_power() { return env_2__release_power; }
        void set_env_2___release_power(const double & value) { this->env_2__release_power = value; }

        const double & get_env_2___sustain() const { return env_2__sustain; }
        double & get_mutable_env_2___sustain() { return env_2__sustain; }
        void set_env_2___sustain(const double & value) { this->env_2__sustain = value; }

        const double & get_env_3___attack() const { return env_3__attack; }
        double & get_mutable_env_3___attack() { return env_3__attack; }
        void set_env_3___attack(const double & value) { this->env_3__attack = value; }

        const double & get_env_3___attack_power() const { return env_3__attack_power; }
        double & get_mutable_env_3___attack_power() { return env_3__attack_power; }
        void set_env_3___attack_power(const double & value) { this->env_3__attack_power = value; }

        const double & get_env_3___decay() const { return env_3__decay; }
        double & get_mutable_env_3___decay() { return env_3__decay; }
        void set_env_3___decay(const double & value) { this->env_3__decay = value; }

        const double & get_env_3___decay_power() const { return env_3__decay_power; }
        double & get_mutable_env_3___decay_power() { return env_3__decay_power; }
        void set_env_3___decay_power(const double & value) { this->env_3__decay_power = value; }

        const double & get_env_3___delay() const { return env_3__delay; }
        double & get_mutable_env_3___delay() { return env_3__delay; }
        void set_env_3___delay(const double & value) { this->env_3__delay = value; }

        const double & get_env_3___hold() const { return env_3__hold; }
        double & get_mutable_env_3___hold() { return env_3__hold; }
        void set_env_3___hold(const double & value) { this->env_3__hold = value; }

        const double & get_env_3___release() const { return env_3__release; }
        double & get_mutable_env_3___release() { return env_3__release; }
        void set_env_3___release(const double & value) { this->env_3__release = value; }

        const double & get_env_3___release_power() const { return env_3__release_power; }
        double & get_mutable_env_3___release_power() { return env_3__release_power; }
        void set_env_3___release_power(const double & value) { this->env_3__release_power = value; }

        const double & get_env_3___sustain() const { return env_3__sustain; }
        double & get_mutable_env_3___sustain() { return env_3__sustain; }
        void set_env_3___sustain(const double & value) { this->env_3__sustain = value; }

        const double & get_env_4___attack() const { return env_4__attack; }
        double & get_mutable_env_4___attack() { return env_4__attack; }
        void set_env_4___attack(const double & value) { this->env_4__attack = value; }

        const double & get_env_4___attack_power() const { return env_4__attack_power; }
        double & get_mutable_env_4___attack_power() { return env_4__attack_power; }
        void set_env_4___attack_power(const double & value) { this->env_4__attack_power = value; }

        const double & get_env_4___decay() const { return env_4__decay; }
        double & get_mutable_env_4___decay() { return env_4__decay; }
        void set_env_4___decay(const double & value) { this->env_4__decay = value; }

        const double & get_env_4___decay_power() const { return env_4__decay_power; }
        double & get_mutable_env_4___decay_power() { return env_4__decay_power; }
        void set_env_4___decay_power(const double & value) { this->env_4__decay_power = value; }

        const double & get_env_4___delay() const { return env_4__delay; }
        double & get_mutable_env_4___delay() { return env_4__delay; }
        void set_env_4___delay(const double & value) { this->env_4__delay = value; }

        const double & get_env_4___hold() const { return env_4__hold; }
        double & get_mutable_env_4___hold() { return env_4__hold; }
        void set_env_4___hold(const double & value) { this->env_4__hold = value; }

        const double & get_env_4___release() const { return env_4__release; }
        double & get_mutable_env_4___release() { return env_4__release; }
        void set_env_4___release(const double & value) { this->env_4__release = value; }

        const double & get_env_4___release_power() const { return env_4__release_power; }
        double & get_mutable_env_4___release_power() { return env_4__release_power; }
        void set_env_4___release_power(const double & value) { this->env_4__release_power = value; }

        const double & get_env_4___sustain() const { return env_4__sustain; }
        double & get_mutable_env_4___sustain() { return env_4__sustain; }
        void set_env_4___sustain(const double & value) { this->env_4__sustain = value; }

        const double & get_env_5___attack() const { return env_5__attack; }
        double & get_mutable_env_5___attack() { return env_5__attack; }
        void set_env_5___attack(const double & value) { this->env_5__attack = value; }

        const double & get_env_5___attack_power() const { return env_5__attack_power; }
        double & get_mutable_env_5___attack_power() { return env_5__attack_power; }
        void set_env_5___attack_power(const double & value) { this->env_5__attack_power = value; }

        const double & get_env_5___decay() const { return env_5__decay; }
        double & get_mutable_env_5___decay() { return env_5__decay; }
        void set_env_5___decay(const double & value) { this->env_5__decay = value; }

        const double & get_env_5___decay_power() const { return env_5__decay_power; }
        double & get_mutable_env_5___decay_power() { return env_5__decay_power; }
        void set_env_5___decay_power(const double & value) { this->env_5__decay_power = value; }

        const double & get_env_5___delay() const { return env_5__delay; }
        double & get_mutable_env_5___delay() { return env_5__delay; }
        void set_env_5___delay(const double & value) { this->env_5__delay = value; }

        const double & get_env_5___hold() const { return env_5__hold; }
        double & get_mutable_env_5___hold() { return env_5__hold; }
        void set_env_5___hold(const double & value) { this->env_5__hold = value; }

        const double & get_env_5___release() const { return env_5__release; }
        double & get_mutable_env_5___release() { return env_5__release; }
        void set_env_5___release(const double & value) { this->env_5__release = value; }

        const double & get_env_5___release_power() const { return env_5__release_power; }
        double & get_mutable_env_5___release_power() { return env_5__release_power; }
        void set_env_5___release_power(const double & value) { this->env_5__release_power = value; }

        const double & get_env_5___sustain() const { return env_5__sustain; }
        double & get_mutable_env_5___sustain() { return env_5__sustain; }
        void set_env_5___sustain(const double & value) { this->env_5__sustain = value; }

        const double & get_env_6___attack() const { return env_6__attack; }
        double & get_mutable_env_6___attack() { return env_6__attack; }
        void set_env_6___attack(const double & value) { this->env_6__attack = value; }

        const double & get_env_6___attack_power() const { return env_6__attack_power; }
        double & get_mutable_env_6___attack_power() { return env_6__attack_power; }
        void set_env_6___attack_power(const double & value) { this->env_6__attack_power = value; }

        const double & get_env_6___decay() const { return env_6__decay; }
        double & get_mutable_env_6___decay() { return env_6__decay; }
        void set_env_6___decay(const double & value) { this->env_6__decay = value; }

        const double & get_env_6___decay_power() const { return env_6__decay_power; }
        double & get_mutable_env_6___decay_power() { return env_6__decay_power; }
        void set_env_6___decay_power(const double & value) { this->env_6__decay_power = value; }

        const double & get_env_6___delay() const { return env_6__delay; }
        double & get_mutable_env_6___delay() { return env_6__delay; }
        void set_env_6___delay(const double & value) { this->env_6__delay = value; }

        const double & get_env_6___hold() const { return env_6__hold; }
        double & get_mutable_env_6___hold() { return env_6__hold; }
        void set_env_6___hold(const double & value) { this->env_6__hold = value; }

        const double & get_env_6___release() const { return env_6__release; }
        double & get_mutable_env_6___release() { return env_6__release; }
        void set_env_6___release(const double & value) { this->env_6__release = value; }

        const double & get_env_6___release_power() const { return env_6__release_power; }
        double & get_mutable_env_6___release_power() { return env_6__release_power; }
        void set_env_6___release_power(const double & value) { this->env_6__release_power = value; }

        const double & get_env_6___sustain() const { return env_6__sustain; }
        double & get_mutable_env_6___sustain() { return env_6__sustain; }
        void set_env_6___sustain(const double & value) { this->env_6__sustain = value; }

        const double & get_eq_band_cutoff() const { return eq_band_cutoff; }
        double & get_mutable_eq_band_cutoff() { return eq_band_cutoff; }
        void set_eq_band_cutoff(const double & value) { this->eq_band_cutoff = value; }

        const double & get_eq_band_gain() const { return eq_band_gain; }
        double & get_mutable_eq_band_gain() { return eq_band_gain; }
        void set_eq_band_gain(const double & value) { this->eq_band_gain = value; }

        const double & get_eq_band_mode() const { return eq_band_mode; }
        double & get_mutable_eq_band_mode() { return eq_band_mode; }
        void set_eq_band_mode(const double & value) { this->eq_band_mode = value; }

        const double & get_eq_band_resonance() const { return eq_band_resonance; }
        double & get_mutable_eq_band_resonance() { return eq_band_resonance; }
        void set_eq_band_resonance(const double & value) { this->eq_band_resonance = value; }

        const double & get_eq_high_cutoff() const { return eq_high_cutoff; }
        double & get_mutable_eq_high_cutoff() { return eq_high_cutoff; }
        void set_eq_high_cutoff(const double & value) { this->eq_high_cutoff = value; }

        const double & get_eq_high_gain() const { return eq_high_gain; }
        double & get_mutable_eq_high_gain() { return eq_high_gain; }
        void set_eq_high_gain(const double & value) { this->eq_high_gain = value; }

        const double & get_eq_high_mode() const { return eq_high_mode; }
        double & get_mutable_eq_high_mode() { return eq_high_mode; }
        void set_eq_high_mode(const double & value) { this->eq_high_mode = value; }

        const double & get_eq_high_resonance() const { return eq_high_resonance; }
        double & get_mutable_eq_high_resonance() { return eq_high_resonance; }
        void set_eq_high_resonance(const double & value) { this->eq_high_resonance = value; }

        const double & get_eq_low_cutoff() const { return eq_low_cutoff; }
        double & get_mutable_eq_low_cutoff() { return eq_low_cutoff; }
        void set_eq_low_cutoff(const double & value) { this->eq_low_cutoff = value; }

        const double & get_eq_low_gain() const { return eq_low_gain; }
        double & get_mutable_eq_low_gain() { return eq_low_gain; }
        void set_eq_low_gain(const double & value) { this->eq_low_gain = value; }

        const double & get_eq_low_mode() const { return eq_low_mode; }
        double & get_mutable_eq_low_mode() { return eq_low_mode; }
        void set_eq_low_mode(const double & value) { this->eq_low_mode = value; }

        const double & get_eq_low_resonance() const { return eq_low_resonance; }
        double & get_mutable_eq_low_resonance() { return eq_low_resonance; }
        void set_eq_low_resonance(const double & value) { this->eq_low_resonance = value; }

        const double & get_eq_on() const { return eq_on; }
        double & get_mutable_eq_on() { return eq_on; }
        void set_eq_on(const double & value) { this->eq_on = value; }

        const double & get_filter_1___blend() const { return filter_1__blend; }
        double & get_mutable_filter_1___blend() { return filter_1__blend; }
        void set_filter_1___blend(const double & value) { this->filter_1__blend = value; }

        const double & get_filter_1___blend_transpose() const { return filter_1__blend_transpose; }
        double & get_mutable_filter_1___blend_transpose() { return filter_1__blend_transpose; }
        void set_filter_1___blend_transpose(const double & value) { this->filter_1__blend_transpose = value; }

        const double & get_filter_1___cutoff() const { return filter_1__cutoff; }
        double & get_mutable_filter_1___cutoff() { return filter_1__cutoff; }
        void set_filter_1___cutoff(const double & value) { this->filter_1__cutoff = value; }

        const double & get_filter_1___drive() const { return filter_1__drive; }
        double & get_mutable_filter_1___drive() { return filter_1__drive; }
        void set_filter_1___drive(const double & value) { this->filter_1__drive = value; }

        const double & get_filter_1___filter_input() const { return filter_1__filter_input; }
        double & get_mutable_filter_1___filter_input() { return filter_1__filter_input; }
        void set_filter_1___filter_input(const double & value) { this->filter_1__filter_input = value; }

        const double & get_filter_1___formant_resonance() const { return filter_1__formant_resonance; }
        double & get_mutable_filter_1___formant_resonance() { return filter_1__formant_resonance; }
        void set_filter_1___formant_resonance(const double & value) { this->filter_1__formant_resonance = value; }

        std::shared_ptr<double> get_filter_1___formant_spread() const { return filter_1__formant_spread; }
        void set_filter_1___formant_spread(std::shared_ptr<double> value) { this->filter_1__formant_spread = value; }

        const double & get_filter_1___formant_transpose() const { return filter_1__formant_transpose; }
        double & get_mutable_filter_1___formant_transpose() { return filter_1__formant_transpose; }
        void set_filter_1___formant_transpose(const double & value) { this->filter_1__formant_transpose = value; }

        const double & get_filter_1___formant_x() const { return filter_1__formant_x; }
        double & get_mutable_filter_1___formant_x() { return filter_1__formant_x; }
        void set_filter_1___formant_x(const double & value) { this->filter_1__formant_x = value; }

        const double & get_filter_1___formant_y() const { return filter_1__formant_y; }
        double & get_mutable_filter_1___formant_y() { return filter_1__formant_y; }
        void set_filter_1___formant_y(const double & value) { this->filter_1__formant_y = value; }

        const double & get_filter_1___keytrack() const { return filter_1__keytrack; }
        double & get_mutable_filter_1___keytrack() { return filter_1__keytrack; }
        void set_filter_1___keytrack(const double & value) { this->filter_1__keytrack = value; }

        const double & get_filter_1___mix() const { return filter_1__mix; }
        double & get_mutable_filter_1___mix() { return filter_1__mix; }
        void set_filter_1___mix(const double & value) { this->filter_1__mix = value; }

        const double & get_filter_1___model() const { return filter_1__model; }
        double & get_mutable_filter_1___model() { return filter_1__model; }
        void set_filter_1___model(const double & value) { this->filter_1__model = value; }

        const double & get_filter_1___on() const { return filter_1__on; }
        double & get_mutable_filter_1___on() { return filter_1__on; }
        void set_filter_1___on(const double & value) { this->filter_1__on = value; }

        const double & get_filter_1___resonance() const { return filter_1__resonance; }
        double & get_mutable_filter_1___resonance() { return filter_1__resonance; }
        void set_filter_1___resonance(const double & value) { this->filter_1__resonance = value; }

        const double & get_filter_1___style() const { return filter_1__style; }
        double & get_mutable_filter_1___style() { return filter_1__style; }
        void set_filter_1___style(const double & value) { this->filter_1__style = value; }

        const double & get_filter_2___blend() const { return filter_2__blend; }
        double & get_mutable_filter_2___blend() { return filter_2__blend; }
        void set_filter_2___blend(const double & value) { this->filter_2__blend = value; }

        const double & get_filter_2___blend_transpose() const { return filter_2__blend_transpose; }
        double & get_mutable_filter_2___blend_transpose() { return filter_2__blend_transpose; }
        void set_filter_2___blend_transpose(const double & value) { this->filter_2__blend_transpose = value; }

        const double & get_filter_2___cutoff() const { return filter_2__cutoff; }
        double & get_mutable_filter_2___cutoff() { return filter_2__cutoff; }
        void set_filter_2___cutoff(const double & value) { this->filter_2__cutoff = value; }

        const double & get_filter_2___drive() const { return filter_2__drive; }
        double & get_mutable_filter_2___drive() { return filter_2__drive; }
        void set_filter_2___drive(const double & value) { this->filter_2__drive = value; }

        const double & get_filter_2___filter_input() const { return filter_2__filter_input; }
        double & get_mutable_filter_2___filter_input() { return filter_2__filter_input; }
        void set_filter_2___filter_input(const double & value) { this->filter_2__filter_input = value; }

        const double & get_filter_2___formant_resonance() const { return filter_2__formant_resonance; }
        double & get_mutable_filter_2___formant_resonance() { return filter_2__formant_resonance; }
        void set_filter_2___formant_resonance(const double & value) { this->filter_2__formant_resonance = value; }

        std::shared_ptr<double> get_filter_2___formant_spread() const { return filter_2__formant_spread; }
        void set_filter_2___formant_spread(std::shared_ptr<double> value) { this->filter_2__formant_spread = value; }

        const double & get_filter_2___formant_transpose() const { return filter_2__formant_transpose; }
        double & get_mutable_filter_2___formant_transpose() { return filter_2__formant_transpose; }
        void set_filter_2___formant_transpose(const double & value) { this->filter_2__formant_transpose = value; }

        const double & get_filter_2___formant_x() const { return filter_2__formant_x; }
        double & get_mutable_filter_2___formant_x() { return filter_2__formant_x; }
        void set_filter_2___formant_x(const double & value) { this->filter_2__formant_x = value; }

        const double & get_filter_2___formant_y() const { return filter_2__formant_y; }
        double & get_mutable_filter_2___formant_y() { return filter_2__formant_y; }
        void set_filter_2___formant_y(const double & value) { this->filter_2__formant_y = value; }

        const double & get_filter_2___keytrack() const { return filter_2__keytrack; }
        double & get_mutable_filter_2___keytrack() { return filter_2__keytrack; }
        void set_filter_2___keytrack(const double & value) { this->filter_2__keytrack = value; }

        const double & get_filter_2___mix() const { return filter_2__mix; }
        double & get_mutable_filter_2___mix() { return filter_2__mix; }
        void set_filter_2___mix(const double & value) { this->filter_2__mix = value; }

        const double & get_filter_2___model() const { return filter_2__model; }
        double & get_mutable_filter_2___model() { return filter_2__model; }
        void set_filter_2___model(const double & value) { this->filter_2__model = value; }

        const double & get_filter_2___on() const { return filter_2__on; }
        double & get_mutable_filter_2___on() { return filter_2__on; }
        void set_filter_2___on(const double & value) { this->filter_2__on = value; }

        const double & get_filter_2___resonance() const { return filter_2__resonance; }
        double & get_mutable_filter_2___resonance() { return filter_2__resonance; }
        void set_filter_2___resonance(const double & value) { this->filter_2__resonance = value; }

        const double & get_filter_2___style() const { return filter_2__style; }
        double & get_mutable_filter_2___style() { return filter_2__style; }
        void set_filter_2___style(const double & value) { this->filter_2__style = value; }

        const double & get_filter_fx_blend() const { return filter_fx_blend; }
        double & get_mutable_filter_fx_blend() { return filter_fx_blend; }
        void set_filter_fx_blend(const double & value) { this->filter_fx_blend = value; }

        const double & get_filter_fx_blend_transpose() const { return filter_fx_blend_transpose; }
        double & get_mutable_filter_fx_blend_transpose() { return filter_fx_blend_transpose; }
        void set_filter_fx_blend_transpose(const double & value) { this->filter_fx_blend_transpose = value; }

        const double & get_filter_fx_cutoff() const { return filter_fx_cutoff; }
        double & get_mutable_filter_fx_cutoff() { return filter_fx_cutoff; }
        void set_filter_fx_cutoff(const double & value) { this->filter_fx_cutoff = value; }

        const double & get_filter_fx_drive() const { return filter_fx_drive; }
        double & get_mutable_filter_fx_drive() { return filter_fx_drive; }
        void set_filter_fx_drive(const double & value) { this->filter_fx_drive = value; }

        const double & get_filter_fx_formant_resonance() const { return filter_fx_formant_resonance; }
        double & get_mutable_filter_fx_formant_resonance() { return filter_fx_formant_resonance; }
        void set_filter_fx_formant_resonance(const double & value) { this->filter_fx_formant_resonance = value; }

        std::shared_ptr<double> get_filter_fx_formant_spread() const { return filter_fx_formant_spread; }
        void set_filter_fx_formant_spread(std::shared_ptr<double> value) { this->filter_fx_formant_spread = value; }

        const double & get_filter_fx_formant_transpose() const { return filter_fx_formant_transpose; }
        double & get_mutable_filter_fx_formant_transpose() { return filter_fx_formant_transpose; }
        void set_filter_fx_formant_transpose(const double & value) { this->filter_fx_formant_transpose = value; }

        const double & get_filter_fx_formant_x() const { return filter_fx_formant_x; }
        double & get_mutable_filter_fx_formant_x() { return filter_fx_formant_x; }
        void set_filter_fx_formant_x(const double & value) { this->filter_fx_formant_x = value; }

        const double & get_filter_fx_formant_y() const { return filter_fx_formant_y; }
        double & get_mutable_filter_fx_formant_y() { return filter_fx_formant_y; }
        void set_filter_fx_formant_y(const double & value) { this->filter_fx_formant_y = value; }

        const double & get_filter_fx_keytrack() const { return filter_fx_keytrack; }
        double & get_mutable_filter_fx_keytrack() { return filter_fx_keytrack; }
        void set_filter_fx_keytrack(const double & value) { this->filter_fx_keytrack = value; }

        const double & get_filter_fx_mix() const { return filter_fx_mix; }
        double & get_mutable_filter_fx_mix() { return filter_fx_mix; }
        void set_filter_fx_mix(const double & value) { this->filter_fx_mix = value; }

        const double & get_filter_fx_model() const { return filter_fx_model; }
        double & get_mutable_filter_fx_model() { return filter_fx_model; }
        void set_filter_fx_model(const double & value) { this->filter_fx_model = value; }

        const double & get_filter_fx_on() const { return filter_fx_on; }
        double & get_mutable_filter_fx_on() { return filter_fx_on; }
        void set_filter_fx_on(const double & value) { this->filter_fx_on = value; }

        const double & get_filter_fx_resonance() const { return filter_fx_resonance; }
        double & get_mutable_filter_fx_resonance() { return filter_fx_resonance; }
        void set_filter_fx_resonance(const double & value) { this->filter_fx_resonance = value; }

        const double & get_filter_fx_style() const { return filter_fx_style; }
        double & get_mutable_filter_fx_style() { return filter_fx_style; }
        void set_filter_fx_style(const double & value) { this->filter_fx_style = value; }

        const double & get_flanger_center() const { return flanger_center; }
        double & get_mutable_flanger_center() { return flanger_center; }
        void set_flanger_center(const double & value) { this->flanger_center = value; }

        const double & get_flanger_dry_wet() const { return flanger_dry_wet; }
        double & get_mutable_flanger_dry_wet() { return flanger_dry_wet; }
        void set_flanger_dry_wet(const double & value) { this->flanger_dry_wet = value; }

        const double & get_flanger_feedback() const { return flanger_feedback; }
        double & get_mutable_flanger_feedback() { return flanger_feedback; }
        void set_flanger_feedback(const double & value) { this->flanger_feedback = value; }

        const double & get_flanger_frequency() const { return flanger_frequency; }
        double & get_mutable_flanger_frequency() { return flanger_frequency; }
        void set_flanger_frequency(const double & value) { this->flanger_frequency = value; }

        const double & get_flanger_mod_depth() const { return flanger_mod_depth; }
        double & get_mutable_flanger_mod_depth() { return flanger_mod_depth; }
        void set_flanger_mod_depth(const double & value) { this->flanger_mod_depth = value; }

        const double & get_flanger_on() const { return flanger_on; }
        double & get_mutable_flanger_on() { return flanger_on; }
        void set_flanger_on(const double & value) { this->flanger_on = value; }

        const double & get_flanger_phase_offset() const { return flanger_phase_offset; }
        double & get_mutable_flanger_phase_offset() { return flanger_phase_offset; }
        void set_flanger_phase_offset(const double & value) { this->flanger_phase_offset = value; }

        const double & get_flanger_sync() const { return flanger_sync; }
        double & get_mutable_flanger_sync() { return flanger_sync; }
        void set_flanger_sync(const double & value) { this->flanger_sync = value; }

        const double & get_flanger_tempo() const { return flanger_tempo; }
        double & get_mutable_flanger_tempo() { return flanger_tempo; }
        void set_flanger_tempo(const double & value) { this->flanger_tempo = value; }

        const double & get_legato() const { return legato; }
        double & get_mutable_legato() { return legato; }
        void set_legato(const double & value) { this->legato = value; }

        const double & get_lfo_1___delay_time() const { return lfo_1__delay_time; }
        double & get_mutable_lfo_1___delay_time() { return lfo_1__delay_time; }
        void set_lfo_1___delay_time(const double & value) { this->lfo_1__delay_time = value; }

        const double & get_lfo_1___fade_time() const { return lfo_1__fade_time; }
        double & get_mutable_lfo_1___fade_time() { return lfo_1__fade_time; }
        void set_lfo_1___fade_time(const double & value) { this->lfo_1__fade_time = value; }

        const double & get_lfo_1___frequency() const { return lfo_1__frequency; }
        double & get_mutable_lfo_1___frequency() { return lfo_1__frequency; }
        void set_lfo_1___frequency(const double & value) { this->lfo_1__frequency = value; }

        std::shared_ptr<double> get_lfo_1___keytrack_transpose() const { return lfo_1__keytrack_transpose; }
        void set_lfo_1___keytrack_transpose(std::shared_ptr<double> value) { this->lfo_1__keytrack_transpose = value; }

        std::shared_ptr<double> get_lfo_1___keytrack_tune() const { return lfo_1__keytrack_tune; }
        void set_lfo_1___keytrack_tune(std::shared_ptr<double> value) { this->lfo_1__keytrack_tune = value; }

        const double & get_lfo_1___phase() const { return lfo_1__phase; }
        double & get_mutable_lfo_1___phase() { return lfo_1__phase; }
        void set_lfo_1___phase(const double & value) { this->lfo_1__phase = value; }

        std::shared_ptr<double> get_lfo_1___smooth_mode() const { return lfo_1__smooth_mode; }
        void set_lfo_1___smooth_mode(std::shared_ptr<double> value) { this->lfo_1__smooth_mode = value; }

        std::shared_ptr<double> get_lfo_1___smooth_time() const { return lfo_1__smooth_time; }
        void set_lfo_1___smooth_time(std::shared_ptr<double> value) { this->lfo_1__smooth_time = value; }

        const double & get_lfo_1___stereo() const { return lfo_1__stereo; }
        double & get_mutable_lfo_1___stereo() { return lfo_1__stereo; }
        void set_lfo_1___stereo(const double & value) { this->lfo_1__stereo = value; }

        const double & get_lfo_1___sync() const { return lfo_1__sync; }
        double & get_mutable_lfo_1___sync() { return lfo_1__sync; }
        void set_lfo_1___sync(const double & value) { this->lfo_1__sync = value; }

        const double & get_lfo_1___sync_type() const { return lfo_1__sync_type; }
        double & get_mutable_lfo_1___sync_type() { return lfo_1__sync_type; }
        void set_lfo_1___sync_type(const double & value) { this->lfo_1__sync_type = value; }

        const double & get_lfo_1___tempo() const { return lfo_1__tempo; }
        double & get_mutable_lfo_1___tempo() { return lfo_1__tempo; }
        void set_lfo_1___tempo(const double & value) { this->lfo_1__tempo = value; }

        const double & get_lfo_2___delay_time() const { return lfo_2__delay_time; }
        double & get_mutable_lfo_2___delay_time() { return lfo_2__delay_time; }
        void set_lfo_2___delay_time(const double & value) { this->lfo_2__delay_time = value; }

        const double & get_lfo_2___fade_time() const { return lfo_2__fade_time; }
        double & get_mutable_lfo_2___fade_time() { return lfo_2__fade_time; }
        void set_lfo_2___fade_time(const double & value) { this->lfo_2__fade_time = value; }

        const double & get_lfo_2___frequency() const { return lfo_2__frequency; }
        double & get_mutable_lfo_2___frequency() { return lfo_2__frequency; }
        void set_lfo_2___frequency(const double & value) { this->lfo_2__frequency = value; }

        std::shared_ptr<double> get_lfo_2___keytrack_transpose() const { return lfo_2__keytrack_transpose; }
        void set_lfo_2___keytrack_transpose(std::shared_ptr<double> value) { this->lfo_2__keytrack_transpose = value; }

        std::shared_ptr<double> get_lfo_2___keytrack_tune() const { return lfo_2__keytrack_tune; }
        void set_lfo_2___keytrack_tune(std::shared_ptr<double> value) { this->lfo_2__keytrack_tune = value; }

        const double & get_lfo_2___phase() const { return lfo_2__phase; }
        double & get_mutable_lfo_2___phase() { return lfo_2__phase; }
        void set_lfo_2___phase(const double & value) { this->lfo_2__phase = value; }

        std::shared_ptr<double> get_lfo_2___smooth_mode() const { return lfo_2__smooth_mode; }
        void set_lfo_2___smooth_mode(std::shared_ptr<double> value) { this->lfo_2__smooth_mode = value; }

        std::shared_ptr<double> get_lfo_2___smooth_time() const { return lfo_2__smooth_time; }
        void set_lfo_2___smooth_time(std::shared_ptr<double> value) { this->lfo_2__smooth_time = value; }

        const double & get_lfo_2___stereo() const { return lfo_2__stereo; }
        double & get_mutable_lfo_2___stereo() { return lfo_2__stereo; }
        void set_lfo_2___stereo(const double & value) { this->lfo_2__stereo = value; }

        const double & get_lfo_2___sync() const { return lfo_2__sync; }
        double & get_mutable_lfo_2___sync() { return lfo_2__sync; }
        void set_lfo_2___sync(const double & value) { this->lfo_2__sync = value; }

        const double & get_lfo_2___sync_type() const { return lfo_2__sync_type; }
        double & get_mutable_lfo_2___sync_type() { return lfo_2__sync_type; }
        void set_lfo_2___sync_type(const double & value) { this->lfo_2__sync_type = value; }

        const double & get_lfo_2___tempo() const { return lfo_2__tempo; }
        double & get_mutable_lfo_2___tempo() { return lfo_2__tempo; }
        void set_lfo_2___tempo(const double & value) { this->lfo_2__tempo = value; }

        const double & get_lfo_3___delay_time() const { return lfo_3__delay_time; }
        double & get_mutable_lfo_3___delay_time() { return lfo_3__delay_time; }
        void set_lfo_3___delay_time(const double & value) { this->lfo_3__delay_time = value; }

        const double & get_lfo_3___fade_time() const { return lfo_3__fade_time; }
        double & get_mutable_lfo_3___fade_time() { return lfo_3__fade_time; }
        void set_lfo_3___fade_time(const double & value) { this->lfo_3__fade_time = value; }

        const double & get_lfo_3___frequency() const { return lfo_3__frequency; }
        double & get_mutable_lfo_3___frequency() { return lfo_3__frequency; }
        void set_lfo_3___frequency(const double & value) { this->lfo_3__frequency = value; }

        std::shared_ptr<double> get_lfo_3___keytrack_transpose() const { return lfo_3__keytrack_transpose; }
        void set_lfo_3___keytrack_transpose(std::shared_ptr<double> value) { this->lfo_3__keytrack_transpose = value; }

        std::shared_ptr<double> get_lfo_3___keytrack_tune() const { return lfo_3__keytrack_tune; }
        void set_lfo_3___keytrack_tune(std::shared_ptr<double> value) { this->lfo_3__keytrack_tune = value; }

        const double & get_lfo_3___phase() const { return lfo_3__phase; }
        double & get_mutable_lfo_3___phase() { return lfo_3__phase; }
        void set_lfo_3___phase(const double & value) { this->lfo_3__phase = value; }

        std::shared_ptr<double> get_lfo_3___smooth_mode() const { return lfo_3__smooth_mode; }
        void set_lfo_3___smooth_mode(std::shared_ptr<double> value) { this->lfo_3__smooth_mode = value; }

        std::shared_ptr<double> get_lfo_3___smooth_time() const { return lfo_3__smooth_time; }
        void set_lfo_3___smooth_time(std::shared_ptr<double> value) { this->lfo_3__smooth_time = value; }

        const double & get_lfo_3___stereo() const { return lfo_3__stereo; }
        double & get_mutable_lfo_3___stereo() { return lfo_3__stereo; }
        void set_lfo_3___stereo(const double & value) { this->lfo_3__stereo = value; }

        const double & get_lfo_3___sync() const { return lfo_3__sync; }
        double & get_mutable_lfo_3___sync() { return lfo_3__sync; }
        void set_lfo_3___sync(const double & value) { this->lfo_3__sync = value; }

        const double & get_lfo_3___sync_type() const { return lfo_3__sync_type; }
        double & get_mutable_lfo_3___sync_type() { return lfo_3__sync_type; }
        void set_lfo_3___sync_type(const double & value) { this->lfo_3__sync_type = value; }

        const double & get_lfo_3___tempo() const { return lfo_3__tempo; }
        double & get_mutable_lfo_3___tempo() { return lfo_3__tempo; }
        void set_lfo_3___tempo(const double & value) { this->lfo_3__tempo = value; }

        const double & get_lfo_4___delay_time() const { return lfo_4__delay_time; }
        double & get_mutable_lfo_4___delay_time() { return lfo_4__delay_time; }
        void set_lfo_4___delay_time(const double & value) { this->lfo_4__delay_time = value; }

        const double & get_lfo_4___fade_time() const { return lfo_4__fade_time; }
        double & get_mutable_lfo_4___fade_time() { return lfo_4__fade_time; }
        void set_lfo_4___fade_time(const double & value) { this->lfo_4__fade_time = value; }

        const double & get_lfo_4___frequency() const { return lfo_4__frequency; }
        double & get_mutable_lfo_4___frequency() { return lfo_4__frequency; }
        void set_lfo_4___frequency(const double & value) { this->lfo_4__frequency = value; }

        std::shared_ptr<double> get_lfo_4___keytrack_transpose() const { return lfo_4__keytrack_transpose; }
        void set_lfo_4___keytrack_transpose(std::shared_ptr<double> value) { this->lfo_4__keytrack_transpose = value; }

        std::shared_ptr<double> get_lfo_4___keytrack_tune() const { return lfo_4__keytrack_tune; }
        void set_lfo_4___keytrack_tune(std::shared_ptr<double> value) { this->lfo_4__keytrack_tune = value; }

        const double & get_lfo_4___phase() const { return lfo_4__phase; }
        double & get_mutable_lfo_4___phase() { return lfo_4__phase; }
        void set_lfo_4___phase(const double & value) { this->lfo_4__phase = value; }

        std::shared_ptr<double> get_lfo_4___smooth_mode() const { return lfo_4__smooth_mode; }
        void set_lfo_4___smooth_mode(std::shared_ptr<double> value) { this->lfo_4__smooth_mode = value; }

        std::shared_ptr<double> get_lfo_4___smooth_time() const { return lfo_4__smooth_time; }
        void set_lfo_4___smooth_time(std::shared_ptr<double> value) { this->lfo_4__smooth_time = value; }

        const double & get_lfo_4___stereo() const { return lfo_4__stereo; }
        double & get_mutable_lfo_4___stereo() { return lfo_4__stereo; }
        void set_lfo_4___stereo(const double & value) { this->lfo_4__stereo = value; }

        const double & get_lfo_4___sync() const { return lfo_4__sync; }
        double & get_mutable_lfo_4___sync() { return lfo_4__sync; }
        void set_lfo_4___sync(const double & value) { this->lfo_4__sync = value; }

        const double & get_lfo_4___sync_type() const { return lfo_4__sync_type; }
        double & get_mutable_lfo_4___sync_type() { return lfo_4__sync_type; }
        void set_lfo_4___sync_type(const double & value) { this->lfo_4__sync_type = value; }

        const double & get_lfo_4___tempo() const { return lfo_4__tempo; }
        double & get_mutable_lfo_4___tempo() { return lfo_4__tempo; }
        void set_lfo_4___tempo(const double & value) { this->lfo_4__tempo = value; }

        const double & get_lfo_5___delay_time() const { return lfo_5__delay_time; }
        double & get_mutable_lfo_5___delay_time() { return lfo_5__delay_time; }
        void set_lfo_5___delay_time(const double & value) { this->lfo_5__delay_time = value; }

        const double & get_lfo_5___fade_time() const { return lfo_5__fade_time; }
        double & get_mutable_lfo_5___fade_time() { return lfo_5__fade_time; }
        void set_lfo_5___fade_time(const double & value) { this->lfo_5__fade_time = value; }

        const double & get_lfo_5___frequency() const { return lfo_5__frequency; }
        double & get_mutable_lfo_5___frequency() { return lfo_5__frequency; }
        void set_lfo_5___frequency(const double & value) { this->lfo_5__frequency = value; }

        std::shared_ptr<double> get_lfo_5___keytrack_transpose() const { return lfo_5__keytrack_transpose; }
        void set_lfo_5___keytrack_transpose(std::shared_ptr<double> value) { this->lfo_5__keytrack_transpose = value; }

        std::shared_ptr<double> get_lfo_5___keytrack_tune() const { return lfo_5__keytrack_tune; }
        void set_lfo_5___keytrack_tune(std::shared_ptr<double> value) { this->lfo_5__keytrack_tune = value; }

        const double & get_lfo_5___phase() const { return lfo_5__phase; }
        double & get_mutable_lfo_5___phase() { return lfo_5__phase; }
        void set_lfo_5___phase(const double & value) { this->lfo_5__phase = value; }

        std::shared_ptr<double> get_lfo_5___smooth_mode() const { return lfo_5__smooth_mode; }
        void set_lfo_5___smooth_mode(std::shared_ptr<double> value) { this->lfo_5__smooth_mode = value; }

        std::shared_ptr<double> get_lfo_5___smooth_time() const { return lfo_5__smooth_time; }
        void set_lfo_5___smooth_time(std::shared_ptr<double> value) { this->lfo_5__smooth_time = value; }

        const double & get_lfo_5___stereo() const { return lfo_5__stereo; }
        double & get_mutable_lfo_5___stereo() { return lfo_5__stereo; }
        void set_lfo_5___stereo(const double & value) { this->lfo_5__stereo = value; }

        const double & get_lfo_5___sync() const { return lfo_5__sync; }
        double & get_mutable_lfo_5___sync() { return lfo_5__sync; }
        void set_lfo_5___sync(const double & value) { this->lfo_5__sync = value; }

        const double & get_lfo_5___sync_type() const { return lfo_5__sync_type; }
        double & get_mutable_lfo_5___sync_type() { return lfo_5__sync_type; }
        void set_lfo_5___sync_type(const double & value) { this->lfo_5__sync_type = value; }

        const double & get_lfo_5___tempo() const { return lfo_5__tempo; }
        double & get_mutable_lfo_5___tempo() { return lfo_5__tempo; }
        void set_lfo_5___tempo(const double & value) { this->lfo_5__tempo = value; }

        const double & get_lfo_6___delay_time() const { return lfo_6__delay_time; }
        double & get_mutable_lfo_6___delay_time() { return lfo_6__delay_time; }
        void set_lfo_6___delay_time(const double & value) { this->lfo_6__delay_time = value; }

        const double & get_lfo_6___fade_time() const { return lfo_6__fade_time; }
        double & get_mutable_lfo_6___fade_time() { return lfo_6__fade_time; }
        void set_lfo_6___fade_time(const double & value) { this->lfo_6__fade_time = value; }

        const double & get_lfo_6___frequency() const { return lfo_6__frequency; }
        double & get_mutable_lfo_6___frequency() { return lfo_6__frequency; }
        void set_lfo_6___frequency(const double & value) { this->lfo_6__frequency = value; }

        std::shared_ptr<double> get_lfo_6___keytrack_transpose() const { return lfo_6__keytrack_transpose; }
        void set_lfo_6___keytrack_transpose(std::shared_ptr<double> value) { this->lfo_6__keytrack_transpose = value; }

        std::shared_ptr<double> get_lfo_6___keytrack_tune() const { return lfo_6__keytrack_tune; }
        void set_lfo_6___keytrack_tune(std::shared_ptr<double> value) { this->lfo_6__keytrack_tune = value; }

        const double & get_lfo_6___phase() const { return lfo_6__phase; }
        double & get_mutable_lfo_6___phase() { return lfo_6__phase; }
        void set_lfo_6___phase(const double & value) { this->lfo_6__phase = value; }

        std::shared_ptr<double> get_lfo_6___smooth_mode() const { return lfo_6__smooth_mode; }
        void set_lfo_6___smooth_mode(std::shared_ptr<double> value) { this->lfo_6__smooth_mode = value; }

        std::shared_ptr<double> get_lfo_6___smooth_time() const { return lfo_6__smooth_time; }
        void set_lfo_6___smooth_time(std::shared_ptr<double> value) { this->lfo_6__smooth_time = value; }

        const double & get_lfo_6___stereo() const { return lfo_6__stereo; }
        double & get_mutable_lfo_6___stereo() { return lfo_6__stereo; }
        void set_lfo_6___stereo(const double & value) { this->lfo_6__stereo = value; }

        const double & get_lfo_6___sync() const { return lfo_6__sync; }
        double & get_mutable_lfo_6___sync() { return lfo_6__sync; }
        void set_lfo_6___sync(const double & value) { this->lfo_6__sync = value; }

        const double & get_lfo_6___sync_type() const { return lfo_6__sync_type; }
        double & get_mutable_lfo_6___sync_type() { return lfo_6__sync_type; }
        void set_lfo_6___sync_type(const double & value) { this->lfo_6__sync_type = value; }

        const double & get_lfo_6___tempo() const { return lfo_6__tempo; }
        double & get_mutable_lfo_6___tempo() { return lfo_6__tempo; }
        void set_lfo_6___tempo(const double & value) { this->lfo_6__tempo = value; }

        const double & get_lfo_7___delay_time() const { return lfo_7__delay_time; }
        double & get_mutable_lfo_7___delay_time() { return lfo_7__delay_time; }
        void set_lfo_7___delay_time(const double & value) { this->lfo_7__delay_time = value; }

        const double & get_lfo_7___fade_time() const { return lfo_7__fade_time; }
        double & get_mutable_lfo_7___fade_time() { return lfo_7__fade_time; }
        void set_lfo_7___fade_time(const double & value) { this->lfo_7__fade_time = value; }

        const double & get_lfo_7___frequency() const { return lfo_7__frequency; }
        double & get_mutable_lfo_7___frequency() { return lfo_7__frequency; }
        void set_lfo_7___frequency(const double & value) { this->lfo_7__frequency = value; }

        std::shared_ptr<double> get_lfo_7___keytrack_transpose() const { return lfo_7__keytrack_transpose; }
        void set_lfo_7___keytrack_transpose(std::shared_ptr<double> value) { this->lfo_7__keytrack_transpose = value; }

        std::shared_ptr<double> get_lfo_7___keytrack_tune() const { return lfo_7__keytrack_tune; }
        void set_lfo_7___keytrack_tune(std::shared_ptr<double> value) { this->lfo_7__keytrack_tune = value; }

        const double & get_lfo_7___phase() const { return lfo_7__phase; }
        double & get_mutable_lfo_7___phase() { return lfo_7__phase; }
        void set_lfo_7___phase(const double & value) { this->lfo_7__phase = value; }

        std::shared_ptr<double> get_lfo_7___smooth_mode() const { return lfo_7__smooth_mode; }
        void set_lfo_7___smooth_mode(std::shared_ptr<double> value) { this->lfo_7__smooth_mode = value; }

        std::shared_ptr<double> get_lfo_7___smooth_time() const { return lfo_7__smooth_time; }
        void set_lfo_7___smooth_time(std::shared_ptr<double> value) { this->lfo_7__smooth_time = value; }

        const double & get_lfo_7___stereo() const { return lfo_7__stereo; }
        double & get_mutable_lfo_7___stereo() { return lfo_7__stereo; }
        void set_lfo_7___stereo(const double & value) { this->lfo_7__stereo = value; }

        const double & get_lfo_7___sync() const { return lfo_7__sync; }
        double & get_mutable_lfo_7___sync() { return lfo_7__sync; }
        void set_lfo_7___sync(const double & value) { this->lfo_7__sync = value; }

        const double & get_lfo_7___sync_type() const { return lfo_7__sync_type; }
        double & get_mutable_lfo_7___sync_type() { return lfo_7__sync_type; }
        void set_lfo_7___sync_type(const double & value) { this->lfo_7__sync_type = value; }

        const double & get_lfo_7___tempo() const { return lfo_7__tempo; }
        double & get_mutable_lfo_7___tempo() { return lfo_7__tempo; }
        void set_lfo_7___tempo(const double & value) { this->lfo_7__tempo = value; }

        const double & get_lfo_8___delay_time() const { return lfo_8__delay_time; }
        double & get_mutable_lfo_8___delay_time() { return lfo_8__delay_time; }
        void set_lfo_8___delay_time(const double & value) { this->lfo_8__delay_time = value; }

        const double & get_lfo_8___fade_time() const { return lfo_8__fade_time; }
        double & get_mutable_lfo_8___fade_time() { return lfo_8__fade_time; }
        void set_lfo_8___fade_time(const double & value) { this->lfo_8__fade_time = value; }

        const double & get_lfo_8___frequency() const { return lfo_8__frequency; }
        double & get_mutable_lfo_8___frequency() { return lfo_8__frequency; }
        void set_lfo_8___frequency(const double & value) { this->lfo_8__frequency = value; }

        std::shared_ptr<double> get_lfo_8___keytrack_transpose() const { return lfo_8__keytrack_transpose; }
        void set_lfo_8___keytrack_transpose(std::shared_ptr<double> value) { this->lfo_8__keytrack_transpose = value; }

        std::shared_ptr<double> get_lfo_8___keytrack_tune() const { return lfo_8__keytrack_tune; }
        void set_lfo_8___keytrack_tune(std::shared_ptr<double> value) { this->lfo_8__keytrack_tune = value; }

        const double & get_lfo_8___phase() const { return lfo_8__phase; }
        double & get_mutable_lfo_8___phase() { return lfo_8__phase; }
        void set_lfo_8___phase(const double & value) { this->lfo_8__phase = value; }

        std::shared_ptr<double> get_lfo_8___smooth_mode() const { return lfo_8__smooth_mode; }
        void set_lfo_8___smooth_mode(std::shared_ptr<double> value) { this->lfo_8__smooth_mode = value; }

        std::shared_ptr<double> get_lfo_8___smooth_time() const { return lfo_8__smooth_time; }
        void set_lfo_8___smooth_time(std::shared_ptr<double> value) { this->lfo_8__smooth_time = value; }

        const double & get_lfo_8___stereo() const { return lfo_8__stereo; }
        double & get_mutable_lfo_8___stereo() { return lfo_8__stereo; }
        void set_lfo_8___stereo(const double & value) { this->lfo_8__stereo = value; }

        const double & get_lfo_8___sync() const { return lfo_8__sync; }
        double & get_mutable_lfo_8___sync() { return lfo_8__sync; }
        void set_lfo_8___sync(const double & value) { this->lfo_8__sync = value; }

        const double & get_lfo_8___sync_type() const { return lfo_8__sync_type; }
        double & get_mutable_lfo_8___sync_type() { return lfo_8__sync_type; }
        void set_lfo_8___sync_type(const double & value) { this->lfo_8__sync_type = value; }

        const double & get_lfo_8___tempo() const { return lfo_8__tempo; }
        double & get_mutable_lfo_8___tempo() { return lfo_8__tempo; }
        void set_lfo_8___tempo(const double & value) { this->lfo_8__tempo = value; }

        const std::vector<Lfo> & get_lfos() const { return lfos; }
        std::vector<Lfo> & get_mutable_lfos() { return lfos; }
        void set_lfos(const std::vector<Lfo> & value) { this->lfos = value; }

        const double & get_macro_control_1() const { return macro_control_1; }
        double & get_mutable_macro_control_1() { return macro_control_1; }
        void set_macro_control_1(const double & value) { this->macro_control_1 = value; }

        const double & get_macro_control_2() const { return macro_control_2; }
        double & get_mutable_macro_control_2() { return macro_control_2; }
        void set_macro_control_2(const double & value) { this->macro_control_2 = value; }

        const double & get_macro_control_3() const { return macro_control_3; }
        double & get_mutable_macro_control_3() { return macro_control_3; }
        void set_macro_control_3(const double & value) { this->macro_control_3 = value; }

        const double & get_macro_control_4() const { return macro_control_4; }
        double & get_mutable_macro_control_4() { return macro_control_4; }
        void set_macro_control_4(const double & value) { this->macro_control_4 = value; }

        const double & get_mod_wheel() const { return mod_wheel; }
        double & get_mutable_mod_wheel() { return mod_wheel; }
        void set_mod_wheel(const double & value) { this->mod_wheel = value; }

        const double & get_modulation_10___amount() const { return modulation_10__amount; }
        double & get_mutable_modulation_10___amount() { return modulation_10__amount; }
        void set_modulation_10___amount(const double & value) { this->modulation_10__amount = value; }

        const double & get_modulation_10___bipolar() const { return modulation_10__bipolar; }
        double & get_mutable_modulation_10___bipolar() { return modulation_10__bipolar; }
        void set_modulation_10___bipolar(const double & value) { this->modulation_10__bipolar = value; }

        const double & get_modulation_10___bypass() const { return modulation_10__bypass; }
        double & get_mutable_modulation_10___bypass() { return modulation_10__bypass; }
        void set_modulation_10___bypass(const double & value) { this->modulation_10__bypass = value; }

        const double & get_modulation_10___power() const { return modulation_10__power; }
        double & get_mutable_modulation_10___power() { return modulation_10__power; }
        void set_modulation_10___power(const double & value) { this->modulation_10__power = value; }

        const double & get_modulation_10___stereo() const { return modulation_10__stereo; }
        double & get_mutable_modulation_10___stereo() { return modulation_10__stereo; }
        void set_modulation_10___stereo(const double & value) { this->modulation_10__stereo = value; }

        const double & get_modulation_11___amount() const { return modulation_11__amount; }
        double & get_mutable_modulation_11___amount() { return modulation_11__amount; }
        void set_modulation_11___amount(const double & value) { this->modulation_11__amount = value; }

        const double & get_modulation_11___bipolar() const { return modulation_11__bipolar; }
        double & get_mutable_modulation_11___bipolar() { return modulation_11__bipolar; }
        void set_modulation_11___bipolar(const double & value) { this->modulation_11__bipolar = value; }

        const double & get_modulation_11___bypass() const { return modulation_11__bypass; }
        double & get_mutable_modulation_11___bypass() { return modulation_11__bypass; }
        void set_modulation_11___bypass(const double & value) { this->modulation_11__bypass = value; }

        const double & get_modulation_11___power() const { return modulation_11__power; }
        double & get_mutable_modulation_11___power() { return modulation_11__power; }
        void set_modulation_11___power(const double & value) { this->modulation_11__power = value; }

        const double & get_modulation_11___stereo() const { return modulation_11__stereo; }
        double & get_mutable_modulation_11___stereo() { return modulation_11__stereo; }
        void set_modulation_11___stereo(const double & value) { this->modulation_11__stereo = value; }

        const double & get_modulation_12___amount() const { return modulation_12__amount; }
        double & get_mutable_modulation_12___amount() { return modulation_12__amount; }
        void set_modulation_12___amount(const double & value) { this->modulation_12__amount = value; }

        const double & get_modulation_12___bipolar() const { return modulation_12__bipolar; }
        double & get_mutable_modulation_12___bipolar() { return modulation_12__bipolar; }
        void set_modulation_12___bipolar(const double & value) { this->modulation_12__bipolar = value; }

        const double & get_modulation_12___bypass() const { return modulation_12__bypass; }
        double & get_mutable_modulation_12___bypass() { return modulation_12__bypass; }
        void set_modulation_12___bypass(const double & value) { this->modulation_12__bypass = value; }

        const double & get_modulation_12___power() const { return modulation_12__power; }
        double & get_mutable_modulation_12___power() { return modulation_12__power; }
        void set_modulation_12___power(const double & value) { this->modulation_12__power = value; }

        const double & get_modulation_12___stereo() const { return modulation_12__stereo; }
        double & get_mutable_modulation_12___stereo() { return modulation_12__stereo; }
        void set_modulation_12___stereo(const double & value) { this->modulation_12__stereo = value; }

        const double & get_modulation_13___amount() const { return modulation_13__amount; }
        double & get_mutable_modulation_13___amount() { return modulation_13__amount; }
        void set_modulation_13___amount(const double & value) { this->modulation_13__amount = value; }

        const double & get_modulation_13___bipolar() const { return modulation_13__bipolar; }
        double & get_mutable_modulation_13___bipolar() { return modulation_13__bipolar; }
        void set_modulation_13___bipolar(const double & value) { this->modulation_13__bipolar = value; }

        const double & get_modulation_13___bypass() const { return modulation_13__bypass; }
        double & get_mutable_modulation_13___bypass() { return modulation_13__bypass; }
        void set_modulation_13___bypass(const double & value) { this->modulation_13__bypass = value; }

        const double & get_modulation_13___power() const { return modulation_13__power; }
        double & get_mutable_modulation_13___power() { return modulation_13__power; }
        void set_modulation_13___power(const double & value) { this->modulation_13__power = value; }

        const double & get_modulation_13___stereo() const { return modulation_13__stereo; }
        double & get_mutable_modulation_13___stereo() { return modulation_13__stereo; }
        void set_modulation_13___stereo(const double & value) { this->modulation_13__stereo = value; }

        const double & get_modulation_14___amount() const { return modulation_14__amount; }
        double & get_mutable_modulation_14___amount() { return modulation_14__amount; }
        void set_modulation_14___amount(const double & value) { this->modulation_14__amount = value; }

        const double & get_modulation_14___bipolar() const { return modulation_14__bipolar; }
        double & get_mutable_modulation_14___bipolar() { return modulation_14__bipolar; }
        void set_modulation_14___bipolar(const double & value) { this->modulation_14__bipolar = value; }

        const double & get_modulation_14___bypass() const { return modulation_14__bypass; }
        double & get_mutable_modulation_14___bypass() { return modulation_14__bypass; }
        void set_modulation_14___bypass(const double & value) { this->modulation_14__bypass = value; }

        const double & get_modulation_14___power() const { return modulation_14__power; }
        double & get_mutable_modulation_14___power() { return modulation_14__power; }
        void set_modulation_14___power(const double & value) { this->modulation_14__power = value; }

        const double & get_modulation_14___stereo() const { return modulation_14__stereo; }
        double & get_mutable_modulation_14___stereo() { return modulation_14__stereo; }
        void set_modulation_14___stereo(const double & value) { this->modulation_14__stereo = value; }

        const double & get_modulation_15___amount() const { return modulation_15__amount; }
        double & get_mutable_modulation_15___amount() { return modulation_15__amount; }
        void set_modulation_15___amount(const double & value) { this->modulation_15__amount = value; }

        const double & get_modulation_15___bipolar() const { return modulation_15__bipolar; }
        double & get_mutable_modulation_15___bipolar() { return modulation_15__bipolar; }
        void set_modulation_15___bipolar(const double & value) { this->modulation_15__bipolar = value; }

        const double & get_modulation_15___bypass() const { return modulation_15__bypass; }
        double & get_mutable_modulation_15___bypass() { return modulation_15__bypass; }
        void set_modulation_15___bypass(const double & value) { this->modulation_15__bypass = value; }

        const double & get_modulation_15___power() const { return modulation_15__power; }
        double & get_mutable_modulation_15___power() { return modulation_15__power; }
        void set_modulation_15___power(const double & value) { this->modulation_15__power = value; }

        const double & get_modulation_15___stereo() const { return modulation_15__stereo; }
        double & get_mutable_modulation_15___stereo() { return modulation_15__stereo; }
        void set_modulation_15___stereo(const double & value) { this->modulation_15__stereo = value; }

        const double & get_modulation_16___amount() const { return modulation_16__amount; }
        double & get_mutable_modulation_16___amount() { return modulation_16__amount; }
        void set_modulation_16___amount(const double & value) { this->modulation_16__amount = value; }

        const double & get_modulation_16___bipolar() const { return modulation_16__bipolar; }
        double & get_mutable_modulation_16___bipolar() { return modulation_16__bipolar; }
        void set_modulation_16___bipolar(const double & value) { this->modulation_16__bipolar = value; }

        const double & get_modulation_16___bypass() const { return modulation_16__bypass; }
        double & get_mutable_modulation_16___bypass() { return modulation_16__bypass; }
        void set_modulation_16___bypass(const double & value) { this->modulation_16__bypass = value; }

        const double & get_modulation_16___power() const { return modulation_16__power; }
        double & get_mutable_modulation_16___power() { return modulation_16__power; }
        void set_modulation_16___power(const double & value) { this->modulation_16__power = value; }

        const double & get_modulation_16___stereo() const { return modulation_16__stereo; }
        double & get_mutable_modulation_16___stereo() { return modulation_16__stereo; }
        void set_modulation_16___stereo(const double & value) { this->modulation_16__stereo = value; }

        const double & get_modulation_17___amount() const { return modulation_17__amount; }
        double & get_mutable_modulation_17___amount() { return modulation_17__amount; }
        void set_modulation_17___amount(const double & value) { this->modulation_17__amount = value; }

        const double & get_modulation_17___bipolar() const { return modulation_17__bipolar; }
        double & get_mutable_modulation_17___bipolar() { return modulation_17__bipolar; }
        void set_modulation_17___bipolar(const double & value) { this->modulation_17__bipolar = value; }

        const double & get_modulation_17___bypass() const { return modulation_17__bypass; }
        double & get_mutable_modulation_17___bypass() { return modulation_17__bypass; }
        void set_modulation_17___bypass(const double & value) { this->modulation_17__bypass = value; }

        const double & get_modulation_17___power() const { return modulation_17__power; }
        double & get_mutable_modulation_17___power() { return modulation_17__power; }
        void set_modulation_17___power(const double & value) { this->modulation_17__power = value; }

        const double & get_modulation_17___stereo() const { return modulation_17__stereo; }
        double & get_mutable_modulation_17___stereo() { return modulation_17__stereo; }
        void set_modulation_17___stereo(const double & value) { this->modulation_17__stereo = value; }

        const double & get_modulation_18___amount() const { return modulation_18__amount; }
        double & get_mutable_modulation_18___amount() { return modulation_18__amount; }
        void set_modulation_18___amount(const double & value) { this->modulation_18__amount = value; }

        const double & get_modulation_18___bipolar() const { return modulation_18__bipolar; }
        double & get_mutable_modulation_18___bipolar() { return modulation_18__bipolar; }
        void set_modulation_18___bipolar(const double & value) { this->modulation_18__bipolar = value; }

        const double & get_modulation_18___bypass() const { return modulation_18__bypass; }
        double & get_mutable_modulation_18___bypass() { return modulation_18__bypass; }
        void set_modulation_18___bypass(const double & value) { this->modulation_18__bypass = value; }

        const double & get_modulation_18___power() const { return modulation_18__power; }
        double & get_mutable_modulation_18___power() { return modulation_18__power; }
        void set_modulation_18___power(const double & value) { this->modulation_18__power = value; }

        const double & get_modulation_18___stereo() const { return modulation_18__stereo; }
        double & get_mutable_modulation_18___stereo() { return modulation_18__stereo; }
        void set_modulation_18___stereo(const double & value) { this->modulation_18__stereo = value; }

        const double & get_modulation_19___amount() const { return modulation_19__amount; }
        double & get_mutable_modulation_19___amount() { return modulation_19__amount; }
        void set_modulation_19___amount(const double & value) { this->modulation_19__amount = value; }

        const double & get_modulation_19___bipolar() const { return modulation_19__bipolar; }
        double & get_mutable_modulation_19___bipolar() { return modulation_19__bipolar; }
        void set_modulation_19___bipolar(const double & value) { this->modulation_19__bipolar = value; }

        const double & get_modulation_19___bypass() const { return modulation_19__bypass; }
        double & get_mutable_modulation_19___bypass() { return modulation_19__bypass; }
        void set_modulation_19___bypass(const double & value) { this->modulation_19__bypass = value; }

        const double & get_modulation_19___power() const { return modulation_19__power; }
        double & get_mutable_modulation_19___power() { return modulation_19__power; }
        void set_modulation_19___power(const double & value) { this->modulation_19__power = value; }

        const double & get_modulation_19___stereo() const { return modulation_19__stereo; }
        double & get_mutable_modulation_19___stereo() { return modulation_19__stereo; }
        void set_modulation_19___stereo(const double & value) { this->modulation_19__stereo = value; }

        const double & get_modulation_1___amount() const { return modulation_1__amount; }
        double & get_mutable_modulation_1___amount() { return modulation_1__amount; }
        void set_modulation_1___amount(const double & value) { this->modulation_1__amount = value; }

        const double & get_modulation_1___bipolar() const { return modulation_1__bipolar; }
        double & get_mutable_modulation_1___bipolar() { return modulation_1__bipolar; }
        void set_modulation_1___bipolar(const double & value) { this->modulation_1__bipolar = value; }

        const double & get_modulation_1___bypass() const { return modulation_1__bypass; }
        double & get_mutable_modulation_1___bypass() { return modulation_1__bypass; }
        void set_modulation_1___bypass(const double & value) { this->modulation_1__bypass = value; }

        const double & get_modulation_1___power() const { return modulation_1__power; }
        double & get_mutable_modulation_1___power() { return modulation_1__power; }
        void set_modulation_1___power(const double & value) { this->modulation_1__power = value; }

        const double & get_modulation_1___stereo() const { return modulation_1__stereo; }
        double & get_mutable_modulation_1___stereo() { return modulation_1__stereo; }
        void set_modulation_1___stereo(const double & value) { this->modulation_1__stereo = value; }

        const double & get_modulation_20___amount() const { return modulation_20__amount; }
        double & get_mutable_modulation_20___amount() { return modulation_20__amount; }
        void set_modulation_20___amount(const double & value) { this->modulation_20__amount = value; }

        const double & get_modulation_20___bipolar() const { return modulation_20__bipolar; }
        double & get_mutable_modulation_20___bipolar() { return modulation_20__bipolar; }
        void set_modulation_20___bipolar(const double & value) { this->modulation_20__bipolar = value; }

        const double & get_modulation_20___bypass() const { return modulation_20__bypass; }
        double & get_mutable_modulation_20___bypass() { return modulation_20__bypass; }
        void set_modulation_20___bypass(const double & value) { this->modulation_20__bypass = value; }

        const double & get_modulation_20___power() const { return modulation_20__power; }
        double & get_mutable_modulation_20___power() { return modulation_20__power; }
        void set_modulation_20___power(const double & value) { this->modulation_20__power = value; }

        const double & get_modulation_20___stereo() const { return modulation_20__stereo; }
        double & get_mutable_modulation_20___stereo() { return modulation_20__stereo; }
        void set_modulation_20___stereo(const double & value) { this->modulation_20__stereo = value; }

        const double & get_modulation_21___amount() const { return modulation_21__amount; }
        double & get_mutable_modulation_21___amount() { return modulation_21__amount; }
        void set_modulation_21___amount(const double & value) { this->modulation_21__amount = value; }

        const double & get_modulation_21___bipolar() const { return modulation_21__bipolar; }
        double & get_mutable_modulation_21___bipolar() { return modulation_21__bipolar; }
        void set_modulation_21___bipolar(const double & value) { this->modulation_21__bipolar = value; }

        const double & get_modulation_21___bypass() const { return modulation_21__bypass; }
        double & get_mutable_modulation_21___bypass() { return modulation_21__bypass; }
        void set_modulation_21___bypass(const double & value) { this->modulation_21__bypass = value; }

        const double & get_modulation_21___power() const { return modulation_21__power; }
        double & get_mutable_modulation_21___power() { return modulation_21__power; }
        void set_modulation_21___power(const double & value) { this->modulation_21__power = value; }

        const double & get_modulation_21___stereo() const { return modulation_21__stereo; }
        double & get_mutable_modulation_21___stereo() { return modulation_21__stereo; }
        void set_modulation_21___stereo(const double & value) { this->modulation_21__stereo = value; }

        const double & get_modulation_22___amount() const { return modulation_22__amount; }
        double & get_mutable_modulation_22___amount() { return modulation_22__amount; }
        void set_modulation_22___amount(const double & value) { this->modulation_22__amount = value; }

        const double & get_modulation_22___bipolar() const { return modulation_22__bipolar; }
        double & get_mutable_modulation_22___bipolar() { return modulation_22__bipolar; }
        void set_modulation_22___bipolar(const double & value) { this->modulation_22__bipolar = value; }

        const double & get_modulation_22___bypass() const { return modulation_22__bypass; }
        double & get_mutable_modulation_22___bypass() { return modulation_22__bypass; }
        void set_modulation_22___bypass(const double & value) { this->modulation_22__bypass = value; }

        const double & get_modulation_22___power() const { return modulation_22__power; }
        double & get_mutable_modulation_22___power() { return modulation_22__power; }
        void set_modulation_22___power(const double & value) { this->modulation_22__power = value; }

        const double & get_modulation_22___stereo() const { return modulation_22__stereo; }
        double & get_mutable_modulation_22___stereo() { return modulation_22__stereo; }
        void set_modulation_22___stereo(const double & value) { this->modulation_22__stereo = value; }

        const double & get_modulation_23___amount() const { return modulation_23__amount; }
        double & get_mutable_modulation_23___amount() { return modulation_23__amount; }
        void set_modulation_23___amount(const double & value) { this->modulation_23__amount = value; }

        const double & get_modulation_23___bipolar() const { return modulation_23__bipolar; }
        double & get_mutable_modulation_23___bipolar() { return modulation_23__bipolar; }
        void set_modulation_23___bipolar(const double & value) { this->modulation_23__bipolar = value; }

        const double & get_modulation_23___bypass() const { return modulation_23__bypass; }
        double & get_mutable_modulation_23___bypass() { return modulation_23__bypass; }
        void set_modulation_23___bypass(const double & value) { this->modulation_23__bypass = value; }

        const double & get_modulation_23___power() const { return modulation_23__power; }
        double & get_mutable_modulation_23___power() { return modulation_23__power; }
        void set_modulation_23___power(const double & value) { this->modulation_23__power = value; }

        const double & get_modulation_23___stereo() const { return modulation_23__stereo; }
        double & get_mutable_modulation_23___stereo() { return modulation_23__stereo; }
        void set_modulation_23___stereo(const double & value) { this->modulation_23__stereo = value; }

        const double & get_modulation_24___amount() const { return modulation_24__amount; }
        double & get_mutable_modulation_24___amount() { return modulation_24__amount; }
        void set_modulation_24___amount(const double & value) { this->modulation_24__amount = value; }

        const double & get_modulation_24___bipolar() const { return modulation_24__bipolar; }
        double & get_mutable_modulation_24___bipolar() { return modulation_24__bipolar; }
        void set_modulation_24___bipolar(const double & value) { this->modulation_24__bipolar = value; }

        const double & get_modulation_24___bypass() const { return modulation_24__bypass; }
        double & get_mutable_modulation_24___bypass() { return modulation_24__bypass; }
        void set_modulation_24___bypass(const double & value) { this->modulation_24__bypass = value; }

        const double & get_modulation_24___power() const { return modulation_24__power; }
        double & get_mutable_modulation_24___power() { return modulation_24__power; }
        void set_modulation_24___power(const double & value) { this->modulation_24__power = value; }

        const double & get_modulation_24___stereo() const { return modulation_24__stereo; }
        double & get_mutable_modulation_24___stereo() { return modulation_24__stereo; }
        void set_modulation_24___stereo(const double & value) { this->modulation_24__stereo = value; }

        const double & get_modulation_25___amount() const { return modulation_25__amount; }
        double & get_mutable_modulation_25___amount() { return modulation_25__amount; }
        void set_modulation_25___amount(const double & value) { this->modulation_25__amount = value; }

        const double & get_modulation_25___bipolar() const { return modulation_25__bipolar; }
        double & get_mutable_modulation_25___bipolar() { return modulation_25__bipolar; }
        void set_modulation_25___bipolar(const double & value) { this->modulation_25__bipolar = value; }

        const double & get_modulation_25___bypass() const { return modulation_25__bypass; }
        double & get_mutable_modulation_25___bypass() { return modulation_25__bypass; }
        void set_modulation_25___bypass(const double & value) { this->modulation_25__bypass = value; }

        const double & get_modulation_25___power() const { return modulation_25__power; }
        double & get_mutable_modulation_25___power() { return modulation_25__power; }
        void set_modulation_25___power(const double & value) { this->modulation_25__power = value; }

        const double & get_modulation_25___stereo() const { return modulation_25__stereo; }
        double & get_mutable_modulation_25___stereo() { return modulation_25__stereo; }
        void set_modulation_25___stereo(const double & value) { this->modulation_25__stereo = value; }

        const double & get_modulation_26___amount() const { return modulation_26__amount; }
        double & get_mutable_modulation_26___amount() { return modulation_26__amount; }
        void set_modulation_26___amount(const double & value) { this->modulation_26__amount = value; }

        const double & get_modulation_26___bipolar() const { return modulation_26__bipolar; }
        double & get_mutable_modulation_26___bipolar() { return modulation_26__bipolar; }
        void set_modulation_26___bipolar(const double & value) { this->modulation_26__bipolar = value; }

        const double & get_modulation_26___bypass() const { return modulation_26__bypass; }
        double & get_mutable_modulation_26___bypass() { return modulation_26__bypass; }
        void set_modulation_26___bypass(const double & value) { this->modulation_26__bypass = value; }

        const double & get_modulation_26___power() const { return modulation_26__power; }
        double & get_mutable_modulation_26___power() { return modulation_26__power; }
        void set_modulation_26___power(const double & value) { this->modulation_26__power = value; }

        const double & get_modulation_26___stereo() const { return modulation_26__stereo; }
        double & get_mutable_modulation_26___stereo() { return modulation_26__stereo; }
        void set_modulation_26___stereo(const double & value) { this->modulation_26__stereo = value; }

        const double & get_modulation_27___amount() const { return modulation_27__amount; }
        double & get_mutable_modulation_27___amount() { return modulation_27__amount; }
        void set_modulation_27___amount(const double & value) { this->modulation_27__amount = value; }

        const double & get_modulation_27___bipolar() const { return modulation_27__bipolar; }
        double & get_mutable_modulation_27___bipolar() { return modulation_27__bipolar; }
        void set_modulation_27___bipolar(const double & value) { this->modulation_27__bipolar = value; }

        const double & get_modulation_27___bypass() const { return modulation_27__bypass; }
        double & get_mutable_modulation_27___bypass() { return modulation_27__bypass; }
        void set_modulation_27___bypass(const double & value) { this->modulation_27__bypass = value; }

        const double & get_modulation_27___power() const { return modulation_27__power; }
        double & get_mutable_modulation_27___power() { return modulation_27__power; }
        void set_modulation_27___power(const double & value) { this->modulation_27__power = value; }

        const double & get_modulation_27___stereo() const { return modulation_27__stereo; }
        double & get_mutable_modulation_27___stereo() { return modulation_27__stereo; }
        void set_modulation_27___stereo(const double & value) { this->modulation_27__stereo = value; }

        const double & get_modulation_28___amount() const { return modulation_28__amount; }
        double & get_mutable_modulation_28___amount() { return modulation_28__amount; }
        void set_modulation_28___amount(const double & value) { this->modulation_28__amount = value; }

        const double & get_modulation_28___bipolar() const { return modulation_28__bipolar; }
        double & get_mutable_modulation_28___bipolar() { return modulation_28__bipolar; }
        void set_modulation_28___bipolar(const double & value) { this->modulation_28__bipolar = value; }

        const double & get_modulation_28___bypass() const { return modulation_28__bypass; }
        double & get_mutable_modulation_28___bypass() { return modulation_28__bypass; }
        void set_modulation_28___bypass(const double & value) { this->modulation_28__bypass = value; }

        const double & get_modulation_28___power() const { return modulation_28__power; }
        double & get_mutable_modulation_28___power() { return modulation_28__power; }
        void set_modulation_28___power(const double & value) { this->modulation_28__power = value; }

        const double & get_modulation_28___stereo() const { return modulation_28__stereo; }
        double & get_mutable_modulation_28___stereo() { return modulation_28__stereo; }
        void set_modulation_28___stereo(const double & value) { this->modulation_28__stereo = value; }

        const double & get_modulation_29___amount() const { return modulation_29__amount; }
        double & get_mutable_modulation_29___amount() { return modulation_29__amount; }
        void set_modulation_29___amount(const double & value) { this->modulation_29__amount = value; }

        const double & get_modulation_29___bipolar() const { return modulation_29__bipolar; }
        double & get_mutable_modulation_29___bipolar() { return modulation_29__bipolar; }
        void set_modulation_29___bipolar(const double & value) { this->modulation_29__bipolar = value; }

        const double & get_modulation_29___bypass() const { return modulation_29__bypass; }
        double & get_mutable_modulation_29___bypass() { return modulation_29__bypass; }
        void set_modulation_29___bypass(const double & value) { this->modulation_29__bypass = value; }

        const double & get_modulation_29___power() const { return modulation_29__power; }
        double & get_mutable_modulation_29___power() { return modulation_29__power; }
        void set_modulation_29___power(const double & value) { this->modulation_29__power = value; }

        const double & get_modulation_29___stereo() const { return modulation_29__stereo; }
        double & get_mutable_modulation_29___stereo() { return modulation_29__stereo; }
        void set_modulation_29___stereo(const double & value) { this->modulation_29__stereo = value; }

        const double & get_modulation_2___amount() const { return modulation_2__amount; }
        double & get_mutable_modulation_2___amount() { return modulation_2__amount; }
        void set_modulation_2___amount(const double & value) { this->modulation_2__amount = value; }

        const double & get_modulation_2___bipolar() const { return modulation_2__bipolar; }
        double & get_mutable_modulation_2___bipolar() { return modulation_2__bipolar; }
        void set_modulation_2___bipolar(const double & value) { this->modulation_2__bipolar = value; }

        const double & get_modulation_2___bypass() const { return modulation_2__bypass; }
        double & get_mutable_modulation_2___bypass() { return modulation_2__bypass; }
        void set_modulation_2___bypass(const double & value) { this->modulation_2__bypass = value; }

        const double & get_modulation_2___power() const { return modulation_2__power; }
        double & get_mutable_modulation_2___power() { return modulation_2__power; }
        void set_modulation_2___power(const double & value) { this->modulation_2__power = value; }

        const double & get_modulation_2___stereo() const { return modulation_2__stereo; }
        double & get_mutable_modulation_2___stereo() { return modulation_2__stereo; }
        void set_modulation_2___stereo(const double & value) { this->modulation_2__stereo = value; }

        const double & get_modulation_30___amount() const { return modulation_30__amount; }
        double & get_mutable_modulation_30___amount() { return modulation_30__amount; }
        void set_modulation_30___amount(const double & value) { this->modulation_30__amount = value; }

        const double & get_modulation_30___bipolar() const { return modulation_30__bipolar; }
        double & get_mutable_modulation_30___bipolar() { return modulation_30__bipolar; }
        void set_modulation_30___bipolar(const double & value) { this->modulation_30__bipolar = value; }

        const double & get_modulation_30___bypass() const { return modulation_30__bypass; }
        double & get_mutable_modulation_30___bypass() { return modulation_30__bypass; }
        void set_modulation_30___bypass(const double & value) { this->modulation_30__bypass = value; }

        const double & get_modulation_30___power() const { return modulation_30__power; }
        double & get_mutable_modulation_30___power() { return modulation_30__power; }
        void set_modulation_30___power(const double & value) { this->modulation_30__power = value; }

        const double & get_modulation_30___stereo() const { return modulation_30__stereo; }
        double & get_mutable_modulation_30___stereo() { return modulation_30__stereo; }
        void set_modulation_30___stereo(const double & value) { this->modulation_30__stereo = value; }

        const double & get_modulation_31___amount() const { return modulation_31__amount; }
        double & get_mutable_modulation_31___amount() { return modulation_31__amount; }
        void set_modulation_31___amount(const double & value) { this->modulation_31__amount = value; }

        const double & get_modulation_31___bipolar() const { return modulation_31__bipolar; }
        double & get_mutable_modulation_31___bipolar() { return modulation_31__bipolar; }
        void set_modulation_31___bipolar(const double & value) { this->modulation_31__bipolar = value; }

        const double & get_modulation_31___bypass() const { return modulation_31__bypass; }
        double & get_mutable_modulation_31___bypass() { return modulation_31__bypass; }
        void set_modulation_31___bypass(const double & value) { this->modulation_31__bypass = value; }

        const double & get_modulation_31___power() const { return modulation_31__power; }
        double & get_mutable_modulation_31___power() { return modulation_31__power; }
        void set_modulation_31___power(const double & value) { this->modulation_31__power = value; }

        const double & get_modulation_31___stereo() const { return modulation_31__stereo; }
        double & get_mutable_modulation_31___stereo() { return modulation_31__stereo; }
        void set_modulation_31___stereo(const double & value) { this->modulation_31__stereo = value; }

        const double & get_modulation_32___amount() const { return modulation_32__amount; }
        double & get_mutable_modulation_32___amount() { return modulation_32__amount; }
        void set_modulation_32___amount(const double & value) { this->modulation_32__amount = value; }

        const double & get_modulation_32___bipolar() const { return modulation_32__bipolar; }
        double & get_mutable_modulation_32___bipolar() { return modulation_32__bipolar; }
        void set_modulation_32___bipolar(const double & value) { this->modulation_32__bipolar = value; }

        const double & get_modulation_32___bypass() const { return modulation_32__bypass; }
        double & get_mutable_modulation_32___bypass() { return modulation_32__bypass; }
        void set_modulation_32___bypass(const double & value) { this->modulation_32__bypass = value; }

        const double & get_modulation_32___power() const { return modulation_32__power; }
        double & get_mutable_modulation_32___power() { return modulation_32__power; }
        void set_modulation_32___power(const double & value) { this->modulation_32__power = value; }

        const double & get_modulation_32___stereo() const { return modulation_32__stereo; }
        double & get_mutable_modulation_32___stereo() { return modulation_32__stereo; }
        void set_modulation_32___stereo(const double & value) { this->modulation_32__stereo = value; }

        const double & get_modulation_33___amount() const { return modulation_33__amount; }
        double & get_mutable_modulation_33___amount() { return modulation_33__amount; }
        void set_modulation_33___amount(const double & value) { this->modulation_33__amount = value; }

        const double & get_modulation_33___bipolar() const { return modulation_33__bipolar; }
        double & get_mutable_modulation_33___bipolar() { return modulation_33__bipolar; }
        void set_modulation_33___bipolar(const double & value) { this->modulation_33__bipolar = value; }

        const double & get_modulation_33___bypass() const { return modulation_33__bypass; }
        double & get_mutable_modulation_33___bypass() { return modulation_33__bypass; }
        void set_modulation_33___bypass(const double & value) { this->modulation_33__bypass = value; }

        const double & get_modulation_33___power() const { return modulation_33__power; }
        double & get_mutable_modulation_33___power() { return modulation_33__power; }
        void set_modulation_33___power(const double & value) { this->modulation_33__power = value; }

        const double & get_modulation_33___stereo() const { return modulation_33__stereo; }
        double & get_mutable_modulation_33___stereo() { return modulation_33__stereo; }
        void set_modulation_33___stereo(const double & value) { this->modulation_33__stereo = value; }

        const double & get_modulation_34___amount() const { return modulation_34__amount; }
        double & get_mutable_modulation_34___amount() { return modulation_34__amount; }
        void set_modulation_34___amount(const double & value) { this->modulation_34__amount = value; }

        const double & get_modulation_34___bipolar() const { return modulation_34__bipolar; }
        double & get_mutable_modulation_34___bipolar() { return modulation_34__bipolar; }
        void set_modulation_34___bipolar(const double & value) { this->modulation_34__bipolar = value; }

        const double & get_modulation_34___bypass() const { return modulation_34__bypass; }
        double & get_mutable_modulation_34___bypass() { return modulation_34__bypass; }
        void set_modulation_34___bypass(const double & value) { this->modulation_34__bypass = value; }

        const double & get_modulation_34___power() const { return modulation_34__power; }
        double & get_mutable_modulation_34___power() { return modulation_34__power; }
        void set_modulation_34___power(const double & value) { this->modulation_34__power = value; }

        const double & get_modulation_34___stereo() const { return modulation_34__stereo; }
        double & get_mutable_modulation_34___stereo() { return modulation_34__stereo; }
        void set_modulation_34___stereo(const double & value) { this->modulation_34__stereo = value; }

        const double & get_modulation_35___amount() const { return modulation_35__amount; }
        double & get_mutable_modulation_35___amount() { return modulation_35__amount; }
        void set_modulation_35___amount(const double & value) { this->modulation_35__amount = value; }

        const double & get_modulation_35___bipolar() const { return modulation_35__bipolar; }
        double & get_mutable_modulation_35___bipolar() { return modulation_35__bipolar; }
        void set_modulation_35___bipolar(const double & value) { this->modulation_35__bipolar = value; }

        const double & get_modulation_35___bypass() const { return modulation_35__bypass; }
        double & get_mutable_modulation_35___bypass() { return modulation_35__bypass; }
        void set_modulation_35___bypass(const double & value) { this->modulation_35__bypass = value; }

        const double & get_modulation_35___power() const { return modulation_35__power; }
        double & get_mutable_modulation_35___power() { return modulation_35__power; }
        void set_modulation_35___power(const double & value) { this->modulation_35__power = value; }

        const double & get_modulation_35___stereo() const { return modulation_35__stereo; }
        double & get_mutable_modulation_35___stereo() { return modulation_35__stereo; }
        void set_modulation_35___stereo(const double & value) { this->modulation_35__stereo = value; }

        const double & get_modulation_36___amount() const { return modulation_36__amount; }
        double & get_mutable_modulation_36___amount() { return modulation_36__amount; }
        void set_modulation_36___amount(const double & value) { this->modulation_36__amount = value; }

        const double & get_modulation_36___bipolar() const { return modulation_36__bipolar; }
        double & get_mutable_modulation_36___bipolar() { return modulation_36__bipolar; }
        void set_modulation_36___bipolar(const double & value) { this->modulation_36__bipolar = value; }

        const double & get_modulation_36___bypass() const { return modulation_36__bypass; }
        double & get_mutable_modulation_36___bypass() { return modulation_36__bypass; }
        void set_modulation_36___bypass(const double & value) { this->modulation_36__bypass = value; }

        const double & get_modulation_36___power() const { return modulation_36__power; }
        double & get_mutable_modulation_36___power() { return modulation_36__power; }
        void set_modulation_36___power(const double & value) { this->modulation_36__power = value; }

        const double & get_modulation_36___stereo() const { return modulation_36__stereo; }
        double & get_mutable_modulation_36___stereo() { return modulation_36__stereo; }
        void set_modulation_36___stereo(const double & value) { this->modulation_36__stereo = value; }

        const double & get_modulation_37___amount() const { return modulation_37__amount; }
        double & get_mutable_modulation_37___amount() { return modulation_37__amount; }
        void set_modulation_37___amount(const double & value) { this->modulation_37__amount = value; }

        const double & get_modulation_37___bipolar() const { return modulation_37__bipolar; }
        double & get_mutable_modulation_37___bipolar() { return modulation_37__bipolar; }
        void set_modulation_37___bipolar(const double & value) { this->modulation_37__bipolar = value; }

        const double & get_modulation_37___bypass() const { return modulation_37__bypass; }
        double & get_mutable_modulation_37___bypass() { return modulation_37__bypass; }
        void set_modulation_37___bypass(const double & value) { this->modulation_37__bypass = value; }

        const double & get_modulation_37___power() const { return modulation_37__power; }
        double & get_mutable_modulation_37___power() { return modulation_37__power; }
        void set_modulation_37___power(const double & value) { this->modulation_37__power = value; }

        const double & get_modulation_37___stereo() const { return modulation_37__stereo; }
        double & get_mutable_modulation_37___stereo() { return modulation_37__stereo; }
        void set_modulation_37___stereo(const double & value) { this->modulation_37__stereo = value; }

        const double & get_modulation_38___amount() const { return modulation_38__amount; }
        double & get_mutable_modulation_38___amount() { return modulation_38__amount; }
        void set_modulation_38___amount(const double & value) { this->modulation_38__amount = value; }

        const double & get_modulation_38___bipolar() const { return modulation_38__bipolar; }
        double & get_mutable_modulation_38___bipolar() { return modulation_38__bipolar; }
        void set_modulation_38___bipolar(const double & value) { this->modulation_38__bipolar = value; }

        const double & get_modulation_38___bypass() const { return modulation_38__bypass; }
        double & get_mutable_modulation_38___bypass() { return modulation_38__bypass; }
        void set_modulation_38___bypass(const double & value) { this->modulation_38__bypass = value; }

        const double & get_modulation_38___power() const { return modulation_38__power; }
        double & get_mutable_modulation_38___power() { return modulation_38__power; }
        void set_modulation_38___power(const double & value) { this->modulation_38__power = value; }

        const double & get_modulation_38___stereo() const { return modulation_38__stereo; }
        double & get_mutable_modulation_38___stereo() { return modulation_38__stereo; }
        void set_modulation_38___stereo(const double & value) { this->modulation_38__stereo = value; }

        const double & get_modulation_39___amount() const { return modulation_39__amount; }
        double & get_mutable_modulation_39___amount() { return modulation_39__amount; }
        void set_modulation_39___amount(const double & value) { this->modulation_39__amount = value; }

        const double & get_modulation_39___bipolar() const { return modulation_39__bipolar; }
        double & get_mutable_modulation_39___bipolar() { return modulation_39__bipolar; }
        void set_modulation_39___bipolar(const double & value) { this->modulation_39__bipolar = value; }

        const double & get_modulation_39___bypass() const { return modulation_39__bypass; }
        double & get_mutable_modulation_39___bypass() { return modulation_39__bypass; }
        void set_modulation_39___bypass(const double & value) { this->modulation_39__bypass = value; }

        const double & get_modulation_39___power() const { return modulation_39__power; }
        double & get_mutable_modulation_39___power() { return modulation_39__power; }
        void set_modulation_39___power(const double & value) { this->modulation_39__power = value; }

        const double & get_modulation_39___stereo() const { return modulation_39__stereo; }
        double & get_mutable_modulation_39___stereo() { return modulation_39__stereo; }
        void set_modulation_39___stereo(const double & value) { this->modulation_39__stereo = value; }

        const double & get_modulation_3___amount() const { return modulation_3__amount; }
        double & get_mutable_modulation_3___amount() { return modulation_3__amount; }
        void set_modulation_3___amount(const double & value) { this->modulation_3__amount = value; }

        const double & get_modulation_3___bipolar() const { return modulation_3__bipolar; }
        double & get_mutable_modulation_3___bipolar() { return modulation_3__bipolar; }
        void set_modulation_3___bipolar(const double & value) { this->modulation_3__bipolar = value; }

        const double & get_modulation_3___bypass() const { return modulation_3__bypass; }
        double & get_mutable_modulation_3___bypass() { return modulation_3__bypass; }
        void set_modulation_3___bypass(const double & value) { this->modulation_3__bypass = value; }

        const double & get_modulation_3___power() const { return modulation_3__power; }
        double & get_mutable_modulation_3___power() { return modulation_3__power; }
        void set_modulation_3___power(const double & value) { this->modulation_3__power = value; }

        const double & get_modulation_3___stereo() const { return modulation_3__stereo; }
        double & get_mutable_modulation_3___stereo() { return modulation_3__stereo; }
        void set_modulation_3___stereo(const double & value) { this->modulation_3__stereo = value; }

        const double & get_modulation_40___amount() const { return modulation_40__amount; }
        double & get_mutable_modulation_40___amount() { return modulation_40__amount; }
        void set_modulation_40___amount(const double & value) { this->modulation_40__amount = value; }

        const double & get_modulation_40___bipolar() const { return modulation_40__bipolar; }
        double & get_mutable_modulation_40___bipolar() { return modulation_40__bipolar; }
        void set_modulation_40___bipolar(const double & value) { this->modulation_40__bipolar = value; }

        const double & get_modulation_40___bypass() const { return modulation_40__bypass; }
        double & get_mutable_modulation_40___bypass() { return modulation_40__bypass; }
        void set_modulation_40___bypass(const double & value) { this->modulation_40__bypass = value; }

        const double & get_modulation_40___power() const { return modulation_40__power; }
        double & get_mutable_modulation_40___power() { return modulation_40__power; }
        void set_modulation_40___power(const double & value) { this->modulation_40__power = value; }

        const double & get_modulation_40___stereo() const { return modulation_40__stereo; }
        double & get_mutable_modulation_40___stereo() { return modulation_40__stereo; }
        void set_modulation_40___stereo(const double & value) { this->modulation_40__stereo = value; }

        const double & get_modulation_41___amount() const { return modulation_41__amount; }
        double & get_mutable_modulation_41___amount() { return modulation_41__amount; }
        void set_modulation_41___amount(const double & value) { this->modulation_41__amount = value; }

        const double & get_modulation_41___bipolar() const { return modulation_41__bipolar; }
        double & get_mutable_modulation_41___bipolar() { return modulation_41__bipolar; }
        void set_modulation_41___bipolar(const double & value) { this->modulation_41__bipolar = value; }

        const double & get_modulation_41___bypass() const { return modulation_41__bypass; }
        double & get_mutable_modulation_41___bypass() { return modulation_41__bypass; }
        void set_modulation_41___bypass(const double & value) { this->modulation_41__bypass = value; }

        const double & get_modulation_41___power() const { return modulation_41__power; }
        double & get_mutable_modulation_41___power() { return modulation_41__power; }
        void set_modulation_41___power(const double & value) { this->modulation_41__power = value; }

        const double & get_modulation_41___stereo() const { return modulation_41__stereo; }
        double & get_mutable_modulation_41___stereo() { return modulation_41__stereo; }
        void set_modulation_41___stereo(const double & value) { this->modulation_41__stereo = value; }

        const double & get_modulation_42___amount() const { return modulation_42__amount; }
        double & get_mutable_modulation_42___amount() { return modulation_42__amount; }
        void set_modulation_42___amount(const double & value) { this->modulation_42__amount = value; }

        const double & get_modulation_42___bipolar() const { return modulation_42__bipolar; }
        double & get_mutable_modulation_42___bipolar() { return modulation_42__bipolar; }
        void set_modulation_42___bipolar(const double & value) { this->modulation_42__bipolar = value; }

        const double & get_modulation_42___bypass() const { return modulation_42__bypass; }
        double & get_mutable_modulation_42___bypass() { return modulation_42__bypass; }
        void set_modulation_42___bypass(const double & value) { this->modulation_42__bypass = value; }

        const double & get_modulation_42___power() const { return modulation_42__power; }
        double & get_mutable_modulation_42___power() { return modulation_42__power; }
        void set_modulation_42___power(const double & value) { this->modulation_42__power = value; }

        const double & get_modulation_42___stereo() const { return modulation_42__stereo; }
        double & get_mutable_modulation_42___stereo() { return modulation_42__stereo; }
        void set_modulation_42___stereo(const double & value) { this->modulation_42__stereo = value; }

        const double & get_modulation_43___amount() const { return modulation_43__amount; }
        double & get_mutable_modulation_43___amount() { return modulation_43__amount; }
        void set_modulation_43___amount(const double & value) { this->modulation_43__amount = value; }

        const double & get_modulation_43___bipolar() const { return modulation_43__bipolar; }
        double & get_mutable_modulation_43___bipolar() { return modulation_43__bipolar; }
        void set_modulation_43___bipolar(const double & value) { this->modulation_43__bipolar = value; }

        const double & get_modulation_43___bypass() const { return modulation_43__bypass; }
        double & get_mutable_modulation_43___bypass() { return modulation_43__bypass; }
        void set_modulation_43___bypass(const double & value) { this->modulation_43__bypass = value; }

        const double & get_modulation_43___power() const { return modulation_43__power; }
        double & get_mutable_modulation_43___power() { return modulation_43__power; }
        void set_modulation_43___power(const double & value) { this->modulation_43__power = value; }

        const double & get_modulation_43___stereo() const { return modulation_43__stereo; }
        double & get_mutable_modulation_43___stereo() { return modulation_43__stereo; }
        void set_modulation_43___stereo(const double & value) { this->modulation_43__stereo = value; }

        const double & get_modulation_44___amount() const { return modulation_44__amount; }
        double & get_mutable_modulation_44___amount() { return modulation_44__amount; }
        void set_modulation_44___amount(const double & value) { this->modulation_44__amount = value; }

        const double & get_modulation_44___bipolar() const { return modulation_44__bipolar; }
        double & get_mutable_modulation_44___bipolar() { return modulation_44__bipolar; }
        void set_modulation_44___bipolar(const double & value) { this->modulation_44__bipolar = value; }

        const double & get_modulation_44___bypass() const { return modulation_44__bypass; }
        double & get_mutable_modulation_44___bypass() { return modulation_44__bypass; }
        void set_modulation_44___bypass(const double & value) { this->modulation_44__bypass = value; }

        const double & get_modulation_44___power() const { return modulation_44__power; }
        double & get_mutable_modulation_44___power() { return modulation_44__power; }
        void set_modulation_44___power(const double & value) { this->modulation_44__power = value; }

        const double & get_modulation_44___stereo() const { return modulation_44__stereo; }
        double & get_mutable_modulation_44___stereo() { return modulation_44__stereo; }
        void set_modulation_44___stereo(const double & value) { this->modulation_44__stereo = value; }

        const double & get_modulation_45___amount() const { return modulation_45__amount; }
        double & get_mutable_modulation_45___amount() { return modulation_45__amount; }
        void set_modulation_45___amount(const double & value) { this->modulation_45__amount = value; }

        const double & get_modulation_45___bipolar() const { return modulation_45__bipolar; }
        double & get_mutable_modulation_45___bipolar() { return modulation_45__bipolar; }
        void set_modulation_45___bipolar(const double & value) { this->modulation_45__bipolar = value; }

        const double & get_modulation_45___bypass() const { return modulation_45__bypass; }
        double & get_mutable_modulation_45___bypass() { return modulation_45__bypass; }
        void set_modulation_45___bypass(const double & value) { this->modulation_45__bypass = value; }

        const double & get_modulation_45___power() const { return modulation_45__power; }
        double & get_mutable_modulation_45___power() { return modulation_45__power; }
        void set_modulation_45___power(const double & value) { this->modulation_45__power = value; }

        const double & get_modulation_45___stereo() const { return modulation_45__stereo; }
        double & get_mutable_modulation_45___stereo() { return modulation_45__stereo; }
        void set_modulation_45___stereo(const double & value) { this->modulation_45__stereo = value; }

        const double & get_modulation_46___amount() const { return modulation_46__amount; }
        double & get_mutable_modulation_46___amount() { return modulation_46__amount; }
        void set_modulation_46___amount(const double & value) { this->modulation_46__amount = value; }

        const double & get_modulation_46___bipolar() const { return modulation_46__bipolar; }
        double & get_mutable_modulation_46___bipolar() { return modulation_46__bipolar; }
        void set_modulation_46___bipolar(const double & value) { this->modulation_46__bipolar = value; }

        const double & get_modulation_46___bypass() const { return modulation_46__bypass; }
        double & get_mutable_modulation_46___bypass() { return modulation_46__bypass; }
        void set_modulation_46___bypass(const double & value) { this->modulation_46__bypass = value; }

        const double & get_modulation_46___power() const { return modulation_46__power; }
        double & get_mutable_modulation_46___power() { return modulation_46__power; }
        void set_modulation_46___power(const double & value) { this->modulation_46__power = value; }

        const double & get_modulation_46___stereo() const { return modulation_46__stereo; }
        double & get_mutable_modulation_46___stereo() { return modulation_46__stereo; }
        void set_modulation_46___stereo(const double & value) { this->modulation_46__stereo = value; }

        const double & get_modulation_47___amount() const { return modulation_47__amount; }
        double & get_mutable_modulation_47___amount() { return modulation_47__amount; }
        void set_modulation_47___amount(const double & value) { this->modulation_47__amount = value; }

        const double & get_modulation_47___bipolar() const { return modulation_47__bipolar; }
        double & get_mutable_modulation_47___bipolar() { return modulation_47__bipolar; }
        void set_modulation_47___bipolar(const double & value) { this->modulation_47__bipolar = value; }

        const double & get_modulation_47___bypass() const { return modulation_47__bypass; }
        double & get_mutable_modulation_47___bypass() { return modulation_47__bypass; }
        void set_modulation_47___bypass(const double & value) { this->modulation_47__bypass = value; }

        const double & get_modulation_47___power() const { return modulation_47__power; }
        double & get_mutable_modulation_47___power() { return modulation_47__power; }
        void set_modulation_47___power(const double & value) { this->modulation_47__power = value; }

        const double & get_modulation_47___stereo() const { return modulation_47__stereo; }
        double & get_mutable_modulation_47___stereo() { return modulation_47__stereo; }
        void set_modulation_47___stereo(const double & value) { this->modulation_47__stereo = value; }

        const double & get_modulation_48___amount() const { return modulation_48__amount; }
        double & get_mutable_modulation_48___amount() { return modulation_48__amount; }
        void set_modulation_48___amount(const double & value) { this->modulation_48__amount = value; }

        const double & get_modulation_48___bipolar() const { return modulation_48__bipolar; }
        double & get_mutable_modulation_48___bipolar() { return modulation_48__bipolar; }
        void set_modulation_48___bipolar(const double & value) { this->modulation_48__bipolar = value; }

        const double & get_modulation_48___bypass() const { return modulation_48__bypass; }
        double & get_mutable_modulation_48___bypass() { return modulation_48__bypass; }
        void set_modulation_48___bypass(const double & value) { this->modulation_48__bypass = value; }

        const double & get_modulation_48___power() const { return modulation_48__power; }
        double & get_mutable_modulation_48___power() { return modulation_48__power; }
        void set_modulation_48___power(const double & value) { this->modulation_48__power = value; }

        const double & get_modulation_48___stereo() const { return modulation_48__stereo; }
        double & get_mutable_modulation_48___stereo() { return modulation_48__stereo; }
        void set_modulation_48___stereo(const double & value) { this->modulation_48__stereo = value; }

        const double & get_modulation_49___amount() const { return modulation_49__amount; }
        double & get_mutable_modulation_49___amount() { return modulation_49__amount; }
        void set_modulation_49___amount(const double & value) { this->modulation_49__amount = value; }

        const double & get_modulation_49___bipolar() const { return modulation_49__bipolar; }
        double & get_mutable_modulation_49___bipolar() { return modulation_49__bipolar; }
        void set_modulation_49___bipolar(const double & value) { this->modulation_49__bipolar = value; }

        const double & get_modulation_49___bypass() const { return modulation_49__bypass; }
        double & get_mutable_modulation_49___bypass() { return modulation_49__bypass; }
        void set_modulation_49___bypass(const double & value) { this->modulation_49__bypass = value; }

        const double & get_modulation_49___power() const { return modulation_49__power; }
        double & get_mutable_modulation_49___power() { return modulation_49__power; }
        void set_modulation_49___power(const double & value) { this->modulation_49__power = value; }

        const double & get_modulation_49___stereo() const { return modulation_49__stereo; }
        double & get_mutable_modulation_49___stereo() { return modulation_49__stereo; }
        void set_modulation_49___stereo(const double & value) { this->modulation_49__stereo = value; }

        const double & get_modulation_4___amount() const { return modulation_4__amount; }
        double & get_mutable_modulation_4___amount() { return modulation_4__amount; }
        void set_modulation_4___amount(const double & value) { this->modulation_4__amount = value; }

        const double & get_modulation_4___bipolar() const { return modulation_4__bipolar; }
        double & get_mutable_modulation_4___bipolar() { return modulation_4__bipolar; }
        void set_modulation_4___bipolar(const double & value) { this->modulation_4__bipolar = value; }

        const double & get_modulation_4___bypass() const { return modulation_4__bypass; }
        double & get_mutable_modulation_4___bypass() { return modulation_4__bypass; }
        void set_modulation_4___bypass(const double & value) { this->modulation_4__bypass = value; }

        const double & get_modulation_4___power() const { return modulation_4__power; }
        double & get_mutable_modulation_4___power() { return modulation_4__power; }
        void set_modulation_4___power(const double & value) { this->modulation_4__power = value; }

        const double & get_modulation_4___stereo() const { return modulation_4__stereo; }
        double & get_mutable_modulation_4___stereo() { return modulation_4__stereo; }
        void set_modulation_4___stereo(const double & value) { this->modulation_4__stereo = value; }

        const double & get_modulation_50___amount() const { return modulation_50__amount; }
        double & get_mutable_modulation_50___amount() { return modulation_50__amount; }
        void set_modulation_50___amount(const double & value) { this->modulation_50__amount = value; }

        const double & get_modulation_50___bipolar() const { return modulation_50__bipolar; }
        double & get_mutable_modulation_50___bipolar() { return modulation_50__bipolar; }
        void set_modulation_50___bipolar(const double & value) { this->modulation_50__bipolar = value; }

        const double & get_modulation_50___bypass() const { return modulation_50__bypass; }
        double & get_mutable_modulation_50___bypass() { return modulation_50__bypass; }
        void set_modulation_50___bypass(const double & value) { this->modulation_50__bypass = value; }

        const double & get_modulation_50___power() const { return modulation_50__power; }
        double & get_mutable_modulation_50___power() { return modulation_50__power; }
        void set_modulation_50___power(const double & value) { this->modulation_50__power = value; }

        const double & get_modulation_50___stereo() const { return modulation_50__stereo; }
        double & get_mutable_modulation_50___stereo() { return modulation_50__stereo; }
        void set_modulation_50___stereo(const double & value) { this->modulation_50__stereo = value; }

        const double & get_modulation_51___amount() const { return modulation_51__amount; }
        double & get_mutable_modulation_51___amount() { return modulation_51__amount; }
        void set_modulation_51___amount(const double & value) { this->modulation_51__amount = value; }

        const double & get_modulation_51___bipolar() const { return modulation_51__bipolar; }
        double & get_mutable_modulation_51___bipolar() { return modulation_51__bipolar; }
        void set_modulation_51___bipolar(const double & value) { this->modulation_51__bipolar = value; }

        const double & get_modulation_51___bypass() const { return modulation_51__bypass; }
        double & get_mutable_modulation_51___bypass() { return modulation_51__bypass; }
        void set_modulation_51___bypass(const double & value) { this->modulation_51__bypass = value; }

        const double & get_modulation_51___power() const { return modulation_51__power; }
        double & get_mutable_modulation_51___power() { return modulation_51__power; }
        void set_modulation_51___power(const double & value) { this->modulation_51__power = value; }

        const double & get_modulation_51___stereo() const { return modulation_51__stereo; }
        double & get_mutable_modulation_51___stereo() { return modulation_51__stereo; }
        void set_modulation_51___stereo(const double & value) { this->modulation_51__stereo = value; }

        const double & get_modulation_52___amount() const { return modulation_52__amount; }
        double & get_mutable_modulation_52___amount() { return modulation_52__amount; }
        void set_modulation_52___amount(const double & value) { this->modulation_52__amount = value; }

        const double & get_modulation_52___bipolar() const { return modulation_52__bipolar; }
        double & get_mutable_modulation_52___bipolar() { return modulation_52__bipolar; }
        void set_modulation_52___bipolar(const double & value) { this->modulation_52__bipolar = value; }

        const double & get_modulation_52___bypass() const { return modulation_52__bypass; }
        double & get_mutable_modulation_52___bypass() { return modulation_52__bypass; }
        void set_modulation_52___bypass(const double & value) { this->modulation_52__bypass = value; }

        const double & get_modulation_52___power() const { return modulation_52__power; }
        double & get_mutable_modulation_52___power() { return modulation_52__power; }
        void set_modulation_52___power(const double & value) { this->modulation_52__power = value; }

        const double & get_modulation_52___stereo() const { return modulation_52__stereo; }
        double & get_mutable_modulation_52___stereo() { return modulation_52__stereo; }
        void set_modulation_52___stereo(const double & value) { this->modulation_52__stereo = value; }

        const double & get_modulation_53___amount() const { return modulation_53__amount; }
        double & get_mutable_modulation_53___amount() { return modulation_53__amount; }
        void set_modulation_53___amount(const double & value) { this->modulation_53__amount = value; }

        const double & get_modulation_53___bipolar() const { return modulation_53__bipolar; }
        double & get_mutable_modulation_53___bipolar() { return modulation_53__bipolar; }
        void set_modulation_53___bipolar(const double & value) { this->modulation_53__bipolar = value; }

        const double & get_modulation_53___bypass() const { return modulation_53__bypass; }
        double & get_mutable_modulation_53___bypass() { return modulation_53__bypass; }
        void set_modulation_53___bypass(const double & value) { this->modulation_53__bypass = value; }

        const double & get_modulation_53___power() const { return modulation_53__power; }
        double & get_mutable_modulation_53___power() { return modulation_53__power; }
        void set_modulation_53___power(const double & value) { this->modulation_53__power = value; }

        const double & get_modulation_53___stereo() const { return modulation_53__stereo; }
        double & get_mutable_modulation_53___stereo() { return modulation_53__stereo; }
        void set_modulation_53___stereo(const double & value) { this->modulation_53__stereo = value; }

        const double & get_modulation_54___amount() const { return modulation_54__amount; }
        double & get_mutable_modulation_54___amount() { return modulation_54__amount; }
        void set_modulation_54___amount(const double & value) { this->modulation_54__amount = value; }

        const double & get_modulation_54___bipolar() const { return modulation_54__bipolar; }
        double & get_mutable_modulation_54___bipolar() { return modulation_54__bipolar; }
        void set_modulation_54___bipolar(const double & value) { this->modulation_54__bipolar = value; }

        const double & get_modulation_54___bypass() const { return modulation_54__bypass; }
        double & get_mutable_modulation_54___bypass() { return modulation_54__bypass; }
        void set_modulation_54___bypass(const double & value) { this->modulation_54__bypass = value; }

        const double & get_modulation_54___power() const { return modulation_54__power; }
        double & get_mutable_modulation_54___power() { return modulation_54__power; }
        void set_modulation_54___power(const double & value) { this->modulation_54__power = value; }

        const double & get_modulation_54___stereo() const { return modulation_54__stereo; }
        double & get_mutable_modulation_54___stereo() { return modulation_54__stereo; }
        void set_modulation_54___stereo(const double & value) { this->modulation_54__stereo = value; }

        const double & get_modulation_55___amount() const { return modulation_55__amount; }
        double & get_mutable_modulation_55___amount() { return modulation_55__amount; }
        void set_modulation_55___amount(const double & value) { this->modulation_55__amount = value; }

        const double & get_modulation_55___bipolar() const { return modulation_55__bipolar; }
        double & get_mutable_modulation_55___bipolar() { return modulation_55__bipolar; }
        void set_modulation_55___bipolar(const double & value) { this->modulation_55__bipolar = value; }

        const double & get_modulation_55___bypass() const { return modulation_55__bypass; }
        double & get_mutable_modulation_55___bypass() { return modulation_55__bypass; }
        void set_modulation_55___bypass(const double & value) { this->modulation_55__bypass = value; }

        const double & get_modulation_55___power() const { return modulation_55__power; }
        double & get_mutable_modulation_55___power() { return modulation_55__power; }
        void set_modulation_55___power(const double & value) { this->modulation_55__power = value; }

        const double & get_modulation_55___stereo() const { return modulation_55__stereo; }
        double & get_mutable_modulation_55___stereo() { return modulation_55__stereo; }
        void set_modulation_55___stereo(const double & value) { this->modulation_55__stereo = value; }

        const double & get_modulation_56___amount() const { return modulation_56__amount; }
        double & get_mutable_modulation_56___amount() { return modulation_56__amount; }
        void set_modulation_56___amount(const double & value) { this->modulation_56__amount = value; }

        const double & get_modulation_56___bipolar() const { return modulation_56__bipolar; }
        double & get_mutable_modulation_56___bipolar() { return modulation_56__bipolar; }
        void set_modulation_56___bipolar(const double & value) { this->modulation_56__bipolar = value; }

        const double & get_modulation_56___bypass() const { return modulation_56__bypass; }
        double & get_mutable_modulation_56___bypass() { return modulation_56__bypass; }
        void set_modulation_56___bypass(const double & value) { this->modulation_56__bypass = value; }

        const double & get_modulation_56___power() const { return modulation_56__power; }
        double & get_mutable_modulation_56___power() { return modulation_56__power; }
        void set_modulation_56___power(const double & value) { this->modulation_56__power = value; }

        const double & get_modulation_56___stereo() const { return modulation_56__stereo; }
        double & get_mutable_modulation_56___stereo() { return modulation_56__stereo; }
        void set_modulation_56___stereo(const double & value) { this->modulation_56__stereo = value; }

        const double & get_modulation_57___amount() const { return modulation_57__amount; }
        double & get_mutable_modulation_57___amount() { return modulation_57__amount; }
        void set_modulation_57___amount(const double & value) { this->modulation_57__amount = value; }

        const double & get_modulation_57___bipolar() const { return modulation_57__bipolar; }
        double & get_mutable_modulation_57___bipolar() { return modulation_57__bipolar; }
        void set_modulation_57___bipolar(const double & value) { this->modulation_57__bipolar = value; }

        const double & get_modulation_57___bypass() const { return modulation_57__bypass; }
        double & get_mutable_modulation_57___bypass() { return modulation_57__bypass; }
        void set_modulation_57___bypass(const double & value) { this->modulation_57__bypass = value; }

        const double & get_modulation_57___power() const { return modulation_57__power; }
        double & get_mutable_modulation_57___power() { return modulation_57__power; }
        void set_modulation_57___power(const double & value) { this->modulation_57__power = value; }

        const double & get_modulation_57___stereo() const { return modulation_57__stereo; }
        double & get_mutable_modulation_57___stereo() { return modulation_57__stereo; }
        void set_modulation_57___stereo(const double & value) { this->modulation_57__stereo = value; }

        const double & get_modulation_58___amount() const { return modulation_58__amount; }
        double & get_mutable_modulation_58___amount() { return modulation_58__amount; }
        void set_modulation_58___amount(const double & value) { this->modulation_58__amount = value; }

        const double & get_modulation_58___bipolar() const { return modulation_58__bipolar; }
        double & get_mutable_modulation_58___bipolar() { return modulation_58__bipolar; }
        void set_modulation_58___bipolar(const double & value) { this->modulation_58__bipolar = value; }

        const double & get_modulation_58___bypass() const { return modulation_58__bypass; }
        double & get_mutable_modulation_58___bypass() { return modulation_58__bypass; }
        void set_modulation_58___bypass(const double & value) { this->modulation_58__bypass = value; }

        const double & get_modulation_58___power() const { return modulation_58__power; }
        double & get_mutable_modulation_58___power() { return modulation_58__power; }
        void set_modulation_58___power(const double & value) { this->modulation_58__power = value; }

        const double & get_modulation_58___stereo() const { return modulation_58__stereo; }
        double & get_mutable_modulation_58___stereo() { return modulation_58__stereo; }
        void set_modulation_58___stereo(const double & value) { this->modulation_58__stereo = value; }

        const double & get_modulation_59___amount() const { return modulation_59__amount; }
        double & get_mutable_modulation_59___amount() { return modulation_59__amount; }
        void set_modulation_59___amount(const double & value) { this->modulation_59__amount = value; }

        const double & get_modulation_59___bipolar() const { return modulation_59__bipolar; }
        double & get_mutable_modulation_59___bipolar() { return modulation_59__bipolar; }
        void set_modulation_59___bipolar(const double & value) { this->modulation_59__bipolar = value; }

        const double & get_modulation_59___bypass() const { return modulation_59__bypass; }
        double & get_mutable_modulation_59___bypass() { return modulation_59__bypass; }
        void set_modulation_59___bypass(const double & value) { this->modulation_59__bypass = value; }

        const double & get_modulation_59___power() const { return modulation_59__power; }
        double & get_mutable_modulation_59___power() { return modulation_59__power; }
        void set_modulation_59___power(const double & value) { this->modulation_59__power = value; }

        const double & get_modulation_59___stereo() const { return modulation_59__stereo; }
        double & get_mutable_modulation_59___stereo() { return modulation_59__stereo; }
        void set_modulation_59___stereo(const double & value) { this->modulation_59__stereo = value; }

        const double & get_modulation_5___amount() const { return modulation_5__amount; }
        double & get_mutable_modulation_5___amount() { return modulation_5__amount; }
        void set_modulation_5___amount(const double & value) { this->modulation_5__amount = value; }

        const double & get_modulation_5___bipolar() const { return modulation_5__bipolar; }
        double & get_mutable_modulation_5___bipolar() { return modulation_5__bipolar; }
        void set_modulation_5___bipolar(const double & value) { this->modulation_5__bipolar = value; }

        const double & get_modulation_5___bypass() const { return modulation_5__bypass; }
        double & get_mutable_modulation_5___bypass() { return modulation_5__bypass; }
        void set_modulation_5___bypass(const double & value) { this->modulation_5__bypass = value; }

        const double & get_modulation_5___power() const { return modulation_5__power; }
        double & get_mutable_modulation_5___power() { return modulation_5__power; }
        void set_modulation_5___power(const double & value) { this->modulation_5__power = value; }

        const double & get_modulation_5___stereo() const { return modulation_5__stereo; }
        double & get_mutable_modulation_5___stereo() { return modulation_5__stereo; }
        void set_modulation_5___stereo(const double & value) { this->modulation_5__stereo = value; }

        const double & get_modulation_60___amount() const { return modulation_60__amount; }
        double & get_mutable_modulation_60___amount() { return modulation_60__amount; }
        void set_modulation_60___amount(const double & value) { this->modulation_60__amount = value; }

        const double & get_modulation_60___bipolar() const { return modulation_60__bipolar; }
        double & get_mutable_modulation_60___bipolar() { return modulation_60__bipolar; }
        void set_modulation_60___bipolar(const double & value) { this->modulation_60__bipolar = value; }

        const double & get_modulation_60___bypass() const { return modulation_60__bypass; }
        double & get_mutable_modulation_60___bypass() { return modulation_60__bypass; }
        void set_modulation_60___bypass(const double & value) { this->modulation_60__bypass = value; }

        const double & get_modulation_60___power() const { return modulation_60__power; }
        double & get_mutable_modulation_60___power() { return modulation_60__power; }
        void set_modulation_60___power(const double & value) { this->modulation_60__power = value; }

        const double & get_modulation_60___stereo() const { return modulation_60__stereo; }
        double & get_mutable_modulation_60___stereo() { return modulation_60__stereo; }
        void set_modulation_60___stereo(const double & value) { this->modulation_60__stereo = value; }

        const double & get_modulation_61___amount() const { return modulation_61__amount; }
        double & get_mutable_modulation_61___amount() { return modulation_61__amount; }
        void set_modulation_61___amount(const double & value) { this->modulation_61__amount = value; }

        const double & get_modulation_61___bipolar() const { return modulation_61__bipolar; }
        double & get_mutable_modulation_61___bipolar() { return modulation_61__bipolar; }
        void set_modulation_61___bipolar(const double & value) { this->modulation_61__bipolar = value; }

        const double & get_modulation_61___bypass() const { return modulation_61__bypass; }
        double & get_mutable_modulation_61___bypass() { return modulation_61__bypass; }
        void set_modulation_61___bypass(const double & value) { this->modulation_61__bypass = value; }

        const double & get_modulation_61___power() const { return modulation_61__power; }
        double & get_mutable_modulation_61___power() { return modulation_61__power; }
        void set_modulation_61___power(const double & value) { this->modulation_61__power = value; }

        const double & get_modulation_61___stereo() const { return modulation_61__stereo; }
        double & get_mutable_modulation_61___stereo() { return modulation_61__stereo; }
        void set_modulation_61___stereo(const double & value) { this->modulation_61__stereo = value; }

        const double & get_modulation_62___amount() const { return modulation_62__amount; }
        double & get_mutable_modulation_62___amount() { return modulation_62__amount; }
        void set_modulation_62___amount(const double & value) { this->modulation_62__amount = value; }

        const double & get_modulation_62___bipolar() const { return modulation_62__bipolar; }
        double & get_mutable_modulation_62___bipolar() { return modulation_62__bipolar; }
        void set_modulation_62___bipolar(const double & value) { this->modulation_62__bipolar = value; }

        const double & get_modulation_62___bypass() const { return modulation_62__bypass; }
        double & get_mutable_modulation_62___bypass() { return modulation_62__bypass; }
        void set_modulation_62___bypass(const double & value) { this->modulation_62__bypass = value; }

        const double & get_modulation_62___power() const { return modulation_62__power; }
        double & get_mutable_modulation_62___power() { return modulation_62__power; }
        void set_modulation_62___power(const double & value) { this->modulation_62__power = value; }

        const double & get_modulation_62___stereo() const { return modulation_62__stereo; }
        double & get_mutable_modulation_62___stereo() { return modulation_62__stereo; }
        void set_modulation_62___stereo(const double & value) { this->modulation_62__stereo = value; }

        const double & get_modulation_63___amount() const { return modulation_63__amount; }
        double & get_mutable_modulation_63___amount() { return modulation_63__amount; }
        void set_modulation_63___amount(const double & value) { this->modulation_63__amount = value; }

        const double & get_modulation_63___bipolar() const { return modulation_63__bipolar; }
        double & get_mutable_modulation_63___bipolar() { return modulation_63__bipolar; }
        void set_modulation_63___bipolar(const double & value) { this->modulation_63__bipolar = value; }

        const double & get_modulation_63___bypass() const { return modulation_63__bypass; }
        double & get_mutable_modulation_63___bypass() { return modulation_63__bypass; }
        void set_modulation_63___bypass(const double & value) { this->modulation_63__bypass = value; }

        const double & get_modulation_63___power() const { return modulation_63__power; }
        double & get_mutable_modulation_63___power() { return modulation_63__power; }
        void set_modulation_63___power(const double & value) { this->modulation_63__power = value; }

        const double & get_modulation_63___stereo() const { return modulation_63__stereo; }
        double & get_mutable_modulation_63___stereo() { return modulation_63__stereo; }
        void set_modulation_63___stereo(const double & value) { this->modulation_63__stereo = value; }

        const double & get_modulation_64___amount() const { return modulation_64__amount; }
        double & get_mutable_modulation_64___amount() { return modulation_64__amount; }
        void set_modulation_64___amount(const double & value) { this->modulation_64__amount = value; }

        const double & get_modulation_64___bipolar() const { return modulation_64__bipolar; }
        double & get_mutable_modulation_64___bipolar() { return modulation_64__bipolar; }
        void set_modulation_64___bipolar(const double & value) { this->modulation_64__bipolar = value; }

        const double & get_modulation_64___bypass() const { return modulation_64__bypass; }
        double & get_mutable_modulation_64___bypass() { return modulation_64__bypass; }
        void set_modulation_64___bypass(const double & value) { this->modulation_64__bypass = value; }

        const double & get_modulation_64___power() const { return modulation_64__power; }
        double & get_mutable_modulation_64___power() { return modulation_64__power; }
        void set_modulation_64___power(const double & value) { this->modulation_64__power = value; }

        const double & get_modulation_64___stereo() const { return modulation_64__stereo; }
        double & get_mutable_modulation_64___stereo() { return modulation_64__stereo; }
        void set_modulation_64___stereo(const double & value) { this->modulation_64__stereo = value; }

        const double & get_modulation_6___amount() const { return modulation_6__amount; }
        double & get_mutable_modulation_6___amount() { return modulation_6__amount; }
        void set_modulation_6___amount(const double & value) { this->modulation_6__amount = value; }

        const double & get_modulation_6___bipolar() const { return modulation_6__bipolar; }
        double & get_mutable_modulation_6___bipolar() { return modulation_6__bipolar; }
        void set_modulation_6___bipolar(const double & value) { this->modulation_6__bipolar = value; }

        const double & get_modulation_6___bypass() const { return modulation_6__bypass; }
        double & get_mutable_modulation_6___bypass() { return modulation_6__bypass; }
        void set_modulation_6___bypass(const double & value) { this->modulation_6__bypass = value; }

        const double & get_modulation_6___power() const { return modulation_6__power; }
        double & get_mutable_modulation_6___power() { return modulation_6__power; }
        void set_modulation_6___power(const double & value) { this->modulation_6__power = value; }

        const double & get_modulation_6___stereo() const { return modulation_6__stereo; }
        double & get_mutable_modulation_6___stereo() { return modulation_6__stereo; }
        void set_modulation_6___stereo(const double & value) { this->modulation_6__stereo = value; }

        const double & get_modulation_7___amount() const { return modulation_7__amount; }
        double & get_mutable_modulation_7___amount() { return modulation_7__amount; }
        void set_modulation_7___amount(const double & value) { this->modulation_7__amount = value; }

        const double & get_modulation_7___bipolar() const { return modulation_7__bipolar; }
        double & get_mutable_modulation_7___bipolar() { return modulation_7__bipolar; }
        void set_modulation_7___bipolar(const double & value) { this->modulation_7__bipolar = value; }

        const double & get_modulation_7___bypass() const { return modulation_7__bypass; }
        double & get_mutable_modulation_7___bypass() { return modulation_7__bypass; }
        void set_modulation_7___bypass(const double & value) { this->modulation_7__bypass = value; }

        const double & get_modulation_7___power() const { return modulation_7__power; }
        double & get_mutable_modulation_7___power() { return modulation_7__power; }
        void set_modulation_7___power(const double & value) { this->modulation_7__power = value; }

        const double & get_modulation_7___stereo() const { return modulation_7__stereo; }
        double & get_mutable_modulation_7___stereo() { return modulation_7__stereo; }
        void set_modulation_7___stereo(const double & value) { this->modulation_7__stereo = value; }

        const double & get_modulation_8___amount() const { return modulation_8__amount; }
        double & get_mutable_modulation_8___amount() { return modulation_8__amount; }
        void set_modulation_8___amount(const double & value) { this->modulation_8__amount = value; }

        const double & get_modulation_8___bipolar() const { return modulation_8__bipolar; }
        double & get_mutable_modulation_8___bipolar() { return modulation_8__bipolar; }
        void set_modulation_8___bipolar(const double & value) { this->modulation_8__bipolar = value; }

        const double & get_modulation_8___bypass() const { return modulation_8__bypass; }
        double & get_mutable_modulation_8___bypass() { return modulation_8__bypass; }
        void set_modulation_8___bypass(const double & value) { this->modulation_8__bypass = value; }

        const double & get_modulation_8___power() const { return modulation_8__power; }
        double & get_mutable_modulation_8___power() { return modulation_8__power; }
        void set_modulation_8___power(const double & value) { this->modulation_8__power = value; }

        const double & get_modulation_8___stereo() const { return modulation_8__stereo; }
        double & get_mutable_modulation_8___stereo() { return modulation_8__stereo; }
        void set_modulation_8___stereo(const double & value) { this->modulation_8__stereo = value; }

        const double & get_modulation_9___amount() const { return modulation_9__amount; }
        double & get_mutable_modulation_9___amount() { return modulation_9__amount; }
        void set_modulation_9___amount(const double & value) { this->modulation_9__amount = value; }

        const double & get_modulation_9___bipolar() const { return modulation_9__bipolar; }
        double & get_mutable_modulation_9___bipolar() { return modulation_9__bipolar; }
        void set_modulation_9___bipolar(const double & value) { this->modulation_9__bipolar = value; }

        const double & get_modulation_9___bypass() const { return modulation_9__bypass; }
        double & get_mutable_modulation_9___bypass() { return modulation_9__bypass; }
        void set_modulation_9___bypass(const double & value) { this->modulation_9__bypass = value; }

        const double & get_modulation_9___power() const { return modulation_9__power; }
        double & get_mutable_modulation_9___power() { return modulation_9__power; }
        void set_modulation_9___power(const double & value) { this->modulation_9__power = value; }

        const double & get_modulation_9___stereo() const { return modulation_9__stereo; }
        double & get_mutable_modulation_9___stereo() { return modulation_9__stereo; }
        void set_modulation_9___stereo(const double & value) { this->modulation_9__stereo = value; }

        const std::vector<Modulation> & get_modulations() const { return modulations; }
        std::vector<Modulation> & get_mutable_modulations() { return modulations; }
        void set_modulations(const std::vector<Modulation> & value) { this->modulations = value; }

        const double & get_osc_1___destination() const { return osc_1__destination; }
        double & get_mutable_osc_1___destination() { return osc_1__destination; }
        void set_osc_1___destination(const double & value) { this->osc_1__destination = value; }

        const double & get_osc_1___detune_power() const { return osc_1__detune_power; }
        double & get_mutable_osc_1___detune_power() { return osc_1__detune_power; }
        void set_osc_1___detune_power(const double & value) { this->osc_1__detune_power = value; }

        const double & get_osc_1___detune_range() const { return osc_1__detune_range; }
        double & get_mutable_osc_1___detune_range() { return osc_1__detune_range; }
        void set_osc_1___detune_range(const double & value) { this->osc_1__detune_range = value; }

        const double & get_osc_1___distortion_amount() const { return osc_1__distortion_amount; }
        double & get_mutable_osc_1___distortion_amount() { return osc_1__distortion_amount; }
        void set_osc_1___distortion_amount(const double & value) { this->osc_1__distortion_amount = value; }

        const double & get_osc_1___distortion_phase() const { return osc_1__distortion_phase; }
        double & get_mutable_osc_1___distortion_phase() { return osc_1__distortion_phase; }
        void set_osc_1___distortion_phase(const double & value) { this->osc_1__distortion_phase = value; }

        const double & get_osc_1___distortion_spread() const { return osc_1__distortion_spread; }
        double & get_mutable_osc_1___distortion_spread() { return osc_1__distortion_spread; }
        void set_osc_1___distortion_spread(const double & value) { this->osc_1__distortion_spread = value; }

        const double & get_osc_1___distortion_type() const { return osc_1__distortion_type; }
        double & get_mutable_osc_1___distortion_type() { return osc_1__distortion_type; }
        void set_osc_1___distortion_type(const double & value) { this->osc_1__distortion_type = value; }

        const double & get_osc_1___frame_spread() const { return osc_1__frame_spread; }
        double & get_mutable_osc_1___frame_spread() { return osc_1__frame_spread; }
        void set_osc_1___frame_spread(const double & value) { this->osc_1__frame_spread = value; }

        const double & get_osc_1___level() const { return osc_1__level; }
        double & get_mutable_osc_1___level() { return osc_1__level; }
        void set_osc_1___level(const double & value) { this->osc_1__level = value; }

        const double & get_osc_1___midi_track() const { return osc_1__midi_track; }
        double & get_mutable_osc_1___midi_track() { return osc_1__midi_track; }
        void set_osc_1___midi_track(const double & value) { this->osc_1__midi_track = value; }

        const double & get_osc_1___on() const { return osc_1__on; }
        double & get_mutable_osc_1___on() { return osc_1__on; }
        void set_osc_1___on(const double & value) { this->osc_1__on = value; }

        const double & get_osc_1___pan() const { return osc_1__pan; }
        double & get_mutable_osc_1___pan() { return osc_1__pan; }
        void set_osc_1___pan(const double & value) { this->osc_1__pan = value; }

        const double & get_osc_1___phase() const { return osc_1__phase; }
        double & get_mutable_osc_1___phase() { return osc_1__phase; }
        void set_osc_1___phase(const double & value) { this->osc_1__phase = value; }

        const double & get_osc_1___random_phase() const { return osc_1__random_phase; }
        double & get_mutable_osc_1___random_phase() { return osc_1__random_phase; }
        void set_osc_1___random_phase(const double & value) { this->osc_1__random_phase = value; }

        const double & get_osc_1___smooth_interpolation() const { return osc_1__smooth_interpolation; }
        double & get_mutable_osc_1___smooth_interpolation() { return osc_1__smooth_interpolation; }
        void set_osc_1___smooth_interpolation(const double & value) { this->osc_1__smooth_interpolation = value; }

        const double & get_osc_1___spectral_morph_amount() const { return osc_1__spectral_morph_amount; }
        double & get_mutable_osc_1___spectral_morph_amount() { return osc_1__spectral_morph_amount; }
        void set_osc_1___spectral_morph_amount(const double & value) { this->osc_1__spectral_morph_amount = value; }

        const double & get_osc_1___spectral_morph_spread() const { return osc_1__spectral_morph_spread; }
        double & get_mutable_osc_1___spectral_morph_spread() { return osc_1__spectral_morph_spread; }
        void set_osc_1___spectral_morph_spread(const double & value) { this->osc_1__spectral_morph_spread = value; }

        const double & get_osc_1___spectral_morph_type() const { return osc_1__spectral_morph_type; }
        double & get_mutable_osc_1___spectral_morph_type() { return osc_1__spectral_morph_type; }
        void set_osc_1___spectral_morph_type(const double & value) { this->osc_1__spectral_morph_type = value; }

        const double & get_osc_1___spectral_unison() const { return osc_1__spectral_unison; }
        double & get_mutable_osc_1___spectral_unison() { return osc_1__spectral_unison; }
        void set_osc_1___spectral_unison(const double & value) { this->osc_1__spectral_unison = value; }

        const double & get_osc_1___stack_style() const { return osc_1__stack_style; }
        double & get_mutable_osc_1___stack_style() { return osc_1__stack_style; }
        void set_osc_1___stack_style(const double & value) { this->osc_1__stack_style = value; }

        const double & get_osc_1___stereo_spread() const { return osc_1__stereo_spread; }
        double & get_mutable_osc_1___stereo_spread() { return osc_1__stereo_spread; }
        void set_osc_1___stereo_spread(const double & value) { this->osc_1__stereo_spread = value; }

        const double & get_osc_1___transpose() const { return osc_1__transpose; }
        double & get_mutable_osc_1___transpose() { return osc_1__transpose; }
        void set_osc_1___transpose(const double & value) { this->osc_1__transpose = value; }

        const double & get_osc_1___transpose_quantize() const { return osc_1__transpose_quantize; }
        double & get_mutable_osc_1___transpose_quantize() { return osc_1__transpose_quantize; }
        void set_osc_1___transpose_quantize(const double & value) { this->osc_1__transpose_quantize = value; }

        const double & get_osc_1___tune() const { return osc_1__tune; }
        double & get_mutable_osc_1___tune() { return osc_1__tune; }
        void set_osc_1___tune(const double & value) { this->osc_1__tune = value; }

        const double & get_osc_1___unison_blend() const { return osc_1__unison_blend; }
        double & get_mutable_osc_1___unison_blend() { return osc_1__unison_blend; }
        void set_osc_1___unison_blend(const double & value) { this->osc_1__unison_blend = value; }

        const double & get_osc_1___unison_detune() const { return osc_1__unison_detune; }
        double & get_mutable_osc_1___unison_detune() { return osc_1__unison_detune; }
        void set_osc_1___unison_detune(const double & value) { this->osc_1__unison_detune = value; }

        const double & get_osc_1___unison_voices() const { return osc_1__unison_voices; }
        double & get_mutable_osc_1___unison_voices() { return osc_1__unison_voices; }
        void set_osc_1___unison_voices(const double & value) { this->osc_1__unison_voices = value; }

        const double & get_osc_1___view_2__d() const { return osc_1__view_2_d; }
        double & get_mutable_osc_1___view_2__d() { return osc_1__view_2_d; }
        void set_osc_1___view_2__d(const double & value) { this->osc_1__view_2_d = value; }

        const double & get_osc_1___wave_frame() const { return osc_1__wave_frame; }
        double & get_mutable_osc_1___wave_frame() { return osc_1__wave_frame; }
        void set_osc_1___wave_frame(const double & value) { this->osc_1__wave_frame = value; }

        const double & get_osc_2___destination() const { return osc_2__destination; }
        double & get_mutable_osc_2___destination() { return osc_2__destination; }
        void set_osc_2___destination(const double & value) { this->osc_2__destination = value; }

        const double & get_osc_2___detune_power() const { return osc_2__detune_power; }
        double & get_mutable_osc_2___detune_power() { return osc_2__detune_power; }
        void set_osc_2___detune_power(const double & value) { this->osc_2__detune_power = value; }

        const double & get_osc_2___detune_range() const { return osc_2__detune_range; }
        double & get_mutable_osc_2___detune_range() { return osc_2__detune_range; }
        void set_osc_2___detune_range(const double & value) { this->osc_2__detune_range = value; }

        const double & get_osc_2___distortion_amount() const { return osc_2__distortion_amount; }
        double & get_mutable_osc_2___distortion_amount() { return osc_2__distortion_amount; }
        void set_osc_2___distortion_amount(const double & value) { this->osc_2__distortion_amount = value; }

        const double & get_osc_2___distortion_phase() const { return osc_2__distortion_phase; }
        double & get_mutable_osc_2___distortion_phase() { return osc_2__distortion_phase; }
        void set_osc_2___distortion_phase(const double & value) { this->osc_2__distortion_phase = value; }

        const double & get_osc_2___distortion_spread() const { return osc_2__distortion_spread; }
        double & get_mutable_osc_2___distortion_spread() { return osc_2__distortion_spread; }
        void set_osc_2___distortion_spread(const double & value) { this->osc_2__distortion_spread = value; }

        const double & get_osc_2___distortion_type() const { return osc_2__distortion_type; }
        double & get_mutable_osc_2___distortion_type() { return osc_2__distortion_type; }
        void set_osc_2___distortion_type(const double & value) { this->osc_2__distortion_type = value; }

        const double & get_osc_2___frame_spread() const { return osc_2__frame_spread; }
        double & get_mutable_osc_2___frame_spread() { return osc_2__frame_spread; }
        void set_osc_2___frame_spread(const double & value) { this->osc_2__frame_spread = value; }

        const double & get_osc_2___level() const { return osc_2__level; }
        double & get_mutable_osc_2___level() { return osc_2__level; }
        void set_osc_2___level(const double & value) { this->osc_2__level = value; }

        const double & get_osc_2___midi_track() const { return osc_2__midi_track; }
        double & get_mutable_osc_2___midi_track() { return osc_2__midi_track; }
        void set_osc_2___midi_track(const double & value) { this->osc_2__midi_track = value; }

        const double & get_osc_2___on() const { return osc_2__on; }
        double & get_mutable_osc_2___on() { return osc_2__on; }
        void set_osc_2___on(const double & value) { this->osc_2__on = value; }

        const double & get_osc_2___pan() const { return osc_2__pan; }
        double & get_mutable_osc_2___pan() { return osc_2__pan; }
        void set_osc_2___pan(const double & value) { this->osc_2__pan = value; }

        const double & get_osc_2___phase() const { return osc_2__phase; }
        double & get_mutable_osc_2___phase() { return osc_2__phase; }
        void set_osc_2___phase(const double & value) { this->osc_2__phase = value; }

        const double & get_osc_2___random_phase() const { return osc_2__random_phase; }
        double & get_mutable_osc_2___random_phase() { return osc_2__random_phase; }
        void set_osc_2___random_phase(const double & value) { this->osc_2__random_phase = value; }

        const double & get_osc_2___smooth_interpolation() const { return osc_2__smooth_interpolation; }
        double & get_mutable_osc_2___smooth_interpolation() { return osc_2__smooth_interpolation; }
        void set_osc_2___smooth_interpolation(const double & value) { this->osc_2__smooth_interpolation = value; }

        const double & get_osc_2___spectral_morph_amount() const { return osc_2__spectral_morph_amount; }
        double & get_mutable_osc_2___spectral_morph_amount() { return osc_2__spectral_morph_amount; }
        void set_osc_2___spectral_morph_amount(const double & value) { this->osc_2__spectral_morph_amount = value; }

        const double & get_osc_2___spectral_morph_spread() const { return osc_2__spectral_morph_spread; }
        double & get_mutable_osc_2___spectral_morph_spread() { return osc_2__spectral_morph_spread; }
        void set_osc_2___spectral_morph_spread(const double & value) { this->osc_2__spectral_morph_spread = value; }

        const double & get_osc_2___spectral_morph_type() const { return osc_2__spectral_morph_type; }
        double & get_mutable_osc_2___spectral_morph_type() { return osc_2__spectral_morph_type; }
        void set_osc_2___spectral_morph_type(const double & value) { this->osc_2__spectral_morph_type = value; }

        const double & get_osc_2___spectral_unison() const { return osc_2__spectral_unison; }
        double & get_mutable_osc_2___spectral_unison() { return osc_2__spectral_unison; }
        void set_osc_2___spectral_unison(const double & value) { this->osc_2__spectral_unison = value; }

        const double & get_osc_2___stack_style() const { return osc_2__stack_style; }
        double & get_mutable_osc_2___stack_style() { return osc_2__stack_style; }
        void set_osc_2___stack_style(const double & value) { this->osc_2__stack_style = value; }

        const double & get_osc_2___stereo_spread() const { return osc_2__stereo_spread; }
        double & get_mutable_osc_2___stereo_spread() { return osc_2__stereo_spread; }
        void set_osc_2___stereo_spread(const double & value) { this->osc_2__stereo_spread = value; }

        const double & get_osc_2___transpose() const { return osc_2__transpose; }
        double & get_mutable_osc_2___transpose() { return osc_2__transpose; }
        void set_osc_2___transpose(const double & value) { this->osc_2__transpose = value; }

        const double & get_osc_2___transpose_quantize() const { return osc_2__transpose_quantize; }
        double & get_mutable_osc_2___transpose_quantize() { return osc_2__transpose_quantize; }
        void set_osc_2___transpose_quantize(const double & value) { this->osc_2__transpose_quantize = value; }

        const double & get_osc_2___tune() const { return osc_2__tune; }
        double & get_mutable_osc_2___tune() { return osc_2__tune; }
        void set_osc_2___tune(const double & value) { this->osc_2__tune = value; }

        const double & get_osc_2___unison_blend() const { return osc_2__unison_blend; }
        double & get_mutable_osc_2___unison_blend() { return osc_2__unison_blend; }
        void set_osc_2___unison_blend(const double & value) { this->osc_2__unison_blend = value; }

        const double & get_osc_2___unison_detune() const { return osc_2__unison_detune; }
        double & get_mutable_osc_2___unison_detune() { return osc_2__unison_detune; }
        void set_osc_2___unison_detune(const double & value) { this->osc_2__unison_detune = value; }

        const double & get_osc_2___unison_voices() const { return osc_2__unison_voices; }
        double & get_mutable_osc_2___unison_voices() { return osc_2__unison_voices; }
        void set_osc_2___unison_voices(const double & value) { this->osc_2__unison_voices = value; }

        const double & get_osc_2___view_2__d() const { return osc_2__view_2_d; }
        double & get_mutable_osc_2___view_2__d() { return osc_2__view_2_d; }
        void set_osc_2___view_2__d(const double & value) { this->osc_2__view_2_d = value; }

        const double & get_osc_2___wave_frame() const { return osc_2__wave_frame; }
        double & get_mutable_osc_2___wave_frame() { return osc_2__wave_frame; }
        void set_osc_2___wave_frame(const double & value) { this->osc_2__wave_frame = value; }

        const double & get_osc_3___destination() const { return osc_3__destination; }
        double & get_mutable_osc_3___destination() { return osc_3__destination; }
        void set_osc_3___destination(const double & value) { this->osc_3__destination = value; }

        const double & get_osc_3___detune_power() const { return osc_3__detune_power; }
        double & get_mutable_osc_3___detune_power() { return osc_3__detune_power; }
        void set_osc_3___detune_power(const double & value) { this->osc_3__detune_power = value; }

        const double & get_osc_3___detune_range() const { return osc_3__detune_range; }
        double & get_mutable_osc_3___detune_range() { return osc_3__detune_range; }
        void set_osc_3___detune_range(const double & value) { this->osc_3__detune_range = value; }

        const double & get_osc_3___distortion_amount() const { return osc_3__distortion_amount; }
        double & get_mutable_osc_3___distortion_amount() { return osc_3__distortion_amount; }
        void set_osc_3___distortion_amount(const double & value) { this->osc_3__distortion_amount = value; }

        const double & get_osc_3___distortion_phase() const { return osc_3__distortion_phase; }
        double & get_mutable_osc_3___distortion_phase() { return osc_3__distortion_phase; }
        void set_osc_3___distortion_phase(const double & value) { this->osc_3__distortion_phase = value; }

        const double & get_osc_3___distortion_spread() const { return osc_3__distortion_spread; }
        double & get_mutable_osc_3___distortion_spread() { return osc_3__distortion_spread; }
        void set_osc_3___distortion_spread(const double & value) { this->osc_3__distortion_spread = value; }

        const double & get_osc_3___distortion_type() const { return osc_3__distortion_type; }
        double & get_mutable_osc_3___distortion_type() { return osc_3__distortion_type; }
        void set_osc_3___distortion_type(const double & value) { this->osc_3__distortion_type = value; }

        const double & get_osc_3___frame_spread() const { return osc_3__frame_spread; }
        double & get_mutable_osc_3___frame_spread() { return osc_3__frame_spread; }
        void set_osc_3___frame_spread(const double & value) { this->osc_3__frame_spread = value; }

        const double & get_osc_3___level() const { return osc_3__level; }
        double & get_mutable_osc_3___level() { return osc_3__level; }
        void set_osc_3___level(const double & value) { this->osc_3__level = value; }

        const double & get_osc_3___midi_track() const { return osc_3__midi_track; }
        double & get_mutable_osc_3___midi_track() { return osc_3__midi_track; }
        void set_osc_3___midi_track(const double & value) { this->osc_3__midi_track = value; }

        const double & get_osc_3___on() const { return osc_3__on; }
        double & get_mutable_osc_3___on() { return osc_3__on; }
        void set_osc_3___on(const double & value) { this->osc_3__on = value; }

        const double & get_osc_3___pan() const { return osc_3__pan; }
        double & get_mutable_osc_3___pan() { return osc_3__pan; }
        void set_osc_3___pan(const double & value) { this->osc_3__pan = value; }

        const double & get_osc_3___phase() const { return osc_3__phase; }
        double & get_mutable_osc_3___phase() { return osc_3__phase; }
        void set_osc_3___phase(const double & value) { this->osc_3__phase = value; }

        const double & get_osc_3___random_phase() const { return osc_3__random_phase; }
        double & get_mutable_osc_3___random_phase() { return osc_3__random_phase; }
        void set_osc_3___random_phase(const double & value) { this->osc_3__random_phase = value; }

        const double & get_osc_3___smooth_interpolation() const { return osc_3__smooth_interpolation; }
        double & get_mutable_osc_3___smooth_interpolation() { return osc_3__smooth_interpolation; }
        void set_osc_3___smooth_interpolation(const double & value) { this->osc_3__smooth_interpolation = value; }

        const double & get_osc_3___spectral_morph_amount() const { return osc_3__spectral_morph_amount; }
        double & get_mutable_osc_3___spectral_morph_amount() { return osc_3__spectral_morph_amount; }
        void set_osc_3___spectral_morph_amount(const double & value) { this->osc_3__spectral_morph_amount = value; }

        const double & get_osc_3___spectral_morph_spread() const { return osc_3__spectral_morph_spread; }
        double & get_mutable_osc_3___spectral_morph_spread() { return osc_3__spectral_morph_spread; }
        void set_osc_3___spectral_morph_spread(const double & value) { this->osc_3__spectral_morph_spread = value; }

        const double & get_osc_3___spectral_morph_type() const { return osc_3__spectral_morph_type; }
        double & get_mutable_osc_3___spectral_morph_type() { return osc_3__spectral_morph_type; }
        void set_osc_3___spectral_morph_type(const double & value) { this->osc_3__spectral_morph_type = value; }

        const double & get_osc_3___spectral_unison() const { return osc_3__spectral_unison; }
        double & get_mutable_osc_3___spectral_unison() { return osc_3__spectral_unison; }
        void set_osc_3___spectral_unison(const double & value) { this->osc_3__spectral_unison = value; }

        const double & get_osc_3___stack_style() const { return osc_3__stack_style; }
        double & get_mutable_osc_3___stack_style() { return osc_3__stack_style; }
        void set_osc_3___stack_style(const double & value) { this->osc_3__stack_style = value; }

        const double & get_osc_3___stereo_spread() const { return osc_3__stereo_spread; }
        double & get_mutable_osc_3___stereo_spread() { return osc_3__stereo_spread; }
        void set_osc_3___stereo_spread(const double & value) { this->osc_3__stereo_spread = value; }

        const double & get_osc_3___transpose() const { return osc_3__transpose; }
        double & get_mutable_osc_3___transpose() { return osc_3__transpose; }
        void set_osc_3___transpose(const double & value) { this->osc_3__transpose = value; }

        const double & get_osc_3___transpose_quantize() const { return osc_3__transpose_quantize; }
        double & get_mutable_osc_3___transpose_quantize() { return osc_3__transpose_quantize; }
        void set_osc_3___transpose_quantize(const double & value) { this->osc_3__transpose_quantize = value; }

        const double & get_osc_3___tune() const { return osc_3__tune; }
        double & get_mutable_osc_3___tune() { return osc_3__tune; }
        void set_osc_3___tune(const double & value) { this->osc_3__tune = value; }

        const double & get_osc_3___unison_blend() const { return osc_3__unison_blend; }
        double & get_mutable_osc_3___unison_blend() { return osc_3__unison_blend; }
        void set_osc_3___unison_blend(const double & value) { this->osc_3__unison_blend = value; }

        const double & get_osc_3___unison_detune() const { return osc_3__unison_detune; }
        double & get_mutable_osc_3___unison_detune() { return osc_3__unison_detune; }
        void set_osc_3___unison_detune(const double & value) { this->osc_3__unison_detune = value; }

        const double & get_osc_3___unison_voices() const { return osc_3__unison_voices; }
        double & get_mutable_osc_3___unison_voices() { return osc_3__unison_voices; }
        void set_osc_3___unison_voices(const double & value) { this->osc_3__unison_voices = value; }

        const double & get_osc_3___view_2__d() const { return osc_3__view_2_d; }
        double & get_mutable_osc_3___view_2__d() { return osc_3__view_2_d; }
        void set_osc_3___view_2__d(const double & value) { this->osc_3__view_2_d = value; }

        const double & get_osc_3___wave_frame() const { return osc_3__wave_frame; }
        double & get_mutable_osc_3___wave_frame() { return osc_3__wave_frame; }
        void set_osc_3___wave_frame(const double & value) { this->osc_3__wave_frame = value; }

        const double & get_oversampling() const { return oversampling; }
        double & get_mutable_oversampling() { return oversampling; }
        void set_oversampling(const double & value) { this->oversampling = value; }

        const double & get_phaser_blend() const { return phaser_blend; }
        double & get_mutable_phaser_blend() { return phaser_blend; }
        void set_phaser_blend(const double & value) { this->phaser_blend = value; }

        const double & get_phaser_center() const { return phaser_center; }
        double & get_mutable_phaser_center() { return phaser_center; }
        void set_phaser_center(const double & value) { this->phaser_center = value; }

        const double & get_phaser_dry_wet() const { return phaser_dry_wet; }
        double & get_mutable_phaser_dry_wet() { return phaser_dry_wet; }
        void set_phaser_dry_wet(const double & value) { this->phaser_dry_wet = value; }

        const double & get_phaser_feedback() const { return phaser_feedback; }
        double & get_mutable_phaser_feedback() { return phaser_feedback; }
        void set_phaser_feedback(const double & value) { this->phaser_feedback = value; }

        const double & get_phaser_frequency() const { return phaser_frequency; }
        double & get_mutable_phaser_frequency() { return phaser_frequency; }
        void set_phaser_frequency(const double & value) { this->phaser_frequency = value; }

        const double & get_phaser_mod_depth() const { return phaser_mod_depth; }
        double & get_mutable_phaser_mod_depth() { return phaser_mod_depth; }
        void set_phaser_mod_depth(const double & value) { this->phaser_mod_depth = value; }

        const double & get_phaser_on() const { return phaser_on; }
        double & get_mutable_phaser_on() { return phaser_on; }
        void set_phaser_on(const double & value) { this->phaser_on = value; }

        const double & get_phaser_phase_offset() const { return phaser_phase_offset; }
        double & get_mutable_phaser_phase_offset() { return phaser_phase_offset; }
        void set_phaser_phase_offset(const double & value) { this->phaser_phase_offset = value; }

        const double & get_phaser_sync() const { return phaser_sync; }
        double & get_mutable_phaser_sync() { return phaser_sync; }
        void set_phaser_sync(const double & value) { this->phaser_sync = value; }

        const double & get_phaser_tempo() const { return phaser_tempo; }
        double & get_mutable_phaser_tempo() { return phaser_tempo; }
        void set_phaser_tempo(const double & value) { this->phaser_tempo = value; }

        const double & get_pitch_bend_range() const { return pitch_bend_range; }
        double & get_mutable_pitch_bend_range() { return pitch_bend_range; }
        void set_pitch_bend_range(const double & value) { this->pitch_bend_range = value; }

        const double & get_pitch_wheel() const { return pitch_wheel; }
        double & get_mutable_pitch_wheel() { return pitch_wheel; }
        void set_pitch_wheel(const double & value) { this->pitch_wheel = value; }

        const double & get_polyphony() const { return polyphony; }
        double & get_mutable_polyphony() { return polyphony; }
        void set_polyphony(const double & value) { this->polyphony = value; }

        const double & get_portamento_force() const { return portamento_force; }
        double & get_mutable_portamento_force() { return portamento_force; }
        void set_portamento_force(const double & value) { this->portamento_force = value; }

        const double & get_portamento_scale() const { return portamento_scale; }
        double & get_mutable_portamento_scale() { return portamento_scale; }
        void set_portamento_scale(const double & value) { this->portamento_scale = value; }

        const double & get_portamento_slope() const { return portamento_slope; }
        double & get_mutable_portamento_slope() { return portamento_slope; }
        void set_portamento_slope(const double & value) { this->portamento_slope = value; }

        const double & get_portamento_time() const { return portamento_time; }
        double & get_mutable_portamento_time() { return portamento_time; }
        void set_portamento_time(const double & value) { this->portamento_time = value; }

        const double & get_random_1___frequency() const { return random_1__frequency; }
        double & get_mutable_random_1___frequency() { return random_1__frequency; }
        void set_random_1___frequency(const double & value) { this->random_1__frequency = value; }

        std::shared_ptr<double> get_random_1___keytrack_transpose() const { return random_1__keytrack_transpose; }
        void set_random_1___keytrack_transpose(std::shared_ptr<double> value) { this->random_1__keytrack_transpose = value; }

        std::shared_ptr<double> get_random_1___keytrack_tune() const { return random_1__keytrack_tune; }
        void set_random_1___keytrack_tune(std::shared_ptr<double> value) { this->random_1__keytrack_tune = value; }

        const double & get_random_1___stereo() const { return random_1__stereo; }
        double & get_mutable_random_1___stereo() { return random_1__stereo; }
        void set_random_1___stereo(const double & value) { this->random_1__stereo = value; }

        const double & get_random_1___style() const { return random_1__style; }
        double & get_mutable_random_1___style() { return random_1__style; }
        void set_random_1___style(const double & value) { this->random_1__style = value; }

        const double & get_random_1___sync() const { return random_1__sync; }
        double & get_mutable_random_1___sync() { return random_1__sync; }
        void set_random_1___sync(const double & value) { this->random_1__sync = value; }

        const double & get_random_1___sync_type() const { return random_1__sync_type; }
        double & get_mutable_random_1___sync_type() { return random_1__sync_type; }
        void set_random_1___sync_type(const double & value) { this->random_1__sync_type = value; }

        const double & get_random_1___tempo() const { return random_1__tempo; }
        double & get_mutable_random_1___tempo() { return random_1__tempo; }
        void set_random_1___tempo(const double & value) { this->random_1__tempo = value; }

        const double & get_random_2___frequency() const { return random_2__frequency; }
        double & get_mutable_random_2___frequency() { return random_2__frequency; }
        void set_random_2___frequency(const double & value) { this->random_2__frequency = value; }

        std::shared_ptr<double> get_random_2___keytrack_transpose() const { return random_2__keytrack_transpose; }
        void set_random_2___keytrack_transpose(std::shared_ptr<double> value) { this->random_2__keytrack_transpose = value; }

        std::shared_ptr<double> get_random_2___keytrack_tune() const { return random_2__keytrack_tune; }
        void set_random_2___keytrack_tune(std::shared_ptr<double> value) { this->random_2__keytrack_tune = value; }

        const double & get_random_2___stereo() const { return random_2__stereo; }
        double & get_mutable_random_2___stereo() { return random_2__stereo; }
        void set_random_2___stereo(const double & value) { this->random_2__stereo = value; }

        const double & get_random_2___style() const { return random_2__style; }
        double & get_mutable_random_2___style() { return random_2__style; }
        void set_random_2___style(const double & value) { this->random_2__style = value; }

        const double & get_random_2___sync() const { return random_2__sync; }
        double & get_mutable_random_2___sync() { return random_2__sync; }
        void set_random_2___sync(const double & value) { this->random_2__sync = value; }

        const double & get_random_2___sync_type() const { return random_2__sync_type; }
        double & get_mutable_random_2___sync_type() { return random_2__sync_type; }
        void set_random_2___sync_type(const double & value) { this->random_2__sync_type = value; }

        const double & get_random_2___tempo() const { return random_2__tempo; }
        double & get_mutable_random_2___tempo() { return random_2__tempo; }
        void set_random_2___tempo(const double & value) { this->random_2__tempo = value; }

        const double & get_random_3___frequency() const { return random_3__frequency; }
        double & get_mutable_random_3___frequency() { return random_3__frequency; }
        void set_random_3___frequency(const double & value) { this->random_3__frequency = value; }

        std::shared_ptr<double> get_random_3___keytrack_transpose() const { return random_3__keytrack_transpose; }
        void set_random_3___keytrack_transpose(std::shared_ptr<double> value) { this->random_3__keytrack_transpose = value; }

        std::shared_ptr<double> get_random_3___keytrack_tune() const { return random_3__keytrack_tune; }
        void set_random_3___keytrack_tune(std::shared_ptr<double> value) { this->random_3__keytrack_tune = value; }

        const double & get_random_3___stereo() const { return random_3__stereo; }
        double & get_mutable_random_3___stereo() { return random_3__stereo; }
        void set_random_3___stereo(const double & value) { this->random_3__stereo = value; }

        const double & get_random_3___style() const { return random_3__style; }
        double & get_mutable_random_3___style() { return random_3__style; }
        void set_random_3___style(const double & value) { this->random_3__style = value; }

        const double & get_random_3___sync() const { return random_3__sync; }
        double & get_mutable_random_3___sync() { return random_3__sync; }
        void set_random_3___sync(const double & value) { this->random_3__sync = value; }

        const double & get_random_3___sync_type() const { return random_3__sync_type; }
        double & get_mutable_random_3___sync_type() { return random_3__sync_type; }
        void set_random_3___sync_type(const double & value) { this->random_3__sync_type = value; }

        const double & get_random_3___tempo() const { return random_3__tempo; }
        double & get_mutable_random_3___tempo() { return random_3__tempo; }
        void set_random_3___tempo(const double & value) { this->random_3__tempo = value; }

        const double & get_random_4___frequency() const { return random_4__frequency; }
        double & get_mutable_random_4___frequency() { return random_4__frequency; }
        void set_random_4___frequency(const double & value) { this->random_4__frequency = value; }

        std::shared_ptr<double> get_random_4___keytrack_transpose() const { return random_4__keytrack_transpose; }
        void set_random_4___keytrack_transpose(std::shared_ptr<double> value) { this->random_4__keytrack_transpose = value; }

        std::shared_ptr<double> get_random_4___keytrack_tune() const { return random_4__keytrack_tune; }
        void set_random_4___keytrack_tune(std::shared_ptr<double> value) { this->random_4__keytrack_tune = value; }

        const double & get_random_4___stereo() const { return random_4__stereo; }
        double & get_mutable_random_4___stereo() { return random_4__stereo; }
        void set_random_4___stereo(const double & value) { this->random_4__stereo = value; }

        const double & get_random_4___style() const { return random_4__style; }
        double & get_mutable_random_4___style() { return random_4__style; }
        void set_random_4___style(const double & value) { this->random_4__style = value; }

        const double & get_random_4___sync() const { return random_4__sync; }
        double & get_mutable_random_4___sync() { return random_4__sync; }
        void set_random_4___sync(const double & value) { this->random_4__sync = value; }

        const double & get_random_4___sync_type() const { return random_4__sync_type; }
        double & get_mutable_random_4___sync_type() { return random_4__sync_type; }
        void set_random_4___sync_type(const double & value) { this->random_4__sync_type = value; }

        const double & get_random_4___tempo() const { return random_4__tempo; }
        double & get_mutable_random_4___tempo() { return random_4__tempo; }
        void set_random_4___tempo(const double & value) { this->random_4__tempo = value; }

        const double & get_reverb_chorus_amount() const { return reverb_chorus_amount; }
        double & get_mutable_reverb_chorus_amount() { return reverb_chorus_amount; }
        void set_reverb_chorus_amount(const double & value) { this->reverb_chorus_amount = value; }

        const double & get_reverb_chorus_frequency() const { return reverb_chorus_frequency; }
        double & get_mutable_reverb_chorus_frequency() { return reverb_chorus_frequency; }
        void set_reverb_chorus_frequency(const double & value) { this->reverb_chorus_frequency = value; }

        const double & get_reverb_decay_time() const { return reverb_decay_time; }
        double & get_mutable_reverb_decay_time() { return reverb_decay_time; }
        void set_reverb_decay_time(const double & value) { this->reverb_decay_time = value; }

        std::shared_ptr<double> get_reverb_delay() const { return reverb_delay; }
        void set_reverb_delay(std::shared_ptr<double> value) { this->reverb_delay = value; }

        const double & get_reverb_dry_wet() const { return reverb_dry_wet; }
        double & get_mutable_reverb_dry_wet() { return reverb_dry_wet; }
        void set_reverb_dry_wet(const double & value) { this->reverb_dry_wet = value; }

        const double & get_reverb_high_shelf_cutoff() const { return reverb_high_shelf_cutoff; }
        double & get_mutable_reverb_high_shelf_cutoff() { return reverb_high_shelf_cutoff; }
        void set_reverb_high_shelf_cutoff(const double & value) { this->reverb_high_shelf_cutoff = value; }

        const double & get_reverb_high_shelf_gain() const { return reverb_high_shelf_gain; }
        double & get_mutable_reverb_high_shelf_gain() { return reverb_high_shelf_gain; }
        void set_reverb_high_shelf_gain(const double & value) { this->reverb_high_shelf_gain = value; }

        const double & get_reverb_low_shelf_cutoff() const { return reverb_low_shelf_cutoff; }
        double & get_mutable_reverb_low_shelf_cutoff() { return reverb_low_shelf_cutoff; }
        void set_reverb_low_shelf_cutoff(const double & value) { this->reverb_low_shelf_cutoff = value; }

        const double & get_reverb_low_shelf_gain() const { return reverb_low_shelf_gain; }
        double & get_mutable_reverb_low_shelf_gain() { return reverb_low_shelf_gain; }
        void set_reverb_low_shelf_gain(const double & value) { this->reverb_low_shelf_gain = value; }

        const double & get_reverb_on() const { return reverb_on; }
        double & get_mutable_reverb_on() { return reverb_on; }
        void set_reverb_on(const double & value) { this->reverb_on = value; }

        const double & get_reverb_pre_high_cutoff() const { return reverb_pre_high_cutoff; }
        double & get_mutable_reverb_pre_high_cutoff() { return reverb_pre_high_cutoff; }
        void set_reverb_pre_high_cutoff(const double & value) { this->reverb_pre_high_cutoff = value; }

        const double & get_reverb_pre_low_cutoff() const { return reverb_pre_low_cutoff; }
        double & get_mutable_reverb_pre_low_cutoff() { return reverb_pre_low_cutoff; }
        void set_reverb_pre_low_cutoff(const double & value) { this->reverb_pre_low_cutoff = value; }

        const double & get_reverb_size() const { return reverb_size; }
        double & get_mutable_reverb_size() { return reverb_size; }
        void set_reverb_size(const double & value) { this->reverb_size = value; }

        const Sample & get_sample() const { return sample; }
        Sample & get_mutable_sample() { return sample; }
        void set_sample(const Sample & value) { this->sample = value; }

        std::shared_ptr<double> get_sample_bounce() const { return sample_bounce; }
        void set_sample_bounce(std::shared_ptr<double> value) { this->sample_bounce = value; }

        const double & get_sample_destination() const { return sample_destination; }
        double & get_mutable_sample_destination() { return sample_destination; }
        void set_sample_destination(const double & value) { this->sample_destination = value; }

        const double & get_sample_keytrack() const { return sample_keytrack; }
        double & get_mutable_sample_keytrack() { return sample_keytrack; }
        void set_sample_keytrack(const double & value) { this->sample_keytrack = value; }

        const double & get_sample_level() const { return sample_level; }
        double & get_mutable_sample_level() { return sample_level; }
        void set_sample_level(const double & value) { this->sample_level = value; }

        const double & get_sample_loop() const { return sample_loop; }
        double & get_mutable_sample_loop() { return sample_loop; }
        void set_sample_loop(const double & value) { this->sample_loop = value; }

        const double & get_sample_on() const { return sample_on; }
        double & get_mutable_sample_on() { return sample_on; }
        void set_sample_on(const double & value) { this->sample_on = value; }

        const double & get_sample_pan() const { return sample_pan; }
        double & get_mutable_sample_pan() { return sample_pan; }
        void set_sample_pan(const double & value) { this->sample_pan = value; }

        const double & get_sample_random_phase() const { return sample_random_phase; }
        double & get_mutable_sample_random_phase() { return sample_random_phase; }
        void set_sample_random_phase(const double & value) { this->sample_random_phase = value; }

        const double & get_sample_transpose() const { return sample_transpose; }
        double & get_mutable_sample_transpose() { return sample_transpose; }
        void set_sample_transpose(const double & value) { this->sample_transpose = value; }

        const double & get_sample_transpose_quantize() const { return sample_transpose_quantize; }
        double & get_mutable_sample_transpose_quantize() { return sample_transpose_quantize; }
        void set_sample_transpose_quantize(const double & value) { this->sample_transpose_quantize = value; }

        const double & get_sample_tune() const { return sample_tune; }
        double & get_mutable_sample_tune() { return sample_tune; }
        void set_sample_tune(const double & value) { this->sample_tune = value; }

        std::shared_ptr<double> get_stereo_mode() const { return stereo_mode; }
        void set_stereo_mode(std::shared_ptr<double> value) { this->stereo_mode = value; }

        const double & get_stereo_routing() const { return stereo_routing; }
        double & get_mutable_stereo_routing() { return stereo_routing; }
        void set_stereo_routing(const double & value) { this->stereo_routing = value; }

        const double & get_velocity_track() const { return velocity_track; }
        double & get_mutable_velocity_track() { return velocity_track; }
        void set_velocity_track(const double & value) { this->velocity_track = value; }

        std::shared_ptr<double> get_view_spectrogram() const { return view_spectrogram; }
        void set_view_spectrogram(std::shared_ptr<double> value) { this->view_spectrogram = value; }

        const double & get_voice_amplitude() const { return voice_amplitude; }
        double & get_mutable_voice_amplitude() { return voice_amplitude; }
        void set_voice_amplitude(const double & value) { this->voice_amplitude = value; }

        std::shared_ptr<double> get_voice_override() const { return voice_override; }
        void set_voice_override(std::shared_ptr<double> value) { this->voice_override = value; }

        const double & get_voice_priority() const { return voice_priority; }
        double & get_mutable_voice_priority() { return voice_priority; }
        void set_voice_priority(const double & value) { this->voice_priority = value; }

        std::shared_ptr<double> get_voice_transpose() const { return voice_transpose; }
        void set_voice_transpose(std::shared_ptr<double> value) { this->voice_transpose = value; }

        const double & get_voice_tune() const { return voice_tune; }
        double & get_mutable_voice_tune() { return voice_tune; }
        void set_voice_tune(const double & value) { this->voice_tune = value; }

        const double & get_volume() const { return volume; }
        double & get_mutable_volume() { return volume; }
        void set_volume(const double & value) { this->volume = value; }

        const std::vector<Wavetable> & get_wavetables() const { return wavetables; }
        std::vector<Wavetable> & get_mutable_wavetables() { return wavetables; }
        void set_wavetables(const std::vector<Wavetable> & value) { this->wavetables = value; }
    };

    class VitalPreset {
        public:
        VitalPreset() = default;
        virtual ~VitalPreset() = default;

        private:
        std::string author;
        std::string comments;
        std::string macro1;
        std::string macro2;
        std::string macro3;
        std::string macro4;
        std::shared_ptr<std::string> preset_name;
        PresetStyle preset_style;
        PresetSettings settings;
        std::string synth_version;

        public:
        const std::string & get_author() const { return author; }
        std::string & get_mutable_author() { return author; }
        void set_author(const std::string & value) { this->author = value; }

        const std::string & get_comments() const { return comments; }
        std::string & get_mutable_comments() { return comments; }
        void set_comments(const std::string & value) { this->comments = value; }

        const std::string & get_macro1() const { return macro1; }
        std::string & get_mutable_macro1() { return macro1; }
        void set_macro1(const std::string & value) { this->macro1 = value; }

        const std::string & get_macro2() const { return macro2; }
        std::string & get_mutable_macro2() { return macro2; }
        void set_macro2(const std::string & value) { this->macro2 = value; }

        const std::string & get_macro3() const { return macro3; }
        std::string & get_mutable_macro3() { return macro3; }
        void set_macro3(const std::string & value) { this->macro3 = value; }

        const std::string & get_macro4() const { return macro4; }
        std::string & get_mutable_macro4() { return macro4; }
        void set_macro4(const std::string & value) { this->macro4 = value; }

        std::shared_ptr<std::string> get_preset_name() const { return preset_name; }
        void set_preset_name(std::shared_ptr<std::string> value) { this->preset_name = value; }

        const PresetStyle & get_preset_style() const { return preset_style; }
        PresetStyle & get_mutable_preset_style() { return preset_style; }
        void set_preset_style(const PresetStyle & value) { this->preset_style = value; }

        const PresetSettings & get_settings() const { return settings; }
        PresetSettings & get_mutable_settings() { return settings; }
        void set_settings(const PresetSettings & value) { this->settings = value; }

        const std::string & get_synth_version() const { return synth_version; }
        std::string & get_mutable_synth_version() { return synth_version; }
        void set_synth_version(const std::string & value) { this->synth_version = value; }
    };
}

namespace nlohmann {
    void from_json(const json & j, quicktype::Lfo & x);
    void to_json(json & j, const quicktype::Lfo & x);

    void from_json(const json & j, quicktype::Modulation & x);
    void to_json(json & j, const quicktype::Modulation & x);

    void from_json(const json & j, quicktype::Sample & x);
    void to_json(json & j, const quicktype::Sample & x);

    void from_json(const json & j, quicktype::Keyframe & x);
    void to_json(json & j, const quicktype::Keyframe & x);

    void from_json(const json & j, quicktype::Component & x);
    void to_json(json & j, const quicktype::Component & x);

    void from_json(const json & j, quicktype::Group & x);
    void to_json(json & j, const quicktype::Group & x);

    void from_json(const json & j, quicktype::Wavetable & x);
    void to_json(json & j, const quicktype::Wavetable & x);

    void from_json(const json & j, quicktype::PresetSettings & x);
    void to_json(json & j, const quicktype::PresetSettings & x);

    void from_json(const json & j, quicktype::VitalPreset & x);
    void to_json(json & j, const quicktype::VitalPreset & x);

    void from_json(const json & j, quicktype::PresetStyle & x);
    void to_json(json & j, const quicktype::PresetStyle & x);

    void from_json(const json & j, quicktype::Source & x);
    void to_json(json & j, const quicktype::Source & x);

    void from_json(const json & j, quicktype::Type & x);
    void to_json(json & j, const quicktype::Type & x);

    inline void from_json(const json & j, quicktype::Lfo& x) {
        x.set_name(j.at("name").get<std::string>());
        x.set_num_points(j.at("num_points").get<double>());
        x.set_points(j.at("points").get<std::vector<double>>());
        x.set_powers(j.at("powers").get<std::vector<double>>());
        x.set_smooth(j.at("smooth").get<bool>());
    }

    inline void to_json(json & j, const quicktype::Lfo & x) {
        j = json::object();
        j["name"] = x.get_name();
        j["num_points"] = x.get_num_points();
        j["points"] = x.get_points();
        j["powers"] = x.get_powers();
        j["smooth"] = x.get_smooth();
    }

    inline void from_json(const json & j, quicktype::Modulation& x) {
        x.set_destination(j.at("destination").get<std::string>());
        x.set_line_mapping(quicktype::get_optional<quicktype::Lfo>(j, "line_mapping"));
        x.set_source(j.at("source").get<quicktype::Source>());
    }

    inline void to_json(json & j, const quicktype::Modulation & x) {
        j = json::object();
        j["destination"] = x.get_destination();
        j["line_mapping"] = x.get_line_mapping();
        j["source"] = x.get_source();
    }

    inline void from_json(const json & j, quicktype::Sample& x) {
        x.set_length(j.at("length").get<double>());
        x.set_name(j.at("name").get<std::string>());
        x.set_sample_rate(j.at("sample_rate").get<double>());
        x.set_samples(j.at("samples").get<std::string>());
        x.set_samples_stereo(quicktype::get_optional<std::string>(j, "samples_stereo"));
    }

    inline void to_json(json & j, const quicktype::Sample & x) {
        j = json::object();
        j["length"] = x.get_length();
        j["name"] = x.get_name();
        j["sample_rate"] = x.get_sample_rate();
        j["samples"] = x.get_samples();
        j["samples_stereo"] = x.get_samples_stereo();
    }

    inline void from_json(const json & j, quicktype::Keyframe& x) {
        x.set_cutoff(quicktype::get_optional<double>(j, "cutoff"));
        x.set_down_run_rise(quicktype::get_optional<double>(j, "down_run_rise"));
        x.set_fold_boost(quicktype::get_optional<double>(j, "fold_boost"));
        x.set_horizontal_power(quicktype::get_optional<double>(j, "horizontal_power"));
        x.set_left_position(quicktype::get_optional<double>(j, "left_position"));
        x.set_line(quicktype::get_optional<quicktype::Lfo>(j, "line"));
        x.set_mix(quicktype::get_optional<double>(j, "mix"));
        x.set_phase(quicktype::get_optional<double>(j, "phase"));
        x.set_position(j.at("position").get<double>());
        x.set_pull_power(quicktype::get_optional<double>(j, "pull_power"));
        x.set_right_position(quicktype::get_optional<double>(j, "right_position"));
        x.set_shape(quicktype::get_optional<double>(j, "shape"));
        x.set_start_position(quicktype::get_optional<double>(j, "start_position"));
        x.set_up_run_rise(quicktype::get_optional<double>(j, "up_run_rise"));
        x.set_vertical_power(quicktype::get_optional<double>(j, "vertical_power"));
        x.set_wave_data(quicktype::get_optional<std::string>(j, "wave_data"));
        x.set_window_fade(quicktype::get_optional<double>(j, "window_fade"));
        x.set_window_size(quicktype::get_optional<double>(j, "window_size"));
    }

    inline void to_json(json & j, const quicktype::Keyframe & x) {
        j = json::object();
        j["cutoff"] = x.get_cutoff();
        j["down_run_rise"] = x.get_down_run_rise();
        j["fold_boost"] = x.get_fold_boost();
        j["horizontal_power"] = x.get_horizontal_power();
        j["left_position"] = x.get_left_position();
        j["line"] = x.get_line();
        j["mix"] = x.get_mix();
        j["phase"] = x.get_phase();
        j["position"] = x.get_position();
        j["pull_power"] = x.get_pull_power();
        j["right_position"] = x.get_right_position();
        j["shape"] = x.get_shape();
        j["start_position"] = x.get_start_position();
        j["up_run_rise"] = x.get_up_run_rise();
        j["vertical_power"] = x.get_vertical_power();
        j["wave_data"] = x.get_wave_data();
        j["window_fade"] = x.get_window_fade();
        j["window_size"] = x.get_window_size();
    }

    inline void from_json(const json & j, quicktype::Component& x) {
        x.set_audio_file(quicktype::get_optional<std::string>(j, "audio_file"));
        x.set_audio_sample_rate(quicktype::get_optional<double>(j, "audio_sample_rate"));
        x.set_fade_style(quicktype::get_optional<double>(j, "fade_style"));
        x.set_horizontal_asymmetric(quicktype::get_optional<bool>(j, "horizontal_asymmetric"));
        x.set_interpolation(quicktype::get_optional<double>(j, "interpolation"));
        x.set_interpolation_style(j.at("interpolation_style").get<double>());
        x.set_keyframes(quicktype::get_optional<std::vector<quicktype::Keyframe>>(j, "keyframes"));
        x.set_normalize(quicktype::get_optional<bool>(j, "normalize"));
        x.set_normalize_gain(quicktype::get_optional<bool>(j, "normalize_gain"));
        x.set_normalize_mult(quicktype::get_optional<bool>(j, "normalize_mult"));
        x.set_num_points(quicktype::get_optional<double>(j, "num_points"));
        x.set_phase_style(quicktype::get_optional<double>(j, "phase_style"));
        x.set_random_seed(quicktype::get_optional<double>(j, "random_seed"));
        x.set_style(quicktype::get_optional<double>(j, "style"));
        x.set_type(j.at("type").get<quicktype::Type>());
        x.set_vertical_asymmetric(quicktype::get_optional<bool>(j, "vertical_asymmetric"));
        x.set_window_shape(quicktype::get_optional<double>(j, "window_shape"));
        x.set_window_size(quicktype::get_optional<double>(j, "window_size"));
    }

    inline void to_json(json & j, const quicktype::Component & x) {
        j = json::object();
        j["audio_file"] = x.get_audio_file();
        j["audio_sample_rate"] = x.get_audio_sample_rate();
        j["fade_style"] = x.get_fade_style();
        j["horizontal_asymmetric"] = x.get_horizontal_asymmetric();
        j["interpolation"] = x.get_interpolation();
        j["interpolation_style"] = x.get_interpolation_style();
        j["keyframes"] = x.get_keyframes();
        j["normalize"] = x.get_normalize();
        j["normalize_gain"] = x.get_normalize_gain();
        j["normalize_mult"] = x.get_normalize_mult();
        j["num_points"] = x.get_num_points();
        j["phase_style"] = x.get_phase_style();
        j["random_seed"] = x.get_random_seed();
        j["style"] = x.get_style();
        j["type"] = x.get_type();
        j["vertical_asymmetric"] = x.get_vertical_asymmetric();
        j["window_shape"] = x.get_window_shape();
        j["window_size"] = x.get_window_size();
    }

    inline void from_json(const json & j, quicktype::Group& x) {
        x.set_components(j.at("components").get<std::vector<quicktype::Component>>());
    }

    inline void to_json(json & j, const quicktype::Group & x) {
        j = json::object();
        j["components"] = x.get_components();
    }

    inline void from_json(const json & j, quicktype::Wavetable& x) {
        x.set_author(quicktype::get_optional<std::string>(j, "author"));
        x.set_full_normalize(j.at("full_normalize").get<bool>());
        x.set_groups(j.at("groups").get<std::vector<quicktype::Group>>());
        x.set_name(j.at("name").get<std::string>());
        x.set_remove_all_dc(j.at("remove_all_dc").get<bool>());
        x.set_version(j.at("version").get<std::string>());
    }

    inline void to_json(json & j, const quicktype::Wavetable & x) {
        j = json::object();
        j["author"] = x.get_author();
        j["full_normalize"] = x.get_full_normalize();
        j["groups"] = x.get_groups();
        j["name"] = x.get_name();
        j["remove_all_dc"] = x.get_remove_all_dc();
        j["version"] = x.get_version();
    }

    inline void from_json(const json & j, quicktype::PresetSettings& x) {
        x.set_beats_per_minute(j.at("beats_per_minute").get<double>());
        x.set_bypass(quicktype::get_optional<double>(j, "bypass"));
        x.set_chorus_cutoff(quicktype::get_optional<double>(j, "chorus_cutoff"));
        x.set_chorus_damping(quicktype::get_optional<double>(j, "chorus_damping"));
        x.set_chorus_delay_1(j.at("chorus_delay_1").get<double>());
        x.set_chorus_delay_2(j.at("chorus_delay_2").get<double>());
        x.set_chorus_dry_wet(j.at("chorus_dry_wet").get<double>());
        x.set_chorus_feedback(j.at("chorus_feedback").get<double>());
        x.set_chorus_frequency(j.at("chorus_frequency").get<double>());
        x.set_chorus_mod_depth(j.at("chorus_mod_depth").get<double>());
        x.set_chorus_on(j.at("chorus_on").get<double>());
        x.set_chorus_spread(quicktype::get_optional<double>(j, "chorus_spread"));
        x.set_chorus_sync(j.at("chorus_sync").get<double>());
        x.set_chorus_tempo(j.at("chorus_tempo").get<double>());
        x.set_chorus_voices(j.at("chorus_voices").get<double>());
        x.set_compressor_attack(j.at("compressor_attack").get<double>());
        x.set_compressor_band_gain(j.at("compressor_band_gain").get<double>());
        x.set_compressor_band_lower_ratio(j.at("compressor_band_lower_ratio").get<double>());
        x.set_compressor_band_lower_threshold(j.at("compressor_band_lower_threshold").get<double>());
        x.set_compressor_band_upper_ratio(j.at("compressor_band_upper_ratio").get<double>());
        x.set_compressor_band_upper_threshold(j.at("compressor_band_upper_threshold").get<double>());
        x.set_compressor_enabled_bands(j.at("compressor_enabled_bands").get<double>());
        x.set_compressor_high_gain(j.at("compressor_high_gain").get<double>());
        x.set_compressor_high_lower_ratio(j.at("compressor_high_lower_ratio").get<double>());
        x.set_compressor_high_lower_threshold(j.at("compressor_high_lower_threshold").get<double>());
        x.set_compressor_high_upper_ratio(j.at("compressor_high_upper_ratio").get<double>());
        x.set_compressor_high_upper_threshold(j.at("compressor_high_upper_threshold").get<double>());
        x.set_compressor_low_gain(j.at("compressor_low_gain").get<double>());
        x.set_compressor_low_lower_ratio(j.at("compressor_low_lower_ratio").get<double>());
        x.set_compressor_low_lower_threshold(j.at("compressor_low_lower_threshold").get<double>());
        x.set_compressor_low_upper_ratio(j.at("compressor_low_upper_ratio").get<double>());
        x.set_compressor_low_upper_threshold(j.at("compressor_low_upper_threshold").get<double>());
        x.set_compressor_mix(quicktype::get_optional<double>(j, "compressor_mix"));
        x.set_compressor_on(j.at("compressor_on").get<double>());
        x.set_compressor_release(j.at("compressor_release").get<double>());
        x.set_delay_aux_frequency(j.at("delay_aux_frequency").get<double>());
        x.set_delay_aux_sync(j.at("delay_aux_sync").get<double>());
        x.set_delay_aux_tempo(j.at("delay_aux_tempo").get<double>());
        x.set_delay_dry_wet(j.at("delay_dry_wet").get<double>());
        x.set_delay_feedback(j.at("delay_feedback").get<double>());
        x.set_delay_filter_cutoff(j.at("delay_filter_cutoff").get<double>());
        x.set_delay_filter_spread(j.at("delay_filter_spread").get<double>());
        x.set_delay_frequency(j.at("delay_frequency").get<double>());
        x.set_delay_on(j.at("delay_on").get<double>());
        x.set_delay_style(j.at("delay_style").get<double>());
        x.set_delay_sync(j.at("delay_sync").get<double>());
        x.set_delay_tempo(j.at("delay_tempo").get<double>());
        x.set_distortion_drive(j.at("distortion_drive").get<double>());
        x.set_distortion_filter_blend(j.at("distortion_filter_blend").get<double>());
        x.set_distortion_filter_cutoff(j.at("distortion_filter_cutoff").get<double>());
        x.set_distortion_filter_order(j.at("distortion_filter_order").get<double>());
        x.set_distortion_filter_resonance(j.at("distortion_filter_resonance").get<double>());
        x.set_distortion_mix(j.at("distortion_mix").get<double>());
        x.set_distortion_on(j.at("distortion_on").get<double>());
        x.set_distortion_type(j.at("distortion_type").get<double>());
        x.set_effect_chain_order(j.at("effect_chain_order").get<double>());
        x.set_env_1___attack(j.at("env_1_attack").get<double>());
        x.set_env_1___attack_power(j.at("env_1_attack_power").get<double>());
        x.set_env_1___decay(j.at("env_1_decay").get<double>());
        x.set_env_1___decay_power(j.at("env_1_decay_power").get<double>());
        x.set_env_1___delay(j.at("env_1_delay").get<double>());
        x.set_env_1___hold(j.at("env_1_hold").get<double>());
        x.set_env_1___release(j.at("env_1_release").get<double>());
        x.set_env_1___release_power(j.at("env_1_release_power").get<double>());
        x.set_env_1___sustain(j.at("env_1_sustain").get<double>());
        x.set_env_2___attack(j.at("env_2_attack").get<double>());
        x.set_env_2___attack_power(j.at("env_2_attack_power").get<double>());
        x.set_env_2___decay(j.at("env_2_decay").get<double>());
        x.set_env_2___decay_power(j.at("env_2_decay_power").get<double>());
        x.set_env_2___delay(j.at("env_2_delay").get<double>());
        x.set_env_2___hold(j.at("env_2_hold").get<double>());
        x.set_env_2___release(j.at("env_2_release").get<double>());
        x.set_env_2___release_power(j.at("env_2_release_power").get<double>());
        x.set_env_2___sustain(j.at("env_2_sustain").get<double>());
        x.set_env_3___attack(j.at("env_3_attack").get<double>());
        x.set_env_3___attack_power(j.at("env_3_attack_power").get<double>());
        x.set_env_3___decay(j.at("env_3_decay").get<double>());
        x.set_env_3___decay_power(j.at("env_3_decay_power").get<double>());
        x.set_env_3___delay(j.at("env_3_delay").get<double>());
        x.set_env_3___hold(j.at("env_3_hold").get<double>());
        x.set_env_3___release(j.at("env_3_release").get<double>());
        x.set_env_3___release_power(j.at("env_3_release_power").get<double>());
        x.set_env_3___sustain(j.at("env_3_sustain").get<double>());
        x.set_env_4___attack(j.at("env_4_attack").get<double>());
        x.set_env_4___attack_power(j.at("env_4_attack_power").get<double>());
        x.set_env_4___decay(j.at("env_4_decay").get<double>());
        x.set_env_4___decay_power(j.at("env_4_decay_power").get<double>());
        x.set_env_4___delay(j.at("env_4_delay").get<double>());
        x.set_env_4___hold(j.at("env_4_hold").get<double>());
        x.set_env_4___release(j.at("env_4_release").get<double>());
        x.set_env_4___release_power(j.at("env_4_release_power").get<double>());
        x.set_env_4___sustain(j.at("env_4_sustain").get<double>());
        x.set_env_5___attack(j.at("env_5_attack").get<double>());
        x.set_env_5___attack_power(j.at("env_5_attack_power").get<double>());
        x.set_env_5___decay(j.at("env_5_decay").get<double>());
        x.set_env_5___decay_power(j.at("env_5_decay_power").get<double>());
        x.set_env_5___delay(j.at("env_5_delay").get<double>());
        x.set_env_5___hold(j.at("env_5_hold").get<double>());
        x.set_env_5___release(j.at("env_5_release").get<double>());
        x.set_env_5___release_power(j.at("env_5_release_power").get<double>());
        x.set_env_5___sustain(j.at("env_5_sustain").get<double>());
        x.set_env_6___attack(j.at("env_6_attack").get<double>());
        x.set_env_6___attack_power(j.at("env_6_attack_power").get<double>());
        x.set_env_6___decay(j.at("env_6_decay").get<double>());
        x.set_env_6___decay_power(j.at("env_6_decay_power").get<double>());
        x.set_env_6___delay(j.at("env_6_delay").get<double>());
        x.set_env_6___hold(j.at("env_6_hold").get<double>());
        x.set_env_6___release(j.at("env_6_release").get<double>());
        x.set_env_6___release_power(j.at("env_6_release_power").get<double>());
        x.set_env_6___sustain(j.at("env_6_sustain").get<double>());
        x.set_eq_band_cutoff(j.at("eq_band_cutoff").get<double>());
        x.set_eq_band_gain(j.at("eq_band_gain").get<double>());
        x.set_eq_band_mode(j.at("eq_band_mode").get<double>());
        x.set_eq_band_resonance(j.at("eq_band_resonance").get<double>());
        x.set_eq_high_cutoff(j.at("eq_high_cutoff").get<double>());
        x.set_eq_high_gain(j.at("eq_high_gain").get<double>());
        x.set_eq_high_mode(j.at("eq_high_mode").get<double>());
        x.set_eq_high_resonance(j.at("eq_high_resonance").get<double>());
        x.set_eq_low_cutoff(j.at("eq_low_cutoff").get<double>());
        x.set_eq_low_gain(j.at("eq_low_gain").get<double>());
        x.set_eq_low_mode(j.at("eq_low_mode").get<double>());
        x.set_eq_low_resonance(j.at("eq_low_resonance").get<double>());
        x.set_eq_on(j.at("eq_on").get<double>());
        x.set_filter_1___blend(j.at("filter_1_blend").get<double>());
        x.set_filter_1___blend_transpose(j.at("filter_1_blend_transpose").get<double>());
        x.set_filter_1___cutoff(j.at("filter_1_cutoff").get<double>());
        x.set_filter_1___drive(j.at("filter_1_drive").get<double>());
        x.set_filter_1___filter_input(j.at("filter_1_filter_input").get<double>());
        x.set_filter_1___formant_resonance(j.at("filter_1_formant_resonance").get<double>());
        x.set_filter_1___formant_spread(quicktype::get_optional<double>(j, "filter_1_formant_spread"));
        x.set_filter_1___formant_transpose(j.at("filter_1_formant_transpose").get<double>());
        x.set_filter_1___formant_x(j.at("filter_1_formant_x").get<double>());
        x.set_filter_1___formant_y(j.at("filter_1_formant_y").get<double>());
        x.set_filter_1___keytrack(j.at("filter_1_keytrack").get<double>());
        x.set_filter_1___mix(j.at("filter_1_mix").get<double>());
        x.set_filter_1___model(j.at("filter_1_model").get<double>());
        x.set_filter_1___on(j.at("filter_1_on").get<double>());
        x.set_filter_1___resonance(j.at("filter_1_resonance").get<double>());
        x.set_filter_1___style(j.at("filter_1_style").get<double>());
        x.set_filter_2___blend(j.at("filter_2_blend").get<double>());
        x.set_filter_2___blend_transpose(j.at("filter_2_blend_transpose").get<double>());
        x.set_filter_2___cutoff(j.at("filter_2_cutoff").get<double>());
        x.set_filter_2___drive(j.at("filter_2_drive").get<double>());
        x.set_filter_2___filter_input(j.at("filter_2_filter_input").get<double>());
        x.set_filter_2___formant_resonance(j.at("filter_2_formant_resonance").get<double>());
        x.set_filter_2___formant_spread(quicktype::get_optional<double>(j, "filter_2_formant_spread"));
        x.set_filter_2___formant_transpose(j.at("filter_2_formant_transpose").get<double>());
        x.set_filter_2___formant_x(j.at("filter_2_formant_x").get<double>());
        x.set_filter_2___formant_y(j.at("filter_2_formant_y").get<double>());
        x.set_filter_2___keytrack(j.at("filter_2_keytrack").get<double>());
        x.set_filter_2___mix(j.at("filter_2_mix").get<double>());
        x.set_filter_2___model(j.at("filter_2_model").get<double>());
        x.set_filter_2___on(j.at("filter_2_on").get<double>());
        x.set_filter_2___resonance(j.at("filter_2_resonance").get<double>());
        x.set_filter_2___style(j.at("filter_2_style").get<double>());
        x.set_filter_fx_blend(j.at("filter_fx_blend").get<double>());
        x.set_filter_fx_blend_transpose(j.at("filter_fx_blend_transpose").get<double>());
        x.set_filter_fx_cutoff(j.at("filter_fx_cutoff").get<double>());
        x.set_filter_fx_drive(j.at("filter_fx_drive").get<double>());
        x.set_filter_fx_formant_resonance(j.at("filter_fx_formant_resonance").get<double>());
        x.set_filter_fx_formant_spread(quicktype::get_optional<double>(j, "filter_fx_formant_spread"));
        x.set_filter_fx_formant_transpose(j.at("filter_fx_formant_transpose").get<double>());
        x.set_filter_fx_formant_x(j.at("filter_fx_formant_x").get<double>());
        x.set_filter_fx_formant_y(j.at("filter_fx_formant_y").get<double>());
        x.set_filter_fx_keytrack(j.at("filter_fx_keytrack").get<double>());
        x.set_filter_fx_mix(j.at("filter_fx_mix").get<double>());
        x.set_filter_fx_model(j.at("filter_fx_model").get<double>());
        x.set_filter_fx_on(j.at("filter_fx_on").get<double>());
        x.set_filter_fx_resonance(j.at("filter_fx_resonance").get<double>());
        x.set_filter_fx_style(j.at("filter_fx_style").get<double>());
        x.set_flanger_center(j.at("flanger_center").get<double>());
        x.set_flanger_dry_wet(j.at("flanger_dry_wet").get<double>());
        x.set_flanger_feedback(j.at("flanger_feedback").get<double>());
        x.set_flanger_frequency(j.at("flanger_frequency").get<double>());
        x.set_flanger_mod_depth(j.at("flanger_mod_depth").get<double>());
        x.set_flanger_on(j.at("flanger_on").get<double>());
        x.set_flanger_phase_offset(j.at("flanger_phase_offset").get<double>());
        x.set_flanger_sync(j.at("flanger_sync").get<double>());
        x.set_flanger_tempo(j.at("flanger_tempo").get<double>());
        x.set_legato(j.at("legato").get<double>());
        x.set_lfo_1___delay_time(j.at("lfo_1_delay_time").get<double>());
        x.set_lfo_1___fade_time(j.at("lfo_1_fade_time").get<double>());
        x.set_lfo_1___frequency(j.at("lfo_1_frequency").get<double>());
        x.set_lfo_1___keytrack_transpose(quicktype::get_optional<double>(j, "lfo_1_keytrack_transpose"));
        x.set_lfo_1___keytrack_tune(quicktype::get_optional<double>(j, "lfo_1_keytrack_tune"));
        x.set_lfo_1___phase(j.at("lfo_1_phase").get<double>());
        x.set_lfo_1___smooth_mode(quicktype::get_optional<double>(j, "lfo_1_smooth_mode"));
        x.set_lfo_1___smooth_time(quicktype::get_optional<double>(j, "lfo_1_smooth_time"));
        x.set_lfo_1___stereo(j.at("lfo_1_stereo").get<double>());
        x.set_lfo_1___sync(j.at("lfo_1_sync").get<double>());
        x.set_lfo_1___sync_type(j.at("lfo_1_sync_type").get<double>());
        x.set_lfo_1___tempo(j.at("lfo_1_tempo").get<double>());
        x.set_lfo_2___delay_time(j.at("lfo_2_delay_time").get<double>());
        x.set_lfo_2___fade_time(j.at("lfo_2_fade_time").get<double>());
        x.set_lfo_2___frequency(j.at("lfo_2_frequency").get<double>());
        x.set_lfo_2___keytrack_transpose(quicktype::get_optional<double>(j, "lfo_2_keytrack_transpose"));
        x.set_lfo_2___keytrack_tune(quicktype::get_optional<double>(j, "lfo_2_keytrack_tune"));
        x.set_lfo_2___phase(j.at("lfo_2_phase").get<double>());
        x.set_lfo_2___smooth_mode(quicktype::get_optional<double>(j, "lfo_2_smooth_mode"));
        x.set_lfo_2___smooth_time(quicktype::get_optional<double>(j, "lfo_2_smooth_time"));
        x.set_lfo_2___stereo(j.at("lfo_2_stereo").get<double>());
        x.set_lfo_2___sync(j.at("lfo_2_sync").get<double>());
        x.set_lfo_2___sync_type(j.at("lfo_2_sync_type").get<double>());
        x.set_lfo_2___tempo(j.at("lfo_2_tempo").get<double>());
        x.set_lfo_3___delay_time(j.at("lfo_3_delay_time").get<double>());
        x.set_lfo_3___fade_time(j.at("lfo_3_fade_time").get<double>());
        x.set_lfo_3___frequency(j.at("lfo_3_frequency").get<double>());
        x.set_lfo_3___keytrack_transpose(quicktype::get_optional<double>(j, "lfo_3_keytrack_transpose"));
        x.set_lfo_3___keytrack_tune(quicktype::get_optional<double>(j, "lfo_3_keytrack_tune"));
        x.set_lfo_3___phase(j.at("lfo_3_phase").get<double>());
        x.set_lfo_3___smooth_mode(quicktype::get_optional<double>(j, "lfo_3_smooth_mode"));
        x.set_lfo_3___smooth_time(quicktype::get_optional<double>(j, "lfo_3_smooth_time"));
        x.set_lfo_3___stereo(j.at("lfo_3_stereo").get<double>());
        x.set_lfo_3___sync(j.at("lfo_3_sync").get<double>());
        x.set_lfo_3___sync_type(j.at("lfo_3_sync_type").get<double>());
        x.set_lfo_3___tempo(j.at("lfo_3_tempo").get<double>());
        x.set_lfo_4___delay_time(j.at("lfo_4_delay_time").get<double>());
        x.set_lfo_4___fade_time(j.at("lfo_4_fade_time").get<double>());
        x.set_lfo_4___frequency(j.at("lfo_4_frequency").get<double>());
        x.set_lfo_4___keytrack_transpose(quicktype::get_optional<double>(j, "lfo_4_keytrack_transpose"));
        x.set_lfo_4___keytrack_tune(quicktype::get_optional<double>(j, "lfo_4_keytrack_tune"));
        x.set_lfo_4___phase(j.at("lfo_4_phase").get<double>());
        x.set_lfo_4___smooth_mode(quicktype::get_optional<double>(j, "lfo_4_smooth_mode"));
        x.set_lfo_4___smooth_time(quicktype::get_optional<double>(j, "lfo_4_smooth_time"));
        x.set_lfo_4___stereo(j.at("lfo_4_stereo").get<double>());
        x.set_lfo_4___sync(j.at("lfo_4_sync").get<double>());
        x.set_lfo_4___sync_type(j.at("lfo_4_sync_type").get<double>());
        x.set_lfo_4___tempo(j.at("lfo_4_tempo").get<double>());
        x.set_lfo_5___delay_time(j.at("lfo_5_delay_time").get<double>());
        x.set_lfo_5___fade_time(j.at("lfo_5_fade_time").get<double>());
        x.set_lfo_5___frequency(j.at("lfo_5_frequency").get<double>());
        x.set_lfo_5___keytrack_transpose(quicktype::get_optional<double>(j, "lfo_5_keytrack_transpose"));
        x.set_lfo_5___keytrack_tune(quicktype::get_optional<double>(j, "lfo_5_keytrack_tune"));
        x.set_lfo_5___phase(j.at("lfo_5_phase").get<double>());
        x.set_lfo_5___smooth_mode(quicktype::get_optional<double>(j, "lfo_5_smooth_mode"));
        x.set_lfo_5___smooth_time(quicktype::get_optional<double>(j, "lfo_5_smooth_time"));
        x.set_lfo_5___stereo(j.at("lfo_5_stereo").get<double>());
        x.set_lfo_5___sync(j.at("lfo_5_sync").get<double>());
        x.set_lfo_5___sync_type(j.at("lfo_5_sync_type").get<double>());
        x.set_lfo_5___tempo(j.at("lfo_5_tempo").get<double>());
        x.set_lfo_6___delay_time(j.at("lfo_6_delay_time").get<double>());
        x.set_lfo_6___fade_time(j.at("lfo_6_fade_time").get<double>());
        x.set_lfo_6___frequency(j.at("lfo_6_frequency").get<double>());
        x.set_lfo_6___keytrack_transpose(quicktype::get_optional<double>(j, "lfo_6_keytrack_transpose"));
        x.set_lfo_6___keytrack_tune(quicktype::get_optional<double>(j, "lfo_6_keytrack_tune"));
        x.set_lfo_6___phase(j.at("lfo_6_phase").get<double>());
        x.set_lfo_6___smooth_mode(quicktype::get_optional<double>(j, "lfo_6_smooth_mode"));
        x.set_lfo_6___smooth_time(quicktype::get_optional<double>(j, "lfo_6_smooth_time"));
        x.set_lfo_6___stereo(j.at("lfo_6_stereo").get<double>());
        x.set_lfo_6___sync(j.at("lfo_6_sync").get<double>());
        x.set_lfo_6___sync_type(j.at("lfo_6_sync_type").get<double>());
        x.set_lfo_6___tempo(j.at("lfo_6_tempo").get<double>());
        x.set_lfo_7___delay_time(j.at("lfo_7_delay_time").get<double>());
        x.set_lfo_7___fade_time(j.at("lfo_7_fade_time").get<double>());
        x.set_lfo_7___frequency(j.at("lfo_7_frequency").get<double>());
        x.set_lfo_7___keytrack_transpose(quicktype::get_optional<double>(j, "lfo_7_keytrack_transpose"));
        x.set_lfo_7___keytrack_tune(quicktype::get_optional<double>(j, "lfo_7_keytrack_tune"));
        x.set_lfo_7___phase(j.at("lfo_7_phase").get<double>());
        x.set_lfo_7___smooth_mode(quicktype::get_optional<double>(j, "lfo_7_smooth_mode"));
        x.set_lfo_7___smooth_time(quicktype::get_optional<double>(j, "lfo_7_smooth_time"));
        x.set_lfo_7___stereo(j.at("lfo_7_stereo").get<double>());
        x.set_lfo_7___sync(j.at("lfo_7_sync").get<double>());
        x.set_lfo_7___sync_type(j.at("lfo_7_sync_type").get<double>());
        x.set_lfo_7___tempo(j.at("lfo_7_tempo").get<double>());
        x.set_lfo_8___delay_time(j.at("lfo_8_delay_time").get<double>());
        x.set_lfo_8___fade_time(j.at("lfo_8_fade_time").get<double>());
        x.set_lfo_8___frequency(j.at("lfo_8_frequency").get<double>());
        x.set_lfo_8___keytrack_transpose(quicktype::get_optional<double>(j, "lfo_8_keytrack_transpose"));
        x.set_lfo_8___keytrack_tune(quicktype::get_optional<double>(j, "lfo_8_keytrack_tune"));
        x.set_lfo_8___phase(j.at("lfo_8_phase").get<double>());
        x.set_lfo_8___smooth_mode(quicktype::get_optional<double>(j, "lfo_8_smooth_mode"));
        x.set_lfo_8___smooth_time(quicktype::get_optional<double>(j, "lfo_8_smooth_time"));
        x.set_lfo_8___stereo(j.at("lfo_8_stereo").get<double>());
        x.set_lfo_8___sync(j.at("lfo_8_sync").get<double>());
        x.set_lfo_8___sync_type(j.at("lfo_8_sync_type").get<double>());
        x.set_lfo_8___tempo(j.at("lfo_8_tempo").get<double>());
        x.set_lfos(j.at("lfos").get<std::vector<quicktype::Lfo>>());
        x.set_macro_control_1(j.at("macro_control_1").get<double>());
        x.set_macro_control_2(j.at("macro_control_2").get<double>());
        x.set_macro_control_3(j.at("macro_control_3").get<double>());
        x.set_macro_control_4(j.at("macro_control_4").get<double>());
        x.set_mod_wheel(j.at("mod_wheel").get<double>());
        x.set_modulation_10___amount(j.at("modulation_10_amount").get<double>());
        x.set_modulation_10___bipolar(j.at("modulation_10_bipolar").get<double>());
        x.set_modulation_10___bypass(j.at("modulation_10_bypass").get<double>());
        x.set_modulation_10___power(j.at("modulation_10_power").get<double>());
        x.set_modulation_10___stereo(j.at("modulation_10_stereo").get<double>());
        x.set_modulation_11___amount(j.at("modulation_11_amount").get<double>());
        x.set_modulation_11___bipolar(j.at("modulation_11_bipolar").get<double>());
        x.set_modulation_11___bypass(j.at("modulation_11_bypass").get<double>());
        x.set_modulation_11___power(j.at("modulation_11_power").get<double>());
        x.set_modulation_11___stereo(j.at("modulation_11_stereo").get<double>());
        x.set_modulation_12___amount(j.at("modulation_12_amount").get<double>());
        x.set_modulation_12___bipolar(j.at("modulation_12_bipolar").get<double>());
        x.set_modulation_12___bypass(j.at("modulation_12_bypass").get<double>());
        x.set_modulation_12___power(j.at("modulation_12_power").get<double>());
        x.set_modulation_12___stereo(j.at("modulation_12_stereo").get<double>());
        x.set_modulation_13___amount(j.at("modulation_13_amount").get<double>());
        x.set_modulation_13___bipolar(j.at("modulation_13_bipolar").get<double>());
        x.set_modulation_13___bypass(j.at("modulation_13_bypass").get<double>());
        x.set_modulation_13___power(j.at("modulation_13_power").get<double>());
        x.set_modulation_13___stereo(j.at("modulation_13_stereo").get<double>());
        x.set_modulation_14___amount(j.at("modulation_14_amount").get<double>());
        x.set_modulation_14___bipolar(j.at("modulation_14_bipolar").get<double>());
        x.set_modulation_14___bypass(j.at("modulation_14_bypass").get<double>());
        x.set_modulation_14___power(j.at("modulation_14_power").get<double>());
        x.set_modulation_14___stereo(j.at("modulation_14_stereo").get<double>());
        x.set_modulation_15___amount(j.at("modulation_15_amount").get<double>());
        x.set_modulation_15___bipolar(j.at("modulation_15_bipolar").get<double>());
        x.set_modulation_15___bypass(j.at("modulation_15_bypass").get<double>());
        x.set_modulation_15___power(j.at("modulation_15_power").get<double>());
        x.set_modulation_15___stereo(j.at("modulation_15_stereo").get<double>());
        x.set_modulation_16___amount(j.at("modulation_16_amount").get<double>());
        x.set_modulation_16___bipolar(j.at("modulation_16_bipolar").get<double>());
        x.set_modulation_16___bypass(j.at("modulation_16_bypass").get<double>());
        x.set_modulation_16___power(j.at("modulation_16_power").get<double>());
        x.set_modulation_16___stereo(j.at("modulation_16_stereo").get<double>());
        x.set_modulation_17___amount(j.at("modulation_17_amount").get<double>());
        x.set_modulation_17___bipolar(j.at("modulation_17_bipolar").get<double>());
        x.set_modulation_17___bypass(j.at("modulation_17_bypass").get<double>());
        x.set_modulation_17___power(j.at("modulation_17_power").get<double>());
        x.set_modulation_17___stereo(j.at("modulation_17_stereo").get<double>());
        x.set_modulation_18___amount(j.at("modulation_18_amount").get<double>());
        x.set_modulation_18___bipolar(j.at("modulation_18_bipolar").get<double>());
        x.set_modulation_18___bypass(j.at("modulation_18_bypass").get<double>());
        x.set_modulation_18___power(j.at("modulation_18_power").get<double>());
        x.set_modulation_18___stereo(j.at("modulation_18_stereo").get<double>());
        x.set_modulation_19___amount(j.at("modulation_19_amount").get<double>());
        x.set_modulation_19___bipolar(j.at("modulation_19_bipolar").get<double>());
        x.set_modulation_19___bypass(j.at("modulation_19_bypass").get<double>());
        x.set_modulation_19___power(j.at("modulation_19_power").get<double>());
        x.set_modulation_19___stereo(j.at("modulation_19_stereo").get<double>());
        x.set_modulation_1___amount(j.at("modulation_1_amount").get<double>());
        x.set_modulation_1___bipolar(j.at("modulation_1_bipolar").get<double>());
        x.set_modulation_1___bypass(j.at("modulation_1_bypass").get<double>());
        x.set_modulation_1___power(j.at("modulation_1_power").get<double>());
        x.set_modulation_1___stereo(j.at("modulation_1_stereo").get<double>());
        x.set_modulation_20___amount(j.at("modulation_20_amount").get<double>());
        x.set_modulation_20___bipolar(j.at("modulation_20_bipolar").get<double>());
        x.set_modulation_20___bypass(j.at("modulation_20_bypass").get<double>());
        x.set_modulation_20___power(j.at("modulation_20_power").get<double>());
        x.set_modulation_20___stereo(j.at("modulation_20_stereo").get<double>());
        x.set_modulation_21___amount(j.at("modulation_21_amount").get<double>());
        x.set_modulation_21___bipolar(j.at("modulation_21_bipolar").get<double>());
        x.set_modulation_21___bypass(j.at("modulation_21_bypass").get<double>());
        x.set_modulation_21___power(j.at("modulation_21_power").get<double>());
        x.set_modulation_21___stereo(j.at("modulation_21_stereo").get<double>());
        x.set_modulation_22___amount(j.at("modulation_22_amount").get<double>());
        x.set_modulation_22___bipolar(j.at("modulation_22_bipolar").get<double>());
        x.set_modulation_22___bypass(j.at("modulation_22_bypass").get<double>());
        x.set_modulation_22___power(j.at("modulation_22_power").get<double>());
        x.set_modulation_22___stereo(j.at("modulation_22_stereo").get<double>());
        x.set_modulation_23___amount(j.at("modulation_23_amount").get<double>());
        x.set_modulation_23___bipolar(j.at("modulation_23_bipolar").get<double>());
        x.set_modulation_23___bypass(j.at("modulation_23_bypass").get<double>());
        x.set_modulation_23___power(j.at("modulation_23_power").get<double>());
        x.set_modulation_23___stereo(j.at("modulation_23_stereo").get<double>());
        x.set_modulation_24___amount(j.at("modulation_24_amount").get<double>());
        x.set_modulation_24___bipolar(j.at("modulation_24_bipolar").get<double>());
        x.set_modulation_24___bypass(j.at("modulation_24_bypass").get<double>());
        x.set_modulation_24___power(j.at("modulation_24_power").get<double>());
        x.set_modulation_24___stereo(j.at("modulation_24_stereo").get<double>());
        x.set_modulation_25___amount(j.at("modulation_25_amount").get<double>());
        x.set_modulation_25___bipolar(j.at("modulation_25_bipolar").get<double>());
        x.set_modulation_25___bypass(j.at("modulation_25_bypass").get<double>());
        x.set_modulation_25___power(j.at("modulation_25_power").get<double>());
        x.set_modulation_25___stereo(j.at("modulation_25_stereo").get<double>());
        x.set_modulation_26___amount(j.at("modulation_26_amount").get<double>());
        x.set_modulation_26___bipolar(j.at("modulation_26_bipolar").get<double>());
        x.set_modulation_26___bypass(j.at("modulation_26_bypass").get<double>());
        x.set_modulation_26___power(j.at("modulation_26_power").get<double>());
        x.set_modulation_26___stereo(j.at("modulation_26_stereo").get<double>());
        x.set_modulation_27___amount(j.at("modulation_27_amount").get<double>());
        x.set_modulation_27___bipolar(j.at("modulation_27_bipolar").get<double>());
        x.set_modulation_27___bypass(j.at("modulation_27_bypass").get<double>());
        x.set_modulation_27___power(j.at("modulation_27_power").get<double>());
        x.set_modulation_27___stereo(j.at("modulation_27_stereo").get<double>());
        x.set_modulation_28___amount(j.at("modulation_28_amount").get<double>());
        x.set_modulation_28___bipolar(j.at("modulation_28_bipolar").get<double>());
        x.set_modulation_28___bypass(j.at("modulation_28_bypass").get<double>());
        x.set_modulation_28___power(j.at("modulation_28_power").get<double>());
        x.set_modulation_28___stereo(j.at("modulation_28_stereo").get<double>());
        x.set_modulation_29___amount(j.at("modulation_29_amount").get<double>());
        x.set_modulation_29___bipolar(j.at("modulation_29_bipolar").get<double>());
        x.set_modulation_29___bypass(j.at("modulation_29_bypass").get<double>());
        x.set_modulation_29___power(j.at("modulation_29_power").get<double>());
        x.set_modulation_29___stereo(j.at("modulation_29_stereo").get<double>());
        x.set_modulation_2___amount(j.at("modulation_2_amount").get<double>());
        x.set_modulation_2___bipolar(j.at("modulation_2_bipolar").get<double>());
        x.set_modulation_2___bypass(j.at("modulation_2_bypass").get<double>());
        x.set_modulation_2___power(j.at("modulation_2_power").get<double>());
        x.set_modulation_2___stereo(j.at("modulation_2_stereo").get<double>());
        x.set_modulation_30___amount(j.at("modulation_30_amount").get<double>());
        x.set_modulation_30___bipolar(j.at("modulation_30_bipolar").get<double>());
        x.set_modulation_30___bypass(j.at("modulation_30_bypass").get<double>());
        x.set_modulation_30___power(j.at("modulation_30_power").get<double>());
        x.set_modulation_30___stereo(j.at("modulation_30_stereo").get<double>());
        x.set_modulation_31___amount(j.at("modulation_31_amount").get<double>());
        x.set_modulation_31___bipolar(j.at("modulation_31_bipolar").get<double>());
        x.set_modulation_31___bypass(j.at("modulation_31_bypass").get<double>());
        x.set_modulation_31___power(j.at("modulation_31_power").get<double>());
        x.set_modulation_31___stereo(j.at("modulation_31_stereo").get<double>());
        x.set_modulation_32___amount(j.at("modulation_32_amount").get<double>());
        x.set_modulation_32___bipolar(j.at("modulation_32_bipolar").get<double>());
        x.set_modulation_32___bypass(j.at("modulation_32_bypass").get<double>());
        x.set_modulation_32___power(j.at("modulation_32_power").get<double>());
        x.set_modulation_32___stereo(j.at("modulation_32_stereo").get<double>());
        x.set_modulation_33___amount(j.at("modulation_33_amount").get<double>());
        x.set_modulation_33___bipolar(j.at("modulation_33_bipolar").get<double>());
        x.set_modulation_33___bypass(j.at("modulation_33_bypass").get<double>());
        x.set_modulation_33___power(j.at("modulation_33_power").get<double>());
        x.set_modulation_33___stereo(j.at("modulation_33_stereo").get<double>());
        x.set_modulation_34___amount(j.at("modulation_34_amount").get<double>());
        x.set_modulation_34___bipolar(j.at("modulation_34_bipolar").get<double>());
        x.set_modulation_34___bypass(j.at("modulation_34_bypass").get<double>());
        x.set_modulation_34___power(j.at("modulation_34_power").get<double>());
        x.set_modulation_34___stereo(j.at("modulation_34_stereo").get<double>());
        x.set_modulation_35___amount(j.at("modulation_35_amount").get<double>());
        x.set_modulation_35___bipolar(j.at("modulation_35_bipolar").get<double>());
        x.set_modulation_35___bypass(j.at("modulation_35_bypass").get<double>());
        x.set_modulation_35___power(j.at("modulation_35_power").get<double>());
        x.set_modulation_35___stereo(j.at("modulation_35_stereo").get<double>());
        x.set_modulation_36___amount(j.at("modulation_36_amount").get<double>());
        x.set_modulation_36___bipolar(j.at("modulation_36_bipolar").get<double>());
        x.set_modulation_36___bypass(j.at("modulation_36_bypass").get<double>());
        x.set_modulation_36___power(j.at("modulation_36_power").get<double>());
        x.set_modulation_36___stereo(j.at("modulation_36_stereo").get<double>());
        x.set_modulation_37___amount(j.at("modulation_37_amount").get<double>());
        x.set_modulation_37___bipolar(j.at("modulation_37_bipolar").get<double>());
        x.set_modulation_37___bypass(j.at("modulation_37_bypass").get<double>());
        x.set_modulation_37___power(j.at("modulation_37_power").get<double>());
        x.set_modulation_37___stereo(j.at("modulation_37_stereo").get<double>());
        x.set_modulation_38___amount(j.at("modulation_38_amount").get<double>());
        x.set_modulation_38___bipolar(j.at("modulation_38_bipolar").get<double>());
        x.set_modulation_38___bypass(j.at("modulation_38_bypass").get<double>());
        x.set_modulation_38___power(j.at("modulation_38_power").get<double>());
        x.set_modulation_38___stereo(j.at("modulation_38_stereo").get<double>());
        x.set_modulation_39___amount(j.at("modulation_39_amount").get<double>());
        x.set_modulation_39___bipolar(j.at("modulation_39_bipolar").get<double>());
        x.set_modulation_39___bypass(j.at("modulation_39_bypass").get<double>());
        x.set_modulation_39___power(j.at("modulation_39_power").get<double>());
        x.set_modulation_39___stereo(j.at("modulation_39_stereo").get<double>());
        x.set_modulation_3___amount(j.at("modulation_3_amount").get<double>());
        x.set_modulation_3___bipolar(j.at("modulation_3_bipolar").get<double>());
        x.set_modulation_3___bypass(j.at("modulation_3_bypass").get<double>());
        x.set_modulation_3___power(j.at("modulation_3_power").get<double>());
        x.set_modulation_3___stereo(j.at("modulation_3_stereo").get<double>());
        x.set_modulation_40___amount(j.at("modulation_40_amount").get<double>());
        x.set_modulation_40___bipolar(j.at("modulation_40_bipolar").get<double>());
        x.set_modulation_40___bypass(j.at("modulation_40_bypass").get<double>());
        x.set_modulation_40___power(j.at("modulation_40_power").get<double>());
        x.set_modulation_40___stereo(j.at("modulation_40_stereo").get<double>());
        x.set_modulation_41___amount(j.at("modulation_41_amount").get<double>());
        x.set_modulation_41___bipolar(j.at("modulation_41_bipolar").get<double>());
        x.set_modulation_41___bypass(j.at("modulation_41_bypass").get<double>());
        x.set_modulation_41___power(j.at("modulation_41_power").get<double>());
        x.set_modulation_41___stereo(j.at("modulation_41_stereo").get<double>());
        x.set_modulation_42___amount(j.at("modulation_42_amount").get<double>());
        x.set_modulation_42___bipolar(j.at("modulation_42_bipolar").get<double>());
        x.set_modulation_42___bypass(j.at("modulation_42_bypass").get<double>());
        x.set_modulation_42___power(j.at("modulation_42_power").get<double>());
        x.set_modulation_42___stereo(j.at("modulation_42_stereo").get<double>());
        x.set_modulation_43___amount(j.at("modulation_43_amount").get<double>());
        x.set_modulation_43___bipolar(j.at("modulation_43_bipolar").get<double>());
        x.set_modulation_43___bypass(j.at("modulation_43_bypass").get<double>());
        x.set_modulation_43___power(j.at("modulation_43_power").get<double>());
        x.set_modulation_43___stereo(j.at("modulation_43_stereo").get<double>());
        x.set_modulation_44___amount(j.at("modulation_44_amount").get<double>());
        x.set_modulation_44___bipolar(j.at("modulation_44_bipolar").get<double>());
        x.set_modulation_44___bypass(j.at("modulation_44_bypass").get<double>());
        x.set_modulation_44___power(j.at("modulation_44_power").get<double>());
        x.set_modulation_44___stereo(j.at("modulation_44_stereo").get<double>());
        x.set_modulation_45___amount(j.at("modulation_45_amount").get<double>());
        x.set_modulation_45___bipolar(j.at("modulation_45_bipolar").get<double>());
        x.set_modulation_45___bypass(j.at("modulation_45_bypass").get<double>());
        x.set_modulation_45___power(j.at("modulation_45_power").get<double>());
        x.set_modulation_45___stereo(j.at("modulation_45_stereo").get<double>());
        x.set_modulation_46___amount(j.at("modulation_46_amount").get<double>());
        x.set_modulation_46___bipolar(j.at("modulation_46_bipolar").get<double>());
        x.set_modulation_46___bypass(j.at("modulation_46_bypass").get<double>());
        x.set_modulation_46___power(j.at("modulation_46_power").get<double>());
        x.set_modulation_46___stereo(j.at("modulation_46_stereo").get<double>());
        x.set_modulation_47___amount(j.at("modulation_47_amount").get<double>());
        x.set_modulation_47___bipolar(j.at("modulation_47_bipolar").get<double>());
        x.set_modulation_47___bypass(j.at("modulation_47_bypass").get<double>());
        x.set_modulation_47___power(j.at("modulation_47_power").get<double>());
        x.set_modulation_47___stereo(j.at("modulation_47_stereo").get<double>());
        x.set_modulation_48___amount(j.at("modulation_48_amount").get<double>());
        x.set_modulation_48___bipolar(j.at("modulation_48_bipolar").get<double>());
        x.set_modulation_48___bypass(j.at("modulation_48_bypass").get<double>());
        x.set_modulation_48___power(j.at("modulation_48_power").get<double>());
        x.set_modulation_48___stereo(j.at("modulation_48_stereo").get<double>());
        x.set_modulation_49___amount(j.at("modulation_49_amount").get<double>());
        x.set_modulation_49___bipolar(j.at("modulation_49_bipolar").get<double>());
        x.set_modulation_49___bypass(j.at("modulation_49_bypass").get<double>());
        x.set_modulation_49___power(j.at("modulation_49_power").get<double>());
        x.set_modulation_49___stereo(j.at("modulation_49_stereo").get<double>());
        x.set_modulation_4___amount(j.at("modulation_4_amount").get<double>());
        x.set_modulation_4___bipolar(j.at("modulation_4_bipolar").get<double>());
        x.set_modulation_4___bypass(j.at("modulation_4_bypass").get<double>());
        x.set_modulation_4___power(j.at("modulation_4_power").get<double>());
        x.set_modulation_4___stereo(j.at("modulation_4_stereo").get<double>());
        x.set_modulation_50___amount(j.at("modulation_50_amount").get<double>());
        x.set_modulation_50___bipolar(j.at("modulation_50_bipolar").get<double>());
        x.set_modulation_50___bypass(j.at("modulation_50_bypass").get<double>());
        x.set_modulation_50___power(j.at("modulation_50_power").get<double>());
        x.set_modulation_50___stereo(j.at("modulation_50_stereo").get<double>());
        x.set_modulation_51___amount(j.at("modulation_51_amount").get<double>());
        x.set_modulation_51___bipolar(j.at("modulation_51_bipolar").get<double>());
        x.set_modulation_51___bypass(j.at("modulation_51_bypass").get<double>());
        x.set_modulation_51___power(j.at("modulation_51_power").get<double>());
        x.set_modulation_51___stereo(j.at("modulation_51_stereo").get<double>());
        x.set_modulation_52___amount(j.at("modulation_52_amount").get<double>());
        x.set_modulation_52___bipolar(j.at("modulation_52_bipolar").get<double>());
        x.set_modulation_52___bypass(j.at("modulation_52_bypass").get<double>());
        x.set_modulation_52___power(j.at("modulation_52_power").get<double>());
        x.set_modulation_52___stereo(j.at("modulation_52_stereo").get<double>());
        x.set_modulation_53___amount(j.at("modulation_53_amount").get<double>());
        x.set_modulation_53___bipolar(j.at("modulation_53_bipolar").get<double>());
        x.set_modulation_53___bypass(j.at("modulation_53_bypass").get<double>());
        x.set_modulation_53___power(j.at("modulation_53_power").get<double>());
        x.set_modulation_53___stereo(j.at("modulation_53_stereo").get<double>());
        x.set_modulation_54___amount(j.at("modulation_54_amount").get<double>());
        x.set_modulation_54___bipolar(j.at("modulation_54_bipolar").get<double>());
        x.set_modulation_54___bypass(j.at("modulation_54_bypass").get<double>());
        x.set_modulation_54___power(j.at("modulation_54_power").get<double>());
        x.set_modulation_54___stereo(j.at("modulation_54_stereo").get<double>());
        x.set_modulation_55___amount(j.at("modulation_55_amount").get<double>());
        x.set_modulation_55___bipolar(j.at("modulation_55_bipolar").get<double>());
        x.set_modulation_55___bypass(j.at("modulation_55_bypass").get<double>());
        x.set_modulation_55___power(j.at("modulation_55_power").get<double>());
        x.set_modulation_55___stereo(j.at("modulation_55_stereo").get<double>());
        x.set_modulation_56___amount(j.at("modulation_56_amount").get<double>());
        x.set_modulation_56___bipolar(j.at("modulation_56_bipolar").get<double>());
        x.set_modulation_56___bypass(j.at("modulation_56_bypass").get<double>());
        x.set_modulation_56___power(j.at("modulation_56_power").get<double>());
        x.set_modulation_56___stereo(j.at("modulation_56_stereo").get<double>());
        x.set_modulation_57___amount(j.at("modulation_57_amount").get<double>());
        x.set_modulation_57___bipolar(j.at("modulation_57_bipolar").get<double>());
        x.set_modulation_57___bypass(j.at("modulation_57_bypass").get<double>());
        x.set_modulation_57___power(j.at("modulation_57_power").get<double>());
        x.set_modulation_57___stereo(j.at("modulation_57_stereo").get<double>());
        x.set_modulation_58___amount(j.at("modulation_58_amount").get<double>());
        x.set_modulation_58___bipolar(j.at("modulation_58_bipolar").get<double>());
        x.set_modulation_58___bypass(j.at("modulation_58_bypass").get<double>());
        x.set_modulation_58___power(j.at("modulation_58_power").get<double>());
        x.set_modulation_58___stereo(j.at("modulation_58_stereo").get<double>());
        x.set_modulation_59___amount(j.at("modulation_59_amount").get<double>());
        x.set_modulation_59___bipolar(j.at("modulation_59_bipolar").get<double>());
        x.set_modulation_59___bypass(j.at("modulation_59_bypass").get<double>());
        x.set_modulation_59___power(j.at("modulation_59_power").get<double>());
        x.set_modulation_59___stereo(j.at("modulation_59_stereo").get<double>());
        x.set_modulation_5___amount(j.at("modulation_5_amount").get<double>());
        x.set_modulation_5___bipolar(j.at("modulation_5_bipolar").get<double>());
        x.set_modulation_5___bypass(j.at("modulation_5_bypass").get<double>());
        x.set_modulation_5___power(j.at("modulation_5_power").get<double>());
        x.set_modulation_5___stereo(j.at("modulation_5_stereo").get<double>());
        x.set_modulation_60___amount(j.at("modulation_60_amount").get<double>());
        x.set_modulation_60___bipolar(j.at("modulation_60_bipolar").get<double>());
        x.set_modulation_60___bypass(j.at("modulation_60_bypass").get<double>());
        x.set_modulation_60___power(j.at("modulation_60_power").get<double>());
        x.set_modulation_60___stereo(j.at("modulation_60_stereo").get<double>());
        x.set_modulation_61___amount(j.at("modulation_61_amount").get<double>());
        x.set_modulation_61___bipolar(j.at("modulation_61_bipolar").get<double>());
        x.set_modulation_61___bypass(j.at("modulation_61_bypass").get<double>());
        x.set_modulation_61___power(j.at("modulation_61_power").get<double>());
        x.set_modulation_61___stereo(j.at("modulation_61_stereo").get<double>());
        x.set_modulation_62___amount(j.at("modulation_62_amount").get<double>());
        x.set_modulation_62___bipolar(j.at("modulation_62_bipolar").get<double>());
        x.set_modulation_62___bypass(j.at("modulation_62_bypass").get<double>());
        x.set_modulation_62___power(j.at("modulation_62_power").get<double>());
        x.set_modulation_62___stereo(j.at("modulation_62_stereo").get<double>());
        x.set_modulation_63___amount(j.at("modulation_63_amount").get<double>());
        x.set_modulation_63___bipolar(j.at("modulation_63_bipolar").get<double>());
        x.set_modulation_63___bypass(j.at("modulation_63_bypass").get<double>());
        x.set_modulation_63___power(j.at("modulation_63_power").get<double>());
        x.set_modulation_63___stereo(j.at("modulation_63_stereo").get<double>());
        x.set_modulation_64___amount(j.at("modulation_64_amount").get<double>());
        x.set_modulation_64___bipolar(j.at("modulation_64_bipolar").get<double>());
        x.set_modulation_64___bypass(j.at("modulation_64_bypass").get<double>());
        x.set_modulation_64___power(j.at("modulation_64_power").get<double>());
        x.set_modulation_64___stereo(j.at("modulation_64_stereo").get<double>());
        x.set_modulation_6___amount(j.at("modulation_6_amount").get<double>());
        x.set_modulation_6___bipolar(j.at("modulation_6_bipolar").get<double>());
        x.set_modulation_6___bypass(j.at("modulation_6_bypass").get<double>());
        x.set_modulation_6___power(j.at("modulation_6_power").get<double>());
        x.set_modulation_6___stereo(j.at("modulation_6_stereo").get<double>());
        x.set_modulation_7___amount(j.at("modulation_7_amount").get<double>());
        x.set_modulation_7___bipolar(j.at("modulation_7_bipolar").get<double>());
        x.set_modulation_7___bypass(j.at("modulation_7_bypass").get<double>());
        x.set_modulation_7___power(j.at("modulation_7_power").get<double>());
        x.set_modulation_7___stereo(j.at("modulation_7_stereo").get<double>());
        x.set_modulation_8___amount(j.at("modulation_8_amount").get<double>());
        x.set_modulation_8___bipolar(j.at("modulation_8_bipolar").get<double>());
        x.set_modulation_8___bypass(j.at("modulation_8_bypass").get<double>());
        x.set_modulation_8___power(j.at("modulation_8_power").get<double>());
        x.set_modulation_8___stereo(j.at("modulation_8_stereo").get<double>());
        x.set_modulation_9___amount(j.at("modulation_9_amount").get<double>());
        x.set_modulation_9___bipolar(j.at("modulation_9_bipolar").get<double>());
        x.set_modulation_9___bypass(j.at("modulation_9_bypass").get<double>());
        x.set_modulation_9___power(j.at("modulation_9_power").get<double>());
        x.set_modulation_9___stereo(j.at("modulation_9_stereo").get<double>());
        x.set_modulations(j.at("modulations").get<std::vector<quicktype::Modulation>>());
        x.set_osc_1___destination(j.at("osc_1_destination").get<double>());
        x.set_osc_1___detune_power(j.at("osc_1_detune_power").get<double>());
        x.set_osc_1___detune_range(j.at("osc_1_detune_range").get<double>());
        x.set_osc_1___distortion_amount(j.at("osc_1_distortion_amount").get<double>());
        x.set_osc_1___distortion_phase(j.at("osc_1_distortion_phase").get<double>());
        x.set_osc_1___distortion_spread(j.at("osc_1_distortion_spread").get<double>());
        x.set_osc_1___distortion_type(j.at("osc_1_distortion_type").get<double>());
        x.set_osc_1___frame_spread(j.at("osc_1_frame_spread").get<double>());
        x.set_osc_1___level(j.at("osc_1_level").get<double>());
        x.set_osc_1___midi_track(j.at("osc_1_midi_track").get<double>());
        x.set_osc_1___on(j.at("osc_1_on").get<double>());
        x.set_osc_1___pan(j.at("osc_1_pan").get<double>());
        x.set_osc_1___phase(j.at("osc_1_phase").get<double>());
        x.set_osc_1___random_phase(j.at("osc_1_random_phase").get<double>());
        x.set_osc_1___smooth_interpolation(j.at("osc_1_smooth_interpolation").get<double>());
        x.set_osc_1___spectral_morph_amount(j.at("osc_1_spectral_morph_amount").get<double>());
        x.set_osc_1___spectral_morph_spread(j.at("osc_1_spectral_morph_spread").get<double>());
        x.set_osc_1___spectral_morph_type(j.at("osc_1_spectral_morph_type").get<double>());
        x.set_osc_1___spectral_unison(j.at("osc_1_spectral_unison").get<double>());
        x.set_osc_1___stack_style(j.at("osc_1_stack_style").get<double>());
        x.set_osc_1___stereo_spread(j.at("osc_1_stereo_spread").get<double>());
        x.set_osc_1___transpose(j.at("osc_1_transpose").get<double>());
        x.set_osc_1___transpose_quantize(j.at("osc_1_transpose_quantize").get<double>());
        x.set_osc_1___tune(j.at("osc_1_tune").get<double>());
        x.set_osc_1___unison_blend(j.at("osc_1_unison_blend").get<double>());
        x.set_osc_1___unison_detune(j.at("osc_1_unison_detune").get<double>());
        x.set_osc_1___unison_voices(j.at("osc_1_unison_voices").get<double>());
        x.set_osc_1___view_2__d(j.at("osc_1_view_2d").get<double>());
        x.set_osc_1___wave_frame(j.at("osc_1_wave_frame").get<double>());
        x.set_osc_2___destination(j.at("osc_2_destination").get<double>());
        x.set_osc_2___detune_power(j.at("osc_2_detune_power").get<double>());
        x.set_osc_2___detune_range(j.at("osc_2_detune_range").get<double>());
        x.set_osc_2___distortion_amount(j.at("osc_2_distortion_amount").get<double>());
        x.set_osc_2___distortion_phase(j.at("osc_2_distortion_phase").get<double>());
        x.set_osc_2___distortion_spread(j.at("osc_2_distortion_spread").get<double>());
        x.set_osc_2___distortion_type(j.at("osc_2_distortion_type").get<double>());
        x.set_osc_2___frame_spread(j.at("osc_2_frame_spread").get<double>());
        x.set_osc_2___level(j.at("osc_2_level").get<double>());
        x.set_osc_2___midi_track(j.at("osc_2_midi_track").get<double>());
        x.set_osc_2___on(j.at("osc_2_on").get<double>());
        x.set_osc_2___pan(j.at("osc_2_pan").get<double>());
        x.set_osc_2___phase(j.at("osc_2_phase").get<double>());
        x.set_osc_2___random_phase(j.at("osc_2_random_phase").get<double>());
        x.set_osc_2___smooth_interpolation(j.at("osc_2_smooth_interpolation").get<double>());
        x.set_osc_2___spectral_morph_amount(j.at("osc_2_spectral_morph_amount").get<double>());
        x.set_osc_2___spectral_morph_spread(j.at("osc_2_spectral_morph_spread").get<double>());
        x.set_osc_2___spectral_morph_type(j.at("osc_2_spectral_morph_type").get<double>());
        x.set_osc_2___spectral_unison(j.at("osc_2_spectral_unison").get<double>());
        x.set_osc_2___stack_style(j.at("osc_2_stack_style").get<double>());
        x.set_osc_2___stereo_spread(j.at("osc_2_stereo_spread").get<double>());
        x.set_osc_2___transpose(j.at("osc_2_transpose").get<double>());
        x.set_osc_2___transpose_quantize(j.at("osc_2_transpose_quantize").get<double>());
        x.set_osc_2___tune(j.at("osc_2_tune").get<double>());
        x.set_osc_2___unison_blend(j.at("osc_2_unison_blend").get<double>());
        x.set_osc_2___unison_detune(j.at("osc_2_unison_detune").get<double>());
        x.set_osc_2___unison_voices(j.at("osc_2_unison_voices").get<double>());
        x.set_osc_2___view_2__d(j.at("osc_2_view_2d").get<double>());
        x.set_osc_2___wave_frame(j.at("osc_2_wave_frame").get<double>());
        x.set_osc_3___destination(j.at("osc_3_destination").get<double>());
        x.set_osc_3___detune_power(j.at("osc_3_detune_power").get<double>());
        x.set_osc_3___detune_range(j.at("osc_3_detune_range").get<double>());
        x.set_osc_3___distortion_amount(j.at("osc_3_distortion_amount").get<double>());
        x.set_osc_3___distortion_phase(j.at("osc_3_distortion_phase").get<double>());
        x.set_osc_3___distortion_spread(j.at("osc_3_distortion_spread").get<double>());
        x.set_osc_3___distortion_type(j.at("osc_3_distortion_type").get<double>());
        x.set_osc_3___frame_spread(j.at("osc_3_frame_spread").get<double>());
        x.set_osc_3___level(j.at("osc_3_level").get<double>());
        x.set_osc_3___midi_track(j.at("osc_3_midi_track").get<double>());
        x.set_osc_3___on(j.at("osc_3_on").get<double>());
        x.set_osc_3___pan(j.at("osc_3_pan").get<double>());
        x.set_osc_3___phase(j.at("osc_3_phase").get<double>());
        x.set_osc_3___random_phase(j.at("osc_3_random_phase").get<double>());
        x.set_osc_3___smooth_interpolation(j.at("osc_3_smooth_interpolation").get<double>());
        x.set_osc_3___spectral_morph_amount(j.at("osc_3_spectral_morph_amount").get<double>());
        x.set_osc_3___spectral_morph_spread(j.at("osc_3_spectral_morph_spread").get<double>());
        x.set_osc_3___spectral_morph_type(j.at("osc_3_spectral_morph_type").get<double>());
        x.set_osc_3___spectral_unison(j.at("osc_3_spectral_unison").get<double>());
        x.set_osc_3___stack_style(j.at("osc_3_stack_style").get<double>());
        x.set_osc_3___stereo_spread(j.at("osc_3_stereo_spread").get<double>());
        x.set_osc_3___transpose(j.at("osc_3_transpose").get<double>());
        x.set_osc_3___transpose_quantize(j.at("osc_3_transpose_quantize").get<double>());
        x.set_osc_3___tune(j.at("osc_3_tune").get<double>());
        x.set_osc_3___unison_blend(j.at("osc_3_unison_blend").get<double>());
        x.set_osc_3___unison_detune(j.at("osc_3_unison_detune").get<double>());
        x.set_osc_3___unison_voices(j.at("osc_3_unison_voices").get<double>());
        x.set_osc_3___view_2__d(j.at("osc_3_view_2d").get<double>());
        x.set_osc_3___wave_frame(j.at("osc_3_wave_frame").get<double>());
        x.set_oversampling(j.at("oversampling").get<double>());
        x.set_phaser_blend(j.at("phaser_blend").get<double>());
        x.set_phaser_center(j.at("phaser_center").get<double>());
        x.set_phaser_dry_wet(j.at("phaser_dry_wet").get<double>());
        x.set_phaser_feedback(j.at("phaser_feedback").get<double>());
        x.set_phaser_frequency(j.at("phaser_frequency").get<double>());
        x.set_phaser_mod_depth(j.at("phaser_mod_depth").get<double>());
        x.set_phaser_on(j.at("phaser_on").get<double>());
        x.set_phaser_phase_offset(j.at("phaser_phase_offset").get<double>());
        x.set_phaser_sync(j.at("phaser_sync").get<double>());
        x.set_phaser_tempo(j.at("phaser_tempo").get<double>());
        x.set_pitch_bend_range(j.at("pitch_bend_range").get<double>());
        x.set_pitch_wheel(j.at("pitch_wheel").get<double>());
        x.set_polyphony(j.at("polyphony").get<double>());
        x.set_portamento_force(j.at("portamento_force").get<double>());
        x.set_portamento_scale(j.at("portamento_scale").get<double>());
        x.set_portamento_slope(j.at("portamento_slope").get<double>());
        x.set_portamento_time(j.at("portamento_time").get<double>());
        x.set_random_1___frequency(j.at("random_1_frequency").get<double>());
        x.set_random_1___keytrack_transpose(quicktype::get_optional<double>(j, "random_1_keytrack_transpose"));
        x.set_random_1___keytrack_tune(quicktype::get_optional<double>(j, "random_1_keytrack_tune"));
        x.set_random_1___stereo(j.at("random_1_stereo").get<double>());
        x.set_random_1___style(j.at("random_1_style").get<double>());
        x.set_random_1___sync(j.at("random_1_sync").get<double>());
        x.set_random_1___sync_type(j.at("random_1_sync_type").get<double>());
        x.set_random_1___tempo(j.at("random_1_tempo").get<double>());
        x.set_random_2___frequency(j.at("random_2_frequency").get<double>());
        x.set_random_2___keytrack_transpose(quicktype::get_optional<double>(j, "random_2_keytrack_transpose"));
        x.set_random_2___keytrack_tune(quicktype::get_optional<double>(j, "random_2_keytrack_tune"));
        x.set_random_2___stereo(j.at("random_2_stereo").get<double>());
        x.set_random_2___style(j.at("random_2_style").get<double>());
        x.set_random_2___sync(j.at("random_2_sync").get<double>());
        x.set_random_2___sync_type(j.at("random_2_sync_type").get<double>());
        x.set_random_2___tempo(j.at("random_2_tempo").get<double>());
        x.set_random_3___frequency(j.at("random_3_frequency").get<double>());
        x.set_random_3___keytrack_transpose(quicktype::get_optional<double>(j, "random_3_keytrack_transpose"));
        x.set_random_3___keytrack_tune(quicktype::get_optional<double>(j, "random_3_keytrack_tune"));
        x.set_random_3___stereo(j.at("random_3_stereo").get<double>());
        x.set_random_3___style(j.at("random_3_style").get<double>());
        x.set_random_3___sync(j.at("random_3_sync").get<double>());
        x.set_random_3___sync_type(j.at("random_3_sync_type").get<double>());
        x.set_random_3___tempo(j.at("random_3_tempo").get<double>());
        x.set_random_4___frequency(j.at("random_4_frequency").get<double>());
        x.set_random_4___keytrack_transpose(quicktype::get_optional<double>(j, "random_4_keytrack_transpose"));
        x.set_random_4___keytrack_tune(quicktype::get_optional<double>(j, "random_4_keytrack_tune"));
        x.set_random_4___stereo(j.at("random_4_stereo").get<double>());
        x.set_random_4___style(j.at("random_4_style").get<double>());
        x.set_random_4___sync(j.at("random_4_sync").get<double>());
        x.set_random_4___sync_type(j.at("random_4_sync_type").get<double>());
        x.set_random_4___tempo(j.at("random_4_tempo").get<double>());
        x.set_reverb_chorus_amount(j.at("reverb_chorus_amount").get<double>());
        x.set_reverb_chorus_frequency(j.at("reverb_chorus_frequency").get<double>());
        x.set_reverb_decay_time(j.at("reverb_decay_time").get<double>());
        x.set_reverb_delay(quicktype::get_optional<double>(j, "reverb_delay"));
        x.set_reverb_dry_wet(j.at("reverb_dry_wet").get<double>());
        x.set_reverb_high_shelf_cutoff(j.at("reverb_high_shelf_cutoff").get<double>());
        x.set_reverb_high_shelf_gain(j.at("reverb_high_shelf_gain").get<double>());
        x.set_reverb_low_shelf_cutoff(j.at("reverb_low_shelf_cutoff").get<double>());
        x.set_reverb_low_shelf_gain(j.at("reverb_low_shelf_gain").get<double>());
        x.set_reverb_on(j.at("reverb_on").get<double>());
        x.set_reverb_pre_high_cutoff(j.at("reverb_pre_high_cutoff").get<double>());
        x.set_reverb_pre_low_cutoff(j.at("reverb_pre_low_cutoff").get<double>());
        x.set_reverb_size(j.at("reverb_size").get<double>());
        x.set_sample(j.at("sample").get<quicktype::Sample>());
        x.set_sample_bounce(quicktype::get_optional<double>(j, "sample_bounce"));
        x.set_sample_destination(j.at("sample_destination").get<double>());
        x.set_sample_keytrack(j.at("sample_keytrack").get<double>());
        x.set_sample_level(j.at("sample_level").get<double>());
        x.set_sample_loop(j.at("sample_loop").get<double>());
        x.set_sample_on(j.at("sample_on").get<double>());
        x.set_sample_pan(j.at("sample_pan").get<double>());
        x.set_sample_random_phase(j.at("sample_random_phase").get<double>());
        x.set_sample_transpose(j.at("sample_transpose").get<double>());
        x.set_sample_transpose_quantize(j.at("sample_transpose_quantize").get<double>());
        x.set_sample_tune(j.at("sample_tune").get<double>());
        x.set_stereo_mode(quicktype::get_optional<double>(j, "stereo_mode"));
        x.set_stereo_routing(j.at("stereo_routing").get<double>());
        x.set_velocity_track(j.at("velocity_track").get<double>());
        x.set_view_spectrogram(quicktype::get_optional<double>(j, "view_spectrogram"));
        x.set_voice_amplitude(j.at("voice_amplitude").get<double>());
        x.set_voice_override(quicktype::get_optional<double>(j, "voice_override"));
        x.set_voice_priority(j.at("voice_priority").get<double>());
        x.set_voice_transpose(quicktype::get_optional<double>(j, "voice_transpose"));
        x.set_voice_tune(j.at("voice_tune").get<double>());
        x.set_volume(j.at("volume").get<double>());
        x.set_wavetables(j.at("wavetables").get<std::vector<quicktype::Wavetable>>());
    }

    inline void to_json(json & j, const quicktype::PresetSettings & x) {
        j = json::object();
        j["beats_per_minute"] = x.get_beats_per_minute();
        j["bypass"] = x.get_bypass();
        j["chorus_cutoff"] = x.get_chorus_cutoff();
        j["chorus_damping"] = x.get_chorus_damping();
        j["chorus_delay_1"] = x.get_chorus_delay_1();
        j["chorus_delay_2"] = x.get_chorus_delay_2();
        j["chorus_dry_wet"] = x.get_chorus_dry_wet();
        j["chorus_feedback"] = x.get_chorus_feedback();
        j["chorus_frequency"] = x.get_chorus_frequency();
        j["chorus_mod_depth"] = x.get_chorus_mod_depth();
        j["chorus_on"] = x.get_chorus_on();
        j["chorus_spread"] = x.get_chorus_spread();
        j["chorus_sync"] = x.get_chorus_sync();
        j["chorus_tempo"] = x.get_chorus_tempo();
        j["chorus_voices"] = x.get_chorus_voices();
        j["compressor_attack"] = x.get_compressor_attack();
        j["compressor_band_gain"] = x.get_compressor_band_gain();
        j["compressor_band_lower_ratio"] = x.get_compressor_band_lower_ratio();
        j["compressor_band_lower_threshold"] = x.get_compressor_band_lower_threshold();
        j["compressor_band_upper_ratio"] = x.get_compressor_band_upper_ratio();
        j["compressor_band_upper_threshold"] = x.get_compressor_band_upper_threshold();
        j["compressor_enabled_bands"] = x.get_compressor_enabled_bands();
        j["compressor_high_gain"] = x.get_compressor_high_gain();
        j["compressor_high_lower_ratio"] = x.get_compressor_high_lower_ratio();
        j["compressor_high_lower_threshold"] = x.get_compressor_high_lower_threshold();
        j["compressor_high_upper_ratio"] = x.get_compressor_high_upper_ratio();
        j["compressor_high_upper_threshold"] = x.get_compressor_high_upper_threshold();
        j["compressor_low_gain"] = x.get_compressor_low_gain();
        j["compressor_low_lower_ratio"] = x.get_compressor_low_lower_ratio();
        j["compressor_low_lower_threshold"] = x.get_compressor_low_lower_threshold();
        j["compressor_low_upper_ratio"] = x.get_compressor_low_upper_ratio();
        j["compressor_low_upper_threshold"] = x.get_compressor_low_upper_threshold();
        j["compressor_mix"] = x.get_compressor_mix();
        j["compressor_on"] = x.get_compressor_on();
        j["compressor_release"] = x.get_compressor_release();
        j["delay_aux_frequency"] = x.get_delay_aux_frequency();
        j["delay_aux_sync"] = x.get_delay_aux_sync();
        j["delay_aux_tempo"] = x.get_delay_aux_tempo();
        j["delay_dry_wet"] = x.get_delay_dry_wet();
        j["delay_feedback"] = x.get_delay_feedback();
        j["delay_filter_cutoff"] = x.get_delay_filter_cutoff();
        j["delay_filter_spread"] = x.get_delay_filter_spread();
        j["delay_frequency"] = x.get_delay_frequency();
        j["delay_on"] = x.get_delay_on();
        j["delay_style"] = x.get_delay_style();
        j["delay_sync"] = x.get_delay_sync();
        j["delay_tempo"] = x.get_delay_tempo();
        j["distortion_drive"] = x.get_distortion_drive();
        j["distortion_filter_blend"] = x.get_distortion_filter_blend();
        j["distortion_filter_cutoff"] = x.get_distortion_filter_cutoff();
        j["distortion_filter_order"] = x.get_distortion_filter_order();
        j["distortion_filter_resonance"] = x.get_distortion_filter_resonance();
        j["distortion_mix"] = x.get_distortion_mix();
        j["distortion_on"] = x.get_distortion_on();
        j["distortion_type"] = x.get_distortion_type();
        j["effect_chain_order"] = x.get_effect_chain_order();
        j["env_1_attack"] = x.get_env_1___attack();
        j["env_1_attack_power"] = x.get_env_1___attack_power();
        j["env_1_decay"] = x.get_env_1___decay();
        j["env_1_decay_power"] = x.get_env_1___decay_power();
        j["env_1_delay"] = x.get_env_1___delay();
        j["env_1_hold"] = x.get_env_1___hold();
        j["env_1_release"] = x.get_env_1___release();
        j["env_1_release_power"] = x.get_env_1___release_power();
        j["env_1_sustain"] = x.get_env_1___sustain();
        j["env_2_attack"] = x.get_env_2___attack();
        j["env_2_attack_power"] = x.get_env_2___attack_power();
        j["env_2_decay"] = x.get_env_2___decay();
        j["env_2_decay_power"] = x.get_env_2___decay_power();
        j["env_2_delay"] = x.get_env_2___delay();
        j["env_2_hold"] = x.get_env_2___hold();
        j["env_2_release"] = x.get_env_2___release();
        j["env_2_release_power"] = x.get_env_2___release_power();
        j["env_2_sustain"] = x.get_env_2___sustain();
        j["env_3_attack"] = x.get_env_3___attack();
        j["env_3_attack_power"] = x.get_env_3___attack_power();
        j["env_3_decay"] = x.get_env_3___decay();
        j["env_3_decay_power"] = x.get_env_3___decay_power();
        j["env_3_delay"] = x.get_env_3___delay();
        j["env_3_hold"] = x.get_env_3___hold();
        j["env_3_release"] = x.get_env_3___release();
        j["env_3_release_power"] = x.get_env_3___release_power();
        j["env_3_sustain"] = x.get_env_3___sustain();
        j["env_4_attack"] = x.get_env_4___attack();
        j["env_4_attack_power"] = x.get_env_4___attack_power();
        j["env_4_decay"] = x.get_env_4___decay();
        j["env_4_decay_power"] = x.get_env_4___decay_power();
        j["env_4_delay"] = x.get_env_4___delay();
        j["env_4_hold"] = x.get_env_4___hold();
        j["env_4_release"] = x.get_env_4___release();
        j["env_4_release_power"] = x.get_env_4___release_power();
        j["env_4_sustain"] = x.get_env_4___sustain();
        j["env_5_attack"] = x.get_env_5___attack();
        j["env_5_attack_power"] = x.get_env_5___attack_power();
        j["env_5_decay"] = x.get_env_5___decay();
        j["env_5_decay_power"] = x.get_env_5___decay_power();
        j["env_5_delay"] = x.get_env_5___delay();
        j["env_5_hold"] = x.get_env_5___hold();
        j["env_5_release"] = x.get_env_5___release();
        j["env_5_release_power"] = x.get_env_5___release_power();
        j["env_5_sustain"] = x.get_env_5___sustain();
        j["env_6_attack"] = x.get_env_6___attack();
        j["env_6_attack_power"] = x.get_env_6___attack_power();
        j["env_6_decay"] = x.get_env_6___decay();
        j["env_6_decay_power"] = x.get_env_6___decay_power();
        j["env_6_delay"] = x.get_env_6___delay();
        j["env_6_hold"] = x.get_env_6___hold();
        j["env_6_release"] = x.get_env_6___release();
        j["env_6_release_power"] = x.get_env_6___release_power();
        j["env_6_sustain"] = x.get_env_6___sustain();
        j["eq_band_cutoff"] = x.get_eq_band_cutoff();
        j["eq_band_gain"] = x.get_eq_band_gain();
        j["eq_band_mode"] = x.get_eq_band_mode();
        j["eq_band_resonance"] = x.get_eq_band_resonance();
        j["eq_high_cutoff"] = x.get_eq_high_cutoff();
        j["eq_high_gain"] = x.get_eq_high_gain();
        j["eq_high_mode"] = x.get_eq_high_mode();
        j["eq_high_resonance"] = x.get_eq_high_resonance();
        j["eq_low_cutoff"] = x.get_eq_low_cutoff();
        j["eq_low_gain"] = x.get_eq_low_gain();
        j["eq_low_mode"] = x.get_eq_low_mode();
        j["eq_low_resonance"] = x.get_eq_low_resonance();
        j["eq_on"] = x.get_eq_on();
        j["filter_1_blend"] = x.get_filter_1___blend();
        j["filter_1_blend_transpose"] = x.get_filter_1___blend_transpose();
        j["filter_1_cutoff"] = x.get_filter_1___cutoff();
        j["filter_1_drive"] = x.get_filter_1___drive();
        j["filter_1_filter_input"] = x.get_filter_1___filter_input();
        j["filter_1_formant_resonance"] = x.get_filter_1___formant_resonance();
        j["filter_1_formant_spread"] = x.get_filter_1___formant_spread();
        j["filter_1_formant_transpose"] = x.get_filter_1___formant_transpose();
        j["filter_1_formant_x"] = x.get_filter_1___formant_x();
        j["filter_1_formant_y"] = x.get_filter_1___formant_y();
        j["filter_1_keytrack"] = x.get_filter_1___keytrack();
        j["filter_1_mix"] = x.get_filter_1___mix();
        j["filter_1_model"] = x.get_filter_1___model();
        j["filter_1_on"] = x.get_filter_1___on();
        j["filter_1_resonance"] = x.get_filter_1___resonance();
        j["filter_1_style"] = x.get_filter_1___style();
        j["filter_2_blend"] = x.get_filter_2___blend();
        j["filter_2_blend_transpose"] = x.get_filter_2___blend_transpose();
        j["filter_2_cutoff"] = x.get_filter_2___cutoff();
        j["filter_2_drive"] = x.get_filter_2___drive();
        j["filter_2_filter_input"] = x.get_filter_2___filter_input();
        j["filter_2_formant_resonance"] = x.get_filter_2___formant_resonance();
        j["filter_2_formant_spread"] = x.get_filter_2___formant_spread();
        j["filter_2_formant_transpose"] = x.get_filter_2___formant_transpose();
        j["filter_2_formant_x"] = x.get_filter_2___formant_x();
        j["filter_2_formant_y"] = x.get_filter_2___formant_y();
        j["filter_2_keytrack"] = x.get_filter_2___keytrack();
        j["filter_2_mix"] = x.get_filter_2___mix();
        j["filter_2_model"] = x.get_filter_2___model();
        j["filter_2_on"] = x.get_filter_2___on();
        j["filter_2_resonance"] = x.get_filter_2___resonance();
        j["filter_2_style"] = x.get_filter_2___style();
        j["filter_fx_blend"] = x.get_filter_fx_blend();
        j["filter_fx_blend_transpose"] = x.get_filter_fx_blend_transpose();
        j["filter_fx_cutoff"] = x.get_filter_fx_cutoff();
        j["filter_fx_drive"] = x.get_filter_fx_drive();
        j["filter_fx_formant_resonance"] = x.get_filter_fx_formant_resonance();
        j["filter_fx_formant_spread"] = x.get_filter_fx_formant_spread();
        j["filter_fx_formant_transpose"] = x.get_filter_fx_formant_transpose();
        j["filter_fx_formant_x"] = x.get_filter_fx_formant_x();
        j["filter_fx_formant_y"] = x.get_filter_fx_formant_y();
        j["filter_fx_keytrack"] = x.get_filter_fx_keytrack();
        j["filter_fx_mix"] = x.get_filter_fx_mix();
        j["filter_fx_model"] = x.get_filter_fx_model();
        j["filter_fx_on"] = x.get_filter_fx_on();
        j["filter_fx_resonance"] = x.get_filter_fx_resonance();
        j["filter_fx_style"] = x.get_filter_fx_style();
        j["flanger_center"] = x.get_flanger_center();
        j["flanger_dry_wet"] = x.get_flanger_dry_wet();
        j["flanger_feedback"] = x.get_flanger_feedback();
        j["flanger_frequency"] = x.get_flanger_frequency();
        j["flanger_mod_depth"] = x.get_flanger_mod_depth();
        j["flanger_on"] = x.get_flanger_on();
        j["flanger_phase_offset"] = x.get_flanger_phase_offset();
        j["flanger_sync"] = x.get_flanger_sync();
        j["flanger_tempo"] = x.get_flanger_tempo();
        j["legato"] = x.get_legato();
        j["lfo_1_delay_time"] = x.get_lfo_1___delay_time();
        j["lfo_1_fade_time"] = x.get_lfo_1___fade_time();
        j["lfo_1_frequency"] = x.get_lfo_1___frequency();
        j["lfo_1_keytrack_transpose"] = x.get_lfo_1___keytrack_transpose();
        j["lfo_1_keytrack_tune"] = x.get_lfo_1___keytrack_tune();
        j["lfo_1_phase"] = x.get_lfo_1___phase();
        j["lfo_1_smooth_mode"] = x.get_lfo_1___smooth_mode();
        j["lfo_1_smooth_time"] = x.get_lfo_1___smooth_time();
        j["lfo_1_stereo"] = x.get_lfo_1___stereo();
        j["lfo_1_sync"] = x.get_lfo_1___sync();
        j["lfo_1_sync_type"] = x.get_lfo_1___sync_type();
        j["lfo_1_tempo"] = x.get_lfo_1___tempo();
        j["lfo_2_delay_time"] = x.get_lfo_2___delay_time();
        j["lfo_2_fade_time"] = x.get_lfo_2___fade_time();
        j["lfo_2_frequency"] = x.get_lfo_2___frequency();
        j["lfo_2_keytrack_transpose"] = x.get_lfo_2___keytrack_transpose();
        j["lfo_2_keytrack_tune"] = x.get_lfo_2___keytrack_tune();
        j["lfo_2_phase"] = x.get_lfo_2___phase();
        j["lfo_2_smooth_mode"] = x.get_lfo_2___smooth_mode();
        j["lfo_2_smooth_time"] = x.get_lfo_2___smooth_time();
        j["lfo_2_stereo"] = x.get_lfo_2___stereo();
        j["lfo_2_sync"] = x.get_lfo_2___sync();
        j["lfo_2_sync_type"] = x.get_lfo_2___sync_type();
        j["lfo_2_tempo"] = x.get_lfo_2___tempo();
        j["lfo_3_delay_time"] = x.get_lfo_3___delay_time();
        j["lfo_3_fade_time"] = x.get_lfo_3___fade_time();
        j["lfo_3_frequency"] = x.get_lfo_3___frequency();
        j["lfo_3_keytrack_transpose"] = x.get_lfo_3___keytrack_transpose();
        j["lfo_3_keytrack_tune"] = x.get_lfo_3___keytrack_tune();
        j["lfo_3_phase"] = x.get_lfo_3___phase();
        j["lfo_3_smooth_mode"] = x.get_lfo_3___smooth_mode();
        j["lfo_3_smooth_time"] = x.get_lfo_3___smooth_time();
        j["lfo_3_stereo"] = x.get_lfo_3___stereo();
        j["lfo_3_sync"] = x.get_lfo_3___sync();
        j["lfo_3_sync_type"] = x.get_lfo_3___sync_type();
        j["lfo_3_tempo"] = x.get_lfo_3___tempo();
        j["lfo_4_delay_time"] = x.get_lfo_4___delay_time();
        j["lfo_4_fade_time"] = x.get_lfo_4___fade_time();
        j["lfo_4_frequency"] = x.get_lfo_4___frequency();
        j["lfo_4_keytrack_transpose"] = x.get_lfo_4___keytrack_transpose();
        j["lfo_4_keytrack_tune"] = x.get_lfo_4___keytrack_tune();
        j["lfo_4_phase"] = x.get_lfo_4___phase();
        j["lfo_4_smooth_mode"] = x.get_lfo_4___smooth_mode();
        j["lfo_4_smooth_time"] = x.get_lfo_4___smooth_time();
        j["lfo_4_stereo"] = x.get_lfo_4___stereo();
        j["lfo_4_sync"] = x.get_lfo_4___sync();
        j["lfo_4_sync_type"] = x.get_lfo_4___sync_type();
        j["lfo_4_tempo"] = x.get_lfo_4___tempo();
        j["lfo_5_delay_time"] = x.get_lfo_5___delay_time();
        j["lfo_5_fade_time"] = x.get_lfo_5___fade_time();
        j["lfo_5_frequency"] = x.get_lfo_5___frequency();
        j["lfo_5_keytrack_transpose"] = x.get_lfo_5___keytrack_transpose();
        j["lfo_5_keytrack_tune"] = x.get_lfo_5___keytrack_tune();
        j["lfo_5_phase"] = x.get_lfo_5___phase();
        j["lfo_5_smooth_mode"] = x.get_lfo_5___smooth_mode();
        j["lfo_5_smooth_time"] = x.get_lfo_5___smooth_time();
        j["lfo_5_stereo"] = x.get_lfo_5___stereo();
        j["lfo_5_sync"] = x.get_lfo_5___sync();
        j["lfo_5_sync_type"] = x.get_lfo_5___sync_type();
        j["lfo_5_tempo"] = x.get_lfo_5___tempo();
        j["lfo_6_delay_time"] = x.get_lfo_6___delay_time();
        j["lfo_6_fade_time"] = x.get_lfo_6___fade_time();
        j["lfo_6_frequency"] = x.get_lfo_6___frequency();
        j["lfo_6_keytrack_transpose"] = x.get_lfo_6___keytrack_transpose();
        j["lfo_6_keytrack_tune"] = x.get_lfo_6___keytrack_tune();
        j["lfo_6_phase"] = x.get_lfo_6___phase();
        j["lfo_6_smooth_mode"] = x.get_lfo_6___smooth_mode();
        j["lfo_6_smooth_time"] = x.get_lfo_6___smooth_time();
        j["lfo_6_stereo"] = x.get_lfo_6___stereo();
        j["lfo_6_sync"] = x.get_lfo_6___sync();
        j["lfo_6_sync_type"] = x.get_lfo_6___sync_type();
        j["lfo_6_tempo"] = x.get_lfo_6___tempo();
        j["lfo_7_delay_time"] = x.get_lfo_7___delay_time();
        j["lfo_7_fade_time"] = x.get_lfo_7___fade_time();
        j["lfo_7_frequency"] = x.get_lfo_7___frequency();
        j["lfo_7_keytrack_transpose"] = x.get_lfo_7___keytrack_transpose();
        j["lfo_7_keytrack_tune"] = x.get_lfo_7___keytrack_tune();
        j["lfo_7_phase"] = x.get_lfo_7___phase();
        j["lfo_7_smooth_mode"] = x.get_lfo_7___smooth_mode();
        j["lfo_7_smooth_time"] = x.get_lfo_7___smooth_time();
        j["lfo_7_stereo"] = x.get_lfo_7___stereo();
        j["lfo_7_sync"] = x.get_lfo_7___sync();
        j["lfo_7_sync_type"] = x.get_lfo_7___sync_type();
        j["lfo_7_tempo"] = x.get_lfo_7___tempo();
        j["lfo_8_delay_time"] = x.get_lfo_8___delay_time();
        j["lfo_8_fade_time"] = x.get_lfo_8___fade_time();
        j["lfo_8_frequency"] = x.get_lfo_8___frequency();
        j["lfo_8_keytrack_transpose"] = x.get_lfo_8___keytrack_transpose();
        j["lfo_8_keytrack_tune"] = x.get_lfo_8___keytrack_tune();
        j["lfo_8_phase"] = x.get_lfo_8___phase();
        j["lfo_8_smooth_mode"] = x.get_lfo_8___smooth_mode();
        j["lfo_8_smooth_time"] = x.get_lfo_8___smooth_time();
        j["lfo_8_stereo"] = x.get_lfo_8___stereo();
        j["lfo_8_sync"] = x.get_lfo_8___sync();
        j["lfo_8_sync_type"] = x.get_lfo_8___sync_type();
        j["lfo_8_tempo"] = x.get_lfo_8___tempo();
        j["lfos"] = x.get_lfos();
        j["macro_control_1"] = x.get_macro_control_1();
        j["macro_control_2"] = x.get_macro_control_2();
        j["macro_control_3"] = x.get_macro_control_3();
        j["macro_control_4"] = x.get_macro_control_4();
        j["mod_wheel"] = x.get_mod_wheel();
        j["modulation_10_amount"] = x.get_modulation_10___amount();
        j["modulation_10_bipolar"] = x.get_modulation_10___bipolar();
        j["modulation_10_bypass"] = x.get_modulation_10___bypass();
        j["modulation_10_power"] = x.get_modulation_10___power();
        j["modulation_10_stereo"] = x.get_modulation_10___stereo();
        j["modulation_11_amount"] = x.get_modulation_11___amount();
        j["modulation_11_bipolar"] = x.get_modulation_11___bipolar();
        j["modulation_11_bypass"] = x.get_modulation_11___bypass();
        j["modulation_11_power"] = x.get_modulation_11___power();
        j["modulation_11_stereo"] = x.get_modulation_11___stereo();
        j["modulation_12_amount"] = x.get_modulation_12___amount();
        j["modulation_12_bipolar"] = x.get_modulation_12___bipolar();
        j["modulation_12_bypass"] = x.get_modulation_12___bypass();
        j["modulation_12_power"] = x.get_modulation_12___power();
        j["modulation_12_stereo"] = x.get_modulation_12___stereo();
        j["modulation_13_amount"] = x.get_modulation_13___amount();
        j["modulation_13_bipolar"] = x.get_modulation_13___bipolar();
        j["modulation_13_bypass"] = x.get_modulation_13___bypass();
        j["modulation_13_power"] = x.get_modulation_13___power();
        j["modulation_13_stereo"] = x.get_modulation_13___stereo();
        j["modulation_14_amount"] = x.get_modulation_14___amount();
        j["modulation_14_bipolar"] = x.get_modulation_14___bipolar();
        j["modulation_14_bypass"] = x.get_modulation_14___bypass();
        j["modulation_14_power"] = x.get_modulation_14___power();
        j["modulation_14_stereo"] = x.get_modulation_14___stereo();
        j["modulation_15_amount"] = x.get_modulation_15___amount();
        j["modulation_15_bipolar"] = x.get_modulation_15___bipolar();
        j["modulation_15_bypass"] = x.get_modulation_15___bypass();
        j["modulation_15_power"] = x.get_modulation_15___power();
        j["modulation_15_stereo"] = x.get_modulation_15___stereo();
        j["modulation_16_amount"] = x.get_modulation_16___amount();
        j["modulation_16_bipolar"] = x.get_modulation_16___bipolar();
        j["modulation_16_bypass"] = x.get_modulation_16___bypass();
        j["modulation_16_power"] = x.get_modulation_16___power();
        j["modulation_16_stereo"] = x.get_modulation_16___stereo();
        j["modulation_17_amount"] = x.get_modulation_17___amount();
        j["modulation_17_bipolar"] = x.get_modulation_17___bipolar();
        j["modulation_17_bypass"] = x.get_modulation_17___bypass();
        j["modulation_17_power"] = x.get_modulation_17___power();
        j["modulation_17_stereo"] = x.get_modulation_17___stereo();
        j["modulation_18_amount"] = x.get_modulation_18___amount();
        j["modulation_18_bipolar"] = x.get_modulation_18___bipolar();
        j["modulation_18_bypass"] = x.get_modulation_18___bypass();
        j["modulation_18_power"] = x.get_modulation_18___power();
        j["modulation_18_stereo"] = x.get_modulation_18___stereo();
        j["modulation_19_amount"] = x.get_modulation_19___amount();
        j["modulation_19_bipolar"] = x.get_modulation_19___bipolar();
        j["modulation_19_bypass"] = x.get_modulation_19___bypass();
        j["modulation_19_power"] = x.get_modulation_19___power();
        j["modulation_19_stereo"] = x.get_modulation_19___stereo();
        j["modulation_1_amount"] = x.get_modulation_1___amount();
        j["modulation_1_bipolar"] = x.get_modulation_1___bipolar();
        j["modulation_1_bypass"] = x.get_modulation_1___bypass();
        j["modulation_1_power"] = x.get_modulation_1___power();
        j["modulation_1_stereo"] = x.get_modulation_1___stereo();
        j["modulation_20_amount"] = x.get_modulation_20___amount();
        j["modulation_20_bipolar"] = x.get_modulation_20___bipolar();
        j["modulation_20_bypass"] = x.get_modulation_20___bypass();
        j["modulation_20_power"] = x.get_modulation_20___power();
        j["modulation_20_stereo"] = x.get_modulation_20___stereo();
        j["modulation_21_amount"] = x.get_modulation_21___amount();
        j["modulation_21_bipolar"] = x.get_modulation_21___bipolar();
        j["modulation_21_bypass"] = x.get_modulation_21___bypass();
        j["modulation_21_power"] = x.get_modulation_21___power();
        j["modulation_21_stereo"] = x.get_modulation_21___stereo();
        j["modulation_22_amount"] = x.get_modulation_22___amount();
        j["modulation_22_bipolar"] = x.get_modulation_22___bipolar();
        j["modulation_22_bypass"] = x.get_modulation_22___bypass();
        j["modulation_22_power"] = x.get_modulation_22___power();
        j["modulation_22_stereo"] = x.get_modulation_22___stereo();
        j["modulation_23_amount"] = x.get_modulation_23___amount();
        j["modulation_23_bipolar"] = x.get_modulation_23___bipolar();
        j["modulation_23_bypass"] = x.get_modulation_23___bypass();
        j["modulation_23_power"] = x.get_modulation_23___power();
        j["modulation_23_stereo"] = x.get_modulation_23___stereo();
        j["modulation_24_amount"] = x.get_modulation_24___amount();
        j["modulation_24_bipolar"] = x.get_modulation_24___bipolar();
        j["modulation_24_bypass"] = x.get_modulation_24___bypass();
        j["modulation_24_power"] = x.get_modulation_24___power();
        j["modulation_24_stereo"] = x.get_modulation_24___stereo();
        j["modulation_25_amount"] = x.get_modulation_25___amount();
        j["modulation_25_bipolar"] = x.get_modulation_25___bipolar();
        j["modulation_25_bypass"] = x.get_modulation_25___bypass();
        j["modulation_25_power"] = x.get_modulation_25___power();
        j["modulation_25_stereo"] = x.get_modulation_25___stereo();
        j["modulation_26_amount"] = x.get_modulation_26___amount();
        j["modulation_26_bipolar"] = x.get_modulation_26___bipolar();
        j["modulation_26_bypass"] = x.get_modulation_26___bypass();
        j["modulation_26_power"] = x.get_modulation_26___power();
        j["modulation_26_stereo"] = x.get_modulation_26___stereo();
        j["modulation_27_amount"] = x.get_modulation_27___amount();
        j["modulation_27_bipolar"] = x.get_modulation_27___bipolar();
        j["modulation_27_bypass"] = x.get_modulation_27___bypass();
        j["modulation_27_power"] = x.get_modulation_27___power();
        j["modulation_27_stereo"] = x.get_modulation_27___stereo();
        j["modulation_28_amount"] = x.get_modulation_28___amount();
        j["modulation_28_bipolar"] = x.get_modulation_28___bipolar();
        j["modulation_28_bypass"] = x.get_modulation_28___bypass();
        j["modulation_28_power"] = x.get_modulation_28___power();
        j["modulation_28_stereo"] = x.get_modulation_28___stereo();
        j["modulation_29_amount"] = x.get_modulation_29___amount();
        j["modulation_29_bipolar"] = x.get_modulation_29___bipolar();
        j["modulation_29_bypass"] = x.get_modulation_29___bypass();
        j["modulation_29_power"] = x.get_modulation_29___power();
        j["modulation_29_stereo"] = x.get_modulation_29___stereo();
        j["modulation_2_amount"] = x.get_modulation_2___amount();
        j["modulation_2_bipolar"] = x.get_modulation_2___bipolar();
        j["modulation_2_bypass"] = x.get_modulation_2___bypass();
        j["modulation_2_power"] = x.get_modulation_2___power();
        j["modulation_2_stereo"] = x.get_modulation_2___stereo();
        j["modulation_30_amount"] = x.get_modulation_30___amount();
        j["modulation_30_bipolar"] = x.get_modulation_30___bipolar();
        j["modulation_30_bypass"] = x.get_modulation_30___bypass();
        j["modulation_30_power"] = x.get_modulation_30___power();
        j["modulation_30_stereo"] = x.get_modulation_30___stereo();
        j["modulation_31_amount"] = x.get_modulation_31___amount();
        j["modulation_31_bipolar"] = x.get_modulation_31___bipolar();
        j["modulation_31_bypass"] = x.get_modulation_31___bypass();
        j["modulation_31_power"] = x.get_modulation_31___power();
        j["modulation_31_stereo"] = x.get_modulation_31___stereo();
        j["modulation_32_amount"] = x.get_modulation_32___amount();
        j["modulation_32_bipolar"] = x.get_modulation_32___bipolar();
        j["modulation_32_bypass"] = x.get_modulation_32___bypass();
        j["modulation_32_power"] = x.get_modulation_32___power();
        j["modulation_32_stereo"] = x.get_modulation_32___stereo();
        j["modulation_33_amount"] = x.get_modulation_33___amount();
        j["modulation_33_bipolar"] = x.get_modulation_33___bipolar();
        j["modulation_33_bypass"] = x.get_modulation_33___bypass();
        j["modulation_33_power"] = x.get_modulation_33___power();
        j["modulation_33_stereo"] = x.get_modulation_33___stereo();
        j["modulation_34_amount"] = x.get_modulation_34___amount();
        j["modulation_34_bipolar"] = x.get_modulation_34___bipolar();
        j["modulation_34_bypass"] = x.get_modulation_34___bypass();
        j["modulation_34_power"] = x.get_modulation_34___power();
        j["modulation_34_stereo"] = x.get_modulation_34___stereo();
        j["modulation_35_amount"] = x.get_modulation_35___amount();
        j["modulation_35_bipolar"] = x.get_modulation_35___bipolar();
        j["modulation_35_bypass"] = x.get_modulation_35___bypass();
        j["modulation_35_power"] = x.get_modulation_35___power();
        j["modulation_35_stereo"] = x.get_modulation_35___stereo();
        j["modulation_36_amount"] = x.get_modulation_36___amount();
        j["modulation_36_bipolar"] = x.get_modulation_36___bipolar();
        j["modulation_36_bypass"] = x.get_modulation_36___bypass();
        j["modulation_36_power"] = x.get_modulation_36___power();
        j["modulation_36_stereo"] = x.get_modulation_36___stereo();
        j["modulation_37_amount"] = x.get_modulation_37___amount();
        j["modulation_37_bipolar"] = x.get_modulation_37___bipolar();
        j["modulation_37_bypass"] = x.get_modulation_37___bypass();
        j["modulation_37_power"] = x.get_modulation_37___power();
        j["modulation_37_stereo"] = x.get_modulation_37___stereo();
        j["modulation_38_amount"] = x.get_modulation_38___amount();
        j["modulation_38_bipolar"] = x.get_modulation_38___bipolar();
        j["modulation_38_bypass"] = x.get_modulation_38___bypass();
        j["modulation_38_power"] = x.get_modulation_38___power();
        j["modulation_38_stereo"] = x.get_modulation_38___stereo();
        j["modulation_39_amount"] = x.get_modulation_39___amount();
        j["modulation_39_bipolar"] = x.get_modulation_39___bipolar();
        j["modulation_39_bypass"] = x.get_modulation_39___bypass();
        j["modulation_39_power"] = x.get_modulation_39___power();
        j["modulation_39_stereo"] = x.get_modulation_39___stereo();
        j["modulation_3_amount"] = x.get_modulation_3___amount();
        j["modulation_3_bipolar"] = x.get_modulation_3___bipolar();
        j["modulation_3_bypass"] = x.get_modulation_3___bypass();
        j["modulation_3_power"] = x.get_modulation_3___power();
        j["modulation_3_stereo"] = x.get_modulation_3___stereo();
        j["modulation_40_amount"] = x.get_modulation_40___amount();
        j["modulation_40_bipolar"] = x.get_modulation_40___bipolar();
        j["modulation_40_bypass"] = x.get_modulation_40___bypass();
        j["modulation_40_power"] = x.get_modulation_40___power();
        j["modulation_40_stereo"] = x.get_modulation_40___stereo();
        j["modulation_41_amount"] = x.get_modulation_41___amount();
        j["modulation_41_bipolar"] = x.get_modulation_41___bipolar();
        j["modulation_41_bypass"] = x.get_modulation_41___bypass();
        j["modulation_41_power"] = x.get_modulation_41___power();
        j["modulation_41_stereo"] = x.get_modulation_41___stereo();
        j["modulation_42_amount"] = x.get_modulation_42___amount();
        j["modulation_42_bipolar"] = x.get_modulation_42___bipolar();
        j["modulation_42_bypass"] = x.get_modulation_42___bypass();
        j["modulation_42_power"] = x.get_modulation_42___power();
        j["modulation_42_stereo"] = x.get_modulation_42___stereo();
        j["modulation_43_amount"] = x.get_modulation_43___amount();
        j["modulation_43_bipolar"] = x.get_modulation_43___bipolar();
        j["modulation_43_bypass"] = x.get_modulation_43___bypass();
        j["modulation_43_power"] = x.get_modulation_43___power();
        j["modulation_43_stereo"] = x.get_modulation_43___stereo();
        j["modulation_44_amount"] = x.get_modulation_44___amount();
        j["modulation_44_bipolar"] = x.get_modulation_44___bipolar();
        j["modulation_44_bypass"] = x.get_modulation_44___bypass();
        j["modulation_44_power"] = x.get_modulation_44___power();
        j["modulation_44_stereo"] = x.get_modulation_44___stereo();
        j["modulation_45_amount"] = x.get_modulation_45___amount();
        j["modulation_45_bipolar"] = x.get_modulation_45___bipolar();
        j["modulation_45_bypass"] = x.get_modulation_45___bypass();
        j["modulation_45_power"] = x.get_modulation_45___power();
        j["modulation_45_stereo"] = x.get_modulation_45___stereo();
        j["modulation_46_amount"] = x.get_modulation_46___amount();
        j["modulation_46_bipolar"] = x.get_modulation_46___bipolar();
        j["modulation_46_bypass"] = x.get_modulation_46___bypass();
        j["modulation_46_power"] = x.get_modulation_46___power();
        j["modulation_46_stereo"] = x.get_modulation_46___stereo();
        j["modulation_47_amount"] = x.get_modulation_47___amount();
        j["modulation_47_bipolar"] = x.get_modulation_47___bipolar();
        j["modulation_47_bypass"] = x.get_modulation_47___bypass();
        j["modulation_47_power"] = x.get_modulation_47___power();
        j["modulation_47_stereo"] = x.get_modulation_47___stereo();
        j["modulation_48_amount"] = x.get_modulation_48___amount();
        j["modulation_48_bipolar"] = x.get_modulation_48___bipolar();
        j["modulation_48_bypass"] = x.get_modulation_48___bypass();
        j["modulation_48_power"] = x.get_modulation_48___power();
        j["modulation_48_stereo"] = x.get_modulation_48___stereo();
        j["modulation_49_amount"] = x.get_modulation_49___amount();
        j["modulation_49_bipolar"] = x.get_modulation_49___bipolar();
        j["modulation_49_bypass"] = x.get_modulation_49___bypass();
        j["modulation_49_power"] = x.get_modulation_49___power();
        j["modulation_49_stereo"] = x.get_modulation_49___stereo();
        j["modulation_4_amount"] = x.get_modulation_4___amount();
        j["modulation_4_bipolar"] = x.get_modulation_4___bipolar();
        j["modulation_4_bypass"] = x.get_modulation_4___bypass();
        j["modulation_4_power"] = x.get_modulation_4___power();
        j["modulation_4_stereo"] = x.get_modulation_4___stereo();
        j["modulation_50_amount"] = x.get_modulation_50___amount();
        j["modulation_50_bipolar"] = x.get_modulation_50___bipolar();
        j["modulation_50_bypass"] = x.get_modulation_50___bypass();
        j["modulation_50_power"] = x.get_modulation_50___power();
        j["modulation_50_stereo"] = x.get_modulation_50___stereo();
        j["modulation_51_amount"] = x.get_modulation_51___amount();
        j["modulation_51_bipolar"] = x.get_modulation_51___bipolar();
        j["modulation_51_bypass"] = x.get_modulation_51___bypass();
        j["modulation_51_power"] = x.get_modulation_51___power();
        j["modulation_51_stereo"] = x.get_modulation_51___stereo();
        j["modulation_52_amount"] = x.get_modulation_52___amount();
        j["modulation_52_bipolar"] = x.get_modulation_52___bipolar();
        j["modulation_52_bypass"] = x.get_modulation_52___bypass();
        j["modulation_52_power"] = x.get_modulation_52___power();
        j["modulation_52_stereo"] = x.get_modulation_52___stereo();
        j["modulation_53_amount"] = x.get_modulation_53___amount();
        j["modulation_53_bipolar"] = x.get_modulation_53___bipolar();
        j["modulation_53_bypass"] = x.get_modulation_53___bypass();
        j["modulation_53_power"] = x.get_modulation_53___power();
        j["modulation_53_stereo"] = x.get_modulation_53___stereo();
        j["modulation_54_amount"] = x.get_modulation_54___amount();
        j["modulation_54_bipolar"] = x.get_modulation_54___bipolar();
        j["modulation_54_bypass"] = x.get_modulation_54___bypass();
        j["modulation_54_power"] = x.get_modulation_54___power();
        j["modulation_54_stereo"] = x.get_modulation_54___stereo();
        j["modulation_55_amount"] = x.get_modulation_55___amount();
        j["modulation_55_bipolar"] = x.get_modulation_55___bipolar();
        j["modulation_55_bypass"] = x.get_modulation_55___bypass();
        j["modulation_55_power"] = x.get_modulation_55___power();
        j["modulation_55_stereo"] = x.get_modulation_55___stereo();
        j["modulation_56_amount"] = x.get_modulation_56___amount();
        j["modulation_56_bipolar"] = x.get_modulation_56___bipolar();
        j["modulation_56_bypass"] = x.get_modulation_56___bypass();
        j["modulation_56_power"] = x.get_modulation_56___power();
        j["modulation_56_stereo"] = x.get_modulation_56___stereo();
        j["modulation_57_amount"] = x.get_modulation_57___amount();
        j["modulation_57_bipolar"] = x.get_modulation_57___bipolar();
        j["modulation_57_bypass"] = x.get_modulation_57___bypass();
        j["modulation_57_power"] = x.get_modulation_57___power();
        j["modulation_57_stereo"] = x.get_modulation_57___stereo();
        j["modulation_58_amount"] = x.get_modulation_58___amount();
        j["modulation_58_bipolar"] = x.get_modulation_58___bipolar();
        j["modulation_58_bypass"] = x.get_modulation_58___bypass();
        j["modulation_58_power"] = x.get_modulation_58___power();
        j["modulation_58_stereo"] = x.get_modulation_58___stereo();
        j["modulation_59_amount"] = x.get_modulation_59___amount();
        j["modulation_59_bipolar"] = x.get_modulation_59___bipolar();
        j["modulation_59_bypass"] = x.get_modulation_59___bypass();
        j["modulation_59_power"] = x.get_modulation_59___power();
        j["modulation_59_stereo"] = x.get_modulation_59___stereo();
        j["modulation_5_amount"] = x.get_modulation_5___amount();
        j["modulation_5_bipolar"] = x.get_modulation_5___bipolar();
        j["modulation_5_bypass"] = x.get_modulation_5___bypass();
        j["modulation_5_power"] = x.get_modulation_5___power();
        j["modulation_5_stereo"] = x.get_modulation_5___stereo();
        j["modulation_60_amount"] = x.get_modulation_60___amount();
        j["modulation_60_bipolar"] = x.get_modulation_60___bipolar();
        j["modulation_60_bypass"] = x.get_modulation_60___bypass();
        j["modulation_60_power"] = x.get_modulation_60___power();
        j["modulation_60_stereo"] = x.get_modulation_60___stereo();
        j["modulation_61_amount"] = x.get_modulation_61___amount();
        j["modulation_61_bipolar"] = x.get_modulation_61___bipolar();
        j["modulation_61_bypass"] = x.get_modulation_61___bypass();
        j["modulation_61_power"] = x.get_modulation_61___power();
        j["modulation_61_stereo"] = x.get_modulation_61___stereo();
        j["modulation_62_amount"] = x.get_modulation_62___amount();
        j["modulation_62_bipolar"] = x.get_modulation_62___bipolar();
        j["modulation_62_bypass"] = x.get_modulation_62___bypass();
        j["modulation_62_power"] = x.get_modulation_62___power();
        j["modulation_62_stereo"] = x.get_modulation_62___stereo();
        j["modulation_63_amount"] = x.get_modulation_63___amount();
        j["modulation_63_bipolar"] = x.get_modulation_63___bipolar();
        j["modulation_63_bypass"] = x.get_modulation_63___bypass();
        j["modulation_63_power"] = x.get_modulation_63___power();
        j["modulation_63_stereo"] = x.get_modulation_63___stereo();
        j["modulation_64_amount"] = x.get_modulation_64___amount();
        j["modulation_64_bipolar"] = x.get_modulation_64___bipolar();
        j["modulation_64_bypass"] = x.get_modulation_64___bypass();
        j["modulation_64_power"] = x.get_modulation_64___power();
        j["modulation_64_stereo"] = x.get_modulation_64___stereo();
        j["modulation_6_amount"] = x.get_modulation_6___amount();
        j["modulation_6_bipolar"] = x.get_modulation_6___bipolar();
        j["modulation_6_bypass"] = x.get_modulation_6___bypass();
        j["modulation_6_power"] = x.get_modulation_6___power();
        j["modulation_6_stereo"] = x.get_modulation_6___stereo();
        j["modulation_7_amount"] = x.get_modulation_7___amount();
        j["modulation_7_bipolar"] = x.get_modulation_7___bipolar();
        j["modulation_7_bypass"] = x.get_modulation_7___bypass();
        j["modulation_7_power"] = x.get_modulation_7___power();
        j["modulation_7_stereo"] = x.get_modulation_7___stereo();
        j["modulation_8_amount"] = x.get_modulation_8___amount();
        j["modulation_8_bipolar"] = x.get_modulation_8___bipolar();
        j["modulation_8_bypass"] = x.get_modulation_8___bypass();
        j["modulation_8_power"] = x.get_modulation_8___power();
        j["modulation_8_stereo"] = x.get_modulation_8___stereo();
        j["modulation_9_amount"] = x.get_modulation_9___amount();
        j["modulation_9_bipolar"] = x.get_modulation_9___bipolar();
        j["modulation_9_bypass"] = x.get_modulation_9___bypass();
        j["modulation_9_power"] = x.get_modulation_9___power();
        j["modulation_9_stereo"] = x.get_modulation_9___stereo();
        j["modulations"] = x.get_modulations();
        j["osc_1_destination"] = x.get_osc_1___destination();
        j["osc_1_detune_power"] = x.get_osc_1___detune_power();
        j["osc_1_detune_range"] = x.get_osc_1___detune_range();
        j["osc_1_distortion_amount"] = x.get_osc_1___distortion_amount();
        j["osc_1_distortion_phase"] = x.get_osc_1___distortion_phase();
        j["osc_1_distortion_spread"] = x.get_osc_1___distortion_spread();
        j["osc_1_distortion_type"] = x.get_osc_1___distortion_type();
        j["osc_1_frame_spread"] = x.get_osc_1___frame_spread();
        j["osc_1_level"] = x.get_osc_1___level();
        j["osc_1_midi_track"] = x.get_osc_1___midi_track();
        j["osc_1_on"] = x.get_osc_1___on();
        j["osc_1_pan"] = x.get_osc_1___pan();
        j["osc_1_phase"] = x.get_osc_1___phase();
        j["osc_1_random_phase"] = x.get_osc_1___random_phase();
        j["osc_1_smooth_interpolation"] = x.get_osc_1___smooth_interpolation();
        j["osc_1_spectral_morph_amount"] = x.get_osc_1___spectral_morph_amount();
        j["osc_1_spectral_morph_spread"] = x.get_osc_1___spectral_morph_spread();
        j["osc_1_spectral_morph_type"] = x.get_osc_1___spectral_morph_type();
        j["osc_1_spectral_unison"] = x.get_osc_1___spectral_unison();
        j["osc_1_stack_style"] = x.get_osc_1___stack_style();
        j["osc_1_stereo_spread"] = x.get_osc_1___stereo_spread();
        j["osc_1_transpose"] = x.get_osc_1___transpose();
        j["osc_1_transpose_quantize"] = x.get_osc_1___transpose_quantize();
        j["osc_1_tune"] = x.get_osc_1___tune();
        j["osc_1_unison_blend"] = x.get_osc_1___unison_blend();
        j["osc_1_unison_detune"] = x.get_osc_1___unison_detune();
        j["osc_1_unison_voices"] = x.get_osc_1___unison_voices();
        j["osc_1_view_2d"] = x.get_osc_1___view_2__d();
        j["osc_1_wave_frame"] = x.get_osc_1___wave_frame();
        j["osc_2_destination"] = x.get_osc_2___destination();
        j["osc_2_detune_power"] = x.get_osc_2___detune_power();
        j["osc_2_detune_range"] = x.get_osc_2___detune_range();
        j["osc_2_distortion_amount"] = x.get_osc_2___distortion_amount();
        j["osc_2_distortion_phase"] = x.get_osc_2___distortion_phase();
        j["osc_2_distortion_spread"] = x.get_osc_2___distortion_spread();
        j["osc_2_distortion_type"] = x.get_osc_2___distortion_type();
        j["osc_2_frame_spread"] = x.get_osc_2___frame_spread();
        j["osc_2_level"] = x.get_osc_2___level();
        j["osc_2_midi_track"] = x.get_osc_2___midi_track();
        j["osc_2_on"] = x.get_osc_2___on();
        j["osc_2_pan"] = x.get_osc_2___pan();
        j["osc_2_phase"] = x.get_osc_2___phase();
        j["osc_2_random_phase"] = x.get_osc_2___random_phase();
        j["osc_2_smooth_interpolation"] = x.get_osc_2___smooth_interpolation();
        j["osc_2_spectral_morph_amount"] = x.get_osc_2___spectral_morph_amount();
        j["osc_2_spectral_morph_spread"] = x.get_osc_2___spectral_morph_spread();
        j["osc_2_spectral_morph_type"] = x.get_osc_2___spectral_morph_type();
        j["osc_2_spectral_unison"] = x.get_osc_2___spectral_unison();
        j["osc_2_stack_style"] = x.get_osc_2___stack_style();
        j["osc_2_stereo_spread"] = x.get_osc_2___stereo_spread();
        j["osc_2_transpose"] = x.get_osc_2___transpose();
        j["osc_2_transpose_quantize"] = x.get_osc_2___transpose_quantize();
        j["osc_2_tune"] = x.get_osc_2___tune();
        j["osc_2_unison_blend"] = x.get_osc_2___unison_blend();
        j["osc_2_unison_detune"] = x.get_osc_2___unison_detune();
        j["osc_2_unison_voices"] = x.get_osc_2___unison_voices();
        j["osc_2_view_2d"] = x.get_osc_2___view_2__d();
        j["osc_2_wave_frame"] = x.get_osc_2___wave_frame();
        j["osc_3_destination"] = x.get_osc_3___destination();
        j["osc_3_detune_power"] = x.get_osc_3___detune_power();
        j["osc_3_detune_range"] = x.get_osc_3___detune_range();
        j["osc_3_distortion_amount"] = x.get_osc_3___distortion_amount();
        j["osc_3_distortion_phase"] = x.get_osc_3___distortion_phase();
        j["osc_3_distortion_spread"] = x.get_osc_3___distortion_spread();
        j["osc_3_distortion_type"] = x.get_osc_3___distortion_type();
        j["osc_3_frame_spread"] = x.get_osc_3___frame_spread();
        j["osc_3_level"] = x.get_osc_3___level();
        j["osc_3_midi_track"] = x.get_osc_3___midi_track();
        j["osc_3_on"] = x.get_osc_3___on();
        j["osc_3_pan"] = x.get_osc_3___pan();
        j["osc_3_phase"] = x.get_osc_3___phase();
        j["osc_3_random_phase"] = x.get_osc_3___random_phase();
        j["osc_3_smooth_interpolation"] = x.get_osc_3___smooth_interpolation();
        j["osc_3_spectral_morph_amount"] = x.get_osc_3___spectral_morph_amount();
        j["osc_3_spectral_morph_spread"] = x.get_osc_3___spectral_morph_spread();
        j["osc_3_spectral_morph_type"] = x.get_osc_3___spectral_morph_type();
        j["osc_3_spectral_unison"] = x.get_osc_3___spectral_unison();
        j["osc_3_stack_style"] = x.get_osc_3___stack_style();
        j["osc_3_stereo_spread"] = x.get_osc_3___stereo_spread();
        j["osc_3_transpose"] = x.get_osc_3___transpose();
        j["osc_3_transpose_quantize"] = x.get_osc_3___transpose_quantize();
        j["osc_3_tune"] = x.get_osc_3___tune();
        j["osc_3_unison_blend"] = x.get_osc_3___unison_blend();
        j["osc_3_unison_detune"] = x.get_osc_3___unison_detune();
        j["osc_3_unison_voices"] = x.get_osc_3___unison_voices();
        j["osc_3_view_2d"] = x.get_osc_3___view_2__d();
        j["osc_3_wave_frame"] = x.get_osc_3___wave_frame();
        j["oversampling"] = x.get_oversampling();
        j["phaser_blend"] = x.get_phaser_blend();
        j["phaser_center"] = x.get_phaser_center();
        j["phaser_dry_wet"] = x.get_phaser_dry_wet();
        j["phaser_feedback"] = x.get_phaser_feedback();
        j["phaser_frequency"] = x.get_phaser_frequency();
        j["phaser_mod_depth"] = x.get_phaser_mod_depth();
        j["phaser_on"] = x.get_phaser_on();
        j["phaser_phase_offset"] = x.get_phaser_phase_offset();
        j["phaser_sync"] = x.get_phaser_sync();
        j["phaser_tempo"] = x.get_phaser_tempo();
        j["pitch_bend_range"] = x.get_pitch_bend_range();
        j["pitch_wheel"] = x.get_pitch_wheel();
        j["polyphony"] = x.get_polyphony();
        j["portamento_force"] = x.get_portamento_force();
        j["portamento_scale"] = x.get_portamento_scale();
        j["portamento_slope"] = x.get_portamento_slope();
        j["portamento_time"] = x.get_portamento_time();
        j["random_1_frequency"] = x.get_random_1___frequency();
        j["random_1_keytrack_transpose"] = x.get_random_1___keytrack_transpose();
        j["random_1_keytrack_tune"] = x.get_random_1___keytrack_tune();
        j["random_1_stereo"] = x.get_random_1___stereo();
        j["random_1_style"] = x.get_random_1___style();
        j["random_1_sync"] = x.get_random_1___sync();
        j["random_1_sync_type"] = x.get_random_1___sync_type();
        j["random_1_tempo"] = x.get_random_1___tempo();
        j["random_2_frequency"] = x.get_random_2___frequency();
        j["random_2_keytrack_transpose"] = x.get_random_2___keytrack_transpose();
        j["random_2_keytrack_tune"] = x.get_random_2___keytrack_tune();
        j["random_2_stereo"] = x.get_random_2___stereo();
        j["random_2_style"] = x.get_random_2___style();
        j["random_2_sync"] = x.get_random_2___sync();
        j["random_2_sync_type"] = x.get_random_2___sync_type();
        j["random_2_tempo"] = x.get_random_2___tempo();
        j["random_3_frequency"] = x.get_random_3___frequency();
        j["random_3_keytrack_transpose"] = x.get_random_3___keytrack_transpose();
        j["random_3_keytrack_tune"] = x.get_random_3___keytrack_tune();
        j["random_3_stereo"] = x.get_random_3___stereo();
        j["random_3_style"] = x.get_random_3___style();
        j["random_3_sync"] = x.get_random_3___sync();
        j["random_3_sync_type"] = x.get_random_3___sync_type();
        j["random_3_tempo"] = x.get_random_3___tempo();
        j["random_4_frequency"] = x.get_random_4___frequency();
        j["random_4_keytrack_transpose"] = x.get_random_4___keytrack_transpose();
        j["random_4_keytrack_tune"] = x.get_random_4___keytrack_tune();
        j["random_4_stereo"] = x.get_random_4___stereo();
        j["random_4_style"] = x.get_random_4___style();
        j["random_4_sync"] = x.get_random_4___sync();
        j["random_4_sync_type"] = x.get_random_4___sync_type();
        j["random_4_tempo"] = x.get_random_4___tempo();
        j["reverb_chorus_amount"] = x.get_reverb_chorus_amount();
        j["reverb_chorus_frequency"] = x.get_reverb_chorus_frequency();
        j["reverb_decay_time"] = x.get_reverb_decay_time();
        j["reverb_delay"] = x.get_reverb_delay();
        j["reverb_dry_wet"] = x.get_reverb_dry_wet();
        j["reverb_high_shelf_cutoff"] = x.get_reverb_high_shelf_cutoff();
        j["reverb_high_shelf_gain"] = x.get_reverb_high_shelf_gain();
        j["reverb_low_shelf_cutoff"] = x.get_reverb_low_shelf_cutoff();
        j["reverb_low_shelf_gain"] = x.get_reverb_low_shelf_gain();
        j["reverb_on"] = x.get_reverb_on();
        j["reverb_pre_high_cutoff"] = x.get_reverb_pre_high_cutoff();
        j["reverb_pre_low_cutoff"] = x.get_reverb_pre_low_cutoff();
        j["reverb_size"] = x.get_reverb_size();
        j["sample"] = x.get_sample();
        j["sample_bounce"] = x.get_sample_bounce();
        j["sample_destination"] = x.get_sample_destination();
        j["sample_keytrack"] = x.get_sample_keytrack();
        j["sample_level"] = x.get_sample_level();
        j["sample_loop"] = x.get_sample_loop();
        j["sample_on"] = x.get_sample_on();
        j["sample_pan"] = x.get_sample_pan();
        j["sample_random_phase"] = x.get_sample_random_phase();
        j["sample_transpose"] = x.get_sample_transpose();
        j["sample_transpose_quantize"] = x.get_sample_transpose_quantize();
        j["sample_tune"] = x.get_sample_tune();
        j["stereo_mode"] = x.get_stereo_mode();
        j["stereo_routing"] = x.get_stereo_routing();
        j["velocity_track"] = x.get_velocity_track();
        j["view_spectrogram"] = x.get_view_spectrogram();
        j["voice_amplitude"] = x.get_voice_amplitude();
        j["voice_override"] = x.get_voice_override();
        j["voice_priority"] = x.get_voice_priority();
        j["voice_transpose"] = x.get_voice_transpose();
        j["voice_tune"] = x.get_voice_tune();
        j["volume"] = x.get_volume();
        j["wavetables"] = x.get_wavetables();
    }

    inline void from_json(const json & j, quicktype::VitalPreset& x) {
        x.set_author(j.at("author").get<std::string>());
        x.set_comments(j.at("comments").get<std::string>());
        x.set_macro1(j.at("macro1").get<std::string>());
        x.set_macro2(j.at("macro2").get<std::string>());
        x.set_macro3(j.at("macro3").get<std::string>());
        x.set_macro4(j.at("macro4").get<std::string>());
        x.set_preset_name(quicktype::get_optional<std::string>(j, "preset_name"));
        x.set_preset_style(j.at("preset_style").get<quicktype::PresetStyle>());
        x.set_settings(j.at("settings").get<quicktype::PresetSettings>());
        x.set_synth_version(j.at("synth_version").get<std::string>());
    }

    inline void to_json(json & j, const quicktype::VitalPreset & x) {
        j = json::object();
        j["author"] = x.get_author();
        j["comments"] = x.get_comments();
        j["macro1"] = x.get_macro1();
        j["macro2"] = x.get_macro2();
        j["macro3"] = x.get_macro3();
        j["macro4"] = x.get_macro4();
        j["preset_name"] = x.get_preset_name();
        j["preset_style"] = x.get_preset_style();
        j["settings"] = x.get_settings();
        j["synth_version"] = x.get_synth_version();
    }

    inline void from_json(const json & j, quicktype::PresetStyle & x) {
        if (j == "Bass") x = quicktype::PresetStyle::BASS;
        else if (j == "") x = quicktype::PresetStyle::EMPTY;
        else if (j == "Experiment") x = quicktype::PresetStyle::EXPERIMENT;
        else if (j == "Keys") x = quicktype::PresetStyle::KEYS;
        else if (j == "Lead") x = quicktype::PresetStyle::LEAD;
        else if (j == "Pad") x = quicktype::PresetStyle::PAD;
        else if (j == "Percussion") x = quicktype::PresetStyle::PERCUSSION;
        else if (j == "Sequence") x = quicktype::PresetStyle::SEQUENCE;
        else if (j == "SFX") x = quicktype::PresetStyle::SFX;
        else if (j == "Template") x = quicktype::PresetStyle::TEMPLATE;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const quicktype::PresetStyle & x) {
        switch (x) {
            case quicktype::PresetStyle::BASS: j = "Bass"; break;
            case quicktype::PresetStyle::EMPTY: j = ""; break;
            case quicktype::PresetStyle::EXPERIMENT: j = "Experiment"; break;
            case quicktype::PresetStyle::KEYS: j = "Keys"; break;
            case quicktype::PresetStyle::LEAD: j = "Lead"; break;
            case quicktype::PresetStyle::PAD: j = "Pad"; break;
            case quicktype::PresetStyle::PERCUSSION: j = "Percussion"; break;
            case quicktype::PresetStyle::SEQUENCE: j = "Sequence"; break;
            case quicktype::PresetStyle::SFX: j = "SFX"; break;
            case quicktype::PresetStyle::TEMPLATE: j = "Template"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, quicktype::Source & x) {
        static std::unordered_map<std::string, quicktype::Source> enumValues {
            {"aftertouch", quicktype::Source::AFTERTOUCH},
            {"", quicktype::Source::EMPTY},
            {"env_1", quicktype::Source::ENV_1},
            {"env_2", quicktype::Source::ENV_2},
            {"env_3", quicktype::Source::ENV_3},
            {"env_4", quicktype::Source::ENV_4},
            {"env_5", quicktype::Source::ENV_5},
            {"env_6", quicktype::Source::ENV_6},
            {"lfo_1", quicktype::Source::LFO_1},
            {"lfo_2", quicktype::Source::LFO_2},
            {"lfo_3", quicktype::Source::LFO_3},
            {"lfo_4", quicktype::Source::LFO_4},
            {"lfo_5", quicktype::Source::LFO_5},
            {"lfo_6", quicktype::Source::LFO_6},
            {"lfo_7", quicktype::Source::LFO_7},
            {"lfo_8", quicktype::Source::LFO_8},
            {"lift", quicktype::Source::LIFT},
            {"macro_control_1", quicktype::Source::MACRO_CONTROL_1},
            {"macro_control_2", quicktype::Source::MACRO_CONTROL_2},
            {"macro_control_3", quicktype::Source::MACRO_CONTROL_3},
            {"macro_control_4", quicktype::Source::MACRO_CONTROL_4},
            {"mod_wheel", quicktype::Source::MOD_WHEEL},
            {"note", quicktype::Source::NOTE},
            {"note_in_octave", quicktype::Source::NOTE_IN_OCTAVE},
            {"pitch_wheel", quicktype::Source::PITCH_WHEEL},
            {"random", quicktype::Source::RANDOM},
            {"random_1", quicktype::Source::RANDOM_1},
            {"random_2", quicktype::Source::RANDOM_2},
            {"random_3", quicktype::Source::RANDOM_3},
            {"random_4", quicktype::Source::RANDOM_4},
            {"slide", quicktype::Source::SLIDE},
            {"stereo", quicktype::Source::STEREO},
            {"velocity", quicktype::Source::VELOCITY},
        };
        auto iter = enumValues.find(j.get<std::string>());
        if (iter != enumValues.end()) {
            x = iter->second;
        }
    }

    inline void to_json(json & j, const quicktype::Source & x) {
        switch (x) {
            case quicktype::Source::AFTERTOUCH: j = "aftertouch"; break;
            case quicktype::Source::EMPTY: j = ""; break;
            case quicktype::Source::ENV_1: j = "env_1"; break;
            case quicktype::Source::ENV_2: j = "env_2"; break;
            case quicktype::Source::ENV_3: j = "env_3"; break;
            case quicktype::Source::ENV_4: j = "env_4"; break;
            case quicktype::Source::ENV_5: j = "env_5"; break;
            case quicktype::Source::ENV_6: j = "env_6"; break;
            case quicktype::Source::LFO_1: j = "lfo_1"; break;
            case quicktype::Source::LFO_2: j = "lfo_2"; break;
            case quicktype::Source::LFO_3: j = "lfo_3"; break;
            case quicktype::Source::LFO_4: j = "lfo_4"; break;
            case quicktype::Source::LFO_5: j = "lfo_5"; break;
            case quicktype::Source::LFO_6: j = "lfo_6"; break;
            case quicktype::Source::LFO_7: j = "lfo_7"; break;
            case quicktype::Source::LFO_8: j = "lfo_8"; break;
            case quicktype::Source::LIFT: j = "lift"; break;
            case quicktype::Source::MACRO_CONTROL_1: j = "macro_control_1"; break;
            case quicktype::Source::MACRO_CONTROL_2: j = "macro_control_2"; break;
            case quicktype::Source::MACRO_CONTROL_3: j = "macro_control_3"; break;
            case quicktype::Source::MACRO_CONTROL_4: j = "macro_control_4"; break;
            case quicktype::Source::MOD_WHEEL: j = "mod_wheel"; break;
            case quicktype::Source::NOTE: j = "note"; break;
            case quicktype::Source::NOTE_IN_OCTAVE: j = "note_in_octave"; break;
            case quicktype::Source::PITCH_WHEEL: j = "pitch_wheel"; break;
            case quicktype::Source::RANDOM: j = "random"; break;
            case quicktype::Source::RANDOM_1: j = "random_1"; break;
            case quicktype::Source::RANDOM_2: j = "random_2"; break;
            case quicktype::Source::RANDOM_3: j = "random_3"; break;
            case quicktype::Source::RANDOM_4: j = "random_4"; break;
            case quicktype::Source::SLIDE: j = "slide"; break;
            case quicktype::Source::STEREO: j = "stereo"; break;
            case quicktype::Source::VELOCITY: j = "velocity"; break;
            default: throw "This should not happen";
        }
    }

    inline void from_json(const json & j, quicktype::Type & x) {
        if (j == "Audio File Source") x = quicktype::Type::AUDIO_FILE_SOURCE;
        else if (j == "Frequency Filter") x = quicktype::Type::FREQUENCY_FILTER;
        else if (j == "Line Source") x = quicktype::Type::LINE_SOURCE;
        else if (j == "Phase Shift") x = quicktype::Type::PHASE_SHIFT;
        else if (j == "Shepard Tone Source") x = quicktype::Type::SHEPARD_TONE_SOURCE;
        else if (j == "Slew Limiter") x = quicktype::Type::SLEW_LIMITER;
        else if (j == "Wave Folder") x = quicktype::Type::WAVE_FOLDER;
        else if (j == "Wave Source") x = quicktype::Type::WAVE_SOURCE;
        else if (j == "Wave Warp") x = quicktype::Type::WAVE_WARP;
        else if (j == "Wave Window") x = quicktype::Type::WAVE_WINDOW;
        else throw "Input JSON does not conform to schema";
    }

    inline void to_json(json & j, const quicktype::Type & x) {
        switch (x) {
            case quicktype::Type::AUDIO_FILE_SOURCE: j = "Audio File Source"; break;
            case quicktype::Type::FREQUENCY_FILTER: j = "Frequency Filter"; break;
            case quicktype::Type::LINE_SOURCE: j = "Line Source"; break;
            case quicktype::Type::PHASE_SHIFT: j = "Phase Shift"; break;
            case quicktype::Type::SHEPARD_TONE_SOURCE: j = "Shepard Tone Source"; break;
            case quicktype::Type::SLEW_LIMITER: j = "Slew Limiter"; break;
            case quicktype::Type::WAVE_FOLDER: j = "Wave Folder"; break;
            case quicktype::Type::WAVE_SOURCE: j = "Wave Source"; break;
            case quicktype::Type::WAVE_WARP: j = "Wave Warp"; break;
            case quicktype::Type::WAVE_WINDOW: j = "Wave Window"; break;
            default: throw "This should not happen";
        }
    }
}
