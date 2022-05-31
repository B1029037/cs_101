#include <iostream>

using namespace std;

class MMmanger {
	private:
		int space;
		int** calloced_p;
		int* g_mm;
	public:
		MMmanger(int num) {
			space = num;
			calloced_p = (int**)malloc(space * sizeof(int*));
			for(int i=0; i < space; i++) {
		    	calloced_p[i] = 0;
		    }
			g_mm = (int*)malloc(space * sizeof(int));
		}

		int get_MMCapacity() {
			int unallocated = 0;
			for(int i=0; i < space; i++) {
				if(!calloced_p[i]) {
					unallocated++;
				}
			}
			return unallocated;
		}

		void print_calloc_array(int flag, int size) {
			cout << "Capacity:" << get_MMCapacity() << " - ";
			for(int i=0; i < space; i++) {
		        (calloced_p[i]) ? cout << "1" : cout << "0";
		    }
		    if(!flag) {
		    	cout << " <- Out of space: demand " << size;
		    }
		    cout << endl;
		}

		int* calloc_MM(int size) {
			int av_size = 0;
		    int index = 0;
		    for(; index < space; index++) {
		        av_size = (calloced_p[index]) ? 0 : av_size+1;
		        if(av_size == size) {
		            index -= size-1;
		            break;
		        }
		    }
		    
		    if(av_size < size) {
		        print_calloc_array(0, size);
		        return NULL;
		    }
		    for(int i=0; i < size; i++) {
		        calloced_p[index + i] = &g_mm[index];
		    }
		    print_calloc_array(1,0);
		    return &g_mm[index];
		}

		void free_MM(int* p) {
			for(int i=0; i < space; i++) {
		        if(calloced_p[i] == p) {
		            calloced_p[i] = NULL;
		        }
		    }
		    print_calloc_array(1,0);
		}
};

int main() {
	MMmanger mmer(10);
	int* p1 = mmer.calloc_MM(1);
	int* p2 = mmer.calloc_MM(2);
	int* p3 = mmer.calloc_MM(3);
	int* p4 = mmer.calloc_MM(4);
	mmer.free_MM(p1);
	mmer.free_MM(p4);
	int* p5 = mmer.calloc_MM(6);

	return 0;
}