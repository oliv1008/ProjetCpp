.PHONY: clean All

All:
	@echo "----------Building project:[ ProjetCpp - Debug ]----------"
	@"$(MAKE)" -f  "ProjetCpp.mk"
clean:
	@echo "----------Cleaning project:[ ProjetCpp - Debug ]----------"
	@"$(MAKE)" -f  "ProjetCpp.mk" clean
