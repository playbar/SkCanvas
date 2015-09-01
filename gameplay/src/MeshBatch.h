#ifndef MESHBATCH_H_
#define MESHBATCH_H_

#include "Mesh.h"

namespace gameplay
{

class Material;

class MeshBatch
{
public:
    static MeshBatch* create(const VertexFormat& vertexFormat, Mesh::PrimitiveType primitiveType, const char* materialPath, bool indexed, unsigned int initialCapacity = 1024, unsigned int growSize = 1024);
    static MeshBatch* create(const VertexFormat& vertexFormat, Mesh::PrimitiveType primitiveType, Material* material, bool indexed, unsigned int initialCapacity = 1024, unsigned int growSize = 1024);

    ~MeshBatch();
    unsigned int getCapacity() const;
    void setCapacity(unsigned int capacity);
    inline Material* getMaterial() const;

    template <class T>
    void add(const T* vertices, unsigned int vertexCount, const unsigned short* indices = NULL, unsigned int indexCount = 0);
    void add(const float* vertices, unsigned int vertexCount, const unsigned short* indices = NULL, unsigned int indexCount = 0);
    void start();
    bool isStarted() const;
    void finish();
    void draw();

private:
    MeshBatch(const VertexFormat& vertexFormat, Mesh::PrimitiveType primitiveType, Material* material, bool indexed, unsigned int initialCapacity, unsigned int growSize);
    MeshBatch(const MeshBatch& copy);

    MeshBatch& operator=(const MeshBatch&);
	void add(const void* vertices, size_t size, unsigned int vertexCount, const unsigned short* indices, unsigned int indexCount);

    void updateVertexAttributeBinding();

    bool resize(unsigned int capacity);

    const VertexFormat _vertexFormat;
    Mesh::PrimitiveType _primitiveType;
    Material* _material;
    bool _indexed;
    unsigned int _capacity;
    unsigned int _growSize;
    unsigned int _vertexCapacity;
    unsigned int _indexCapacity;
    unsigned int _vertexCount;
    unsigned int _indexCount;
    unsigned char* _vertices;
    unsigned char* _verticesPtr;
    unsigned short* _indices;
    unsigned short* _indicesPtr;
    bool _started;

};

}

#include "MeshBatch.inl"

#endif
