/*  :ts=8 bk=0
 *
 * elkabong.c:	Defense against bug in filesystem version XX.XX.
 *		Nomenclature by Dave Platt.
 *
 * Description Of Bug:
 *	The Opera Filesystem (release versions 1.1 and earlier) have a bug
 *	that may cause synchronous I/O operations to jam, manifesting as a
 *	program lockup.  This bug is triggered by posting a high-priority
 *	asynchronous I/O request to a file, then AbortIO()ing it before it
 *	is processed.  The filesystem's internal priority level is not
 *	reset, and the next I/O request to arrive will be queued but not
 *	processed (since it is believed to be of lower priority).  However,
 *	it's arrival will trigger a recalculation of the internal priority
 *	level, and subsequent I/O requests will be processed, in addition to
 *	releasing and processing the jammed one.
 *
 * Workaround Theory Of Operation:
 *	This source module basically caters to the problem by posting an
 *	asynchronous CMD_READ request which is anticipated to jam.  Then a
 *	second synchronous request is issued which is expected to complete
 *	and un-jam the first.  All subsequent I/O should then behave
 *	normally.
 *
 *	Note:  The file must be open before this operation is done, since
 *	OpenDiskFile() may cause a read of the directory.  Such a read would
 *	jam, and OpenDiskFile() would not complete.
 *
 *	This operation is not performed on filesystem versions later than
 *	XX.XX.
 *
 * Leo L. Schwab					9311.07
 *  Minor sanity check on returned block size.		9311.16
 */

#include "types.h"
//#include "mem.h"
//#include "filesystem.h"
//#include "filefunctions.h"
//#include "filefolioglue.h"


/***************************************************************************
 * #defines
 */
#define	KABONG_VERSION		0	/*  WHAT ARE THESE REALLY???  */
#define	KABONG_REVISION		0

#define	DEFAULT_BLOCK_SIZE	2048


/***************************************************************************
 * Prototypes.
 */
int32 performElKabong(void *buf);
int32 initElKabong(char *filename);
void closeElKabong(void);
int elKabongRequired(void);



int32
performElKabong (void *buf)
{
  return 0;
}

int32
initElKabong (char *filename)
{
  return 0;
}


/***************************************************************************
 * Cleanup resources allocated to deal with filesystem bug.
 */
void
closeElKabong ()
{

}


/***************************************************************************
 * This routine checks the version and revision numbers of the filesystem
 * folio against the last version known to have the priority sorting bug.
 * If the version currently running is newer than this, the bug is presumed
 * to have been fixed, and FALSE is returned.  Else, TRUE is returned.
 */
int
elKabongRequired ()
{
  return false;
}
