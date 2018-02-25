#pragma once

#include <unordered_map>
#include <string>
#include <memory>


namespace NIRTree {

    typedef std::string CLabel;

    class CLabelHandler {
    public:
        static CLabelHandler &GetInstance() {
            static CLabelHandler instance;
            return instance;
        }

        const std::shared_ptr<const CLabel> GetLabel(const std::string &src);

        CLabelHandler(CLabelHandler const &) = delete;

        void operator=(CLabelHandler const &)  = delete;

    private:
        CLabelHandler() = default;

        std::unordered_map<std::string, const std::shared_ptr<const CLabel>> stringToLabel;
    };
}