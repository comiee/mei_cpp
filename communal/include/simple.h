#pragma once

#define INSTANCE(__cls__) \
static __cls__ *getInstance() { \
    static __cls__ instance; \
    return &instance; \
}
