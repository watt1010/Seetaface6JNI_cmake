#ifndef INC_SEETA_FACETRACKING_H
#define INC_SEETA_FACETRACKING_H

#include "seeta/Common/Struct.h"
#include "CTrackingFaceInfo.h"
#include <string>
#include <vector>


namespace seeta
{
    namespace v6
    {
        class FaceTracker {
        public:
            /**
             * \brief initialize FaceTracker with face detector model
             * \param setting model used by FaceDetector5.1.0
             * \param video_width input video frame width
             * \param video_height input video frame height
             */
            SEETA_API explicit FaceTracker( const seeta::ModelSetting &setting, int video_width, int video_height );
            SEETA_API ~FaceTracker();

            SEETA_API void SetSingleCalculationThreads( int num );
            
            /**
             * Set tracking frame interval
             */
            SEETA_API void SetInterval(int interval); 

            /**
             * \brief �������
             * \param [in] image ����ͼ����Ҫ RGB ��ɫͨ��
             * \return ��⵽��������SeetaTrackingFaceInfo������
             * \note �˺�����֧�ֶ��̵߳��ã��ڶ��̻߳�������Ҫ������Ӧ�� FaceTracker �Ķ���ֱ���ü�⺯��
             * \see SeetaTrackingFaceInfo, SeetaImageData
             */
            SEETA_API SeetaTrackingFaceInfoArray Track( const SeetaImageData &image ) const;

            /**
             * \brief �������
             * \param [in] image ����ͼ����Ҫ RGB ��ɫͨ��
             * \param [in] frame_no ����֡�ţ������֡���й�
             * \return ��⵽��������SeetaTrackingFaceInfo������
             * \note �˺�����֧�ֶ��̵߳��ã��ڶ��̻߳�������Ҫ������Ӧ�� FaceTracker �Ķ���ֱ���ü�⺯��
             * \see SeetaTrackingFaceInfo, SeetaImageData
             * \note frame_no С��0 ���Զ��� frame_no
             */
            SEETA_API SeetaTrackingFaceInfoArray Track( const SeetaImageData &image, int frame_no ) const;

            /**
             * \brief ������С����
             * \param [in] size ��С�ɼ���������С��Ϊ������͸߳˻��Ķ��θ�ֵ
             * \note ��������Ϊ 20��С�� 20 ��ֵ�ᱻ����
             */
            SEETA_API void SetMinFaceSize( int32_t size );

            /**
             * \brief ��ȡ��С����
             * \return ��С�ɼ���������С��Ϊ������͸߳˻��Ķ��θ�ֵ
             */
            SEETA_API int32_t GetMinFaceSize() const;


            SEETA_API void SetThreshold( float thresh );

            SEETA_API float GetThreshold() const;


 	    /**
	      * \brief ��������������?
	      * \param stable ����
	      * \note ������������
	      * \note ������������������
	     */
	    SEETA_API void SetVideoStable(bool stable = true);

	    /**
	      * \brief ������������?
	      * \return ����
	      */
	    SEETA_API bool GetVideoStable() const;

            SEETA_API void SetVideoSize(int vidwidth, int vidheight);

            SEETA_API void Reset();           
        private:
            FaceTracker( const FaceTracker &other ) = delete;
            const FaceTracker &operator=( const FaceTracker &other ) = delete;

        private:
            class Implement;
            Implement *m_impl;
        };
    }
    using namespace v6;
}

#endif
