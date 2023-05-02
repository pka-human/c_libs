#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define create_empty_dca create_dca(NULL)

typedef struct dynamic_char_array {
    unsigned size;
    char* array;
} dca;

char get(struct dynamic_char_array* this, unsigned position) {
    if (position <= this->size - 1 && this->size > 0) {
        return this->array[position];
    } else {
        return '\0';
    }
}

bool add(struct dynamic_char_array* this, char value) {
    char* tempvar = (char*) realloc(this->array, (this->size + 1) * sizeof(char));
    if (!tempvar) {
        return false;
    }
    this->array = tempvar;
    this->array[this->size++] = value;
    return true;
}

void clear(struct dynamic_char_array* this) {
    free(this->array);
    this->size = 0;
    this->array = NULL;
}

bool set(struct dynamic_char_array* this, unsigned position, char value) {
    if (position <= this->size - 1 && this->size > 0) {
        this->array[position] = value;
    } else {
        return false;
    }
    if (get(this, position) == value) {
        return true;
    } else {
        return false;
    }
}

bool ksets(struct dynamic_char_array* this, char text[]) {
    bool IsEndOfLine = false;
    if (this->size > 0 && get(this, this->size - 1) == '\0') {
        if (!set(this, this->size - 1, text[0])) {
            return false;
        }
        IsEndOfLine = true;
    }
    unsigned textsize = strlen(text);
    for (unsigned i = IsEndOfLine?1:0; i < textsize; i++) {
        if(!add(this, text[i])) {
            return false;
        }
    }
    if(!add(this, '\0')) {
            return false;
    }
    return true;
}

bool sets(struct dynamic_char_array* this, char text[]) {
    clear(this);
    ksets(this, text);
}

bool del(struct dynamic_char_array* this, unsigned position) {
    if (position <= this->size - 1 && this->size > 0) {
        if (this->size == 1) {
            clear(this);
            return true;
        }
        bool IsExecOnce = false;
        for (unsigned i = position; i < this->size - 1; i++) {
            IsExecOnce = true;
            if (!set(this, i, get(this, i + 1))) {
                return false;
            }
        }
        char* tempvar = (char*) realloc(this->array, (--this->size) * sizeof(char));
        if (!tempvar) {
            return false;
        }
        this->array = tempvar;
    } else {
        return false;
    }
    return true;
}

struct dynamic_char_array create_dca(char text[]) {
    struct dynamic_char_array new_dynamic_char_array = {0, NULL};
    bool success = true;
    if (text != NULL) {
        success = sets(&new_dynamic_char_array, text);
    }
    if (success) {
        return new_dynamic_char_array;
    }
}

struct dynamic_char_array input(char invitation[]) {
    printf("%s", invitation);
    struct dynamic_char_array outputstring = create_empty_dca;
    bool err = false;
    char tmpchar = getchar();
    while (tmpchar != '\n') {
        if (!add(&outputstring, tmpchar)) {
            err = true;
            break;
        }
        tmpchar = getchar();
    }
    if (!add(&outputstring, '\0')) {
        err = true;
    }
    if (!err) {
        return outputstring;
    }
}
