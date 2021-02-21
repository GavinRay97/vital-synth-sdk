# To use this code, make sure you
#
#     import json
#
# and then, to convert JSON from a string, do
#
#     result = vital_preset_from_dict(json.loads(json_string))
#     result = preset_style_from_dict(json.loads(json_string))
#     result = preset_settings_from_dict(json.loads(json_string))
#     result = lfo_from_dict(json.loads(json_string))
#     result = modulation_from_dict(json.loads(json_string))
#     result = source_from_dict(json.loads(json_string))
#     result = sample_from_dict(json.loads(json_string))
#     result = wavetable_from_dict(json.loads(json_string))
#     result = group_from_dict(json.loads(json_string))
#     result = component_from_dict(json.loads(json_string))
#     result = keyframe_from_dict(json.loads(json_string))
#     result = purple_type_from_dict(json.loads(json_string))

from enum import Enum
from dataclasses import dataclass
from typing import List, Any, Optional, TypeVar, Callable, Type, cast


T = TypeVar("T")
EnumT = TypeVar("EnumT", bound=Enum)


def from_str(x: Any) -> str:
    assert isinstance(x, str)
    return x


def from_float(x: Any) -> float:
    assert isinstance(x, (float, int)) and not isinstance(x, bool)
    return float(x)


def from_list(f: Callable[[Any], T], x: Any) -> List[T]:
    assert isinstance(x, list)
    return [f(y) for y in x]


def from_bool(x: Any) -> bool:
    assert isinstance(x, bool)
    return x


def to_float(x: Any) -> float:
    assert isinstance(x, float)
    return x


def from_none(x: Any) -> Any:
    assert x is None
    return x


def from_union(fs, x):
    for f in fs:
        try:
            return f(x)
        except:
            pass
    assert False


def to_enum(c: Type[EnumT], x: Any) -> EnumT:
    assert isinstance(x, c)
    return x.value


def to_class(c: Type[T], x: Any) -> dict:
    assert isinstance(x, c)
    return cast(Any, x).to_dict()


class PresetStyle(Enum):
    BASS = "Bass"
    EMPTY = ""
    EXPERIMENT = "Experiment"
    KEYS = "Keys"
    LEAD = "Lead"
    PAD = "Pad"
    PERCUSSION = "Percussion"
    SEQUENCE = "Sequence"
    SFX = "SFX"
    TEMPLATE = "Template"


@dataclass
class Lfo:
    name: str
    num_points: float
    points: List[float]
    powers: List[float]
    smooth: bool

    @staticmethod
    def from_dict(obj: Any) -> 'Lfo':
        assert isinstance(obj, dict)
        name = from_str(obj.get("name"))
        num_points = from_float(obj.get("num_points"))
        points = from_list(from_float, obj.get("points"))
        powers = from_list(from_float, obj.get("powers"))
        smooth = from_bool(obj.get("smooth"))
        return Lfo(name, num_points, points, powers, smooth)

    def to_dict(self) -> dict:
        result: dict = {}
        result["name"] = from_str(self.name)
        result["num_points"] = to_float(self.num_points)
        result["points"] = from_list(to_float, self.points)
        result["powers"] = from_list(to_float, self.powers)
        result["smooth"] = from_bool(self.smooth)
        return result


class Source(Enum):
    AFTERTOUCH = "aftertouch"
    EMPTY = ""
    ENV_1 = "env_1"
    ENV_2 = "env_2"
    ENV_3 = "env_3"
    ENV_4 = "env_4"
    ENV_5 = "env_5"
    ENV_6 = "env_6"
    LFO_1 = "lfo_1"
    LFO_2 = "lfo_2"
    LFO_3 = "lfo_3"
    LFO_4 = "lfo_4"
    LFO_5 = "lfo_5"
    LFO_6 = "lfo_6"
    LFO_7 = "lfo_7"
    LFO_8 = "lfo_8"
    LIFT = "lift"
    MACRO_CONTROL_1 = "macro_control_1"
    MACRO_CONTROL_2 = "macro_control_2"
    MACRO_CONTROL_3 = "macro_control_3"
    MACRO_CONTROL_4 = "macro_control_4"
    MOD_WHEEL = "mod_wheel"
    NOTE = "note"
    NOTE_IN_OCTAVE = "note_in_octave"
    PITCH_WHEEL = "pitch_wheel"
    RANDOM = "random"
    RANDOM_1 = "random_1"
    RANDOM_2 = "random_2"
    RANDOM_3 = "random_3"
    RANDOM_4 = "random_4"
    SLIDE = "slide"
    STEREO = "stereo"
    VELOCITY = "velocity"


@dataclass
class Modulation:
    destination: str
    source: Source
    line_mapping: Optional[Lfo] = None

    @staticmethod
    def from_dict(obj: Any) -> 'Modulation':
        assert isinstance(obj, dict)
        destination = from_str(obj.get("destination"))
        source = Source(obj.get("source"))
        line_mapping = from_union([Lfo.from_dict, from_none], obj.get("line_mapping"))
        return Modulation(destination, source, line_mapping)

    def to_dict(self) -> dict:
        result: dict = {}
        result["destination"] = from_str(self.destination)
        result["source"] = to_enum(Source, self.source)
        result["line_mapping"] = from_union([lambda x: to_class(Lfo, x), from_none], self.line_mapping)
        return result


@dataclass
class Sample:
    length: float
    name: str
    sample_rate: float
    samples: str
    samples_stereo: Optional[str] = None

    @staticmethod
    def from_dict(obj: Any) -> 'Sample':
        assert isinstance(obj, dict)
        length = from_float(obj.get("length"))
        name = from_str(obj.get("name"))
        sample_rate = from_float(obj.get("sample_rate"))
        samples = from_str(obj.get("samples"))
        samples_stereo = from_union([from_str, from_none], obj.get("samples_stereo"))
        return Sample(length, name, sample_rate, samples, samples_stereo)

    def to_dict(self) -> dict:
        result: dict = {}
        result["length"] = to_float(self.length)
        result["name"] = from_str(self.name)
        result["sample_rate"] = to_float(self.sample_rate)
        result["samples"] = from_str(self.samples)
        result["samples_stereo"] = from_union([from_str, from_none], self.samples_stereo)
        return result


@dataclass
class Keyframe:
    position: float
    cutoff: Optional[float] = None
    down_run_rise: Optional[float] = None
    fold_boost: Optional[float] = None
    horizontal_power: Optional[float] = None
    left_position: Optional[float] = None
    line: Optional[Lfo] = None
    mix: Optional[float] = None
    phase: Optional[float] = None
    pull_power: Optional[float] = None
    right_position: Optional[float] = None
    shape: Optional[float] = None
    start_position: Optional[float] = None
    up_run_rise: Optional[float] = None
    vertical_power: Optional[float] = None
    wave_data: Optional[str] = None
    window_fade: Optional[float] = None
    window_size: Optional[float] = None

    @staticmethod
    def from_dict(obj: Any) -> 'Keyframe':
        assert isinstance(obj, dict)
        position = from_float(obj.get("position"))
        cutoff = from_union([from_float, from_none], obj.get("cutoff"))
        down_run_rise = from_union([from_float, from_none], obj.get("down_run_rise"))
        fold_boost = from_union([from_float, from_none], obj.get("fold_boost"))
        horizontal_power = from_union([from_float, from_none], obj.get("horizontal_power"))
        left_position = from_union([from_float, from_none], obj.get("left_position"))
        line = from_union([Lfo.from_dict, from_none], obj.get("line"))
        mix = from_union([from_float, from_none], obj.get("mix"))
        phase = from_union([from_float, from_none], obj.get("phase"))
        pull_power = from_union([from_float, from_none], obj.get("pull_power"))
        right_position = from_union([from_float, from_none], obj.get("right_position"))
        shape = from_union([from_float, from_none], obj.get("shape"))
        start_position = from_union([from_float, from_none], obj.get("start_position"))
        up_run_rise = from_union([from_float, from_none], obj.get("up_run_rise"))
        vertical_power = from_union([from_float, from_none], obj.get("vertical_power"))
        wave_data = from_union([from_str, from_none], obj.get("wave_data"))
        window_fade = from_union([from_float, from_none], obj.get("window_fade"))
        window_size = from_union([from_float, from_none], obj.get("window_size"))
        return Keyframe(position, cutoff, down_run_rise, fold_boost, horizontal_power, left_position, line, mix, phase, pull_power, right_position, shape, start_position, up_run_rise, vertical_power, wave_data, window_fade, window_size)

    def to_dict(self) -> dict:
        result: dict = {}
        result["position"] = to_float(self.position)
        result["cutoff"] = from_union([to_float, from_none], self.cutoff)
        result["down_run_rise"] = from_union([to_float, from_none], self.down_run_rise)
        result["fold_boost"] = from_union([to_float, from_none], self.fold_boost)
        result["horizontal_power"] = from_union([to_float, from_none], self.horizontal_power)
        result["left_position"] = from_union([to_float, from_none], self.left_position)
        result["line"] = from_union([lambda x: to_class(Lfo, x), from_none], self.line)
        result["mix"] = from_union([to_float, from_none], self.mix)
        result["phase"] = from_union([to_float, from_none], self.phase)
        result["pull_power"] = from_union([to_float, from_none], self.pull_power)
        result["right_position"] = from_union([to_float, from_none], self.right_position)
        result["shape"] = from_union([to_float, from_none], self.shape)
        result["start_position"] = from_union([to_float, from_none], self.start_position)
        result["up_run_rise"] = from_union([to_float, from_none], self.up_run_rise)
        result["vertical_power"] = from_union([to_float, from_none], self.vertical_power)
        result["wave_data"] = from_union([from_str, from_none], self.wave_data)
        result["window_fade"] = from_union([to_float, from_none], self.window_fade)
        result["window_size"] = from_union([to_float, from_none], self.window_size)
        return result


class PurpleType(Enum):
    AUDIO_FILE_SOURCE = "Audio File Source"
    FREQUENCY_FILTER = "Frequency Filter"
    LINE_SOURCE = "Line Source"
    PHASE_SHIFT = "Phase Shift"
    SHEPARD_TONE_SOURCE = "Shepard Tone Source"
    SLEW_LIMITER = "Slew Limiter"
    WAVE_FOLDER = "Wave Folder"
    WAVE_SOURCE = "Wave Source"
    WAVE_WARP = "Wave Warp"
    WAVE_WINDOW = "Wave Window"


@dataclass
class Component:
    interpolation_style: float
    type: PurpleType
    audio_file: Optional[str] = None
    audio_sample_rate: Optional[float] = None
    fade_style: Optional[float] = None
    horizontal_asymmetric: Optional[bool] = None
    interpolation: Optional[float] = None
    keyframes: Optional[List[Keyframe]] = None
    normalize: Optional[bool] = None
    normalize_gain: Optional[bool] = None
    normalize_mult: Optional[bool] = None
    num_points: Optional[float] = None
    phase_style: Optional[float] = None
    random_seed: Optional[float] = None
    style: Optional[float] = None
    vertical_asymmetric: Optional[bool] = None
    window_shape: Optional[float] = None
    window_size: Optional[float] = None

    @staticmethod
    def from_dict(obj: Any) -> 'Component':
        assert isinstance(obj, dict)
        interpolation_style = from_float(obj.get("interpolation_style"))
        type = PurpleType(obj.get("type"))
        audio_file = from_union([from_str, from_none], obj.get("audio_file"))
        audio_sample_rate = from_union([from_float, from_none], obj.get("audio_sample_rate"))
        fade_style = from_union([from_float, from_none], obj.get("fade_style"))
        horizontal_asymmetric = from_union([from_bool, from_none], obj.get("horizontal_asymmetric"))
        interpolation = from_union([from_float, from_none], obj.get("interpolation"))
        keyframes = from_union([lambda x: from_list(Keyframe.from_dict, x), from_none], obj.get("keyframes"))
        normalize = from_union([from_bool, from_none], obj.get("normalize"))
        normalize_gain = from_union([from_bool, from_none], obj.get("normalize_gain"))
        normalize_mult = from_union([from_bool, from_none], obj.get("normalize_mult"))
        num_points = from_union([from_float, from_none], obj.get("num_points"))
        phase_style = from_union([from_float, from_none], obj.get("phase_style"))
        random_seed = from_union([from_float, from_none], obj.get("random_seed"))
        style = from_union([from_float, from_none], obj.get("style"))
        vertical_asymmetric = from_union([from_bool, from_none], obj.get("vertical_asymmetric"))
        window_shape = from_union([from_float, from_none], obj.get("window_shape"))
        window_size = from_union([from_float, from_none], obj.get("window_size"))
        return Component(interpolation_style, type, audio_file, audio_sample_rate, fade_style, horizontal_asymmetric, interpolation, keyframes, normalize, normalize_gain, normalize_mult, num_points, phase_style, random_seed, style, vertical_asymmetric, window_shape, window_size)

    def to_dict(self) -> dict:
        result: dict = {}
        result["interpolation_style"] = to_float(self.interpolation_style)
        result["type"] = to_enum(PurpleType, self.type)
        result["audio_file"] = from_union([from_str, from_none], self.audio_file)
        result["audio_sample_rate"] = from_union([to_float, from_none], self.audio_sample_rate)
        result["fade_style"] = from_union([to_float, from_none], self.fade_style)
        result["horizontal_asymmetric"] = from_union([from_bool, from_none], self.horizontal_asymmetric)
        result["interpolation"] = from_union([to_float, from_none], self.interpolation)
        result["keyframes"] = from_union([lambda x: from_list(lambda x: to_class(Keyframe, x), x), from_none], self.keyframes)
        result["normalize"] = from_union([from_bool, from_none], self.normalize)
        result["normalize_gain"] = from_union([from_bool, from_none], self.normalize_gain)
        result["normalize_mult"] = from_union([from_bool, from_none], self.normalize_mult)
        result["num_points"] = from_union([to_float, from_none], self.num_points)
        result["phase_style"] = from_union([to_float, from_none], self.phase_style)
        result["random_seed"] = from_union([to_float, from_none], self.random_seed)
        result["style"] = from_union([to_float, from_none], self.style)
        result["vertical_asymmetric"] = from_union([from_bool, from_none], self.vertical_asymmetric)
        result["window_shape"] = from_union([to_float, from_none], self.window_shape)
        result["window_size"] = from_union([to_float, from_none], self.window_size)
        return result


@dataclass
class Group:
    components: List[Component]

    @staticmethod
    def from_dict(obj: Any) -> 'Group':
        assert isinstance(obj, dict)
        components = from_list(Component.from_dict, obj.get("components"))
        return Group(components)

    def to_dict(self) -> dict:
        result: dict = {}
        result["components"] = from_list(lambda x: to_class(Component, x), self.components)
        return result


@dataclass
class Wavetable:
    full_normalize: bool
    groups: List[Group]
    name: str
    remove_all_dc: bool
    version: str
    author: Optional[str] = None

    @staticmethod
    def from_dict(obj: Any) -> 'Wavetable':
        assert isinstance(obj, dict)
        full_normalize = from_bool(obj.get("full_normalize"))
        groups = from_list(Group.from_dict, obj.get("groups"))
        name = from_str(obj.get("name"))
        remove_all_dc = from_bool(obj.get("remove_all_dc"))
        version = from_str(obj.get("version"))
        author = from_union([from_str, from_none], obj.get("author"))
        return Wavetable(full_normalize, groups, name, remove_all_dc, version, author)

    def to_dict(self) -> dict:
        result: dict = {}
        result["full_normalize"] = from_bool(self.full_normalize)
        result["groups"] = from_list(lambda x: to_class(Group, x), self.groups)
        result["name"] = from_str(self.name)
        result["remove_all_dc"] = from_bool(self.remove_all_dc)
        result["version"] = from_str(self.version)
        result["author"] = from_union([from_str, from_none], self.author)
        return result


@dataclass
class PresetSettings:
    beats_per_minute: float
    chorus_delay_1: float
    chorus_delay_2: float
    chorus_dry_wet: float
    chorus_feedback: float
    chorus_frequency: float
    chorus_mod_depth: float
    chorus_on: float
    chorus_sync: float
    chorus_tempo: float
    chorus_voices: float
    compressor_attack: float
    compressor_band_gain: float
    compressor_band_lower_ratio: float
    compressor_band_lower_threshold: float
    compressor_band_upper_ratio: float
    compressor_band_upper_threshold: float
    compressor_enabled_bands: float
    compressor_high_gain: float
    compressor_high_lower_ratio: float
    compressor_high_lower_threshold: float
    compressor_high_upper_ratio: float
    compressor_high_upper_threshold: float
    compressor_low_gain: float
    compressor_low_lower_ratio: float
    compressor_low_lower_threshold: float
    compressor_low_upper_ratio: float
    compressor_low_upper_threshold: float
    compressor_on: float
    compressor_release: float
    delay_aux_frequency: float
    delay_aux_sync: float
    delay_aux_tempo: float
    delay_dry_wet: float
    delay_feedback: float
    delay_filter_cutoff: float
    delay_filter_spread: float
    delay_frequency: float
    delay_on: float
    delay_style: float
    delay_sync: float
    delay_tempo: float
    distortion_drive: float
    distortion_filter_blend: float
    distortion_filter_cutoff: float
    distortion_filter_order: float
    distortion_filter_resonance: float
    distortion_mix: float
    distortion_on: float
    distortion_type: float
    effect_chain_order: float
    env_1__attack: float
    env_1__attack_power: float
    env_1__decay: float
    env_1__decay_power: float
    env_1__delay: float
    env_1__hold: float
    env_1__release: float
    env_1__release_power: float
    env_1__sustain: float
    env_2__attack: float
    env_2__attack_power: float
    env_2__decay: float
    env_2__decay_power: float
    env_2__delay: float
    env_2__hold: float
    env_2__release: float
    env_2__release_power: float
    env_2__sustain: float
    env_3__attack: float
    env_3__attack_power: float
    env_3__decay: float
    env_3__decay_power: float
    env_3__delay: float
    env_3__hold: float
    env_3__release: float
    env_3__release_power: float
    env_3__sustain: float
    env_4__attack: float
    env_4__attack_power: float
    env_4__decay: float
    env_4__decay_power: float
    env_4__delay: float
    env_4__hold: float
    env_4__release: float
    env_4__release_power: float
    env_4__sustain: float
    env_5__attack: float
    env_5__attack_power: float
    env_5__decay: float
    env_5__decay_power: float
    env_5__delay: float
    env_5__hold: float
    env_5__release: float
    env_5__release_power: float
    env_5__sustain: float
    env_6__attack: float
    env_6__attack_power: float
    env_6__decay: float
    env_6__decay_power: float
    env_6__delay: float
    env_6__hold: float
    env_6__release: float
    env_6__release_power: float
    env_6__sustain: float
    eq_band_cutoff: float
    eq_band_gain: float
    eq_band_mode: float
    eq_band_resonance: float
    eq_high_cutoff: float
    eq_high_gain: float
    eq_high_mode: float
    eq_high_resonance: float
    eq_low_cutoff: float
    eq_low_gain: float
    eq_low_mode: float
    eq_low_resonance: float
    eq_on: float
    filter_1__blend: float
    filter_1__blend_transpose: float
    filter_1__cutoff: float
    filter_1__drive: float
    filter_1__filter_input: float
    filter_1__formant_resonance: float
    filter_1__formant_transpose: float
    filter_1__formant_x: float
    filter_1__formant_y: float
    filter_1__keytrack: float
    filter_1__mix: float
    filter_1__model: float
    filter_1__on: float
    filter_1__resonance: float
    filter_1__style: float
    filter_2__blend: float
    filter_2__blend_transpose: float
    filter_2__cutoff: float
    filter_2__drive: float
    filter_2__filter_input: float
    filter_2__formant_resonance: float
    filter_2__formant_transpose: float
    filter_2__formant_x: float
    filter_2__formant_y: float
    filter_2__keytrack: float
    filter_2__mix: float
    filter_2__model: float
    filter_2__on: float
    filter_2__resonance: float
    filter_2__style: float
    filter_fx_blend: float
    filter_fx_blend_transpose: float
    filter_fx_cutoff: float
    filter_fx_drive: float
    filter_fx_formant_resonance: float
    filter_fx_formant_transpose: float
    filter_fx_formant_x: float
    filter_fx_formant_y: float
    filter_fx_keytrack: float
    filter_fx_mix: float
    filter_fx_model: float
    filter_fx_on: float
    filter_fx_resonance: float
    filter_fx_style: float
    flanger_center: float
    flanger_dry_wet: float
    flanger_feedback: float
    flanger_frequency: float
    flanger_mod_depth: float
    flanger_on: float
    flanger_phase_offset: float
    flanger_sync: float
    flanger_tempo: float
    legato: float
    lfo_1__delay_time: float
    lfo_1__fade_time: float
    lfo_1__frequency: float
    lfo_1__phase: float
    lfo_1__stereo: float
    lfo_1__sync: float
    lfo_1__sync_type: float
    lfo_1__tempo: float
    lfo_2__delay_time: float
    lfo_2__fade_time: float
    lfo_2__frequency: float
    lfo_2__phase: float
    lfo_2__stereo: float
    lfo_2__sync: float
    lfo_2__sync_type: float
    lfo_2__tempo: float
    lfo_3__delay_time: float
    lfo_3__fade_time: float
    lfo_3__frequency: float
    lfo_3__phase: float
    lfo_3__stereo: float
    lfo_3__sync: float
    lfo_3__sync_type: float
    lfo_3__tempo: float
    lfo_4__delay_time: float
    lfo_4__fade_time: float
    lfo_4__frequency: float
    lfo_4__phase: float
    lfo_4__stereo: float
    lfo_4__sync: float
    lfo_4__sync_type: float
    lfo_4__tempo: float
    lfo_5__delay_time: float
    lfo_5__fade_time: float
    lfo_5__frequency: float
    lfo_5__phase: float
    lfo_5__stereo: float
    lfo_5__sync: float
    lfo_5__sync_type: float
    lfo_5__tempo: float
    lfo_6__delay_time: float
    lfo_6__fade_time: float
    lfo_6__frequency: float
    lfo_6__phase: float
    lfo_6__stereo: float
    lfo_6__sync: float
    lfo_6__sync_type: float
    lfo_6__tempo: float
    lfo_7__delay_time: float
    lfo_7__fade_time: float
    lfo_7__frequency: float
    lfo_7__phase: float
    lfo_7__stereo: float
    lfo_7__sync: float
    lfo_7__sync_type: float
    lfo_7__tempo: float
    lfo_8__delay_time: float
    lfo_8__fade_time: float
    lfo_8__frequency: float
    lfo_8__phase: float
    lfo_8__stereo: float
    lfo_8__sync: float
    lfo_8__sync_type: float
    lfo_8__tempo: float
    lfos: List[Lfo]
    macro_control_1: float
    macro_control_2: float
    macro_control_3: float
    macro_control_4: float
    mod_wheel: float
    modulation_10__amount: float
    modulation_10__bipolar: float
    modulation_10__bypass: float
    modulation_10__power: float
    modulation_10__stereo: float
    modulation_11__amount: float
    modulation_11__bipolar: float
    modulation_11__bypass: float
    modulation_11__power: float
    modulation_11__stereo: float
    modulation_12__amount: float
    modulation_12__bipolar: float
    modulation_12__bypass: float
    modulation_12__power: float
    modulation_12__stereo: float
    modulation_13__amount: float
    modulation_13__bipolar: float
    modulation_13__bypass: float
    modulation_13__power: float
    modulation_13__stereo: float
    modulation_14__amount: float
    modulation_14__bipolar: float
    modulation_14__bypass: float
    modulation_14__power: float
    modulation_14__stereo: float
    modulation_15__amount: float
    modulation_15__bipolar: float
    modulation_15__bypass: float
    modulation_15__power: float
    modulation_15__stereo: float
    modulation_16__amount: float
    modulation_16__bipolar: float
    modulation_16__bypass: float
    modulation_16__power: float
    modulation_16__stereo: float
    modulation_17__amount: float
    modulation_17__bipolar: float
    modulation_17__bypass: float
    modulation_17__power: float
    modulation_17__stereo: float
    modulation_18__amount: float
    modulation_18__bipolar: float
    modulation_18__bypass: float
    modulation_18__power: float
    modulation_18__stereo: float
    modulation_19__amount: float
    modulation_19__bipolar: float
    modulation_19__bypass: float
    modulation_19__power: float
    modulation_19__stereo: float
    modulation_1__amount: float
    modulation_1__bipolar: float
    modulation_1__bypass: float
    modulation_1__power: float
    modulation_1__stereo: float
    modulation_20__amount: float
    modulation_20__bipolar: float
    modulation_20__bypass: float
    modulation_20__power: float
    modulation_20__stereo: float
    modulation_21__amount: float
    modulation_21__bipolar: float
    modulation_21__bypass: float
    modulation_21__power: float
    modulation_21__stereo: float
    modulation_22__amount: float
    modulation_22__bipolar: float
    modulation_22__bypass: float
    modulation_22__power: float
    modulation_22__stereo: float
    modulation_23__amount: float
    modulation_23__bipolar: float
    modulation_23__bypass: float
    modulation_23__power: float
    modulation_23__stereo: float
    modulation_24__amount: float
    modulation_24__bipolar: float
    modulation_24__bypass: float
    modulation_24__power: float
    modulation_24__stereo: float
    modulation_25__amount: float
    modulation_25__bipolar: float
    modulation_25__bypass: float
    modulation_25__power: float
    modulation_25__stereo: float
    modulation_26__amount: float
    modulation_26__bipolar: float
    modulation_26__bypass: float
    modulation_26__power: float
    modulation_26__stereo: float
    modulation_27__amount: float
    modulation_27__bipolar: float
    modulation_27__bypass: float
    modulation_27__power: float
    modulation_27__stereo: float
    modulation_28__amount: float
    modulation_28__bipolar: float
    modulation_28__bypass: float
    modulation_28__power: float
    modulation_28__stereo: float
    modulation_29__amount: float
    modulation_29__bipolar: float
    modulation_29__bypass: float
    modulation_29__power: float
    modulation_29__stereo: float
    modulation_2__amount: float
    modulation_2__bipolar: float
    modulation_2__bypass: float
    modulation_2__power: float
    modulation_2__stereo: float
    modulation_30__amount: float
    modulation_30__bipolar: float
    modulation_30__bypass: float
    modulation_30__power: float
    modulation_30__stereo: float
    modulation_31__amount: float
    modulation_31__bipolar: float
    modulation_31__bypass: float
    modulation_31__power: float
    modulation_31__stereo: float
    modulation_32__amount: float
    modulation_32__bipolar: float
    modulation_32__bypass: float
    modulation_32__power: float
    modulation_32__stereo: float
    modulation_33__amount: float
    modulation_33__bipolar: float
    modulation_33__bypass: float
    modulation_33__power: float
    modulation_33__stereo: float
    modulation_34__amount: float
    modulation_34__bipolar: float
    modulation_34__bypass: float
    modulation_34__power: float
    modulation_34__stereo: float
    modulation_35__amount: float
    modulation_35__bipolar: float
    modulation_35__bypass: float
    modulation_35__power: float
    modulation_35__stereo: float
    modulation_36__amount: float
    modulation_36__bipolar: float
    modulation_36__bypass: float
    modulation_36__power: float
    modulation_36__stereo: float
    modulation_37__amount: float
    modulation_37__bipolar: float
    modulation_37__bypass: float
    modulation_37__power: float
    modulation_37__stereo: float
    modulation_38__amount: float
    modulation_38__bipolar: float
    modulation_38__bypass: float
    modulation_38__power: float
    modulation_38__stereo: float
    modulation_39__amount: float
    modulation_39__bipolar: float
    modulation_39__bypass: float
    modulation_39__power: float
    modulation_39__stereo: float
    modulation_3__amount: float
    modulation_3__bipolar: float
    modulation_3__bypass: float
    modulation_3__power: float
    modulation_3__stereo: float
    modulation_40__amount: float
    modulation_40__bipolar: float
    modulation_40__bypass: float
    modulation_40__power: float
    modulation_40__stereo: float
    modulation_41__amount: float
    modulation_41__bipolar: float
    modulation_41__bypass: float
    modulation_41__power: float
    modulation_41__stereo: float
    modulation_42__amount: float
    modulation_42__bipolar: float
    modulation_42__bypass: float
    modulation_42__power: float
    modulation_42__stereo: float
    modulation_43__amount: float
    modulation_43__bipolar: float
    modulation_43__bypass: float
    modulation_43__power: float
    modulation_43__stereo: float
    modulation_44__amount: float
    modulation_44__bipolar: float
    modulation_44__bypass: float
    modulation_44__power: float
    modulation_44__stereo: float
    modulation_45__amount: float
    modulation_45__bipolar: float
    modulation_45__bypass: float
    modulation_45__power: float
    modulation_45__stereo: float
    modulation_46__amount: float
    modulation_46__bipolar: float
    modulation_46__bypass: float
    modulation_46__power: float
    modulation_46__stereo: float
    modulation_47__amount: float
    modulation_47__bipolar: float
    modulation_47__bypass: float
    modulation_47__power: float
    modulation_47__stereo: float
    modulation_48__amount: float
    modulation_48__bipolar: float
    modulation_48__bypass: float
    modulation_48__power: float
    modulation_48__stereo: float
    modulation_49__amount: float
    modulation_49__bipolar: float
    modulation_49__bypass: float
    modulation_49__power: float
    modulation_49__stereo: float
    modulation_4__amount: float
    modulation_4__bipolar: float
    modulation_4__bypass: float
    modulation_4__power: float
    modulation_4__stereo: float
    modulation_50__amount: float
    modulation_50__bipolar: float
    modulation_50__bypass: float
    modulation_50__power: float
    modulation_50__stereo: float
    modulation_51__amount: float
    modulation_51__bipolar: float
    modulation_51__bypass: float
    modulation_51__power: float
    modulation_51__stereo: float
    modulation_52__amount: float
    modulation_52__bipolar: float
    modulation_52__bypass: float
    modulation_52__power: float
    modulation_52__stereo: float
    modulation_53__amount: float
    modulation_53__bipolar: float
    modulation_53__bypass: float
    modulation_53__power: float
    modulation_53__stereo: float
    modulation_54__amount: float
    modulation_54__bipolar: float
    modulation_54__bypass: float
    modulation_54__power: float
    modulation_54__stereo: float
    modulation_55__amount: float
    modulation_55__bipolar: float
    modulation_55__bypass: float
    modulation_55__power: float
    modulation_55__stereo: float
    modulation_56__amount: float
    modulation_56__bipolar: float
    modulation_56__bypass: float
    modulation_56__power: float
    modulation_56__stereo: float
    modulation_57__amount: float
    modulation_57__bipolar: float
    modulation_57__bypass: float
    modulation_57__power: float
    modulation_57__stereo: float
    modulation_58__amount: float
    modulation_58__bipolar: float
    modulation_58__bypass: float
    modulation_58__power: float
    modulation_58__stereo: float
    modulation_59__amount: float
    modulation_59__bipolar: float
    modulation_59__bypass: float
    modulation_59__power: float
    modulation_59__stereo: float
    modulation_5__amount: float
    modulation_5__bipolar: float
    modulation_5__bypass: float
    modulation_5__power: float
    modulation_5__stereo: float
    modulation_60__amount: float
    modulation_60__bipolar: float
    modulation_60__bypass: float
    modulation_60__power: float
    modulation_60__stereo: float
    modulation_61__amount: float
    modulation_61__bipolar: float
    modulation_61__bypass: float
    modulation_61__power: float
    modulation_61__stereo: float
    modulation_62__amount: float
    modulation_62__bipolar: float
    modulation_62__bypass: float
    modulation_62__power: float
    modulation_62__stereo: float
    modulation_63__amount: float
    modulation_63__bipolar: float
    modulation_63__bypass: float
    modulation_63__power: float
    modulation_63__stereo: float
    modulation_64__amount: float
    modulation_64__bipolar: float
    modulation_64__bypass: float
    modulation_64__power: float
    modulation_64__stereo: float
    modulation_6__amount: float
    modulation_6__bipolar: float
    modulation_6__bypass: float
    modulation_6__power: float
    modulation_6__stereo: float
    modulation_7__amount: float
    modulation_7__bipolar: float
    modulation_7__bypass: float
    modulation_7__power: float
    modulation_7__stereo: float
    modulation_8__amount: float
    modulation_8__bipolar: float
    modulation_8__bypass: float
    modulation_8__power: float
    modulation_8__stereo: float
    modulation_9__amount: float
    modulation_9__bipolar: float
    modulation_9__bypass: float
    modulation_9__power: float
    modulation_9__stereo: float
    modulations: List[Modulation]
    osc_1__destination: float
    osc_1__detune_power: float
    osc_1__detune_range: float
    osc_1__distortion_amount: float
    osc_1__distortion_phase: float
    osc_1__distortion_spread: float
    osc_1__distortion_type: float
    osc_1__frame_spread: float
    osc_1__level: float
    osc_1__midi_track: float
    osc_1__on: float
    osc_1__pan: float
    osc_1__phase: float
    osc_1__random_phase: float
    osc_1__smooth_interpolation: float
    osc_1__spectral_morph_amount: float
    osc_1__spectral_morph_spread: float
    osc_1__spectral_morph_type: float
    osc_1__spectral_unison: float
    osc_1__stack_style: float
    osc_1__stereo_spread: float
    osc_1__transpose: float
    osc_1__transpose_quantize: float
    osc_1__tune: float
    osc_1__unison_blend: float
    osc_1__unison_detune: float
    osc_1__unison_voices: float
    osc_1__view_2_d: float
    osc_1__wave_frame: float
    osc_2__destination: float
    osc_2__detune_power: float
    osc_2__detune_range: float
    osc_2__distortion_amount: float
    osc_2__distortion_phase: float
    osc_2__distortion_spread: float
    osc_2__distortion_type: float
    osc_2__frame_spread: float
    osc_2__level: float
    osc_2__midi_track: float
    osc_2__on: float
    osc_2__pan: float
    osc_2__phase: float
    osc_2__random_phase: float
    osc_2__smooth_interpolation: float
    osc_2__spectral_morph_amount: float
    osc_2__spectral_morph_spread: float
    osc_2__spectral_morph_type: float
    osc_2__spectral_unison: float
    osc_2__stack_style: float
    osc_2__stereo_spread: float
    osc_2__transpose: float
    osc_2__transpose_quantize: float
    osc_2__tune: float
    osc_2__unison_blend: float
    osc_2__unison_detune: float
    osc_2__unison_voices: float
    osc_2__view_2_d: float
    osc_2__wave_frame: float
    osc_3__destination: float
    osc_3__detune_power: float
    osc_3__detune_range: float
    osc_3__distortion_amount: float
    osc_3__distortion_phase: float
    osc_3__distortion_spread: float
    osc_3__distortion_type: float
    osc_3__frame_spread: float
    osc_3__level: float
    osc_3__midi_track: float
    osc_3__on: float
    osc_3__pan: float
    osc_3__phase: float
    osc_3__random_phase: float
    osc_3__smooth_interpolation: float
    osc_3__spectral_morph_amount: float
    osc_3__spectral_morph_spread: float
    osc_3__spectral_morph_type: float
    osc_3__spectral_unison: float
    osc_3__stack_style: float
    osc_3__stereo_spread: float
    osc_3__transpose: float
    osc_3__transpose_quantize: float
    osc_3__tune: float
    osc_3__unison_blend: float
    osc_3__unison_detune: float
    osc_3__unison_voices: float
    osc_3__view_2_d: float
    osc_3__wave_frame: float
    oversampling: float
    phaser_blend: float
    phaser_center: float
    phaser_dry_wet: float
    phaser_feedback: float
    phaser_frequency: float
    phaser_mod_depth: float
    phaser_on: float
    phaser_phase_offset: float
    phaser_sync: float
    phaser_tempo: float
    pitch_bend_range: float
    pitch_wheel: float
    polyphony: float
    portamento_force: float
    portamento_scale: float
    portamento_slope: float
    portamento_time: float
    random_1__frequency: float
    random_1__stereo: float
    random_1__style: float
    random_1__sync: float
    random_1__sync_type: float
    random_1__tempo: float
    random_2__frequency: float
    random_2__stereo: float
    random_2__style: float
    random_2__sync: float
    random_2__sync_type: float
    random_2__tempo: float
    random_3__frequency: float
    random_3__stereo: float
    random_3__style: float
    random_3__sync: float
    random_3__sync_type: float
    random_3__tempo: float
    random_4__frequency: float
    random_4__stereo: float
    random_4__style: float
    random_4__sync: float
    random_4__sync_type: float
    random_4__tempo: float
    reverb_chorus_amount: float
    reverb_chorus_frequency: float
    reverb_decay_time: float
    reverb_dry_wet: float
    reverb_high_shelf_cutoff: float
    reverb_high_shelf_gain: float
    reverb_low_shelf_cutoff: float
    reverb_low_shelf_gain: float
    reverb_on: float
    reverb_pre_high_cutoff: float
    reverb_pre_low_cutoff: float
    reverb_size: float
    sample: Sample
    sample_destination: float
    sample_keytrack: float
    sample_level: float
    sample_loop: float
    sample_on: float
    sample_pan: float
    sample_random_phase: float
    sample_transpose: float
    sample_transpose_quantize: float
    sample_tune: float
    stereo_routing: float
    velocity_track: float
    voice_amplitude: float
    voice_priority: float
    voice_tune: float
    volume: float
    wavetables: List[Wavetable]
    bypass: Optional[float] = None
    chorus_cutoff: Optional[float] = None
    chorus_damping: Optional[float] = None
    chorus_spread: Optional[float] = None
    compressor_mix: Optional[float] = None
    filter_1__formant_spread: Optional[float] = None
    filter_2__formant_spread: Optional[float] = None
    filter_fx_formant_spread: Optional[float] = None
    lfo_1__keytrack_transpose: Optional[float] = None
    lfo_1__keytrack_tune: Optional[float] = None
    lfo_1__smooth_mode: Optional[float] = None
    lfo_1__smooth_time: Optional[float] = None
    lfo_2__keytrack_transpose: Optional[float] = None
    lfo_2__keytrack_tune: Optional[float] = None
    lfo_2__smooth_mode: Optional[float] = None
    lfo_2__smooth_time: Optional[float] = None
    lfo_3__keytrack_transpose: Optional[float] = None
    lfo_3__keytrack_tune: Optional[float] = None
    lfo_3__smooth_mode: Optional[float] = None
    lfo_3__smooth_time: Optional[float] = None
    lfo_4__keytrack_transpose: Optional[float] = None
    lfo_4__keytrack_tune: Optional[float] = None
    lfo_4__smooth_mode: Optional[float] = None
    lfo_4__smooth_time: Optional[float] = None
    lfo_5__keytrack_transpose: Optional[float] = None
    lfo_5__keytrack_tune: Optional[float] = None
    lfo_5__smooth_mode: Optional[float] = None
    lfo_5__smooth_time: Optional[float] = None
    lfo_6__keytrack_transpose: Optional[float] = None
    lfo_6__keytrack_tune: Optional[float] = None
    lfo_6__smooth_mode: Optional[float] = None
    lfo_6__smooth_time: Optional[float] = None
    lfo_7__keytrack_transpose: Optional[float] = None
    lfo_7__keytrack_tune: Optional[float] = None
    lfo_7__smooth_mode: Optional[float] = None
    lfo_7__smooth_time: Optional[float] = None
    lfo_8__keytrack_transpose: Optional[float] = None
    lfo_8__keytrack_tune: Optional[float] = None
    lfo_8__smooth_mode: Optional[float] = None
    lfo_8__smooth_time: Optional[float] = None
    random_1__keytrack_transpose: Optional[float] = None
    random_1__keytrack_tune: Optional[float] = None
    random_2__keytrack_transpose: Optional[float] = None
    random_2__keytrack_tune: Optional[float] = None
    random_3__keytrack_transpose: Optional[float] = None
    random_3__keytrack_tune: Optional[float] = None
    random_4__keytrack_transpose: Optional[float] = None
    random_4__keytrack_tune: Optional[float] = None
    reverb_delay: Optional[float] = None
    sample_bounce: Optional[float] = None
    stereo_mode: Optional[float] = None
    view_spectrogram: Optional[float] = None
    voice_override: Optional[float] = None
    voice_transpose: Optional[float] = None

    @staticmethod
    def from_dict(obj: Any) -> 'PresetSettings':
        assert isinstance(obj, dict)
        beats_per_minute = from_float(obj.get("beats_per_minute"))
        chorus_delay_1 = from_float(obj.get("chorus_delay_1"))
        chorus_delay_2 = from_float(obj.get("chorus_delay_2"))
        chorus_dry_wet = from_float(obj.get("chorus_dry_wet"))
        chorus_feedback = from_float(obj.get("chorus_feedback"))
        chorus_frequency = from_float(obj.get("chorus_frequency"))
        chorus_mod_depth = from_float(obj.get("chorus_mod_depth"))
        chorus_on = from_float(obj.get("chorus_on"))
        chorus_sync = from_float(obj.get("chorus_sync"))
        chorus_tempo = from_float(obj.get("chorus_tempo"))
        chorus_voices = from_float(obj.get("chorus_voices"))
        compressor_attack = from_float(obj.get("compressor_attack"))
        compressor_band_gain = from_float(obj.get("compressor_band_gain"))
        compressor_band_lower_ratio = from_float(obj.get("compressor_band_lower_ratio"))
        compressor_band_lower_threshold = from_float(obj.get("compressor_band_lower_threshold"))
        compressor_band_upper_ratio = from_float(obj.get("compressor_band_upper_ratio"))
        compressor_band_upper_threshold = from_float(obj.get("compressor_band_upper_threshold"))
        compressor_enabled_bands = from_float(obj.get("compressor_enabled_bands"))
        compressor_high_gain = from_float(obj.get("compressor_high_gain"))
        compressor_high_lower_ratio = from_float(obj.get("compressor_high_lower_ratio"))
        compressor_high_lower_threshold = from_float(obj.get("compressor_high_lower_threshold"))
        compressor_high_upper_ratio = from_float(obj.get("compressor_high_upper_ratio"))
        compressor_high_upper_threshold = from_float(obj.get("compressor_high_upper_threshold"))
        compressor_low_gain = from_float(obj.get("compressor_low_gain"))
        compressor_low_lower_ratio = from_float(obj.get("compressor_low_lower_ratio"))
        compressor_low_lower_threshold = from_float(obj.get("compressor_low_lower_threshold"))
        compressor_low_upper_ratio = from_float(obj.get("compressor_low_upper_ratio"))
        compressor_low_upper_threshold = from_float(obj.get("compressor_low_upper_threshold"))
        compressor_on = from_float(obj.get("compressor_on"))
        compressor_release = from_float(obj.get("compressor_release"))
        delay_aux_frequency = from_float(obj.get("delay_aux_frequency"))
        delay_aux_sync = from_float(obj.get("delay_aux_sync"))
        delay_aux_tempo = from_float(obj.get("delay_aux_tempo"))
        delay_dry_wet = from_float(obj.get("delay_dry_wet"))
        delay_feedback = from_float(obj.get("delay_feedback"))
        delay_filter_cutoff = from_float(obj.get("delay_filter_cutoff"))
        delay_filter_spread = from_float(obj.get("delay_filter_spread"))
        delay_frequency = from_float(obj.get("delay_frequency"))
        delay_on = from_float(obj.get("delay_on"))
        delay_style = from_float(obj.get("delay_style"))
        delay_sync = from_float(obj.get("delay_sync"))
        delay_tempo = from_float(obj.get("delay_tempo"))
        distortion_drive = from_float(obj.get("distortion_drive"))
        distortion_filter_blend = from_float(obj.get("distortion_filter_blend"))
        distortion_filter_cutoff = from_float(obj.get("distortion_filter_cutoff"))
        distortion_filter_order = from_float(obj.get("distortion_filter_order"))
        distortion_filter_resonance = from_float(obj.get("distortion_filter_resonance"))
        distortion_mix = from_float(obj.get("distortion_mix"))
        distortion_on = from_float(obj.get("distortion_on"))
        distortion_type = from_float(obj.get("distortion_type"))
        effect_chain_order = from_float(obj.get("effect_chain_order"))
        env_1__attack = from_float(obj.get("env_1_attack"))
        env_1__attack_power = from_float(obj.get("env_1_attack_power"))
        env_1__decay = from_float(obj.get("env_1_decay"))
        env_1__decay_power = from_float(obj.get("env_1_decay_power"))
        env_1__delay = from_float(obj.get("env_1_delay"))
        env_1__hold = from_float(obj.get("env_1_hold"))
        env_1__release = from_float(obj.get("env_1_release"))
        env_1__release_power = from_float(obj.get("env_1_release_power"))
        env_1__sustain = from_float(obj.get("env_1_sustain"))
        env_2__attack = from_float(obj.get("env_2_attack"))
        env_2__attack_power = from_float(obj.get("env_2_attack_power"))
        env_2__decay = from_float(obj.get("env_2_decay"))
        env_2__decay_power = from_float(obj.get("env_2_decay_power"))
        env_2__delay = from_float(obj.get("env_2_delay"))
        env_2__hold = from_float(obj.get("env_2_hold"))
        env_2__release = from_float(obj.get("env_2_release"))
        env_2__release_power = from_float(obj.get("env_2_release_power"))
        env_2__sustain = from_float(obj.get("env_2_sustain"))
        env_3__attack = from_float(obj.get("env_3_attack"))
        env_3__attack_power = from_float(obj.get("env_3_attack_power"))
        env_3__decay = from_float(obj.get("env_3_decay"))
        env_3__decay_power = from_float(obj.get("env_3_decay_power"))
        env_3__delay = from_float(obj.get("env_3_delay"))
        env_3__hold = from_float(obj.get("env_3_hold"))
        env_3__release = from_float(obj.get("env_3_release"))
        env_3__release_power = from_float(obj.get("env_3_release_power"))
        env_3__sustain = from_float(obj.get("env_3_sustain"))
        env_4__attack = from_float(obj.get("env_4_attack"))
        env_4__attack_power = from_float(obj.get("env_4_attack_power"))
        env_4__decay = from_float(obj.get("env_4_decay"))
        env_4__decay_power = from_float(obj.get("env_4_decay_power"))
        env_4__delay = from_float(obj.get("env_4_delay"))
        env_4__hold = from_float(obj.get("env_4_hold"))
        env_4__release = from_float(obj.get("env_4_release"))
        env_4__release_power = from_float(obj.get("env_4_release_power"))
        env_4__sustain = from_float(obj.get("env_4_sustain"))
        env_5__attack = from_float(obj.get("env_5_attack"))
        env_5__attack_power = from_float(obj.get("env_5_attack_power"))
        env_5__decay = from_float(obj.get("env_5_decay"))
        env_5__decay_power = from_float(obj.get("env_5_decay_power"))
        env_5__delay = from_float(obj.get("env_5_delay"))
        env_5__hold = from_float(obj.get("env_5_hold"))
        env_5__release = from_float(obj.get("env_5_release"))
        env_5__release_power = from_float(obj.get("env_5_release_power"))
        env_5__sustain = from_float(obj.get("env_5_sustain"))
        env_6__attack = from_float(obj.get("env_6_attack"))
        env_6__attack_power = from_float(obj.get("env_6_attack_power"))
        env_6__decay = from_float(obj.get("env_6_decay"))
        env_6__decay_power = from_float(obj.get("env_6_decay_power"))
        env_6__delay = from_float(obj.get("env_6_delay"))
        env_6__hold = from_float(obj.get("env_6_hold"))
        env_6__release = from_float(obj.get("env_6_release"))
        env_6__release_power = from_float(obj.get("env_6_release_power"))
        env_6__sustain = from_float(obj.get("env_6_sustain"))
        eq_band_cutoff = from_float(obj.get("eq_band_cutoff"))
        eq_band_gain = from_float(obj.get("eq_band_gain"))
        eq_band_mode = from_float(obj.get("eq_band_mode"))
        eq_band_resonance = from_float(obj.get("eq_band_resonance"))
        eq_high_cutoff = from_float(obj.get("eq_high_cutoff"))
        eq_high_gain = from_float(obj.get("eq_high_gain"))
        eq_high_mode = from_float(obj.get("eq_high_mode"))
        eq_high_resonance = from_float(obj.get("eq_high_resonance"))
        eq_low_cutoff = from_float(obj.get("eq_low_cutoff"))
        eq_low_gain = from_float(obj.get("eq_low_gain"))
        eq_low_mode = from_float(obj.get("eq_low_mode"))
        eq_low_resonance = from_float(obj.get("eq_low_resonance"))
        eq_on = from_float(obj.get("eq_on"))
        filter_1__blend = from_float(obj.get("filter_1_blend"))
        filter_1__blend_transpose = from_float(obj.get("filter_1_blend_transpose"))
        filter_1__cutoff = from_float(obj.get("filter_1_cutoff"))
        filter_1__drive = from_float(obj.get("filter_1_drive"))
        filter_1__filter_input = from_float(obj.get("filter_1_filter_input"))
        filter_1__formant_resonance = from_float(obj.get("filter_1_formant_resonance"))
        filter_1__formant_transpose = from_float(obj.get("filter_1_formant_transpose"))
        filter_1__formant_x = from_float(obj.get("filter_1_formant_x"))
        filter_1__formant_y = from_float(obj.get("filter_1_formant_y"))
        filter_1__keytrack = from_float(obj.get("filter_1_keytrack"))
        filter_1__mix = from_float(obj.get("filter_1_mix"))
        filter_1__model = from_float(obj.get("filter_1_model"))
        filter_1__on = from_float(obj.get("filter_1_on"))
        filter_1__resonance = from_float(obj.get("filter_1_resonance"))
        filter_1__style = from_float(obj.get("filter_1_style"))
        filter_2__blend = from_float(obj.get("filter_2_blend"))
        filter_2__blend_transpose = from_float(obj.get("filter_2_blend_transpose"))
        filter_2__cutoff = from_float(obj.get("filter_2_cutoff"))
        filter_2__drive = from_float(obj.get("filter_2_drive"))
        filter_2__filter_input = from_float(obj.get("filter_2_filter_input"))
        filter_2__formant_resonance = from_float(obj.get("filter_2_formant_resonance"))
        filter_2__formant_transpose = from_float(obj.get("filter_2_formant_transpose"))
        filter_2__formant_x = from_float(obj.get("filter_2_formant_x"))
        filter_2__formant_y = from_float(obj.get("filter_2_formant_y"))
        filter_2__keytrack = from_float(obj.get("filter_2_keytrack"))
        filter_2__mix = from_float(obj.get("filter_2_mix"))
        filter_2__model = from_float(obj.get("filter_2_model"))
        filter_2__on = from_float(obj.get("filter_2_on"))
        filter_2__resonance = from_float(obj.get("filter_2_resonance"))
        filter_2__style = from_float(obj.get("filter_2_style"))
        filter_fx_blend = from_float(obj.get("filter_fx_blend"))
        filter_fx_blend_transpose = from_float(obj.get("filter_fx_blend_transpose"))
        filter_fx_cutoff = from_float(obj.get("filter_fx_cutoff"))
        filter_fx_drive = from_float(obj.get("filter_fx_drive"))
        filter_fx_formant_resonance = from_float(obj.get("filter_fx_formant_resonance"))
        filter_fx_formant_transpose = from_float(obj.get("filter_fx_formant_transpose"))
        filter_fx_formant_x = from_float(obj.get("filter_fx_formant_x"))
        filter_fx_formant_y = from_float(obj.get("filter_fx_formant_y"))
        filter_fx_keytrack = from_float(obj.get("filter_fx_keytrack"))
        filter_fx_mix = from_float(obj.get("filter_fx_mix"))
        filter_fx_model = from_float(obj.get("filter_fx_model"))
        filter_fx_on = from_float(obj.get("filter_fx_on"))
        filter_fx_resonance = from_float(obj.get("filter_fx_resonance"))
        filter_fx_style = from_float(obj.get("filter_fx_style"))
        flanger_center = from_float(obj.get("flanger_center"))
        flanger_dry_wet = from_float(obj.get("flanger_dry_wet"))
        flanger_feedback = from_float(obj.get("flanger_feedback"))
        flanger_frequency = from_float(obj.get("flanger_frequency"))
        flanger_mod_depth = from_float(obj.get("flanger_mod_depth"))
        flanger_on = from_float(obj.get("flanger_on"))
        flanger_phase_offset = from_float(obj.get("flanger_phase_offset"))
        flanger_sync = from_float(obj.get("flanger_sync"))
        flanger_tempo = from_float(obj.get("flanger_tempo"))
        legato = from_float(obj.get("legato"))
        lfo_1__delay_time = from_float(obj.get("lfo_1_delay_time"))
        lfo_1__fade_time = from_float(obj.get("lfo_1_fade_time"))
        lfo_1__frequency = from_float(obj.get("lfo_1_frequency"))
        lfo_1__phase = from_float(obj.get("lfo_1_phase"))
        lfo_1__stereo = from_float(obj.get("lfo_1_stereo"))
        lfo_1__sync = from_float(obj.get("lfo_1_sync"))
        lfo_1__sync_type = from_float(obj.get("lfo_1_sync_type"))
        lfo_1__tempo = from_float(obj.get("lfo_1_tempo"))
        lfo_2__delay_time = from_float(obj.get("lfo_2_delay_time"))
        lfo_2__fade_time = from_float(obj.get("lfo_2_fade_time"))
        lfo_2__frequency = from_float(obj.get("lfo_2_frequency"))
        lfo_2__phase = from_float(obj.get("lfo_2_phase"))
        lfo_2__stereo = from_float(obj.get("lfo_2_stereo"))
        lfo_2__sync = from_float(obj.get("lfo_2_sync"))
        lfo_2__sync_type = from_float(obj.get("lfo_2_sync_type"))
        lfo_2__tempo = from_float(obj.get("lfo_2_tempo"))
        lfo_3__delay_time = from_float(obj.get("lfo_3_delay_time"))
        lfo_3__fade_time = from_float(obj.get("lfo_3_fade_time"))
        lfo_3__frequency = from_float(obj.get("lfo_3_frequency"))
        lfo_3__phase = from_float(obj.get("lfo_3_phase"))
        lfo_3__stereo = from_float(obj.get("lfo_3_stereo"))
        lfo_3__sync = from_float(obj.get("lfo_3_sync"))
        lfo_3__sync_type = from_float(obj.get("lfo_3_sync_type"))
        lfo_3__tempo = from_float(obj.get("lfo_3_tempo"))
        lfo_4__delay_time = from_float(obj.get("lfo_4_delay_time"))
        lfo_4__fade_time = from_float(obj.get("lfo_4_fade_time"))
        lfo_4__frequency = from_float(obj.get("lfo_4_frequency"))
        lfo_4__phase = from_float(obj.get("lfo_4_phase"))
        lfo_4__stereo = from_float(obj.get("lfo_4_stereo"))
        lfo_4__sync = from_float(obj.get("lfo_4_sync"))
        lfo_4__sync_type = from_float(obj.get("lfo_4_sync_type"))
        lfo_4__tempo = from_float(obj.get("lfo_4_tempo"))
        lfo_5__delay_time = from_float(obj.get("lfo_5_delay_time"))
        lfo_5__fade_time = from_float(obj.get("lfo_5_fade_time"))
        lfo_5__frequency = from_float(obj.get("lfo_5_frequency"))
        lfo_5__phase = from_float(obj.get("lfo_5_phase"))
        lfo_5__stereo = from_float(obj.get("lfo_5_stereo"))
        lfo_5__sync = from_float(obj.get("lfo_5_sync"))
        lfo_5__sync_type = from_float(obj.get("lfo_5_sync_type"))
        lfo_5__tempo = from_float(obj.get("lfo_5_tempo"))
        lfo_6__delay_time = from_float(obj.get("lfo_6_delay_time"))
        lfo_6__fade_time = from_float(obj.get("lfo_6_fade_time"))
        lfo_6__frequency = from_float(obj.get("lfo_6_frequency"))
        lfo_6__phase = from_float(obj.get("lfo_6_phase"))
        lfo_6__stereo = from_float(obj.get("lfo_6_stereo"))
        lfo_6__sync = from_float(obj.get("lfo_6_sync"))
        lfo_6__sync_type = from_float(obj.get("lfo_6_sync_type"))
        lfo_6__tempo = from_float(obj.get("lfo_6_tempo"))
        lfo_7__delay_time = from_float(obj.get("lfo_7_delay_time"))
        lfo_7__fade_time = from_float(obj.get("lfo_7_fade_time"))
        lfo_7__frequency = from_float(obj.get("lfo_7_frequency"))
        lfo_7__phase = from_float(obj.get("lfo_7_phase"))
        lfo_7__stereo = from_float(obj.get("lfo_7_stereo"))
        lfo_7__sync = from_float(obj.get("lfo_7_sync"))
        lfo_7__sync_type = from_float(obj.get("lfo_7_sync_type"))
        lfo_7__tempo = from_float(obj.get("lfo_7_tempo"))
        lfo_8__delay_time = from_float(obj.get("lfo_8_delay_time"))
        lfo_8__fade_time = from_float(obj.get("lfo_8_fade_time"))
        lfo_8__frequency = from_float(obj.get("lfo_8_frequency"))
        lfo_8__phase = from_float(obj.get("lfo_8_phase"))
        lfo_8__stereo = from_float(obj.get("lfo_8_stereo"))
        lfo_8__sync = from_float(obj.get("lfo_8_sync"))
        lfo_8__sync_type = from_float(obj.get("lfo_8_sync_type"))
        lfo_8__tempo = from_float(obj.get("lfo_8_tempo"))
        lfos = from_list(Lfo.from_dict, obj.get("lfos"))
        macro_control_1 = from_float(obj.get("macro_control_1"))
        macro_control_2 = from_float(obj.get("macro_control_2"))
        macro_control_3 = from_float(obj.get("macro_control_3"))
        macro_control_4 = from_float(obj.get("macro_control_4"))
        mod_wheel = from_float(obj.get("mod_wheel"))
        modulation_10__amount = from_float(obj.get("modulation_10_amount"))
        modulation_10__bipolar = from_float(obj.get("modulation_10_bipolar"))
        modulation_10__bypass = from_float(obj.get("modulation_10_bypass"))
        modulation_10__power = from_float(obj.get("modulation_10_power"))
        modulation_10__stereo = from_float(obj.get("modulation_10_stereo"))
        modulation_11__amount = from_float(obj.get("modulation_11_amount"))
        modulation_11__bipolar = from_float(obj.get("modulation_11_bipolar"))
        modulation_11__bypass = from_float(obj.get("modulation_11_bypass"))
        modulation_11__power = from_float(obj.get("modulation_11_power"))
        modulation_11__stereo = from_float(obj.get("modulation_11_stereo"))
        modulation_12__amount = from_float(obj.get("modulation_12_amount"))
        modulation_12__bipolar = from_float(obj.get("modulation_12_bipolar"))
        modulation_12__bypass = from_float(obj.get("modulation_12_bypass"))
        modulation_12__power = from_float(obj.get("modulation_12_power"))
        modulation_12__stereo = from_float(obj.get("modulation_12_stereo"))
        modulation_13__amount = from_float(obj.get("modulation_13_amount"))
        modulation_13__bipolar = from_float(obj.get("modulation_13_bipolar"))
        modulation_13__bypass = from_float(obj.get("modulation_13_bypass"))
        modulation_13__power = from_float(obj.get("modulation_13_power"))
        modulation_13__stereo = from_float(obj.get("modulation_13_stereo"))
        modulation_14__amount = from_float(obj.get("modulation_14_amount"))
        modulation_14__bipolar = from_float(obj.get("modulation_14_bipolar"))
        modulation_14__bypass = from_float(obj.get("modulation_14_bypass"))
        modulation_14__power = from_float(obj.get("modulation_14_power"))
        modulation_14__stereo = from_float(obj.get("modulation_14_stereo"))
        modulation_15__amount = from_float(obj.get("modulation_15_amount"))
        modulation_15__bipolar = from_float(obj.get("modulation_15_bipolar"))
        modulation_15__bypass = from_float(obj.get("modulation_15_bypass"))
        modulation_15__power = from_float(obj.get("modulation_15_power"))
        modulation_15__stereo = from_float(obj.get("modulation_15_stereo"))
        modulation_16__amount = from_float(obj.get("modulation_16_amount"))
        modulation_16__bipolar = from_float(obj.get("modulation_16_bipolar"))
        modulation_16__bypass = from_float(obj.get("modulation_16_bypass"))
        modulation_16__power = from_float(obj.get("modulation_16_power"))
        modulation_16__stereo = from_float(obj.get("modulation_16_stereo"))
        modulation_17__amount = from_float(obj.get("modulation_17_amount"))
        modulation_17__bipolar = from_float(obj.get("modulation_17_bipolar"))
        modulation_17__bypass = from_float(obj.get("modulation_17_bypass"))
        modulation_17__power = from_float(obj.get("modulation_17_power"))
        modulation_17__stereo = from_float(obj.get("modulation_17_stereo"))
        modulation_18__amount = from_float(obj.get("modulation_18_amount"))
        modulation_18__bipolar = from_float(obj.get("modulation_18_bipolar"))
        modulation_18__bypass = from_float(obj.get("modulation_18_bypass"))
        modulation_18__power = from_float(obj.get("modulation_18_power"))
        modulation_18__stereo = from_float(obj.get("modulation_18_stereo"))
        modulation_19__amount = from_float(obj.get("modulation_19_amount"))
        modulation_19__bipolar = from_float(obj.get("modulation_19_bipolar"))
        modulation_19__bypass = from_float(obj.get("modulation_19_bypass"))
        modulation_19__power = from_float(obj.get("modulation_19_power"))
        modulation_19__stereo = from_float(obj.get("modulation_19_stereo"))
        modulation_1__amount = from_float(obj.get("modulation_1_amount"))
        modulation_1__bipolar = from_float(obj.get("modulation_1_bipolar"))
        modulation_1__bypass = from_float(obj.get("modulation_1_bypass"))
        modulation_1__power = from_float(obj.get("modulation_1_power"))
        modulation_1__stereo = from_float(obj.get("modulation_1_stereo"))
        modulation_20__amount = from_float(obj.get("modulation_20_amount"))
        modulation_20__bipolar = from_float(obj.get("modulation_20_bipolar"))
        modulation_20__bypass = from_float(obj.get("modulation_20_bypass"))
        modulation_20__power = from_float(obj.get("modulation_20_power"))
        modulation_20__stereo = from_float(obj.get("modulation_20_stereo"))
        modulation_21__amount = from_float(obj.get("modulation_21_amount"))
        modulation_21__bipolar = from_float(obj.get("modulation_21_bipolar"))
        modulation_21__bypass = from_float(obj.get("modulation_21_bypass"))
        modulation_21__power = from_float(obj.get("modulation_21_power"))
        modulation_21__stereo = from_float(obj.get("modulation_21_stereo"))
        modulation_22__amount = from_float(obj.get("modulation_22_amount"))
        modulation_22__bipolar = from_float(obj.get("modulation_22_bipolar"))
        modulation_22__bypass = from_float(obj.get("modulation_22_bypass"))
        modulation_22__power = from_float(obj.get("modulation_22_power"))
        modulation_22__stereo = from_float(obj.get("modulation_22_stereo"))
        modulation_23__amount = from_float(obj.get("modulation_23_amount"))
        modulation_23__bipolar = from_float(obj.get("modulation_23_bipolar"))
        modulation_23__bypass = from_float(obj.get("modulation_23_bypass"))
        modulation_23__power = from_float(obj.get("modulation_23_power"))
        modulation_23__stereo = from_float(obj.get("modulation_23_stereo"))
        modulation_24__amount = from_float(obj.get("modulation_24_amount"))
        modulation_24__bipolar = from_float(obj.get("modulation_24_bipolar"))
        modulation_24__bypass = from_float(obj.get("modulation_24_bypass"))
        modulation_24__power = from_float(obj.get("modulation_24_power"))
        modulation_24__stereo = from_float(obj.get("modulation_24_stereo"))
        modulation_25__amount = from_float(obj.get("modulation_25_amount"))
        modulation_25__bipolar = from_float(obj.get("modulation_25_bipolar"))
        modulation_25__bypass = from_float(obj.get("modulation_25_bypass"))
        modulation_25__power = from_float(obj.get("modulation_25_power"))
        modulation_25__stereo = from_float(obj.get("modulation_25_stereo"))
        modulation_26__amount = from_float(obj.get("modulation_26_amount"))
        modulation_26__bipolar = from_float(obj.get("modulation_26_bipolar"))
        modulation_26__bypass = from_float(obj.get("modulation_26_bypass"))
        modulation_26__power = from_float(obj.get("modulation_26_power"))
        modulation_26__stereo = from_float(obj.get("modulation_26_stereo"))
        modulation_27__amount = from_float(obj.get("modulation_27_amount"))
        modulation_27__bipolar = from_float(obj.get("modulation_27_bipolar"))
        modulation_27__bypass = from_float(obj.get("modulation_27_bypass"))
        modulation_27__power = from_float(obj.get("modulation_27_power"))
        modulation_27__stereo = from_float(obj.get("modulation_27_stereo"))
        modulation_28__amount = from_float(obj.get("modulation_28_amount"))
        modulation_28__bipolar = from_float(obj.get("modulation_28_bipolar"))
        modulation_28__bypass = from_float(obj.get("modulation_28_bypass"))
        modulation_28__power = from_float(obj.get("modulation_28_power"))
        modulation_28__stereo = from_float(obj.get("modulation_28_stereo"))
        modulation_29__amount = from_float(obj.get("modulation_29_amount"))
        modulation_29__bipolar = from_float(obj.get("modulation_29_bipolar"))
        modulation_29__bypass = from_float(obj.get("modulation_29_bypass"))
        modulation_29__power = from_float(obj.get("modulation_29_power"))
        modulation_29__stereo = from_float(obj.get("modulation_29_stereo"))
        modulation_2__amount = from_float(obj.get("modulation_2_amount"))
        modulation_2__bipolar = from_float(obj.get("modulation_2_bipolar"))
        modulation_2__bypass = from_float(obj.get("modulation_2_bypass"))
        modulation_2__power = from_float(obj.get("modulation_2_power"))
        modulation_2__stereo = from_float(obj.get("modulation_2_stereo"))
        modulation_30__amount = from_float(obj.get("modulation_30_amount"))
        modulation_30__bipolar = from_float(obj.get("modulation_30_bipolar"))
        modulation_30__bypass = from_float(obj.get("modulation_30_bypass"))
        modulation_30__power = from_float(obj.get("modulation_30_power"))
        modulation_30__stereo = from_float(obj.get("modulation_30_stereo"))
        modulation_31__amount = from_float(obj.get("modulation_31_amount"))
        modulation_31__bipolar = from_float(obj.get("modulation_31_bipolar"))
        modulation_31__bypass = from_float(obj.get("modulation_31_bypass"))
        modulation_31__power = from_float(obj.get("modulation_31_power"))
        modulation_31__stereo = from_float(obj.get("modulation_31_stereo"))
        modulation_32__amount = from_float(obj.get("modulation_32_amount"))
        modulation_32__bipolar = from_float(obj.get("modulation_32_bipolar"))
        modulation_32__bypass = from_float(obj.get("modulation_32_bypass"))
        modulation_32__power = from_float(obj.get("modulation_32_power"))
        modulation_32__stereo = from_float(obj.get("modulation_32_stereo"))
        modulation_33__amount = from_float(obj.get("modulation_33_amount"))
        modulation_33__bipolar = from_float(obj.get("modulation_33_bipolar"))
        modulation_33__bypass = from_float(obj.get("modulation_33_bypass"))
        modulation_33__power = from_float(obj.get("modulation_33_power"))
        modulation_33__stereo = from_float(obj.get("modulation_33_stereo"))
        modulation_34__amount = from_float(obj.get("modulation_34_amount"))
        modulation_34__bipolar = from_float(obj.get("modulation_34_bipolar"))
        modulation_34__bypass = from_float(obj.get("modulation_34_bypass"))
        modulation_34__power = from_float(obj.get("modulation_34_power"))
        modulation_34__stereo = from_float(obj.get("modulation_34_stereo"))
        modulation_35__amount = from_float(obj.get("modulation_35_amount"))
        modulation_35__bipolar = from_float(obj.get("modulation_35_bipolar"))
        modulation_35__bypass = from_float(obj.get("modulation_35_bypass"))
        modulation_35__power = from_float(obj.get("modulation_35_power"))
        modulation_35__stereo = from_float(obj.get("modulation_35_stereo"))
        modulation_36__amount = from_float(obj.get("modulation_36_amount"))
        modulation_36__bipolar = from_float(obj.get("modulation_36_bipolar"))
        modulation_36__bypass = from_float(obj.get("modulation_36_bypass"))
        modulation_36__power = from_float(obj.get("modulation_36_power"))
        modulation_36__stereo = from_float(obj.get("modulation_36_stereo"))
        modulation_37__amount = from_float(obj.get("modulation_37_amount"))
        modulation_37__bipolar = from_float(obj.get("modulation_37_bipolar"))
        modulation_37__bypass = from_float(obj.get("modulation_37_bypass"))
        modulation_37__power = from_float(obj.get("modulation_37_power"))
        modulation_37__stereo = from_float(obj.get("modulation_37_stereo"))
        modulation_38__amount = from_float(obj.get("modulation_38_amount"))
        modulation_38__bipolar = from_float(obj.get("modulation_38_bipolar"))
        modulation_38__bypass = from_float(obj.get("modulation_38_bypass"))
        modulation_38__power = from_float(obj.get("modulation_38_power"))
        modulation_38__stereo = from_float(obj.get("modulation_38_stereo"))
        modulation_39__amount = from_float(obj.get("modulation_39_amount"))
        modulation_39__bipolar = from_float(obj.get("modulation_39_bipolar"))
        modulation_39__bypass = from_float(obj.get("modulation_39_bypass"))
        modulation_39__power = from_float(obj.get("modulation_39_power"))
        modulation_39__stereo = from_float(obj.get("modulation_39_stereo"))
        modulation_3__amount = from_float(obj.get("modulation_3_amount"))
        modulation_3__bipolar = from_float(obj.get("modulation_3_bipolar"))
        modulation_3__bypass = from_float(obj.get("modulation_3_bypass"))
        modulation_3__power = from_float(obj.get("modulation_3_power"))
        modulation_3__stereo = from_float(obj.get("modulation_3_stereo"))
        modulation_40__amount = from_float(obj.get("modulation_40_amount"))
        modulation_40__bipolar = from_float(obj.get("modulation_40_bipolar"))
        modulation_40__bypass = from_float(obj.get("modulation_40_bypass"))
        modulation_40__power = from_float(obj.get("modulation_40_power"))
        modulation_40__stereo = from_float(obj.get("modulation_40_stereo"))
        modulation_41__amount = from_float(obj.get("modulation_41_amount"))
        modulation_41__bipolar = from_float(obj.get("modulation_41_bipolar"))
        modulation_41__bypass = from_float(obj.get("modulation_41_bypass"))
        modulation_41__power = from_float(obj.get("modulation_41_power"))
        modulation_41__stereo = from_float(obj.get("modulation_41_stereo"))
        modulation_42__amount = from_float(obj.get("modulation_42_amount"))
        modulation_42__bipolar = from_float(obj.get("modulation_42_bipolar"))
        modulation_42__bypass = from_float(obj.get("modulation_42_bypass"))
        modulation_42__power = from_float(obj.get("modulation_42_power"))
        modulation_42__stereo = from_float(obj.get("modulation_42_stereo"))
        modulation_43__amount = from_float(obj.get("modulation_43_amount"))
        modulation_43__bipolar = from_float(obj.get("modulation_43_bipolar"))
        modulation_43__bypass = from_float(obj.get("modulation_43_bypass"))
        modulation_43__power = from_float(obj.get("modulation_43_power"))
        modulation_43__stereo = from_float(obj.get("modulation_43_stereo"))
        modulation_44__amount = from_float(obj.get("modulation_44_amount"))
        modulation_44__bipolar = from_float(obj.get("modulation_44_bipolar"))
        modulation_44__bypass = from_float(obj.get("modulation_44_bypass"))
        modulation_44__power = from_float(obj.get("modulation_44_power"))
        modulation_44__stereo = from_float(obj.get("modulation_44_stereo"))
        modulation_45__amount = from_float(obj.get("modulation_45_amount"))
        modulation_45__bipolar = from_float(obj.get("modulation_45_bipolar"))
        modulation_45__bypass = from_float(obj.get("modulation_45_bypass"))
        modulation_45__power = from_float(obj.get("modulation_45_power"))
        modulation_45__stereo = from_float(obj.get("modulation_45_stereo"))
        modulation_46__amount = from_float(obj.get("modulation_46_amount"))
        modulation_46__bipolar = from_float(obj.get("modulation_46_bipolar"))
        modulation_46__bypass = from_float(obj.get("modulation_46_bypass"))
        modulation_46__power = from_float(obj.get("modulation_46_power"))
        modulation_46__stereo = from_float(obj.get("modulation_46_stereo"))
        modulation_47__amount = from_float(obj.get("modulation_47_amount"))
        modulation_47__bipolar = from_float(obj.get("modulation_47_bipolar"))
        modulation_47__bypass = from_float(obj.get("modulation_47_bypass"))
        modulation_47__power = from_float(obj.get("modulation_47_power"))
        modulation_47__stereo = from_float(obj.get("modulation_47_stereo"))
        modulation_48__amount = from_float(obj.get("modulation_48_amount"))
        modulation_48__bipolar = from_float(obj.get("modulation_48_bipolar"))
        modulation_48__bypass = from_float(obj.get("modulation_48_bypass"))
        modulation_48__power = from_float(obj.get("modulation_48_power"))
        modulation_48__stereo = from_float(obj.get("modulation_48_stereo"))
        modulation_49__amount = from_float(obj.get("modulation_49_amount"))
        modulation_49__bipolar = from_float(obj.get("modulation_49_bipolar"))
        modulation_49__bypass = from_float(obj.get("modulation_49_bypass"))
        modulation_49__power = from_float(obj.get("modulation_49_power"))
        modulation_49__stereo = from_float(obj.get("modulation_49_stereo"))
        modulation_4__amount = from_float(obj.get("modulation_4_amount"))
        modulation_4__bipolar = from_float(obj.get("modulation_4_bipolar"))
        modulation_4__bypass = from_float(obj.get("modulation_4_bypass"))
        modulation_4__power = from_float(obj.get("modulation_4_power"))
        modulation_4__stereo = from_float(obj.get("modulation_4_stereo"))
        modulation_50__amount = from_float(obj.get("modulation_50_amount"))
        modulation_50__bipolar = from_float(obj.get("modulation_50_bipolar"))
        modulation_50__bypass = from_float(obj.get("modulation_50_bypass"))
        modulation_50__power = from_float(obj.get("modulation_50_power"))
        modulation_50__stereo = from_float(obj.get("modulation_50_stereo"))
        modulation_51__amount = from_float(obj.get("modulation_51_amount"))
        modulation_51__bipolar = from_float(obj.get("modulation_51_bipolar"))
        modulation_51__bypass = from_float(obj.get("modulation_51_bypass"))
        modulation_51__power = from_float(obj.get("modulation_51_power"))
        modulation_51__stereo = from_float(obj.get("modulation_51_stereo"))
        modulation_52__amount = from_float(obj.get("modulation_52_amount"))
        modulation_52__bipolar = from_float(obj.get("modulation_52_bipolar"))
        modulation_52__bypass = from_float(obj.get("modulation_52_bypass"))
        modulation_52__power = from_float(obj.get("modulation_52_power"))
        modulation_52__stereo = from_float(obj.get("modulation_52_stereo"))
        modulation_53__amount = from_float(obj.get("modulation_53_amount"))
        modulation_53__bipolar = from_float(obj.get("modulation_53_bipolar"))
        modulation_53__bypass = from_float(obj.get("modulation_53_bypass"))
        modulation_53__power = from_float(obj.get("modulation_53_power"))
        modulation_53__stereo = from_float(obj.get("modulation_53_stereo"))
        modulation_54__amount = from_float(obj.get("modulation_54_amount"))
        modulation_54__bipolar = from_float(obj.get("modulation_54_bipolar"))
        modulation_54__bypass = from_float(obj.get("modulation_54_bypass"))
        modulation_54__power = from_float(obj.get("modulation_54_power"))
        modulation_54__stereo = from_float(obj.get("modulation_54_stereo"))
        modulation_55__amount = from_float(obj.get("modulation_55_amount"))
        modulation_55__bipolar = from_float(obj.get("modulation_55_bipolar"))
        modulation_55__bypass = from_float(obj.get("modulation_55_bypass"))
        modulation_55__power = from_float(obj.get("modulation_55_power"))
        modulation_55__stereo = from_float(obj.get("modulation_55_stereo"))
        modulation_56__amount = from_float(obj.get("modulation_56_amount"))
        modulation_56__bipolar = from_float(obj.get("modulation_56_bipolar"))
        modulation_56__bypass = from_float(obj.get("modulation_56_bypass"))
        modulation_56__power = from_float(obj.get("modulation_56_power"))
        modulation_56__stereo = from_float(obj.get("modulation_56_stereo"))
        modulation_57__amount = from_float(obj.get("modulation_57_amount"))
        modulation_57__bipolar = from_float(obj.get("modulation_57_bipolar"))
        modulation_57__bypass = from_float(obj.get("modulation_57_bypass"))
        modulation_57__power = from_float(obj.get("modulation_57_power"))
        modulation_57__stereo = from_float(obj.get("modulation_57_stereo"))
        modulation_58__amount = from_float(obj.get("modulation_58_amount"))
        modulation_58__bipolar = from_float(obj.get("modulation_58_bipolar"))
        modulation_58__bypass = from_float(obj.get("modulation_58_bypass"))
        modulation_58__power = from_float(obj.get("modulation_58_power"))
        modulation_58__stereo = from_float(obj.get("modulation_58_stereo"))
        modulation_59__amount = from_float(obj.get("modulation_59_amount"))
        modulation_59__bipolar = from_float(obj.get("modulation_59_bipolar"))
        modulation_59__bypass = from_float(obj.get("modulation_59_bypass"))
        modulation_59__power = from_float(obj.get("modulation_59_power"))
        modulation_59__stereo = from_float(obj.get("modulation_59_stereo"))
        modulation_5__amount = from_float(obj.get("modulation_5_amount"))
        modulation_5__bipolar = from_float(obj.get("modulation_5_bipolar"))
        modulation_5__bypass = from_float(obj.get("modulation_5_bypass"))
        modulation_5__power = from_float(obj.get("modulation_5_power"))
        modulation_5__stereo = from_float(obj.get("modulation_5_stereo"))
        modulation_60__amount = from_float(obj.get("modulation_60_amount"))
        modulation_60__bipolar = from_float(obj.get("modulation_60_bipolar"))
        modulation_60__bypass = from_float(obj.get("modulation_60_bypass"))
        modulation_60__power = from_float(obj.get("modulation_60_power"))
        modulation_60__stereo = from_float(obj.get("modulation_60_stereo"))
        modulation_61__amount = from_float(obj.get("modulation_61_amount"))
        modulation_61__bipolar = from_float(obj.get("modulation_61_bipolar"))
        modulation_61__bypass = from_float(obj.get("modulation_61_bypass"))
        modulation_61__power = from_float(obj.get("modulation_61_power"))
        modulation_61__stereo = from_float(obj.get("modulation_61_stereo"))
        modulation_62__amount = from_float(obj.get("modulation_62_amount"))
        modulation_62__bipolar = from_float(obj.get("modulation_62_bipolar"))
        modulation_62__bypass = from_float(obj.get("modulation_62_bypass"))
        modulation_62__power = from_float(obj.get("modulation_62_power"))
        modulation_62__stereo = from_float(obj.get("modulation_62_stereo"))
        modulation_63__amount = from_float(obj.get("modulation_63_amount"))
        modulation_63__bipolar = from_float(obj.get("modulation_63_bipolar"))
        modulation_63__bypass = from_float(obj.get("modulation_63_bypass"))
        modulation_63__power = from_float(obj.get("modulation_63_power"))
        modulation_63__stereo = from_float(obj.get("modulation_63_stereo"))
        modulation_64__amount = from_float(obj.get("modulation_64_amount"))
        modulation_64__bipolar = from_float(obj.get("modulation_64_bipolar"))
        modulation_64__bypass = from_float(obj.get("modulation_64_bypass"))
        modulation_64__power = from_float(obj.get("modulation_64_power"))
        modulation_64__stereo = from_float(obj.get("modulation_64_stereo"))
        modulation_6__amount = from_float(obj.get("modulation_6_amount"))
        modulation_6__bipolar = from_float(obj.get("modulation_6_bipolar"))
        modulation_6__bypass = from_float(obj.get("modulation_6_bypass"))
        modulation_6__power = from_float(obj.get("modulation_6_power"))
        modulation_6__stereo = from_float(obj.get("modulation_6_stereo"))
        modulation_7__amount = from_float(obj.get("modulation_7_amount"))
        modulation_7__bipolar = from_float(obj.get("modulation_7_bipolar"))
        modulation_7__bypass = from_float(obj.get("modulation_7_bypass"))
        modulation_7__power = from_float(obj.get("modulation_7_power"))
        modulation_7__stereo = from_float(obj.get("modulation_7_stereo"))
        modulation_8__amount = from_float(obj.get("modulation_8_amount"))
        modulation_8__bipolar = from_float(obj.get("modulation_8_bipolar"))
        modulation_8__bypass = from_float(obj.get("modulation_8_bypass"))
        modulation_8__power = from_float(obj.get("modulation_8_power"))
        modulation_8__stereo = from_float(obj.get("modulation_8_stereo"))
        modulation_9__amount = from_float(obj.get("modulation_9_amount"))
        modulation_9__bipolar = from_float(obj.get("modulation_9_bipolar"))
        modulation_9__bypass = from_float(obj.get("modulation_9_bypass"))
        modulation_9__power = from_float(obj.get("modulation_9_power"))
        modulation_9__stereo = from_float(obj.get("modulation_9_stereo"))
        modulations = from_list(Modulation.from_dict, obj.get("modulations"))
        osc_1__destination = from_float(obj.get("osc_1_destination"))
        osc_1__detune_power = from_float(obj.get("osc_1_detune_power"))
        osc_1__detune_range = from_float(obj.get("osc_1_detune_range"))
        osc_1__distortion_amount = from_float(obj.get("osc_1_distortion_amount"))
        osc_1__distortion_phase = from_float(obj.get("osc_1_distortion_phase"))
        osc_1__distortion_spread = from_float(obj.get("osc_1_distortion_spread"))
        osc_1__distortion_type = from_float(obj.get("osc_1_distortion_type"))
        osc_1__frame_spread = from_float(obj.get("osc_1_frame_spread"))
        osc_1__level = from_float(obj.get("osc_1_level"))
        osc_1__midi_track = from_float(obj.get("osc_1_midi_track"))
        osc_1__on = from_float(obj.get("osc_1_on"))
        osc_1__pan = from_float(obj.get("osc_1_pan"))
        osc_1__phase = from_float(obj.get("osc_1_phase"))
        osc_1__random_phase = from_float(obj.get("osc_1_random_phase"))
        osc_1__smooth_interpolation = from_float(obj.get("osc_1_smooth_interpolation"))
        osc_1__spectral_morph_amount = from_float(obj.get("osc_1_spectral_morph_amount"))
        osc_1__spectral_morph_spread = from_float(obj.get("osc_1_spectral_morph_spread"))
        osc_1__spectral_morph_type = from_float(obj.get("osc_1_spectral_morph_type"))
        osc_1__spectral_unison = from_float(obj.get("osc_1_spectral_unison"))
        osc_1__stack_style = from_float(obj.get("osc_1_stack_style"))
        osc_1__stereo_spread = from_float(obj.get("osc_1_stereo_spread"))
        osc_1__transpose = from_float(obj.get("osc_1_transpose"))
        osc_1__transpose_quantize = from_float(obj.get("osc_1_transpose_quantize"))
        osc_1__tune = from_float(obj.get("osc_1_tune"))
        osc_1__unison_blend = from_float(obj.get("osc_1_unison_blend"))
        osc_1__unison_detune = from_float(obj.get("osc_1_unison_detune"))
        osc_1__unison_voices = from_float(obj.get("osc_1_unison_voices"))
        osc_1__view_2_d = from_float(obj.get("osc_1_view_2d"))
        osc_1__wave_frame = from_float(obj.get("osc_1_wave_frame"))
        osc_2__destination = from_float(obj.get("osc_2_destination"))
        osc_2__detune_power = from_float(obj.get("osc_2_detune_power"))
        osc_2__detune_range = from_float(obj.get("osc_2_detune_range"))
        osc_2__distortion_amount = from_float(obj.get("osc_2_distortion_amount"))
        osc_2__distortion_phase = from_float(obj.get("osc_2_distortion_phase"))
        osc_2__distortion_spread = from_float(obj.get("osc_2_distortion_spread"))
        osc_2__distortion_type = from_float(obj.get("osc_2_distortion_type"))
        osc_2__frame_spread = from_float(obj.get("osc_2_frame_spread"))
        osc_2__level = from_float(obj.get("osc_2_level"))
        osc_2__midi_track = from_float(obj.get("osc_2_midi_track"))
        osc_2__on = from_float(obj.get("osc_2_on"))
        osc_2__pan = from_float(obj.get("osc_2_pan"))
        osc_2__phase = from_float(obj.get("osc_2_phase"))
        osc_2__random_phase = from_float(obj.get("osc_2_random_phase"))
        osc_2__smooth_interpolation = from_float(obj.get("osc_2_smooth_interpolation"))
        osc_2__spectral_morph_amount = from_float(obj.get("osc_2_spectral_morph_amount"))
        osc_2__spectral_morph_spread = from_float(obj.get("osc_2_spectral_morph_spread"))
        osc_2__spectral_morph_type = from_float(obj.get("osc_2_spectral_morph_type"))
        osc_2__spectral_unison = from_float(obj.get("osc_2_spectral_unison"))
        osc_2__stack_style = from_float(obj.get("osc_2_stack_style"))
        osc_2__stereo_spread = from_float(obj.get("osc_2_stereo_spread"))
        osc_2__transpose = from_float(obj.get("osc_2_transpose"))
        osc_2__transpose_quantize = from_float(obj.get("osc_2_transpose_quantize"))
        osc_2__tune = from_float(obj.get("osc_2_tune"))
        osc_2__unison_blend = from_float(obj.get("osc_2_unison_blend"))
        osc_2__unison_detune = from_float(obj.get("osc_2_unison_detune"))
        osc_2__unison_voices = from_float(obj.get("osc_2_unison_voices"))
        osc_2__view_2_d = from_float(obj.get("osc_2_view_2d"))
        osc_2__wave_frame = from_float(obj.get("osc_2_wave_frame"))
        osc_3__destination = from_float(obj.get("osc_3_destination"))
        osc_3__detune_power = from_float(obj.get("osc_3_detune_power"))
        osc_3__detune_range = from_float(obj.get("osc_3_detune_range"))
        osc_3__distortion_amount = from_float(obj.get("osc_3_distortion_amount"))
        osc_3__distortion_phase = from_float(obj.get("osc_3_distortion_phase"))
        osc_3__distortion_spread = from_float(obj.get("osc_3_distortion_spread"))
        osc_3__distortion_type = from_float(obj.get("osc_3_distortion_type"))
        osc_3__frame_spread = from_float(obj.get("osc_3_frame_spread"))
        osc_3__level = from_float(obj.get("osc_3_level"))
        osc_3__midi_track = from_float(obj.get("osc_3_midi_track"))
        osc_3__on = from_float(obj.get("osc_3_on"))
        osc_3__pan = from_float(obj.get("osc_3_pan"))
        osc_3__phase = from_float(obj.get("osc_3_phase"))
        osc_3__random_phase = from_float(obj.get("osc_3_random_phase"))
        osc_3__smooth_interpolation = from_float(obj.get("osc_3_smooth_interpolation"))
        osc_3__spectral_morph_amount = from_float(obj.get("osc_3_spectral_morph_amount"))
        osc_3__spectral_morph_spread = from_float(obj.get("osc_3_spectral_morph_spread"))
        osc_3__spectral_morph_type = from_float(obj.get("osc_3_spectral_morph_type"))
        osc_3__spectral_unison = from_float(obj.get("osc_3_spectral_unison"))
        osc_3__stack_style = from_float(obj.get("osc_3_stack_style"))
        osc_3__stereo_spread = from_float(obj.get("osc_3_stereo_spread"))
        osc_3__transpose = from_float(obj.get("osc_3_transpose"))
        osc_3__transpose_quantize = from_float(obj.get("osc_3_transpose_quantize"))
        osc_3__tune = from_float(obj.get("osc_3_tune"))
        osc_3__unison_blend = from_float(obj.get("osc_3_unison_blend"))
        osc_3__unison_detune = from_float(obj.get("osc_3_unison_detune"))
        osc_3__unison_voices = from_float(obj.get("osc_3_unison_voices"))
        osc_3__view_2_d = from_float(obj.get("osc_3_view_2d"))
        osc_3__wave_frame = from_float(obj.get("osc_3_wave_frame"))
        oversampling = from_float(obj.get("oversampling"))
        phaser_blend = from_float(obj.get("phaser_blend"))
        phaser_center = from_float(obj.get("phaser_center"))
        phaser_dry_wet = from_float(obj.get("phaser_dry_wet"))
        phaser_feedback = from_float(obj.get("phaser_feedback"))
        phaser_frequency = from_float(obj.get("phaser_frequency"))
        phaser_mod_depth = from_float(obj.get("phaser_mod_depth"))
        phaser_on = from_float(obj.get("phaser_on"))
        phaser_phase_offset = from_float(obj.get("phaser_phase_offset"))
        phaser_sync = from_float(obj.get("phaser_sync"))
        phaser_tempo = from_float(obj.get("phaser_tempo"))
        pitch_bend_range = from_float(obj.get("pitch_bend_range"))
        pitch_wheel = from_float(obj.get("pitch_wheel"))
        polyphony = from_float(obj.get("polyphony"))
        portamento_force = from_float(obj.get("portamento_force"))
        portamento_scale = from_float(obj.get("portamento_scale"))
        portamento_slope = from_float(obj.get("portamento_slope"))
        portamento_time = from_float(obj.get("portamento_time"))
        random_1__frequency = from_float(obj.get("random_1_frequency"))
        random_1__stereo = from_float(obj.get("random_1_stereo"))
        random_1__style = from_float(obj.get("random_1_style"))
        random_1__sync = from_float(obj.get("random_1_sync"))
        random_1__sync_type = from_float(obj.get("random_1_sync_type"))
        random_1__tempo = from_float(obj.get("random_1_tempo"))
        random_2__frequency = from_float(obj.get("random_2_frequency"))
        random_2__stereo = from_float(obj.get("random_2_stereo"))
        random_2__style = from_float(obj.get("random_2_style"))
        random_2__sync = from_float(obj.get("random_2_sync"))
        random_2__sync_type = from_float(obj.get("random_2_sync_type"))
        random_2__tempo = from_float(obj.get("random_2_tempo"))
        random_3__frequency = from_float(obj.get("random_3_frequency"))
        random_3__stereo = from_float(obj.get("random_3_stereo"))
        random_3__style = from_float(obj.get("random_3_style"))
        random_3__sync = from_float(obj.get("random_3_sync"))
        random_3__sync_type = from_float(obj.get("random_3_sync_type"))
        random_3__tempo = from_float(obj.get("random_3_tempo"))
        random_4__frequency = from_float(obj.get("random_4_frequency"))
        random_4__stereo = from_float(obj.get("random_4_stereo"))
        random_4__style = from_float(obj.get("random_4_style"))
        random_4__sync = from_float(obj.get("random_4_sync"))
        random_4__sync_type = from_float(obj.get("random_4_sync_type"))
        random_4__tempo = from_float(obj.get("random_4_tempo"))
        reverb_chorus_amount = from_float(obj.get("reverb_chorus_amount"))
        reverb_chorus_frequency = from_float(obj.get("reverb_chorus_frequency"))
        reverb_decay_time = from_float(obj.get("reverb_decay_time"))
        reverb_dry_wet = from_float(obj.get("reverb_dry_wet"))
        reverb_high_shelf_cutoff = from_float(obj.get("reverb_high_shelf_cutoff"))
        reverb_high_shelf_gain = from_float(obj.get("reverb_high_shelf_gain"))
        reverb_low_shelf_cutoff = from_float(obj.get("reverb_low_shelf_cutoff"))
        reverb_low_shelf_gain = from_float(obj.get("reverb_low_shelf_gain"))
        reverb_on = from_float(obj.get("reverb_on"))
        reverb_pre_high_cutoff = from_float(obj.get("reverb_pre_high_cutoff"))
        reverb_pre_low_cutoff = from_float(obj.get("reverb_pre_low_cutoff"))
        reverb_size = from_float(obj.get("reverb_size"))
        sample = Sample.from_dict(obj.get("sample"))
        sample_destination = from_float(obj.get("sample_destination"))
        sample_keytrack = from_float(obj.get("sample_keytrack"))
        sample_level = from_float(obj.get("sample_level"))
        sample_loop = from_float(obj.get("sample_loop"))
        sample_on = from_float(obj.get("sample_on"))
        sample_pan = from_float(obj.get("sample_pan"))
        sample_random_phase = from_float(obj.get("sample_random_phase"))
        sample_transpose = from_float(obj.get("sample_transpose"))
        sample_transpose_quantize = from_float(obj.get("sample_transpose_quantize"))
        sample_tune = from_float(obj.get("sample_tune"))
        stereo_routing = from_float(obj.get("stereo_routing"))
        velocity_track = from_float(obj.get("velocity_track"))
        voice_amplitude = from_float(obj.get("voice_amplitude"))
        voice_priority = from_float(obj.get("voice_priority"))
        voice_tune = from_float(obj.get("voice_tune"))
        volume = from_float(obj.get("volume"))
        wavetables = from_list(Wavetable.from_dict, obj.get("wavetables"))
        bypass = from_union([from_float, from_none], obj.get("bypass"))
        chorus_cutoff = from_union([from_float, from_none], obj.get("chorus_cutoff"))
        chorus_damping = from_union([from_float, from_none], obj.get("chorus_damping"))
        chorus_spread = from_union([from_float, from_none], obj.get("chorus_spread"))
        compressor_mix = from_union([from_float, from_none], obj.get("compressor_mix"))
        filter_1__formant_spread = from_union([from_float, from_none], obj.get("filter_1_formant_spread"))
        filter_2__formant_spread = from_union([from_float, from_none], obj.get("filter_2_formant_spread"))
        filter_fx_formant_spread = from_union([from_float, from_none], obj.get("filter_fx_formant_spread"))
        lfo_1__keytrack_transpose = from_union([from_float, from_none], obj.get("lfo_1_keytrack_transpose"))
        lfo_1__keytrack_tune = from_union([from_float, from_none], obj.get("lfo_1_keytrack_tune"))
        lfo_1__smooth_mode = from_union([from_float, from_none], obj.get("lfo_1_smooth_mode"))
        lfo_1__smooth_time = from_union([from_float, from_none], obj.get("lfo_1_smooth_time"))
        lfo_2__keytrack_transpose = from_union([from_float, from_none], obj.get("lfo_2_keytrack_transpose"))
        lfo_2__keytrack_tune = from_union([from_float, from_none], obj.get("lfo_2_keytrack_tune"))
        lfo_2__smooth_mode = from_union([from_float, from_none], obj.get("lfo_2_smooth_mode"))
        lfo_2__smooth_time = from_union([from_float, from_none], obj.get("lfo_2_smooth_time"))
        lfo_3__keytrack_transpose = from_union([from_float, from_none], obj.get("lfo_3_keytrack_transpose"))
        lfo_3__keytrack_tune = from_union([from_float, from_none], obj.get("lfo_3_keytrack_tune"))
        lfo_3__smooth_mode = from_union([from_float, from_none], obj.get("lfo_3_smooth_mode"))
        lfo_3__smooth_time = from_union([from_float, from_none], obj.get("lfo_3_smooth_time"))
        lfo_4__keytrack_transpose = from_union([from_float, from_none], obj.get("lfo_4_keytrack_transpose"))
        lfo_4__keytrack_tune = from_union([from_float, from_none], obj.get("lfo_4_keytrack_tune"))
        lfo_4__smooth_mode = from_union([from_float, from_none], obj.get("lfo_4_smooth_mode"))
        lfo_4__smooth_time = from_union([from_float, from_none], obj.get("lfo_4_smooth_time"))
        lfo_5__keytrack_transpose = from_union([from_float, from_none], obj.get("lfo_5_keytrack_transpose"))
        lfo_5__keytrack_tune = from_union([from_float, from_none], obj.get("lfo_5_keytrack_tune"))
        lfo_5__smooth_mode = from_union([from_float, from_none], obj.get("lfo_5_smooth_mode"))
        lfo_5__smooth_time = from_union([from_float, from_none], obj.get("lfo_5_smooth_time"))
        lfo_6__keytrack_transpose = from_union([from_float, from_none], obj.get("lfo_6_keytrack_transpose"))
        lfo_6__keytrack_tune = from_union([from_float, from_none], obj.get("lfo_6_keytrack_tune"))
        lfo_6__smooth_mode = from_union([from_float, from_none], obj.get("lfo_6_smooth_mode"))
        lfo_6__smooth_time = from_union([from_float, from_none], obj.get("lfo_6_smooth_time"))
        lfo_7__keytrack_transpose = from_union([from_float, from_none], obj.get("lfo_7_keytrack_transpose"))
        lfo_7__keytrack_tune = from_union([from_float, from_none], obj.get("lfo_7_keytrack_tune"))
        lfo_7__smooth_mode = from_union([from_float, from_none], obj.get("lfo_7_smooth_mode"))
        lfo_7__smooth_time = from_union([from_float, from_none], obj.get("lfo_7_smooth_time"))
        lfo_8__keytrack_transpose = from_union([from_float, from_none], obj.get("lfo_8_keytrack_transpose"))
        lfo_8__keytrack_tune = from_union([from_float, from_none], obj.get("lfo_8_keytrack_tune"))
        lfo_8__smooth_mode = from_union([from_float, from_none], obj.get("lfo_8_smooth_mode"))
        lfo_8__smooth_time = from_union([from_float, from_none], obj.get("lfo_8_smooth_time"))
        random_1__keytrack_transpose = from_union([from_float, from_none], obj.get("random_1_keytrack_transpose"))
        random_1__keytrack_tune = from_union([from_float, from_none], obj.get("random_1_keytrack_tune"))
        random_2__keytrack_transpose = from_union([from_float, from_none], obj.get("random_2_keytrack_transpose"))
        random_2__keytrack_tune = from_union([from_float, from_none], obj.get("random_2_keytrack_tune"))
        random_3__keytrack_transpose = from_union([from_float, from_none], obj.get("random_3_keytrack_transpose"))
        random_3__keytrack_tune = from_union([from_float, from_none], obj.get("random_3_keytrack_tune"))
        random_4__keytrack_transpose = from_union([from_float, from_none], obj.get("random_4_keytrack_transpose"))
        random_4__keytrack_tune = from_union([from_float, from_none], obj.get("random_4_keytrack_tune"))
        reverb_delay = from_union([from_float, from_none], obj.get("reverb_delay"))
        sample_bounce = from_union([from_float, from_none], obj.get("sample_bounce"))
        stereo_mode = from_union([from_float, from_none], obj.get("stereo_mode"))
        view_spectrogram = from_union([from_float, from_none], obj.get("view_spectrogram"))
        voice_override = from_union([from_float, from_none], obj.get("voice_override"))
        voice_transpose = from_union([from_float, from_none], obj.get("voice_transpose"))
        return PresetSettings(beats_per_minute, chorus_delay_1, chorus_delay_2, chorus_dry_wet, chorus_feedback, chorus_frequency, chorus_mod_depth, chorus_on, chorus_sync, chorus_tempo, chorus_voices, compressor_attack, compressor_band_gain, compressor_band_lower_ratio, compressor_band_lower_threshold, compressor_band_upper_ratio, compressor_band_upper_threshold, compressor_enabled_bands, compressor_high_gain, compressor_high_lower_ratio, compressor_high_lower_threshold, compressor_high_upper_ratio, compressor_high_upper_threshold, compressor_low_gain, compressor_low_lower_ratio, compressor_low_lower_threshold, compressor_low_upper_ratio, compressor_low_upper_threshold, compressor_on, compressor_release, delay_aux_frequency, delay_aux_sync, delay_aux_tempo, delay_dry_wet, delay_feedback, delay_filter_cutoff, delay_filter_spread, delay_frequency, delay_on, delay_style, delay_sync, delay_tempo, distortion_drive, distortion_filter_blend, distortion_filter_cutoff, distortion_filter_order, distortion_filter_resonance, distortion_mix, distortion_on, distortion_type, effect_chain_order, env_1__attack, env_1__attack_power, env_1__decay, env_1__decay_power, env_1__delay, env_1__hold, env_1__release, env_1__release_power, env_1__sustain, env_2__attack, env_2__attack_power, env_2__decay, env_2__decay_power, env_2__delay, env_2__hold, env_2__release, env_2__release_power, env_2__sustain, env_3__attack, env_3__attack_power, env_3__decay, env_3__decay_power, env_3__delay, env_3__hold, env_3__release, env_3__release_power, env_3__sustain, env_4__attack, env_4__attack_power, env_4__decay, env_4__decay_power, env_4__delay, env_4__hold, env_4__release, env_4__release_power, env_4__sustain, env_5__attack, env_5__attack_power, env_5__decay, env_5__decay_power, env_5__delay, env_5__hold, env_5__release, env_5__release_power, env_5__sustain, env_6__attack, env_6__attack_power, env_6__decay, env_6__decay_power, env_6__delay, env_6__hold, env_6__release, env_6__release_power, env_6__sustain, eq_band_cutoff, eq_band_gain, eq_band_mode, eq_band_resonance, eq_high_cutoff, eq_high_gain, eq_high_mode, eq_high_resonance, eq_low_cutoff, eq_low_gain, eq_low_mode, eq_low_resonance, eq_on, filter_1__blend, filter_1__blend_transpose, filter_1__cutoff, filter_1__drive, filter_1__filter_input, filter_1__formant_resonance, filter_1__formant_transpose, filter_1__formant_x, filter_1__formant_y, filter_1__keytrack, filter_1__mix, filter_1__model, filter_1__on, filter_1__resonance, filter_1__style, filter_2__blend, filter_2__blend_transpose, filter_2__cutoff, filter_2__drive, filter_2__filter_input, filter_2__formant_resonance, filter_2__formant_transpose, filter_2__formant_x, filter_2__formant_y, filter_2__keytrack, filter_2__mix, filter_2__model, filter_2__on, filter_2__resonance, filter_2__style, filter_fx_blend, filter_fx_blend_transpose, filter_fx_cutoff, filter_fx_drive, filter_fx_formant_resonance, filter_fx_formant_transpose, filter_fx_formant_x, filter_fx_formant_y, filter_fx_keytrack, filter_fx_mix, filter_fx_model, filter_fx_on, filter_fx_resonance, filter_fx_style, flanger_center, flanger_dry_wet, flanger_feedback, flanger_frequency, flanger_mod_depth, flanger_on, flanger_phase_offset, flanger_sync, flanger_tempo, legato, lfo_1__delay_time, lfo_1__fade_time, lfo_1__frequency, lfo_1__phase, lfo_1__stereo, lfo_1__sync, lfo_1__sync_type, lfo_1__tempo, lfo_2__delay_time, lfo_2__fade_time, lfo_2__frequency, lfo_2__phase, lfo_2__stereo, lfo_2__sync, lfo_2__sync_type, lfo_2__tempo, lfo_3__delay_time, lfo_3__fade_time, lfo_3__frequency, lfo_3__phase, lfo_3__stereo, lfo_3__sync, lfo_3__sync_type, lfo_3__tempo, lfo_4__delay_time, lfo_4__fade_time, lfo_4__frequency, lfo_4__phase, lfo_4__stereo, lfo_4__sync, lfo_4__sync_type, lfo_4__tempo, lfo_5__delay_time, lfo_5__fade_time, lfo_5__frequency, lfo_5__phase, lfo_5__stereo, lfo_5__sync, lfo_5__sync_type, lfo_5__tempo, lfo_6__delay_time, lfo_6__fade_time, lfo_6__frequency, lfo_6__phase, lfo_6__stereo, lfo_6__sync, lfo_6__sync_type, lfo_6__tempo, lfo_7__delay_time, lfo_7__fade_time, lfo_7__frequency, lfo_7__phase, lfo_7__stereo, lfo_7__sync, lfo_7__sync_type, lfo_7__tempo, lfo_8__delay_time, lfo_8__fade_time, lfo_8__frequency, lfo_8__phase, lfo_8__stereo, lfo_8__sync, lfo_8__sync_type, lfo_8__tempo, lfos, macro_control_1, macro_control_2, macro_control_3, macro_control_4, mod_wheel, modulation_10__amount, modulation_10__bipolar, modulation_10__bypass, modulation_10__power, modulation_10__stereo, modulation_11__amount, modulation_11__bipolar, modulation_11__bypass, modulation_11__power, modulation_11__stereo, modulation_12__amount, modulation_12__bipolar, modulation_12__bypass, modulation_12__power, modulation_12__stereo, modulation_13__amount, modulation_13__bipolar, modulation_13__bypass, modulation_13__power, modulation_13__stereo, modulation_14__amount, modulation_14__bipolar, modulation_14__bypass, modulation_14__power, modulation_14__stereo, modulation_15__amount, modulation_15__bipolar, modulation_15__bypass, modulation_15__power, modulation_15__stereo, modulation_16__amount, modulation_16__bipolar, modulation_16__bypass, modulation_16__power, modulation_16__stereo, modulation_17__amount, modulation_17__bipolar, modulation_17__bypass, modulation_17__power, modulation_17__stereo, modulation_18__amount, modulation_18__bipolar, modulation_18__bypass, modulation_18__power, modulation_18__stereo, modulation_19__amount, modulation_19__bipolar, modulation_19__bypass, modulation_19__power, modulation_19__stereo, modulation_1__amount, modulation_1__bipolar, modulation_1__bypass, modulation_1__power, modulation_1__stereo, modulation_20__amount, modulation_20__bipolar, modulation_20__bypass, modulation_20__power, modulation_20__stereo, modulation_21__amount, modulation_21__bipolar, modulation_21__bypass, modulation_21__power, modulation_21__stereo, modulation_22__amount, modulation_22__bipolar, modulation_22__bypass, modulation_22__power, modulation_22__stereo, modulation_23__amount, modulation_23__bipolar, modulation_23__bypass, modulation_23__power, modulation_23__stereo, modulation_24__amount, modulation_24__bipolar, modulation_24__bypass, modulation_24__power, modulation_24__stereo, modulation_25__amount, modulation_25__bipolar, modulation_25__bypass, modulation_25__power, modulation_25__stereo, modulation_26__amount, modulation_26__bipolar, modulation_26__bypass, modulation_26__power, modulation_26__stereo, modulation_27__amount, modulation_27__bipolar, modulation_27__bypass, modulation_27__power, modulation_27__stereo, modulation_28__amount, modulation_28__bipolar, modulation_28__bypass, modulation_28__power, modulation_28__stereo, modulation_29__amount, modulation_29__bipolar, modulation_29__bypass, modulation_29__power, modulation_29__stereo, modulation_2__amount, modulation_2__bipolar, modulation_2__bypass, modulation_2__power, modulation_2__stereo, modulation_30__amount, modulation_30__bipolar, modulation_30__bypass, modulation_30__power, modulation_30__stereo, modulation_31__amount, modulation_31__bipolar, modulation_31__bypass, modulation_31__power, modulation_31__stereo, modulation_32__amount, modulation_32__bipolar, modulation_32__bypass, modulation_32__power, modulation_32__stereo, modulation_33__amount, modulation_33__bipolar, modulation_33__bypass, modulation_33__power, modulation_33__stereo, modulation_34__amount, modulation_34__bipolar, modulation_34__bypass, modulation_34__power, modulation_34__stereo, modulation_35__amount, modulation_35__bipolar, modulation_35__bypass, modulation_35__power, modulation_35__stereo, modulation_36__amount, modulation_36__bipolar, modulation_36__bypass, modulation_36__power, modulation_36__stereo, modulation_37__amount, modulation_37__bipolar, modulation_37__bypass, modulation_37__power, modulation_37__stereo, modulation_38__amount, modulation_38__bipolar, modulation_38__bypass, modulation_38__power, modulation_38__stereo, modulation_39__amount, modulation_39__bipolar, modulation_39__bypass, modulation_39__power, modulation_39__stereo, modulation_3__amount, modulation_3__bipolar, modulation_3__bypass, modulation_3__power, modulation_3__stereo, modulation_40__amount, modulation_40__bipolar, modulation_40__bypass, modulation_40__power, modulation_40__stereo, modulation_41__amount, modulation_41__bipolar, modulation_41__bypass, modulation_41__power, modulation_41__stereo, modulation_42__amount, modulation_42__bipolar, modulation_42__bypass, modulation_42__power, modulation_42__stereo, modulation_43__amount, modulation_43__bipolar, modulation_43__bypass, modulation_43__power, modulation_43__stereo, modulation_44__amount, modulation_44__bipolar, modulation_44__bypass, modulation_44__power, modulation_44__stereo, modulation_45__amount, modulation_45__bipolar, modulation_45__bypass, modulation_45__power, modulation_45__stereo, modulation_46__amount, modulation_46__bipolar, modulation_46__bypass, modulation_46__power, modulation_46__stereo, modulation_47__amount, modulation_47__bipolar, modulation_47__bypass, modulation_47__power, modulation_47__stereo, modulation_48__amount, modulation_48__bipolar, modulation_48__bypass, modulation_48__power, modulation_48__stereo, modulation_49__amount, modulation_49__bipolar, modulation_49__bypass, modulation_49__power, modulation_49__stereo, modulation_4__amount, modulation_4__bipolar, modulation_4__bypass, modulation_4__power, modulation_4__stereo, modulation_50__amount, modulation_50__bipolar, modulation_50__bypass, modulation_50__power, modulation_50__stereo, modulation_51__amount, modulation_51__bipolar, modulation_51__bypass, modulation_51__power, modulation_51__stereo, modulation_52__amount, modulation_52__bipolar, modulation_52__bypass, modulation_52__power, modulation_52__stereo, modulation_53__amount, modulation_53__bipolar, modulation_53__bypass, modulation_53__power, modulation_53__stereo, modulation_54__amount, modulation_54__bipolar, modulation_54__bypass, modulation_54__power, modulation_54__stereo, modulation_55__amount, modulation_55__bipolar, modulation_55__bypass, modulation_55__power, modulation_55__stereo, modulation_56__amount, modulation_56__bipolar, modulation_56__bypass, modulation_56__power, modulation_56__stereo, modulation_57__amount, modulation_57__bipolar, modulation_57__bypass, modulation_57__power, modulation_57__stereo, modulation_58__amount, modulation_58__bipolar, modulation_58__bypass, modulation_58__power, modulation_58__stereo, modulation_59__amount, modulation_59__bipolar, modulation_59__bypass, modulation_59__power, modulation_59__stereo, modulation_5__amount, modulation_5__bipolar, modulation_5__bypass, modulation_5__power, modulation_5__stereo, modulation_60__amount, modulation_60__bipolar, modulation_60__bypass, modulation_60__power, modulation_60__stereo, modulation_61__amount, modulation_61__bipolar, modulation_61__bypass, modulation_61__power, modulation_61__stereo, modulation_62__amount, modulation_62__bipolar, modulation_62__bypass, modulation_62__power, modulation_62__stereo, modulation_63__amount, modulation_63__bipolar, modulation_63__bypass, modulation_63__power, modulation_63__stereo, modulation_64__amount, modulation_64__bipolar, modulation_64__bypass, modulation_64__power, modulation_64__stereo, modulation_6__amount, modulation_6__bipolar, modulation_6__bypass, modulation_6__power, modulation_6__stereo, modulation_7__amount, modulation_7__bipolar, modulation_7__bypass, modulation_7__power, modulation_7__stereo, modulation_8__amount, modulation_8__bipolar, modulation_8__bypass, modulation_8__power, modulation_8__stereo, modulation_9__amount, modulation_9__bipolar, modulation_9__bypass, modulation_9__power, modulation_9__stereo, modulations, osc_1__destination, osc_1__detune_power, osc_1__detune_range, osc_1__distortion_amount, osc_1__distortion_phase, osc_1__distortion_spread, osc_1__distortion_type, osc_1__frame_spread, osc_1__level, osc_1__midi_track, osc_1__on, osc_1__pan, osc_1__phase, osc_1__random_phase, osc_1__smooth_interpolation, osc_1__spectral_morph_amount, osc_1__spectral_morph_spread, osc_1__spectral_morph_type, osc_1__spectral_unison, osc_1__stack_style, osc_1__stereo_spread, osc_1__transpose, osc_1__transpose_quantize, osc_1__tune, osc_1__unison_blend, osc_1__unison_detune, osc_1__unison_voices, osc_1__view_2_d, osc_1__wave_frame, osc_2__destination, osc_2__detune_power, osc_2__detune_range, osc_2__distortion_amount, osc_2__distortion_phase, osc_2__distortion_spread, osc_2__distortion_type, osc_2__frame_spread, osc_2__level, osc_2__midi_track, osc_2__on, osc_2__pan, osc_2__phase, osc_2__random_phase, osc_2__smooth_interpolation, osc_2__spectral_morph_amount, osc_2__spectral_morph_spread, osc_2__spectral_morph_type, osc_2__spectral_unison, osc_2__stack_style, osc_2__stereo_spread, osc_2__transpose, osc_2__transpose_quantize, osc_2__tune, osc_2__unison_blend, osc_2__unison_detune, osc_2__unison_voices, osc_2__view_2_d, osc_2__wave_frame, osc_3__destination, osc_3__detune_power, osc_3__detune_range, osc_3__distortion_amount, osc_3__distortion_phase, osc_3__distortion_spread, osc_3__distortion_type, osc_3__frame_spread, osc_3__level, osc_3__midi_track, osc_3__on, osc_3__pan, osc_3__phase, osc_3__random_phase, osc_3__smooth_interpolation, osc_3__spectral_morph_amount, osc_3__spectral_morph_spread, osc_3__spectral_morph_type, osc_3__spectral_unison, osc_3__stack_style, osc_3__stereo_spread, osc_3__transpose, osc_3__transpose_quantize, osc_3__tune, osc_3__unison_blend, osc_3__unison_detune, osc_3__unison_voices, osc_3__view_2_d, osc_3__wave_frame, oversampling, phaser_blend, phaser_center, phaser_dry_wet, phaser_feedback, phaser_frequency, phaser_mod_depth, phaser_on, phaser_phase_offset, phaser_sync, phaser_tempo, pitch_bend_range, pitch_wheel, polyphony, portamento_force, portamento_scale, portamento_slope, portamento_time, random_1__frequency, random_1__stereo, random_1__style, random_1__sync, random_1__sync_type, random_1__tempo, random_2__frequency, random_2__stereo, random_2__style, random_2__sync, random_2__sync_type, random_2__tempo, random_3__frequency, random_3__stereo, random_3__style, random_3__sync, random_3__sync_type, random_3__tempo, random_4__frequency, random_4__stereo, random_4__style, random_4__sync, random_4__sync_type, random_4__tempo, reverb_chorus_amount, reverb_chorus_frequency, reverb_decay_time, reverb_dry_wet, reverb_high_shelf_cutoff, reverb_high_shelf_gain, reverb_low_shelf_cutoff, reverb_low_shelf_gain, reverb_on, reverb_pre_high_cutoff, reverb_pre_low_cutoff, reverb_size, sample, sample_destination, sample_keytrack, sample_level, sample_loop, sample_on, sample_pan, sample_random_phase, sample_transpose, sample_transpose_quantize, sample_tune, stereo_routing, velocity_track, voice_amplitude, voice_priority, voice_tune, volume, wavetables, bypass, chorus_cutoff, chorus_damping, chorus_spread, compressor_mix, filter_1__formant_spread, filter_2__formant_spread, filter_fx_formant_spread, lfo_1__keytrack_transpose, lfo_1__keytrack_tune, lfo_1__smooth_mode, lfo_1__smooth_time, lfo_2__keytrack_transpose, lfo_2__keytrack_tune, lfo_2__smooth_mode, lfo_2__smooth_time, lfo_3__keytrack_transpose, lfo_3__keytrack_tune, lfo_3__smooth_mode, lfo_3__smooth_time, lfo_4__keytrack_transpose, lfo_4__keytrack_tune, lfo_4__smooth_mode, lfo_4__smooth_time, lfo_5__keytrack_transpose, lfo_5__keytrack_tune, lfo_5__smooth_mode, lfo_5__smooth_time, lfo_6__keytrack_transpose, lfo_6__keytrack_tune, lfo_6__smooth_mode, lfo_6__smooth_time, lfo_7__keytrack_transpose, lfo_7__keytrack_tune, lfo_7__smooth_mode, lfo_7__smooth_time, lfo_8__keytrack_transpose, lfo_8__keytrack_tune, lfo_8__smooth_mode, lfo_8__smooth_time, random_1__keytrack_transpose, random_1__keytrack_tune, random_2__keytrack_transpose, random_2__keytrack_tune, random_3__keytrack_transpose, random_3__keytrack_tune, random_4__keytrack_transpose, random_4__keytrack_tune, reverb_delay, sample_bounce, stereo_mode, view_spectrogram, voice_override, voice_transpose)

    def to_dict(self) -> dict:
        result: dict = {}
        result["beats_per_minute"] = to_float(self.beats_per_minute)
        result["chorus_delay_1"] = to_float(self.chorus_delay_1)
        result["chorus_delay_2"] = to_float(self.chorus_delay_2)
        result["chorus_dry_wet"] = to_float(self.chorus_dry_wet)
        result["chorus_feedback"] = to_float(self.chorus_feedback)
        result["chorus_frequency"] = to_float(self.chorus_frequency)
        result["chorus_mod_depth"] = to_float(self.chorus_mod_depth)
        result["chorus_on"] = to_float(self.chorus_on)
        result["chorus_sync"] = to_float(self.chorus_sync)
        result["chorus_tempo"] = to_float(self.chorus_tempo)
        result["chorus_voices"] = to_float(self.chorus_voices)
        result["compressor_attack"] = to_float(self.compressor_attack)
        result["compressor_band_gain"] = to_float(self.compressor_band_gain)
        result["compressor_band_lower_ratio"] = to_float(self.compressor_band_lower_ratio)
        result["compressor_band_lower_threshold"] = to_float(self.compressor_band_lower_threshold)
        result["compressor_band_upper_ratio"] = to_float(self.compressor_band_upper_ratio)
        result["compressor_band_upper_threshold"] = to_float(self.compressor_band_upper_threshold)
        result["compressor_enabled_bands"] = to_float(self.compressor_enabled_bands)
        result["compressor_high_gain"] = to_float(self.compressor_high_gain)
        result["compressor_high_lower_ratio"] = to_float(self.compressor_high_lower_ratio)
        result["compressor_high_lower_threshold"] = to_float(self.compressor_high_lower_threshold)
        result["compressor_high_upper_ratio"] = to_float(self.compressor_high_upper_ratio)
        result["compressor_high_upper_threshold"] = to_float(self.compressor_high_upper_threshold)
        result["compressor_low_gain"] = to_float(self.compressor_low_gain)
        result["compressor_low_lower_ratio"] = to_float(self.compressor_low_lower_ratio)
        result["compressor_low_lower_threshold"] = to_float(self.compressor_low_lower_threshold)
        result["compressor_low_upper_ratio"] = to_float(self.compressor_low_upper_ratio)
        result["compressor_low_upper_threshold"] = to_float(self.compressor_low_upper_threshold)
        result["compressor_on"] = to_float(self.compressor_on)
        result["compressor_release"] = to_float(self.compressor_release)
        result["delay_aux_frequency"] = to_float(self.delay_aux_frequency)
        result["delay_aux_sync"] = to_float(self.delay_aux_sync)
        result["delay_aux_tempo"] = to_float(self.delay_aux_tempo)
        result["delay_dry_wet"] = to_float(self.delay_dry_wet)
        result["delay_feedback"] = to_float(self.delay_feedback)
        result["delay_filter_cutoff"] = to_float(self.delay_filter_cutoff)
        result["delay_filter_spread"] = to_float(self.delay_filter_spread)
        result["delay_frequency"] = to_float(self.delay_frequency)
        result["delay_on"] = to_float(self.delay_on)
        result["delay_style"] = to_float(self.delay_style)
        result["delay_sync"] = to_float(self.delay_sync)
        result["delay_tempo"] = to_float(self.delay_tempo)
        result["distortion_drive"] = to_float(self.distortion_drive)
        result["distortion_filter_blend"] = to_float(self.distortion_filter_blend)
        result["distortion_filter_cutoff"] = to_float(self.distortion_filter_cutoff)
        result["distortion_filter_order"] = to_float(self.distortion_filter_order)
        result["distortion_filter_resonance"] = to_float(self.distortion_filter_resonance)
        result["distortion_mix"] = to_float(self.distortion_mix)
        result["distortion_on"] = to_float(self.distortion_on)
        result["distortion_type"] = to_float(self.distortion_type)
        result["effect_chain_order"] = to_float(self.effect_chain_order)
        result["env_1_attack"] = to_float(self.env_1__attack)
        result["env_1_attack_power"] = to_float(self.env_1__attack_power)
        result["env_1_decay"] = to_float(self.env_1__decay)
        result["env_1_decay_power"] = to_float(self.env_1__decay_power)
        result["env_1_delay"] = to_float(self.env_1__delay)
        result["env_1_hold"] = to_float(self.env_1__hold)
        result["env_1_release"] = to_float(self.env_1__release)
        result["env_1_release_power"] = to_float(self.env_1__release_power)
        result["env_1_sustain"] = to_float(self.env_1__sustain)
        result["env_2_attack"] = to_float(self.env_2__attack)
        result["env_2_attack_power"] = to_float(self.env_2__attack_power)
        result["env_2_decay"] = to_float(self.env_2__decay)
        result["env_2_decay_power"] = to_float(self.env_2__decay_power)
        result["env_2_delay"] = to_float(self.env_2__delay)
        result["env_2_hold"] = to_float(self.env_2__hold)
        result["env_2_release"] = to_float(self.env_2__release)
        result["env_2_release_power"] = to_float(self.env_2__release_power)
        result["env_2_sustain"] = to_float(self.env_2__sustain)
        result["env_3_attack"] = to_float(self.env_3__attack)
        result["env_3_attack_power"] = to_float(self.env_3__attack_power)
        result["env_3_decay"] = to_float(self.env_3__decay)
        result["env_3_decay_power"] = to_float(self.env_3__decay_power)
        result["env_3_delay"] = to_float(self.env_3__delay)
        result["env_3_hold"] = to_float(self.env_3__hold)
        result["env_3_release"] = to_float(self.env_3__release)
        result["env_3_release_power"] = to_float(self.env_3__release_power)
        result["env_3_sustain"] = to_float(self.env_3__sustain)
        result["env_4_attack"] = to_float(self.env_4__attack)
        result["env_4_attack_power"] = to_float(self.env_4__attack_power)
        result["env_4_decay"] = to_float(self.env_4__decay)
        result["env_4_decay_power"] = to_float(self.env_4__decay_power)
        result["env_4_delay"] = to_float(self.env_4__delay)
        result["env_4_hold"] = to_float(self.env_4__hold)
        result["env_4_release"] = to_float(self.env_4__release)
        result["env_4_release_power"] = to_float(self.env_4__release_power)
        result["env_4_sustain"] = to_float(self.env_4__sustain)
        result["env_5_attack"] = to_float(self.env_5__attack)
        result["env_5_attack_power"] = to_float(self.env_5__attack_power)
        result["env_5_decay"] = to_float(self.env_5__decay)
        result["env_5_decay_power"] = to_float(self.env_5__decay_power)
        result["env_5_delay"] = to_float(self.env_5__delay)
        result["env_5_hold"] = to_float(self.env_5__hold)
        result["env_5_release"] = to_float(self.env_5__release)
        result["env_5_release_power"] = to_float(self.env_5__release_power)
        result["env_5_sustain"] = to_float(self.env_5__sustain)
        result["env_6_attack"] = to_float(self.env_6__attack)
        result["env_6_attack_power"] = to_float(self.env_6__attack_power)
        result["env_6_decay"] = to_float(self.env_6__decay)
        result["env_6_decay_power"] = to_float(self.env_6__decay_power)
        result["env_6_delay"] = to_float(self.env_6__delay)
        result["env_6_hold"] = to_float(self.env_6__hold)
        result["env_6_release"] = to_float(self.env_6__release)
        result["env_6_release_power"] = to_float(self.env_6__release_power)
        result["env_6_sustain"] = to_float(self.env_6__sustain)
        result["eq_band_cutoff"] = to_float(self.eq_band_cutoff)
        result["eq_band_gain"] = to_float(self.eq_band_gain)
        result["eq_band_mode"] = to_float(self.eq_band_mode)
        result["eq_band_resonance"] = to_float(self.eq_band_resonance)
        result["eq_high_cutoff"] = to_float(self.eq_high_cutoff)
        result["eq_high_gain"] = to_float(self.eq_high_gain)
        result["eq_high_mode"] = to_float(self.eq_high_mode)
        result["eq_high_resonance"] = to_float(self.eq_high_resonance)
        result["eq_low_cutoff"] = to_float(self.eq_low_cutoff)
        result["eq_low_gain"] = to_float(self.eq_low_gain)
        result["eq_low_mode"] = to_float(self.eq_low_mode)
        result["eq_low_resonance"] = to_float(self.eq_low_resonance)
        result["eq_on"] = to_float(self.eq_on)
        result["filter_1_blend"] = to_float(self.filter_1__blend)
        result["filter_1_blend_transpose"] = to_float(self.filter_1__blend_transpose)
        result["filter_1_cutoff"] = to_float(self.filter_1__cutoff)
        result["filter_1_drive"] = to_float(self.filter_1__drive)
        result["filter_1_filter_input"] = to_float(self.filter_1__filter_input)
        result["filter_1_formant_resonance"] = to_float(self.filter_1__formant_resonance)
        result["filter_1_formant_transpose"] = to_float(self.filter_1__formant_transpose)
        result["filter_1_formant_x"] = to_float(self.filter_1__formant_x)
        result["filter_1_formant_y"] = to_float(self.filter_1__formant_y)
        result["filter_1_keytrack"] = to_float(self.filter_1__keytrack)
        result["filter_1_mix"] = to_float(self.filter_1__mix)
        result["filter_1_model"] = to_float(self.filter_1__model)
        result["filter_1_on"] = to_float(self.filter_1__on)
        result["filter_1_resonance"] = to_float(self.filter_1__resonance)
        result["filter_1_style"] = to_float(self.filter_1__style)
        result["filter_2_blend"] = to_float(self.filter_2__blend)
        result["filter_2_blend_transpose"] = to_float(self.filter_2__blend_transpose)
        result["filter_2_cutoff"] = to_float(self.filter_2__cutoff)
        result["filter_2_drive"] = to_float(self.filter_2__drive)
        result["filter_2_filter_input"] = to_float(self.filter_2__filter_input)
        result["filter_2_formant_resonance"] = to_float(self.filter_2__formant_resonance)
        result["filter_2_formant_transpose"] = to_float(self.filter_2__formant_transpose)
        result["filter_2_formant_x"] = to_float(self.filter_2__formant_x)
        result["filter_2_formant_y"] = to_float(self.filter_2__formant_y)
        result["filter_2_keytrack"] = to_float(self.filter_2__keytrack)
        result["filter_2_mix"] = to_float(self.filter_2__mix)
        result["filter_2_model"] = to_float(self.filter_2__model)
        result["filter_2_on"] = to_float(self.filter_2__on)
        result["filter_2_resonance"] = to_float(self.filter_2__resonance)
        result["filter_2_style"] = to_float(self.filter_2__style)
        result["filter_fx_blend"] = to_float(self.filter_fx_blend)
        result["filter_fx_blend_transpose"] = to_float(self.filter_fx_blend_transpose)
        result["filter_fx_cutoff"] = to_float(self.filter_fx_cutoff)
        result["filter_fx_drive"] = to_float(self.filter_fx_drive)
        result["filter_fx_formant_resonance"] = to_float(self.filter_fx_formant_resonance)
        result["filter_fx_formant_transpose"] = to_float(self.filter_fx_formant_transpose)
        result["filter_fx_formant_x"] = to_float(self.filter_fx_formant_x)
        result["filter_fx_formant_y"] = to_float(self.filter_fx_formant_y)
        result["filter_fx_keytrack"] = to_float(self.filter_fx_keytrack)
        result["filter_fx_mix"] = to_float(self.filter_fx_mix)
        result["filter_fx_model"] = to_float(self.filter_fx_model)
        result["filter_fx_on"] = to_float(self.filter_fx_on)
        result["filter_fx_resonance"] = to_float(self.filter_fx_resonance)
        result["filter_fx_style"] = to_float(self.filter_fx_style)
        result["flanger_center"] = to_float(self.flanger_center)
        result["flanger_dry_wet"] = to_float(self.flanger_dry_wet)
        result["flanger_feedback"] = to_float(self.flanger_feedback)
        result["flanger_frequency"] = to_float(self.flanger_frequency)
        result["flanger_mod_depth"] = to_float(self.flanger_mod_depth)
        result["flanger_on"] = to_float(self.flanger_on)
        result["flanger_phase_offset"] = to_float(self.flanger_phase_offset)
        result["flanger_sync"] = to_float(self.flanger_sync)
        result["flanger_tempo"] = to_float(self.flanger_tempo)
        result["legato"] = to_float(self.legato)
        result["lfo_1_delay_time"] = to_float(self.lfo_1__delay_time)
        result["lfo_1_fade_time"] = to_float(self.lfo_1__fade_time)
        result["lfo_1_frequency"] = to_float(self.lfo_1__frequency)
        result["lfo_1_phase"] = to_float(self.lfo_1__phase)
        result["lfo_1_stereo"] = to_float(self.lfo_1__stereo)
        result["lfo_1_sync"] = to_float(self.lfo_1__sync)
        result["lfo_1_sync_type"] = to_float(self.lfo_1__sync_type)
        result["lfo_1_tempo"] = to_float(self.lfo_1__tempo)
        result["lfo_2_delay_time"] = to_float(self.lfo_2__delay_time)
        result["lfo_2_fade_time"] = to_float(self.lfo_2__fade_time)
        result["lfo_2_frequency"] = to_float(self.lfo_2__frequency)
        result["lfo_2_phase"] = to_float(self.lfo_2__phase)
        result["lfo_2_stereo"] = to_float(self.lfo_2__stereo)
        result["lfo_2_sync"] = to_float(self.lfo_2__sync)
        result["lfo_2_sync_type"] = to_float(self.lfo_2__sync_type)
        result["lfo_2_tempo"] = to_float(self.lfo_2__tempo)
        result["lfo_3_delay_time"] = to_float(self.lfo_3__delay_time)
        result["lfo_3_fade_time"] = to_float(self.lfo_3__fade_time)
        result["lfo_3_frequency"] = to_float(self.lfo_3__frequency)
        result["lfo_3_phase"] = to_float(self.lfo_3__phase)
        result["lfo_3_stereo"] = to_float(self.lfo_3__stereo)
        result["lfo_3_sync"] = to_float(self.lfo_3__sync)
        result["lfo_3_sync_type"] = to_float(self.lfo_3__sync_type)
        result["lfo_3_tempo"] = to_float(self.lfo_3__tempo)
        result["lfo_4_delay_time"] = to_float(self.lfo_4__delay_time)
        result["lfo_4_fade_time"] = to_float(self.lfo_4__fade_time)
        result["lfo_4_frequency"] = to_float(self.lfo_4__frequency)
        result["lfo_4_phase"] = to_float(self.lfo_4__phase)
        result["lfo_4_stereo"] = to_float(self.lfo_4__stereo)
        result["lfo_4_sync"] = to_float(self.lfo_4__sync)
        result["lfo_4_sync_type"] = to_float(self.lfo_4__sync_type)
        result["lfo_4_tempo"] = to_float(self.lfo_4__tempo)
        result["lfo_5_delay_time"] = to_float(self.lfo_5__delay_time)
        result["lfo_5_fade_time"] = to_float(self.lfo_5__fade_time)
        result["lfo_5_frequency"] = to_float(self.lfo_5__frequency)
        result["lfo_5_phase"] = to_float(self.lfo_5__phase)
        result["lfo_5_stereo"] = to_float(self.lfo_5__stereo)
        result["lfo_5_sync"] = to_float(self.lfo_5__sync)
        result["lfo_5_sync_type"] = to_float(self.lfo_5__sync_type)
        result["lfo_5_tempo"] = to_float(self.lfo_5__tempo)
        result["lfo_6_delay_time"] = to_float(self.lfo_6__delay_time)
        result["lfo_6_fade_time"] = to_float(self.lfo_6__fade_time)
        result["lfo_6_frequency"] = to_float(self.lfo_6__frequency)
        result["lfo_6_phase"] = to_float(self.lfo_6__phase)
        result["lfo_6_stereo"] = to_float(self.lfo_6__stereo)
        result["lfo_6_sync"] = to_float(self.lfo_6__sync)
        result["lfo_6_sync_type"] = to_float(self.lfo_6__sync_type)
        result["lfo_6_tempo"] = to_float(self.lfo_6__tempo)
        result["lfo_7_delay_time"] = to_float(self.lfo_7__delay_time)
        result["lfo_7_fade_time"] = to_float(self.lfo_7__fade_time)
        result["lfo_7_frequency"] = to_float(self.lfo_7__frequency)
        result["lfo_7_phase"] = to_float(self.lfo_7__phase)
        result["lfo_7_stereo"] = to_float(self.lfo_7__stereo)
        result["lfo_7_sync"] = to_float(self.lfo_7__sync)
        result["lfo_7_sync_type"] = to_float(self.lfo_7__sync_type)
        result["lfo_7_tempo"] = to_float(self.lfo_7__tempo)
        result["lfo_8_delay_time"] = to_float(self.lfo_8__delay_time)
        result["lfo_8_fade_time"] = to_float(self.lfo_8__fade_time)
        result["lfo_8_frequency"] = to_float(self.lfo_8__frequency)
        result["lfo_8_phase"] = to_float(self.lfo_8__phase)
        result["lfo_8_stereo"] = to_float(self.lfo_8__stereo)
        result["lfo_8_sync"] = to_float(self.lfo_8__sync)
        result["lfo_8_sync_type"] = to_float(self.lfo_8__sync_type)
        result["lfo_8_tempo"] = to_float(self.lfo_8__tempo)
        result["lfos"] = from_list(lambda x: to_class(Lfo, x), self.lfos)
        result["macro_control_1"] = to_float(self.macro_control_1)
        result["macro_control_2"] = to_float(self.macro_control_2)
        result["macro_control_3"] = to_float(self.macro_control_3)
        result["macro_control_4"] = to_float(self.macro_control_4)
        result["mod_wheel"] = to_float(self.mod_wheel)
        result["modulation_10_amount"] = to_float(self.modulation_10__amount)
        result["modulation_10_bipolar"] = to_float(self.modulation_10__bipolar)
        result["modulation_10_bypass"] = to_float(self.modulation_10__bypass)
        result["modulation_10_power"] = to_float(self.modulation_10__power)
        result["modulation_10_stereo"] = to_float(self.modulation_10__stereo)
        result["modulation_11_amount"] = to_float(self.modulation_11__amount)
        result["modulation_11_bipolar"] = to_float(self.modulation_11__bipolar)
        result["modulation_11_bypass"] = to_float(self.modulation_11__bypass)
        result["modulation_11_power"] = to_float(self.modulation_11__power)
        result["modulation_11_stereo"] = to_float(self.modulation_11__stereo)
        result["modulation_12_amount"] = to_float(self.modulation_12__amount)
        result["modulation_12_bipolar"] = to_float(self.modulation_12__bipolar)
        result["modulation_12_bypass"] = to_float(self.modulation_12__bypass)
        result["modulation_12_power"] = to_float(self.modulation_12__power)
        result["modulation_12_stereo"] = to_float(self.modulation_12__stereo)
        result["modulation_13_amount"] = to_float(self.modulation_13__amount)
        result["modulation_13_bipolar"] = to_float(self.modulation_13__bipolar)
        result["modulation_13_bypass"] = to_float(self.modulation_13__bypass)
        result["modulation_13_power"] = to_float(self.modulation_13__power)
        result["modulation_13_stereo"] = to_float(self.modulation_13__stereo)
        result["modulation_14_amount"] = to_float(self.modulation_14__amount)
        result["modulation_14_bipolar"] = to_float(self.modulation_14__bipolar)
        result["modulation_14_bypass"] = to_float(self.modulation_14__bypass)
        result["modulation_14_power"] = to_float(self.modulation_14__power)
        result["modulation_14_stereo"] = to_float(self.modulation_14__stereo)
        result["modulation_15_amount"] = to_float(self.modulation_15__amount)
        result["modulation_15_bipolar"] = to_float(self.modulation_15__bipolar)
        result["modulation_15_bypass"] = to_float(self.modulation_15__bypass)
        result["modulation_15_power"] = to_float(self.modulation_15__power)
        result["modulation_15_stereo"] = to_float(self.modulation_15__stereo)
        result["modulation_16_amount"] = to_float(self.modulation_16__amount)
        result["modulation_16_bipolar"] = to_float(self.modulation_16__bipolar)
        result["modulation_16_bypass"] = to_float(self.modulation_16__bypass)
        result["modulation_16_power"] = to_float(self.modulation_16__power)
        result["modulation_16_stereo"] = to_float(self.modulation_16__stereo)
        result["modulation_17_amount"] = to_float(self.modulation_17__amount)
        result["modulation_17_bipolar"] = to_float(self.modulation_17__bipolar)
        result["modulation_17_bypass"] = to_float(self.modulation_17__bypass)
        result["modulation_17_power"] = to_float(self.modulation_17__power)
        result["modulation_17_stereo"] = to_float(self.modulation_17__stereo)
        result["modulation_18_amount"] = to_float(self.modulation_18__amount)
        result["modulation_18_bipolar"] = to_float(self.modulation_18__bipolar)
        result["modulation_18_bypass"] = to_float(self.modulation_18__bypass)
        result["modulation_18_power"] = to_float(self.modulation_18__power)
        result["modulation_18_stereo"] = to_float(self.modulation_18__stereo)
        result["modulation_19_amount"] = to_float(self.modulation_19__amount)
        result["modulation_19_bipolar"] = to_float(self.modulation_19__bipolar)
        result["modulation_19_bypass"] = to_float(self.modulation_19__bypass)
        result["modulation_19_power"] = to_float(self.modulation_19__power)
        result["modulation_19_stereo"] = to_float(self.modulation_19__stereo)
        result["modulation_1_amount"] = to_float(self.modulation_1__amount)
        result["modulation_1_bipolar"] = to_float(self.modulation_1__bipolar)
        result["modulation_1_bypass"] = to_float(self.modulation_1__bypass)
        result["modulation_1_power"] = to_float(self.modulation_1__power)
        result["modulation_1_stereo"] = to_float(self.modulation_1__stereo)
        result["modulation_20_amount"] = to_float(self.modulation_20__amount)
        result["modulation_20_bipolar"] = to_float(self.modulation_20__bipolar)
        result["modulation_20_bypass"] = to_float(self.modulation_20__bypass)
        result["modulation_20_power"] = to_float(self.modulation_20__power)
        result["modulation_20_stereo"] = to_float(self.modulation_20__stereo)
        result["modulation_21_amount"] = to_float(self.modulation_21__amount)
        result["modulation_21_bipolar"] = to_float(self.modulation_21__bipolar)
        result["modulation_21_bypass"] = to_float(self.modulation_21__bypass)
        result["modulation_21_power"] = to_float(self.modulation_21__power)
        result["modulation_21_stereo"] = to_float(self.modulation_21__stereo)
        result["modulation_22_amount"] = to_float(self.modulation_22__amount)
        result["modulation_22_bipolar"] = to_float(self.modulation_22__bipolar)
        result["modulation_22_bypass"] = to_float(self.modulation_22__bypass)
        result["modulation_22_power"] = to_float(self.modulation_22__power)
        result["modulation_22_stereo"] = to_float(self.modulation_22__stereo)
        result["modulation_23_amount"] = to_float(self.modulation_23__amount)
        result["modulation_23_bipolar"] = to_float(self.modulation_23__bipolar)
        result["modulation_23_bypass"] = to_float(self.modulation_23__bypass)
        result["modulation_23_power"] = to_float(self.modulation_23__power)
        result["modulation_23_stereo"] = to_float(self.modulation_23__stereo)
        result["modulation_24_amount"] = to_float(self.modulation_24__amount)
        result["modulation_24_bipolar"] = to_float(self.modulation_24__bipolar)
        result["modulation_24_bypass"] = to_float(self.modulation_24__bypass)
        result["modulation_24_power"] = to_float(self.modulation_24__power)
        result["modulation_24_stereo"] = to_float(self.modulation_24__stereo)
        result["modulation_25_amount"] = to_float(self.modulation_25__amount)
        result["modulation_25_bipolar"] = to_float(self.modulation_25__bipolar)
        result["modulation_25_bypass"] = to_float(self.modulation_25__bypass)
        result["modulation_25_power"] = to_float(self.modulation_25__power)
        result["modulation_25_stereo"] = to_float(self.modulation_25__stereo)
        result["modulation_26_amount"] = to_float(self.modulation_26__amount)
        result["modulation_26_bipolar"] = to_float(self.modulation_26__bipolar)
        result["modulation_26_bypass"] = to_float(self.modulation_26__bypass)
        result["modulation_26_power"] = to_float(self.modulation_26__power)
        result["modulation_26_stereo"] = to_float(self.modulation_26__stereo)
        result["modulation_27_amount"] = to_float(self.modulation_27__amount)
        result["modulation_27_bipolar"] = to_float(self.modulation_27__bipolar)
        result["modulation_27_bypass"] = to_float(self.modulation_27__bypass)
        result["modulation_27_power"] = to_float(self.modulation_27__power)
        result["modulation_27_stereo"] = to_float(self.modulation_27__stereo)
        result["modulation_28_amount"] = to_float(self.modulation_28__amount)
        result["modulation_28_bipolar"] = to_float(self.modulation_28__bipolar)
        result["modulation_28_bypass"] = to_float(self.modulation_28__bypass)
        result["modulation_28_power"] = to_float(self.modulation_28__power)
        result["modulation_28_stereo"] = to_float(self.modulation_28__stereo)
        result["modulation_29_amount"] = to_float(self.modulation_29__amount)
        result["modulation_29_bipolar"] = to_float(self.modulation_29__bipolar)
        result["modulation_29_bypass"] = to_float(self.modulation_29__bypass)
        result["modulation_29_power"] = to_float(self.modulation_29__power)
        result["modulation_29_stereo"] = to_float(self.modulation_29__stereo)
        result["modulation_2_amount"] = to_float(self.modulation_2__amount)
        result["modulation_2_bipolar"] = to_float(self.modulation_2__bipolar)
        result["modulation_2_bypass"] = to_float(self.modulation_2__bypass)
        result["modulation_2_power"] = to_float(self.modulation_2__power)
        result["modulation_2_stereo"] = to_float(self.modulation_2__stereo)
        result["modulation_30_amount"] = to_float(self.modulation_30__amount)
        result["modulation_30_bipolar"] = to_float(self.modulation_30__bipolar)
        result["modulation_30_bypass"] = to_float(self.modulation_30__bypass)
        result["modulation_30_power"] = to_float(self.modulation_30__power)
        result["modulation_30_stereo"] = to_float(self.modulation_30__stereo)
        result["modulation_31_amount"] = to_float(self.modulation_31__amount)
        result["modulation_31_bipolar"] = to_float(self.modulation_31__bipolar)
        result["modulation_31_bypass"] = to_float(self.modulation_31__bypass)
        result["modulation_31_power"] = to_float(self.modulation_31__power)
        result["modulation_31_stereo"] = to_float(self.modulation_31__stereo)
        result["modulation_32_amount"] = to_float(self.modulation_32__amount)
        result["modulation_32_bipolar"] = to_float(self.modulation_32__bipolar)
        result["modulation_32_bypass"] = to_float(self.modulation_32__bypass)
        result["modulation_32_power"] = to_float(self.modulation_32__power)
        result["modulation_32_stereo"] = to_float(self.modulation_32__stereo)
        result["modulation_33_amount"] = to_float(self.modulation_33__amount)
        result["modulation_33_bipolar"] = to_float(self.modulation_33__bipolar)
        result["modulation_33_bypass"] = to_float(self.modulation_33__bypass)
        result["modulation_33_power"] = to_float(self.modulation_33__power)
        result["modulation_33_stereo"] = to_float(self.modulation_33__stereo)
        result["modulation_34_amount"] = to_float(self.modulation_34__amount)
        result["modulation_34_bipolar"] = to_float(self.modulation_34__bipolar)
        result["modulation_34_bypass"] = to_float(self.modulation_34__bypass)
        result["modulation_34_power"] = to_float(self.modulation_34__power)
        result["modulation_34_stereo"] = to_float(self.modulation_34__stereo)
        result["modulation_35_amount"] = to_float(self.modulation_35__amount)
        result["modulation_35_bipolar"] = to_float(self.modulation_35__bipolar)
        result["modulation_35_bypass"] = to_float(self.modulation_35__bypass)
        result["modulation_35_power"] = to_float(self.modulation_35__power)
        result["modulation_35_stereo"] = to_float(self.modulation_35__stereo)
        result["modulation_36_amount"] = to_float(self.modulation_36__amount)
        result["modulation_36_bipolar"] = to_float(self.modulation_36__bipolar)
        result["modulation_36_bypass"] = to_float(self.modulation_36__bypass)
        result["modulation_36_power"] = to_float(self.modulation_36__power)
        result["modulation_36_stereo"] = to_float(self.modulation_36__stereo)
        result["modulation_37_amount"] = to_float(self.modulation_37__amount)
        result["modulation_37_bipolar"] = to_float(self.modulation_37__bipolar)
        result["modulation_37_bypass"] = to_float(self.modulation_37__bypass)
        result["modulation_37_power"] = to_float(self.modulation_37__power)
        result["modulation_37_stereo"] = to_float(self.modulation_37__stereo)
        result["modulation_38_amount"] = to_float(self.modulation_38__amount)
        result["modulation_38_bipolar"] = to_float(self.modulation_38__bipolar)
        result["modulation_38_bypass"] = to_float(self.modulation_38__bypass)
        result["modulation_38_power"] = to_float(self.modulation_38__power)
        result["modulation_38_stereo"] = to_float(self.modulation_38__stereo)
        result["modulation_39_amount"] = to_float(self.modulation_39__amount)
        result["modulation_39_bipolar"] = to_float(self.modulation_39__bipolar)
        result["modulation_39_bypass"] = to_float(self.modulation_39__bypass)
        result["modulation_39_power"] = to_float(self.modulation_39__power)
        result["modulation_39_stereo"] = to_float(self.modulation_39__stereo)
        result["modulation_3_amount"] = to_float(self.modulation_3__amount)
        result["modulation_3_bipolar"] = to_float(self.modulation_3__bipolar)
        result["modulation_3_bypass"] = to_float(self.modulation_3__bypass)
        result["modulation_3_power"] = to_float(self.modulation_3__power)
        result["modulation_3_stereo"] = to_float(self.modulation_3__stereo)
        result["modulation_40_amount"] = to_float(self.modulation_40__amount)
        result["modulation_40_bipolar"] = to_float(self.modulation_40__bipolar)
        result["modulation_40_bypass"] = to_float(self.modulation_40__bypass)
        result["modulation_40_power"] = to_float(self.modulation_40__power)
        result["modulation_40_stereo"] = to_float(self.modulation_40__stereo)
        result["modulation_41_amount"] = to_float(self.modulation_41__amount)
        result["modulation_41_bipolar"] = to_float(self.modulation_41__bipolar)
        result["modulation_41_bypass"] = to_float(self.modulation_41__bypass)
        result["modulation_41_power"] = to_float(self.modulation_41__power)
        result["modulation_41_stereo"] = to_float(self.modulation_41__stereo)
        result["modulation_42_amount"] = to_float(self.modulation_42__amount)
        result["modulation_42_bipolar"] = to_float(self.modulation_42__bipolar)
        result["modulation_42_bypass"] = to_float(self.modulation_42__bypass)
        result["modulation_42_power"] = to_float(self.modulation_42__power)
        result["modulation_42_stereo"] = to_float(self.modulation_42__stereo)
        result["modulation_43_amount"] = to_float(self.modulation_43__amount)
        result["modulation_43_bipolar"] = to_float(self.modulation_43__bipolar)
        result["modulation_43_bypass"] = to_float(self.modulation_43__bypass)
        result["modulation_43_power"] = to_float(self.modulation_43__power)
        result["modulation_43_stereo"] = to_float(self.modulation_43__stereo)
        result["modulation_44_amount"] = to_float(self.modulation_44__amount)
        result["modulation_44_bipolar"] = to_float(self.modulation_44__bipolar)
        result["modulation_44_bypass"] = to_float(self.modulation_44__bypass)
        result["modulation_44_power"] = to_float(self.modulation_44__power)
        result["modulation_44_stereo"] = to_float(self.modulation_44__stereo)
        result["modulation_45_amount"] = to_float(self.modulation_45__amount)
        result["modulation_45_bipolar"] = to_float(self.modulation_45__bipolar)
        result["modulation_45_bypass"] = to_float(self.modulation_45__bypass)
        result["modulation_45_power"] = to_float(self.modulation_45__power)
        result["modulation_45_stereo"] = to_float(self.modulation_45__stereo)
        result["modulation_46_amount"] = to_float(self.modulation_46__amount)
        result["modulation_46_bipolar"] = to_float(self.modulation_46__bipolar)
        result["modulation_46_bypass"] = to_float(self.modulation_46__bypass)
        result["modulation_46_power"] = to_float(self.modulation_46__power)
        result["modulation_46_stereo"] = to_float(self.modulation_46__stereo)
        result["modulation_47_amount"] = to_float(self.modulation_47__amount)
        result["modulation_47_bipolar"] = to_float(self.modulation_47__bipolar)
        result["modulation_47_bypass"] = to_float(self.modulation_47__bypass)
        result["modulation_47_power"] = to_float(self.modulation_47__power)
        result["modulation_47_stereo"] = to_float(self.modulation_47__stereo)
        result["modulation_48_amount"] = to_float(self.modulation_48__amount)
        result["modulation_48_bipolar"] = to_float(self.modulation_48__bipolar)
        result["modulation_48_bypass"] = to_float(self.modulation_48__bypass)
        result["modulation_48_power"] = to_float(self.modulation_48__power)
        result["modulation_48_stereo"] = to_float(self.modulation_48__stereo)
        result["modulation_49_amount"] = to_float(self.modulation_49__amount)
        result["modulation_49_bipolar"] = to_float(self.modulation_49__bipolar)
        result["modulation_49_bypass"] = to_float(self.modulation_49__bypass)
        result["modulation_49_power"] = to_float(self.modulation_49__power)
        result["modulation_49_stereo"] = to_float(self.modulation_49__stereo)
        result["modulation_4_amount"] = to_float(self.modulation_4__amount)
        result["modulation_4_bipolar"] = to_float(self.modulation_4__bipolar)
        result["modulation_4_bypass"] = to_float(self.modulation_4__bypass)
        result["modulation_4_power"] = to_float(self.modulation_4__power)
        result["modulation_4_stereo"] = to_float(self.modulation_4__stereo)
        result["modulation_50_amount"] = to_float(self.modulation_50__amount)
        result["modulation_50_bipolar"] = to_float(self.modulation_50__bipolar)
        result["modulation_50_bypass"] = to_float(self.modulation_50__bypass)
        result["modulation_50_power"] = to_float(self.modulation_50__power)
        result["modulation_50_stereo"] = to_float(self.modulation_50__stereo)
        result["modulation_51_amount"] = to_float(self.modulation_51__amount)
        result["modulation_51_bipolar"] = to_float(self.modulation_51__bipolar)
        result["modulation_51_bypass"] = to_float(self.modulation_51__bypass)
        result["modulation_51_power"] = to_float(self.modulation_51__power)
        result["modulation_51_stereo"] = to_float(self.modulation_51__stereo)
        result["modulation_52_amount"] = to_float(self.modulation_52__amount)
        result["modulation_52_bipolar"] = to_float(self.modulation_52__bipolar)
        result["modulation_52_bypass"] = to_float(self.modulation_52__bypass)
        result["modulation_52_power"] = to_float(self.modulation_52__power)
        result["modulation_52_stereo"] = to_float(self.modulation_52__stereo)
        result["modulation_53_amount"] = to_float(self.modulation_53__amount)
        result["modulation_53_bipolar"] = to_float(self.modulation_53__bipolar)
        result["modulation_53_bypass"] = to_float(self.modulation_53__bypass)
        result["modulation_53_power"] = to_float(self.modulation_53__power)
        result["modulation_53_stereo"] = to_float(self.modulation_53__stereo)
        result["modulation_54_amount"] = to_float(self.modulation_54__amount)
        result["modulation_54_bipolar"] = to_float(self.modulation_54__bipolar)
        result["modulation_54_bypass"] = to_float(self.modulation_54__bypass)
        result["modulation_54_power"] = to_float(self.modulation_54__power)
        result["modulation_54_stereo"] = to_float(self.modulation_54__stereo)
        result["modulation_55_amount"] = to_float(self.modulation_55__amount)
        result["modulation_55_bipolar"] = to_float(self.modulation_55__bipolar)
        result["modulation_55_bypass"] = to_float(self.modulation_55__bypass)
        result["modulation_55_power"] = to_float(self.modulation_55__power)
        result["modulation_55_stereo"] = to_float(self.modulation_55__stereo)
        result["modulation_56_amount"] = to_float(self.modulation_56__amount)
        result["modulation_56_bipolar"] = to_float(self.modulation_56__bipolar)
        result["modulation_56_bypass"] = to_float(self.modulation_56__bypass)
        result["modulation_56_power"] = to_float(self.modulation_56__power)
        result["modulation_56_stereo"] = to_float(self.modulation_56__stereo)
        result["modulation_57_amount"] = to_float(self.modulation_57__amount)
        result["modulation_57_bipolar"] = to_float(self.modulation_57__bipolar)
        result["modulation_57_bypass"] = to_float(self.modulation_57__bypass)
        result["modulation_57_power"] = to_float(self.modulation_57__power)
        result["modulation_57_stereo"] = to_float(self.modulation_57__stereo)
        result["modulation_58_amount"] = to_float(self.modulation_58__amount)
        result["modulation_58_bipolar"] = to_float(self.modulation_58__bipolar)
        result["modulation_58_bypass"] = to_float(self.modulation_58__bypass)
        result["modulation_58_power"] = to_float(self.modulation_58__power)
        result["modulation_58_stereo"] = to_float(self.modulation_58__stereo)
        result["modulation_59_amount"] = to_float(self.modulation_59__amount)
        result["modulation_59_bipolar"] = to_float(self.modulation_59__bipolar)
        result["modulation_59_bypass"] = to_float(self.modulation_59__bypass)
        result["modulation_59_power"] = to_float(self.modulation_59__power)
        result["modulation_59_stereo"] = to_float(self.modulation_59__stereo)
        result["modulation_5_amount"] = to_float(self.modulation_5__amount)
        result["modulation_5_bipolar"] = to_float(self.modulation_5__bipolar)
        result["modulation_5_bypass"] = to_float(self.modulation_5__bypass)
        result["modulation_5_power"] = to_float(self.modulation_5__power)
        result["modulation_5_stereo"] = to_float(self.modulation_5__stereo)
        result["modulation_60_amount"] = to_float(self.modulation_60__amount)
        result["modulation_60_bipolar"] = to_float(self.modulation_60__bipolar)
        result["modulation_60_bypass"] = to_float(self.modulation_60__bypass)
        result["modulation_60_power"] = to_float(self.modulation_60__power)
        result["modulation_60_stereo"] = to_float(self.modulation_60__stereo)
        result["modulation_61_amount"] = to_float(self.modulation_61__amount)
        result["modulation_61_bipolar"] = to_float(self.modulation_61__bipolar)
        result["modulation_61_bypass"] = to_float(self.modulation_61__bypass)
        result["modulation_61_power"] = to_float(self.modulation_61__power)
        result["modulation_61_stereo"] = to_float(self.modulation_61__stereo)
        result["modulation_62_amount"] = to_float(self.modulation_62__amount)
        result["modulation_62_bipolar"] = to_float(self.modulation_62__bipolar)
        result["modulation_62_bypass"] = to_float(self.modulation_62__bypass)
        result["modulation_62_power"] = to_float(self.modulation_62__power)
        result["modulation_62_stereo"] = to_float(self.modulation_62__stereo)
        result["modulation_63_amount"] = to_float(self.modulation_63__amount)
        result["modulation_63_bipolar"] = to_float(self.modulation_63__bipolar)
        result["modulation_63_bypass"] = to_float(self.modulation_63__bypass)
        result["modulation_63_power"] = to_float(self.modulation_63__power)
        result["modulation_63_stereo"] = to_float(self.modulation_63__stereo)
        result["modulation_64_amount"] = to_float(self.modulation_64__amount)
        result["modulation_64_bipolar"] = to_float(self.modulation_64__bipolar)
        result["modulation_64_bypass"] = to_float(self.modulation_64__bypass)
        result["modulation_64_power"] = to_float(self.modulation_64__power)
        result["modulation_64_stereo"] = to_float(self.modulation_64__stereo)
        result["modulation_6_amount"] = to_float(self.modulation_6__amount)
        result["modulation_6_bipolar"] = to_float(self.modulation_6__bipolar)
        result["modulation_6_bypass"] = to_float(self.modulation_6__bypass)
        result["modulation_6_power"] = to_float(self.modulation_6__power)
        result["modulation_6_stereo"] = to_float(self.modulation_6__stereo)
        result["modulation_7_amount"] = to_float(self.modulation_7__amount)
        result["modulation_7_bipolar"] = to_float(self.modulation_7__bipolar)
        result["modulation_7_bypass"] = to_float(self.modulation_7__bypass)
        result["modulation_7_power"] = to_float(self.modulation_7__power)
        result["modulation_7_stereo"] = to_float(self.modulation_7__stereo)
        result["modulation_8_amount"] = to_float(self.modulation_8__amount)
        result["modulation_8_bipolar"] = to_float(self.modulation_8__bipolar)
        result["modulation_8_bypass"] = to_float(self.modulation_8__bypass)
        result["modulation_8_power"] = to_float(self.modulation_8__power)
        result["modulation_8_stereo"] = to_float(self.modulation_8__stereo)
        result["modulation_9_amount"] = to_float(self.modulation_9__amount)
        result["modulation_9_bipolar"] = to_float(self.modulation_9__bipolar)
        result["modulation_9_bypass"] = to_float(self.modulation_9__bypass)
        result["modulation_9_power"] = to_float(self.modulation_9__power)
        result["modulation_9_stereo"] = to_float(self.modulation_9__stereo)
        result["modulations"] = from_list(lambda x: to_class(Modulation, x), self.modulations)
        result["osc_1_destination"] = to_float(self.osc_1__destination)
        result["osc_1_detune_power"] = to_float(self.osc_1__detune_power)
        result["osc_1_detune_range"] = to_float(self.osc_1__detune_range)
        result["osc_1_distortion_amount"] = to_float(self.osc_1__distortion_amount)
        result["osc_1_distortion_phase"] = to_float(self.osc_1__distortion_phase)
        result["osc_1_distortion_spread"] = to_float(self.osc_1__distortion_spread)
        result["osc_1_distortion_type"] = to_float(self.osc_1__distortion_type)
        result["osc_1_frame_spread"] = to_float(self.osc_1__frame_spread)
        result["osc_1_level"] = to_float(self.osc_1__level)
        result["osc_1_midi_track"] = to_float(self.osc_1__midi_track)
        result["osc_1_on"] = to_float(self.osc_1__on)
        result["osc_1_pan"] = to_float(self.osc_1__pan)
        result["osc_1_phase"] = to_float(self.osc_1__phase)
        result["osc_1_random_phase"] = to_float(self.osc_1__random_phase)
        result["osc_1_smooth_interpolation"] = to_float(self.osc_1__smooth_interpolation)
        result["osc_1_spectral_morph_amount"] = to_float(self.osc_1__spectral_morph_amount)
        result["osc_1_spectral_morph_spread"] = to_float(self.osc_1__spectral_morph_spread)
        result["osc_1_spectral_morph_type"] = to_float(self.osc_1__spectral_morph_type)
        result["osc_1_spectral_unison"] = to_float(self.osc_1__spectral_unison)
        result["osc_1_stack_style"] = to_float(self.osc_1__stack_style)
        result["osc_1_stereo_spread"] = to_float(self.osc_1__stereo_spread)
        result["osc_1_transpose"] = to_float(self.osc_1__transpose)
        result["osc_1_transpose_quantize"] = to_float(self.osc_1__transpose_quantize)
        result["osc_1_tune"] = to_float(self.osc_1__tune)
        result["osc_1_unison_blend"] = to_float(self.osc_1__unison_blend)
        result["osc_1_unison_detune"] = to_float(self.osc_1__unison_detune)
        result["osc_1_unison_voices"] = to_float(self.osc_1__unison_voices)
        result["osc_1_view_2d"] = to_float(self.osc_1__view_2_d)
        result["osc_1_wave_frame"] = to_float(self.osc_1__wave_frame)
        result["osc_2_destination"] = to_float(self.osc_2__destination)
        result["osc_2_detune_power"] = to_float(self.osc_2__detune_power)
        result["osc_2_detune_range"] = to_float(self.osc_2__detune_range)
        result["osc_2_distortion_amount"] = to_float(self.osc_2__distortion_amount)
        result["osc_2_distortion_phase"] = to_float(self.osc_2__distortion_phase)
        result["osc_2_distortion_spread"] = to_float(self.osc_2__distortion_spread)
        result["osc_2_distortion_type"] = to_float(self.osc_2__distortion_type)
        result["osc_2_frame_spread"] = to_float(self.osc_2__frame_spread)
        result["osc_2_level"] = to_float(self.osc_2__level)
        result["osc_2_midi_track"] = to_float(self.osc_2__midi_track)
        result["osc_2_on"] = to_float(self.osc_2__on)
        result["osc_2_pan"] = to_float(self.osc_2__pan)
        result["osc_2_phase"] = to_float(self.osc_2__phase)
        result["osc_2_random_phase"] = to_float(self.osc_2__random_phase)
        result["osc_2_smooth_interpolation"] = to_float(self.osc_2__smooth_interpolation)
        result["osc_2_spectral_morph_amount"] = to_float(self.osc_2__spectral_morph_amount)
        result["osc_2_spectral_morph_spread"] = to_float(self.osc_2__spectral_morph_spread)
        result["osc_2_spectral_morph_type"] = to_float(self.osc_2__spectral_morph_type)
        result["osc_2_spectral_unison"] = to_float(self.osc_2__spectral_unison)
        result["osc_2_stack_style"] = to_float(self.osc_2__stack_style)
        result["osc_2_stereo_spread"] = to_float(self.osc_2__stereo_spread)
        result["osc_2_transpose"] = to_float(self.osc_2__transpose)
        result["osc_2_transpose_quantize"] = to_float(self.osc_2__transpose_quantize)
        result["osc_2_tune"] = to_float(self.osc_2__tune)
        result["osc_2_unison_blend"] = to_float(self.osc_2__unison_blend)
        result["osc_2_unison_detune"] = to_float(self.osc_2__unison_detune)
        result["osc_2_unison_voices"] = to_float(self.osc_2__unison_voices)
        result["osc_2_view_2d"] = to_float(self.osc_2__view_2_d)
        result["osc_2_wave_frame"] = to_float(self.osc_2__wave_frame)
        result["osc_3_destination"] = to_float(self.osc_3__destination)
        result["osc_3_detune_power"] = to_float(self.osc_3__detune_power)
        result["osc_3_detune_range"] = to_float(self.osc_3__detune_range)
        result["osc_3_distortion_amount"] = to_float(self.osc_3__distortion_amount)
        result["osc_3_distortion_phase"] = to_float(self.osc_3__distortion_phase)
        result["osc_3_distortion_spread"] = to_float(self.osc_3__distortion_spread)
        result["osc_3_distortion_type"] = to_float(self.osc_3__distortion_type)
        result["osc_3_frame_spread"] = to_float(self.osc_3__frame_spread)
        result["osc_3_level"] = to_float(self.osc_3__level)
        result["osc_3_midi_track"] = to_float(self.osc_3__midi_track)
        result["osc_3_on"] = to_float(self.osc_3__on)
        result["osc_3_pan"] = to_float(self.osc_3__pan)
        result["osc_3_phase"] = to_float(self.osc_3__phase)
        result["osc_3_random_phase"] = to_float(self.osc_3__random_phase)
        result["osc_3_smooth_interpolation"] = to_float(self.osc_3__smooth_interpolation)
        result["osc_3_spectral_morph_amount"] = to_float(self.osc_3__spectral_morph_amount)
        result["osc_3_spectral_morph_spread"] = to_float(self.osc_3__spectral_morph_spread)
        result["osc_3_spectral_morph_type"] = to_float(self.osc_3__spectral_morph_type)
        result["osc_3_spectral_unison"] = to_float(self.osc_3__spectral_unison)
        result["osc_3_stack_style"] = to_float(self.osc_3__stack_style)
        result["osc_3_stereo_spread"] = to_float(self.osc_3__stereo_spread)
        result["osc_3_transpose"] = to_float(self.osc_3__transpose)
        result["osc_3_transpose_quantize"] = to_float(self.osc_3__transpose_quantize)
        result["osc_3_tune"] = to_float(self.osc_3__tune)
        result["osc_3_unison_blend"] = to_float(self.osc_3__unison_blend)
        result["osc_3_unison_detune"] = to_float(self.osc_3__unison_detune)
        result["osc_3_unison_voices"] = to_float(self.osc_3__unison_voices)
        result["osc_3_view_2d"] = to_float(self.osc_3__view_2_d)
        result["osc_3_wave_frame"] = to_float(self.osc_3__wave_frame)
        result["oversampling"] = to_float(self.oversampling)
        result["phaser_blend"] = to_float(self.phaser_blend)
        result["phaser_center"] = to_float(self.phaser_center)
        result["phaser_dry_wet"] = to_float(self.phaser_dry_wet)
        result["phaser_feedback"] = to_float(self.phaser_feedback)
        result["phaser_frequency"] = to_float(self.phaser_frequency)
        result["phaser_mod_depth"] = to_float(self.phaser_mod_depth)
        result["phaser_on"] = to_float(self.phaser_on)
        result["phaser_phase_offset"] = to_float(self.phaser_phase_offset)
        result["phaser_sync"] = to_float(self.phaser_sync)
        result["phaser_tempo"] = to_float(self.phaser_tempo)
        result["pitch_bend_range"] = to_float(self.pitch_bend_range)
        result["pitch_wheel"] = to_float(self.pitch_wheel)
        result["polyphony"] = to_float(self.polyphony)
        result["portamento_force"] = to_float(self.portamento_force)
        result["portamento_scale"] = to_float(self.portamento_scale)
        result["portamento_slope"] = to_float(self.portamento_slope)
        result["portamento_time"] = to_float(self.portamento_time)
        result["random_1_frequency"] = to_float(self.random_1__frequency)
        result["random_1_stereo"] = to_float(self.random_1__stereo)
        result["random_1_style"] = to_float(self.random_1__style)
        result["random_1_sync"] = to_float(self.random_1__sync)
        result["random_1_sync_type"] = to_float(self.random_1__sync_type)
        result["random_1_tempo"] = to_float(self.random_1__tempo)
        result["random_2_frequency"] = to_float(self.random_2__frequency)
        result["random_2_stereo"] = to_float(self.random_2__stereo)
        result["random_2_style"] = to_float(self.random_2__style)
        result["random_2_sync"] = to_float(self.random_2__sync)
        result["random_2_sync_type"] = to_float(self.random_2__sync_type)
        result["random_2_tempo"] = to_float(self.random_2__tempo)
        result["random_3_frequency"] = to_float(self.random_3__frequency)
        result["random_3_stereo"] = to_float(self.random_3__stereo)
        result["random_3_style"] = to_float(self.random_3__style)
        result["random_3_sync"] = to_float(self.random_3__sync)
        result["random_3_sync_type"] = to_float(self.random_3__sync_type)
        result["random_3_tempo"] = to_float(self.random_3__tempo)
        result["random_4_frequency"] = to_float(self.random_4__frequency)
        result["random_4_stereo"] = to_float(self.random_4__stereo)
        result["random_4_style"] = to_float(self.random_4__style)
        result["random_4_sync"] = to_float(self.random_4__sync)
        result["random_4_sync_type"] = to_float(self.random_4__sync_type)
        result["random_4_tempo"] = to_float(self.random_4__tempo)
        result["reverb_chorus_amount"] = to_float(self.reverb_chorus_amount)
        result["reverb_chorus_frequency"] = to_float(self.reverb_chorus_frequency)
        result["reverb_decay_time"] = to_float(self.reverb_decay_time)
        result["reverb_dry_wet"] = to_float(self.reverb_dry_wet)
        result["reverb_high_shelf_cutoff"] = to_float(self.reverb_high_shelf_cutoff)
        result["reverb_high_shelf_gain"] = to_float(self.reverb_high_shelf_gain)
        result["reverb_low_shelf_cutoff"] = to_float(self.reverb_low_shelf_cutoff)
        result["reverb_low_shelf_gain"] = to_float(self.reverb_low_shelf_gain)
        result["reverb_on"] = to_float(self.reverb_on)
        result["reverb_pre_high_cutoff"] = to_float(self.reverb_pre_high_cutoff)
        result["reverb_pre_low_cutoff"] = to_float(self.reverb_pre_low_cutoff)
        result["reverb_size"] = to_float(self.reverb_size)
        result["sample"] = to_class(Sample, self.sample)
        result["sample_destination"] = to_float(self.sample_destination)
        result["sample_keytrack"] = to_float(self.sample_keytrack)
        result["sample_level"] = to_float(self.sample_level)
        result["sample_loop"] = to_float(self.sample_loop)
        result["sample_on"] = to_float(self.sample_on)
        result["sample_pan"] = to_float(self.sample_pan)
        result["sample_random_phase"] = to_float(self.sample_random_phase)
        result["sample_transpose"] = to_float(self.sample_transpose)
        result["sample_transpose_quantize"] = to_float(self.sample_transpose_quantize)
        result["sample_tune"] = to_float(self.sample_tune)
        result["stereo_routing"] = to_float(self.stereo_routing)
        result["velocity_track"] = to_float(self.velocity_track)
        result["voice_amplitude"] = to_float(self.voice_amplitude)
        result["voice_priority"] = to_float(self.voice_priority)
        result["voice_tune"] = to_float(self.voice_tune)
        result["volume"] = to_float(self.volume)
        result["wavetables"] = from_list(lambda x: to_class(Wavetable, x), self.wavetables)
        result["bypass"] = from_union([to_float, from_none], self.bypass)
        result["chorus_cutoff"] = from_union([to_float, from_none], self.chorus_cutoff)
        result["chorus_damping"] = from_union([to_float, from_none], self.chorus_damping)
        result["chorus_spread"] = from_union([to_float, from_none], self.chorus_spread)
        result["compressor_mix"] = from_union([to_float, from_none], self.compressor_mix)
        result["filter_1_formant_spread"] = from_union([to_float, from_none], self.filter_1__formant_spread)
        result["filter_2_formant_spread"] = from_union([to_float, from_none], self.filter_2__formant_spread)
        result["filter_fx_formant_spread"] = from_union([to_float, from_none], self.filter_fx_formant_spread)
        result["lfo_1_keytrack_transpose"] = from_union([to_float, from_none], self.lfo_1__keytrack_transpose)
        result["lfo_1_keytrack_tune"] = from_union([to_float, from_none], self.lfo_1__keytrack_tune)
        result["lfo_1_smooth_mode"] = from_union([to_float, from_none], self.lfo_1__smooth_mode)
        result["lfo_1_smooth_time"] = from_union([to_float, from_none], self.lfo_1__smooth_time)
        result["lfo_2_keytrack_transpose"] = from_union([to_float, from_none], self.lfo_2__keytrack_transpose)
        result["lfo_2_keytrack_tune"] = from_union([to_float, from_none], self.lfo_2__keytrack_tune)
        result["lfo_2_smooth_mode"] = from_union([to_float, from_none], self.lfo_2__smooth_mode)
        result["lfo_2_smooth_time"] = from_union([to_float, from_none], self.lfo_2__smooth_time)
        result["lfo_3_keytrack_transpose"] = from_union([to_float, from_none], self.lfo_3__keytrack_transpose)
        result["lfo_3_keytrack_tune"] = from_union([to_float, from_none], self.lfo_3__keytrack_tune)
        result["lfo_3_smooth_mode"] = from_union([to_float, from_none], self.lfo_3__smooth_mode)
        result["lfo_3_smooth_time"] = from_union([to_float, from_none], self.lfo_3__smooth_time)
        result["lfo_4_keytrack_transpose"] = from_union([to_float, from_none], self.lfo_4__keytrack_transpose)
        result["lfo_4_keytrack_tune"] = from_union([to_float, from_none], self.lfo_4__keytrack_tune)
        result["lfo_4_smooth_mode"] = from_union([to_float, from_none], self.lfo_4__smooth_mode)
        result["lfo_4_smooth_time"] = from_union([to_float, from_none], self.lfo_4__smooth_time)
        result["lfo_5_keytrack_transpose"] = from_union([to_float, from_none], self.lfo_5__keytrack_transpose)
        result["lfo_5_keytrack_tune"] = from_union([to_float, from_none], self.lfo_5__keytrack_tune)
        result["lfo_5_smooth_mode"] = from_union([to_float, from_none], self.lfo_5__smooth_mode)
        result["lfo_5_smooth_time"] = from_union([to_float, from_none], self.lfo_5__smooth_time)
        result["lfo_6_keytrack_transpose"] = from_union([to_float, from_none], self.lfo_6__keytrack_transpose)
        result["lfo_6_keytrack_tune"] = from_union([to_float, from_none], self.lfo_6__keytrack_tune)
        result["lfo_6_smooth_mode"] = from_union([to_float, from_none], self.lfo_6__smooth_mode)
        result["lfo_6_smooth_time"] = from_union([to_float, from_none], self.lfo_6__smooth_time)
        result["lfo_7_keytrack_transpose"] = from_union([to_float, from_none], self.lfo_7__keytrack_transpose)
        result["lfo_7_keytrack_tune"] = from_union([to_float, from_none], self.lfo_7__keytrack_tune)
        result["lfo_7_smooth_mode"] = from_union([to_float, from_none], self.lfo_7__smooth_mode)
        result["lfo_7_smooth_time"] = from_union([to_float, from_none], self.lfo_7__smooth_time)
        result["lfo_8_keytrack_transpose"] = from_union([to_float, from_none], self.lfo_8__keytrack_transpose)
        result["lfo_8_keytrack_tune"] = from_union([to_float, from_none], self.lfo_8__keytrack_tune)
        result["lfo_8_smooth_mode"] = from_union([to_float, from_none], self.lfo_8__smooth_mode)
        result["lfo_8_smooth_time"] = from_union([to_float, from_none], self.lfo_8__smooth_time)
        result["random_1_keytrack_transpose"] = from_union([to_float, from_none], self.random_1__keytrack_transpose)
        result["random_1_keytrack_tune"] = from_union([to_float, from_none], self.random_1__keytrack_tune)
        result["random_2_keytrack_transpose"] = from_union([to_float, from_none], self.random_2__keytrack_transpose)
        result["random_2_keytrack_tune"] = from_union([to_float, from_none], self.random_2__keytrack_tune)
        result["random_3_keytrack_transpose"] = from_union([to_float, from_none], self.random_3__keytrack_transpose)
        result["random_3_keytrack_tune"] = from_union([to_float, from_none], self.random_3__keytrack_tune)
        result["random_4_keytrack_transpose"] = from_union([to_float, from_none], self.random_4__keytrack_transpose)
        result["random_4_keytrack_tune"] = from_union([to_float, from_none], self.random_4__keytrack_tune)
        result["reverb_delay"] = from_union([to_float, from_none], self.reverb_delay)
        result["sample_bounce"] = from_union([to_float, from_none], self.sample_bounce)
        result["stereo_mode"] = from_union([to_float, from_none], self.stereo_mode)
        result["view_spectrogram"] = from_union([to_float, from_none], self.view_spectrogram)
        result["voice_override"] = from_union([to_float, from_none], self.voice_override)
        result["voice_transpose"] = from_union([to_float, from_none], self.voice_transpose)
        return result


@dataclass
class VitalPreset:
    author: str
    comments: str
    macro1: str
    macro2: str
    macro3: str
    macro4: str
    preset_style: PresetStyle
    settings: PresetSettings
    synth_version: str
    preset_name: Optional[str] = None

    @staticmethod
    def from_dict(obj: Any) -> 'VitalPreset':
        assert isinstance(obj, dict)
        author = from_str(obj.get("author"))
        comments = from_str(obj.get("comments"))
        macro1 = from_str(obj.get("macro1"))
        macro2 = from_str(obj.get("macro2"))
        macro3 = from_str(obj.get("macro3"))
        macro4 = from_str(obj.get("macro4"))
        preset_style = PresetStyle(obj.get("preset_style"))
        settings = PresetSettings.from_dict(obj.get("settings"))
        synth_version = from_str(obj.get("synth_version"))
        preset_name = from_union([from_str, from_none], obj.get("preset_name"))
        return VitalPreset(author, comments, macro1, macro2, macro3, macro4, preset_style, settings, synth_version, preset_name)

    def to_dict(self) -> dict:
        result: dict = {}
        result["author"] = from_str(self.author)
        result["comments"] = from_str(self.comments)
        result["macro1"] = from_str(self.macro1)
        result["macro2"] = from_str(self.macro2)
        result["macro3"] = from_str(self.macro3)
        result["macro4"] = from_str(self.macro4)
        result["preset_style"] = to_enum(PresetStyle, self.preset_style)
        result["settings"] = to_class(PresetSettings, self.settings)
        result["synth_version"] = from_str(self.synth_version)
        result["preset_name"] = from_union([from_str, from_none], self.preset_name)
        return result


def vital_preset_from_dict(s: Any) -> VitalPreset:
    return VitalPreset.from_dict(s)


def vital_preset_to_dict(x: VitalPreset) -> Any:
    return to_class(VitalPreset, x)


def preset_style_from_dict(s: Any) -> PresetStyle:
    return PresetStyle(s)


def preset_style_to_dict(x: PresetStyle) -> Any:
    return to_enum(PresetStyle, x)


def preset_settings_from_dict(s: Any) -> PresetSettings:
    return PresetSettings.from_dict(s)


def preset_settings_to_dict(x: PresetSettings) -> Any:
    return to_class(PresetSettings, x)


def lfo_from_dict(s: Any) -> Lfo:
    return Lfo.from_dict(s)


def lfo_to_dict(x: Lfo) -> Any:
    return to_class(Lfo, x)


def modulation_from_dict(s: Any) -> Modulation:
    return Modulation.from_dict(s)


def modulation_to_dict(x: Modulation) -> Any:
    return to_class(Modulation, x)


def source_from_dict(s: Any) -> Source:
    return Source(s)


def source_to_dict(x: Source) -> Any:
    return to_enum(Source, x)


def sample_from_dict(s: Any) -> Sample:
    return Sample.from_dict(s)


def sample_to_dict(x: Sample) -> Any:
    return to_class(Sample, x)


def wavetable_from_dict(s: Any) -> Wavetable:
    return Wavetable.from_dict(s)


def wavetable_to_dict(x: Wavetable) -> Any:
    return to_class(Wavetable, x)


def group_from_dict(s: Any) -> Group:
    return Group.from_dict(s)


def group_to_dict(x: Group) -> Any:
    return to_class(Group, x)


def component_from_dict(s: Any) -> Component:
    return Component.from_dict(s)


def component_to_dict(x: Component) -> Any:
    return to_class(Component, x)


def keyframe_from_dict(s: Any) -> Keyframe:
    return Keyframe.from_dict(s)


def keyframe_to_dict(x: Keyframe) -> Any:
    return to_class(Keyframe, x)


def purple_type_from_dict(s: Any) -> PurpleType:
    return PurpleType(s)


def purple_type_to_dict(x: PurpleType) -> Any:
    return to_enum(PurpleType, x)
