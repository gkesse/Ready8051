GSRC = $(GPROJECT_SRC)
GBIN = bin
GBUILD = build
GTARGET_BIN = $(GBIN)\rd8051
#================================================
GINCS =\
    $(GSRC)\include \
#================================================
GOBJS = \
    $(patsubst $(GSRC)/%.c, $(GSRC)/%.obj, $(wildcard $(GSRC)/*.c)) \
    $(patsubst $(GSRC)/manager/%.c, $(GSRC)/manager/%.obj, $(wildcard $(GSRC)/manager/*.c)) \
#================================================
GDIRECTIVES =\
    debug \
    code \
    preprint \
    browse \
    optimize(8,speed) \
#================================================
GDEFINE =\
    $(GCOMPILER_NAME) \
#================================================
GCFLAGS =\
    $(GDIRECTIVES) \
    define($(GDEFINE)) \
#================================================
# keil
all: compile

compile: $(GOBJS)
	@if not exist $(GBUILD) ( mkdir $(GBUILD) )
	@echo $(GOBJS)
hex:
	@if not exist $(GBUILD) ( mkdir $(GBUILD) )
	@if not exist $(GBIN) ( mkdir $(GBIN) )
	@packihx $(GTARGET_GEN) > $(GTARGET_BIN)
$(GSRC)/%.obj: $(GSRC)/%.c
	@if not exist $(GBUILD) ( mkdir $(GBUILD) )
	@cd $(GBUILD) && c51 $< $(GDIRECTIVES) incdir($(GINCS)) define($(GDEFINE))
$(GSRC)/manager/%.obj: $(GSRC)/manager/%.c
	@if not exist $(GBUILD) ( mkdir $(GBUILD) )
	@cd $(GBUILD) && c51 $< $(GDIRECTIVES) incdir($(GINCS)) define($(GDEFINE))
clean_exe: 
	@if not exist $(GBIN) ( mkdir $(GBIN) )
	@del /s /q $(GTARGET_BIN)
clean: 
	@if not exist $(GBIN) ( mkdir $(GBIN) )
	@if not exist $(GBUILD) ( mkdir $(GBUILD) )
	@del /s /q $(GBUILD)\*.* $(GTARGET_BIN)
#================================================
# git
git_status:
	@cd $(GPROJECT_PATH) && git status -u
git_push:
	@cd $(GPROJECT_PATH) && git pull && git add --all && git commit -m "Initial Commit" && git push -u origin master
git_push_o:
	@cd $(GPROJECT_PATH) && git add --all && git commit -m "Initial Commit" && git push -u origin master
git_clone:
	@cd $(GPROJECT_ROOT) && git clone $(GGIT_URL) $(GGIT_NAME) 
#================================================
