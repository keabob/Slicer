/*=auto=========================================================================

  Portions (c) Copyright 2005 Brigham and Women's Hospital (BWH) 
  All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Program:   3D Slicer

=========================================================================auto=*/

// MRML includes
#include "vtkMRMLCoreTestingMacros.h"
#include "vtkMRMLHierarchyNode.h"

class vtkMRMLHierarchyNodeTestHelper1 : public vtkMRMLHierarchyNode
{
public:
  // Provide a concrete New.
  static vtkMRMLHierarchyNodeTestHelper1 *New(){return new vtkMRMLHierarchyNodeTestHelper1;};

  vtkTypeMacro( vtkMRMLHierarchyNodeTestHelper1,vtkMRMLHierarchyNode);

  virtual vtkMRMLNode* CreateNodeInstance()
    {
    return new vtkMRMLHierarchyNodeTestHelper1;
    }
  virtual const char* GetNodeTagName()
    {
    return "vtkMRMLHierarchyNodeTestHelper1";
    }
  virtual bool CanApplyNonLinearTransforms() { return false; }
};

int vtkMRMLHierarchyNodeTest1(int , char * [] )
{
  vtkNew<vtkMRMLHierarchyNode> node1;
  
  EXERCISE_BASIC_OBJECT_METHODS( node1.GetPointer() );

  EXERCISE_BASIC_MRML_METHODS(vtkMRMLHierarchyNode, node1.GetPointer());

  TEST_SET_GET_DOUBLE_RANGE(node1.GetPointer(), SortingValue, 0.0, 10.0);
  
  TEST_SET_GET_STRING(node1.GetPointer(), ParentNodeID);

  vtkMRMLHierarchyNode* pnode = node1->GetParentNode();
  std::cout << "GetParentNode returned " << (pnode == NULL ? "null" : "not null") << std::endl;

  node1->SetParentNodeID("testingID");
  pnode = node1->GetParentNode();
  std::cout << "GetParentNode returned " << (pnode == NULL ? "null" : "not null") << std::endl;

  // test the parent node id
  node1->SetParentNodeID(NULL);
  if (node1->GetParentNodeID() != NULL)
    {
    std::cerr << "Error setting parent node id to null" << std::endl;
    return EXIT_FAILURE;
    }
  node1->SetParentNodeID(NULL);
  if (node1->GetParentNodeID() != NULL)
    {
    std::cerr << "Error setting parent node id to null a second time" << std::endl;
    return EXIT_FAILURE;
    }
  node1->SetParentNodeID("testingValidStringID");
  if (node1->GetParentNodeID() == NULL ||
      strcmp(node1->GetParentNodeID(), "testingValidStringID") != 0)
    {
    std::cerr << "Error setting parent node id not null" << std::endl;
    return EXIT_FAILURE;
    }
  node1->SetParentNodeID("testingValidStringID");
  if (node1->GetParentNodeID() == NULL ||
      strcmp(node1->GetParentNodeID(), "testingValidStringID") != 0)
    {
    std::cerr << "Error setting parent node id to a valid string a second time" << std::endl;
    return EXIT_FAILURE;
    }
  node1->SetParentNodeID("anotherID");
  if (node1->GetParentNodeID() == NULL ||
      strcmp(node1->GetParentNodeID(), "anotherID") != 0)
    {
    std::cerr << "Error setting parent node id to a different valid string" << std::endl;
    return EXIT_FAILURE;
    }
  


  TEST_SET_GET_BOOLEAN(node1.GetPointer(), AllowMultipleChildren);

  return EXIT_SUCCESS;
}
