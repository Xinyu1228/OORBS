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

#ifndef polyset_h
#define polyset_h

#include "set.h"

/*
#include "femcmpnn.h"
#include "intarray.h"
#include <list>
*/

namespace oofem {
///@name Input fields for Set
//@{
#define _IFT_Polyset_Name "polyset"
#define _IFT_Polyset_rtetClonesOfGeoNodes "rtetclonesofnodes" ///< List of clone-nodes of rigid tet from input mesh nodes
#define _IFT_Polyset_rtetCellsOfGeoNodes  "rtetcellsofnodes"  ///< List of center-nodes of rigid tet from input mesh nodes
#define _IFT_Polyset_minAssociations      "minassociations"  ///< Minimum number of associated nodes to include in the set
/*
#define _IFT_Set_nodes "nodes" ///< List of specific node indices.
#define _IFT_Set_allNodes "allnodes" ///< List of specific node indices.
#define _IFT_Set_nodeRanges "noderanges" ///< List of node index ranges.
#define _IFT_Set_elements "elements" ///< List of specific element indices.
#define _IFT_Set_allElements "allelements" ///< Will generate a list of all elements in the domain.
#define _IFT_Set_elementRanges "elementranges" ///< List of element index ranges.
#define _IFT_Set_elementBoundaries "elementboundaries" ///< Interleaved array of element index + boundary number
#define _IFT_Set_elementEdges "elementedges" ///< Interleaved array of element index + edge number
#define _IFT_Set_elementSurfaces "elementsurfaces" ///< Interleaved array of element index + surface number
*/
//@}

/*
class EntityRenumberingFunction;
class Range;
*/

/**
 * Extension of the 'set' class for accessing polyhedral shapes components.
 * Currently developed for Rigid Bodies, with potential to be extended to lattice models.
 * @author Saeid Mehrpay
 */
class OOFEM_EXPORT Polyset : public Set
{
protected:
/*
    IntArray elements; ///< Element numbers.
    mutable bool mElementListIsSorted;
    mutable IntArray mElementsSorted;
    IntArray elementBoundaries; /// Element numbers + boundary numbers (interleaved).
    IntArray elementEdges; /// Element numbers + edge numbers (interleaved).
    IntArray elementSurfaces; /// Element numbers + surface numbers (interleaved).
    IntArray nodes; ///< Node numbers.
    IntArray totalNodes; ///< Unique set of nodes (computed).
*/

public:
    /**
     * Constructor
     * @param n Polyset number.
     * @param d Domain to which component belongs to.
     */
    Polyset(int n, Domain * d) : Set(n, d) { }
    virtual ~Polyset() { }

    void initializeFrom(InputRecord &ir) override;
    void giveInputRecord(DynamicInputRecord &input) override;

#if 0
    /**
     * Returns list of elements within set.
     * @return List of element numbers.
     */
    const IntArray &giveElementList();
    /**
     * Returns list of element boundaries within set.
     * Boundaries are either surfaces (3d), edges (2d), or corners (1d).
     * @return List of element boundaries.
     */
    const IntArray &giveBoundaryList();
    /**
     * Returns list of element edges within set (must be edges of 3D elements).
     * @return List of element edges.
     */
    const IntArray &giveEdgeList();
    /**
     * Returns list of element surfaces within set 
     * @return List of element surfaces.
     */
    const IntArray &giveSurfaceList();
    /**
     * Returns list of all nodes within set.
     * This list is computed automatically, based on all elements, boundaries, edges, and specified nodes within the set.
     * @return List of node numbers.
     */
    const IntArray &giveNodeList();
    /**
     * Returns list of all directly specified nodes (excluding those generated from elements).
     * This list is exactly the list given in the input.
     * @note This is useful in for example, remeshing code, and should rarely be used elsewhere.
     * @return List of node numbers.
     */
    const IntArray &giveSpecifiedNodeList();
    /**
     * Sets list of elements within set.
     */
    void setElementList(IntArray newElements);
    /**
     * Sets list of element boundaries within set.
     */
    void setBoundaryList(IntArray newBoundaries);
    /**
     * Sets list of element edges within set (must be edges of 3D elements).
     */
    void setEdgeList(IntArray newEdges);
    /**
     * Sets list of nodes within set.
     */
    void setNodeList(IntArray newNodes);

    /**
     * Clears the entire set.
     */
    void clear();
    /**
     * Initialize the element set to contain all elements in the receiver domain
     */
    void addAllElements();
    /// Return True if given element is contained
    bool hasElement(int elem) const;

    void updateLocalNumbering(EntityRenumberingFunctor &f) override;
    /**
     * Renumbering of nodes (could change due to load balancing).
     */
    void updateLocalNodeNumbering(EntityRenumberingFunctor &f);
    /**
     * Renumbering of nodes (could change due to load balancing).
     */
    void updateLocalElementNumbering(EntityRenumberingFunctor &f);

    void saveContext(DataStream &stream, ContextMode mode) override;
    void restoreContext(DataStream &stream, ContextMode mode) override;
#endif

    const char *giveClassName() const override { return "Polyset"; }
    const char *giveInputRecordName() const override { return _IFT_Polyset_Name; }

protected:
    /**
     * Converts list ranges to list of individual values + individually specified values.
     */
    //void computeIntArray(IntArray &answer, const IntArray &specified, std :: list< Range >ranges);

    /**
     * Finds the clone node of cells from the given list of associated geometry
     * (mesh) nodes' global number
     */
    void clonesOfGeoNodes(IntArray &answer, const IntArray &nodes);
    /**
     * @returns central node of cells associated with list of geometry (mesh)
     * nodes' global number
     * @attention it is assumed that the set and the elements have same domain
     */
    std::set<int> cellNodesOfGeoNode( int geoNode );
    /**
     * Finds the central node of cells from the given list of associated geometry
     * (mesh) nodes
     */
    void cellNodesOfGeoNodes(IntArray &answer, const IntArray &nodes);
    void cellNodesOfGeoNodes(IntArray &answer, const IntArray &nodes, const int minAssoc);
};
}

#endif // polyset_h