/* omdatabaseinternal.h: Class definition for OmDatabaseGroup::Internal
 *
 * ----START-LICENCE----
 * Copyright 1999,2000 Dialog Corporation
 * 
 * This program is free software; you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 * -----END-LICENCE-----
 */

#ifndef OM_HGUARD_OMDATABASEINTERNAL_H
#define OM_HGUARD_OMDATABASEINTERNAL_H

#include <vector>

#include <om/omenquire.h>
#include "omlocks.h"
#include "omrefcnt.h"
#include "database_builder.h"
#include "multi_database.h"

//////////////////////////////////
// Internals of OmDatabaseGroup //
//////////////////////////////////

/** The implementation for OmDatabaseGroup.
 */
class OmDatabaseGroup::Internal {
    public:
	friend class OmDatabaseGroup::InternalInterface;

	Internal() {}
	Internal(const Internal &other)
		: params(other.params), mutex() {}

	/** The parameters to be used to create the database.
	 */
	vector<DatabaseBuilderParams> params;

	/** Mutex to protect access to these internals.
	 */
	OmLock mutex;

	/** Add a database to the group, based on parameters.
	 */
	void add_database(const string & type,
			  const vector<string> & paths);

	/** Get a reference counted pointer to a MultiDatabase
	 *  containing all the entries in the group.
	 */
	OmRefCntPtr<MultiDatabase> get_multi_database();
};

#endif // OM_HGUARD_OMDATABASEINTERNAL_H
