//
// Created by logan on 1/11/18.
//

#include <mongocxx/exception/bulk_write_exception.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <iostream>
#include "AbstractMongoDBWriter.h"
#include "../Version.h"

using namespace plugin::OCMDev_MongoDBWriter;


AbstractMongoDBWriter::AbstractMongoDBWriter(std::shared_ptr<const mongocxx::client> client) :
        client{std::move(client)} {

}

bool AbstractMongoDBWriter::Init() {
    return true;
}

bool AbstractMongoDBWriter::Rotate() {
    return true;
}
