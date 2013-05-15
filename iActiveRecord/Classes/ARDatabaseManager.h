//
//  ARDatabaseManager.m
//  iActiveRecord
//
//  Created by Alex Denisov on 10.01.12.
//  Copyright (c) 2012 okolodev.org. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>

@class ActiveRecord;

@interface ARDatabaseManager : NSObject
{
    @private
    sqlite3 *database;
    NSString *dbPath;
    NSString *dbName;
}

+ (void)disableMigrations;

- (void)createDatabase;
- (void)clearDatabase;

- (void)createTables;
- (void)createTable:(id)aRecord;
- (void)appendMigrations;

- (void)openConnection;
- (void)closeConnection;

- (NSArray *)tables;
- (NSArray *)describedTables;
- (NSArray *)columnsForTable:(NSString *)aTableName;

- (NSString *)tableName:(NSString *)modelName;
- (NSString *)documentsDirectory;
- (NSString *)cachesDirectory;

+ (instancetype)sharedInstance;

- (NSNumber *)insertRecord:(NSString *)aRecordName withSqlQuery:(const char *)anSqlQuery;
- (NSNumber *)getLastId:(NSString *)aRecordName;
- (NSArray *)allRecordsWithName:(NSString *)aName withSql:(NSString *)aSqlRequest;
- (NSArray *)joinedRecordsWithSql:(NSString *)aSqlRequest;
- (NSInteger)countOfRecordsWithName:(NSString *)aName;
- (NSInteger)functionResult:(NSString *)anSql;

- (NSInteger)executeFunction:(const char *)anSqlQuery;

+ (void)registerDatabase:(NSString *)aDatabaseName cachesDirectory:(BOOL)isCache;

- (void)skipBackupAttributeToFile:(NSURL *) url;

- (NSInteger)saveRecord:(ActiveRecord *)aRecord;
- (NSInteger)updateRecord:(ActiveRecord *)aRecord;
- (void)dropRecord:(ActiveRecord *)aRecord;
- (BOOL)executeSqlQuery:(const char *)anSqlQuery;

- (void)createIndices;
- (NSArray *)records;

@end
