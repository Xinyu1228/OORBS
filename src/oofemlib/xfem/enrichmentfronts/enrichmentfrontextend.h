/*
 *
 *                 #####    #####   ######  ######  ###   ###
 *               ##   ##  ##   ##  ##      ##      ## ### ##
 *              ##   ##  ##   ##  ####    ####    ##  #  ##
 *             ##   ##  ##   ##  ##      ##      ##     ##
 *            ##   ##  ##   ##  ##      ##      ##     ##
 *            #####    #####   ##      ######  ##     ##
 *
 *
 *             OOFEM : Object Oriented Finite Element Code
 *
 *               Copyright (C) 1993 - 2013   Borek Patzak
 *
 *
 *
 *       Czech Technical University, Faculty of Civil Engineering,
 *   Department of Structural Mechanics, 166 29 Prague, Czech Republic
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef ENRICHMENTFRONTEXTEND_H_
#define ENRICHMENTFRONTEXTEND_H_

#define _IFT_EnrFrontExtend_Name "enrfrontextend"

#include "oofemcfg.h"
#include <vector>
#include "inputrecord.h"
#include "xfem/enrichmentfronts/enrichmentfront.h"
#include "xfem/tipinfo.h"

namespace oofem {

class XfemManager;
class DofManager;
class FloatArray;
class InputRecord;
class DynamicInputRecord;

/**
 * EnrFrontExtend
 * @author Erik Svenning
 * @date Feb 14, 2014
 */
class OOFEM_EXPORT EnrFrontExtend : public EnrichmentFront
{
public:
    EnrFrontExtend() { };
    virtual ~EnrFrontExtend() { };

    virtual void MarkNodesAsFront(std :: vector< int > &ioNodeEnrMarker, XfemManager &ixFemMan, const std :: vector< double > &iLevelSetNormalDir, const std :: vector< double > &iLevelSetTangDir, const std :: vector< TipInfo > &iTipInfo);

    // No special tip enrichments are applied with this model,
    // it only modifies the set of nodes subject to bulk enrichment.
    virtual int  giveNumEnrichments(const DofManager &iDMan) const { return 0; }
    virtual int  giveMaxNumEnrichments() const { return 0; }

    // Evaluate the enrichment function and its derivative in front nodes.
    virtual void evaluateEnrFuncAt(std :: vector< double > &oEnrFunc, const FloatArray &iPos, const double &iLevelSet, int iNodeInd) const { };
    virtual void evaluateEnrFuncDerivAt(std :: vector< FloatArray > &oEnrFuncDeriv, const FloatArray &iPos, const double &iLevelSet, const FloatArray &iGradLevelSet, int iNodeInd) const { };
    virtual void evaluateEnrFuncJumps(std :: vector< double > &oEnrFuncJumps) const { };


    virtual const char *giveClassName() const { return "EnrFrontExtend"; }
    virtual const char *giveInputRecordName() const { return _IFT_EnrFrontExtend_Name; }

    virtual IRResultType initializeFrom(InputRecord *ir) { return IRRT_OK; }
    virtual void giveInputRecord(DynamicInputRecord &input);
};

} // end namespace oofem




#endif /* ENRICHMENTFRONTEXTEND_H_ */