DEPEND_TARGETS += libplatform.recursive
ECHO_TARGETS += libplatform.echo
libplatform.recursive:
	@echo SUPER_MAKE_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libast/               >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libplatform/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libast/.make >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libplatform/.make/super
	cd /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libplatform/ && make recursive && make install
	-rm /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libplatform/.make/super
libplatform.echo:
	@echo SUPER_MAKE_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libast/               >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libplatform/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libast/.make >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libplatform/.make/super
	cd /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libplatform/ && make echo
	-rm /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libplatform/.make/super
