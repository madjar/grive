/*
	grive: an GPL program to sync a local directory with Google Drive
	Copyright (C) 2012  Wan Wai Ho

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation version 2
	of the License.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#include "GdbmTest.hh"

#include "Assert.hh"

#include "util/Gdbm.hh"

#include <unistd.h>

namespace grut {

using namespace gr ;

GdbmTest::GdbmTest( )
{
}

void GdbmTest::Test( )
{
	{
		Gdbm db( "test.db" ) ;
		db.Set( "key", "value" ) ;
		GRUT_ASSERT_EQUAL( db.Get("key"), "value" ) ;
	}
	
	// re-open and verify
	Gdbm db( "test.db" ) ;
	GRUT_ASSERT_EQUAL( db.Get("key"), "value" ) ;
}

void GdbmTest::tearDown()
{
	unlink( "test.db" ) ;
}

} // end of namespace grut