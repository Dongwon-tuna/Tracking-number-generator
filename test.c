#include <stdio.h>
#include <stdbool.h>
#include "parson.h"

void createAndAppendJSON(JSON_Array *mainArray, const char* title, int year, int runtime, const char* genre, const char* director, const char** actors, int actorsCount, double imdbRating, bool koreaRelease) {
    JSON_Value *rootValue = json_value_init_object();
    JSON_Object *rootObject = json_value_get_object(rootValue);

    json_object_set_string(rootObject, "Title", title);
    json_object_set_number(rootObject, "Year", year);
    json_object_set_number(rootObject, "Runtime", runtime);
    json_object_set_string(rootObject, "Genre", genre);
    json_object_set_string(rootObject, "Director", director);

    json_object_set_value(rootObject, "Actors", json_value_init_array());
    JSON_Array *actorsArray = json_object_get_array(rootObject, "Actors");
    for (int i = 0; i < actorsCount; ++i) {
        json_array_append_string(actorsArray, actors[i]);
    }

    json_object_set_number(rootObject, "imdbRating", imdbRating);
    json_object_set_boolean(rootObject, "KoreaRelease", koreaRelease);

    json_array_append_value(mainArray, rootValue);
}

int main() {
    JSON_Value *mainValue = json_value_init_array();
    JSON_Array *mainArray = json_value_get_array(mainValue);

    const char* actors1[] = {"Leonardo DiCaprio", "Joseph Gordon-Levitt", "Ellen Page", "Tom Hardy", "Ken Watanabe"};
    const char* actors2[] = {"Actor1", "Actor2", "Actor3"};

    createAndAppendJSON(mainArray, "Inception", 2010, 148, "Sci-Fi", "Christopher Nolan", actors1, 5, 8.8, true);
    createAndAppendJSON(mainArray, "Another Movie", 2015, 120, "Drama", "Director X", actors2, 3, 7.5, false);

    json_serialize_to_file_pretty(mainValue, "example_combined.json");

    json_value_free(mainValue);

    return 0;
}
