/*
 *  Copyright (c) 2018 IDscan.net
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  Support: support@idscan.net
 */

#include "libs/linux/include/DLParser.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

static const int KEY_LEN = 128;
static const unsigned char KEY[KEY_LEN]  =
{
	/** License key. **/
};

/** Test data. */
static const char* test_data = "%MNBURNSVILLE^HOMER J. SYMPSON^13225 MADRID RD^?\n\n;636038326007403611=12091991090106?\n\n%\" 55306      D               F064124   HZL                           X\"+H)     ?";

//----------------------------------------------------------------------------------------------------------------------
int main()
{
	//print version.
	cout << "v.:" << DLP_getMajorVersion() << "." << DLP_getMinorVersion() << "." << DLP_getBuildVersion() << endl;
	cout << "-----------------------------------------------------" << endl;

	//setup parser.
	DL_HANDLE parser = DLP_create();
	int err = DLP_setupKey(parser, KEY, KEY_LEN);
	if(err != 0)
		cout << "Invalid key: " << err << endl;

	//parse.
	err = DLP_parse(parser, test_data, strlen(test_data));

	//print result.
	unsigned int flag = FLAG_UNDEFINED;
	if(err == 0)
	{
		char result[256];

		err = DLP_getFullName(parser, result, 256);
		if(err == 0)
			cout << "Full Name: " << result << endl;

		err = DLP_getFirstName(parser, result, 256);
		if(err == 0)
			cout << "First name: " << result << endl;

		err = DLP_getLastName(parser, result, 256);
		if(err == 0)
			cout << "Last name: " << result << endl;

		err = DLP_getMiddleName(parser, result, 256);
		if(err == 0)
			cout << "Middle name: " << result << endl;

		err = DLP_getNameSuffix(parser, result, 256);
		if(err == 0)
			cout << "Name suffix: " << result << endl;

		err = DLP_getNamePrefix(parser, result, 256);
		if(err == 0)
			cout << "Name prefix: " << result << endl;

		err = DLP_getDocumentType(parser, result, 256);
		if(err == 0)
			cout << "Document type: " << result << endl;

		err = DLP_getCountryCode(parser, result, 256);
		if(err == 0)
			cout << "Country code: " << result << endl;

		err = DLP_getCountry(parser, result, 256);
		if(err == 0)
			cout << "Country: " << result << endl;

		err = DLP_getJurisdictionCode(parser, result, 256);
		if(err == 0)
			cout << "Jurisdiction code: " << result << endl;

		err = DLP_getIIN(parser, result, 256);
		if(err == 0)
			cout << "IIN: " << result << endl;

		err = DLP_getAddress1(parser, result, 256);
		if(err == 0)
			cout << "Address1: " << result << endl;

		err = DLP_getAddress2(parser, result, 256);
		if(err == 0)
			cout << "Address2: " << result << endl;

		err = DLP_getCity(parser, result, 256);
		if(err == 0)
			cout << "City: " << result << endl;

		err = DLP_getLicenseNumber(parser, result, 256);
		if(err == 0)
			cout << "License number: " << result << endl;

		err = DLP_getClassificationCode(parser, result, 256);
		if(err == 0)
			cout << "Classification code: " << result << endl;

		err = DLP_getRestrictionCode(parser, result, 256);
		if(err == 0)
			cout << "Restriction code: " << result << endl;

		err = DLP_getRestrictionCodeDescription(parser, result, 256);
		if(err == 0)
			cout << "Restriction code description: " << result << endl;

		err = DLP_getEndorsementsCode(parser, result, 256);
		if(err == 0)
			cout << "Endorsements code: " << result << endl;

		err = DLP_getEndorsementCodeDescription(parser, result, 256);
		if(err == 0)
			cout << "Endorsement code description: " << result << endl;

		err = DLP_getExpirationDate(parser, result, 256);
		if(err == 0)
			cout << "Expiration date: " << result << endl;

		err = DLP_getHAZMATExpDate(parser, result, 256);
		if(err == 0)
			cout << "HAZMATExpDate: " << result << endl;

		err = DLP_getBirthdate(parser, result, 256);
		if(err == 0)
			cout << "Birthdate: " << result << endl;

		err = DLP_getCardRevisionDate(parser, result, 256);
		if(err == 0)
			cout << "Card revision date: " << result << endl;

		err = DLP_getGender(parser, result, 256);
		if(err == 0)
			cout << "Gender: " << result << endl;

		err = DLP_getIssueDate(parser, result, 256);
		if(err == 0)
			cout << "Issue date: " << result << endl;

		err = DLP_getIssuedBy(parser, result, 256);
		if(err == 0)
			cout << "Issued by: " << result << endl;

		err = DLP_getPostalCode(parser, result, 256);
		if(err == 0)
			cout << "Postal code: " << result << endl;

		err = DLP_getEyeColor(parser, result, 256);
		if(err == 0)
			cout << "Eye color: " << result << endl;

		err = DLP_getRace(parser, result, 256);
		if(err == 0)
			cout << "Race: " << result << endl;

		err = DLP_getHairColor(parser, result, 256);
		if(err == 0)
			cout << "Hair color: " << result << endl;

		err = DLP_getHeight(parser, result, 256);
		if(err == 0)
			cout << "Height: " << result << endl;

		err = DLP_getWeightKG(parser, result, 256);
		if(err == 0)
			cout << "WeightKG: " << result << endl;

		err = DLP_getWeightLBS(parser, result, 256);
		if(err == 0)
			cout << "WeightLBS: " << result << endl;

		err = DLP_getComplianceType(parser, result, 256);
		if(err == 0)
			cout << "Compliance type: " << result << endl;

		err = DLP_getLimitedDurationDocument(parser, &flag);
		if(err == 0)
		{
			if(flag == FLAG_FALSE)
				cout << "Limited duration document: " << "No" << endl;
			else if(flag == FLAG_TRUE)
				cout << "Limited duration document: " << "Yes" << endl;
			else
				cout << "Limited duration document: " << "Undefined" << endl;
		}

		err = DLP_getOrganDonor(parser, &flag);
		if(err == 0)
		{
			if(flag == FLAG_FALSE)
				cout << "Organ donor: " << "No" << endl;
			else if(flag == FLAG_TRUE)
				cout << "Organ donor: " << "Yes" << endl;
			else
				cout << "Organ donor: " << "Undefined" << endl;
		}

		err = DLP_getVeteran(parser, &flag);
		if(err == 0)
		{
			if(flag == FLAG_FALSE)
				cout << "Veteran: " << "No" << endl;
			else if(flag == FLAG_TRUE)
				cout << "Veteran: " << "Yes" << endl;
			else
				cout << "Veteran: " << "Undefined" << endl;
		}

		err = DLP_getVehicleClassCode(parser, result, 256);
		if(err == 0)
			cout << "Vehicle class code: " << result << endl;

		err = DLP_getVehicleClassCodeDescription(parser, result, 256);
		if(err == 0)
			cout << "Vehicle class code description: " << result << endl;
	}
	else
		cout << "Error: " << err << endl;

	//free parser.
	DLP_delete(parser);

	return 0;
}
