#ifndef MEI_SIMPLE_H
#define MEI_SIMPLE_H

#define INSTANCE(__cls__) \
static __cls__ *getInstance() { \
    static __cls__ instance; \
    return &instance; \
}

#endif //MEI_SIMPLE_H
