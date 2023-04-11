all: test

test: temp_sensor
	(cd temp_sensor && ceedling test:all)

temp_sensor:
	(ceedling example temp_sensor)

clean:
	-rm -r temp_sensor

.PHONY: all clean test temp_sensor