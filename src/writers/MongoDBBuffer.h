//
// Created by logan on 1/11/18.
//

#ifndef BROPLUGINMONGODBWRITER_MONGOBUFFER_H
#define BROPLUGINMONGODBWRITER_MONGOBUFFER_H
#include <string>
#include <vector>
#include <bsoncxx/document/value.hpp>
#include <mongocxx/client.hpp>
#include <logging/WriterBackend.h>

namespace plugin {
    namespace ActiveCM_MongoDBWriter {
        class MongoDBBuffer {
        public:
            MongoDBBuffer(std::string targetDB, std::string targetCollection);

            bool Empty();

            bool Full();

            void Write(bsoncxx::document::value document);

            bool Flush(const mongocxx::client &client);

            static const unsigned long BUFFER_SIZE = 1000;
            std::string targetDB;
            std::string targetCollection;
            std::vector<bsoncxx::document::value> documents;
        private:
            mongocxx::options::insert insertOptions;
            Reporter reporter;
        };
    }
}


#endif //BROPLUGINMONGODBWRITER_MONGOBUFFER_H
