DEPEND_TARGETS += libplatform.recursive
ECHO_TARGETS += libplatform.echo
libplatform.recursive:
	@echo SUPER_MAKE_DIR=/volumes/llama/home/alpine/libraries/libast/               >> /volumes/llama/home/alpine/libraries/libplatform/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/volumes/llama/home/alpine/libraries/libast/.make >> /volumes/llama/home/alpine/libraries/libplatform/.make/super
	cd /volumes/llama/home/alpine/libraries/libplatform/ && make recursive && make install
	-rm /volumes/llama/home/alpine/libraries/libplatform/.make/super
libplatform.echo:
	@echo SUPER_MAKE_DIR=/volumes/llama/home/alpine/libraries/libast/               >> /volumes/llama/home/alpine/libraries/libplatform/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/volumes/llama/home/alpine/libraries/libast/.make >> /volumes/llama/home/alpine/libraries/libplatform/.make/super
	cd /volumes/llama/home/alpine/libraries/libplatform/ && make echo
	-rm /volumes/llama/home/alpine/libraries/libplatform/.make/super
