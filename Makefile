all: freertos-lab

freertos-repository:
	git clone https://github.com/FreeRTOS/FreeRTOS.git --recurse-submodules

freertos-lab: freertos-repository
	$(MAKE) -C lab_FreeRTOS

clean:
	@echo "not implemented"

.PHONY: all clean freertos-repository freertos-lab