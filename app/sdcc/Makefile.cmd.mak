GSRC = $(GPROJECT_SRC)
GBIN = $(GPROJECT_BUILD)\bin
GBUILD = $(GPROJECT_BUILD)\build
GTARGET_GEN = $(GBUILD)\main.ihx
GTARGET_BIN = $(GBIN)\rd8051.hex
#================================================
GINCS =\
    -I$(GSRC)/include \
#================================================
GOBJS = \
    $(patsubst $(GSRC)/%.c, $(GBUILD)/%.rel, $(wildcard $(GSRC)/*.c)) \
    $(patsubst $(GSRC)/manager/%.c, $(GBUILD)/%.rel, $(wildcard $(GSRC)/manager/*.c)) \
#================================================
GCFLAGS =\
    --std-c11 \
#================================================
all: clean_exe compile hex
#================================================
# sdcc
compile: $(GOBJS)
	@if not exist $(GBUILD) ( mkdir $(GBUILD) )
	cd $(GBUILD) && sdcc $(GCFLAGS) $(GOBJS) $(GLIBS)
hex:
	@if not exist $(GBUILD) ( mkdir $(GBUILD) )
	@if not exist $(GBIN) ( mkdir $(GBIN) )
	packihx $(GTARGET_GEN) > $(GTARGET_BIN)
$(GBUILD)/%.rel: $(GSRC)/%.c
	@if not exist $(GBUILD) ( mkdir $(GBUILD) )
	cd $(GBUILD) && sdcc $(GCFLAGS) -c $< $(GINCS)
$(GBUILD)/%.rel: $(GSRC)/manager/%.c
	@if not exist $(GBUILD) ( mkdir $(GBUILD) )
	cd $(GBUILD) && sdcc $(GCFLAGS) -c $< $(GINCS)
clean_exe: 
	@if not exist $(GBIN) ( mkdir $(GBIN) )
	del /s /q $(GBIN)\*
clean: 
	@if not exist $(GBIN) ( mkdir $(GBIN) )
	@if not exist $(GBUILD) ( mkdir $(GBUILD) )
	del /s /q $(GBUILD)\*.* $(GBIN)\*.*
#================================================
# git
git_status:
	cd $(GPROJECT_PATH) && git status
git_push:
	cd $(GPROJECT_PATH) && git pull && git add --all && git commit -m "Initial Commit" && git push -u origin master
git_push_o:
	cd $(GPROJECT_PATH) && git add --all && git commit -m "Initial Commit" && git push -u origin master
git_clone:
	cd $(GPROJECT_ROOT) && git clone $(GGIT_URL) $(GGIT_NAME) 
#================================================
