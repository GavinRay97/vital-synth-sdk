.PHONY: generate_types_from_preset_directory

generate_types_from_preset_directory: ## Generate type definitions for a language, given the path to a directory containing the user preset folders
generate_types_from_preset_directory: ## [Args]: LANGUAGE, VITAL_PRESET_DIRECTORY
generate_types_from_preset_directory: ## [Example]: make generate_types_from_preset_directory LANGUAGE="ts" VITAL_PRESET_DIRECTORY="./Presets"
generate_types_from_preset_directory: ## [Note 1]: Requires "jq" and "quicktype" installed.
generate_types_from_preset_directory: ## [Note 2]: These types will not be entirely accurate, and will need to be manually cleaned up, but will get you 95% of the way there
	cat `find $(VITAL_PRESET_DIRECTORY) -name "*.vital"` \
	| jq --slurp \
	| quicktype -o Vital.types.ts -l $(LANGUAGE) --just-types --no-maps

help:
	@grep -E '^[a-zA-Z0-9_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.DEFAULT_GOAL := help