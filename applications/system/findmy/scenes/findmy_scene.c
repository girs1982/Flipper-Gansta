#include "findmy_scene.h"
#include "findmy.h"

// Generate scene on_enter handlers array
#define ADD_SCENE(prefix, name, id) prefix##_scene_##name##_on_enter,
void (*const findmy_on_enter_handlers[])(void*) = {
#include "findmy_scenes.h"
};
#undef ADD_SCENE

// Generate scene on_event handlers array
#define ADD_SCENE(prefix, name, id) prefix##_scene_##name##_on_event,
bool (*const findmy_on_event_handlers[])(void* context, SceneManagerEvent event) = {
#include "findmy_scenes.h"
};
#undef ADD_SCENE

// Generate scene on_exit handlers array
#define ADD_SCENE(prefix, name, id) prefix##_scene_##name##_on_exit,
void (*const findmy_on_exit_handlers[])(void* context) = {
#include "findmy_scenes.h"
};
#undef ADD_SCENE

// Initialize scene handlers configuration structure
const SceneManagerHandlers findmy_scene_handlers = {
    .on_enter_handlers = findmy_on_enter_handlers,
    .on_event_handlers = findmy_on_event_handlers,
    .on_exit_handlers = findmy_on_exit_handlers,
    .scene_num = FindMySceneNum,
};
