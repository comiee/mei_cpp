#ifndef MEI_JSON_TOOL_H
#define MEI_JSON_TOOL_H

#include "type.h"
#include "json/json.h"

class JsonTool {
public:
    static string dump(const Json::Value &root);

    static Json::Value parse(const string &str);

    template<typename K, typename V, typename...Args>
    inline static Json::Value createObject(K k, V v, Args...args) { return _createObject(k, v, args...); }

    template<typename X, typename...Args>
    inline static Json::Value createArray(X x, Args...args) { return _createArray(x, args...); }

private:
    // 为保持简洁，使用的模板的方法实现放在这里，public里只透传

    template<typename K, typename V, typename...Args>
    static Json::Value _createObject(K k, V v, Args...args) {
        Json::Value root;
        root[k] = v;
        if constexpr (sizeof...(args) > 0) {
            Json::Value other = _createObject(args...);
            for (const string &key: other.getMemberNames()) {
                root[key] = other[key];
            }
        }
        return root;
    }

    template<typename X, typename...Args>
    static Json::Value _createArray(X x, Args...args) {
        Json::Value root;
        root.append(x);
        if constexpr (sizeof...(args) > 0) {
            Json::Value other = _createArray(args...);
            for (const Json::Value &item: other) {
                root.append(item);
            }
        }
        return root;
    }
};


#endif //MEI_JSON_TOOL_H
