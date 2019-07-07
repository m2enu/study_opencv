MK              := mkdir
RESOURCE_DIR    := resource

GITHUB_URL      := https://raw.githubusercontent.com/yoyoyo-yo/Gasyori100knock/master
RESOURCES_URL   := \
  $(GITHUB_URL)/Tutorial/imori.jpg \

.PHONY: setup

$(RESOURCE_DIR):
	$(MK) $(RESOURCE_DIR)

setup: $(RESOURCE_DIR)
	cd $(RESOURCE_DIR); \
	$(foreach url, $(RESOURCES_URL), wget -N --no-check-certificate $(url))
