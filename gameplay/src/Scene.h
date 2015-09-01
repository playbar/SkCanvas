#ifndef SCENE_H_
#define SCENE_H_

#include "Node.h"
#include "MeshBatch.h"
#include "ScriptController.h"
#include "Light.h"
#include "Model.h"

namespace gameplay
{

/**
 * Defines the root container for a hierarchy of Node objects.
 *
 * @see http://gameplay3d.github.io/GamePlay/docs/file-formats.html#wiki-Scene
 */
class Scene : public Ref
{
public:
	class VisitNode
	{
	public:
		VisitNode();
		~VisitNode();
		virtual bool visitInitNode(Node* node);
		virtual bool visitDrawNode(Node *node);
		virtual bool visitDrawNode(Node *node, void* cookie);
	private:

	};

public:

    /**
     * Creates a new empty scene.
     *
     * @param id ID of the new scene, or NULL to use an empty string for the ID (default).
     *
     * @return The newly created empty scene.
     * @script{create}
     */
    static Scene* create(const char* id = NULL);

    /**
     * Loads a scene from the given '.scene' or '.gpb' file.
     *
     * @param filePath The path to the '.scene' or '.gpb' file to load from.
     * @return The loaded scene or <code>NULL</code> if the scene
     *      could not be loaded from the given file.
     * @script{create}
     */
    static Scene* load(const char* filePath);

    /**
     * Gets a currently active scene.
     *
     * If id is an NULL, the first active scene is returned.
     *
     * @param id ID of the scene to retrieve, or NULL to retrieve the first active scene.
     *
     * @return The scene that matches the specified ID, or NULL if no matching scene could be found.
     */
    static Scene* getScene(const char* id = NULL);

    /**
     * Gets the identifier for the scene.
     *
     * @return The scene identifier.
     */
    const char* getId() const;

    /**
     * Sets the identifier for the scene.
     *
     * @param id The identifier to set for the scene.
     */
    void setId(const char* id);

    /**
     * Returns the first node in the scene that matches the given ID.
     *
     * @param id The ID of the node to find.
     * @param recursive true if a recursive search should be performed, false otherwise.
     * @param exactMatch true if only nodes whose ID exactly matches the specified ID are returned,
     *      or false if nodes that start with the given ID are returned.
     *
     * @return The first node found that matches the given ID.
     */
    Node* findNode(const char* id, bool recursive = true, bool exactMatch = true) const;

    /**
     * Returns all nodes in the scene that match the given ID.
     *
     * @param id The ID of the node to find.
     * @param nodes Vector of nodes to be populated with matches.
     * @param recursive true if a recursive search should be performed, false otherwise.
     * @param exactMatch true if only nodes who's ID exactly matches the specified ID are returned,
     *      or false if nodes that start with the given ID are returned.
     *
     * @return The number of matches found.
     * @script{ignore}
     */
    unsigned int findNodes(const char* id, std::vector<Node*>& nodes, bool recursive = true, bool exactMatch = true) const;

    /**
     * Creates and adds a new node to the scene.
     *
     * @param id An optional node ID.
     *
     * @return The new node.
     */
    Node* addNode(const char* id = NULL);

    /**
     * Adds the specified node to the scene.
     *
     * @param node The node to be added to the scene.
     */
    void addNode(Node* node);

    /**
     * Removes the specified node from the scene.
     *
     * @param node The node to remove.
     */
    void removeNode(Node* node);

    /**
     * Removes all nodes from the scene.
     */
    void removeAllNodes();

    /**
     * Returns the number of nodes at the root level of the scene.
     *
     * @return The node count.
     */
    unsigned int getNodeCount() const;

    /**
     * Returns the first node in the scene.
     *
     * @return The first node in the scene.
     */
    Node* getFirstNode() const;

    /**
     * Gets the active camera for the scene.
     *
     * @return The active camera for the scene.
     * @see VisibleSet#getActiveCamera
     */
    Camera* getActiveCamera();

    /**
     * Sets the active camera on the scene.
     *
     * @param camera The active camera to be set on the scene.
     */
    void setActiveCamera(Camera* camera);

    /**
     * Sets the audio listener to transform along with the active camera if set to true.
     * If you have a 2D game that doesn't require it, then set to false.  This is on by default for the scene.
     *
     * @param bind true if you want to the audio listener to follow the active camera's transform.
     */
    void bindAudioListenerToCamera(bool bind);

    /**
     * Returns the ambient color of the scene.
     *
     * The default ambient light color is black (0,0,0).
     *
     * This value can be bound to materials using the SCENE_LIGHT_AMBIENT_COLOR auto binding.
     *
     * @return The scene's ambient color.
     */
    const Vector3& getAmbientColor() const;

    /**
     * Sets the ambient color of the scene.
     *
     * @param red The red channel between 0.0 and 1.0.
     * @param green The green channel between 0.0 and 1.0.
     * @param blue The blue channel between 0.0 and 1.0.
     *
     * @see getAmbientColor()
     */
    void setAmbientColor(float red, float green, float blue);

    /**
     * Updates all active nodes in the scene.
     *
     * This method is recursively calls the Node::update(float) method on all nodes that
     * are active within the scene. A Node is considered active if Node::isActive()
     * returns true.
     *
     * @param elapsedTime Elapsed time in milliseconds.
     */
    void update(float elapsedTime);

	void visit(VisitNode* instance, bool(VisitNode::*visitMethod)(Node*));

	void visit(VisitNode* instance, bool(VisitNode::*visitMethod)(Node*, void*), void* cookie);
   
	/**
     * Visits each node in the scene and calls the specified Lua function.
     *
     * Calling this method invokes the specified Lua function for each node
     * in the scene hierarchy.
     *
     * The visitMethod parameter must be a string containing the name of a
     * valid Lua function that has a boolean return type and accepts a
     * single parameter of type Node*.
     *
     * A depth-first traversal of the scene continues while the visit method
     * returns true. Returning false will stop traversing further children for
     * the given node and the traversal will continue at the next sibling.
     *
     * @param visitMethod The name of the Lua function to call for each node in the scene.
     */
    inline void visit(const char* visitMethod);

    /**
     * @see VisibleSet#getNext
     */
    Node* getNext();

    /**
     * @see VisibleSet#reset
     */
    void reset();

private:

    /**
     * Constructor.
     */
    Scene();

    /**
     * Hidden copy constructor.
     */
    Scene(const Scene& copy);

    /**
     * Destructor.
     */
    virtual ~Scene();

    /**
     * Hidden copy assignment operator.
     */
    Scene& operator=(const Scene&);

	void visitNode(Node *node, VisitNode *instance, bool(VisitNode::*visitMethod)(Node*));
	void visitNode(Node* node, VisitNode *instance, bool(VisitNode::*visitMethod)(Node*, void*), void* cookie);

	/**
     * Visits the given node and all of its children recursively.
     */
    void visitNode(Node* node, const char* visitMethod);

    Node* findNextVisibleSibling(Node* node);

    bool isNodeVisible(Node* node);

    std::string _id;
    Camera* _activeCamera;
    Node* _firstNode;
    Node* _lastNode;
    unsigned int _nodeCount;
    Vector3 _ambientColor;
    bool _bindAudioListenerToCamera;
    Node* _nextItr;
    bool _nextReset;
};

inline void Scene::visit(const char* visitMethod)
{
	for (Node* node = getFirstNode(); node != NULL; node = node->getNextSibling())
	{
		visitNode(node, visitMethod);
	}
}

}

#endif
