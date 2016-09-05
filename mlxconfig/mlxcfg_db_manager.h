/*
 * Copyright (C) Jan 2013 Mellanox Technologies Ltd. All rights reserved.
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, available from the file
 * COPYING in the main directory of this source tree, or the
 * OpenIB.org BSD license below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *
 * MlxconfigFactory.h
 *
 *  Created on: May 24, 2016
 *      Author: ahmads
 */

#ifndef MLXCFG_FACTORY_H_
#define MLXCFG_FACTORY_H_

#include <vector>
#include <exception>

#include "mlxcfg_tlv.h"
#include "mlxcfg_param.h"
#include <ext_libs/sqlite/sqlite3.h>

class MlxcfgDBManager {

private:
    std::string _dbName;
    sqlite3* _db;
    /*static TLVsTableSchema tlvsTableSchema;

    class TLVsTableSchema {

    };*/

    static int selectTLVCallBack(void *, int, char **, char **);
    static int selectParamCallBack(void *, int, char **, char **);
    static int selectParamByMlxconfigNameCallBack(void *, int, char **, char **);
    void openDB();
    inline bool isDBFileExists(const std::string& name);
    TLVConf* fetchTLVByName(std::string n, u_int8_t port);
    TLVConf* fetchTLVByIndexAndClass(u_int32_t id, TLVClass c);
public:
    MlxcfgDBManager(std::string dbName);
    ~MlxcfgDBManager();
    bool _isAllFetched;
    std::vector<TLVConf*> fetchedTLVs;
    std::vector<Param*> fetchedParams;
    void getAllTLVs();
    TLVConf* getTLVByNameAux(std::string n, u_int8_t port);
    TLVConf* getTLVByIndexAndClassAux(u_int32_t id, TLVClass c);
    TLVConf* getTLVByName(std::string n, u_int8_t port);
    TLVConf* getTLVByParamMlxconfigName(std::string n);
    TLVConf* getTLVByIndexAndClass(u_int32_t id, TLVClass c);

};

#endif
