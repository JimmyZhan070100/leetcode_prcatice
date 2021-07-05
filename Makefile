SUBDIRS := $(*/.)
clean:
	find . -type f -executable -delete $(SUBDIRS)
