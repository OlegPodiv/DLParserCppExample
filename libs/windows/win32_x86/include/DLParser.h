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

#ifndef _DLPARSER_H
#define _DLPARSER_H

#define FLAG_FALSE 0x00
#define FLAG_TRUE 0x01
#define FLAG_UNDEFINED 0x02

#define VALIDATION_STATUS_UNDEFINED    0x01
#define VALIDATION_STATUS_VALID        0x02
#define VALIDATION_STATUS_SUSPICIOUS   0x03

typedef void* DL_HANDLE;

#if defined(_WIN32) || defined(__WIN32__)
#  if defined(DLPEXPORTS) // add by CMake
#    define  DLPEXPORT __declspec(dllexport)
#  else
#    define  DLPEXPORT __declspec(dllimport)
#  endif // MyLibrary_EXPORTS
#else
# define DLPEXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern DLPEXPORT DL_HANDLE DLP_create();
extern DLPEXPORT void DLP_delete(DL_HANDLE handle);
extern DLPEXPORT int DLP_setupKey(DL_HANDLE handle, const unsigned char* key, int len);
extern DLPEXPORT int DLP_parse(DL_HANDLE handle, const char* data, int len);
extern DLPEXPORT int DLP_getFirstName(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getLastName(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getDocumentType(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getCountryCode(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getCountry(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getJurisdictionCode(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getIIN(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getMiddleName(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getNameSuffix(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getNamePrefix(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getFullName(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getAddress1(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getAddress2(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getCity(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getLicenseNumber(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getClassificationCode(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getRestrictionCode(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getRestrictionCodeDescription(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getEndorsementsCode(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getEndorsementCodeDescription(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getExpirationDate(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getHAZMATExpDate(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getBirthdate(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getCardRevisionDate(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getGender(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getIssueDate(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getIssuedBy(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getPostalCode(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getEyeColor(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getRace(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getHairColor(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getHeight(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getWeightKG(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getWeightLBS(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getComplianceType(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getLimitedDurationDocument(DL_HANDLE handle, unsigned int* flag);
extern DLPEXPORT int DLP_getOrganDonor(DL_HANDLE handle, unsigned int* flag);
extern DLPEXPORT int DLP_getVeteran(DL_HANDLE handle, unsigned int* flag);
extern DLPEXPORT int DLP_getVehicleClassCode(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getVehicleClassCodeDescription(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_validateDocumentId(DL_HANDLE handle, unsigned int* status);
extern DLPEXPORT int DLP_validateBarcode(DL_HANDLE handle, int columns, int rows, int ecl, unsigned int* status);
extern DLPEXPORT int DLP_validateJurisdictionCode(DL_HANDLE handle, unsigned int* status);
extern DLPEXPORT int DLP_getAamvaVersion(DL_HANDLE handle, char* out, int len);
extern DLPEXPORT int DLP_getMajorVersion();
extern DLPEXPORT int DLP_getMinorVersion();
extern DLPEXPORT int DLP_getBuildVersion();

#ifdef __cplusplus
}
#endif

#endif
