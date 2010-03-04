#include "config.h"
#include "gnc/Session.hpp"
#include "gnc/Book.hpp"

// Explicit instantiation to check for compiler errors in the template
template class gnc::WeakPointer< QofSession >;


namespace gnc
{

Book Session::get_book () const
{
    return Book(qof_session_get_book(get()));
}


#define TYPE_TO_STR(tstr, desc) tstr : return std::make_pair<QString,QString>(QString::fromUtf8(#tstr), QString::fromUtf8(desc))

std::pair<QString, QString> errorToStringPair(QofBackendError err)
{
    switch (err)
    {
    case TYPE_TO_STR(ERR_BACKEND_NO_ERR, "No Error");
    case TYPE_TO_STR(ERR_BACKEND_NO_HANDLER, "no backend handler found for this access method (ENOSYS)");
    case TYPE_TO_STR(ERR_BACKEND_NO_BACKEND, "Backend * pointer was unexpectedly null");
    case TYPE_TO_STR(ERR_BACKEND_BAD_URL, "Can't parse url");
    case TYPE_TO_STR(ERR_BACKEND_NO_SUCH_DB, "the named database doesn't exist");
    case TYPE_TO_STR(ERR_BACKEND_CANT_CONNECT, "bad dbname/login/passwd or network failure");
    case TYPE_TO_STR(ERR_BACKEND_CONN_LOST, "Lost connection to server");
    case TYPE_TO_STR(ERR_BACKEND_LOCKED, "in use by another user (ETXTBSY)");
    case TYPE_TO_STR(ERR_BACKEND_READONLY, "cannot write to file/directory");
    case TYPE_TO_STR(ERR_BACKEND_TOO_NEW, "file/db version newer than what we can read");
    case TYPE_TO_STR(ERR_BACKEND_DATA_CORRUPT, "data in db is corrupt");
    case TYPE_TO_STR(ERR_BACKEND_SERVER_ERR, "error in response from server");
    case TYPE_TO_STR(ERR_BACKEND_ALLOC, "internal memory allocation failure");
    case TYPE_TO_STR(ERR_BACKEND_PERM, "user login successful, but no permissions to access the desired object");
    case TYPE_TO_STR(ERR_BACKEND_MODIFIED, "commit of object update failed because another user has modified the object");
    case TYPE_TO_STR(ERR_BACKEND_MOD_DESTROY, "commit of object update failed because another user has deleted the object");
    case TYPE_TO_STR(ERR_BACKEND_MISC, "undetermined error");
    case TYPE_TO_STR(ERR_QSF_INVALID_OBJ, "The QSF object failed to validate against the QSF object schema");
    case TYPE_TO_STR(ERR_QSF_INVALID_MAP, "The QSF map failed to validate against the QSF map schema");
    case TYPE_TO_STR(ERR_QSF_BAD_OBJ_GUID, "The QSF object contains one or more invalid GUIDs.");
    case TYPE_TO_STR(ERR_QSF_BAD_QOF_VERSION, "QSF map or object doesn't match the current QOF_OBJECT_VERSION.");
    case TYPE_TO_STR(ERR_QSF_BAD_MAP, "The selected map validates but is unusable.");
    case TYPE_TO_STR(ERR_QSF_NO_MAP, "The QSF object file was loaded without a map");
    case TYPE_TO_STR(ERR_QSF_WRONG_MAP, "The selected map validates but is for different objects.");
    case TYPE_TO_STR(ERR_QSF_MAP_NOT_OBJ, "Selected file is a QSF map and cannot be opened as a QSF object");
    case TYPE_TO_STR(ERR_QSF_OVERFLOW, "EOVERFLOW - generated by strtol or strtoll.");
    case TYPE_TO_STR(ERR_QSF_OPEN_NOT_MERGE, "QSF files cannot be opened alone. The data must be merged.");
    case TYPE_TO_STR(ERR_FILEIO_FILE_BAD_READ, "read failed or file prematurely truncated");
    case TYPE_TO_STR(ERR_FILEIO_FILE_EMPTY, "file exists, is readable, but is empty");
    case TYPE_TO_STR(ERR_FILEIO_FILE_LOCKERR, "mangled locks (unspecified error)");
    case TYPE_TO_STR(ERR_FILEIO_FILE_NOT_FOUND, "not found / no such file");
    case TYPE_TO_STR(ERR_FILEIO_FILE_TOO_OLD, "file version so old we can't read it");
    case TYPE_TO_STR(ERR_FILEIO_UNKNOWN_FILE_TYPE, "didn't recognize the file type");
    case TYPE_TO_STR(ERR_FILEIO_PARSE_ERROR, "couldn't parse the data in the file");
    case TYPE_TO_STR(ERR_FILEIO_BACKUP_ERROR, "couldn't make a backup of the file");
    case TYPE_TO_STR(ERR_FILEIO_WRITE_ERROR, "couldn't write to the file");
    case TYPE_TO_STR(ERR_FILEIO_READ_ERROR, "Could not open the file for reading.");
    case TYPE_TO_STR(ERR_FILEIO_NO_ENCODING, "file does not specify encoding");
    case TYPE_TO_STR(ERR_FILEIO_FILE_EACCES, "No read access permission for the given file");
    case TYPE_TO_STR(ERR_NETIO_SHORT_READ, "not enough bytes received");
    case TYPE_TO_STR(ERR_NETIO_WRONG_CONTENT_TYPE, "wrong kind of server, wrong data served");
    case TYPE_TO_STR(ERR_NETIO_NOT_GNCXML, "whatever it is, we can't parse it.");
    case TYPE_TO_STR(ERR_SQL_MISSING_DATA, "database doesn't contain expected data");
    case TYPE_TO_STR(ERR_SQL_DB_TOO_OLD, "database is old and needs upgrading");
    case TYPE_TO_STR(ERR_SQL_DB_BUSY, "database is busy, cannot upgrade version");
    case TYPE_TO_STR(ERR_RPC_HOST_UNK, "Host unknown");
    case TYPE_TO_STR(ERR_RPC_CANT_BIND, "can't bind to address");
    case TYPE_TO_STR(ERR_RPC_CANT_ACCEPT, "can't accept connection");
    case TYPE_TO_STR(ERR_RPC_NO_CONNECTION, "no connection to server");
    case TYPE_TO_STR(ERR_RPC_BAD_VERSION, "RPC Version Mismatch");
    case TYPE_TO_STR(ERR_RPC_FAILED, "Operation failed");
    case TYPE_TO_STR(ERR_RPC_NOT_ADDED, "object not added");
    default:
        assert(0); // must not be reached
        return std::make_pair("Unknown", "Unknown");
    }
}

} // END namespace gnc