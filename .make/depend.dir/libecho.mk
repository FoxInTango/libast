DEPEND_TARGETS += libecho.recursive
ECHO_TARGETS += libecho.echo
libecho.recursive:
	@echo SUPER_MAKE_DIR=/volumes/llama/home/alpine/libraries/libast/               >> /volumes/llama/home/alpine/libraries/libecho/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/volumes/llama/home/alpine/libraries/libast/.make >> /volumes/llama/home/alpine/libraries/libecho/.make/super
	cd /volumes/llama/home/alpine/libraries/libecho/ && make recursive && make install
	-rm /volumes/llama/home/alpine/libraries/libecho/.make/super
libecho.echo:
	@echo SUPER_MAKE_DIR=/volumes/llama/home/alpine/libraries/libast/               >> /volumes/llama/home/alpine/libraries/libecho/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/volumes/llama/home/alpine/libraries/libast/.make >> /volumes/llama/home/alpine/libraries/libecho/.make/super
	cd /volumes/llama/home/alpine/libraries/libecho/ && make echo
	-rm /volumes/llama/home/alpine/libraries/libecho/.make/super
