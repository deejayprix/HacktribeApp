.PHONY: all apps clean

all: apps

apps:
	cd apps && $(MAKE)

clean:
	cd apps && $(MAKE) clean
