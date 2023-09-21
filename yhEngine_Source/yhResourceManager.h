#pragma once
#include "CommonInclude.h"
#include "yhHeader.h"

namespace yh
{
	class Resource;
	class ResourceManager
	{
	public:
		template <typename T>
		static T* Find(const std::wstring& key)
		{
			std::map<std::wstring, Resource*>::iterator iter = mResourceManager.find(key);

			// �̹� ������ Ű������ �ٸ� ���ҽ��� ���� ��ϵǾ� �־���.
			if (iter != mResourceManager.end())
			{
				return dynamic_cast<T*>(iter->second);
			}

			return nullptr;
		}

		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			// Ű������ Ž��
			T* resource = ResourceManager::Find<T>(key);
			if (nullptr != resource)
			{
				// �ش�Ű�� �̹� �ε��Ȱ� ������ �ش� ���ҽ��� ��ȯ
				return resource;
			}

			// �ش� Ű�� �ε��� ���ҽ��� ����.
			resource = new T();
			if (FAILED(resource->Load(path)))
			{
				MessageBox(nullptr, L"Image Load Failed!", L"Error", MB_OK);
				return nullptr;
			}

			resource->SetKey(key);
			resource->SetPath(path);
			mResourceManager.insert(make_pair(key, dynamic_cast<Resource*>(resource)));

			return dynamic_cast<T*>(resource);
		}

		template <typename T>
		static void Insert(const std::wstring& key, T* resource)
		{
			mResourceManager.insert(make_pair(key, dynamic_cast<Resource*>(resource)));
		}

		static void Release();

	private:
		ResourceManager() = delete;
		~ResourceManager() = delete;

	private:
		static std::map<std::wstring, Resource*> mResourceManager;
	};


}
