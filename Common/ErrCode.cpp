#include "ErrCode.hpp"
std::string ToString (int err)
{
    switch (err) {
        case SUCCESS :
            return "SUCCESS";
        case INDEX_ALREADY_EXIST :
            return "same key already exist";
        case INDEX_FULL :
            return "index full";
        case FLUSH_FAILED :
            return "flush index failed";
        case INDEX_NOT_EXIST :
            return "index not exist";
        case OPEN_FILE_FAILED :
            return "open file failed";
        case FILE_DATA_BROKEN :
            return "file data broken";
        case WRITE_INDEX_FILE_FAILED :
            return "write index failed";
        case READ_INDEX_FILE_FAILED :
            return "read index failed";
        case WRITE_UNIT_FILE_FAILED:
            return "write unit failed";
        case READ_UNIT_FILE_FAILED:
            return "read unit file failed"; 
        case LIST_INDEX_ERROR:
            return "list index failed";

        default : {
            return "unknown error";
        }
    }
}

