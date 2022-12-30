BINDIR = bin
SRCDIR = . src
INCDIR = ./ ./include/

COMPILER = gcc
OPTIMIZATION = -O0
DFLAGS = -MP -MD
CFLAGS = -Wall -Wextra -g $(foreach D, $(INCDIR),-I$(D)) $(OPTIMIZATION) $(DFLAGS)

CFILES = $(foreach D, $(SRCDIR), $(wildcard $(D)/*.c))
OFILES = $(patsubst %.c, %.o, $(CFILES))
DFILES = $(patsubst %.c, %.d, $(CFILES))

APPNAME = FinalProject
OUTPUT = $(APPNAME).exe

# Build all
all: $(BINDIR)/$(OUTPUT)

# Dependencies for final binary
$(BINDIR)/$(OUTPUT): $(OFILES)
	$(COMPILER) -o $@ $^

# Dependencies of each .o files
%.o: %.c
	$(COMPILER) $(CFLAGS) -c -o $@ $<

# Clean
clean:
	rm -rf $(OFILES) $(DFILES) $(BINDIR)/$(OUTPUT)

# Run binary
run:
	$(BINDIR)/$(OUTPUT)

# Include dependencies
-include $(DFILES)