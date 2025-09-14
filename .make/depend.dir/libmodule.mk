DEPEND_TARGETS += libmodule.recursive
ECHO_TARGETS += libmodule.echo
libmodule.recursive:
	@echo SUPER_MAKE_DIR=/volumes/llama/home/alpine/libraries/libast/               >> /volumes/llama/home/alpine/libraries/libmodule/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/volumes/llama/home/alpine/libraries/libast/.make >> /volumes/llama/home/alpine/libraries/libmodule/.make/super
	cd /volumes/llama/home/alpine/libraries/libmodule/ && make recursive && make install
	-rm /volumes/llama/home/alpine/libraries/libmodule/.make/super
libmodule.echo:
	@echo SUPER_MAKE_DIR=/volumes/llama/home/alpine/libraries/libast/               >> /volumes/llama/home/alpine/libraries/libmodule/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/volumes/llama/home/alpine/libraries/libast/.make >> /volumes/llama/home/alpine/libraries/libmodule/.make/super
	cd /volumes/llama/home/alpine/libraries/libmodule/ && make echo
	-rm /volumes/llama/home/alpine/libraries/libmodule/.make/super
