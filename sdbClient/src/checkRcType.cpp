#include "perl_sequoiadb.hpp"
/*
 * int rcNum
 *      -- sdb return rc number
 * int language
 *      -- choose print language, default is english
 *        1 english
 *        2 chinese
 */
int checkOutRcType(int rcNum, int language)
{
   if (rcNum != SDB_OK){
      printf ("rc = %d\n", rcNum) ;
      switch(rcNum)
      {

         case SDB_PMD_CON_INVALID_STATE :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid connection state") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非法连接状态") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_FNE :
            if (language == 1)
            {
               printf ("message : %s\n", "File Not Exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "文件不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLT_OBJ_NOT_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Object does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "对象已释放或不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_EDU_INVAL_STATUS :
            if (language == 1)
            {
               printf ("message : %s\n", "EDU status is not valid") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "引擎调度单元状态错误") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_IO :
            if (language == 1)
            {
               printf ("message : %s\n", "IO Exception") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "IO 错误") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CL_NOT_EXIST_ON_GROUP :
            if (language == 1)
            {
               printf ("message : %s\n", "The collection does not exists on the specified group") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "集合在指定复制组中不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_BUT_FAILED_ON_DATA :
            if (language == 1)
            {
               printf ("message : %s\n", "Failed to execute command on data node") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "在数据节点上执行命令失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DPS_TRANS_LOCK_INCOMPATIBLE :
            if (language == 1)
            {
               printf ("message : %s\n", "Incompatible lock") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "请求的事务锁不兼容") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_NOSPC :
            if (language == 1)
            {
               printf ("message : %s\n", "No space is left on disk") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "无剩余空间") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_QGM_MERGE_JOIN_EQONLY :
            if (language == 1)
            {
               printf ("message : %s\n", "Sort-Merge Join only supports equal predicates") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "合并连接只接受相等谓词") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_AUTH_AUTHORITY_FORBIDDEN :
            if (language == 1)
            {
               printf ("message : %s\n", "Authority is forbidden") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "没有权限") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_OM_TASK_NOT_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Task does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "无法找到后台任务信息") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CM_RUN_NODE_FAILED :
            if (language == 1)
            {
               printf ("message : %s\n", "Failed to start the node") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "启动节点失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_BACKUP_NOT_COMPLETE :
            if (language == 1)
            {
               printf ("message : %s\n", "Backup is not completed") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "备份未结束") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDBCM_FAIL :
            if (language == 1)
            {
               printf ("message : %s\n", "Remote cluster manager failed") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "远程集群管理失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_NODE_NOT_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Node does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "节点不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_PMD_SESSION_NOT_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Session ID does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "会话ID不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_TASK_ALREADY_FINISHED :
            if (language == 1)
            {
               printf ("message : %s\n", "Task is already finished") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "后台任务已完成") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_PMD_RG_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Replication group exists") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "复制组已存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_CONSULT_FAILED :
            if (language == 1)
            {
               printf ("message : %s\n", "Failed to negotiate") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "协商失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CAT_NO_GROUP_IN_DOMAIN :
            if (language == 1)
            {
               printf ("message : %s\n", "The domain is empty") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "域中不包含任何数据组") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_RTN_NO_PRIMARY_FOUND :
            if (language == 1)
            {
               printf ("message : %s\n", "No primary node was found") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "主节点不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_REPL_LOCAL_G_V_EXPIRED :
            if (language == 1)
            {
               printf ("message : %s\n", "Version is expired for local group") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "本地组版本信息过期") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DPS_FILE_SIZE_NOT_SAME :
            if (language == 1)
            {
               printf ("message : %s\n", "Size of DPS files are not the same") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "日志文件大小不统一") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_NOT_IN_REORG :
            if (language == 1)
            {
               printf ("message : %s\n", "Collection is not in reorg state") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "集合不为重组状态") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_SHARD_KEY_NOT_IN_UNIQUE_KEY :
            if (language == 1)
            {
               printf ("message : %s\n", "The unique index must include all fields in sharding key") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "唯一索引必须包含分区键中的所有字段") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_IXM_UNEXPECTED_STATUS :
            if (language == 1)
            {
               printf ("message : %s\n", "Unexpected index flag") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非预期索引状态") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_RTN_COORD_ONLY :
            if (language == 1)
            {
               printf ("message : %s\n", "The operation is for coord node only") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "该操作仅适用于协调节点") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_MIG_END_OF_QUEUE :
            if (language == 1)
            {
               printf ("message : %s\n", "End of queue") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "到达Queue队列结尾") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DPS_LSN_OUTOFRANGE :
            if (language == 1)
            {
               printf ("message : %s\n", "LSN is out of boundary") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "LSN超出边界") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_SU_OUTRANGE :
            if (language == 1)
            {
               printf ("message : %s\n", "Exceed max number of storage unit") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "存储空间数量已最大") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_COORD_QUERY_EOC :
            if (language == 1)
            {
               printf ("message : %s\n", "EOC message is received by coordinator node") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "协调节点接收到集合结尾消息") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_COORD_SPLIT_NO_SHDIDX :
            if (language == 1)
            {
               printf ("message : %s\n", "Unable to split because of no sharding index exists") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "集合不存在分区键索引,不能按百分比分区") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_COORD_SEND_MSG_FAILED :
            if (language == 1)
            {
               printf ("message : %s\n", "Failed to send the message") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "协调节点发送失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_APP_DISCONNECT :
            if (language == 1)
            {
               printf ("message : %s\n", "Application is disconnected") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "应用程序断开连接") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_IXM_NOSPC :
            if (language == 1)
            {
               printf ("message : %s\n", "No space can be found for index extent") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "索引块无空间") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DPS_TRANS_DIABLED :
            if (language == 1)
            {
               printf ("message : %s\n", "Transaction is disabled") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "未开启事务功能") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_QGM_AMBIGUOUS_FIELD :
            if (language == 1)
            {
               printf ("message : %s\n", "Column name is ambiguous") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "列名存在歧义") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_QGM_MAX_NUM_RECORD :
            if (language == 1)
            {
               printf ("message : %s\n", "Too many records to be inserted at once") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "插入操作尝试写入过多数据") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_IXM_KEY_NOTEXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Index key does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "索引键不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_RTN_INDEX_NOTEXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Index does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "索引不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_UTIL_CSV_FIELD_END :
            if (language == 1)
            {
               printf ("message : %s\n", "csv field line end") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "csv字段行结束") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLT_INVALID_HANDLE :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid handle") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非法句柄") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_QGM_MATCH_NONE :
            if (language == 1)
            {
               printf ("message : %s\n", "No records can be matched for the search condition") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "搜索条件无法满足任何条件的匹配") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DPS_CORRUPTED_LOG :
            if (language == 1)
            {
               printf ("message : %s\n", "Log record is corrupted") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "日志记录损坏") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_MIG_UNKNOW_FILE_TYPE :
            if (language == 1)
            {
               printf ("message : %s\n", "Unknown file type") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "未知的文件类型") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_MIG_IMP_BAD_RECORD :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid record is found during import") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "导入数据库时遇到无效的记录") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_OSS_NPIPE_DATA_TOO_BIG :
            if (language == 1)
            {
               printf ("message : %s\n", "Pipe buffer size is too small") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "命名管道请求发送的数据过大") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_BAR_DAMAGED_BK_FILE :
            if (language == 1)
            {
               printf ("message : %s\n", "Backup is corrupted") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "备份文件损坏") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_COORD_NODE_CAT_VER_OLD :
            if (language == 1)
            {
               printf ("message : %s\n", "Catalog version is expired on coordinator node") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "协调节点编目版本过旧") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_RTN_JOB_NOT_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "The specified job does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "指定任务不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_SU_NEED_REORG :
            if (language == 1)
            {
               printf ("message : %s\n", "Storage unit need reorg") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "存储单元需要重组") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CAT_NODE_NOT_FOUND :
            if (language == 1)
            {
               printf ("message : %s\n", "Requested node does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "请求节点不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_COLLECTION_LOAD :
            if (language == 1)
            {
               printf ("message : %s\n", "Collection is in loading status") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "集合已处于装载状态") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_LOB_NOT_OPEN :
            if (language == 1)
            {
               printf ("message : %s\n", "Lob does not open") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "大对象没有打开") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_MUTEX_TASK_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "The mutex task already exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "已存在互斥任务") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_INVALID_SU :
            if (language == 1)
            {
               printf ("message : %s\n", "Storage unit file is invalid") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非法存储单元") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_IXM_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Duplicate index name") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "同名索引已存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_REPLAY_LOG_FAILED :
            if (language == 1)
            {
               printf ("message : %s\n", "Failed to replay log") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "执行日志失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CAT_GRP_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Group already exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "分区组已经存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_REPL_GROUP_NOT_ACTIVE :
            if (language == 1)
            {
               printf ("message : %s\n", "Replication group is not activated") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "复制组未激活") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_NODE_BSFAULT :
            if (language == 1)
            {
               printf ("message : %s\n", "The node is not in normal status") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "节点处于业务故障状态") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CATA_RM_NODE_FORBIDDEN :
            if (language == 1)
            {
               printf ("message : %s\n", "Unable to remove the last node in a group") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "不能删除组内唯一的节点") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDBCM_SVC_RESTARTING :
            if (language == 1)
            {
               printf ("message : %s\n", "Service is restarting") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "服务正在重启") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_APP_FORCED :
            if (language == 1)
            {
               printf ("message : %s\n", "Application is forced") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "应用被强制退出") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_IXM_KEY_TOO_LARGE :
            if (language == 1)
            {
               printf ("message : %s\n", "Index key is too large") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "索引键过大") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_PMD_HELP_ONLY :
            if (language == 1)
            {
               printf ("message : %s\n", "Engine help argument is specified") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "引擎帮助参数") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_PMD_VERSION_ONLY :
            if (language == 1)
            {
               printf ("message : %s\n", "Engine version argument is specified") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "引擎版本参数") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_IXM_MULTIPLE_ARRAY :
            if (language == 1)
            {
               printf ("message : %s\n", "More than one fields are array type") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "超过一个索引字段包含数组") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_SYNC_FAILED :
            if (language == 1)
            {
               printf ("message : %s\n", "Failed to sync log") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "同步日志失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_RTN_DUPLICATE_FIELDNAME :
            if (language == 1)
            {
               printf ("message : %s\n", "Duplicate field name exists in the record") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "记录内含有重复字段名") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_REST_EHS :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid HTTP header") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "HTTP头结构错误") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DOMAIN_IS_OCCUPIED :
            if (language == 1)
            {
               printf ("message : %s\n", "Domain is not empty") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "域非空") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DPS_LOG_NOT_IN_FILE :
            if (language == 1)
            {
               printf ("message : %s\n", "Log was not found in log file") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "日志不在文件中") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_LOB_SEQUENCE_NOT_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "LOB sequence does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "大对象的序列不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_RTN_COORD_CACHE_EMPTY :
            if (language == 1)
            {
               printf ("message : %s\n", "Cache is empty on coordinator node") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "协调节点的缓存中无数据") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_NET_INVALID_HANDLE :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid net handle") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非法网络句柄") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_OSS_CCE :
            if (language == 1)
            {
               printf ("message : %s\n", "Character encoding errors") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "字符编码错误") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_BACKUP_HAS_ALREADY_START :
            if (language == 1)
            {
               printf ("message : %s\n", "Backup has already been started") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "备份已开始") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_PMD_RG_NOT_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Replication group does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "复制组不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_IXM_NOTEXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Index name does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "索引不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_OMA_DIFF_VER_AGT_IS_RUNNING :
            if (language == 1)
            {
               printf ("message : %s\n", "There is another OM Agent running with different version") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "不同版本的OMAgent已运行") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_TASK_HAS_CANCELED :
            if (language == 1)
            {
               printf ("message : %s\n", "Task is canceled") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "后台任务被取消") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DPS_FILE_NOT_RECOGNISE :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid DPS log file") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "日志文件不可识别") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_OM_TASK_ROLLBACK :
            if (language == 1)
            {
               printf ("message : %s\n", "Task is rolling back") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "后台任务正在回滚") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_NET_UPDATE_EXISTING_NODE :
            if (language == 1)
            {
               printf ("message : %s\n", "Updated information is same as old one") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "更新信息无变化") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDBCM_NODE_EXISTED :
            if (language == 1)
            {
               printf ("message : %s\n", "Node already exists") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "节点已存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_INCOMPATIBLE_MODE :
            if (language == 1)
            {
               printf ("message : %s\n", "Collection status is not compatible") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "集合状态不兼容") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_OUT_OF_BOUND :
            if (language == 1)
            {
               printf ("message : %s\n", "Stored procedure arguments are out of bound") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "存储过程参数越界") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_COL_DROPPED :
            if (language == 1)
            {
               printf ("message : %s\n", "Collection is dropped") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "集合已被删除") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_NET_ROUTE_NOT_FOUND :
            if (language == 1)
            {
               printf ("message : %s\n", "Route info does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "路由信息不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_SPT_EVAL_FAIL :
            if (language == 1)
            {
               printf ("message : %s\n", "Evalution failed with error") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "求值过程发生错误") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_INVALID_ROUTEID :
            if (language == 1)
            {
               printf ("message : %s\n", "RouteID is different from the local") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "RouteID与当前节点不一致") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_REORG_FILE_READONLY :
            if (language == 1)
            {
               printf ("message : %s\n", "Reorg file is in read only mode") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "重组文件为只读模式") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_UTIL_NOT_FIND_FIELD :
            if (language == 1)
            {
               printf ("message : %s\n", "Field is not found") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "未找到字段") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_NO_GROUP_INFO :
            if (language == 1)
            {
               printf ("message : %s\n", "The group info not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "该Group信息不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_RECORD_TOO_BIG :
            if (language == 1)
            {
               printf ("message : %s\n", "User record is too large") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "数据记录过大") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_GROUP_NAME_CONFLICT :
            if (language == 1)
            {
               printf ("message : %s\n", "Group name is conflict") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "Group名称冲突") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_INVALID_REORG_FILE :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid reorg file") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "重组文件不合法") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_UPDATE_SHARD_KEY :
            if (language == 1)
            {
               printf ("message : %s\n", "Sharding key cannot be updated") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "分区键不可被更新") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_APP_INTERRUPT :
            if (language == 1)
            {
               printf ("message : %s\n", "Application is interrupted") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "应用程序中断") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_PD_TRACE_IS_STARTED :
            if (language == 1)
            {
               printf ("message : %s\n", "Trace is already started") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "跟踪已经启动") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_NETWORK_CLOSE :
            if (language == 1)
            {
               printf ("message : %s\n", "Network is closed from remote") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "网络已从远程关闭") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_NET_CANNOT_LISTEN :
            if (language == 1)
            {
               printf ("message : %s\n", "Unable to listen the specified address") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "无法监听端口") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_ILL_RM_SUB_CL :
            if (language == 1)
            {
               printf ("message : %s\n", "Unable to remove collection partition") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非法删除集合分区") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CATA_FAILED_TO_CLEANUP :
            if (language == 1)
            {
               printf ("message : %s\n", "Unable to clean up catalog, manual cleanup may be required") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "需要手工完成清理工作") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDBCM_NODE_NOTEXISTED :
            if (language == 1)
            {
               printf ("message : %s\n", "Node does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "节点不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_DATA_NODE_CAT_VER_OLD :
            if (language == 1)
            {
               printf ("message : %s\n", "Catalog version is expired on data node") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "数据节点编目版本过旧") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_IXM_DROP_SHARD :
            if (language == 1)
            {
               printf ("message : %s\n", "$shard index can't be dropped") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "$shard索引不可被删除") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_COLLECTION_NOTSHARD :
            if (language == 1)
            {
               printf ("message : %s\n", "The collection is not sharded") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非分区集合") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_NO_MORE_TEMP :
            if (language == 1)
            {
               printf ("message : %s\n", "No more temp collections are avaliable") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "无可用临时集合") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_PERM :
            if (language == 1)
            {
               printf ("message : %s\n", "Permission Error") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "权限错误") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_FULL_SYNC :
            if (language == 1)
            {
               printf ("message : %s\n", "Full sync is in progress") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "节点间正在全量同步") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_RELINK_SUB_CL :
            if (language == 1)
            {
               printf ("message : %s\n", "Duplicated attach collection partition") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "重复关联集合分区") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_INVALID_MAIN_CL :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid partitioned-collection") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "无效的分区集合") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_RTN_SUBCONTEXT_CONFLICT :
            if (language == 1)
            {
               printf ("message : %s\n", "Sub context is conflict") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "子上下文冲突") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CAT_AUTH_FAILED :
            if (language == 1)
            {
               printf ("message : %s\n", "Catalog authentication failed") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "编目授权错误") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_NET_BROKEN_MSG :
            if (language == 1)
            {
               printf ("message : %s\n", "Broken msg") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "消息错误") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_GRP_NOT_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Group does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "分区组不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_INVALID_COLLECTION_S :
            if (language == 1)
            {
               printf ("message : %s\n", "Collection status is not valid") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "集合状态非法") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_BAR_BACKUP_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Backup already exists") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "该备份已存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_CONTEXT_IS_CLOSE :
            if (language == 1)
            {
               printf ("message : %s\n", "Context is closed") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "上下文已关闭") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_RTN_CMD_NO_SERVICE_AUTH :
            if (language == 1)
            {
               printf ("message : %s\n", "The command can't be run in the serice plane") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "该服务平面不能运行该命令") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_UNKNOWN_MESSAGE :
            if (language == 1)
            {
               printf ("message : %s\n", "Unknown mesage is received") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "未知消息") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_FE :
            if (language == 1)
            {
               printf ("message : %s\n", "File Exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "文件已存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_RTN_IN_BACKUP :
            if (language == 1)
            {
               printf ("message : %s\n", "Backup is in progress") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "备份正在进行") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_BAR_BACKUP_NOTEXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Backup does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "该备份不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_NOTP_AND_NODATA :
            if (language == 1)
            {
               printf ("message : %s\n", "Empty non-primary node") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非主空节点") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_LOCK_FAILED :
            if (language == 1)
            {
               printf ("message : %s\n", "Unable to lock") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "锁定失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_LOB_IS_NOT_AVAILABLE :
            if (language == 1)
            {
               printf ("message : %s\n", "LOB is not useable") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "大对象处于不可用状态") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_INVALIDARG :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid Argument") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非法输入参数") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_SYS :
            if (language == 1)
            {
               printf ("message : %s\n", "System error") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "系统错误") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_CS_NOTEXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Collection space does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "集合空间不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_NO_CATALOG_INFO :
            if (language == 1)
            {
               printf ("message : %s\n", "Catalog information does not exist on data node") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "数据节点不存在编目信息") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DPS_MOVE_FAILED :
            if (language == 1)
            {
               printf ("message : %s\n", "Failed to change DPS metadata") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "日志元数据移动失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_UNKNOW_MSG :
            if (language == 1)
            {
               printf ("message : %s\n", "Unknown message") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "未知消息") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_NO_SHARDINGKEY :
            if (language == 1)
            {
               printf ("message : %s\n", "There is no valid sharding-key defined") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "未包含合法的分区键字段") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_EMPTY_HEAP :
            if (language == 1)
            {
               printf ("message : %s\n", "Empty heap") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "空栈错误") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_TOO_MANY_OPEN_FD :
            if (language == 1)
            {
               printf ("message : %s\n", "Too many opened file description") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "文件描述符已达到上限") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_INVALID_SUB_CL :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid collection partition") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "无效的集合分区") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDBCM_STOP_PART :
            if (language == 1)
            {
               printf ("message : %s\n", "Remote database services have been stopped") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "远程引擎已部分被停止") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_CS_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Collection space already exists") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "集合空间已存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_INVALID_GROUP_NUM :
            if (language == 1)
            {
               printf ("message : %s\n", "Exceeds the max group size") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "超出最大组上限") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DPS_INVALID_LSN :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid LSN") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非法LSN编号") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_QGM_REPEAT_VAR_NAME :
            if (language == 1)
            {
               printf ("message : %s\n", "Repeated variable name") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "发现相同的变量名") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_UPDATE_CAT_FAILED :
            if (language == 1)
            {
               printf ("message : %s\n", "Failed to update catalog") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "更新协调节点失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_NOT_CONNECTED :
            if (language == 1)
            {
               printf ("message : %s\n", "Database is not connected") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "数据库未连接") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_TOO_MANY_TRACE_BP :
            if (language == 1)
            {
               printf ("message : %s\n", "Too many break points are specified") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "跟踪断点数量过多") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_IXM_REORG_DONE :
            if (language == 1)
            {
               printf ("message : %s\n", "Index page is reorged and the pos got different lchild") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "索引页重组后指定位置存在不同左子节点") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_PD_TRACE_HAS_NO_BUFFER :
            if (language == 1)
            {
               printf ("message : %s\n", "Trace buffer does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "跟踪缓冲区不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_UNEXPECTED_RESULT :
            if (language == 1)
            {
               printf ("message : %s\n", "Unexpected result received") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非预期结果") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_NOTEXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Collection does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "集合不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_COORD_RECREATE_CATALOG :
            if (language == 1)
            {
               printf ("message : %s\n", "Unable to create new catalog when there's already one exists") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "重复创建编目节点集群") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_QUIESCED :
            if (language == 1)
            {
               printf ("message : %s\n", "Database is quiesced") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "数据库已暂停") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CAT_TASK_NOTFOUND :
            if (language == 1)
            {
               printf ("message : %s\n", "The specified task does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "指定的任务不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DUPLICATED_SERVICE :
            if (language == 1)
            {
               printf ("message : %s\n", "Service already exists") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "服务已经存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_INIT_INDEX :
            if (language == 1)
            {
               printf ("message : %s\n", "Failed to initialize index") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "初始化索引失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CAT_RM_GRP_FORBIDDEN :
            if (language == 1)
            {
               printf ("message : %s\n", "Unable to remove non-empty group") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "无法删除存在非空组") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_SPLIT_PERCENT_LOWER :
            if (language == 1)
            {
               printf ("message : %s\n", "split percentage is lower then expected") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "分区百分比过低") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_UTIL_PARSE_JSON_INVALID :
            if (language == 1)
            {
               printf ("message : %s\n", "Failed to parse JSON file") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "解析json文件错误") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CM_CONFIG_CONFLICTS :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid node configuration") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "节点配置冲突") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_RTN_INVALID_PREDICATES :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid predicates") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非法谓词") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_SHARDING_NOT_HASH :
            if (language == 1)
            {
               printf ("message : %s\n", "Sharding type is not hash") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "分区类型不为哈稀") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_MAX_INDEX :
            if (language == 1)
            {
               printf ("message : %s\n", "Hit max number of index") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "最大数量索引已存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_BOUND_CONFLICT :
            if (language == 1)
            {
               printf ("message : %s\n", "New boundary is conflict with the existing boundary") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "新增区间与现有区间冲突") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_OM_PASSWD_CHANGE_SUGGUEST :
            if (language == 1)
            {
               printf ("message : %s\n", "Changing password is required") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "提示用户修改登陆密码") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_TASK_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "A task that already exists does not compatible with the new task") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "存在一个不兼容的任务") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_WAIT_SYNC_FAILED :
            if (language == 1)
            {
               printf ("message : %s\n", "Failed to wait for the sync operation from secondary nodes") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "等待备节点同步该操作失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_IXM_DROP_ID :
            if (language == 1)
            {
               printf ("message : %s\n", "$id index can't be dropped") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "$id索引不可被删除") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_VOTE_FAILED :
            if (language == 1)
            {
               printf ("message : %s\n", "Failed to vote for primary") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "投票失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_EOC :
            if (language == 1)
            {
               printf ("message : %s\n", "End of collection") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "集合结尾") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DATABASE_DOWN :
            if (language == 1)
            {
               printf ("message : %s\n", "Database is in shutdown status") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "数据库正在关闭") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_COORD_REMOTE_DISC :
            if (language == 1)
            {
               printf ("message : %s\n", "Remote-node is disconnected") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "远程节点断开连接") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_FMP_FUNC_NOT_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Stored procedure does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "存储过程不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_TIMEOUT :
            if (language == 1)
            {
               printf ("message : %s\n", "Timeout error") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "超时错误") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_OMA_TASK_FAIL :
            if (language == 1)
            {
               printf ("message : %s\n", "Task failed") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "后台任务失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_INVALID_FILE_TYPE :
            if (language == 1)
            {
               printf ("message : %s\n", "Unexpected file type specified") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非预期文件类型") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_REACHED_MAX_NODES :
            if (language == 1)
            {
               printf ("message : %s\n", "Hit the limit of maximum number of nodes in the cluster") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "节点数量达到上限") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_NOSPC :
            if (language == 1)
            {
               printf ("message : %s\n", "There's no space for DMS") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "存储单元中无可用空间") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_COORD_UNKNOWN_OP_REQ :
            if (language == 1)
            {
               printf ("message : %s\n", "Unknown request operation code") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "未知操作请求") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_IXM_DEDUP_BUF_MAX :
            if (language == 1)
            {
               printf ("message : %s\n", "Hit the max of dedup buffer") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "去重缓冲区已满") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_INVALID_PAGESIZE :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid page size") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非法数据页大小") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_CORRUPTED_EXTENT :
            if (language == 1)
            {
               printf ("message : %s\n", "DMS extent is corrupted") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "DMS数据块损坏") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_IXM_IDENTICAL_KEY :
            if (language == 1)
            {
               printf ("message : %s\n", "Two records get same key and rid") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "两条记录拥有同样的键值和RID") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_OOM :
            if (language == 1)
            {
               printf ("message : %s\n", "Out of Memory") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "无可用内存") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_REST_COMMON_UNKNOWN :
            if (language == 1)
            {
               printf ("message : %s\n", "Unknown REST command") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "未知的REST命令") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CURRENT_RECORD_DELETED :
            if (language == 1)
            {
               printf ("message : %s\n", "Current record has been removed") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "当前记录已被删除") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_CORRUPTED_SME :
            if (language == 1)
            {
               printf ("message : %s\n", "SME is corrupted") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "数据文件空间管理段错误") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_REBUILD_HAS_ALREADY_START :
            if (language == 1)
            {
               printf ("message : %s\n", "Database rebuild is already started") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "数据库重建已开始") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_SDB_VERSION_ONLY :
            if (language == 1)
            {
               printf ("message : %s\n", "Version argument is specified") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "客户端版本参数") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_OPTION_NOT_SUPPORT :
            if (language == 1)
            {
               printf ("message : %s\n", "Option is not supported yet") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "选项暂不支持") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_INCOMPATIBLE_VERSION :
            if (language == 1)
            {
               printf ("message : %s\n", "Incompatible version for storage unit") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "存储单元版本不兼容") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_EMPTY_GROUP :
            if (language == 1)
            {
               printf ("message : %s\n", "Group is empty") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "空分区组") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_RTN_MUTEX_JOB_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "The mutex job already exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "已经存在互斥任务") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CAT_NO_ADDR_LIST :
            if (language == 1)
            {
               printf ("message : %s\n", "There is no catalog address specified by user") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "编目节点地址未指定") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_RTN_EXPORTCONF_NOT_COMPLETE :
            if (language == 1)
            {
               printf ("message : %s\n", "Exporting configuration does not complete in all nodes") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "部分节点导出配置文件失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_NODE_NOT_ENOUGH :
            if (language == 1)
            {
               printf ("message : %s\n", "Not enough number of data nodes") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "数据节点不足") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_RTN_CONTEXT_NOTEXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Context does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "上下文不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_MULTI_SHARDING_KEY :
            if (language == 1)
            {
               printf ("message : %s\n", "The record contains more than one sharding key") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "记录包含超过一条分区键") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_NOT_PRIMARY :
            if (language == 1)
            {
               printf ("message : %s\n", "Node is not primary") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非主节点") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CAT_DOMAIN_NOT_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Domain does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "域不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_INVALID_MAIN_CL_TYPE :
            if (language == 1)
            {
               printf ("message : %s\n", "Sharding type must be ranged partition for partitioned-collection") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "分区集合的分区类型必须是范围分区") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_INVALID_REQID :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid request id is received") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非法请求ID") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_IXM_EOC :
            if (language == 1)
            {
               printf ("message : %s\n", "Hit end of index") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "索引结束") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_SECRETVALUE_NOT_SAME :
            if (language == 1)
            {
               printf ("message : %s\n", "Secret value for index file does not match with data file") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "索引文件特征值与数据文件不匹配") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_CONTEXT_IS_OPEN :
            if (language == 1)
            {
               printf ("message : %s\n", "Context is already opened") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "上下文已打开") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_INVALID_INDEXCB :
            if (language == 1)
            {
               printf ("message : %s\n", "Index is dropped or invalid") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "索引被删除或非法状态") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CATA_RM_CATA_FORBIDDEN :
            if (language == 1)
            {
               printf ("message : %s\n", "Unable to remove catalog for non-empty database") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "系统存在其它组时不能删除编目节点和组") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CAT_ASSIGN_NODE_FAILED :
            if (language == 1)
            {
               printf ("message : %s\n", "Failed to assign data node from coordinator node") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "协调节点分配数据节点失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_MIG_DATA_NON_UTF :
            if (language == 1)
            {
               printf ("message : %s\n", "Data is not in UTF-8 format") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "数据格式非UTF-8编码") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DPS_TRANS_DOING_ROLLBACK :
            if (language == 1)
            {
               printf ("message : %s\n", "Rollback operation is in progress") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "系统正在执行回滚操作") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CM_OP_NODE_FAILED :
            if (language == 1)
            {
               printf ("message : %s\n", "Failed to operate on node only") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "在节点上执行操作失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_IXM_REDEF :
            if (language == 1)
            {
               printf ("message : %s\n", "Redefine index") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "重复定义索引") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_HIT_HIGH_WATERMARK :
            if (language == 1)
            {
               printf ("message : %s\n", "Hit the high water mark") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "达到高水位") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DPS_LOG_FILE_OUT_OF_SIZE :
            if (language == 1)
            {
               printf ("message : %s\n", "Log file size is too large") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "日志文件超长") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_REPL_INVALID_GROUP_MEMBER :
            if (language == 1)
            {
               printf ("message : %s\n", "Node does not belong to the group") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非法复制组成员") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_MAIN_CL_OP_ERR :
            if (language == 1)
            {
               printf ("message : %s\n", "Operation is not supported on partitioned-collection") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "分区集合不支持此操作") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CORRUPTED_RECORD :
            if (language == 1)
            {
               printf ("message : %s\n", "Corrupted record") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "记录损坏") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_FIELD_NOT_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "The parameter field does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "指定参数字段不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CAT_GROUP_NOT_IN_DOMAIN :
            if (language == 1)
            {
               printf ("message : %s\n", "Group is not in domain") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "组不存在指定域中") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CAT_GRP_NOT_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Group does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "分区组不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_INVALIDSIZE :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid size") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非法长度") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_INTERRUPT :
            if (language == 1)
            {
               printf ("message : %s\n", "Interrupt") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "中断错误") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_PHP_DRIVER_INTERNAL_ERROR :
            if (language == 1)
            {
               printf ("message : %s\n", "PHP driver internal error") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "PHP驱动内部错误") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDBCM_SVC_STARTING :
            if (language == 1)
            {
               printf ("message : %s\n", "Service is starting") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "服务正在启动") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_NET_SEND_ERR :
            if (language == 1)
            {
               printf ("message : %s\n", "Failed to send") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "发送失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_EOF :
            if (language == 1)
            {
               printf ("message : %s\n", "Hit end of file") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "文件结束") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_CS_DELETING :
            if (language == 1)
            {
               printf ("message : %s\n", "Dropping the collection space is in progress") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "正在删除CS") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_PMD_FORCE_SYSTEM_EDU :
            if (language == 1)
            {
               printf ("message : %s\n", "System EDU cannot be forced") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "系统引擎调度单元不可被终止") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CAT_CORRUPTION :
            if (language == 1)
            {
               printf ("message : %s\n", "The catalog information is corrupted") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "系统集合数据损坏") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_NET_NOT_CONNECT :
            if (language == 1)
            {
               printf ("message : %s\n", "Connection does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "连接不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DPS_LOG_NOT_IN_BUF :
            if (language == 1)
            {
               printf ("message : %s\n", "Log was not found in log buf") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "日志不在缓冲区内") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CAT_DOMAIN_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Domain already exists") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "域已存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_SDB_HELP_ONLY :
            if (language == 1)
            {
               printf ("message : %s\n", "Help argument is specified") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "客户端帮助参数") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CAT_NO_NODEGROUP_INFO :
            if (language == 1)
            {
               printf ("message : %s\n", "Unable to find the group information on catalog") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "节点组信息不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_NETWORK :
            if (language == 1)
            {
               printf ("message : %s\n", "Network error") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "网络错误") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_RTN_IN_REBUILD :
            if (language == 1)
            {
               printf ("message : %s\n", "Database rebuild is in progress") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "数据库重建正在进行") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_RECORD_NOTEXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Record does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "数据记录不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_NET_ALREADY_LISTENED :
            if (language == 1)
            {
               printf ("message : %s\n", "Listening port is already occupied") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "监听端口已被占用") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_UTIL_PARSE_CSV_INVALID :
            if (language == 1)
            {
               printf ("message : %s\n", "Failed to parse CSV file") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "解析CSV文件错误") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_RECORD_INVALID :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid record") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非法记录") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_INVALID_SHARDINGKEY :
            if (language == 1)
            {
               printf ("message : %s\n", "The record does not contains valid sharding key") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "记录不包含合法的分区键") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_BUFFER_FULL :
            if (language == 1)
            {
               printf ("message : %s\n", "Buffer array is full") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "缓冲区数组满") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_RTN_CMD_NO_NODE_AUTH :
            if (language == 1)
            {
               printf ("message : %s\n", "The command can't be run in the node") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "该节点不能运行该命令") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_COORD_NOT_ALL_DONE :
            if (language == 1)
            {
               printf ("message : %s\n", "One or more nodes did not complete successfully") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "部分节点未返回成功") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_COOR_NO_NODEGROUP_INFO :
            if (language == 1)
            {
               printf ("message : %s\n", "Group information cannot be found on coordinator node") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "协调节点无法找到本地节点组信息") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDBCM_SVC_STARTED :
            if (language == 1)
            {
               printf ("message : %s\n", "Service has been started") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "服务已经启动") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_NODE_INFO_EXPIRED :
            if (language == 1)
            {
               printf ("message : %s\n", "Node information is expired") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "节点信息过期") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_STATE_NOT_COMPATIBLE :
            if (language == 1)
            {
               printf ("message : %s\n", "DMS state is not compatible with current command") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "DMS状态与当前请求不兼容") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_PD_TRACE_FILE_INVALID :
            if (language == 1)
            {
               printf ("message : %s\n", "Trace file is not valid") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "跟踪文件不合法") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DRIVER_DS_RUNOUT :
            if (language == 1)
            {
               printf ("message : %s\n", "Data source is running out of connection pool") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "客户端连接池已满") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDBCM_NODE_IS_IN_RESTORING :
            if (language == 1)
            {
               printf ("message : %s\n", "Node is in restoring") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "节点正在启动恢复") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_RTN_INVALID_HINT :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid hint") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "索引提示非法") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_BOUND_INVALID :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid boundary for the shard") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "新增区间不合法") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_NET_CANNOT_CONNECT :
            if (language == 1)
            {
               printf ("message : %s\n", "Unable to connect to the specified address") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "无法连接到指定地址") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_REST_RECV_SIZE :
            if (language == 1)
            {
               printf ("message : %s\n", "The data received by REST is larger than the max size") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "REST接收的数据大小超过最大值") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_BUSY_PREFETCHER :
            if (language == 1)
            {
               printf ("message : %s\n", "All prefetchers are busy") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "预取器繁忙") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_IXM_DUP_KEY :
            if (language == 1)
            {
               printf ("message : %s\n", "Duplicate key exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "索引键已存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CLS_BAD_SPLIT_KEY :
            if (language == 1)
            {
               printf ("message : %s\n", "The split key is not valid or not in the source group") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "指定的分区键不合法或不在源节点范围内") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DPS_TRANS_NO_TRANS :
            if (language == 1)
            {
               printf ("message : %s\n", "Invalid transactional operation") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "无效的事务操作") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_DELETING :
            if (language == 1)
            {
               printf ("message : %s\n", "Record is deleted") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "记录已被删除") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DRIVER_BSON_ERROR :
            if (language == 1)
            {
               printf ("message : %s\n", "Failed to build bson object") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "构建bson失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_INVALIDPATH :
            if (language == 1)
            {
               printf ("message : %s\n", "Given path is not valid") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "非法路径错误") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_LOB_HAS_OPEN :
            if (language == 1)
            {
               printf ("message : %s\n", "Lob has been open") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "大对象已打开") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_REPL_REMOTE_G_V_EXPIRED :
            if (language == 1)
            {
               printf ("message : %s\n", "Version is expired for remote group") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "远程组版本信息过期") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_COORD_QUERY_FAILED :
            if (language == 1)
            {
               printf ("message : %s\n", "Failed to query on coord node") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "协调节点查询失败") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_NET_TIMER_ID_NOT_FOUND :
            if (language == 1)
            {
               printf ("message : %s\n", "Timer does not exist") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "定时器标示不存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_CAT_NO_MATCH_CATALOG :
            if (language == 1)
            {
               printf ("message : %s\n", "Unable to find the catalog information") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "无法找到匹配的协调节点信息") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_OVF_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Remote overflow record exists") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "溢出记录已存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DMS_EXIST :
            if (language == 1)
            {
               printf ("message : %s\n", "Collection already exists") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "集合已存在") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_LOAD_ROLLBACK :
            if (language == 1)
            {
               printf ("message : %s\n", "Rolling back load operation") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "进行装载操作回滚") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_DPS_TRANS_APPEND_TO_WAIT :
            if (language == 1)
            {
               printf ("message : %s\n", "Append to lock-wait-queue") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "加入锁的等待队列中") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_OSS_NORES :
            if (language == 1)
            {
               printf ("message : %s\n", "No resource is avaliable") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "无可用资源") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

         case SDB_SQL_SYNTAX_ERROR :
            if (language == 1)
            {
               printf ("message : %s\n", "SQL syntax error") ;
            }
            else if (language == 2)
            {
               printf ("message : %s\n", "SQL中存在语法错误") ;
            }
            croak ("%d", rcNum) ; 
            break ;   

      }
   }
   return SDB_OK ;
   
}
