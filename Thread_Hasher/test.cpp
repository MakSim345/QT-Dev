/*

void MainView::hashPressed()
{
    if ( ui->filenameEdit->text().isEmpty() )
        return;
    hasher->setFilename( ui->filenameEdit->text() );
    switch( ui->algorithmCombo->currentIndex() ) {
    case 0:
        hasher->setAlgorithm( QCryptographicHash::Sha1 );
        break;
    case 1:
        hasher->setAlgorithm( QCryptographicHash::Md5 );
        break;
    case 2:
        hasher->setAlgorithm( QCryptographicHash::Md4 );
        break;
    }
    ui->resultEdit->setText( QString("Working...") );
    hasher->start();
}

*/