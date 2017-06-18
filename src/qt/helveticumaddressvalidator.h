// Copyright (c) 2011-2014 The Helveticum Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef HELVETICUM_QT_HELVETICUMADDRESSVALIDATOR_H
#define HELVETICUM_QT_HELVETICUMADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class HelveticumAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit HelveticumAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Helveticum address widget validator, checks for a valid helveticum address.
 */
class HelveticumAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit HelveticumAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // HELVETICUM_QT_HELVETICUMADDRESSVALIDATOR_H
