#include <stdio.h>
#include <stdlib.h>
#define MAX_HEIGHT 41
typedef struct {
    int length;
    int width;
    int height;
} box;

// Function to check if the box can fit in the tunnel
int is_lower_than_max_height(box b) {
    return b.height < MAX_HEIGHT;
}

// Function to compute the volume of a box
int get_volume(box b) {
    return b.length * b.width * b.height;
}

int main()
{
	int n;
	scanf("%d", &n);
	box *boxes = malloc(n * sizeof(box));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
	}
	for (int i = 0; i < n; i++) {
		if (is_lower_than_max_height(boxes[i])) {
			printf("%d\n", get_volume(boxes[i]));
		}
	}
	return 0;
}
