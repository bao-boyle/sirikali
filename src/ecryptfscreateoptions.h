/*
 *
 *  Copyright (c) 2017
 *  name : Francis Banyikwa
 *  email: mhogomchungu@gmail.com
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ECRYPTFSCREATEOPTIONS_H
#define ECRYPTFSCREATEOPTIONS_H

#include <functional>
#include <utility>

#include <QCloseEvent>
#include <QString>
#include <QDialog>

namespace Ui {
class ecryptfscreateoptions;
}

class ecryptfscreateoptions : public QDialog
{
	Q_OBJECT
public:
	struct Options{
		Options( const QStringList& s ) :
			options( s ),success( true )
		{
		}
		Options() : success( false )
		{
		}
		QStringList options ;
		bool success ;
	} ;
	static QString defaultCreateOptions()
	{
		return "key=passphrase,ecryptfs_key_bytes=32,ecryptfs_cipher=aes,ecryptfs_passthrough=n,ecryptfs_enable_filename_crypto=y" ;
	}
	static QString defaultMiniCreateOptions()
	{
		return "key=passphrase,ecryptfs_key_bytes=32,ecryptfs_cipher=aes" ;
	}
	static void instance( QWidget * parent,std::function< void( const Options& ) > function )
	{
                new ecryptfscreateoptions( parent,std::move( function ) ) ;
	}
	ecryptfscreateoptions( QWidget * parent,std::function< void( const Options& ) > ) ;
        ~ecryptfscreateoptions() ;
private slots:
	void pbSelectConfigPath() ;
	void pbOK() ;
	void pbCancel() ;
private:
	void HideUI( const Options& = Options() ) ;
	void closeEvent( QCloseEvent * ) ;
        Ui::ecryptfscreateoptions * m_ui ;
	std::function< void( const Options& ) > m_function ;
};

#endif // ECRYPTFSCREATEOPTIONS_H
