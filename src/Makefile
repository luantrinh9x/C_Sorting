CC=gcc
CFLAGS=-Wall -std=c99 #-g -pg

SOURCES = pt_utils.c pt_sorting.c test_pt_sorting.c
OBJS = $(patsubst %.c,%.o,$(SOURCES))
HEADERS = pt_utils.h pt_sorting.h
EXECS = test_pt_sorting

SOURCES2 = pt_utils.c pt_sorting.c test2_pt_sorting.c
OBJS2 = $(patsubst %.c,%.o,$(SOURCES2))
EXECS2 = test2_pt_sorting
LENGTH = 1000
NBITS = 16
SEED = 2451

test_pt_sorting: $(OBJS) 
	$(CC) $(CFLAGS) -o test_pt_sorting $(OBJS)

$(OBJS): $(HEADERS)

test2_pt_sorting: $(OBJS2) 

tests: $(EXECS2)
	./test2_pt_sorting selection_sort $(LENGTH) $(NBITS) $(SEED)
	./test2_pt_sorting insertion_sort $(LENGTH) $(NBITS) $(SEED)
	./test2_pt_sorting merge_sort $(LENGTH) $(NBITS) $(SEED)
	./test2_pt_sorting heap_sort $(LENGTH) $(NBITS) $(SEED)
	./test2_pt_sorting quick_sort_hoare $(LENGTH) $(NBITS) $(SEED)
	./test2_pt_sorting quick_sort_median $(LENGTH) $(NBITS) $(SEED)
	./test2_pt_sorting quick_sort_random $(LENGTH) $(NBITS) $(SEED)

.PHONY: clean
clean:
	rm *.o 
	
.PHONY: cleanall
cleanall:
	rm *.o *~ $(EXECS)
