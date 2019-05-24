.PHONY: clean All

All:
	@echo "----------Building project:[ ProjetCpp - Release ]----------"
	@"$(MAKE)" -f  "ProjetCpp.mk"
clean:
	@echo "----------Cleaning project:[ ProjetCpp - Release ]----------"
	@"$(MAKE)" -f  "ProjetCpp.mk" clean
