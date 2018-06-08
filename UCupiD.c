#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20

struct person_info {
	int SID, age, pol_lean, height, weight;
	char sex, preference;
	char name[MAX_LEN], major_hobby[MAX_LEN], minor_hobby[MAX_LEN];
	struct person_info *next;
};

struct person_info *insert_person (struct person_info *q, struct person_info *p)
{
	struct person_info *last;
	struct person_info *prev;

	last = malloc(sizeof(struct person_info));
	prev = malloc(sizeof(struct person_info));

	p->next = NULL;
	last = q;
	
	for (last = q; last != NULL; last = last->next) {
		prev = last;
	}

	prev->next = p;

	return q;
}

struct person_info *find (struct person_info *q, int SID, char *sid)
{
	struct person_info* temp = malloc(sizeof(struct person_info));
	temp = q;
        while (temp->next != NULL) {
		if (temp->SID == SID) {
                	return temp;
		}
		temp = temp->next;
	}

	return NULL;
}

int match_sexual_orientation (struct person_info *q, struct person_info *test_person)
{
	return ((test_person->sex == q->preference) && 
		(test_person->preference == q->sex));
}

int match_appearance (struct person_info *q, struct person_info *test_person)
{
	int height_diff, weight_diff;
	height_diff = abs(test_person->height - q->height);
	weight_diff = abs(test_person->weight - q->weight);

	return (((height_diff <= test_person->height/10) || 
		(height_diff <= q->height/10)) && 
		((weight_diff <= test_person->weight/10) || 
		(weight_diff <= q->weight/10)));
}

int match_personality (struct person_info *q, struct person_info *test_person)
{
	return (!strcmp(test_person->major_hobby, q->major_hobby) && 
		!strcmp(test_person->minor_hobby, q->minor_hobby));
}

int match_identity (struct person_info *q, struct person_info *test_person)
{
	return ((abs(test_person->age - q->age) <= 10) && 
		(abs(q->pol_lean - test_person->pol_lean) <= 2));
}

void match(struct person_info *q, struct person_info *test_person)
{
	char line[40];
	sprintf(line, "match_%d.txt", test_person->SID);
	FILE *fout = fopen(line, "w");

	char output[256];

	fprintf(fout, "Matches for user %d (%s): \n", test_person->SID, test_person->name);
	while (q) {
		if (q->SID != test_person->SID) {
			if (match_sexual_orientation(q, test_person) && 
				(match_appearance(q, test_person) || 
				match_personality(q, test_person) || 
				match_identity(q, test_person))) {
				sprintf(output, "- %d (%s)", q->SID, q->name);
				fprintf(fout, "%s\n", output);
			}
		}
		q = q->next;
	}
	fclose(fout);
}

void free_data (struct person_info* q)
{
	struct person_info* temp;
	while(q->next != NULL)
      	{
                temp = q;
		q = q->next;
                free(temp);
        }
}

int read_file (char *file, int SID, char *sid)
{
	char temp[256];
	
	struct person_info *q = NULL;
	struct person_info *p;

	FILE *fin;

	fin = fopen(file, "r");

	if (!fin) {
		printf("Error: cannot open %s\n", file);
		exit(1);
	}

	while (fgets(temp, 256, fin) != NULL) {
		p = malloc(sizeof(struct person_info));
		sscanf(temp, "%d,%[^,],%c,%c,%d,%d,%[^,],%[^,],%d,%d", 
			&(p->SID), p->name, &(p->sex), &(p->preference),
			&(p->age), &(p->pol_lean), p->major_hobby, 
			p->minor_hobby, &(p->height), &(p->weight));

		if (!q) {
			q = p;
		} else {
			insert_person(q, p);
		}
	}

	struct person_info *test_person = find(q, SID, sid);
	
	if(!test_person)
	{
		printf("User with SID %s not found\n", sid);
		exit(1);
	}

	match(q, test_person);
	free_data(q);

	fclose(fin);
	return 0;
}

int main (int argc, char *argv[])
{
	if (argc < 3) {
		printf("Usage: %s db_file SID\n", argv[0]);
                exit(1);
	} else {
		read_file(argv[1], atoi(argv[2]), argv[2]);
	}
}