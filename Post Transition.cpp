#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* id;
    int weight;
} package;

typedef struct {
    int min_weight;
    int max_weight;
    int packages_count;
    package* packages;
} post_office;

typedef struct {
    char* name;
    int offices_count;
    post_office* offices;
} town;

/* FIND TOWN BY NAME */
town* find_town(town* towns, int towns_count, char* name) {
    for (int i = 0; i < towns_count; i++) {
        if (strcmp(towns[i].name, name) == 0) {
            return &towns[i];
        }
    }
    return NULL;
}

/* FIND TOWN WITH MOST PACKAGES */
town* town_with_most_packages(town* towns, int towns_count) {
    town* result = &towns[0];
    int max_packages = 0;

    for (int i = 0; i < towns_count; i++) {
        int total = 0;
        for (int j = 0; j < towns[i].offices_count; j++) {
            total += towns[i].offices[j].packages_count;
        }
        if (total > max_packages) {
            max_packages = total;
            result = &towns[i];
        }
    }
    return result;
}

/* PRINT ALL PACKAGES OF A TOWN */
void print_all_packages(town t) {
    printf("%s:\n", t.name);

    for (int i = 0; i < t.offices_count; i++) {
        printf("\t%d:\n", i);
        for (int j = 0; j < t.offices[i].packages_count; j++) {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

/* SEND PACKAGES BETWEEN OFFICES */
void send_all_acceptable_packages(
    town* source, int source_office_index,
    town* target, int target_office_index
) {
    post_office* src = &source->offices[source_office_index];
    post_office* tgt = &target->offices[target_office_index];

    package* new_src = malloc(src->packages_count * sizeof(package));
    int new_src_count = 0;

    for (int i = 0; i < src->packages_count; i++) {
        if (src->packages[i].weight >= tgt->min_weight &&
            src->packages[i].weight <= tgt->max_weight) {

            tgt->packages = realloc(tgt->packages,
                                    (tgt->packages_count + 1) * sizeof(package));

            tgt->packages[tgt->packages_count++] = src->packages[i];

        } else {
            new_src[new_src_count++] = src->packages[i];
        }
    }

    free(src->packages);
    src->packages = new_src;
    src->packages_count = new_src_count;
}

int main() {
    int towns_count;
    scanf("%d", &towns_count);

    town* towns = malloc(towns_count * sizeof(town));

    for (int i = 0; i < towns_count; i++) {
        towns[i].name = malloc(100 * sizeof(char));
        scanf("%s", towns[i].name);

        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(towns[i].offices_count * sizeof(post_office));

        for (int j = 0; j < towns[i].offices_count; j++) {
            scanf("%d %d %d",
                  &towns[i].offices[j].packages_count,
                  &towns[i].offices[j].min_weight,
                  &towns[i].offices[j].max_weight);

            towns[i].offices[j].packages =
                malloc(towns[i].offices[j].packages_count * sizeof(package));

            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                towns[i].offices[j].packages[k].id =
                    malloc(100 * sizeof(char));
                scanf("%s", towns[i].offices[j].packages[k].id);

                scanf("%d", &towns[i].offices[j].packages[k].weight);
            }
        }
    }

    int queries;
    scanf("%d", &queries);

    for (int i = 0; i < queries; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            char name[100];
            scanf("%s", name);
            town* t = find_town(towns, towns_count, name);
            print_all_packages(*t);
        }

        else if (type == 2) {
            char src_name[100], tgt_name[100];
            int src_idx, tgt_idx;

            scanf("%s %d %s %d", src_name, &src_idx, tgt_name, &tgt_idx);

            town* src = find_town(towns, towns_count, src_name);
            town* tgt = find_town(towns, towns_count, tgt_name);

            send_all_acceptable_packages(src, src_idx, tgt, tgt_idx);
        }

        else if (type == 3) {
            town* t = town_with_most_packages(towns, towns_count);
            printf("Town with the most number of packages is %s\n", t->name);
        }
    }

    return 0;
}

