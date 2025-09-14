DEPEND_TARGETS += libstream.recursive
ECHO_TARGETS += libstream.echo
libstream.recursive:
	@echo SUPER_MAKE_DIR=/volumes/llama/home/alpine/libraries/libast/               >> /volumes/llama/home/alpine/libraries/libstream/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/volumes/llama/home/alpine/libraries/libast/.make >> /volumes/llama/home/alpine/libraries/libstream/.make/super
	cd /volumes/llama/home/alpine/libraries/libstream/ && make recursive && make install
	-rm /volumes/llama/home/alpine/libraries/libstream/.make/super
libstream.echo:
	@echo SUPER_MAKE_DIR=/volumes/llama/home/alpine/libraries/libast/               >> /volumes/llama/home/alpine/libraries/libstream/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/volumes/llama/home/alpine/libraries/libast/.make >> /volumes/llama/home/alpine/libraries/libstream/.make/super
	cd /volumes/llama/home/alpine/libraries/libstream/ && make echo
	-rm /volumes/llama/home/alpine/libraries/libstream/.make/super
